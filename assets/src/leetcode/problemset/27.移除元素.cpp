/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int len = int(nums.size());
        int i = 0, j = len - 1;
        while (i <= j)
        {
            while (i <= j && nums[i] != val)
                ++i;
            while (j >= i && nums[j] == val)
                --j;
            if (i <= j)
            {
                swap(nums[i], nums[j]);
                ++i;
                --j;
            }
        }
        return j + 1;
    }
};
// @lc code=end
