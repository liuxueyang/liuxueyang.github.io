/*
 * @lc app=leetcode.cn id=1053 lang=cpp
 *
 * [1053] 交换一次的先前排列
 * 
 * 從後往前找到第一個逆序 pos
 * 
 * 在 pos 右側，找到比 a[pos] 小，同時最大，並且最靠左邊的位置 cur
 * 交換 a[pos], a[cur]
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int len = int(arr.size());
        if (len <= 1) return arr;
        int pos = -1;
        for (int i = len - 2; i >= 0; --i) {
            if (arr[i] > arr[i + 1]) {
                pos = i;
                break;
            }
        }
        if (pos < 0) { return arr; }
        int cur = pos + 1;
        for (int i = pos + 2; i < len; ++i) {
            if (arr[i] < arr[pos]) {
                if (arr[i] > arr[cur]) {
                    cur = i;
                }
            }
        }
        swap(arr[pos], arr[cur]);
        return arr;
    }
};
// @lc code=end

