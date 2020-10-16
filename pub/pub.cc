#include "node.h"

int main() {
  Node pubNode;
  pubNode.setPub("talker");
  std::string msg = "hello world";
  while (1) {
    pubNode.publish(msg);
    sleep(2);
  }
}