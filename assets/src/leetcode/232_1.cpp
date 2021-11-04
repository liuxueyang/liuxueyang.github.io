// Date: Wed Nov  3 12:01:15 2021

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

class MyQueue {
public:
  stack<int> q1, q2;

  MyQueue() {

  }

  void push(int x) {
    q1.push(x);
  }

  int pop() {
    if (q2.empty()) {
      while (!q1.empty()) {
        int t = q1.top();
        q1.pop();
        q2.push(t);
      }
    }

    if (q2.empty()) return -1;
    int t = q2.top();
    q2.pop();
    return t;
  }

  int peek() {
    if (q2.empty()) {
      while (!q1.empty()) {
        int t = q1.top();
        q1.pop();
        q2.push(t);
      }
    }

    if (q2.empty()) return -1;
    return q2.top();
  }

  bool empty() {
    return q1.empty() && q2.empty();
  }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
