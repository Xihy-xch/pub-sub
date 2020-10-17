#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include <iostream>
using namespace std;
class Test {
 public:
  int sum;
  int cnt;
  Test() { sum = 0; }

 public:
  int insert();
  static void* insert_pth(void*);
  void lanch();
};
int Test::insert() {
  sleep(2);
  sum += 1;
  printf("%d insert.....\n", sum);
}
void* Test::insert_pth(void* __this) {
  Test* _this = (Test*)__this;

  for (int i = 0; i < 5; i++) {
    sleep(2);
    _this->sum += 1;
  }

  printf("%d insert.....\n", _this->sum);
}
void Test::lanch() {
  pthread_t pth;
  pthread_create(&pth, NULL, insert_pth, (void*)this);
}
int main() {
  Test t;
  t.sum = 0;
  t.lanch();
  sleep(5);
  return 0;
}