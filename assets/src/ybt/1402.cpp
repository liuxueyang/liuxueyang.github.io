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


char a[30][30];

int main( void ) {

#ifdef DEBUG
  freopen("1402.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  for(char i='A';i<='Z';i++)
    {
      for(char j='A';j<='Z';j++)
        {
          int i1=i-'A',j1=j-'A';
          a[i1][j1]=(i1+j1)%26;
        }
    }
  char k[200];
  cin>>k;
  for(int i=0;k[i];i++)k[i]=toupper(k[i]);
  char C[1100];
  cin>>C;
  string m;
  for(int i=0;C[i];i++)
    {
      int c1=toupper(C[i])-'A', k1=k[i%strlen(k)]-'A', m1=0;
      for(int j=0;j<26;j++)
        {
          if(a[j][k1]==c1)
            {
              m1=j;
              break;
            }
        }
      if(isupper(C[i]))
        {
          m1+='A';
        }
      else m1+='a';
      m+=char(m1);
    }
  cout<<m<<endl;

  return 0;
}
