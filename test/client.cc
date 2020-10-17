#include "common.h"

int main(int argc, char* argv[]) {
  int clientSock = socket(AF_INET, SOCK_STREAM, 0);

  struct sockaddr_in serverAddr;
  setSocAddress(HOST_IP, 12345, serverAddr);

  int ret =
      connect(clientSock, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
  if (ret == - 1) {
      std::cout << "connect error" << std::endl;
  }
  //   while (1) {
  std::string buf = "server1";
  ret = send(clientSock, buf.c_str(), sizeof(buf), 0);

  if (ret == -1) {
    std::cout << "send error" << std::endl;
    // }
  }
  
  setSocAddress(HOST_IP, 12346, serverAddr);
  ret =
      connect(clientSock, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
  if (ret == - 1) {
      std::cout << "connect error" << std::endl;
  }
  //   while (1) {
  buf = "server2";
  ret = send(clientSock, buf.c_str(), sizeof(buf), 0);

  if (ret == -1) {
    std::cout << "send error" << std::endl;
    // }
  }

}