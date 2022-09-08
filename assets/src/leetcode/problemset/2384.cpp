// Date: Thu Sep  8 21:53:40 2022

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

class Solution {
public:
  string largestPalindromic(string a) {
    int n = SZ(a);
    map<char, int> m, m1;
    set<char> s;

    REP(i, 0, n) {
      m[a[i]]++;
    }

    for (auto &p : m) {
      if (p.second & 1) {
        s.insert(p.f1);
        p.f2--;
        if (p.f2) {
          s.insert(p.first);
          m1[p.first] = p.second;
        }
      } else {
        m1[p.f1] = p.f2;
      }
    }

    string res;
    for (auto it = m1.rbegin(); it != m1.rend(); it++) {
      int cnt = it->f2 / 2;
      if (res.empty() && it->f1 == '0') continue;
      while (cnt--) res += it->f1;
    }
    bool flag = false;

    if (nonempty(s)) {
      flag = true;
      res += *s.rbegin();
    }

    int sz = SZ(res), end = sz;
    if (flag) end--;
    PER(i, 0, end) {
      res += res[i];
    }

    if (res.empty()) res = "0";

    return res;
  }
};
