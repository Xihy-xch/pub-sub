#include "pubNode.h"

int main() {
  PubNode pubNode;
  pubNode.setPub("talker");
  while(1) {
    pubNode.publish("helloworld");
    sleep(2);
  }
  return 0;
}