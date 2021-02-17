#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

const int N = 100010;

vector<int> alls;
int a[N], n;

int bsearch(int x) {
  int mid, l = 0, r = alls.size() - 1;
  while (l < r) {
    mid = (l + r) >> 1;
    if (alls[mid] >= x) r = mid;
    else l = mid + 1;
  }
  return r + 1;
}

int main() {
  #ifdef _DEBUG
  freopen("37.in", "r", stdin);
  #endif

  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    alls.push_back(a[i]);
  }

  sort(alls.begin(), alls.end());
  alls.erase(unique(alls.begin(), alls.end()), alls.end());

  for (int i = 1; i <= n; ++i) printf("%d ", bsearch(a[i]));
  puts("");

  return 0;
}
