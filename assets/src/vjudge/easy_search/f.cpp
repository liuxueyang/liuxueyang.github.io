// Date: Wed Sep 22 18:35:43 2021

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <utility>

using namespace std;

const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const double eps = 1e-8;
const int dir[8][2] = {
  {0, 1}, {0, -1},
  {1, 0}, {-1, 0},
  {1, 1}, {1, -1},
  {-1, 1}, {-1, -1},
};

typedef long long ll;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef pair<string, string> PSS;

string merge(string &a, string &b) {
  string res;
  for (int i = 0; i < int(b.size()); ++i) {
    res += b[i];
    res += a[i];
  }
  return res;
}

PSS split(string s) {
  PSS res;
  int n = s.size();
  res.first = s.substr(0, n / 2);
  res.second = s.substr(n / 2, n / 2);
  return res;
}

int main(void)
{
#ifdef _DEBUG
  freopen("f.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  int T;
  cin >> T;
  for (int _t = 1; _t <= T; ++_t) {
    int n;
    cin >> n;
    string s1, s2, s12;
    cin >> s1 >> s2 >> s12;
    set<string> vis;
    map<string, int> dis;
    queue<string> que;
    int res = 0;
    bool mark = false;

    string cur = merge(s1, s2);
    vis.insert(cur);
    dis[cur] = 1;
    que.push(cur);

    while (!que.empty()) {
      string t = que.front();
      que.pop();

      if (t == s12) {
	mark = true;
	res = dis[t];
	break;
      }

      PSS p = split(t);
      string t1 = p.first, t2 = p.second, t12 = merge(t1, t2);
      if (vis.find(t12) == vis.end()) {
	dis[t12] = dis[t] + 1;
	vis.insert(t12);
	que.push(t12);
      }
    }

    if (mark) { cout << _t << ' ' << res << "\n"; }
    else cout << _t << ' ' << -1 << "\n";
  }

  return 0;
}
