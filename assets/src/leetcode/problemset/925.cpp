#include <string>

using namespace std;

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int n = name.size(), m = typed.size();
        int k1 = 0, k2 = 0;
        for (int i = 0, j = 0; i < n && j < m; i++, j++) {
            char ch1 = name[i], ch2 = typed[j];
            if (ch1 != ch2) return false;
            int cnt1 = 0, cnt2 = 0;
            k1 = i, k2 = j;
            while (k1 < n && name[k1] == name[i]) {
                cnt1++;
                k1++;
            }
            while (k2 < m && typed[k2] == typed[j]) {
                cnt2++;
                k2++;
            }
            if (cnt2 < cnt1) return false;
            i = k1 - 1;
            j = k2 - 1;
        }
        return (k1 == n && k2 == m);
    }
};