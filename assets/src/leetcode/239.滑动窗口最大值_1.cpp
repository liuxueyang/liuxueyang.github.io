#include <vector>

using namespace std;

const int N = 100010;
int q[N];

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        int hh = 0, tt = -1, n = a.size();
        vector<int> res;
        for (int i = 0; i < n; i++) {
            while (hh <= tt && i - q[hh] >= k) ++hh;
            while (hh <= tt && a[q[tt]] < a[i]) --tt;
            q[++tt] = i;
            if (i >= k - 1) res.push_back(a[q[hh]]);
        }
        return res;
    }
};