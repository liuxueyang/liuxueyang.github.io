/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// @lc code=start
class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int len = int(nums.size()), gap = INT_MAX, sum = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i <= len - 3; ++i)
        {
            int target1 = target - nums[i];
            int j = i + 1, k = len - 1;
            while (j < k)
            {
                int tmp = nums[j] + nums[k];
                int dist = abs(tmp + nums[i] - target);
                if (tmp == target1)
                    return target;
                else if (tmp < target1)
                {
                    ++j;
                }
                else if (tmp > target1)
                {
                    --k;
                }
                if (dist < gap)
                {
                    gap = dist;
                    sum = tmp + nums[i];
                }
            }
        }
        return sum;
    }
};
// @lc code=end
