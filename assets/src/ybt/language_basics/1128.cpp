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

static int dir[4][2]={ {0,1},{0,-1},{1,0},{-1,0} };

int main( void ) {

#ifdef DEBUG
  freopen("1128.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m, a[120][120], b[120][120];
  cin>>n>>m;
  for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
                         {
                           cin>>a[i][j];
                           b[i][j]=a[i][j];
                         }

  for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
        {
          if(i==1||i==n||
             j==1||j==m) continue;
          else
            {
              int cnt=1;
              b[i][j]=a[i][j];
              for(int c=0;c<4;c++)
                {
                  int i1=i+dir[c][0],j1=j+dir[c][1];
                  if(i1>=1&&i1<=n&&
                     j1>=1&&j1<=m)
                    {
                      cnt++;
                      b[i][j]+=a[i1][j1];
                    }
                }
              b[i][j] = int(round(b[i][j]*1./cnt));
            }
        }
    }
  for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
                         {
                           cout<<b[i][j];
                           cout<<(j==m?"\n":" ");
                         }

  return 0;
}
