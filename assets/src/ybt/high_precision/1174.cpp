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


int a[300], b[300], c[300];

int main( void ) {

#ifdef DEBUG
  freopen("1174.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  memset(a,0,sizeof(a));
  memset(b,0,sizeof(b));
  memset(c,0,sizeof(c));
  string a1,b1;
  cin>>a1>>b1;
  int lena=a1.size(),lenb=b1.size(),lenc=lena+lenb-1;
  for(int i=lena;i>=1;i--){
    a[i]=a1[lena-i]-'0';
  }
  for(int i=lenb;i>=1;i--){
    b[i]=b1[lenb-i]-'0';
  }
  for(int i=1;i<=lena;i++){
    for(int j=1;j<=lenb;j++){
      int t=i+j-1;
      c[t]+=a[i]*b[j];
      if(c[t]>=10){
        c[t+1]+=c[t]/10;
        c[t]%=10;
      }
    }
  }
  while(c[lenc+1])lenc++;
  while(lenc>0&&!c[lenc])lenc--;
  if(!lenc)cout<<0<<endl;
  else{
    for(int i=lenc;i>=1;--i){
      cout<<c[i];
    }
    cout<<endl;
  }

  return 0;
}
