class Solution {
public:
  int findTheWinner(int n, int k) {
    int cur = 1, sum = 0;
    int a[510] {};

    while (sum < n-1) {
      int k1 = 0;

      for (int i = cur; i <= n; ) {
        if (a[i] == 0) {
          ++k1;

          // printf("i=%d k1=%d\n", i, k1);

          if (k1 == k) {
            cur = i;
            break;
          }
        }

        ++i;
        if (i == n+1) i = 1;
      }

      a[cur] = 1;

      // printf("cur=%d\n", cur);

      ++sum;
    }

    for (int i = 1; i <= n; ++i) {
      if (a[i] == 0) return i;
    }
    return 0;
  }
};
