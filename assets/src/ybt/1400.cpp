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


string w;
string a;
bool flag=false;
int pos,f1pos,cnt;

string lowcase(string a)
{
  string s;
  for(size_t i=0;i<a.size();i++)
    {
      s+=tolower(a[i]);
    }
  return s;
}

void find_token()
{
  while (a[pos])
    {
      string t;
      while(a[pos]&&isspace(a[pos]))++pos;
      t="";
      while(a[pos]&&isalpha(a[pos]))
        {
          t+=a[pos++];
        }
      if(lowcase(t)==lowcase(w))
        {
          if(!flag)
            {
              f1pos=pos-t.size();
            }
          flag=true;
          ++cnt;
        }
    }
}

int main( void ) {

#ifdef DEBUG
  freopen("1400.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin>>w;

  string _t;
  getline(cin, _t);

  // NOTE: 输入字符串的长度大于10000，使用string,不能预设长度。
  getline(cin, a);

  find_token();

  if(!flag)
    {
      cout<<-1<<endl;
    }
  else
    {
      cout<<cnt<<" "<<f1pos<<endl;
    }

  return 0;
}
