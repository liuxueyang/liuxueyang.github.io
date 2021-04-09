---
layout: post
title:  【一本通】搜索与回溯 13 题
date:   2020-07-28 16:16:09 +0800
---

[Problem 1212](http://ybt.ssoier.cn:8088/problem_show.php?pid=1212)

```cpp
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

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef long long LL;

// ==================================================
#define oo (1LL<<31);
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
//

int R,S,res,cnt;
char a[100][100];
int dir[4][2]={ {0,1},{0,-1},{-1,0},{1,0} }, cc[200];

bool check(int i,int j){
  return (i>=0&&i<R&&
          j>=0&&j<S);
}
void foo(int x,int y){
  int _c=int(a[x][y]);
  ++cc[_c];
  ++cnt;
  res=max_(res,cnt);

  for(int i=0;i<4;i++){
    int x1=x+dir[i][0],y1=y+dir[i][1];
    int _c=int(a[x1][y1]);
    if(!cc[_c]&&check(x1,y1)){
      foo(x1,y1);
      --cc[_c];
      --cnt;
    }
  }
}

int main( void ) {

#ifdef DEBUG
  freopen("1212.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin>>R>>S;
  for(int i=0;i<R;++i){
    cin>>a[i];
  }
  foo(0,0);
  cout<<res;NL;

  return 0;
}
```

[1212.cpp](/assets/src/ybt/search_backtrack/1212.cpp)

----

[Problem 1213](http://ybt.ssoier.cn:8088/problem_show.php?pid=1213)

```cpp
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

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef long long LL;

// ==================================================
#define oo (1LL<<31);
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
//

int a[10][10],cnt,p;

void print(){
  cout<<"No. "<<cnt;NL;
  for(int i=1;i<=8;i++){
    for(int j=1;j<=8;j++){
      cout<<a[j][i]<<" ";
    }NL;
  }
  ++cnt;
}
void bar(int x){
  if(x==9&&p==8){
    print();return;
  }
#define BR {flag=true;break;}
  for(int j=1;j<=8;++j){
    bool flag=false;
    for(int i=x-1;i>=1;--i){
      if(a[i][j]) BR;

      int y1=x-i+j;
      if(y1>=1 && y1 <= 8 && a[i][y1]) BR;

      y1=j-x+i;
      if(y1 >= 1 && y1 <= 8 && a[i][y1]) BR;
    }
    if(flag)continue;
    a[x][j]=1;
    ++p;
    bar(x+1);
    --p;
    a[x][j]=0;
  }
}

/*
  这题需要观察前两个输出，找规律。
  需要把原始输出按 x=y 线对称输出矩阵。
  贡献了好几次 WA
*/

int main( void ) {

#ifdef DEBUG
  // freopen("1213.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cnt=1;
  bar(1);

  return 0;
}
```

[1213.cpp](/assets/src/ybt/search_backtrack/1213.cpp)

----

[Problem 1214](http://ybt.ssoier.cn:8088/problem_show.php?pid=1214)

```cpp
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

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef long long LL;

__attribute__((unused)) static int dir[4][2] = {
  {0, 1}, {1, 0},
  {0, -1},{-1, 0},
};

// ==================================================
#define oo (1LL<<31);
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
//

int a[10][10],cnt,p,n;

void print(){
  if (n == cnt) {
    for(int i=1;i<=8;i++){
      for(int j=1;j<=8;j++){
        if (a[i][j]) cout<<j;
      }
    }NL;
  }

  ++cnt;
}
void bar(int x){
  if(x==9&&p==8){
    print();return;
  }
#define BR {flag=true;break;}
  for(int j=1;j<=8;++j){
    bool flag=false;
    for(int i=x-1;i>=1;--i){
      if(a[i][j]) BR;

      int y1=x-i+j;
      if(y1>=1 && y1 <= 8 && a[i][y1]) BR;

      y1=j-x+i;
      if(y1 >= 1 && y1 <= 8 && a[i][y1]) BR;
    }
    if(flag)continue;
    a[x][j]=1;
    ++p;
    bar(x+1);
    --p;
    a[x][j]=0;
  }
}

int main( void ) {

#ifdef DEBUG
  freopen("1214.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t; cin >> t;
  while (t--) {
    cin >> n;
    cnt=1;
    bar(1);
  }

  return 0;
}
```

[1214.cpp](/assets/src/ybt/search_backtrack/1214.cpp)

----

[Problem 1215](http://ybt.ssoier.cn:8088/problem_show.php?pid=1215)

```cpp
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

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef long long LL;

// ==================================================
#define oo (1LL<<31);
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

__attribute__((unused)) const static int dir[8][2] = {
  {0, 1}, {1, 0},
  {0, -1},{-1, 0},
  {1, 1}, {1, -1},
  {-1,1}, {-1,-1},
};

// ==================================================
//

const int N = 200;
int a[N][N], n, ha, la, hb, lb;
char m[N][N];
bool flag;

bool check(int x, int y) {
  return (x >= 0 && x < n &&
          y >= 0 && y < n &&
          m[x][y] == '.');
}

void dfs(int x, int y) {
  if (flag) return;
  if (x == hb && y == lb) { flag = true; return; }
  a[x][y] = 1;
  for (int i = 0; i < 4; ++i) {
    int x1 = x + dir[i][0], y1 = y + dir[i][1];
    if (flag) break;
    if (check(x1, y1) && !a[x1][y1]) {
      dfs(x1, y1);
      // NOTE: 只需要找到一个解，不需要恢复现场。否则会超时
      // a[x1][y1] = 0;
    }
  }
}

int main( void ) {

#ifdef DEBUG
  freopen("1215.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int k; cin >> k; while (k--) {
    memset(a, 0, sizeof(a));
    flag = false;

    cin >> n;
    for (int i = 0; i < n; ++i) cin >> m[i];
    cin >> ha >> la >> hb >> lb;
    if (m[ha][la] == '#' ||
        m[hb][lb] == '#') {
      cout << "NO\n"; continue;
    }
    dfs(ha, la);
    cout << (flag ? "YES" : "NO") << endl;
  }

  return 0;
}
```

[1215.cpp](/assets/src/ybt/search_backtrack/1215.cpp)

----

[Problem 1216](http://ybt.ssoier.cn:8088/problem_show.php?pid=1216)

```cpp
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

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef long long LL;

// ==================================================

__attribute__((unused)) const static int dir[8][2] = {
  {0, 1}, {1, 0},
  {0, -1},{-1, 0},
  {1, 1}, {1, -1},
  {-1,1}, {-1,-1},
};

// ==================================================
#define oo (1LL<<31);
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
//

int w, h;
char m[50][50];
int a[50][50], cnt;

bool check(int x, int y) {
  return (x >= 0 && x < h &&
          y >= 0 && y < w && !a[x][y] &&
          m[x][y] == '.');
}

void dfs(int x, int y) {
  a[x][y] = 1;
  // PRINT2(x, y);
  ++cnt;
  for (int i = 0; i < 4; ++i) {
    int x1 = x + dir[i][0],
      y1 = y + dir[i][1];
    if (check(x1, y1)) {
      dfs(x1, y1);
    }
  }
}

int main( void ) {

#ifdef DEBUG
  freopen("1216.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  while(cin >> w >> h) {
    if (!w || !h) break;
    int sx, sy;
    for (int i = 0; i < h; ++i) {
      cin >> m[i];
    }
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (m[i][j] == '@') {
          sx = i; sy = j; break;
        }
      }
    }
    memset(a, 0, sizeof(a));
    cnt = 0;
    dfs(sx, sy);
    cout << cnt << endl;
  }

  return 0;
}

```

[1216.cpp](/assets/src/ybt/search_backtrack/1216.cpp)

----

[Problem 1217](http://ybt.ssoier.cn:8088/problem_show.php?pid=1217)

```cpp
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

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef long long LL;

// ==================================================

__attribute__((unused)) const static int dir[8][2] = {
  {0, 1}, {1, 0},
  {0, -1},{-1, 0},
  {1, 1}, {1, -1},
  {-1,1}, {-1,-1},
};

// ==================================================
#define oo (1LL<<31);
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
//

int n, k;
const int N = 10;
char m[N][N];
int a[N][N];
LL res, cnt;

bool col(int j) {
  for (int i = 0; i < n; i++) {
    if ('#' == m[i][j] && a[i][j]) return true;
  }
  return false;
}

void dfs(int x) {
  if (k == cnt) {
    ++res;
    return;
  }
  if (x >= n) return;

  for (int i = 0; i < n; i++) {
    if ('#' == m[x][i] && !col(i)) {
      a[x][i] = 1;
      ++cnt;
      dfs(x + 1);
      a[x][i] = 0;
      --cnt;
    }
  }
  dfs(x + 1);
}

int main( void ) {

#ifdef DEBUG
  freopen("1217.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  while (cin >> n >> k) {
    if (-1 == n || -1 == k) break;
    memset(a, 0, sizeof(a));
    res = cnt = 0;
    for (int i = 0; i < n; ++i) cin >> m[i];

    dfs(0);
    cout << res << endl;
  }

  return 0;
}
```

[1217.cpp](/assets/src/ybt/search_backtrack/1217.cpp)

----

[Problem 1218](http://ybt.ssoier.cn:8088/problem_show.php?pid=1218)

```cpp
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

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef long long LL;

// ==================================================

__attribute__((unused)) const static int dir[8][2] = {
  {0, 1}, {1, 0},
  {0, -1},{-1, 0},
  {1, 1}, {1, -1},
  {-1,1}, {-1,-1},
};

// ==================================================
#define oo (1LL<<31);
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
//

bool dfs(int a, int b) {
  if (a == b) return true;
  if (a < b) swap(a, b);
  if (a >= 2*b) return true;
  return !dfs(b, a - b);
}

int main( void ) {

#ifdef DEBUG
  freopen("1218.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int a,b; while (cin>>a>>b) {
    if(!a || !b) break;
    cout << (dfs(a, b) ? "win" : "lose") << endl;
  }

  return 0;
}
```

[1218.cpp](/assets/src/ybt/search_backtrack/1218.cpp)

----

[Problem 1219](http://ybt.ssoier.cn:8088/problem_show.php?pid=1219)

```cpp
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

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef long long LL;

// ==================================================

__attribute__((unused)) const static int dir[8][2] = {
  {0, 1}, {1, 0},
  {0, -1},{-1, 0},
  {1, 1}, {1, -1},
  {-1,1}, {-1,-1},
};

// ==================================================
#define oo (1LL<<31);
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
//

const int N=12;
int n,m,x,y,vis[N][N],cnt;
LL res;

bool check(int x,int y) {
  return (x >= 0 && x < n &&
          y >= 0 && y < m &&
          !vis[x][y]);
}

void dfs(int x,int y) {
  vis[x][y] = 1;
  ++cnt;
  if(cnt==n*m) {
    ++res;
    return;
  }

  int dx=1, dy=2;
  for (int i=4;i<8;i++) {
    int x1=x+dir[i][0]*dx, y1=y+dir[i][1]*dy;
    if (check(x1, y1)) {
      dfs(x1, y1);
      --cnt;
      vis[x1][y1] = 0;
    }
  }
  dx=2;dy=1;
  for (int i=4;i<8;i++) {
    int x1=x+dir[i][0]*dx, y1=y+dir[i][1]*dy;
    if (check(x1, y1)) {
      dfs(x1, y1);
      --cnt;
      vis[x1][y1] = 0;
    }
  }
}

int main( void ) {

#ifdef DEBUG
  freopen("1219.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t; cin>>t; while(t--) {
    memset(vis, 0, sizeof(vis));
    cnt = res = 0;
    cin>>n>>m>>x>>y;
    dfs(x,y);
    cout<<res<<endl;
  }

  return 0;
}
```

[1219.cpp](/assets/src/ybt/search_backtrack/1219.cpp)

----

[Problem 1220](http://ybt.ssoier.cn:8088/problem_show.php?pid=1220)

```cpp
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

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef long long LL;

// ==================================================
#define oo (1LL<<31);
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
//

const int N = 30;
int c[N], res, n;
string a[N], s;

void appS(string &a, string b, int k) {
  for (int i = k; i < int(b.size()); ++i) a += b[i];
}

void dfs(string x) {
  res = max_(res, int(x.size()));
  for (int i = 0; i < n; ++i) {
    if (c[i] >= 2) continue;
    int lena = int(x.size()), lenb = int(a[i].size()), len = min_(lena,lenb);
    // 不需要判断是否是前缀、后缀，如果出现前缀或者后缀，那么一定不是最长的
    for (int k = 1; k <= len; ++k) {
      bool flag = true;
      for (int j = 0; j < k; ++j) {
        if (a[i][j] != x[lena-k+j]) {
          flag = false;
          break;
        }
      }
      if (flag) {
        string x1 = x;
        ++c[i];
        appS(x1, a[i], k);
        dfs(x1);
        --c[i];
      }
    }
  }
}

int main( void ) {

#ifdef DEBUG
  freopen("1220.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  cin >> s;
  dfs(s);
  cout << res;
  NL;

  return 0;
}
```

[1220.cpp](/assets/src/ybt/search_backtrack/1220.cpp)

----

[Problem 1221](http://ybt.ssoier.cn:8088/problem_show.php?pid=1221)

```cpp
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

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef long long LL;

// ==================================================
#define oo (1LL<<31);
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
//

int gcd(int a,int b) {
  if (a < b) swap(a, b);
  if (a == b) return a;
  if (a % b == 0) return b;
  return gcd(b, a % b);
}

bool check(int a, int b) {
  return gcd(a, b) == 1;
}

const int N = 20;
bool pr[N][N];
int a[N], n, b[N], res, cnt;

void dfs(int pos) {
  if (pos == 0) {
    ++cnt;
    b[pos] = cnt;
    dfs(pos + 1);
    return;
  }
  if (pos == n) {
    res = min_(res, cnt);
    return;
  }
  if (cnt >= res) return;

  for (int j = 1; j <= cnt; ++j) {
    bool flag = true;
    for (int i = 0; i < pos; ++i) {
      if (b[i] == j) {
        if (!pr[i][pos]) {
          flag = false;
          break;
        }
      }
    }
    if (flag) {
      b[pos] = j;
      dfs(pos + 1);
      b[pos] = 0;
    }
  }

  b[pos] = ++cnt;
  dfs(pos + 1);
  --cnt;
  b[pos] = 0;
}

int main( void ) {

#ifdef DEBUG
  freopen("1221.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for(int i = 0; i < n; ++i) cin >> a[i];
  for(int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      pr[i][j] = pr[j][i] = check(a[i], a[j]);
    }
  }

  res = n+1;
  dfs(0);
  cout << res << endl;

  return 0;
}
```

[1221.cpp](/assets/src/ybt/search_backtrack/1221.cpp)

----

[Problem 1222](http://ybt.ssoier.cn:8088/problem_show.php?pid=1222)

```cpp
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

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef long long LL;

// ==================================================

__attribute__((unused)) const static int dir[8][2] = {
  {0, 1}, {1, 0},
  {0, -1},{-1, 0},
  {1, 1}, {1, -1},
  {-1,1}, {-1,-1},
};

// ==================================================
#define oo (1LL<<31);
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
//

int a[20][20];

LL dfs(int m, int n) {
  // PRINT2(m, n);
  if (n == 0) return a[m][n] = 0;
  if (m == 0) return a[m][n] = 1;

  if (a[m][n] != -1) return a[m][n];
  if (m < n) {
    return a[m][n] = dfs(m, m);
  }
  return a[m][n] = dfs(m-n, n) + dfs(m, n-1);
}

int main( void ) {

#ifdef DEBUG
  freopen("1222.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t, m, n; cin >> t; while(t--) {
    cin >> m >> n;
    memset(a, -1, sizeof(a));
    cout << dfs(m, n) << endl;
  }

  return 0;
}
```

[1222.cpp](/assets/src/ybt/search_backtrack/1222.cpp)

----

[Problem 1317](http://ybt.ssoier.cn:8088/problem_show.php?pid=1317)

```cpp
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

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef long long LL;

// ==================================================
#define oo (1LL<<31);
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
//

int n,r,v[50],a[50];
void print(){
  for(int i=1;i<=r;i++)
    cout<<setw(3)<<a[i];
  cout<<endl;
}
void foo(int k){
  for(int i=a[k-1]+1;i<=n;i++){
    if(!v[i]){
      v[i]=1;
      a[k]=i;
      if(k==r)print();
      else foo(k+1);
      v[i]=0;
    }
  }
}

int main( void ) {

#ifdef DEBUG
  freopen("1317.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin>>n>>r;
  foo(1);

  return 0;
}
```

[1317.cpp](/assets/src/ybt/search_backtrack/1317.cpp)

----

