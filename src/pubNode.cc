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

  ret = send(clientSocket, msg.c_str(), sizeof(msg), 0);

  char buf[1024];
  bzero(buf, 1024);
  ret = recv(clientSocket, buf, 1024, 0);
  if (ret == -1) {
    std::cout << "recv error" << std::endl;
  }

  std::cout << buf << std::endl;
}
