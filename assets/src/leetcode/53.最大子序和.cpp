/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = 0, len = int(nums.size());
        if (len == 0) return 0;
        int cur = nums[0];
        res = cur;
        for (int i = 1; i < len; i++) {
            if (cur < 0) {
                cur = nums[i];
            } else {
                cur += nums[i];
            }
            if (cur > res) {
                res = cur;
            }
        }
        return res;
    }
};
// @lc code=end

