#include <bits/stdc++.h>
#include <pthread.h>
#include <unistd.h>

#include <map>
#define HOST_IP "127.0.0.1"
using namespace std;

int main() {
  char buf[1024];
  memset(buf,'\0', 1024);
  buf[0] = '1';
  buf[1] = '2';
  string buf1 = buf;
  int i = 0;
  while (buf[i] != '\0') {
    cout << buf1[i] << endl;
    i++;
  }

  return 0;
}