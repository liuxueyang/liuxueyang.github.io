/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

#include <iostream>
#include <cstring>

using namespace std;

// @lc code=start
class Solution {
public:
    int d[1000];
    int climbStairs(int n) {
        memset(d, 0, sizeof(d));
        d[0] = 1;
        d[1] = 1;
        for (int i = 2; i <= n; i++) {
            d[i] = d[i-1] + d[i-2];
        }
        return d[n];
    }
};
// @lc code=end

