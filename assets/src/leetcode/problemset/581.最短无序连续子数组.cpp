/*
 * @lc app=leetcode.cn id=581 lang=cpp
 *
 * [581] 最短无序连续子数组
 */

#include <algorithm>
#include <vector>
#include <limits>

using namespace std;

// @lc code=start
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int len = int(nums.size());
        int minx = INT_MAX, maxx = INT_MIN;
        bool flag1 = false;
        for (int i = 0; i < len-1; ++i) {
            if (nums[i] > nums[i+1]) {
                flag1 = true;
            }
            if (flag1) minx = min(minx, nums[i+1]);
        }
        if (!flag1) return 0;
        bool flag2 = false;
        for (int i = len-1; i > 0; --i) {
            if (nums[i-1] > nums[i]) {
                flag2 = true;
            }
            if (flag2) maxx = max(maxx, nums[i-1]);
        }
        if (!flag2) return 0;
        int start = -1, end = len;
        for (int i = 0; i < len; ++i) {
            if (nums[i] > minx) {
                start = i; break;
            }
        }
        for (int i = len-1; i >= 0; --i) {
            if (nums[i] < maxx) {
                end = i; break;
            }
        }
        return end - start + 1;
    }
};
// @lc code=end

