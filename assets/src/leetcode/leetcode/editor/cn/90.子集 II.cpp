//给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。 
//
// 说明：解集不能包含重复的子集。 
//
// 示例: 
//
// 输入: [1,2,2]
//输出:
//[
//  [2],
//  [1],
//  [1,2,2],
//  [2,2],
//  [1,2],
//  []
//] 
// Related Topics 数组 回溯算法 
// 👍 390 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using VI = vector<int>;
    VI a, cur; int n; vector<VI> res;
    void dfs(int k) {
        if (k == n) { res.push_back(cur); return; }
        int cnt = 0;
        while (k + cnt < n && a[k + cnt] == a[k]) ++cnt;
        dfs(k + cnt);
        for (int i = 0; i < cnt; ++i) {
            cur.push_back(a[k]);
            dfs(k + cnt);
        }
        while (cnt--) cur.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        n = nums.size();
        sort(nums.begin(), nums.end());
        a = nums;
        dfs(0);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
