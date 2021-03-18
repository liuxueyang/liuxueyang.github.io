#include <string>
using namespace std;

class Solution {
public:
    bool check(int i, int j, const string& s) {
        for (int k1 = i, k2 = j; k1 < k2; k1++, k2--) {
            if (s[k1] != s[k2]) return false;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n = s.size();
        for (int i = 0, j = n - 1; i < j; ++i, --j) {
            if (s[i] != s[j]) {
                return check(i + 1, j, s) || check(i, j - 1, s);
            }
        }
        return true;
    }
};
