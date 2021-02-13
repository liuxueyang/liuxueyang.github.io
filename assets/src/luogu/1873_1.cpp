#include <cstdio>
#include <algorithm>

using namespace std;
using ll =long long;

const int N = 1000010, INF = 2*1e9+10;
int n, a[N];
ll m;

int bsearch(int l, int r) {
  ll mid;
  while (l < r) {
    mid = (1 + l + r) >> 1;

    ll sum = 0;
    bool flag = false;
    for (int i = 0; i < n; ++i) {
      if (a[i] > mid) {
	sum += (a[i] - mid);
	if (sum >= m) {
	  flag = true;
	  break;
	}
      }
    }

    if (flag) l = mid;
    else r = mid - 1;
  }
  return l;
}

int main() {
  #ifdef _DEBUG
  freopen("1873.in", "r", stdin);
  #endif
  
  scanf("%d%lld", &n, &m);
  for (int i = 0; i < n; ++i) scanf("%d", a + i);
  printf("%d\n", bsearch(1, INF));
  
  return 0;
}
