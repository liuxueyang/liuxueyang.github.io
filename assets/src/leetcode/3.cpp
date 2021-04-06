class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int res = 0, n = s.size();
    if (!n || n == 1) return n;
    map<char, int> cnt;

    for (int i = 0, j = 0; j < n; ++j) {
      cnt[s[j]]++;

      if (cnt[s[j]] > 1) {
        while (i < j && s[j] != s[i]) {
          cnt[s[i]]--;
          ++i;
        }
        cnt[s[i]]--;
        ++i;
      }
      res = max(res, j - i + 1);
    }

    return res;
  }
};
