#ifndef PUBNODE_H
#define PUBNODE_H

#include "common.h"
#include "subNode.h"


class PubNode {
 public:
  //PubNode();
  //void init();
  void setPubTopic(std::string topic);
  void setPub();
  void publish(std::string msg);
  

 public:  
  std::string message;
  std::string topic;
  std::vector<int> subList;
};
#endif