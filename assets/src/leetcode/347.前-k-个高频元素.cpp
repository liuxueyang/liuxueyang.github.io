/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */
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

// @lc code=start

using namespace std;
using VI = vector<int>;
using VS = vector<string>;

class Solution {
public:
    using PII = pair<int, int>;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m; for (auto &x : nums) ++m[x];
        priority_queue<PII, vector<PII>, greater<PII>> q;
        VI res;
        for (auto &x : m) {
            int cnt = x.second, y = x.first;
            if (q.size() < k) {
                q.push(PII(cnt, y));
            } else {
                if (q.top().first < cnt) {
                    q.pop(); q.push(PII(cnt, y));
                }
            }
        }
        while (!q.empty()) {
            res.push_back(q.top().second); q.pop();
        }
        return res;
    }
};
// @lc code=end

