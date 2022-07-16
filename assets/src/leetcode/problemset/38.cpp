#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string describe(string s) {
        string result;
        char ch = '\0';
        int cnt = 0;
        for (auto &x : s) {
            if (!ch) {
                ch = x;
                cnt = 1;
                continue;
            }
            if (ch == x) {
                cnt++;
            } else {
                string num = to_string(cnt);
                result = result + num + ch;
                cnt = 1;
                ch = x;
            }
        }
        if (cnt) {
            string num = to_string(cnt);
            result = result + num + ch;
        }

        return result;
    }
    string countAndSay(int n) {
        vector<string> v {"1"};
        for (int i = 1; i < n; i++) {
            v.push_back(describe(v[i - 1]));
        }
        return v[n - 1];
    }
};