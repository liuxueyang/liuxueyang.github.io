class Solution {
public:
    string reverseWords(string s) {
      string res, cur;
      stringstream ss(s);
      vector<string> v;
      
      while (ss >> cur) {
        v.push_back(cur);
      }
      for (int i = v.size() - 1; i >= 0; --i) {
        res += v[i];
        if (i) {
          res += " ";
        }
      }
      return res;
    }
};
