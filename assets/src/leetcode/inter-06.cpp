class Solution {
public:
    string compressString(string s) {
      string res, bak;
      bak = s;
      int cnt = 0, n = s.size();

      for (int i = 0, j = 0; i < n; ++i) {
	j = i;
	cnt = 0;
	while (j < n && s[i] == s[j]) {
	  ++cnt;
	  ++j;
	}
	res += s[i];

	string num = to_string(cnt);
	for (auto &x : num) res += x;
	
	i = j - 1;
      }

      if (res.size() >= n) return bak;
      return res;
    }
};
