#include <string>

using namespace std;
const int INF = 0x3f3f3f3f;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        string s = "balloon";
        int st[26] {}, sa[26] {}, res = INF;
        for (int i = 0; i < s.size(); i++) {
            st[s[i] - 'a']++;
        }
        for (int i = 0; i < text.size(); i++) {
            sa[text[i] - 'a']++;
        }
        for (int i = 0; i < s.size(); i++) {
            int k = s[i] - 'a';
            int tmp = sa[k] / st[k];
            res = min(res, tmp);
        }
        return res;
    }
};