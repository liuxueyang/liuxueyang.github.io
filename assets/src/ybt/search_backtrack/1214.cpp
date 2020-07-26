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

__attribute__((unused)) static int dir[4][2] = {
  {0, 1}, {1, 0},
  {0, -1},{-1, 0},
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


int a[10][10],cnt,p,n;

void print(){
  if (n == cnt) {
    for(int i=1;i<=8;i++){
      for(int j=1;j<=8;j++){
        if (a[i][j]) cout<<j;
      }
    }NL;
  }

  ++cnt;
}
void bar(int x){
  if(x==9&&p==8){
    print();return;
  }
#define BR {flag=true;break;}
  for(int j=1;j<=8;++j){
    bool flag=false;
    for(int i=x-1;i>=1;--i){
      if(a[i][j]) BR;

      int y1=x-i+j;
      if(y1>=1 && y1 <= 8 && a[i][y1]) BR;

      y1=j-x+i;
      if(y1 >= 1 && y1 <= 8 && a[i][y1]) BR;
    }
    if(flag)continue;
    a[x][j]=1;
    ++p;
    bar(x+1);
    --p;
    a[x][j]=0;
  }
}

int main( void ) {

#ifdef DEBUG
  freopen("1214.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t; cin >> t;
  while (t--) {
    cin >> n;
    cnt=1;
    bar(1);
  }

  return 0;
}
