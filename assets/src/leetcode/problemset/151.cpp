class Solution {
public:
    string reverseWords(string s) {
      int pos = 0, n = s.size();
      // erase space
      for (int i = 0; i < n; ++i) {
        if (isspace(s[i])) {
          if (i == 0) {
            while (i < n && isspace(s[i])) ++i;
            i--;
            continue;
          }
          s[pos++] = s[i++];
          while (i < n && isspace(s[i])) ++i;
          i--;
        } else {
          s[pos++] = s[i];
        }
      }
      if (pos && isspace(s[pos - 1])) pos--;
      s = s.substr(0, pos);
      n = s.size();
      
      for (int i = 0, j = 0; i < n; ++i) {
        if (isspace(s[i])) continue;
        j = i;
        while (j < n && !isspace(s[j])) ++j;
        --j;
        for (int k1 = i, k2 = j; k1 < k2; k1++, k2--)
          swap(s[k1], s[k2]);
        i = j;
      }
      for (int i = 0, j = n - 1; i < j; ++i, --j)
        swap(s[i], s[j]);

      return s;
    }
};
