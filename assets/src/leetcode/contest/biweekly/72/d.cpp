// Date: Sat Feb 19 22:55:39 2022

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

const int N = 100010;

struct arr
{
  int a,b;
}p[N];
ll a1[N],a2[N],c[N],ans;
int n;

int so(arr x,arr y)
{
  if (x.a==y.a) return x.b>y.b;
  return x.a<y.a;
}

ll sum1(ll x)
{
  ll s=0;
  while (x>0)
    {
      s+=c[x];
      x-=x&(-x);
    }
  return s;
}

void change1(int x)
{
  while (x<=n)
    {
      c[x]++;
      x+=x&(-x);
    }
}

ll sum2(ll x)
{
  ll s=0;
  while (x<=n)
    {
      s+=c[x];
      x+=x&(-x);
    }
  return s;
}

void change2(int x)
{
  while (x>0)
    {
      c[x]++;
      x-=x&(-x);
    }
}

class Solution {
public:
  long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size();
    n = n1;
    VI a(n1, 0);

    map<int, int> m;
    for (int i = 0; i < n; ++i) m[nums2[i]] = i;

    for (int i = 0; i < n; ++i) {
      a[i] = m[nums1[i]];
    }

    for (int i=1;i<=n;i++)
      {
        p[i].a = a[i - 1];
        p[i].b=i;
      }
    sort(p + 1,p+n+1,so);

    memset(a1, 0, sizeof a1);
    memset(a2, 0, sizeof a2);

    for (int i=1;i<=n;i++)
      {
        a1[p[i].b]=sum1(p[i].b);
        change1(p[i].b);
      }
    memset(c,0,sizeof c);
    for (int i=n;i>=1;i--)
      {
        a2[p[i].b]=sum2(p[i].b);
        change2(p[i].b);
      }

    ll ans = 0;
    for (int i=1;i<=n;i++)
      ans+=a1[i]*a2[i];

    return ans;
  }
};
