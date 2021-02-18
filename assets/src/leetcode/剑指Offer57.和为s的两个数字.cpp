#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    vector<int> res;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 0, j = n - 1; i < j; ++i) {
      while (i < j && nums[i] + nums[j] > target) --j;
      if (i < j && nums[i] + nums[j] == target) {
        res.push_back(nums[i]);
        res.push_back(nums[j]);
        return res;
      }
    }
    return res;
  }
};
