#include <iostream>

int sum(int a, int b) {
  return a + b;
}

int main() {
  int a = 1;
  int b = 2;

  std::cout << "Hello there" << std::endl;

  std::cout << sum(a, b) << std::endl;

  return 0;
}
