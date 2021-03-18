#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string align_line(int i, int j, vector<string> a, int width) {
        string res;
        if (j == a.size() - 1) {
            int sum = 0;
            for (int k = i; k <= j; ++k) {
                res += a[k];
                sum += a[k].size();
                if (k != j) {
                    res += ' ';
                    sum++;
                }
            }
            sum = width - sum;
            if (sum > 0) {
                res += string(sum, ' ');
            }
        } else {
            int sum = 0;
            for (int k = i; k <= j; ++k) sum += a[k].size();

            sum = width - sum;
            int cnt = j - i, average = sum;

            if (cnt == 0) {
                res += a[i] + string(sum, ' ');
            } else {
                vector<int> spc(cnt, 0);
                average = sum / cnt;
                if (sum % cnt > 0) {
                    int x = sum % cnt;
                    for (int j = 0; j < x; ++j) spc[j]++;
                }

                for (int k = 0; k < cnt; ++k) spc[k] += average;
                for (int k = i; k <= j; ++k) {
                    res += a[k];
                    if (k != j) {
                        res += string(spc[k-i], ' ');
                    }
                }
            }
        }

        return res;
    }

    vector<string> fullJustify(vector<string>& a, int maxWidth) {
        vector<string> res;
        int n = a.size();
        for (int i = 0; i < n; ++i) {
            int j = i + 1, cur = a[i].size();
            while (j < n) {
                int tmp = cur + a[j].size() + (j - i);
                if (tmp > maxWidth) break;
                cur += a[j].size();
                ++j;
            }
            --j;

            string curs = align_line(i, j, a, maxWidth);
            res.push_back(curs);
            i = j;
        }

        return res;
    }
};