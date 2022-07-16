// Date: Thu Jul 14 18:20:04 2022

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

const int N = 30010 * 26;

struct Trie {
  int son[N][26], idx;
  VI cnt[N];

  void init() {
    idx = 0;
    memset(son, 0, sizeof son);
    REP(i, 0, N) cnt[i].clear();
  }

  void insert(string s, int pos) {
    int p = 0;
    for (auto c : s) {
      int i = c - 'a';
      if (!son[p][i]) son[p][i] = ++idx;
      p = son[p][i];
      cnt[p].pb(pos);
    }
  }

  VI& query(string s) {
    int p = 0, n = SZ(s);
    REP(j, 0, n) {
      int i = s[j] - 'a';
      if (!son[p][i]) return cnt[0];
      p = son[p][i];
    }
    return cnt[p];
  }
};

Trie pre, post;

class WordFilter {
public:
  WordFilter(vector<string>& words) {
    pre.init(); post.init();
    REP(i, 0, SZ(words)) {
      auto s = words[i];
      pre.insert(s, i);

      string s1 = s;
      reverse(all(s1));
      post.insert(s1, i);
    }
  }

  int f(string pref, string suff) {
    auto suf1 = suff;
    reverse(all(suf1));

    VI &p1 = pre.query(pref), &p2 = post.query(suf1);
    if (p1.empty() || p2.empty()) return -1;

    int n = SZ(p1), m = SZ(p2), i = n - 1, j = m - 1, ans = -1;
    while (i >= 0 && j >= 0) {
      if (p1[i] > p2[j]) --i;
      else if (p1[i] < p2[j]) --j;
      else {
        ans = p1[i];
        break;
      }
    }

    return ans;
  }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */
