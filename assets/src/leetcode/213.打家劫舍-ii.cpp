/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int rob(vector<int>& a) {
        int len = int(a.size()), res = 0;
        if (len == 0 || len == 2) return res;
        if (len == 1) return a[0];
        int d[110];
        memset(d, 0, sizeof(d));
        
    }
};
// @lc code=end

