#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string reverseLeftWords(string s, int k) {
        int n = s.size();
        for (int i = 0, j = k - 1; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
        for (int i = k, j = n - 1; i < j; i++, j--) swap(s[i], s[j]);
        for (int i = 0, j = n - 1; i < j; i++, j--) swap(s[i], s[j]);
        return s;
    }
};
