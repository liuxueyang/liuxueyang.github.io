#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int T1 = 1233, M1 = 110;
int T, M, w[M1], c[M1], d[T1];

int main(int argc, char *argv[])
{
#ifdef DEBUG
  freopen("1290.in", "r", stdin);
#endif // DEBUG

  cin >> T >> M;
  for (int i = 0; i < M; ++i) {
    cin >> w[i] >> c[i];
  }
  memset(d, 0, sizeof d);
  for (int i = 0; i < M; ++i) {
    for (int v = T; v >= w[i]; --v) {
      d[v] = max(d[v], d[v-w[i]] + c[i]);
    }
  }
  cout << d[T] << endl;

  return 0;
}
