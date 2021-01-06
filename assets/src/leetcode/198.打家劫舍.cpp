/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int res = 0, len = int(nums.size());
        if (len == 0) return res;
        int d[123];
        memset(d, 0, sizeof d);

        for (int i = 0; i < len; i++) {
            if (i >= 2) {
                d[i] = max(d[i-1], d[i-2] + nums[i]);
            } else if (i >= 1) {
                d[i] = max(d[i-1], nums[i]);
            } else {
                d[i] = nums[i];
            }

            res = max(res, d[i]);
        }
        return res;
    }
};
// @lc code=end

