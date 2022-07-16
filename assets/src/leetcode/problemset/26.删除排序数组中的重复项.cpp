/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int res = 0;
        int len = int(nums.size());
        for (int i = 0; i < len; ++i) {
            if (i == 0)
            {
                ++res;
                continue;
            }
            if (nums[i] == nums[i-1])
            {
                continue;
            }
            else 
            {
                nums[res++] = nums[i];
            }
        }
        return res;
    }
};
// @lc code=end

