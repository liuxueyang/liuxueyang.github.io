/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 * 
 * 分兩種情況，第一家是否要打劫。兩次 DP 即可，注意初始值的初始化
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
        if (len == 0) return res;
        if (len == 1) return a[0];
        int d[110];

        memset(d, 0, sizeof(d));
        // use a[0]
        d[0] = d[1] = a[0];
        res = max(res, d[0]);
        for (int i = 2; i < len - 1; i++) {
            d[i] = max(d[i-1], d[i-2] + a[i]);
            res = max(res, d[i]);
        }

        // don't use a[0]
        memset(d, 0, sizeof d);
        d[1] = a[1];
        res = max(res, d[1]);
        for (int i = 2; i < len; i++) {
            d[i] = max(d[i-1], d[i-2] + a[i]);
            res = max(res, d[i]);
        }
        return res;
    }
};
// @lc code=end

