class Solution {
public:
  int leastMinutes(int n) {
    int v = 1, res = 1;

    while (n > v) {
      res++;
      v *= 2;
    }

    return res;
  }
};
