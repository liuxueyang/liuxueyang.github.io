#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 200010;
typedef long long ll;
int n, a[N], c;

int search(int l, int r, ll k) {
  if (l > r) return 0;
  int mid;
  int l1 = l, r1 = r;
  while (l < r) {
    mid = (l + r) >> 1;
    if (a[mid] >= k) r = mid;
    else l = mid + 1;
  }
  if (a[r] != k) return 0;
  int left = r;

  l = l1, r = r1;
  while (l < r) {
    mid = (l + r + 1) >> 1;
    if (a[mid] <= k) l = mid;
    else r = mid - 1;
  }
  int right = l;

  return right - left + 1;
}

int main() {
  #ifdef _DEBUG
  freopen("1102.in", "r", stdin);
  #endif

  scanf("%d%d", &n, &c);
  for (int i = 0; i < n; ++i) scanf("%d", a + i);
  sort(a, a + n);
  ll res = 0;
  for (int i = 0; i < n; ++i) {
    ll d = a[i] - c;
    int cnt = 0;
    cnt = search(0, i - 1, d);
    res += cnt;
    // printf("d=%lld cnt=%d\n", d, cnt);
  }
  printf("%lld\n", res);

  return 0;
}
