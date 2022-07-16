/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

// @lc code=start
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int d[33][33];
        int lens = int(s.size()), lenp = int(s.size());
        memset(d, 0, sizeof d);
        for (int i = 0; i < lens; i++)
        {
            for (int j = 0; j < lenp; j++)
            {
                if (s[i] == p[j] || p[j] == '.')
                {
                    if (i > 0 && j > 0)
                    {
                        d[i][j] |= d[i - 1][j - 1];
                    }
                    else if (i == 0 && j == 0)
                    {
                        d[i][j] |= 1;
                    }
                }
                else if (s[i] != p[j])
                {
                    if (p[j] == '*')
                    {
                        if (j > 0)
                        {
                            if (p[j - 1] == '.' || p[j - 1] == s[i])
                            {
                                if (i > 0)
                                {
                                    d[i][j] |= (d[i - 1][j - 1] |
                                                d[i][j - 1]);
                                    if (j > 2)
                                        d[i][j] |= d[i][j - 2];
                                }
                                else
                                {
                                    if (j - 1 == 0)
                                        d[i][j] |= 1;
                                }
                            }
                            else
                            {
                                if (j > 2)
                                {
                                    d[i][j] |= d[i][j - 2];
                                }
                            }
                            
                        }
                    }
                }
            }
        }
        return d[lens - 1][lenp - 1] == 1;
    }
};
// @lc code=end
