// ==================================================

// C library
#include <cmath>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

// Containers
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>

// Input/Output
#include <iostream>
#include <istream>
#include <ostream>
#include <sstream>
#include <fstream>
#include <ios>
#include <iomanip>

// Other
#include <string>
#include <bitset>
#include <algorithm>
#include <utility>
#include <iterator>
#include <limits>

// ==================================================

using namespace std;

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef long long LL;

// ==================================================

__attribute__((unused)) const static int dir[8][2] = {
  {0, 1}, {1, 0},
  {0, -1},{-1, 0},
  {1, 1}, {1, -1},
  {-1,1}, {-1,-1},
};

// ==================================================
#define oo (1LL<<31);
#define max_(x, y) ((x) > (y) ? (x) : (y))
#define min_(x, y) ((x) > (y) ? (y) : (x))

#define PR(x) cout << #x " = " << (x) << "\t"
#define NL cout << "\n"

#define PRINT1(x) PR(x), NL
#define PRINT2(x1, x2) PR(x1), PRINT1(x2)
#define PRINT3(x1, x2, x3) PR(x1), PRINT2(x2, x3)
#define PRINT4(x1, x2, x3, x4) PR(x1), PRINT3(x2, x3, x4)

// ==================================================

template<typename T>
void PRINTC(const T& a) { cout << a << " "; }

template<typename T>
void PRINTA(const T ar[], int n) {
  for (int i = 0; i < n; ++i) PRINTC(ar[i]); NL;
}

template<typename T1, typename T2>
void PRINTP(const pair<T1, T2>& p) { PRINTC(p.first); PRINTLN(p.second); }

template<typename T>
void PRINTLN(const T& a) { cout << a << "\n"; }

template< typename T1, typename T2 >
void PRINTAV( T1 & vec, T2 x) {
  ostream_iterator< T2 > O( cout, " " );
  copy( begin( vec ), end( vec ), O ); NL;
}

// ==================================================


struct pe{double v; int t;};
pe a[10000+10], b[10000+10];
bool cmp(pe a, pe b){
  if(a.t!=b.t) return a.t<b.t;
  return a.v>b.v;
}

int main( void ) {

#ifdef DEBUG
  freopen("1227.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n; while (cin>>n) {
    if(!n) break;
    for(int i=0;i<n;++i){ cin>>a[i].v>>a[i].t;
      if(a[i].t<0) a[i].t=0;
      a[i].v/=3.6;
    }
    sort(a,a+n,cmp);
    double res=0,d=0,t=4500;
    int j=0;
    for(int i=0;i<n;++i){
      if(!i){
        b[j++]=a[i];continue;
      }
      if(a[i].t==a[i-1].t)continue;
      b[j++]=a[i];
    }

    for(int i=0;i<j;++i) PRINT2(i,b[i].v);

    for(int i=0;i<j;++i) {
      if(i==j-1){
        res+=(t-d)/b[i].v;
        continue;
      }
      int dt=b[i+1].t-b[i].t;
      double d1=b[i].v*dt;
      PRINT2(dt,d1);
      if(d+d1>t){
        res+=(t-d)/b[i].v;
        break;
      } else {
        d+=d1;
        res+=dt;
        if(fabs(d-t)<1e-9) break;
      }
    }
    cout<<int(ceil(res))<<endl;
  }

  return 0;
}
