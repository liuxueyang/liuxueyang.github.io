//给定一个 没有重复 数字的序列，返回其所有可能的全排列。 
//
// 示例: 
//
// 输入: [1,2,3]
//输出:
//[
//  [1,2,3],
//  [1,3,2],
//  [2,1,3],
//  [2,3,1],
//  [3,1,2],
//  [3,2,1]
//] 
// Related Topics 回溯算法 
// 👍 1146 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using VI = vector<int>;
    VI a, cur, vis; vector<VI> res; int n;
    void dfs(int k) {
        if (k == n) { res.push_back(cur); return; }
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                vis[i] = 1;
                cur.push_back(a[i]);
                dfs(k + 1);
                cur.pop_back();
                vis[i] = 0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size(); sort(nums.begin(), nums.end()); a = nums;
        vis = VI(n, 0); dfs(0);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
