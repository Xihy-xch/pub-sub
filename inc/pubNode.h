#ifndef PUBNODE_H
#define PUBNODE_H

#include "common.h"
#include "subNode.h"
;

class PubNode {
 public:
  PubNode(char* ip, int port);
  PubNode();
  //void init();
  void setPub(std::string topic);
  void publish(std::string& msg);
  

 public:
  
  char* ip;
  int port;
};
#endif