#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxPower(string s) {
        char ch = '\0';
        int cnt = 0, res = 0;
        for (auto &x : s) {
            if (!ch) {
                ch = x;
                cnt = 1;
                res = max(res, cnt);
                continue;
            }
            if (ch == x) {
                cnt++;
                res = max(res, cnt);
            } else {
                res = max(res, cnt);
                ch = x;
                cnt = 1;
            }
        }
        if (cnt) {
            res = max(res, cnt);
        }
        return res;
    }
};