#include "masterNode.h"

void Master::init(char* ip, int port) {

  this->masterSocket = socket(AF_INET, SOCK_STREAM, 0);
  struct sockaddr_in address;
  bzero(&address, sizeof(address));

  setSocAddress(HOST_IP, MASTER_PORT, address);
  setServerSocket(this->masterSocket, address);
  this->usablePort = 65535;
}

void Master::run() {
  int epollfd = epoll_create(5);
  struct epoll_event events[MAX_EVENT_NUMBER];
  addfd(epollfd, this->masterSocket);
  bool serverStop = false;
  while (!serverStop) {
    int readyFds = epoll_wait(epollfd, events, MAX_EVENT_NUMBER, -1);
    if (readyFds == -1) {
      std::cout << "epoll_wait error" << std::endl;
      serverStop = true;
      continue;
    }

    for (int i = 0; i < readyFds; i++) {
      int readySocket = events[i].data.fd;

      if (readySocket == masterSocket) {
        struct sockaddr_in clientAddress;
        bzero(&clientAddress, sizeof(clientAddress));
        socklen_t clientAddressLength = sizeof(clientAddress);

        int clientSocket =
            accept(masterSocket, (struct sockaddr*)&clientAddress,
                   &clientAddressLength);
        addfd(epollfd, clientSocket);

      } else if (events[i].events & EPOLLIN) {
          
          char buf[1024];
          bzero(buf, 1024);

          int ret = recv(readySocket, buf, 1024, 0);
          if (ret == -1 || strlen(buf) == 0) {
              std::cout << "recv error" << std::endl;
          }
          parseInfo(buf, readySocket);

      }
    }
  }
}

void Master::parseInfo(char* buf, int socket) {
    int type = buf[0] - '0';

    if (type == SUB) {
      std::string topicName = std::string(buf).substr(1);
      if (pubList.find(topicName) != pubList.end()) {
        std::string msg = "port:" + std::to_string(pubList[topicName]);
        send(socket, msg.c_str(), sizeof(msg), 0);
      } else {
        subList[topicName].push_back(socket);
      }

    } else if (type == PUB) {
        std::string topicName = std::string(buf).substr(1);

        this->usablePort--;
        if (usablePort < 20000) {
            std::cout << "无可用端口" << std::endl;
            return;
        }

        // std::cout << topicName << std::endl;
        this->pubList.insert(std::make_pair(topicName, usablePort));
        std::string msg = "port:" + std::to_string(usablePort);
        send(socket, msg.c_str(), sizeof(msg), 0);
        if (subList.find(topicName) != subList.end()) {
          for (int i = 0; i < subList[topicName].size(); i++) {
            send(subList[topicName][i], msg.c_str(), sizeof(msg), 0);
          }
          subList.erase(topicName);
        }
    }
}
