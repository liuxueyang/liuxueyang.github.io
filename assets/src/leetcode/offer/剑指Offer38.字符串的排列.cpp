#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> res;
  set<string> ss;
  vector<bool> vis;
  string o;

  void dfs(string cur, int c) {
    if (c == o.size()) {
      if (ss.find(cur) == ss.end()) {
        ss.insert(cur);
        res.push_back(cur);
      }
      return;
    }

    for (int i = 0; i < o.size(); ++i) {
      if (!vis[i]) {
        vis[i] = true;
        dfs(cur + o[i], c + 1);
        vis[i] = false;
      }
    }
  }

  vector<string> permutation(string s) {
    o = s;
    int n = s.size();
    for (int i = 0; i < n; ++i) vis.push_back(false);
    dfs("", 0);

    return res;
  }
};
