#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int L, M;

struct Seg {
  int l, r;
  const bool operator<(const Seg& o) const {
    return l < o.l;
  }
} seg[110];

int main(int argc, char *argv[])
{
#ifdef DEBUG
  freopen("422.in", "r", stdin);
#endif // DEBUG
  cin >> L >> M;
  for (int i = 0; i < M; ++i) {
    cin >> seg[i].l >> seg[i].r;
  }
  sort(seg, seg + M);
  int l = seg[0].l, r = seg[0].r;
  int res {0};
  for (int i = 1; i < M; ++i) {
    if (seg[i].l <= r) {
      r = max(r, seg[i].r);
    } else {
      res += (r - l + 1);
      l = seg[i].l;
      r = seg[i].r;
    }
  }
  res += (r - l + 1);
  res = L + 1 - res;
  cout << res << endl;

  return 0;
}
