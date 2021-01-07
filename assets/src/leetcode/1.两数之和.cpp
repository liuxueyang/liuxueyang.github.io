/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> idx;
        vector<int> res;
        for (int i = 0; i < int(nums.size()); ++i) {
            
            if (idx.find(target - nums[i]) != idx.end()) {
                return vector<int>{i, idx[target-nums[i]]};
                break;
            }
            idx[nums[i]] = i;
        }
        return res;
    }
};
// @lc code=end

