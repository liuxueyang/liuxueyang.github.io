/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

#include <string>
#include <cstring>

using namespace std;

// @lc code=start
class Solution
{
public:
    int d[1009][1009];
    string longestPalindrome(string s)
    {
        int len = int(s.size());
        if (len == 0)
            return "";
        memset(d, 0, sizeof d);
        for (int i = 0; i < len; i++)
        {
            d[i][i] = 1;
        }
        int max_len = 1, pos = 0;
        for (int klen = 2; klen <= len; klen++)
        {
            for (int i = 0; i + klen - 1 < len; i++)
            {
                int j = i + klen - 1;
                if (klen == 2)
                {
                    if (s[i] == s[j])
                    {
                        d[i][j] = 2;
                        if (d[i][j] > max_len) {
                            max_len = d[i][j];
                            pos = i;
                        }
                    }
                }
                else
                {
                    if (s[i] == s[j] && s[i + 1] == s[j - 1] && d[i + 1][j - 1])
                    {
                        d[i][j] = d[i + 1][j - 1] + 2;
                        if (d[i][j] > max_len)
                        {
                            max_len = d[i][j];
                            pos = i;
                        }
                    }
                }
            }
        }
        string res(s, pos, max_len);
        return res;
    }
};
// @lc code=end
