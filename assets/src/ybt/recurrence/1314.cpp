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

typedef pair<int, int> PII;
typedef long long LL;

// ==================================================
#define oo ((1LL<<31) - 10);
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


const int N=50;
int a[50][50], dir[4][2]={ {1,1},{1,-1},{-1,1},{-1,-1} };
LL b[N][N];

int main( void ) {

#ifdef DEBUG
  freopen("1314.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n,m,cx,cy,dx,dy;
  cin>>n>>m>>cx>>cy;
  dx=1,dy=2;
  a[cx][cy]=1;
  for(int i=0;i<4;i++){
    int x1=dx*dir[i][0],y1=dy*dir[i][1];
    int x2=cx+x1,y2=cy+y1;
    if(x2>=0&&x2<=n&&
       y2>=0&&y2<=m){
      a[x2][y2]=1;
    }
  }
  dx=2,dy=1;
  for(int i=0;i<4;i++){
    int x1=dx*dir[i][0],y1=dy*dir[i][1];
    int x2=cx+x1,y2=cy+y1;
    if(x2>=0&&x2<=n&&
       y2>=0&&y2<=m){
      a[x2][y2]=1;
    }
  }
  b[0][0]=1LL;
  for(int i=0;i<=n;i++){
    for(int j=0;j<=m;j++){
      if(a[i][j]){
        b[i][j]=0;
        continue;
      }
      if(i>=1)b[i][j]+=b[i-1][j];
      if(j>=1)b[i][j]+=b[i][j-1];
    }
  }
  cout<<b[n][m]<<endl;

  return 0;
}
