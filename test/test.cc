#include <bits/stdc++.h>
#include <pthread.h>
#include <unistd.h>

#include <map>
#define HOST_IP "127.0.0.1"
using namespace std;

int main() {

  char* buf = "0wer";
  std::string topicName = std::string(buf).substr(1);
  cout << topicName << endl;

  return 0;
}