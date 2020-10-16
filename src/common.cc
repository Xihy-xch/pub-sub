#include "common.h"
void setSocAddress(char* ip, int port, struct sockaddr_in& address) {
  address.sin_family = AF_INET;
  address.sin_port = port;
  inet_pton(AF_INET, ip, &address.sin_addr);
}

void setServerSocket(int& socket, struct sockaddr_in& address) {
  int on = 1;
  int ret = 0;
  ret = setsockopt(socket, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));
  if (ret == -1) {
    std::cout << "setsockopt error" << std::endl;
  }

  ret = bind(socket, (struct sockaddr*)&address, sizeof(address));
  if (ret == -1) {
    std::cout << "bind error" << std::endl;
  }

  ret = listen(socket, 5);
  if (ret == -1) {
    std::cout << "listen error" << std::endl;
  }
}

int setNoBlocking(int fd) {
  int oldOption = fcntl(fd, F_GETFL);
  int newOption = oldOption | O_NONBLOCK;
  fcntl(fd, F_SETFL, newOption);
  return oldOption;
}

void addfd(int epollfd, int fd) {
  epoll_event event;
  event.data.fd = fd;
  event.events = EPOLLIN | EPOLLET;
  epoll_ctl(epollfd, EPOLL_CTL_ADD, fd, &event);
  setNoBlocking(fd);
}