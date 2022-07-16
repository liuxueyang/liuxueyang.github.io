/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
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

// @lc code=start
using VI = vector<int>;
using VS = vector<string>;

const int N = 100010;
int q[N];

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        int hh = 0, tt = -1;
        VI res;
        for (int i = 0; i < a.size(); ++i) {
            while (hh <= tt && i - q[hh] + 1 > k) ++hh;
            while (hh <= tt && a[q[tt]] < a[i]) --tt;
            q[++tt] = i;
            if (i >= k - 1) res.push_back(a[q[hh]]);
        }
        return res;
    }
};
// @lc code=end

