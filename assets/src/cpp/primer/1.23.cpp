#include <iostream>
#include "Sales_item.h"

using namespace std;

int main() {
  #ifdef _DEBUG
  freopen("1.23.in", "r", stdin);
  #endif

  Sales_data item, cur;
  int cnt = 0;

  if (cin >> item) {
    cnt = 1;
    cur = item;

    while (cin >> item) {
      if (item.isbn() == cur.isbn()) {
        ++cnt;
      } else {
        cout << "Number of trx for " << cur.isbn() << " : "
             << cnt << endl;

        cnt = 1;
        cur = item;
      }
    }

    cout << "Number of trx for " << cur.isbn() << " : "
         << cnt << endl;
  } else {
    cerr << "no data" << endl;
  }

  return 0;
}
