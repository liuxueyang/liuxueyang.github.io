/*
 * @lc app=leetcode.cn id=463 lang=cpp
 *
 * [463] 岛屿的周长
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int vis[120][120], n, m, res;
    int dir[4][2] = {
            {0, 1}, {1, 0},
            {0, -1}, {-1, 0},
        };

    void dfs(int x, int y, vector<vector<int>> &grid) {
        if (vis[x][y]) return;
        vis[x][y] = 1;
        for (int i = 0; i < 4; ++i) {
            int x1 = x + dir[i][0],
                y1 = y + dir[i][1];
            if (x1 >= 0 && x1 < m &&
                y1 >= 0 && y1 < n) {
                    if (!grid[x1][y1]) res++;
                    if (grid[x1][y1] && !vis[x][y]) 
                        dfs(x1, y1, grid);
            } else res++;
        }
    }

    // 第二种解法
    int islandPerimeter(vector<vector<int>>& grid) {
        memset(vis, 0, sizeof vis);
        res = 0;
        m = int(grid.size());
        if (m == 0) return res;

        n = grid[0].size();
        if (n == 0) return res;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) continue;
                dfs(i, j, grid);
            }
        }
        return res;
    }

    // 第一种解法
    int islandPerimeterV1(vector<vector<int>>& grid) {
        memset(vis, 0, sizeof vis);
        res = 0;
        m = int(grid.size());
        if (m == 0) return res;

        n = grid[0].size();
        if (n == 0) return res;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) continue;
                for (int k = 0; k < 4; ++k) {
                    int i1 = dir[k][0] + i,
                        j1 = dir[k][1] + j;
                    if (i1 >= 0 && i1 < m &&
                        j1 >= 0 && j1 < n) {
                        if (grid[i1][j1] == 0) res++;
                    } else res++;
                }
            }
        }
        return res;
    }
};
// @lc code=end

