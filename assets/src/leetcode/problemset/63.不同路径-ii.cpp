/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
        int m = int(obstacleGrid.size());
        if (m == 0) return 0;
        int n = int(obstacleGrid[0].size());
        if (n == 0) return 0;
        int d[110][110];
        memset(d, 0, sizeof d);
        if (obstacleGrid[0][0] == 1) return 0;
        d[0][0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    d[i][j] = 0;
                } else {
                    if (i > 0) {
                        d[i][j] += d[i-1][j];
                    }
                    if (j > 0) {
                        d[i][j] += d[i][j-1];
                    }
                }
            }
        }
        return d[m-1][n-1];
    }
};
// @lc code=end

