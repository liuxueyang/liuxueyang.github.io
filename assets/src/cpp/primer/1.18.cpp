#include <iostream>

using namespace std;

int main() {
  int val {}, cur_val {}, cnt {};

  if (cin >> val) {
    cnt = 1;
    cur_val = val;

    while (cin >> val) {
      if (val == cur_val) {
        ++cnt;
      } else {
        cout << cur_val << " occured " << cnt << " times" << endl;
        cnt = 1;
        cur_val = val;
      }
    }

    cout << cur_val << " occured " << cnt << " times" << endl;
  }

  return 0;
}
