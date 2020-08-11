---
layout: post
title:  【一本通】分治 18 题
date:   2020-08-11 08:52:42 +0800
---

[Problem 1234](http://ybt.ssoier.cn:8088/problem_show.php?pid=1234)

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
#define oo (1LL<<31)
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


int k;
const int N=300, M=10000;
int a[N], r[600], n, q = 2011;
char b[N];

int main( void ) {

#ifdef DEBUG
  freopen("1234.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  do
    {
      r[++n] = q;
      q = (q*2011) % M;
    } while (q != 2011);
  r[0] = r[n];

  cin >> k;
  while (k--) {
    cin >> b;
    int len = int(strlen(b));
    for (int i = 0; i < len; ++i) {
      a[i+1] = b[i] - '0';
    }
    int x=0;
    for (int i = 1; i <= len; ++i) {
      x = (x * 10 + a[i]) % n;
    }
    cout << r[x] << "\n";
  }

  return 0;
}
```

[1234.cpp](/assets/src/ybt/divide_conquer/1234.cpp)

----

[Problem 1235](http://ybt.ssoier.cn:8088/problem_show.php?pid=1235)

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
#define oo (1LL<<31)
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


const int N=100000+100;
int a[N], n, k;

void qso(int l, int r) {
  if (l >= r) return;
  int mid = a[(l+r)/2], i = l, j = r;
  do
    {
      while (a[i] > mid)++i;
      while (a[j] < mid)--j;
      if (i <= j) {
        swap(a[i], a[j]);
        ++i;--j;
      }
    } while (i <= j);
  if (i < r) qso(i, r);
  if (j > l) qso(l, j);
}

int main( void ) {

#ifdef DEBUG
  freopen("1235.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i+1];
  }
  cin >> k;
  qso(1, n);
  for (int i = 1; i <= k; ++i) {
    cout << a[i] << "\n";
  }


  return 0;
}
```

[1235.cpp](/assets/src/ybt/divide_conquer/1235.cpp)

----

[Problem 1236](http://ybt.ssoier.cn:8088/problem_show.php?pid=1236)

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
#define oo (1LL<<31)
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


const int N = 10000+100;
bool a[N];
int n;

int main( void ) {

#ifdef DEBUG
  freopen("1236.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  int mi = N, ma = -1;
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    mi = min_(mi, x);
    ma = max_(ma, y);
    for (int j = x; j < y; ++j) {
      a[j] = true;
    }
  }
  for (int i = mi; i < ma; ++i) {
    if (!a[i]) {
      cout << "no" << "\n";
      return 0;
    }
  }
  cout << mi << " " << ma << "\n";

  return 0;
}

```

[1236.cpp](/assets/src/ybt/divide_conquer/1236.cpp)

----

[Problem 1237](http://ybt.ssoier.cn:8088/problem_show.php?pid=1237)

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
#define oo (1LL<<31)
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


const int N=101000;
int a[N],b[N],c[N],n;
LL res;

void merge(int l,int r){
  if(l==r){b[l]=a[l];return;}
  if(l>r)return;
  int mid=(l+r)>>1,i=l,j=mid+1,k=l;
  merge(l,mid);merge(mid+1,r);
  while(k<=r){
    if(i>mid){
      while(j<=r)c[k++]=b[j++];break;
    }else if(j>r){
      while(i<=mid)c[k++]=b[i++];break;
    }
    while(i<=mid && j<=r && b[i]<=b[j])c[k++]=b[i++];
    while(i<=mid && j<=r && b[i]>b[j]){
      res+=(mid-i+1);c[k++]=b[j++];
    }
  }
  for(int i=l;i<=r;++i)b[i]=c[i];
}

int main( void ) {

#ifdef DEBUG
  freopen("1237.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin>>n;for(int i=1;i<=n;++i)cin>>a[i];
  merge(1,n);cout<<res<<endl;

  return 0;
}
```

[1237.cpp](/assets/src/ybt/divide_conquer/1237.cpp)

----

[Problem 1238](http://ybt.ssoier.cn:8088/problem_show.php?pid=1238)

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
#define oo (1LL<<31)
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


double a,b,c,d,eps=1e-9,x1,x2,x,y;
int cnt;

inline double f(double x){return a*x*x*x+b*x*x+c*x+d;}
void solve(){
  cout.precision(2);cout.setf(ios::fixed,ios::floatfield);
  for(int i=-100;i<=100;++i){
    x1=i;x2=i+1;y=f(x1)*f(x2);
    // NOTE: 判断 0 的时候不需要使用 fabs 和 eps 比较
    if(f(x1)==0){++cnt;if(cnt!=1)cout<<" ";cout<<x1;continue;}
    if(y<0){
      while(x2-x1>=0.001){
        x=(x1+x2)/2;if(f(x1)*f(x)>0){x1=x;}else{x2=x;}
      }
      ++cnt;if(cnt!=1)cout<<" ";cout<<x1;
    }
  }
}

int main( void ) {

#ifdef DEBUG
  freopen("1238.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin>>a>>b>>c>>d;solve();NL;

  return 0;
}
```

[1238.cpp](/assets/src/ybt/divide_conquer/1238.cpp)

----

[Problem 1239](http://ybt.ssoier.cn:8088/problem_show.php?pid=1239)

```cpp
// ==================================================

// C library
#include <cstdio>
#include <cstdlib>

// Input/Output
#include <iostream>

// ==================================================

using namespace std;

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
#define oo (1LL<<31)
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


const int N = 200000 + 100;
int a[N], n;

void qso(int l, int r) {
  if (l >= r) return;
  int mid = a[(l+r)>>1], i = l, j = r;
  while (i <= j) {
    while (a[i] < mid) {
      ++i;
    }
    while (a[j] > mid) {
      --j;
    }
    if (i <= j) {
      swap(a[i], a[j]);
      ++i;
      --j;
    }
  }
  if (i < r) qso(i, r);
  if (j > l) qso(l, j);
}

int main( void ) {

#ifdef DEBUG
  freopen("1239.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i+1];
  }
  qso(1, n);
  int s = 1;
  for (int i = 2; i <= n; ++i) {
    if (a[i] == a[i-1]) {
      ++s;
      continue;
    }
    else {
      cout << a[i-1] << " " << s << "\n";
      s = 1;
    }
  }
  cout << a[n] << " " << s << "\n";

  return 0;
}
```

[1239.cpp](/assets/src/ybt/divide_conquer/1239.cpp)

----

[Problem 1240](http://ybt.ssoier.cn:8088/problem_show.php?pid=1240)

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
#define oo (1LL<<31)
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


const int N = 100000 + 100;
int a[N], n, m, x;

int main( void ) {

#ifdef DEBUG
  freopen("1240.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i+1];
  }
  cin >> m;
  while (m--) {
    cin >> x;
    int l = 1, r = n, mid;
    while (l < r-1) {
      mid = (l+r)>>1;
      if (a[mid] > x) r = mid;
      else l = mid;
    }
    if (abs(a[l] - x) <= abs(a[r] - x))
      cout << a[l] << "\n";
    else {
      cout << a[r] << "\n";
    }
  }

  return 0;
}
```

[1240.cpp](/assets/src/ybt/divide_conquer/1240.cpp)

----

[Problem 1241](http://ybt.ssoier.cn:8088/problem_show.php?pid=1241)

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
#define oo (1LL<<31)
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


double fac(double x, int n) {
  double res=1;
  for (int i = 1; i <= n; ++i) {
    res *= x;
  }
  return res;
}

// f(x)=x5−15x4+85x3−225x2+274x−121
double f(double x) {
  return fac(x,5) - 15*fac(x,4) + 85*fac(x,3) - 225*fac(x,2) +
    274*x - 121;
}

int main( void ) {

#ifdef DEBUG
  freopen("1241.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  double l=1.5*1e6, r = 2.4*1e6, mid;
  while (r - l > 1) {
    mid = (l+r) / 2;
    if (f(mid/1e6) > 0) l = mid;
    else if (f(mid/1e6) < 0) r = mid;
    else break;
  }
  cout.precision(6);
  cout.setf(ios::fixed, ios::floatfield);
  cout << mid/1e6 << "\n";

  return 0;
}
```

[1241.cpp](/assets/src/ybt/divide_conquer/1241.cpp)

----

[Problem 1242](http://ybt.ssoier.cn:8088/problem_show.php?pid=1242)

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
#define oo (1LL<<31)
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


const int N = 10000+100;
int a[N], K, n;

int bcnt(int len) {
  if (len == 0) {
    return 0;
  }
  int l = 1, r = n, mid, pos, res = 0;
  while (l + 1 < r) {
    mid = (l+r)/2;
    if (a[mid] >= len) {
      r = mid;
    } else {
      l = mid+1;
    }
  }
  pos = (a[l] >= mid ? l : r);
  for (int i = pos; i <= n; ++i) {
    res += a[i] / len;
  }
  return res;
}

int main( void ) {

#ifdef DEBUG
  freopen("1242.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  /*
   * sample input:
   1 3
   0.02
  */

  cin >> n >> K;
  double t;
  int low = 0, high = 0, mid, cnt;
  for (int i = 1; i <= n; ++i) {
    cin >> t;
    a[i] = int(floor(t*100.0));
    high = max_(high, a[i]);
  }

  sort(a+1, a+1+n);
  cout.precision(2);
  cout.setf(ios::floatfield, ios::fixed);

  while (low + 1 < high) {
    mid = (low+high)/2;
    if (mid == 0) {
      break;
    }
    cnt = bcnt(mid);
    if (cnt >= K) {
      low = mid;
    } else {
      high = mid-1;
    }
  }
  cnt = bcnt(high);

  if (cnt >= K) {
    cout << high*1.0/100 << "\n";
  } else {
    if (bcnt(low) >= K) {
      cout << low*1.0/100 << "\n";
    } else {
      cout << "0.00" << "\n";
    }
  }


  return 0;
}
```

[1242.cpp](/assets/src/ybt/divide_conquer/1242.cpp)

----

[Problem 1243](http://ybt.ssoier.cn:8088/problem_show.php?pid=1243)

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
#define oo (1LL<<31)
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


const int N = 100000 + 100;
int a[N], n, m;

int fdays(int amo) {
  int k = 1, cur = 0;
  for (int i = 1; i <= n; ++i) {
    if (cur + a[i] > amo) {
      ++k;
      cur = a[i];
      if (k > m) {
        return k;
      }
    } else {
      cur += a[i];
    }
  }

  return k;
}

int main( void ) {

#ifdef DEBUG
  freopen("1243.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  LL high = 0, low = 0, mid;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    high += a[i];
    low = max_(low, a[i]);
  }
  int days;
  while (low + 1 < high) {
    mid = low + (high-low)/2;
    days = fdays(mid);
    if (days > m) {
      low = mid+1;
    } else {
      high = mid;
    }
  }
  days = fdays(low);
  // PRINT3(low, high, days);
  if (days <= m) {
    cout << low << "\n";
  } else {
    cout << high << "\n";
  }

  return 0;
}
```

[1243.cpp](/assets/src/ybt/divide_conquer/1243.cpp)

----

[Problem 1244](http://ybt.ssoier.cn:8088/problem_show.php?pid=1244)

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
#define oo (1LL<<31)
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


const int N = 100000 + 100;
int a[N], n, m;

void qso(int l, int r) {
  if (l >= r) return;
  int mid = a[(l+r)>>1], i = l, j = r;
  while (i <= j) {
    while (a[i] < mid) {
      ++i;
    }
    while (a[j] > mid) {
      --j;
    }
    if (i <= j) {
      swap(a[i], a[j]);
      ++i;
      --j;
    }
  }
  if (i < r) qso(i, r);
  if (j > l) qso(l, j);
}

int main( void ) {

#ifdef DEBUG
  freopen("1244.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  cin >> m;
  qso(1, n);

  int l = 1, r = n;
  while (l < r) {
    int t = a[l] + a[r];
    if (t < m) ++l;
    else if (t > m) --r;
    else {
      cout << a[l] << " " << a[r] << "\n";
      return 0;
    }
  }
  cout << "No" << "\n";


  return 0;
}
```

[1244.cpp](/assets/src/ybt/divide_conquer/1244.cpp)

----

[Problem 1245](http://ybt.ssoier.cn:8088/problem_show.php?pid=1245)

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
#define oo (1LL<<31)
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


const int N = 100000+100;
int n, a[N];

void qso(int l, int r) {
  if (l >= r) return;
  int mid = a[(l+r)>>1], i = l, j = r;
  while (i <= j) {
    while (a[i] < mid) {
      ++i;
    }
    while (a[j] > mid) {
      --j;
    }
    if (i <= j) {
      swap(a[i], a[j]);
      ++i;
      --j;
    }
  }
  qso(i, r);
  qso(l, j);
}

int main( void ) {

#ifdef DEBUG
  freopen("1245.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  if (n == 1) {
    cout << a[1] << "\n";
    return 0;
  }

  qso(1, n);
  bool flag=false;

  for (int i = 2; i <= n; ++i) {
    if (a[i] == a[i-1]) continue;
    else {
      if (!flag) {
        cout << a[i-1];
        flag = true;
      }
      else {
        cout << " " << a[i-1];
      }
    }
  }
  cout << " " << a[n] << "\n";

  return 0;
}
```

[1245.cpp](/assets/src/ybt/divide_conquer/1245.cpp)

----

[Problem 1246](http://ybt.ssoier.cn:8088/problem_show.php?pid=1246)

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
#define oo (1LL<<31)
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


double L1, n, C, L2, pi, eps = 1e-12;

int main( void ) {

#ifdef DEBUG
  freopen("1246.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  pi = acos(-1.0);
  cin >> L1 >> n >> C;
  L2 = (1+n*C)*L1;
  L1 /= 2;
  L2 /= 2;

  double low = 0, high = pi, mid, s1 = 2*L2/L1, s2;
  while (high - low > eps) {
    mid = (low + high) / 2;
    s2 = mid / sin(mid/2);

    if (s2 < s1) {
      low = mid;
    } else {
      high = mid;
    }
  }

  cout.precision(3);
  cout.setf(ios::floatfield, ios::fixed);

  double r = L2/(mid/2);
  cout << r - r*cos(mid/2) << "\n";

  return 0;
}
```

[1246.cpp](/assets/src/ybt/divide_conquer/1246.cpp)

----

[Problem 1247](http://ybt.ssoier.cn:8088/problem_show.php?pid=1247)

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
#define oo (1LL<<31)
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


const int N = 50000+10;
int a[N],b[N],l,n,m;

int rcnt(int len) {
  for (int i = 0; i <= n; ++i) {
    b[i] = a[i];
  }
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    if (b[i] - b[i-1] < len) {
      b[i] = b[i-1];
      ++cnt;
      if (cnt > m) {
        return cnt;
      }
    }
  }
  return cnt;
}

int main( void ) {

#ifdef DEBUG
  freopen("1247.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> l >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  a[0] = 0;
  a[++n] = l;
  sort(a, a+1+n);
  int low = 1, high = l, cnt;
  while (low < high-1) {
    int mid = (low + high) >> 1;
    cnt = rcnt(mid);
    if (cnt > m) {
      high = mid;
    }
    else {
      low = mid;
    }
  }
  cnt = rcnt(high);
  if (cnt <= m) {
    cout << high << "\n";
    return 0;
  }
  cout << low << "\n";

  return 0;
}
```

[1247.cpp](/assets/src/ybt/divide_conquer/1247.cpp)

----

[Problem 1325](http://ybt.ssoier.cn:8088/problem_show.php?pid=1325)

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
#define oo (1LL<<31)
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

const int N=1100;
int n,m,a[N][N];

void solve(int x){
  if(x==1){
    a[1][1]=a[2][2]=1;
    a[1][2]=a[2][1]=2;return;
  }
  solve(x-1);
  int len=1<<(x-1);
  for(int i=1;i<=len;++i)for(int j=1;j<=len;++j)a[i][j+len]=a[i][j]+len;
  for(int i=1;i<=len;++i)for(int j=1;j<=len;++j)a[i+len][j]=a[i][j]+len;
  for(int i=1;i<=len;++i)for(int j=1;j<=len;++j)a[i+len][j+len]=a[i][j];
}
void print(){
  n=1<<m;for(int i=1;i<=n;++i){
    for(int j=1;j<=n;++j){
      cout<<a[i][j];if(j==n)cout<<endl;else cout<<" ";
    }
  }
}

int main( void ) {

#ifdef DEBUG
  freopen("1325.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin>>m;solve(m);print();

  return 0;
}
```

[1325.cpp](/assets/src/ybt/divide_conquer/1325.cpp)

----

[Problem 1326](http://ybt.ssoier.cn:8088/problem_show.php?pid=1326)

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
#define oo (1LL<<31)
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

LL b,p,k;
LL fac(LL p1){
  if(p1==0)return 1;
  else if(p1==1)return b%k;
  LL t=fac(p1>>1)%k,t1=fac(p1%2)%k;
  t=(t*t)%k;
  return (t*t1)%k;
}

int main( void ) {

#ifdef DEBUG
  freopen("1326.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin>>b>>p>>k;
  // 2^10 mod 9=7
  cout<<b<<"^"<<p<<" mod "<<k<<"="
      <<fac(p)<<endl;

  return 0;
}
```

[1326.cpp](/assets/src/ybt/divide_conquer/1326.cpp)

----

[Problem 1327](http://ybt.ssoier.cn:8088/problem_show.php?pid=1327)

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
#define oo (1LL<<31)
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

const int N=1100;
char a[N];
int n,cnt;
const char *s[]={"ooo*o**--*o",
                 "o--*o**oo*o",
                 "o*o*o*--o*o",
                 "--o*o*o*o*o"};

void solve(int x){
  if(x==1)return;
  if(!cnt){
    for(int i=0;i<n*2+2;++i)a[i]='-';
  }
  for(int i=0;i<x;++i){a[i]='o';a[i+x]='*';}
  a[x*2]=a[x*2+1]='-';
  cout<<"step"<<setw(2)<<cnt++<<":"<<a<<endl;
  a[x-1]=a[x]='-';a[x*2]='o';a[x*2+1]='*';
  cout<<"step"<<setw(2)<<cnt++<<":"<<a<<endl;
  if(x==4){
    for(int i=0;i<4;++i){
      for(int j=0;j<int(strlen(s[i]));++j)a[j]=s[i][j];
      cout<<"step"<<setw(2)<<cnt++<<":"<<a<<endl;
    }
    return;
  }
  solve(x-1);
}

int main( void ) {

#ifdef DEBUG
  freopen("1327.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin>>n;solve(n);

  return 0;
}
```

[1327.cpp](/assets/src/ybt/divide_conquer/1327.cpp)

----

[Problem 1328](http://ybt.ssoier.cn:8088/problem_show.php?pid=1328)

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
#define oo (1LL<<31)
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


const int N=11000;
int a[N],b[N],c[N],n;
LL ans;

void merge(int l, int r){
  if(l>r)return;
  if(l==r){b[l]=a[l];return;}
  int mid=(l+r)>>1;
  merge(l,mid);
  merge(mid+1,r);
  int i=l,j=mid+1,k=l;
  while(k<=r){
    if(j>r){
      while(i<=mid)c[k++]=b[i++];
      break;
    }else if(i>mid){
      while(j<=r)c[k++]=b[j++];
      break;
    }else{
      while(i<=mid&&j<=r){
        if(b[i]<=b[j])c[k++]=b[i++];
        else{
          c[k++]=b[j++];
          ans+=(mid-i+1);
        }
      }
    }
  }
  for(int i=l;i<=r;++i)b[i]=c[i];
}

int main( void ) {

#ifdef DEBUG
  freopen("1328.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin>>n;for(int i=1;i<=n;++i)cin>>a[i];
  ans=0;
  merge(1,n);
  cout<<ans;NL;

  return 0;
}

```

[1328.cpp](/assets/src/ybt/divide_conquer/1328.cpp)

----
