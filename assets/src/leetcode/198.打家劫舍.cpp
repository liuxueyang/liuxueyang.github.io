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

        d[0] = nums[0];
        res = max(res, d[0]);
        if (len == 1) return d[0];
        d[1] = nums[1];
        res = max(res, d[1]);
        
        for (int i = 2; i < len; i++) {
            for (int j = 0; j < i - 1; ++j) {
                d[i] = max(d[i], d[j] + nums[i]);
                res = max(res, d[i]);
            }
        }
        return res;
    }
};
// @lc code=end

