#ifndef MASTER_H
#define MASTER_H

#include "common.h"

class Master {
 public:
  void init(char* ip, int port);
  void run();
  void parseInfo(char* buf, int socket);

 public:
  int masterSocket;
  char* ip;
  int port;

  int usablePort;
  std::map<std::string, int> pubList;
  std::map<std::string, std::vector<int>> subList;
};

#endif