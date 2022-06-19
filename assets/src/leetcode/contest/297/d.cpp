// Date: Sun Jun 12 11:01:46 2022

#include <bits/stdc++.h>

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
typedef unsigned long long ull;
typedef vector<int> VI;
typedef pair<int, int> PII;

const ull Pr = 131;

#define LN ListNode
#define LNP ListNode*
#define TN TreeNode
#define TNP TreeNode*

#define REP(i, a, b) for (int i = int(a); i < int(b); ++i)
#define PER(i, a, b) for (int i = int(b) - 1; i >= int(a); --i)
#define REP1(i, a, b) for (int i = int(a); i <= int(b); ++i)
#define PER1(i, a, b) for (int i = int(b); i >= int(a); --i)
#define REPE(i, j) for (int i = h[j]; i != -1; i = ne[i])

#define f1 first
#define f2 second
#define pb push_back
#define has(a, x) (a.find(x) != a.end())
#define nonempty(a) (!a.empty())
#define all(a) (a).begin(),(a).end()
#define SZ(a) int((a).size())

#ifdef _DEBUG
#define debug1(x) cout << #x" = " << x << endl;
#define debug2(x,y) cout << #x" = " << x << " "#y" = " << y << endl;
#define debug3(x,y,z) cout << #x" = " << x << " "#y" = " << y << " "#z" = " << z << endl;
#else
#define debug1
#define debug2
#define debug3
#endif

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

const int N = 50010 * 26;
int son[N][26], cnt[N], idx, cnt1[N];

class Trie {
public:
  Trie() {
    idx = 0;
    memset(cnt, 0, sizeof cnt);
    memset(cnt1, 0, sizeof cnt1);
    memset(son, 0, sizeof son);
  }

  void insert(string word) {
    int p = 0;
    for (auto &c : word) {
      int u = c - 'a';
      if (!son[p][u]) son[p][u] = ++idx;
      p = son[p][u];
      cnt1[p]++;
    }

    cnt[p]++;
  }

  bool search(string word) {
    int p = 0;
    for (auto &c : word) {
      int u = c - 'a';
      if (!son[p][u]) return false;
      p = son[p][u];
    }

    return cnt[p] > 0;
  }

  int startsWith(string prefix) {
    int p = 0;
    for (auto &c : prefix) {
      int u = c - 'a';
      if (!son[p][u]) return 0;
      p = son[p][u];
    }
    return cnt1[p];
  }
};

class Solution {
public:
  long long distinctNames(vector<string>& a) {
    ll res = 0;
    Trie tr;
    vector<string> b;
    int n = SZ(a);

    for (auto s : a) {
      auto s1 = s;
      reverse(s1.begin(), s1.end());
      b.pb(s1);
      tr.insert(s1);
    }

    for (auto s : b) {
      auto s1 = s.substr(0, SZ(s) - 1);
      int cnt1 = tr.startsWith(s1);
      cout << cnt1 << ' ' << s1 << '\n';

      if (cnt1 < n) {
        res += (n - 1 - cnt1);
      }
    }

    return res;
  }
};
