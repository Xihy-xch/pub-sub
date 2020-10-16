#ifndef MASTER_H
#define MASTER_H

#include "node.h"

class Master {
 public:
  void init(char* ip, int port);
  void run();
  void parseInfo(std::string buf, int sockfd);

 public:
  int masterSocket;
  char* ip;
  int port;

  int usablePort;
  std::map<std::string, int> pubList;
};

#endif