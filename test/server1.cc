#include "common.h"

int main(int argc, char* argv[]) {
  struct sockaddr_in sockaddr;
  bzero(&sockaddr, sizeof(sockaddr));
  setSocAddress(HOST_IP, 12346, sockaddr);

  int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
  setServerSocket(serverSocket, sockaddr);

  struct sockaddr_in clientAddr;
  bzero(&clientAddr, sizeof(clientAddr));

  socklen_t clientAddrLen = sizeof(clientAddr);

  int clientSock =
      accept(serverSocket, (struct sockaddr*)&clientAddr, &clientAddrLen);
    char buf[1024];
    bzero(buf, 1024);
    recv(clientSock, buf, 1024, 0);
    std::cout << buf << std::endl;
  
}