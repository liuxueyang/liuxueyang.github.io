const int N = 20010, M = 10010;
int n, m, ne[M];
char s[N], p[M];

class Solution {
public:
    bool repeatedSubstringPattern(string s1) {
      m = s1.size();
      n = m * 2;

      for (int i = 0; i < m; ++i)
	p[i + 1] = s[i + 1] = s[i + 1 + m] = s1[i];

      memset(ne, 0, sizeof ne);

      for (int i = 2, j = 0; i <= m; ++i) {
	while (j && p[i] != p[j + 1]) j = ne[j];
	if (p[i] == p[j + 1]) ++j;
	ne[i] = j;
      }

      for (int i = 1, j = 0; i <= n; ++i) {
	while (j && s[i] != p[j + 1]) j = ne[j];
	if (s[i] == p[j + 1]) ++j;
	if (j == m) {
	  int k = i - m + 1;
	  j = ne[j];
	  if (k != 1 && k != (m + 1)) return true;
	}
      }

      return false;
    }
};
