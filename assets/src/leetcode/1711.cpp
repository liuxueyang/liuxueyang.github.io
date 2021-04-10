#include <vector>
#include <cstdio>
#include <unordered_map>
#include <set>

using namespace std;

using VI = vector<int>;
using ll = long long;

const int M = 1e9 + 7;

class Solution {
public:
  int countPairs(vector<int>& a) {
    set<int> s;
    unordered_map<int, int> m;

    for (int i = 0; i <= 21; ++i) s.insert(1 << i);

    int res = 0;

    for (auto &x : a) {
        for (auto &t : s) {
            if (t < x) continue;
            int y = t - x;

            if (m.find(y) != m.end()) {
                int c = m[y];
                res = (res + c) % M;
            }
        }
        m[x]++;
    }

    return res;
  }
};
