/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

// @lc code=start
class Solution {
public:
    int d[2525];
    int lengthOfLIS(vector<int>& a) {
        int len = int(a.size());
        if (len == 0) return 0;
        int res = 1;
        memset(d, 0, sizeof d);
        for (int i = 0; i < len; ++i) {
            d[i] = 1;
        }
        for (int i = 1; i < len; ++i) {
            for (int j = 0; j < i; ++j) {
                if (a[j] < a[i]) {
                    d[i] = max(d[i], d[j] + 1);
                    res = max(res, d[i]);
                }
            }
        }
        return res;
    }
};
// @lc code=end

