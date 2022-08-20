#include <bits/stdc++.h>
using namespace std;

namespace lns {
template <typename T, typename = void>
struct func {};

template<typename T>
struct func<T, std::enable_if_t<std::is_same<T, int>::value>> {
  void operator () (T args) {
    std::cout << args << std::endl;
    std::cout << "i am int" << std::endl;
  }
};
}

template <typename T, typename = void>
void func (T args) {
  
}

struct test {
  virtual ~test() {}
  virtual void func () = 0;
  int a;
  int b;
  virtual void Print () {
    std::cout << "hello ,world!" << std::endl;
  }
  test () {}
};



int main () {
  int b = 10;
  std::cout << sizeof(test) << std::endl;
  return 0;
}
