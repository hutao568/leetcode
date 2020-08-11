//
// Created by tao hu on 2020/7/4.
//

#include <iostream>
extern int a_int;
extern void func2();

static char c_array[10000];

void func1() {
  static int a_tmp = 0;
  std::cout << a_tmp++ << std::endl;
  return;
}

int main(int argc, char **argv) {
  a_int = 1;

  //静态局部变量示例
  for (auto i = 0; i < 5; i++) {
    func1();
  }

  //比较静态全局变量的地址示例
  std::cout << static_cast<const void *>(c_array) << std::endl;
  func2();
  return 0;
}