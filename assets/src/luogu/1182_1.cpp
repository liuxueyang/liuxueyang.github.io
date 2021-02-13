#include <cstdio>
#include <algorithm>

using namespace std;
using ll = long long;

const int N = 100010, INF = 1e9 + 10;
int a[N], n, m;

ll bsearch(ll l, ll r) {
  ll mid;
  while (l < r) {
    mid = (l + r) >> 1;

    int cnt = 1;
    ll cur = a[0];
    bool flag = true;
    for (int i = 1; i < n; ++i) {
      cur += a[i];
      if (cur > mid) {
	cur = a[i];
	if (cur > mid) {
	  flag = false;
	  break;
	}
	++cnt;
	if (cnt > m) {
	  flag = false;
	  break;
	}
      }
    }
    if (cnt > m) flag = false;

    if (flag) r = mid;
    else l = mid + 1;
  }

  return r;
}

int main() {
  #ifdef _DEBUG
  freopen("1182.in", "r", stdin);
  #endif
  
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) scanf("%d", a + i);
  printf("%lld\n", bsearch(1, INF));
  
  return 0;
}
