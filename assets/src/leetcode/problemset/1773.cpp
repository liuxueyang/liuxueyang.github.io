class Solution {
public:
  int countMatches(vector<vector<string>>& a, string ruleKey, string ruleValue) {
    int res = 0, n = a.size();
    
    for (int i = 0; i < n; ++i) {
      if (ruleKey == "type") {
        if (a[i][0] == ruleValue) res++;
      } else if (ruleKey == "color") {
        res += (a[i][1] == ruleValue);
      } else if (ruleKey == "name") {
        res += a[i][2] == ruleValue;
      }
    }
    return res;
  }
};
