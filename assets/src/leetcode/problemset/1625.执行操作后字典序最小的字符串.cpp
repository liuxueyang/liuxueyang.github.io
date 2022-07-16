/*
 * @lc app=leetcode.cn id=1625 lang=cpp
 *
 * [1625] 执行操作后字典序最小的字符串
 */

// @lc code=start
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
#include <iomanip>

#include <cmath>
#include <cstdlib>
#include <cstring>

using namespace std;
using VI = vector<int>;
using VS = vector<string>;

class Solution {
public:
    string res;

    string rotate(int n, string s) {
        int len = s.size();
        for (int i = 0, j = n-1; i < j; ++i, --j) {
            swap(s[i], s[j]);
        }
        for (int i = n, j = len-1; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
        for (int i = 0, j = len-1; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
        return s;
    }
    string add_even(int a, string s) {
        int n = s.size();
        for (int i = 0; i < n; i += 2) {
            int c = s[i] - '0';
            c = (c + a) % 10;
            s[i] = c + '0';
        }
        return s;
    }
    string add_odd(int a, string s) {
        int n = s.size();
        for (int i = 1; i < n; i += 2) {
            int c = s[i] - '0';
            c = (c + a) % 10;
            s[i] = c + '0';
        }
        return s;
    }

    string findLexSmallestString(string s, int a, int b) {
        int n = s.size();
        if (b % 2 == 0) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= 10; ++j) {
                    string tmp = add_odd(j * a, s);
                    tmp = rotate(i * b, tmp);
                    if (tmp < res) res = tmp;
                }
            }
        } else {

        }
    }
};
// @lc code=end

