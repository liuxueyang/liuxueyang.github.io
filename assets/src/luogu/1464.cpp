#include <cstdio>
#include <cstring>

using namespace std;
using ll = long long;
const int N = 22;
ll d[N][N][N];

ll dfs(ll a, ll b, ll c) {
  if (a <= 0 || b <= 0 || c <= 0) return 1;
  if (a > 20 || b > 20 || c > 20) return dfs(20, 20, 20);

  if (d[a][b][c]) return d[a][b][c];

  if (a < b && b < c)
    return d[a][b][c] = dfs(a, b, c-1) + dfs(a, b-1, c-1) - dfs(a,b-1,c);
  return d[a][b][c] = dfs(a-1,b,c)+dfs(a-1,b-1,c)+dfs(a-1,b,c-1)-dfs(a-1,b-1,c-1);
}

int main() {
  #ifdef _DEBUG
  freopen("1464.in", "r", stdin);
  #endif

  ll a, b, c;
  memset(d, 0, sizeof d);
  while (~scanf("%lld%lld%lld\n", &a, &b, &c)) {
    if (a == -1 && b == -1 && c == -1) break;
    printf("w(%lld, %lld, %lld) = %lld\n", a,b,c, dfs(a, b, c));
  }

  return 0;
}
