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


int main( void ) {

#ifdef DEBUG
  freopen("1226.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int a[7];while(1){
    int sum=0;for(int i=1;i<=6;++i){cin>>a[i];sum+=a[i];}
    if(!sum)break;
    int res=a[6]+a[5]+a[4];
    // 5x5
    if(a[1]<=(36-25)*a[5])a[1]=0;
    else {a[1]-=11*a[5];a[1]=max_(a[1],0);}
    // 4x4
    if(a[2]<=5*a[4]){a[2]=0;
      a[1]-=(5*a[4]-a[2])*2*2;a[1]=max_(a[1],0);
    }
    else a[2]-=5*a[4];
    // 3x3
    int b[4]={0,5,3,1};
    res+=a[3]/4;int t=a[3]%4;if(t){
      ++res;
      if(a[2]>0){
        if(a[2]>=b[t]) {a[2]-=b[t];
          a[1]-=(36-t*9-b[t]*2*2);
          a[1]=max_(a[1],0);
        }
        else{
          a[2]=0;a[1]-=(b[t]-a[2])*2*2+(36-t*9-b[t]*2*2);
          a[1]=max_(a[1],0);
        }
      }
      else{a[1]-=(36-t*9);a[1]=max_(a[1],0);}
    }
    // 2x2
    if(a[2]>0){
      res+=a[2]/9;a[2]%=9;
      if(a[2]>0){
        ++res;
        a[1]-=(36-a[2]*4);a[1]=max_(a[1],0);
      }
    }
    // 1x1
    if(a[1]>0){
      res+=a[1]/36;a[1]%=36;
      if(a[1]>0)++res;
    }
    cout<<res<<endl;
  }

  return 0;
}
