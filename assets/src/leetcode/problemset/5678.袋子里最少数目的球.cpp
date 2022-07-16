const int INF = 1e9 + 10;

class Solution {
public:
  int minimumSize(vector<int>& nums, int b) {
    int l = 1, r = INF, mid;
    while (l < r) {
      mid = (l + r) >> 1;

      int cnt = 0;
      bool flag = true;
      for (int i = 0; i < int(nums.size()); ++i) {
        if (nums[i] <= mid) continue;
        cnt += nums[i] / mid;
        if (nums[i] % mid == 0) --cnt;
        if (cnt > b) { flag = false; break; }
      }

      if (flag) { r = mid; }
      else l = mid + 1;
    }
    return r;
  }
};
