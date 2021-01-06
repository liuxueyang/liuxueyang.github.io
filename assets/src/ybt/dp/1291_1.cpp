#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 23, S = 1233;
int a[N], n, t;
long long d[S];

int main(int argc, char *argv[])
{
#ifdef DEBUG
  freopen("1291.in", "r", stdin);
#endif // DEBUG

  cin >> n >> t;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  memset(d, 0, sizeof d);
  d[0] = 1;
  for (int i = 0; i < n; ++i) {
    for (int t1 = t ; t1 >= a[i]; t1--) {
      d[t1] += d[t1-a[i]];
    }
  }
  cout << d[t] << endl;

  return 0;
}
