/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        int i = 0, j = len - 1, res = 0;
        while (i < j) {
            if (height[i] > height[j]) {
                res = max(res, (j-i) * height[j]);
                --j;
            } else {
                res = max(res, (j - i) * height[i]);
                ++i;
            }
        }
        return res;
    }
};
// @lc code=end

