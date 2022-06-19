// Date: Fri Apr  1 18:33:51 2022

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <climits>

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
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
typedef unsigned long long ull;
typedef vector<int> VI;
typedef pair<int, int> PII;

const ull Pr = 131;

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

class Solution {
public:
  bool canReorderDoubled(vector<int>& a) {
    map<int, int> m1, m2;
    VI a1, a2;

    for (auto &x : a) {
      if (x <= 0) a1.push_back(x);
      else a2.push_back(x);
    }

    sort(a2.begin(), a2.end());
    sort(a1.begin(), a1.end(), greater<int>());

    for (int i = a2.size() / 2; i < a2.size(); ++i) m2[a2[i]]++;
    for (int i = a1.size() / 2; i < a1.size(); ++i) m1[a1[i]]++;

    for (int i = 0; i < a2.size() / 2; ++i) {
      int x = a2[i] * 2;
      if (!m2[x]) return false;
      m2[x]--;
    }

    for (int i = 0; i < a1.size() / 2; ++i) {
      int x = a1[i] * 2;
      if (!m1[x]) return false;
      m1[x]--;
    }

    return true;
  }
};
