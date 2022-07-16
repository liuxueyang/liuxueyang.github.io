#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size();
        vector<int> v;
        for (int i = 0; i < n; ++i) {
            if (s1[i] != s2[i]) v.push_back(i);
        }
        if (v.size() > 2 || v.size() == 1) return false;
        if (v.size() == 0) return true;

        int i = v[0], j = v[1];
        return (s1[i] == s2[j] && s1[j] == s2[i]);
    }
};
