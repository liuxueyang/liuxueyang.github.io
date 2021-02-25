//给定一个整型数组, 你的任务是找到所有该数组的递增子序列，递增子序列的长度至少是2。 
//
// 示例: 
//
// 
//输入: [4, 6, 7, 7]
//输出: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7
//]] 
//
// 说明: 
//
// 
// 给定数组的长度不会超过15。 
// 数组中的整数范围是 [-100,100]。 
// 给定数组中可能包含重复数字，相等的数字应该被视为递增的一种情况。 
// 
// Related Topics 深度优先搜索 
// 👍 249 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using VI = vector<int>;
    vector <VI> res;
    VI cur, a, vis;
    int n;

    void dfs(int k) {
        if (k == n) {
            if (cur.size() > 1) res.push_back(cur);
            return;
        }

        for (int i = 0; i < k; ++i) {
            if (a[i] == a[k] && !vis[i]) {
                dfs(k + 1); return;
            }
        }

        dfs(k + 1);

        if (!cur.size() || cur.back() <= a[k]) {
            cur.push_back(a[k]);
            vis[k] = 1;
            dfs(k + 1);
            vis[k] = 0;
            cur.pop_back();
        }
    }

    vector <vector<int>> findSubsequences(vector<int> &nums) {
        n = nums.size();
        vis = VI(n, 0);
        a = nums;
        dfs(0);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
