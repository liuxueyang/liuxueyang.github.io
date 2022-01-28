// Date: Fri Jan 28 09:34:31 2022

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
  int numberOfWeakCharacters(vector<vector<int>>& a) {
    int n = a.size();

    vector<PII> b;
    for (auto &v : a) b.push_back(PII(v[0], v[1]));
    sort(b.begin(), b.end());

    VI post(n, 0);
    post[n - 1] = b[n - 1].second;
    for (int i = n - 2; i >= 0; --i) {
      post[i] = max(b[i].second, post[i + 1]);
    }

    int res {};

    for (int i = 0; i < n; ++i) {
      int l = i + 1, r = n - 1, mid;
      while (l < r) {
        mid = (l + r) / 2;
        if (b[mid].first > b[i].first) r = mid;
        else l = mid + 1;
      }

      if (b[r].first > b[i].first) {
        if (post[r] > b[i].second) res++;
      }
    }

    return res;
  }
};
