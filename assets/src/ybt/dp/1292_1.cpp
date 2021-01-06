#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N1 = 1233, M1 = 511, K1 = 111;
int wn[K1], wm[K1], d[N1][M1], N, M, K;

int main(int argc, char *argv[])
{
  #ifdef DEBUG
  freopen("1292.in", "r", stdin);
#endif // DEBUG

  cin >> N >> M >> K;
  for (int i = 0; i < K; ++i) {
    cin >> wn[i] >> wm[i];
  }
  memset(d, 0, sizeof d);
  int res = 0, resm = 0x3f3f3f3f;
  M--;
  for (int i = 0; i < K; ++i) {
    for (int n = N; n >= wn[i]; --n) {
      for (int m = M; m >= wm[i]; --m) {
        d[n][m] = max(d[n][m], d[n-wn[i]][m-wm[i]] + 1);
        if (d[n][m] > res) {
          res = d[n][m];
        }
      }
    }
  }
  for (int n = N; n >= 0; --n) {
    for (int m = M; m >= 0; --m) {
      if (res == d[n][m]) {
        resm = min(resm, m);
      }
    }
  }
  cout << res << ' ' << (M+1-resm) << endl;

  return 0;
}
