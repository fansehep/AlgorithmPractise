#include <bits/stdc++.h>
using namespace std;

template <typename T, typename = void>
struct func {};

template<typename T>
struct func<T, std::enable_if_t<std::is_same<T, int>::value>> {
  void operator () (T args) {
    std::cout << args << std::endl;
    std::cout << "i am int" << std::endl;
  }
};

func<int> funconlyint;

using func_t = func<int>();
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

template <typename T, typename = void>
struct func {};

template <typename T>
struct func<T, std::enable_if_t<std::is_same<T, youwanttype>::value>> {
  T var_;
};


int main () {
  int b = 10;
  funconlyint(b);
  return 0;
}
