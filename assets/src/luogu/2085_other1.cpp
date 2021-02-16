#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<queue>
#include<algorithm>

using namespace std;

#define ll long long
#define MAX 500010

//priority_queue<ll> fun;

struct Node
{
  ll val;
  ll X;
  ll from;
};

bool operator <(Node a,Node b)
{
  return a.val>b.val;
}

priority_queue<Node> fun;

ll a[MAX],b[MAX],c[MAX];
ll n,m;

inline ll Function(ll n,ll x)
{
  return a[n]*x*x+b[n]*x+c[n];
}

int main()
{

#ifdef _DEBUG
  freopen("2085.in", "r", stdin);
#endif

  scanf("%lld%lld",&n,&m);

  ll S,num=0,x=0;

  for(int i=1;i<=n;++i)
    {
      scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
      fun.push((Node){Function(i,1),1,i});
    }

  for(ll i=1;i<=m;++i)
    {
      Node Q=fun.top();
      cout<<Q.val<<' ';
      fun.pop();
      fun.push((Node){Function(Q.from,Q.X+1),Q.X+1,Q.from});
    }

  return 0;
}
