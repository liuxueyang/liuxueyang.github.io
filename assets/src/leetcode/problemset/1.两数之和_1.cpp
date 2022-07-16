/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int>& a, int target) {
    vector<int> A = a;
    sort(a.begin(), a.end());
    vector<int> res;

    int x, y;
    for (int i = 0, j = a.size() - 1; i < j; ++i) {
      while (j > i && a[i] + a[j] > target) --j;
      if (a[i] + a[j] == target) {
        x = a[i];
        y = a[j];
        break;
      }
    }

    for (int i = 0; i < A.size(); ++i) {
      if (A[i] == x || A[i] == y) res.push_back(i);
    }
    return res;
  }
};
// @lc code=end

