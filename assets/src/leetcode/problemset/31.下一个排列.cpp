/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = int(nums.size());
        if (len == 1) return;
        int pos = -1;
        for (int i = len-2; i >= 0; --i) {
            if (nums[i] < nums[i+1]) {
                pos = i;
                break;
            }
        }
        for (int i = len-1; pos != -1 && i > pos && i >= 0; --i) {
            if (nums[i] > nums[pos]) {
                swap(nums[pos], nums[i]);
                break;
            }
        }
        for (int i = pos + 1, j = len - 1; i < j; i++, j--) {
            swap(nums[i], nums[j]);
        }
        return;
    }
};
// @lc code=end

