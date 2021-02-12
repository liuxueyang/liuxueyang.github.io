#include <algorithm>
#include <cstdio>

using namespace std;
using ll = long long;

const int N = 100010, INF = 1e9 + 10;
int a[N], n, m;

ll bsearch(ll l, ll r) {
  ll mid;
  while (l < r) {
    mid = (l + r) >> 1;

    ll cnt = 1, cur = a[0];
    bool flag = true;
    if (cur > mid) flag = false;
    for (int i = 1; i < n && flag; ++i) {
      if (cur + a[i] > mid) {
        cur = a[i];
        ++cnt;
      } else {
        cur += a[i];
      }
      if (cnt > m || cur > mid) { flag = false; break; }
    }

    if (flag) {
      r = mid;
    } else l = mid + 1;
  }
  return r;
}

int main(int argc, char *argv[])
{
  #ifdef _DEBUG
  freopen("1182.in", "r", stdin);
  #endif

  scanf("%d%d", &n, &m);
  ll top = INF;
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  printf("%lld\n", bsearch(1, top));

  return 0;
}
