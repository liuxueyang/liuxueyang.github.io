#include <iostream>
#include "Sales_item.h"

using namespace std;

int main() {
  #ifdef _DEBUG
  freopen("1.25.in", "r", stdin);
  #endif

  Sales_data item, total;

  if (cin >> item) {
    total = item;

    while (cin >> item) {
      if (item.isbn() == total.isbn()) {
        total += item;
      } else {
        cout << total << endl;

        total = item;
      }
    }

    cout << total << endl;
  } else {
    cerr << "no data" << endl;
    return -1;
  }

  return 0;
}
