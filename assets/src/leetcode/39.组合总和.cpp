/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

#include <vector>
#include <algorithm>
#include <set>

using namespace std;

// @lc code=start
class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        set<int> s;
        for (auto &x : candidates)
        {
            if (x <= target)
                s.insert(x);
        }
        vector<int> can;
        for (auto &x : s)
            can.push_back(x);
        sort(can.begin(), can.end());
        vector<vector<int>> res;
        vector<int> tmp;
        helper(res, can, tmp, target, 0, 0);
        return res;
    }

    void helper(vector<vector<int>> &res,
                vector<int> &can,
                vector<int> current,
                int target, int start, int cur_sum)
    {
        if (start >= can.size() || target < 0)
            return;
        if (0 == target)
        {
            res.push_back(current);
            return;
        }

        for (int i = start; i < can.size(); ++i)
        {
            helper(res, can, current,
                   target, i + 1, cur_sum);
            if (can[i] <= target)
            {
                current.push_back(can[i]);
                helper(res, can, current,
                       target - can[i], i, cur_sum + can[i]);
                current.pop_back();
            }
        }
    }
};
// @lc code=end
