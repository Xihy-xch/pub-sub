#include "pubNode.h"
#include "pubThread.h"
int main() {
  
  PubNode pubNode;
  pubNode.setPubTopic("talker");
  startThread(&pubNode);
  while(1) {
    pubNode.publish("hello sub ");
    sleep(2);
    //pubNode.publish("hello");
  }
  return 0;
}