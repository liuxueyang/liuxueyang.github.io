class Solution {
public:
  int halfQuestions(vector<int>& a) {
    int n2 = a.size(), res = 0, n = n2 / 2;
    map<int, int> m;

    for (auto &x : a) {
      m[x]++;
    }
    vector<pair<int, int>> p;
    for (auto &x : m) {
      p.push_back(pair<int, int>(x.second, x.first));
    }
    sort(p.begin(), p.end());
    reverse(p.begin(), p.end());

    for (auto &x : p) {
      ++res;
      n -= x.first;
      if (n <= 0) break;
    }

    return res;
  }
};
