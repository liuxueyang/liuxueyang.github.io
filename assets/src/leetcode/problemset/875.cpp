class Solution {
public:

  bool check(vector<int> &a, int h, int s) {
    int sum = 0;
    for (auto &x : a) {
      sum += int(ceil(x * 1.0 / s));
    }

    return sum <= h;
  }

    int minEatingSpeed(vector<int>& a, int h) {
      int left = 1, right = 1e9 + 10, mid;
      while (left < right) {
        mid = (left + right) / 2;
        if (check(a, h, mid)) right = mid;
        else left = mid + 1;
      }

      return right;
    }
};
