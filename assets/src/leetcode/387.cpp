#include <string>
#include <cstring>

using namespace std;

const int N = 30;
int st[N];

class Solution {
public:
    int firstUniqChar(string s) {
        memset(st, 0, sizeof st);
        for (auto &x : s) st[x - 'a']++;
        for (int i = 0; i < s.size(); ++i) {
            if (st[s[i] - 'a'] == 1) return i;
        }
        return -1;
    }
};