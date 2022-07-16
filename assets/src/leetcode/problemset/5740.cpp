const string s = "aeiou";

class Solution {
public:
  const int cnt[129];

  bool meta(char x) {
    for (const auto &y : s) {
      if (y == x) return true;
    }
    return false;
  }

  int longestBeautifulSubstring(string a) {
    memset(cnt, 0, sizeof cnt);
    int n = a.size(), res = 0;
    char cur = '\0';

    int i, j;
    for (i = 0, j = 0; j < n; ++j) {
      if (meta(a[j])) {
        cnt[a[j]]++;

        for (int k = 'a'; k <= 'u'; ++k) {
          if (meta(k) && k > a[j]) {
            while (cnt[k] > 0) {
              if (meta(a[i])) cnt[a[i]]--;
              ++i;
            }
          }
        }

        cur = '\0';
        for (auto &x : s) {
          if (cnt[x] == 0) break;
          cur = x;
        }

        if (cur == 'u') {
          res = max(j - i + 1, res);
        }
      } else {
        if (cur == 'u') {
          res = max(j - i + 1, res);
        }
      }
    }

    if (cur == 'u') {
      res = max(res, j - i + 1);
    }

    return res;
  }
};
