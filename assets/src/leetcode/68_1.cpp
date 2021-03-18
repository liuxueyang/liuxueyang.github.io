#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& a, int maxWidth) {
        vector<string> res;
        int n = a.size();
        for (int i = 0, j = 0; i < n; ++i) {
            j = i;
            int sum = a[j++].size();
            while (j < n) {
                if (sum + 1 + a[j].size() > maxWidth) break;
                sum += 1 + a[j].size();
                ++j;
            }
            j--;
            string cur;
            if (j == n - 1) {
                // last line
                for (int k = i; k <= j; ++k) {
                    if (k == i) {
                        cur += a[k];
                    } else {
                        cur += " " + a[k];
                    }
                }
                cur += string(maxWidth - sum, ' ');
            } else {
                if (j == i) {
                    // one word
                    cur += a[i];
                    cur += string(maxWidth - sum, ' ');
                } else {
                    int cnt = j - i + 1;
                    sum = maxWidth - sum;
                    vector<int> space(cnt, sum / (cnt - 1));
                    int rem = sum % (cnt - 1);
                    for (int k = 1; k <= rem; ++k) space[k]++;
                    for (int k = i; k <= j; ++k) {
                        if (k == i) cur += a[k];
                        else {
                            cur += string(space[k - i] + 1, ' ') + a[k];
                        }
                    }
                }
            }
            i = j;
            res.push_back(cur);
        }
        return res;
    }
};