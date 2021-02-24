//给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,1,2]
//输出：
//[[1,1,2],
// [1,2,1],
// [2,1,1]]
// 
//
// 示例 2： 
//
// 
//输入：nums = [1,2,3]
//输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 8 
// -10 <= nums[i] <= 10 
// 
// Related Topics 回溯算法 
// 👍 602 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using VI = vector<int>;
    VI a, cur, vis; vector<VI> res; int n;
    void dfs(int k) {
        if (k == n) { res.push_back(cur); return; }
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                if (i && a[i] == a[i - 1] && !vis[i - 1]) continue;
                vis[i] = 1;
                cur.push_back(a[i]);
                dfs(k + 1);
                cur.pop_back();
                vis[i] = 0;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size(); sort(nums.begin(), nums.end()); a = nums;
        vis = VI(n, 0);
        dfs(0);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
