#include <iostream>
#include "Sales_item.h"

using namespace std;

int main() {
  #ifdef _DEBUG
  freopen("1.20.in", "r", stdin);
  #endif

  Sales_data item;
  while (cin >> item) {
    cout << item << endl;
  }

  return 0;
}
