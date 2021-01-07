/*
 * @lc app=leetcode.cn id=1247 lang=cpp
 *
 * [1247] 交换字符使得字符串相同
 * 
 * 觀察交換規律，有兩種情況
 * 1. 'xy', 'xy' 此時需要 1 次；
 * 2. 'xy', 'yx' 需要 2 次；
 * 
 * 因此數 'xy' 和 'yx' 的個數，分別爲 ca, cb
 * 由於上下的對稱性，不影響結果的情況下，不妨設 ca>cb
 * 
 * 若 cb 爲奇數，那麼需要從 ca 中拿出一個來和它配對。cb 中剩下的兩兩組合即可。
 * ca 兩兩組合。
 */

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int ca = 0, cb = 0;
        int lena = int(s1.length());
        for (int i = 0; i < lena; i++) {
            if (s1[i] == s2[i]) continue;
            if (s1[i] == 'x' && s2[i] == 'y') ca++;
            else cb++;
        }
        if (ca < cb) swap(ca, cb);

        int res = 0;

        int cc = ca - cb;
        if (cc & 1) return -1;

        if (cb & 1) {
            res += cb/2;
            cb = 1;
            if (ca % 2 == 0) return -1;
            ca--;
            res += ca/2;
            res += 2;
        } else {
            res = ca / 2 + cb / 2;
        }
        return res;
    }
};
// @lc code=end

