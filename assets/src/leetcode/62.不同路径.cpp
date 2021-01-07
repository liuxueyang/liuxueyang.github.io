/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

#include <iostream>
#include <cstring>

using namespace std;

// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        int d[110][110];
        memset(d, 0, sizeof d);
        d[0][0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || j == 0) {
                    d[i][j] = 1;
                }
                else {
                    d[i][j] = d[i - 1][j] + d[i][j - 1];
                }
            }
        }
        return d[m-1][n-1];
    }
};
// @lc code=end

