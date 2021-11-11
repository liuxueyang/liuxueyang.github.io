// Date: Thu Nov 11 10:54:59 2021

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

/*
// Definition for a Node.
class Node {
public:
int val;
Node* left;
Node* right;
Node* next;

Node() : val(0), left(NULL), right(NULL), next(NULL) {}

Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

Node(int _val, Node* _left, Node* _right, Node* _next)
: val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
  Node* connect(Node* ro) {
    if (!ro) return ro;

    queue<pair<Node*, int>> q;

    int cur = 1;
    q.push({ro, 1});
    vector<Node*> tmp;

    while (!q.empty()) {
      auto t = q.front();
      q.pop();
      auto node = t.first;
      int level = t.second;

      if (level > cur) {
        int n = tmp.size();
        for (int i = 0; i < n; ++i) {
          if (i == n - 1) tmp[i]->next = nullptr;
          else tmp[i]->next = tmp[i + 1];
        }
        tmp = vector<Node*>{node};
        cur = level;
      } else {
        tmp.push_back(node);
      }

      if (node->left) q.push({node->left, level + 1});
      if (node->right) q.push({node->right, level + 1});
    }

    int n = tmp.size();
    for (int i = 0; i < n; ++i) {
      if (i == n - 1) tmp[i]->next = nullptr;
      else tmp[i]->next = tmp[i + 1];
    }

    return ro;
  }
};
