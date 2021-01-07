/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int len = nums.size();
        for (int i = 0; i <= len - 3; ++i)
        {
            if (i != 0 &&
                nums[i] == nums[i-1]) continue;

            int target = -nums[i];
            int j = i + 1, k = len - 1, pj = nums[j] - 1;
            while (j < k)
            {
                int tmp = nums[j] + nums[k];
                if (tmp == target)
                {
                    if (pj != nums[j])
                    {
                        res.push_back(vector<int>{
                            nums[i], nums[j], nums[k]});
                        pj = nums[j];
                    }
                    ++j;
                    --k;
                }
                else if (tmp < target)
                    ++j;
                else if (tmp > target)
                    --k;
            }
        }
        return res;
    }
};
// @lc code=end
