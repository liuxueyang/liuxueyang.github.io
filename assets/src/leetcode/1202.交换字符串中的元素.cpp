/*
 * @lc app=leetcode.cn id=1202 lang=cpp
 *
 * [1202] 交换字符串中的元素
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> pos;
    vector<int> root;
    vector<int> rsize;
    void merge(int i, int j) {
        if (i == j) return;
        int r1 = find_root(i), r2 = find_root(j);
        if (r1 > r2) {
            root[j] = i;
            rsize[i] += rsize[j];
        } else {
            root[i] = j;
            rsize[j] += rsize[i];
        }
    }
    int find_root(int i) {
        int res = root[i];
        int tmp = res, prev = i;
        while (tmp != -1) {
            prev = tmp;
            tmp = root[tmp];
        }
        if (i != prev) {
            root[i] = prev;
        }
        return prev;
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        root = vector<int>(s.size(), -1);
        rsize = vector<int>(s.size(), 1);

    }
};
// @lc code=end

