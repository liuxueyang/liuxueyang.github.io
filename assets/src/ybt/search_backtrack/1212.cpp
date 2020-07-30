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


int R,S,res,cnt;
char a[100][100];
int dir[4][2]={ {0,1},{0,-1},{-1,0},{1,0} }, cc[200];

bool check(int i,int j){
  return (i>=0&&i<R&&
          j>=0&&j<S);
}
void foo(int x,int y){
  int _c=int(a[x][y]);
  ++cc[_c];
  ++cnt;
  res=max_(res,cnt);

  for(int i=0;i<4;i++){
    int x1=x+dir[i][0],y1=y+dir[i][1];
    int _c=int(a[x1][y1]);
    if(!cc[_c]&&check(x1,y1)){
      foo(x1,y1);
      --cc[_c];
      --cnt;
    }
  }
}

int main( void ) {

#ifdef DEBUG
  freopen("1212.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin>>R>>S;
  for(int i=0;i<R;++i){
    cin>>a[i];
  }
  foo(0,0);
  cout<<res;NL;

  return 0;
}
