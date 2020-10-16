#ifndef SUBNODE_H
#define SUBNODE_H

#include "common.h"

class SubNode {
 public:
  SubNode(char* ip, int port);
  SubNode();
  //void init();
  void setSub(std::string topic);
  void getMsg();
  

 public:
  char* ip;
  int port;
};
#endif