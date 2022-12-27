// Date: Tue Dec 27 14:57:02 2022

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

int main(void)
{
#ifdef _DEBUG
  freopen("11995.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  int n, op, x;
  while (~scanf("%d", &n)) {
    queue<int> q;
    priority_queue<int> pq;
    stack<int> st;

    vector<bool> guess(3, true);

    while (n--) {
      scanf("%d%d", &op, &x);
      if (op == 1) {
        if (guess[0]) q.push(x);
        if (guess[1]) pq.push(x);
        if (guess[2]) st.push(x);
      } else {
        if (guess[0]) {
          if (q.empty()) guess[0] = false;
          else {
            if (q.front() != x) {
              guess[0] = false;
            } else {
              q.pop();
            }
          }
        }

        if (guess[1]) {
          if (pq.empty()) guess[1] = false;
          else {
            if (pq.top() != x) guess[1] = false;
            else pq.pop();
          }
        }

        if (guess[2]) {
          if (st.empty()) guess[2] = false;
          else {
            if (st.top() != x) guess[2] = false;
            else st.pop();
          }
        }
      }
    }

    int cnt {};
    REP(i, 0, 3) if (guess[i]) cnt++;
    if (cnt > 1) printf("not sure\n");
    else if (cnt == 0) printf("impossible\n");
    else {
      if (guess[0]) printf("queue\n");
      else if (guess[1]) printf("priority queue\n");
      else printf("stack\n");
    }
  }

  return 0;
}
