[Problem 1168](http://ybt.ssoier.cn:8088/problem_show.php?pid=1168)

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
  // freopen("1168.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  memset(a,0,sizeof(a));
  memset(b,0,sizeof(b));
  memset(c,0,sizeof(c));
  string a1,b1;
  cin>>a1>>b1;
  int lena=a1.size(),lenb=b1.size(),lenc=max(lena,lenb);
  for(int i=lena;i>=1;i--){
    a[i]=a1[lena-i]-'0';
  }
  for(int i=lenb;i>=1;i--){
    b[i]=b1[lenb-i]-'0';
  }
  for(int i=1;i<=lenc;i++){
    c[i]+=a[i]+b[i];
    if(c[i]>=10){
      c[i+1]+=c[i]/10;
      c[i]%=10;
    }
  }
  while(c[lenc+1]>0)lenc++;
  while(lenc>0&&!c[lenc])lenc--;
  if(!lenc)cout<<0<<endl;
  else{
    for(int i=lenc;i>=1;i--){
      cout<<c[i];
    }
    cout<<endl;
  }

  return 0;
}
```

[1168.cpp](/assets/src/ybt/high_precision/1168.cpp)

----

[Problem 1169](http://ybt.ssoier.cn:8088/problem_show.php?pid=1169)

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
  freopen("1169.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  memset(a,0,sizeof(a));
  memset(b,0,sizeof(b));
  memset(c,0,sizeof(c));

  string a1,b1;
  cin>>a1>>b1;
  int lena=a1.size(),lenb=b1.size(),lenc=max(lena,lenb);
  for(int i=lena;i>=1;i--){
    a[i]=a1[lena-i]-'0';
  }
  for(int i=lenb;i>=1;i--){
    b[i]=b1[lenb-i]-'0';
  }
  for(int i=1;i<=lenc;i++){
    c[i]+=a[i]-b[i];
    if(c[i]<0){
      c[i+1]--;
      c[i]+=10;
    }
  }
  while(lenc>0&&!c[lenc])lenc--;
  if(!lenc)cout<<0<<endl;
  else{
    for(int i=lenc;i>=1;i--){
      cout<<c[i];
    }
    cout<<endl;
  }

  return 0;
}
```

[1169.cpp](/assets/src/ybt/high_precision/1169.cpp)

----

