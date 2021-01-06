#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1233;
long long d[N];
int n;

int main(int argc, char *argv[])
{
#ifdef DEBUG
  freopen("1293.in", "r", stdin);
#endif // DEBUG

  cin >> n;
  int a[4] = {10, 20, 50, 100};
  memset(d, 0, sizeof d);
  d[0] = 1;
  for (int i = 0; i < 4; ++i) {
    for (int v = a[i]; v <= n; ++v) {
      d[v] += d[v-a[i]];
    }
  }
  cout << d[n] << endl;

  return 0;
}
