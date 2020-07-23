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


int a[10][10],cnt,p;

void print(){
  ++cnt;
  cout<<"No. "<<cnt;NL;
  for(int i=1;i<=8;i++){
    for(int j=1;j<8;j++){
      cout<<a[i][j]<<" ";
    }
    cout<<a[i][8]<<endl;
  }
}
void bar(int x){
  if(x==9&&p==8){
    print();return;
  }
  for(int j=1;j<=8;++j){
    bool flag=false;
    for(int i=x-1;i>=1;--i){
      if(a[i][j]||a[i][x-i+j]||a[i][j-x+i]){flag=true;break;}
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
  freopen("1213.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  bar(1);

  return 0;
}
```

[1213.cpp](/assets/src/ybt/search/1213.cpp)

----

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


int R,S,res,cnt;
char a[100][100];
int dir[4][2]={{0,1},{0,-1},{-1,0},{1,0}}, cc[200];

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

[1212.cpp](/assets/src/ybt/search/1212.cpp)

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

[1317.cpp](/assets/src/ybt/search/1317.cpp)

----

