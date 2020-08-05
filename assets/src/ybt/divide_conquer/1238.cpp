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
#define oo (1LL<<31)
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


double a,b,c,d,eps=1e-9,x1,x2,x,y;
int cnt;

inline double f(double x){return a*x*x*x+b*x*x+c*x+d;}
void solve(){
  cout.precision(2);cout.setf(ios::fixed,ios::floatfield);
  for(int i=-100;i<=100;++i){
    x1=i;x2=i+1;y=f(x1)*f(x2);
    // NOTE: 判断0的时候不需要使用fabs和eps比较
    if(f(x1)==0){++cnt;if(cnt!=1)cout<<" ";cout<<x1;continue;}
    if(y<0){
      while(x2-x1>=0.001){
        x=(x1+x2)/2;if(f(x1)*f(x)>0){x1=x;}else{x2=x;}
      }
      ++cnt;if(cnt!=1)cout<<" ";cout<<x1;
    }
  }
}

int main( void ) {

#ifdef DEBUG
  freopen("1238.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin>>a>>b>>c>>d;solve();NL;

  return 0;
}
