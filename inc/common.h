#ifndef COMMON_H
#define COMMON_H


#include <arpa/inet.h>
#include <bits/stdc++.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <pthread.h>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <sys/unistd.h>

#define MAX_EVENT_NUMBER 1024
#define PUB 0
#define SUB 1
#define MASTER_PORT 12345
#define HOST_IP "127.0.0.1"


void setSocAddress(char* ip, int port, struct sockaddr_in& address);

void setServerSocket(int& socket, struct sockaddr_in& address);

int setNoBlocking(int fd);

void addfd(int epollfd, int fd);

void addwfd(int epollfd, int fd);
  

#endif