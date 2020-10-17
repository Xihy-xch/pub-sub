#include "pubNode.h"

// PubNode::PubNode() {}

void PubNode::setPub(std::string topic) {
  int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
  struct sockaddr_in serverAddress;
  setSocAddress(HOST_IP, MASTER_PORT, serverAddress);
  int ret = -1;
  while (ret == -1) {
    ret = connect(clientSocket, (struct sockaddr*)&serverAddress,
                  sizeof(serverAddress));
  }

  std::string msg = std::to_string(PUB) + topic;

  ret = send(clientSocket, msg.c_str(), msg.size(), 0);

  char buf[1024];
  bzero(buf, 1024);
  ret = recv(clientSocket, buf, 1024, 0);
  if (ret == -1) {
    std::cout << "recv error" << std::endl;
  }
  int pubPort = 0;
  if (std::string(buf).substr(0, 5) == "port:") {
    pubPort = std::atoi(std::string(buf).substr(5).c_str());
  }
  std::cout << pubPort << std::endl;

  int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
  struct sockaddr_in pubAddress;
  setSocAddress(HOST_IP, pubPort, pubAddress);
  setServerSocket(serverSocket, pubAddress);
  int epollfd = epoll_create(5);
  struct epoll_event events[MAX_EVENT_NUMBER];
  addfd(epollfd, serverSocket);
  bool serverStop = false;
  while (!serverStop) {
    int number = epoll_wait(epollfd, events, MAX_EVENT_NUMBER, -1);

    if (number == -1) {
      std::cout << "epoll_wait error" << std::endl;
      serverStop = true;
      continue;
    }

    for (int i = 0; i < number; i++) {
      int readySokcet = events[i].data.fd;

      if (readySokcet == serverSocket) {
        struct sockaddr_in clientAddress;
        bzero(&clientAddress, sizeof(clientAddress));
        socklen_t clientAddressLength = sizeof(clientAddress);

        int clientSocket =
            accept(serverSocket, (struct sockaddr*)&clientAddress,
                   &clientAddressLength);
        addwfd(epollfd, clientSocket);
      } else if (events[i].events & EPOLLOUT) {
        std::string msg = "hello";
        // if (message.size() != 0) {
        ret = send(readySokcet, msg.c_str(), msg.size(), 0);
        if (ret == -1) {
          std::cout << "send error" << std::endl;
        }
        // }
      }
    }
  }
}

void PubNode::publish(std::string msg) { this->message = msg; }
