/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i <= len - 4; ++i)
        {
            if (i - 1 >= 0 && nums[i - 1] == nums[i])
                continue;
            for (int j = i + 1; j <= len - 3; ++j)
            {
                if (j - 1 != i && nums[j] == nums[j - 1])
                    continue;
                int k = j + 1, m = len - 1, tar = target - nums[i] - nums[j],
                    prev_k = nums[k] - 1;

                while (k < m)
                {
                    int tmp = nums[k] + nums[m];
                    if (tar == tmp)
                    {
                        if (prev_k != nums[k])
                        {
                            res.push_back(vector<int>{
                                nums[i],
                                nums[j],
                                nums[k],
                                nums[m],
                            });
                            prev_k = nums[k];
                        }
                        ++k;
                        --m;
                    }
                    else if (tmp < tar)
                    {
                        ++k;
                    }
                    else
                    {
                        --m;
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end
