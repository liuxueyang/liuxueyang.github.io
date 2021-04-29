#include <iostream>

using namespace std;

#ifdef _DEBUG

#define LOG(frm, args...) {                               \
    printf("[%s %s %d] ", __FILE__, __func__, __LINE__);  \
    printf(frm, ##args);                                  \
    printf("\n");                                         \
}

#else

#define LOG(frm, args...)

#endif

int main() {
  int x = 10;
  LOG("x=%d", x);

  cout << __FILE__ << ' '
       << __LINE__ << ' '
       << __func__ << ' '
       << __PRETTY_FUNCTION__ << ' '
       << endl;

  return 0;
}
