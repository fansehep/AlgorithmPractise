#include <iostream>
class Uncopyable {
 protected:
  constexpr Uncopyable() = default;
  ~Uncopyable() = default;

 public:
  Uncopyable(const Uncopyable&) = delete;
  Uncopyable& operator=(const Uncopyable&) = delete;
};

class test : public Uncopyable {
 public:
  test() {}
  virtual ~test() { printf("test disconstruct!"); }

 private:
};

class test_2 : public test {
 public:
  test_2() {}
  ~test_2() { printf("test_2 disconstruct!"); }

 private:
};

int main() {
  printf("%ld\n", sizeof(test));
  test* a = new test_2();
  delete a;

  return 0;
}
