// Date: Wed Nov  3 13:57:39 2021

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

class MyStack {
public:
  queue<int> q1, q2;

  MyStack() {

  }

  void push(int x) {
    q1.push(x);
    while (!q1.empty()) {
      q2.push(q1.front()); q1.pop();
    }
  }

  int pop() {
    if (q2.empty()) return -1;

    int x;
    while (q2.size() > 1) {
      q1.push(q2.front()); q2.pop();
    }
    x = q2.front(); q2.pop();
    while (!q1.empty()) {
      q2.push(q1.front()); q1.pop();
    }

    return x;
  }

  int top() {
    if (q2.empty()) return -1;
    while (q2.size() > 1) {
      q1.push(q2.front()); q2.pop();
    }
    int x = q2.front();
    q1.push(q2.front()); q2.pop();

    while (!q1.empty()) {
      q2.push(q1.front()); q1.pop();
    }

    return x;
  }

  bool empty() {
    return q1.empty() && q2.empty();
  }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
