// TODO:

class Solution {
public:
  map<char, int> ms, mt;

  bool check() {
    for (auto &x : ms) {
      if (x.second < mt[x.first]) return false;
    }
    return true;
  }

  string minWindow(string s, string t) {
    ms.clear();
    mt.clear();

    string res;
    int n = s.size(), len = n + 1, start = -1;

    for (auto &x : t) {
      mt[x]++;
    }
    for (int i = 0, j = 0; j < n; ++j) {
      ms[s[j]]++;
      while (check()) {
        ms[s[i++]]--;
      }
    }

    if (start != -1)
      res = s.substr(start, len);

    return res;
  }
};
