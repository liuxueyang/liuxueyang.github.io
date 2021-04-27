#include <iostream>
#include "Sales_item.h"

using namespace std;

int main() {
  #ifdef _DEBUG
  freopen("1.21.in", "r", stdin);
  #endif

  Sales_data a, b;
  cin >> a;
  cout << a << endl;

  cin >> b;
  cout << b << endl;

  Sales_data sum;
  sum = a + b;
  cout << "sum: " << sum << endl;

  return 0;
}
