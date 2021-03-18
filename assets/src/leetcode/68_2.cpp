#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& a, int maxWidth) {
        int n = a.size();
        vector<string> res;
        for (int i = 0, j = 0; i < n; ++i) {
            j = i;
            string cur;
            int sum = a[j++].size();
            
            while (j < n) {
                if (sum + 1 + a[j].size() > maxWidth) break;
                sum += 1 + a[j].size();
                ++j;
            }
            j--;

            if (j == n - 1) {
                // lastline
                cur += a[i];
                for (int k = i + 1; k <= j; ++k) cur += " " + a[k];
                cur += string(maxWidth - sum, ' ');
            } else {
                if (i == j) {
                    // one word
                    cur += a[i] + string(maxWidth - sum, ' ');
                } else {
                    cur += a[i];
                    int cnt = j - i + 1;
                    vector<int> space(cnt, 1);
                    int space_count = maxWidth - sum;
                    for (int k = 1; k < cnt; ++k) space[k] += space_count / (cnt - 1);
                    for (int k = 1; k <= space_count % (cnt - 1); ++k) space[k]++;
                    for (int k = i + 1; k <= j; ++k) cur += string(space[k - i], ' ') + a[k];
                }
            }

            i = j;
            res.push_back(cur);
        }
        return res;
    }
};