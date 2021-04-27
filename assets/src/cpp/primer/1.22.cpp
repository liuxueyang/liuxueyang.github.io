#include <iostream>
#include "Sales_item.h"

using namespace std;

int main() {
  #ifdef _DEBUG
  freopen("1.22.in", "r", stdin);
  #endif

  Sales_data item, sum;

  cin >> item;
  cout << item << endl;
  sum = item;

  while (cin >> item) {
    cout << item << endl;
    sum += item;
  }
  cout << sum << endl;

  return 0;
}
