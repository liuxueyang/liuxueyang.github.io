// Date: Mon Oct 18 10:53:29 2021

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

#ifdef _DEBUG

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int val) : val(val), next(nullptr) {}
  ListNode(int val, ListNode *next) : val(val), next(next) {}
};

typedef ListNode LN;
typedef LN* LNP;

#endif



class Bank {
public:
  vector<ll> b;
  int n;

  Bank(vector<long long>& _b) {
    b = _b;
    n = b.size();
  }

  bool check(int x) {
    return x >= 1 && x <= n;
  }

  bool transfer(int account1, int account2, long long money) {
    if (!check(account1) || !check(account2)) return false;

    account1--;
    account2--;

    int x = b[account1];
    if (x >= money) {
      b[account2] += money;
      b[account1] -= money;
      return true;
    }
    return false;
  }

  bool deposit(int account, long long money) {
    if (!check(account)) return false;
    b[account - 1] += money;
    return true;
  }

  bool withdraw(int account, long long money) {
    if (!check(account)) return false;
    account--;
    if (b[account] >= money) {
      b[account] -= money;
      return true;
    }
    return false;
  }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
