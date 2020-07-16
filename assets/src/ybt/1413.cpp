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


LL toD(LL x,int n)
{
  LL b=1,r=0;
  while(x)
    {
      if((x%10)>=n)return 0;
      r=r+(x%10)*b;
      b*=n;
      x/=10;
    }
  return r;
}

int main( void ) {

#ifdef DEBUG
  freopen("1413.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  LL p,q,r;
  cin>>p>>q>>r;

  for(int i=2;i<=40;i++)
    {
      LL t1=toD(p,i), t2=toD(q,i),t3=toD(r,i);
      if(t1&&t2&&t3
         &&t1*t2==t3)
        {
          cout<<i<<endl;
          return 0;
        }
    }
  if(p==q&&q==r&&p==1)cout<<1<<endl;
  else
    cout<<0<<endl;

  return 0;
}
