// Date: Sun Dec  5 23:46:59 2021

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
#include <functional>

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

#define LN ListNode
#define LNP ListNode*
#define TN TreeNode
#define TNP TreeNode*

#ifdef _DEBUG

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int val) : val(val), next(nullptr) {}
  ListNode(int val, ListNode *next) : val(val), next(next) {}
};

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#endif

const int N = 100010;
int h[N], cnt[N], idx;
int e[N], ne[N];

void Init() {
  idx = 0;
  memset(h, -1, sizeof h);
  memset(cnt, 0, sizeof cnt);
}

void Add(int a, int b) {
  e[idx] = b, ne[idx] = h[a], h[a] = idx++;
  cnt[b]++;
}

class Solution {
public:
  vector<vector<int>> validArrangement(vector<vector<int>>& a) {
    // TODO:

    vector<VI> res;

    int n = a.size();
    map<int, VI> m;
    for (int i = 0; i < n; ++i) {
      m[a[i][0]].push_back(i);
    }

    Init();

    for (int i = 0; i < n; ++i) {
      int j = a[i][1];
      if (m.find(j) != m.end()) {
        for (auto &k : m[j]) {
          Add(k, i);
        }
      }
    }

    queue<int> q;
    set<int> s;
    for (int i = 0; i < n; ++i) {
      if (cnt[i] == 0) q.push(i);
      s.insert(i);
    }

    VI b;

    while (!q.empty()) {
      int t = q.front();
      q.pop();
      s.erase(t);
      b.push_back(t);

      for (int i = h[t]; i != -1; i = ne[i]) {
        int j = e[i];
        cnt[j]--;
        if (cnt[j] == 0) q.push(j);
      }
    }

    if (!s.empty()) {
      for (auto &x: s) b.push_back(x);
    }

    reverse(b.begin(), b.end());

    for (auto i : b) {
      res.push_back(a[i]);
    }

    return res;
  }
};
