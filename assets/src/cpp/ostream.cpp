#include <cstdio>
#include <iostream>
#include <vector>
#include <ostream>

using namespace std;

using VI = vector<int>;

int main() {
  #ifdef _DEBUG
  // freopen("ostream.in", "r", stdin);
  #endif

  VI a {3, 4, 5, 10, 11};
  ostream_iterator<int> ot(cout, " ");
  copy(a.begin(), a.end(), ot);

  VI b;
  istream_iterator<int> eos;
  istream_iterator<int> it(cin);
  copy(it, eos, back_inserter(b));
  copy(b.begin(), b.end(), ot);

  if (int n = 3) {
    int ar[] = {5, 4, 3, 2, 1};
    copy(ar, ar + n, ot);
  }

  return 0;
}
