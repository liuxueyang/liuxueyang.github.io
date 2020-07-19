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
using VI = vector<int>;
static const LL oo = (1LL<<31);

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

const int N=100000+10;
unordered_map<int,int> ed, lc;
unordered_map<int,char> lab;
map<int,VI> gr;
map<char, VI> rev;
VI res;
bool vis[N];
int Size;

class Solution {
public:
  void dfs(int pos) {
    vis[pos] = true;
    char c=lab[pos];

    rev[c].push_back(pos);
    for (auto &x: rev[c]) {
      if(vis[x]) ++lc[x];
    }

    for(auto &x: gr[pos]) {
      if(!vis[x]) {
        dfs(x);
        vis[x] = false;
      }
    }
  }
  vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
    lc.clear(); lab.clear(); gr.clear();
    res.clear(); rev.clear();
    memset(vis, false, sizeof(vis));

    Size = n;
    for(auto &x: edges) {
      int a=x[0]+1, b=x[1]+1;
      lc[a] = lc[b] = 0;
      gr[a].push_back(b);
      gr[b].push_back(a);
    }
    for(int i=0;i<int(labels.size());i++) {
      lab[i+1] = labels[i];
    }
    dfs(1);
    for(int i=0;i<n;i++) {
      res.push_back(lc[i+1]);
    }
    return res;
  }
};


int main( void ) {

#ifdef DEBUG
  freopen("5465.in", "r", stdin);
#endif

  Solution a;
  // vector<VI> edgs = {{0,1},{0,2},{1,4},{1,5},{2,3},{2,6}};
  // vector<VI> edgs = {{0,1},{1,2},{0,3}};
  vector<VI> edgs = {{0,2},{1,2},{0,3}};
  PRINT_CONTAINER(a.countSubTrees(4, edgs, "aeed"));

  return 0;
}
