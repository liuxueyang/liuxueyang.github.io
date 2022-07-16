#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    bool check(char a) {
        string s = "aeiou";
        a = tolower(a);
        for (auto &x : s) if (a == x) return true;
        return false;
    }
    string toGoatLatin(string s) {
        string res;
        int n = s.size(), cnt = 1;
        stringstream ss(s);
        string cur;
        while (ss >> cur) {
            if (cnt != 1) res += " ";

            if (check(cur[0])) {
                res += cur + "ma";
            } else {
                cur = cur.substr(1, cur.size() - 1) + cur[0] + "ma";
                res += cur;
            }
            res += string(cnt, 'a');
            cnt++;
        }

        return res;
    }
};