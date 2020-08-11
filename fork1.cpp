//
// Created by tao hu on 2020/8/3.
//

#include <iostream>
#include <unistd.h>
using namespace std;

void fun1(){
  int i =0;
  for (; i<2; i++)
  {
    fork();
    printf("a\n");
  }
}

void fun2(){
  printf("a");
  fork();

  printf("a\n");
  fork();
}
int main(){
  fun2();
}
