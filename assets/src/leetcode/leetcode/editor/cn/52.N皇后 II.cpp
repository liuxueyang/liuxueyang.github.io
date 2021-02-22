//n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。 
//
// 给你一个整数 n ，返回 n 皇后问题 不同的解决方案的数量。 
//
// 
//
// 
// 
// 示例 1： 
//
// 
//输入：n = 4
//输出：2
//解释：如上图所示，4 皇后问题存在两个不同的解法。
// 
//
// 示例 2： 
//
// 
//输入：n = 1
//输出：1
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 9 
// 皇后彼此不能相互攻击，也就是说：任何两个皇后都不能处于同一条横行、纵行或斜线上。 
// 
// 
// 
// Related Topics 回溯算法 
// 👍 235 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using VI = vector<int>;
    VI col, row, d1, d2;
    int res, n;

    void dfs(int k) {
        if (k == n) { ++res; return; }
        for (int j = 0; j < n; ++j) {
            if (!col[j] && !d1[k + j] && !d2[k - j + n]) {
                col[j] = d1[k + j] = d2[k - j + n] = 1;
                dfs(k + 1);
                col[j] = d1[k + j] = d2[k - j + n] = 0;
            }
        }
    }

    int totalNQueens(int _n) {
        n = _n;
        col = VI(n, 0), row = VI(n, 0), d1 = VI(2*n, 0), d2 = VI(2*n, 0);
        dfs(0);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
