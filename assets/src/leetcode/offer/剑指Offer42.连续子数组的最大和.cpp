#include <vector>

using namespace std;

class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int res = 0;
    if (nums.size() == 0) return res;
    res = nums[0];
    int tmp = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
      if (tmp < 0) tmp = nums[i];
      else tmp += nums[i];
      res = max(res, tmp);
    }
    return res;
  }
};
