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


int pos;

int get_int(char *a)
{
  int s=0;
  while(isspace(a[pos]))pos++;
  while(isdigit(a[pos]))
    {
      s=s*10+(a[pos]-'0');
      pos++;
    }
  return s;
}

char get_op(char*a)
{
  while(isspace(a[pos]))pos++;
  return a[pos++];
}

int eval_exp(char op, int i1, int i2)
{
  switch(op)
    {
    case '+': return i1+i2;
    case '-':return i1-i2;
    case '/':return i1/i2;
    case '%':return i1%i2;
    case '*':return i1*i2;
    }
  return 0;
}

int main( void ) {

#ifdef DEBUG
  freopen("1397.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  char a[1000];
  cin.getline(a,999);

  int i1=get_int(a);
  char op=get_op(a);
  int i2=get_int(a);
  // PRINT3(i1,op,i2);
  cout<<eval_exp(op, i1, i2)<<endl;

  return 0;
}
