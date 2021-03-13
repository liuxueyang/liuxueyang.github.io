class Solution {
public:
  int balancedStringSplit(string s) {
    int st1 = 0, st2 = 0, n = s.size(), res = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == 'L') st1++;
      else st2++;
      if (i) {
        if (st1 == st2) res++;
      }
    }
    return res;
  }
};
