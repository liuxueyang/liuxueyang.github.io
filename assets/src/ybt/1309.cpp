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


int a[500],b[500],c[500], lena,lenb,lenc,n;

bool check()
{
  for(int i=1;i<=lenc/2;i++)
    {
      if(c[i]!=c[lenc-i+1])return false;
    }
  return true;
}

void add()
{
  lenb=lena;
  for(int i=1;i<=lena;i++)
    {
      b[i]=a[lena-i+1];
    }
  lenc=lena;
  memset(c,0,sizeof(c));
  for(int i=1;i<=lena;i++)
    {
      c[i+1]=(a[i]+b[i]+c[i])/n;
      c[i]=(a[i]+b[i]+c[i])%n;
    }
  while(c[lenc+1])lenc++;
}

void c2a()
{
  while(!c[lenc])lenc--;
  for(int i=1;i<=lenc;i++)a[i]=c[i];
  lena=lenc;
}

int main( void ) {

#ifdef DEBUG
  freopen("1309.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int cnt=0;
  cin>>n;
  string m;
  cin>>m;
  memset(a,0,sizeof(a));
  memset(b,0,sizeof(b));
  memset(c,0,sizeof(c));
  lena=m.size();
  for(int i=lena;i>=1;i--) {
    if(isdigit(m[lena-i]))
      a[i]=m[lena-i]-'0';
    else a[i]=m[lena-i]-'A'+10;
  }

  bool flag=false;
  for(int i=1;i<=30;i++)
    {
      add();
      if(check())
        {
          // for(int j=lenc;j>=1;j--)cout<<c[j];
          // NL;

          flag=true;
          cnt=i;
          break;
        }
      c2a();
    }
  if(flag)cout<<cnt<<endl;
  else cout<<"Impossible\n";

  return 0;
}
