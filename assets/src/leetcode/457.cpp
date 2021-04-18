const int INF = 0x3f3f3f3f, M = 5000;

// TODO:
class Solution {
public:
  bool circularArrayLoop(vector<int>& a) {
    int n = a.size();

    for (int i = 0; i < n; ++i) {
      if (a[i] >= -1000 && a[i] <= 1000) {
        int j = i, j1;
        while (true) {
          j1 = (j + a[j] + n) % n;
          if (j == j1) {
            a[j] = INF; break;
          }

          if (a[j] * a[j1] < 0) {
            a[j] = INF;
            break;
          }

          if (a[j] > 0) {
            a[i] = M + i;
          } else {
            a[i] = M - i;
          }
        }
      }
    }
  }
};
