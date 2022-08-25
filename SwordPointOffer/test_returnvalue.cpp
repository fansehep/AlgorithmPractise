#include <iostream>

class Test {
  public:
  explicit operator std::string() { return "hello, world"; }
  explicit operator int() { return 123; }
};

int main() {
  std::string v = static_cast<std::string>(Test());
 // std::string v = Test();
  int a = static_cast<int>(Test());
  printf("v = %s\na = %d\n", v.c_str(), a);
  return 0;
}