[Problem 1170](http://ybt.ssoier.cn:8088/problem_show.php?pid=1170)

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


int a[40000], lena;

void fac(int n){
  if(n==1){
    a[n]=1;
    lena++;
    return;
  }
  int t=0;
  for(int i=1;i<=lena;i++){
    a[i]*=n;
    a[i]+=t;
    t = a[i]/10;
    a[i]%=10;
  }
  if(t) a[lena+1]=t;
  while(a[lena+1]){
    a[lena+2]+=a[lena+1]/10;
    a[lena+1]%=10;
    lena++;
  }
}

int main( void ) {

#ifdef DEBUG
  freopen("1170.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin>>n;
  memset(a,0,sizeof(a));
  a[1]=1;
  lena=1;
  for(int i=1;i<=n;i++)
    fac(2);
  if(!lena)cout<<0<<endl;
  else{
    for(int i=lena;i>=1;--i)cout<<a[i];
    cout<<endl;
  }

  return 0;
}
```

[1170.cpp](/assets/src/ybt/high_precision/1170.cpp)

----

[Problem 1171](http://ybt.ssoier.cn:8088/problem_show.php?pid=1171)

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


int a[50], c[50];

int main( void ) {

#ifdef DEBUG
  freopen("1171.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  string a1;
  cin>>a1;
  memset(a,0,sizeof(a));
  memset(c,0,sizeof(c));
  int lena=a1.size(),x=0;
  for(int i=lena;i>=1;i--)a[i]=a1[i-1]-'0';
  bool flag=false;
  for(int k=2;k<=9;k++)
    {
      x=0;
      for(int i=1;i<=lena;i++)
        {
          c[i]=(a[i]+10*x)/k;
          x=(a[i]+10*x)%k;
        }
      if(!x)
        {
          if(flag) cout<<" ";
          flag=true;
          cout<<k;
        }
    }

  if(!flag)cout<<"none\n";
  else
    cout<<endl;

  return 0;
}
```

[1171.cpp](/assets/src/ybt/high_precision/1171.cpp)

----

[Problem 1172](http://ybt.ssoier.cn:8088/problem_show.php?pid=1172)

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


int a[40000], lena;

void fac(int n){
  if(n==1){
    a[n]=1;
    lena++;
    return;
  }
  int t=0;
  for(int i=1;i<=lena;i++){
    a[i]*=n;
    a[i]+=t;
    t = a[i]/10;
    a[i]%=10;
  }
  if(t) a[lena+1]=t;
  while(a[lena+1]){
    a[lena+2]+=a[lena+1]/10;
    a[lena+1]%=10;
    lena++;
  }
}

int main( void ) {

#ifdef DEBUG
  freopen("1172.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin>>n;
  memset(a,0,sizeof(a));
  for(int i=1;i<=n;i++)
    fac(i);
  if(!lena)cout<<0<<endl;
  else{
    for(int i=lena;i>=1;--i)cout<<a[i];
    cout<<endl;
  }

  return 0;
}
```

[1172.cpp](/assets/src/ybt/high_precision/1172.cpp)

----

[Problem 1173](http://ybt.ssoier.cn:8088/problem_show.php?pid=1173)

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


int a[1000], c[1000], lena,lenb,lenc;

void fac(int n){
  if(n==1){
    a[n]=1;
    lena++;
    return;
  }
  for(int i=1;i<=lena;i++){
    a[i]*=n;
  }
  for(int i=1;i<=lena;i++){
    a[i+1]+=a[i]/10;
    a[i]%=10;
  }
  while(a[lena+1]){
    a[lena+2]+=a[lena+1]/10;
    a[lena+1]%=10;
    lena++;
  }
}

void add(){
  lenc=max(lenc,lena);
  for(int i=1;i<=lenc;i++){
    c[i]+=a[i];
    if(c[i]>=10){
      c[i+1]+=c[i]/10;
      c[i]%=10;
    }
  }
  while(c[lenc+1])lenc++;
}

int main( void ) {

#ifdef DEBUG
  freopen("1173.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin>>n;
  memset(a,0,sizeof(a));
  memset(c,0,sizeof(c));
  for(int i=1;i<=n;i++){
    fac(i);
    // for(int i=lena;i>=1;--i)cout<<a[i]<<" ";
    // cout<<endl;
    add();
  }
  if(!lenc)cout<<0<<endl;
  else{
    for(int i=lenc;i>=1;--i)cout<<c[i];
    cout<<endl;
  }

  return 0;
}
```

[1173.cpp](/assets/src/ybt/high_precision/1173.cpp)

----

[Problem 1174](http://ybt.ssoier.cn:8088/problem_show.php?pid=1174)

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
```

[1174.cpp](/assets/src/ybt/high_precision/1174.cpp)

----

[Problem 1175](http://ybt.ssoier.cn:8088/problem_show.php?pid=1175)

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


int a[300], c[300];

int main( void ) {

#ifdef DEBUG
  freopen("1175.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  string a1;
  cin>>a1;
  memset(a,0,sizeof(a));
  memset(c,0,sizeof(c));
  int lena=a1.size(),x=0,k=13,lenc=lena;
  for(int i=lena;i>=1;i--)a[i]=a1[lena-i]-'0';
  for(int i=lena;i>=1;i--)
    {
      c[i]=(a[i]+10*x)/k;
      x=(a[i]+10*x)%k;
    }
  while(!c[lenc])lenc--;
  if(!lenc)cout<<0;
  else
    for(int i=lenc;i>=1;i--)cout<<c[i];
  cout<<endl<<x<<endl;

  return 0;
}
```

[1175.cpp](/assets/src/ybt/high_precision/1175.cpp)

----

[Problem 1307](http://ybt.ssoier.cn:8088/problem_show.php?pid=1307)

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
  freopen("1307.in", "r", stdin);
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
  for(int i=lenc;i>=1;--i){
    cout<<c[i];
  }
  cout<<endl;

  return 0;
}
```

[1307.cpp](/assets/src/ybt/high_precision/1307.cpp)

----

[Problem 1308](http://ybt.ssoier.cn:8088/problem_show.php?pid=1308)

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


int a[500],b[500],c[500],d[500],lena,lenb,lenc,lend;

void copy1(int k)
{
  memset(d,0,sizeof(d));
  lend=lenb+k-1;
  // d=b*(10^(k-1))
  for(int i=1;i<=lenb;i++)
    {
      d[i+k-1]=b[i];
    }
}

void minus1()
{
  // a-d
  for(int i=1;i<=lena;i++)
    {
      if(a[i]>=d[i])
        {
          a[i]-=d[i];
        }
      else
        {
          a[i+1]--;
          a[i]=a[i]+10-d[i];
        }
    }
  while(lena&&!a[lena])--lena;
}

int cmp()
{
  // compare a,d
  if(lena<lend)return -1;
  else if(lena>lend)return 1;
  for(int i=lena;i>=1;i--)
    {
      if(a[i]>d[i])return 1;
      else if(a[i]<d[i])return -1;
    }
  return 0;
}

int main( void ) {

#ifdef DEBUG
  freopen("1308.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  string a1,b1;
  cin>>a1>>b1;
  memset(a,0,sizeof(a));
  memset(b,0,sizeof(b));
  memset(c,0,sizeof(c));
  memset(d,0,sizeof(d));
  lena=a1.size();
  lenb=b1.size();
  for(int i=lena;i>=1;--i)a[i]=a1[lena-i]-'0';
  for(int i=lenb;i>=1;--i)b[i]=b1[lenb-i]-'0';
  lenc=lena-lenb+1;
  if(cmp()==0)
    {
      cout<<1<<endl<<0<<endl;
    }
  else if(cmp()<0)
    {
      cout<<0<<endl<<a1<<endl;
    }
  else
    {
      for(int i=lenc;i>=1;i--)
        {
          copy1(i);
          while(cmp()>=0)
            {
              c[i]++;
              minus1();
            }
        }

      while(lenc&&!c[lenc])--lenc;
      if(lenc)
        {
          for(int i=lenc;i>=1;--i)cout<<c[i];
        }
      else cout<<0;

      NL;

      while(lena&&!a[lena])--lena;
      if(lena)
        for(int i=lena;i>=1;--i)cout<<a[i];
      else cout<<0;

      NL;
    }

  return 0;
}
```

[1308.cpp](/assets/src/ybt/high_precision/1308.cpp)

----

[Problem 1309](http://ybt.ssoier.cn:8088/problem_show.php?pid=1309)

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
```

[1309.cpp](/assets/src/ybt/high_precision/1309.cpp)

----

