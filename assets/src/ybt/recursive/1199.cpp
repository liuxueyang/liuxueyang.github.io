// ==================================================

// C library
#include <cmath>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

// Input/Output
#include <iostream>
#include <istream>
#include <ostream>
#include <sstream>
#include <fstream>
#include <ios>
#include <iomanip>

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

// ==================================================


char a[200],c[200];
bool b[200];
int len;

void foo(int pos)
{
  if(pos==len)
    {
      printf("%s\n",c);
      return;
    }
  for(int i=0;i<len;i++)
    {
      if(!b[int(a[i])])
        {
          b[int(a[i])]=true;
          c[pos]=a[i];
          foo(pos+1);
          b[int(a[i])]=false;
        }
    }
}

int main( void ) {

#ifdef DEBUG
  freopen("1199.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  scanf("%s",a);
  len=strlen(a);
  foo(0);

  return 0;
}
