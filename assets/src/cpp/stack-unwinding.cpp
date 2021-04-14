#include <cstdio>

using namespace std;

class Obj {
public:
  Obj () {
    puts("Obj()");
  }
  ~Obj() {
    puts("~Obj()");
  }
};

void foo(int x) {
  Obj o;
  if (x == 42) {
    throw "life, the universe and everything";
  }
}

int main() {
  try {
    foo(41);
    foo(42);
  }
  catch (const char *s) {
    puts(s);
  }

  return 0;
}
