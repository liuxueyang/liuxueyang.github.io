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
#include <unordered_set>
#include <unordered_map>

// Input/Output
#include <iostream>
#include <istream>
#include <ostream>
#include <sstream>
#include <fstream>
#include <ios>
#include <iomanip>

// Other
#include <tuple>
#include <string>
#include <tuple>
#include <bitset>
#include <algorithm>
#include <utility>
#include <type_traits>
#include <iterator>
#include <limits>
#include <stdexcept>
#include <random>
#include <chrono>

// ==================================================

using namespace std;

using PII = pair<int, int>;
using LL = long long;
static const LL oo = ((1LL<<31) - 10);

// ==================================================

static auto _2333_ = []() {
                       ios::sync_with_stdio(false);
                       cin.tie(nullptr); return 0; }();

// ==================================================
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
void PRINT_CONTAINER(const T& c) { for (auto &x : c) PRINTC(x); NL; }

template<typename T>
void PRINTV(const vector<T>& c) { PRINT_CONTAINER<vector<T>>(c); }

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


const int N=400;
int a[N][N];

int main( void ) {

#ifdef DEBUG
  freopen("b.in", "r", stdin);
#endif

  int t;
  cin>>t;
  for(int _i=0;_i<t;_i++)
    {
      int n, m;
      cin>>n>>m;
      bool flag=true;
      for(int i=0;i<n;i++)
        {
          for(int j=0;j<m;j++)
            {
              cin>>a[i][j];
              if(!flag)continue;
              if(a[i][j]>4)flag=false;
              if(i==0||i==n-1)
                {
                  if((j==0 || j==m-1) && a[i][j]>2) flag=false;
                  if(a[i][j]>3) flag=false;
                }
              if(j==0||j==m-1)
                {
                  if((i==0 || i==n-1) && a[i][j]>2) flag=false;
                  if(a[i][j]>3) flag=false;
                }
            }
        }
      if(!flag)
        {
          cout<<"NO\n";
          continue;
        }
      cout<<"YES\n";
      // DFS
      for(int i=0;i<n;i++)
        {
          for(int j=0;j<m;j++)
            {
              if(i==0||i==n-1)
                {
                  if(j==0) cout<<2<<" ";
                  else if(j==m-1) cout<<2;
                  else cout<<3<<" ";
                }
              else
                {
                  if(j==0) cout<<3<<" ";
                  else if(j==m-1) cout<<3;
                  else cout<<4<<" ";
                }
            }
          cout<<endl;
        }
    }

  return 0;
}
