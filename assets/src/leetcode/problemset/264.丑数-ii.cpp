/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
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

using namespace std;
using VI = vector<int>;
using VS = vector<string>;

// @lc code=start
class Solution {
public:
    using ll = long long;
    using VI = vector<ll>;
    int nthUglyNumber(int n) {
        ll res = 1; ll t = 1;
        priority_queue<ll, VI, greater<ll>> q; q.push(1);
        map<ll, int> m; m[1] = 1;
        while (n--) {
            res = q.top(); q.pop();
            t = 2 * res; if (!m[t]) { m[t] = 1; q.push(t); }
            t = 3 * res; if (!m[t]) { m[t] = 1; q.push(t); }
            t = 5 * res; if (!m[t]) { m[t] = 1; q.push(t); }
        }
        return res;
    }
};
// @lc code=end

