#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int i = 0, j = 0, k1 = 0, k2 = 0;
        char ch1 = '\0', ch2 = '\0';
        while (i < word1.size() || j < word2.size()) {
            if (i == word1.size() || j == word2.size()) return false;

            if (k1 < word1[i].size()) ch1 = word1[i][k1++];
            else {
                ++i;
                k1 = 0;
                if (i == word1.size()) ch1 = '\0';
                else ch1 = word1[i][k1];
                ++k1;
            }

            if (k2 < word2[j].size()) ch2 = word2[j][k2++];
            else {
                ++j;
                k2 = 0;
                if (j == word2.size()) ch2 = '\0';
                else ch2 = word2[j][k2];
                ++k2;
            }

            if (ch1 != ch2) return false;
        }
        return true;
    }
};