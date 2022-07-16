const int N = 26;
int q[N];

class Solution {
public:
    int beautySum(string s) {
      int n = s.size(), res = 0;
      for (int i = 0; i < n; ++i) {
	for (int j = 0; j < i; ++j) {
	  memset(q, 0, sizeof q);
	  int tmin = 10000, tmax = 0;
	  for (int k = j; k <= i; ++k) q[s[k] - 'a']++;
	  for (int k = 0; k < 26; ++k) {
	    if (q[k]) {
	      tmin = min(tmin, q[k]);
	      tmax = max(tmax, q[k]);
	    }
	  }
	  res += (tmax - tmin);
	}
      }
      return res;
    }
};
