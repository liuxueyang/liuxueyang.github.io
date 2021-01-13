//给出一个二维整数网格 grid，网格中的每个值表示该位置处的网格块的颜色。 
//
// 只有当两个网格块的颜色相同，而且在四个方向中任意一个方向上相邻时，它们属于同一连通分量。 
//
// 连通分量的边界是指连通分量中的所有与不在分量中的正方形相邻（四个方向上）的所有正方形，或者在网格的边界上（第一行/列或最后一行/列）的所有正方形。 
//
// 给出位于 (r0, c0) 的网格块和颜色 color，使用指定颜色 color 为所给网格块的连通分量的边界进行着色，并返回最终的网格 grid 。 
//
// 
//
// 示例 1： 
//
// 输入：grid = [[1,1],[1,2]], r0 = 0, c0 = 0, color = 3
//输出：[[3, 3], [3, 2]]
// 
//
// 示例 2： 
//
// 输入：grid = [[1,2,2],[2,3,2]], r0 = 0, c0 = 1, color = 3
//输出：[[1, 3, 3], [2, 3, 3]]
// 
//
// 示例 3： 
//
// 输入：grid = [[1,1,1],[1,1,1],[1,1,1]], r0 = 1, c0 = 1, color = 2
//输出：[[2, 2, 2], [2, 1, 2], [2, 2, 2]] 
//
// 
//
// 提示： 
//
// 
// 1 <= grid.length <= 50 
// 1 <= grid[0].length <= 50 
// 1 <= grid[i][j] <= 1000 
// 0 <= r0 < grid.length 
// 0 <= c0 < grid[0].length 
// 1 <= color <= 1000 
// 
//
// 
// Related Topics 深度优先搜索 
// 👍 22 👎 0

// DFS，遇到边界的时候检查


//leetcode submit region begin(Prohibit modification and deletion)
#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;
using VI = vector<int>;
using VS = vector<string>;


class Solution {
public:
    int m, n;
    int vis[55][55];
    int color, ori_color;
    vector <VI> a;

    int dir[4][2] = {
            {0,  1},
            {0,  -1},
            {1,  0},
            {-1, 0},
    };

    void dfs(int x, int y) {
        vis[x][y] = 1;
        for (int i = 0; i < 4; ++i) {
            int x1 = x + dir[i][0], y1 = y + dir[i][1];
            if (x1 >= 0 && x1 < m && y1 >= 0 && y1 < n) {
                if (!vis[x1][y1]) {
                    if (a[x1][y1] != ori_color) {
                        a[x][y] = -1;
                    } else {
                        dfs(x1, y1);
                    }
                }
            } else {
                // I am on border
                a[x][y] = -1;
            }
        }
    }

    vector <vector<int>> colorBorder(vector <vector<int>> &grid, int r0, int c0, int color) {
        memset(vis, 0, sizeof(vis));
        a = grid;
        m = a.size();
        n = a[0].size();
        ori_color = grid[r0][c0];
        dfs(r0, c0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (a[i][j] == -1) {
                    a[i][j] = color;
                }
            }
        }
        return a;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
