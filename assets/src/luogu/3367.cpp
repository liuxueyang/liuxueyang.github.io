#include <cstdio>
#include <cstring>

using namespace std;

const int N = 10010;
int fa[N], sz[N], n, m;

void Init() {
  for (int i = 1; i <= n; ++i) fa[i] = i, sz[i] = 1;
}

int Find(int x) {
  if (x == fa[x]) return x;
  return fa[x] = Find(fa[x]);
}

void Union(int x, int y) {
  int rx = Find(x), ry = Find(y);
  if (rx == ry) return;
  fa[ry] = rx;
  sz[rx] += sz[ry];
}

int main() {
  #ifdef _DEBUG
  freopen("3367.in", "r", stdin);
  #endif

  scanf("%d%d", &n, &m);
  Init();
  int x, y, op;
  while (m--) {
    scanf("%d%d%d", &op, &x, &y);
    if (op == 2) {
      printf("%c\n", Find(x) == Find(y) ? 'Y' : 'N');
    } else Union(x, y);
  }

  return 0;
}
