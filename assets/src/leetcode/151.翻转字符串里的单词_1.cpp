class Solution {
public:
  string reverseWords(string s) {
    int n = s.size(), cur = 0, len = 0;

    for (int i = 0; i < n; ++i) {
      if (s[i] == ' ') {
        if (i > 0 && s[i - 1] != ' ') {
          s[cur++] = s[i];
        }
      } else {
        s[cur++] = s[i];
      }
    }
    if (s[cur-1] == ' ') --cur;
    len = cur;
    s = s.substr(0, len);

    for (int i = 0, j = len - 1; i < j; i++, j--) {
      swap(s[i], s[j]);
    }

    for (int i = 0; i < len; ++i) {
      if (s[i] == ' ') continue;
      int j = i;
      while (j < len && s[j] != ' ') ++j;
      for (int k = i, k1 = j - 1; k < k1; k++, k1--)
        swap(s[k], s[k1]);
      i = j;
    }

    return s;
  }
};
