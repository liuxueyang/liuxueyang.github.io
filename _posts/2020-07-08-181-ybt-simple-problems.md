---
layout: post
title:  一本通上的 181 道基础题目
date:   2020-07-08 11:55:20 +0800
tags:  ACM/ICPC
---

花了一周的时间，把前面的语言基础题目基本做完了。~~还不是为了刷排名~~

这是这篇博客的拼接脚本：

```pl
#!/usr/bin/env perl
use 5.018;
use strict;
use warnings;
use File::Spec;

my $dir_path="./ybt/";
opendir my $dir, $dir_path or die "Cannot open directory: $!";

my @files = grep {/\d{4}\.cpp/ && -f "$dir_path/$_"} readdir($dir);
closedir($dir);

@files = sort @files;

my $dest_file="ybt.md";
open(DFH, '>', $dest_file) or die $!;

for my $file (@files){
    my $file1=File::Spec->catfile($dir_path, $file);
    open(FH, '<', $file1) or die $!;
    print DFH "\n```cpp\n";
    while(<FH>) {
        print DFH $_;
    }
    print DFH "```\n\n[$file](/assets/src/ybt/$file)\n\n"
}
```

[ybt.pl](/assets/src/ybt.pl)

做的过程中，尽量减少 WA，不过还是因为各种原因 WA 了 39 次。

![ybt](/assets/2020-07-08-14.42.26-ybt.png)

```cpp
#include <iostream>

using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  cout << a + b << endl;

  return 0;
}
```

[1000.cpp](/assets/src/ybt/1000.cpp)


```cpp
#include <iostream>

using namespace std;

int main() {
  cout << "Hello,World!" << endl;

  return 0;
}
```

[1001.cpp](/assets/src/ybt/1001.cpp)


```cpp
#include <iostream>

using namespace std;

int main() {
  int a, b, c; cin >> a >> b >> c; cout << b << endl;

  return 0;
}
```

[1002.cpp](/assets/src/ybt/1002.cpp)


```cpp
#include <iostream>
#include <cstdio>
#include <iomanip>

using namespace std;

int main() {
  int a, b, c; cin >> a >> b >> c;
  cout << setiosflags(ios::right);
  cout << setw(8) << a << " "
       << setw(8) << b << " "
       << setw(8) << c << endl;

  return 0;
}
```

[1003.cpp](/assets/src/ybt/1003.cpp)


```cpp
#include <iostream>

using namespace std;

int main() {
  char ch; cin >> ch; cout << "  " << ch << endl;
  cout << " ";
  for (int i = 0; i < 3; i++) cout << ch; cout << endl;
  for (int i = 0; i < 5; i++) cout << ch; cout << endl;

  return 0;
}
```

[1004.cpp](/assets/src/ybt/1004.cpp)


```cpp
#include <iostream>

using namespace std;
int main(void) {
  int a, b; cin >> a >> b; cout << a + b << endl;
  return 0;
}
```

[1006.cpp](/assets/src/ybt/1006.cpp)


```cpp
#include <iostream>
using namespace std;
int main() {
  int a, b, c; cin >> a >> b >> c; cout << (a + b) * c << endl;
  return 0;
}
```

[1007.cpp](/assets/src/ybt/1007.cpp)


```cpp
#include <iostream>
using namespace std;
int main() {
  int a, b, c; cin >> a >> b >> c; cout << (a + b) / c << endl;
  return 0;
}
```

[1008.cpp](/assets/src/ybt/1008.cpp)


```cpp
#include <iostream>
using namespace std;
int main(void){
  int a, b; cin >> a >> b; cout << a / b << " " << a % b << endl;
  return 0;
}
```

[1009.cpp](/assets/src/ybt/1009.cpp)


```cpp
#include <iostream>
using namespace std;
int main() {
  int a, b; cin >> a >> b; cout.precision(9);
  cout.setf(ios::fixed, ios::floatfield);
  cout << a * 1. / b << endl;
  return 0;
}
```

[1010.cpp](/assets/src/ybt/1010.cpp)


```cpp
#include <iostream>
using namespace std;
int main() {
  int a, b; cin >> a >> b; cout.precision(3);
  cout.setf(ios::fixed, ios::floatfield);
  cout << b * 1. / a * 100. << "%" << endl;
  return 0;
}
```

[1011.cpp](/assets/src/ybt/1011.cpp)


```cpp
#include <iostream>
using namespace std;
int main() {
  double x, a, b, c, d; cout.precision(7);
  cout.setf(ios::fixed, ios::floatfield);
  cin >> x >> a >> b >> c >> d;
  cout << a*x*x*x + b*x*x + c*x + d << endl;
  return 0;
}
```

[1012.cpp](/assets/src/ybt/1012.cpp)


```cpp
#include <iostream>
using namespace std;
int main() {
  double f; cin >> f; cout.precision(5);
  cout.setf(ios::fixed, ios::floatfield);
  cout << 5. * (f-32) / 9. << endl;
  return 0;
}
```

[1013.cpp](/assets/src/ybt/1013.cpp)


```cpp
#include <iostream>
using namespace std;
int main() {
  double pi = 3.14159, r; cin >> r; cout.precision(4);
  cout.setf(ios::fixed, ios::floatfield);
  cout << 2*r << " "
       << 2*pi*r << " "
       << pi*r*r << endl;
  return 0;
}
```

[1014.cpp](/assets/src/ybt/1014.cpp)


```cpp
#include <iostream>
using namespace std;
int main() {
  double r1, r2; cin >> r1 >> r2; cout.precision(2); cout.setf(ios::fixed, ios::floatfield);
  cout << 1./(1./r1 + 1./r2) << endl;
  return 0;
}
```

[1015.cpp](/assets/src/ybt/1015.cpp)


```cpp
#include <iostream>
using namespace std;
int main() {
  int a; short b; cout << sizeof a << " " << sizeof b << endl;
  return 0;
}
```

[1016.cpp](/assets/src/ybt/1016.cpp)


```cpp
#include <iostream>
using namespace std;
int main() {
  float a; double b; cout << sizeof a << " " << sizeof b << endl;
  return 0;
}
```

[1017.cpp](/assets/src/ybt/1017.cpp)


```cpp
#include <iostream>
using namespace std;
int main() {
  bool a; char b; cout << sizeof a << " " << sizeof b << endl;
  return 0;
}
```

[1018.cpp](/assets/src/ybt/1018.cpp)


```cpp
#include <iostream>
using namespace std;
int main() {
  float a; cin >> a;
  int b = int(a);
  cout << b << endl;
  return 0;
}
```

[1019.cpp](/assets/src/ybt/1019.cpp)


```cpp
#include <iostream>
using namespace std;
int main() {
  char c; cin >> c; cout << int(c) << endl;
  return 0;
}
```

[1020.cpp](/assets/src/ybt/1020.cpp)


```cpp
#include <iostream>
using namespace std;
int main() {
  int a; cin >> a; cout << char(a) << endl;
  return 0;
}
```

[1021.cpp](/assets/src/ybt/1021.cpp)


```cpp
#include <iostream>
using namespace std;
int main() {
  int a; cin >> a; bool b; b = a; a = b; cout << a << endl;
  return 0;
}
```

[1022.cpp](/assets/src/ybt/1022.cpp)


```cpp
#include <iostream>
using namespace std;
int main() {
  cout << sizeof "Hello, World!" << endl;
  return 0;
}
```

[1023.cpp](/assets/src/ybt/1023.cpp)


```cpp
#include <iostream>
using namespace std;
int main() {
  float a; cin >> a; cout.precision(3);
  cout.setf(ios::fixed, ios::floatfield); cout << a << endl;
  return 0;
}
```

[1024.cpp](/assets/src/ybt/1024.cpp)


```cpp
#include <iostream>
using namespace std;
int main() {
  double a; cin >> a; cout.precision(12);
  cout.setf(ios::fixed, ios::floatfield);
  cout << a << endl;
  return 0;
}
```

[1025.cpp](/assets/src/ybt/1025.cpp)


```cpp
#include <iostream>
using namespace std;
int main() {
  char a; int b; float c; double d;
  cin >> a >> b >> c >> d;
  cout.precision(6); cout.setf(ios::fixed, ios::floatfield);
  cout << a << " " << b << " " << c << " " << d << endl;
  return 0;
}
```

[1026.cpp](/assets/src/ybt/1026.cpp)


```cpp
#include <iostream>
#include <cstdio>
using namespace std;
int main() {
  double a; scanf("%lf", &a);
  printf("%f\n%.5f\n%e\n%g\n", a, a, a, a);
  return 0;
}
```

[1027.cpp](/assets/src/ybt/1027.cpp)


```cpp
#include <iostream>
using namespace std;
void P(int a, char c) {
  for (int i = 0; i < a; i++) cout << c; cout << endl;
}
void print(int a, char c) {
  if (a == 1) {
    cout << "  " << c << endl;
  } else if (a == 3) {
    cout << " ";
    P(a, c);
  } else if (a == 5) {
    P(a, c);
  }
}
int main() {
  char c; cin >> c;
  print(1, c);
  print(3, c);
  print(5, c);
  print(3, c);
  print(1, c);
  return 0;
}
```

[1028.cpp](/assets/src/ybt/1028.cpp)


```cpp
#include <iostream>
using namespace std;
int main() {
  double a, b; cin >> a >> b;
  int d = int(a / b);
  double c = a - d * b;
  cout << c << endl;
  return 0;
}
```

[1029.cpp](/assets/src/ybt/1029.cpp)


```cpp
#include <iostream>
using namespace std;
int main() {
  double r; cin >> r;
  double pi = 3.14;
  cout.precision(2); cout.setf(ios::fixed, ios::floatfield);
  cout << 4./3. * pi * r*r*r << endl;
  return 0;
}
```

[1030.cpp](/assets/src/ybt/1030.cpp)


```cpp
#include <iostream>
using namespace std;
void P(int a) {
  if (a == 0) {
    cout << endl; return;
  }
  cout << a % 10;
  P(a / 10);
}
int main() {
  int a; cin >> a; P(a);
  return 0;
}
```

[1031.cpp](/assets/src/ybt/1031.cpp)


```cpp
#include <iostream>
#include <cmath>
using namespace std;
int main() {
  double h, r, v; cin >> h >> r; v = 3.1415926 * r*r * h;
  int re = ceil(20 * 1000 / v);
  cout << re << endl;
  return 0;
}
```

[1032.cpp](/assets/src/ybt/1032.cpp)


```cpp
#include <iostream>
#include <cmath>
using namespace std;
int main() {
  double x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
  cout.precision(3); cout.setf(ios::fixed, ios::floatfield);
  double res = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
  cout << res << endl;
  return 0;
}
```

[1033.cpp](/assets/src/ybt/1033.cpp)


```cpp
#include <iostream>
using namespace std;
int main() {
  int a1, a2, n; cin >> a1 >> a2 >> n;
  int d = a2 - a1;
  cout << a1 + (n-1) * d << endl;
  return 0;
}
```

[1035.cpp](/assets/src/ybt/1035.cpp)


```cpp
#include <iostream>
using namespace std;
int main() {
  long long a, b; cin >> a >> b; cout << a * b << endl;
  return 0;
}
```

[1036.cpp](/assets/src/ybt/1036.cpp)


```cpp
#include <iostream>
using namespace std;
int main() {
  int n; cin >> n;
  cout << (1 << n) << endl;
  return 0;
}
```

[1037.cpp](/assets/src/ybt/1037.cpp)


```cpp
#include <iostream>
#include <cmath>
using namespace std;
int main() {
  int n, x, y; cin >> n >> x >> y;
  int re = n - ceil(y * 1.0 / x);
  cout << (re >= 0 ? re : 0) << endl;
  return 0;
}
```

[1038.cpp](/assets/src/ybt/1038.cpp)


```cpp
#include <iostream>
using namespace std;
int main() {
  int n; cin >> n;
  if (n > 0) cout << "positive";
  else if (n == 0) cout << "zero";
  else cout << "negative";
  cout << endl;
  return 0;
}
```

[1039.cpp](/assets/src/ybt/1039.cpp)


```cpp
#include <iostream>
#include <cmath>
using namespace std;
int main() {
  double a; cin >> a;
  cout.precision(2); cout.setf(ios::fixed, ios::floatfield);
  cout << fabs(a) << endl;
  return 0;
}
```

[1040.cpp](/assets/src/ybt/1040.cpp)


```cpp
#include <iostream>
using namespace std;
int main() {
  int n; cin >> n;
  cout << ((n & 1) ? "odd" : "even") << endl;
  return 0;
}
```

[1041.cpp](/assets/src/ybt/1041.cpp)


```cpp
#include <iostream>
using namespace std;
int main() {
  char a; cin >> a;
  cout << ((int(a) & 1) ? "YES" : "NO") << endl;
  return 0;
}
```

[1042.cpp](/assets/src/ybt/1042.cpp)


```cpp
#include <iostream>
using namespace std;
int main() {
  long long a;
  long long b;
  cin >> a >> b;
  if (a > b) cout << ">";
  else if (a == b) cout << "=";
  else cout << "<";
  cout << endl;
  return 0;
}
```

[1043.cpp](/assets/src/ybt/1043.cpp)


```cpp
#include <iostream>
using namespace std;
int main(void) {
  int a; cin >> a;
  cout << (a >= 10 && a <=99) << endl;
  return 0;
}
```

[1044.cpp](/assets/src/ybt/1044.cpp)


```cpp
#include <iostream>
using namespace std;
int main() {
  int a, b; cin >> a >> b;
  cout << (a >= 10 || b >= 20) << endl;
  return 0;
}
```

[1045.cpp](/assets/src/ybt/1045.cpp)


```cpp
#include <iostream>
using namespace std;
int main() {
  int n; cin >> n;
  cout << (((n % 15) == 0) ? "YES" : "NO") << endl;
  return 0;
}
```

[1046.cpp](/assets/src/ybt/1046.cpp)


```cpp
#include <iostream>
using namespace std;
int main() {
  int n; cin >> n;
  if (n % (15*7) == 0) {
    cout << "3 5 7\n";
  } else if (n % 15 == 0) {
    cout << "3 5\n";
  } else if (n % 21 == 0) {
    cout << "3 7\n";
  } else if (n % 35 == 0) {
    cout << "5 7\n";
  } else if (n % 3 == 0) {
    cout << "3\n";
  } else if (n % 5 == 0) {
    cout << "5\n";
  } else if (n % 7 == 0) {
    cout << "7\n";
  } else {
    cout << "n\n";
  }
  return 0;
}
```

[1047.cpp](/assets/src/ybt/1047.cpp)


```cpp
#include <iostream>
using namespace std;
int main() {
  int a, b; cin >> a >> b;
  cout << ((a < 60 && b >= 60) || (b < 60 && a >= 60)) << endl;
  return 0;
}
```

[1048.cpp](/assets/src/ybt/1048.cpp)


```cpp
#include <iostream>
using namespace std;
int main() {
  int n; cin >> n;
  switch (n) {
  case 1:
  case 3:
  case 5:
    cout << "NO\n"; break;
  default:
    cout << "YES\n"; break;
  }
  return 0;
}
```

[1049.cpp](/assets/src/ybt/1049.cpp)


```cpp
#include <iostream>
#include <cmath>
using namespace std;
int main() {
  double x; cin >> x;
  double b = x / 3 + 50;
  double w = x / 1.2;
  double eps = 1e-9;
  if (fabs(b-w) < eps) {
    cout << "All\n";
  } else if (b < w) cout << "Bike\n";
  else cout << "Walk\n";
  return 0;
}
```

[1050.cpp](/assets/src/ybt/1050.cpp)


```cpp
#include <iostream>
using namespace std;
int main() {
  double n; cin >> n;
  double y; cout.precision(3);
  cout.setf(ios::fixed, ios::floatfield);
  if (n >= 0 && n < 5) y = -n + 2.5;
  else if (n >= 5 && n < 10) y = 2-1.5*(n-3)*(n-3);
  else y = n/2. - 1.5;
  cout << y << endl;
  return 0;
}
```

[1051.cpp](/assets/src/ybt/1051.cpp)


```cpp
#include <iostream>
#include <cmath>
using namespace std;
int main() {
  double x, y; char c; cin >> x >> c;
  if (x <= 1000) y = 8;
  else {
    y = 8 + ceil((x - 1000) / 500) * 4;
  }
  if (c == 'y') y += 5;
  cout << int(y) << endl;

  return 0;
}
```

[1052.cpp](/assets/src/ybt/1052.cpp)


```cpp
#include <iostream>
using namespace std;
int main() {
  int a, b[3]; cin >> b[0]; a = b[0];
  for (int i = 1; i < 3; i++) {
    cin >> b[i];
    if (b[i] > a) a = b[i];
  }
  cout << a << endl;
  return 0;
}
```

[1053.cpp](/assets/src/ybt/1053.cpp)


```cpp
#include <iostream>
using namespace std;
int main() {
  int a, b, c; cin >> a >> b >> c;
  if (a + b < c || a + c < b || b + c < a) cout << "no\n";
  else cout << "yes\n";

  return 0;
}
```

[1054.cpp](/assets/src/ybt/1054.cpp)


```cpp
#include <iostream>
using namespace std;
int main() {
  int a; cin >> a;
  if ((a % 100 != 0 && a % 4 == 0) || (a % 400 == 0)) cout << "Y\n";
  else cout << "N\n";
  return 0;
}
```

[1055.cpp](/assets/src/ybt/1055.cpp)


```cpp
#include <iostream>
using namespace std;
int main() {
  int x, y; cin >> x >> y;
  if (x >= -1 && x <= 1 && y >= -1 && y <= 1) cout << "yes\n";
  else cout << "no\n";
  return 0;
}
```

[1056.cpp](/assets/src/ybt/1056.cpp)


```cpp
#include <iostream>
using namespace std;
int main() {
  int a, b, c; char p; cin >> a >> b >> p;
  switch (p) {
  case '+':
    c = a + b; break;
  case '-': c = a - b; break;
  case '*': c = a * b; break;
  case '/':
    if (b == 0) {
      cout << "Divided by zero!\n"; return 0;
    }
    c = a / b; break;
  default:
    cout << "Invalid operator!\n"; return 0;
  }
  cout << c << endl;
  return 0;
}
```

[1057.cpp](/assets/src/ybt/1057.cpp)


```cpp
#include <iostream>
#include <cmath>
using namespace std;
int main() {
  double a, b, c; cin >> a >> b >> c; cout.precision(5);
  cout.setf(ios::fixed, ios::floatfield);
  double delta = b*b - 4*a*c, eps = 1e-9, res, res1, res2;
  if (delta < 0) {
    cout << "No answer!\n";
  } else if (fabs(delta) < eps) {
    res = -b / (2*a);
    cout << "x1=x2=" << res << endl;
  } else {
    double t = sqrt(delta);
    res1 = (-b + t) / (2*a);
    res2 = (-b - t) / (2*a);
    if (res1 > res2) {
      double k = res1;
      res1 = res2;
      res2 = k;
    }
    cout << "x1=" << res1 << ";x2=" << res2 << endl;
  }
  return 0;
}
```

[1058.cpp](/assets/src/ybt/1058.cpp)


```cpp
#include <iostream>
using namespace std;
int main() {
  int n, t; cin >> n; double sum = 0; cout.precision(2);
  cout.setf(ios::fixed, ios::floatfield);
  for (int i = 0; i < n; i++) { cin >> t; sum += t; }
  cout << sum / n << endl;
  return 0;
}
```

[1059.cpp](/assets/src/ybt/1059.cpp)


```cpp
#include <iostream>
using namespace std;
int main() {
  int n; double t; cin >> n; double sum = 0; cout.precision(4);
  cout.setf(ios::fixed, ios::floatfield);
  for (int i = 0; i < n; i++) { cin >> t; sum += t; }
  if (n == 0) cout << 0 << endl;
  else cout << sum / n << endl;
  return 0;
}
```

[1060.cpp](/assets/src/ybt/1060.cpp)


```cpp
#include <iostream>
using namespace std;
int main() {
  int n; double t; cin >> n; double sum = 0; cout.precision(5);
  cout.setf(ios::fixed, ios::floatfield);
  for (int i = 0; i < n; i++) { cin >> t; sum += t; }
  if (n == 0) cout << 0 << " " << 0 << endl;
  else cout << int(sum) << " " << sum / n << endl;
  return 0;
}
```

[1061.cpp](/assets/src/ybt/1061.cpp)


```cpp
#include <iostream>
using namespace std;
int main() {
  int n, t, res = -1; cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> t; if (t > res) res = t;
  }
  cout << res << endl;
  return 0;
}
```

[1062.cpp](/assets/src/ybt/1062.cpp)


```cpp
#include <iostream>
using namespace std;
int main() {
  int n, t, mi = 2000, ma = -1; cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> t;
    if (t > ma) ma = t;
    if (t < mi) mi = t;
  }
  cout << ma - mi << endl;
  return 0;
}
```

[1063.cpp](/assets/src/ybt/1063.cpp)


```cpp
#include <iostream>
using namespace std;
int main() {
  int n, r1 = 0, r2 = 0, r3 = 0, t1, t2, t3, s = 0; cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> t1 >> t2 >> t3;
    r1 += t1; r2 += t2; r3 += t3;
    s += (t1 + t2 + t3);
  }
  cout << r1 << " " << r2 << " " << r3 << " " << s << endl;
  return 0;
}
```

[1064.cpp](/assets/src/ybt/1064.cpp)


```cpp
#include <iostream>
using namespace std;
int main() {
  int m, n, r = 0; cin >> m >> n;
  for (int i = m; i <= n; i++) {
    if (i & 1) r += i;
  }
  cout << r << endl;
  return 0;
}
```

[1065.cpp](/assets/src/ybt/1065.cpp)


```cpp
#include <iostream>
using namespace std;
int main() {
  int n, m, r = 0; cin >> m >> n;
  for (int i = m; i <= n; i++) {
    if (i % 17 == 0) r += i;
  }
  cout << r << endl;
  return 0;
}
```

[1066.cpp](/assets/src/ybt/1066.cpp)


```cpp
#include <iostream>
using namespace std;
int main() {
  int k, r1 = 0, r2 = 0, r3 = 0, t; cin >> k;
  for (int i = 0; i < k; i++) {
    cin >> t;
    switch (t) {
    case 1: r1++; break;
    case 5: r2++; break;
    case 10: r3++; break;
    }
  }
  cout << r1 << endl << r2 << endl << r3 << endl;
  return 0;
}
```

[1067.cpp](/assets/src/ybt/1067.cpp)


```cpp
#include <iostream>
using namespace std;
int main() {
  int N, m, r = 0, t; cin >> N >> m;
  for (int i = 0; i < N; i++) {
    cin >> t; if (t == m) r++;
  }
  cout << r << endl;
  return 0;
}
```

[1068.cpp](/assets/src/ybt/1068.cpp)


```cpp
#include <iostream>
using namespace std;
int main() {
  int a, n, r = 1; cin >> a >> n;
  for (int i = 0; i < n; i++) {
    r *= a;
  }
  cout << r << endl;
  return 0;
}
```

[1069.cpp](/assets/src/ybt/1069.cpp)


```cpp
#include <iostream>
using namespace std;
int main() {
  double x, r = 1; int n; cin >> x >> n; cout.precision(4);
  r = x;
  cout.setf(ios::fixed, ios::floatfield);
  for (int i = 0; i < n; i++) {
    r *= (1 + 0.001);
  }
  cout << r << endl;
  return 0;
}
```

[1070.cpp](/assets/src/ybt/1070.cpp)


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


int main( void ) {

// #ifdef DEBUG
//   freopen(".in", "r", stdin);
// #endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int k;
  LL a = 1, b = 1, t; cin >> k;
  for (int i = 0; i < k-1; i++) {
    t = a + b;
    a = b;
    b = t;
  }
  cout << a << endl;

  return 0;
}
```

[1071.cpp](/assets/src/ybt/1071.cpp)


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


int main( void ) {

#ifdef DEBUG
  freopen("1072.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  double o, a, b, r;
  cin >> a >> b;
  o = b / a;
  for (int i = 0; i < n - 1; i++) {
    cin >> a >> b;
    r = b / a;
    if (r - o > 0.05) cout << "better\n";
    else if (o - r > 0.05) cout << "worse\n";
    else cout << "same\n";
  }

  return 0;
}
```

[1072.cpp](/assets/src/ybt/1072.cpp)


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


int main( void ) {

#ifdef DEBUG
  freopen("1073.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  double r = 0, a, b, p;
  for (int i = 0; i < n; i++) {
    cin >> a >> b >> p;
    double l = sqrt(a*a + b*b);
    r += (l / 50 * 2 + p + p*0.5);
  }
  cout << LL(ceil(r)) << endl;

  return 0;
}
```

[1073.cpp](/assets/src/ybt/1073.cpp)


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


int main( void ) {

#ifdef DEBUG
  freopen("1074.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int a[13], s = 0, c = 0; bool flag = true;
  int r = 0;
  for (int i = 1; i <= 12; i++) {
    cin >> a[i];
    if (!flag) continue;
    c += 300;
    c -= a[i];
    if (c < 0) {
      flag = false;
      r = -i;
    }
    int t = c / 100 * 100;
    c -= t;
    s += t;
  }
  if (flag) {
    // NOTE: precision lost using s * 1.2
    c += (s + s / 5);
    cout << c << endl;
  } else cout << r << endl;

  return 0;
}
```

[1074.cpp](/assets/src/ybt/1074.cpp)


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


int main( void ) {

#ifdef DEBUG
  freopen("1075.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int m, n, t, s = 0;
  cin >> m >> n;
  for (int i = 0; i < n; i++) {
    cin >> t;
    if (m >= t) {
      m -= t;
    } else {
      s++;
    }
  }
  cout << s << endl;

  return 0;
}
```

[1075.cpp](/assets/src/ybt/1075.cpp)


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


int main( void ) {

#ifdef DEBUG
  freopen("1076.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, a, b, s = 0, cur = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    if ((a >= 90 && a <= 140) && (b >= 60 && b <= 90)) {
      cur++;
      if (cur > s) s = cur;
    } else {
      cur = 0;
    }
  }
  cout << s << endl;

  return 0;
}
```

[1076.cpp](/assets/src/ybt/1076.cpp)


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


int main( void ) {

#ifdef DEBUG
  freopen("1077.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, a, s = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    int t = (a % 10) - a/1000 - (a/100 % 10) - (a/10 % 10);
    if (t > 0) s++;
  }
  cout << s << endl;

  return 0;
}
```

[1077.cpp](/assets/src/ybt/1077.cpp)


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


int main( void ) {

#ifdef DEBUG
  freopen("1078.in", "r", stdin);
#endif

  double s = 0, p1 = 1, q1 = 2;
  int n;
  cin >> n;
  cout.precision(4);
  cout.setf(ios::fixed, ios::floatfield);
  for (int i = 0; i < n; i++) {
    s += q1 / p1;
    double t = p1 + q1;
    p1 = q1;
    q1 = t;
  }
  cout << s << endl;

  return 0;
}
```

[1078.cpp](/assets/src/ybt/1078.cpp)


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


int main( void ) {

#ifdef DEBUG
  freopen("1079.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m = 1;
  double s = 0;
  cin >> n;
  cout.precision(4);
  cout.setf(ios::fixed, ios::floatfield);
  for (int i = 1; i <= n; i++) {
    s += double(1. / i) * m;
    m *= -1;
  }
  cout << s << endl;

  return 0;
}
```

[1079.cpp](/assets/src/ybt/1079.cpp)


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


int gcd(int a, int b) {
  if (a < b) swap(a, b);
  if (!b) return a;
  int t = a % b;
  if (!t) return b;
  return gcd(b, a % b);
}

int main( void ) {

#ifdef DEBUG
  // freopen("1080.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int a[3];
  for (int i = 0; i < 3; i++) cin >> a[i];
  sort(a, a + 3);
  int b = a[1] - a[0], c = a[2] - a[1];
  int g = gcd(b, c);
  if (!g) {
    cout << 2 << endl;
  } else {
    for (int i = 2; i <= g; ++i) {
      if (g % i == 0) {
        cout << i << endl;
        break;
      }
    }
  }

  return 0;
}
```

[1080.cpp](/assets/src/ybt/1080.cpp)


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


int main( void ) {

#ifdef DEBUG
  freopen("1081.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  cout << (n + 1) * n / 2 << endl;

  return 0;
}
```

[1081.cpp](/assets/src/ybt/1081.cpp)


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


int main( void ) {

#ifdef DEBUG
  freopen("1083.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int a, b, c;
  cin >> a >> b;
  c = a % 7;
  for (int i = 0; i < b - 1; i++) {
    c = (c * a) % 7;
  }
  a = c;
  switch (a) {
  case 1: cout << "Monday\n"; break;
  case 2: cout << "Tuesday\n"; break;
  case 3: cout << "Wednesday\n"; break;
  case 4: cout << "Thursday\n"; break;
  case 5: cout << "Friday\n"; break;
  case 6: cout << "Saturday\n"; break;
  case 0: cout << "Sunday\n"; break;
  }

  return 0;
}
```

[1083.cpp](/assets/src/ybt/1083.cpp)


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


int main( void ) {

#ifdef DEBUG
  freopen("1084.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int a, b, c;
  cin >> a >> b;
  c = a % 1000;
  for (int i = 0; i < b - 1; ++i) {
    c = (c * a) % 1000;
  }
  cout.setf(ios::fixed);
  cout << setfill('0') << setw(3);
  cout << c << endl;

  return 0;
}
```

[1084.cpp](/assets/src/ybt/1084.cpp)


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


int main( void ) {

#ifdef DEBUG
  freopen("1085.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  double h, s = 0;
  cin >> h;
  s = h;
  for (int i = 1; i < 10; ++i) {
    s += h;
    h /= 2;
  }
  h /= 2;
  cout << s << endl << h << endl;

  return 0;
}
```

[1085.cpp](/assets/src/ybt/1085.cpp)


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


int main( void ) {

#ifdef DEBUG
  freopen("1086.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  while (n != 1) {
    if (n & 1) {
      cout << n << "*3+1=";
      n = n*3 + 1;
      cout << n << endl;
    } else {
      cout << n << "/2=";
      n >>= 1;
      cout << n << endl;
    }
  }
  cout << "End\n";

  return 0;
}
```

[1086.cpp](/assets/src/ybt/1086.cpp)


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


int main( void ) {

#ifdef DEBUG
  freopen("1087.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int k, n = 1;
  double s = 1;
  cin >> k;
  while (s <= k) {
    s += double(1./++n);
  }
  cout << n << "\n";


  return 0;
}
```

[1087.cpp](/assets/src/ybt/1087.cpp)


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


int main( void ) {

#ifdef DEBUG
  freopen("1088.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  while (n) {
    cout << n % 10;
    n /= 10;
    cout << (n ? " " : "\n");
  }

  return 0;
}
```

[1088.cpp](/assets/src/ybt/1088.cpp)


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


int main( void ) {

#ifdef DEBUG
  freopen("1089.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m = 0, n1, k = 10;
  cin >> n;
  n1 = abs(n);
  while (n1) {
    m = m*k + n1 % 10;
    n1 /= 10;
  }
  if (n < 0) m *= -1;
  cout << m << "\n";

  return 0;
}
```

[1089.cpp](/assets/src/ybt/1089.cpp)


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


int main( void ) {

#ifdef DEBUG
  freopen("1090.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int m, k, c = 0;
  cin >> m >> k;
  if (m % 19 == 0) {
    while (m) {
      if (m % 10 == 3) {
        c++;
      }
      m /= 10;
    }

    cout << ((c == k) ? "YES" : "NO") << "\n";
  } else {
    cout << "NO" << "\n";
  }

  return 0;
}
```

[1090.cpp](/assets/src/ybt/1090.cpp)


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


LL fa(int n) {
  LL r = 1;
  for (int i = 1; i <= n; ++i) {
    r *= i;
  }
  return r;
}
int main( void ) {

#ifdef DEBUG
  freopen("1091.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  LL n, s = 0;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    s += fa(i);
  }
  cout << s << "\n";

  return 0;
}
```

[1091.cpp](/assets/src/ybt/1091.cpp)


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


double fa(int n)
{
  double s = 1;
  for (int i = 1; i <= n; ++i) {
    s *= i;
  }
  return s;
}

int main( void ) {

#ifdef DEBUG
  freopen("1092.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  double s = 1;
  cout.precision(10);
  cout.setf(ios::fixed, ios::floatfield);

  for (int i = 1; i <= n; ++i) {
    s += 1./fa(i);
  }

  cout << s << "\n";


  return 0;
}
```

[1092.cpp](/assets/src/ybt/1092.cpp)


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


int main( void ) {

#ifdef DEBUG
  freopen("1093.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  double x, s = 1, x1;
  int n;
  cin >> x >> n;
  x1 = x;

  for (int i = 1; i <= n; ++i) {
    s += x1;
    x1 *= x;
  }
  cout.precision(2);
  cout.setf(ios::fixed, ios::floatfield);
  cout << s << "\n";

  return 0;
}
```

[1093.cpp](/assets/src/ybt/1093.cpp)


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


bool ch(int n)
{
  if (n % 7 == 0) return true;
  while (n) {
    if (n % 10 == 7) return true;
    n /= 10;
  }
  return false;
}

int main( void ) {

#ifdef DEBUG
  freopen("1094.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, s = 0;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    if (!ch(i)) {
      s += i*i;
    }
  }
  cout << s << "\n";

  return 0;
}
```

[1094.cpp](/assets/src/ybt/1094.cpp)


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


int ch(int n)
{
  int r = 0;
  while (n) {
    if (n % 10 == 1) r++;
    n /= 10;
  }
  return r;
}

int main( void ) {

#ifdef DEBUG
  freopen("1095.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, s = 0;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    s += ch(i);
  }
  cout << s << "\n";

  return 0;
}
```

[1095.cpp](/assets/src/ybt/1095.cpp)


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


int ch(int n)
{
  int r = 0;
  while (n) {
    if (n % 10 == 2) r++;
    n /= 10;
  }
  return r;
}

int main( void ) {

#ifdef DEBUG
  freopen("1096.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int l, r, s = 0;
  cin >> l >> r;
  for (int i = l; i <= r; ++i) {
    s += ch(i);
  }
  cout << s << "\n";

  return 0;
}
```

[1096.cpp](/assets/src/ybt/1096.cpp)


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


int main( void ) {

#ifdef DEBUG
  freopen("1097.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m, f;
  char c;
  cin >> n >> m >> c >> f;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (j == 0 || j == m - 1 || i == 0 ||
          i == n - 1) cout << c;
      else
          cout << (f > 0 ? c : ' ');
    }
    cout << "\n";
  }

  return 0;
}
```

[1097.cpp](/assets/src/ybt/1097.cpp)


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


int main( void ) {

#ifdef DEBUG
  freopen("1098.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, c = 0;
  cin >> n;
  for (int i = 2; i <= ceil(sqrt(n)); ++i) {
    if (n % i == 0) {
      c = n / i;
      break;
    }
  }
  cout << c << "\n";

  return 0;
}
```

[1098.cpp](/assets/src/ybt/1098.cpp)


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


const int N = 10010*11;
int a[N], b[N];

int main( void ) {

#ifdef DEBUG
  // freopen("1099.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  for (int i = 2; i <= N/2 + 1; i++) {
    if (!b[i]) {
      for (int j = i * 2; j <= N; j += i) {
        b[j] = 1;
      }
    }
  }
  int k = 1;
  for (int i = 2; i <= N; ++i) {
    if (!b[i]) a[k++] = i;
  }

  int n;
  cin >> n;
  cout << a[n] << "\n";


  return 0;
}
```

[1099.cpp](/assets/src/ybt/1099.cpp)


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


int main( void ) {

#ifdef DEBUG
  freopen("1100.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, s = 0, d = 1;
  cin >> n;
  for (int i = 1; i <= n;) {
    int t = d;
    while (i <= n && d > 0)
      {
        s += t;
        d--;
        i++;
      }
    d = ++t;
  }

  cout << s << "\n";

  return 0;
}
```

[1100.cpp](/assets/src/ybt/1100.cpp)


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


int main( void ) {

#ifdef DEBUG
  freopen("1101.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int a, b, c, s = 0;
  cin >> a >> b >> c;
  for (int x = 0; x <= c / a + 1; ++x) {
    for (int y = 0; y < c / b + 1; ++y) {
      if (a*x + b*y == c) ++s;
    }
  }
  cout << s << "\n";

  return 0;
}
```

[1101.cpp](/assets/src/ybt/1101.cpp)


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


int main( void ) {

#ifdef DEBUG
  freopen("1102.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, a[120], m, s = 0;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  cin >> m;
  for (int i = 0; i < n; i++) if (a[i] == m) s++;
  cout << s << "\n";

  return 0;
}
```

[1102.cpp](/assets/src/ybt/1102.cpp)


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


int main( void ) {

#ifdef DEBUG
  freopen("1103.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int a[10];
  for (int i = 0; i < 10; i++) cin >> a[i];
  int k, s = 0;
  cin >> k;
  for (int i = 0; i < 10; i++) s += (k + 30 >= a[i]);
  cout << s << "\n";

  return 0;
}
```

[1103.cpp](/assets/src/ybt/1103.cpp)


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


int main( void ) {

#ifdef DEBUG
  freopen("1104.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  double p[10] =
    {
      28.9, 32.7, 45.6, 78, 35,
      86.2, 27.8, 43, 56, 65,
    }, s = 0, t;
  for (int i = 0; i < 10; i++)
    {
      cin >> t;
      s += t * p[i];
    }
  cout.precision(1);
  cout.setf(ios::fixed, ios::floatfield);
  cout << s << endl;

  return 0;
}
```

[1104.cpp](/assets/src/ybt/1104.cpp)


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


int main( void ) {

#ifdef DEBUG
  freopen("1105.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, a[120];
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = n - 1; i >= 0; i--)
    {
      cout << a[i];
      if (i == 0) cout << endl;
      else cout << " ";
    }

  return 0;
}
```

[1105.cpp](/assets/src/ybt/1105.cpp)


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


int main( void ) {

#ifdef DEBUG
  freopen("1106.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  double s[4];
  int n, a[120];
  cin >> n;
  for (int i = 0; i < 4; i++) s[i] = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] <= 18) s[0]++;
    else if (a[i] <= 35) s[1]++;
    else if (a[i] <= 60) s[2]++;
    else s[3]++;
  }
  cout.precision(2);
  cout.setf(ios::fixed, ios::floatfield);
  for (int i = 0; i < 4; i++)
    {
      cout << s[i] / n * 100 << "%\n";
    }

  return 0;
}
```

[1106.cpp](/assets/src/ybt/1106.cpp)


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


int a[10010];

int main( void ) {

#ifdef DEBUG
  freopen("1107.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int l, m;
  cin >> l >> m;
  for (int i = 0; i < m; i++)
    {
      int t, t2;
      cin >> t >> t2;
      for (int j = t; j <= t2; j++) a[j] = 1;
    }
  int s = 0;
  for (int i = 0; i <= l; i++) if (!a[i]) s++;
  cout << s << "\n";

  return 0;
}
```

[1107.cpp](/assets/src/ybt/1107.cpp)


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


int main( void ) {

#ifdef DEBUG
  freopen("1108.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int a[1010], b[1010], n;
  LL s = 0;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  for (int i = 0; i < n; i++) s += a[i]*b[i];
  cout << s << endl;

  return 0;
}
```

[1108.cpp](/assets/src/ybt/1108.cpp)


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


int a[5010];

int main( void ) {

#ifdef DEBUG
  freopen("1109.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) a[i] = 1;
  for (int i = 1; i <= m; i++)
    {
      for (int j = i; j <= n; j+=i)
        {
          if (j % i == 0) a[j] = 1-a[j];
        }
    }
  int s = 0;
  for (int i = 1; i <= n; i++)
    if (!a[i]) s++;
  for (int i = 1; i <= n; i++)
    {
      if (!a[i]) {
        cout << i;
        if (--s)
          cout << ",";
      }
    }
  cout << endl;

  return 0;
}
```

[1109.cpp](/assets/src/ybt/1109.cpp)


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


int a[10009];

int main( void ) {

#ifdef DEBUG
  freopen("1110.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, pos = -1, t;
  cin >> n;
  for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
  cin >> t;
  for (int i = 0; i < n; i++)
    {
      if (t == a[i])
        {
          pos = i + 1;
          break;
        }
    }
  cout << pos << endl;

  return 0;
}
```

[1110.cpp](/assets/src/ybt/1110.cpp)


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


int main( void ) {

#ifdef DEBUG
  freopen("1111.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int d = -1, m = -1, a, b;
  for (int i = 0; i < 7; i++)
    {
      cin >> a >> b;
      int s = a + b - 8;
      if (s > 0 && s > m)
        {
          m = s;
          d = i + 1;
        }
    }
  if (d != -1)
    cout << d << endl;
  else cout << 0 << endl;

  return 0;
}
```

[1111.cpp](/assets/src/ybt/1111.cpp)


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


int main( void ) {

#ifdef DEBUG
  freopen("1112.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int mi, ma, m, m1;
  mi = oo;
  ma = -oo;
  cin >> m1;
  for (int i = 0; i < m1; i++)
    {
      cin >> m;
      if (m > ma) ma = m;
      if (m < mi) mi = m;
    }
  cout << ma - mi << endl;

  return 0;
}
```

[1112.cpp](/assets/src/ybt/1112.cpp)


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


int main( void ) {

#ifdef DEBUG
  freopen("1113.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int a[110], n, ma, s = 0;
  ma = -oo;
  cin >> n;
  for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      if (a[i] > ma) ma = a[i];
    }
  for (int i = 0; i < n; i++)
    {
      if (a[i] != ma) s += a[i];
    }
  cout << s << endl;

  return 0;
}
```

[1113.cpp](/assets/src/ybt/1113.cpp)


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


int main( void ) {

#ifdef DEBUG
  freopen("1114.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, mad, mid;
  double ma, mi, a[310], av, pr, s=0;
  cout.precision(2);
  cout.setf(ios::fixed, ios::floatfield);
  cin >> n;
  ma=-oo;
  mi=oo;
  for (int i=0;i<n;i++)
    {
      cin>>a[i];
      s+=a[i];
      if(a[i]>ma)ma=a[i],mad=i;
      if(a[i]<=mi)mi=a[i],mid=i;
    }
  av=(s-ma-mi)/(n-2);
  pr=0;
  for(int i=0;i<n;i++)
    {
      if(i==mid || i==mad)continue;
      double t=fabs(a[i]-av);
      if(t>pr)pr=t;
    }
  cout << av << " " << pr<<endl;

  return 0;
}
```

[1114.cpp](/assets/src/ybt/1114.cpp)


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

const int N=10010;
int a[N], b[N];

int main( void ) {

#ifdef DEBUG
  freopen("1115.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, ma;
  cin>>n;
  ma=-oo;
  for(int i=0;i<N;i++)b[i]=0;
  for (int i=0;i<n;i++)
    {
      cin>>a[i];
      ma=max_(ma,a[i]);
      b[a[i]]++;
    }
  for(int i=0;i<=ma;i++)
    {
      cout<<b[i]<<endl;
    }

  return 0;
}
```

[1115.cpp](/assets/src/ybt/1115.cpp)


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


int main( void ) {

#ifdef DEBUG
  freopen("1116.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, ma=1, c, p, t=1;
  cin>>n;
  for(int i=0;i<n;i++)
    {
      cin>>c;
      if(i==0)
        {
          p=c;
          continue;
        }
      if(c==p)
        {
          t++;
          ma=max_(ma,t);
        }
      else
        {
          t=1;
          p=c;
        }
    }
  cout<<ma<<endl;

  return 0;
}
```

[1116.cpp](/assets/src/ybt/1116.cpp)


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


int a[5009];

int main( void ) {

#ifdef DEBUG
  freopen("1117.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, t, f=0;
  cin>>n;
  for(int i=0;i<n;i++)
    {
      cin>>t;
      if(a[t])continue;
      if(!f)
        {
          f=1;
        }
      else cout<< " ";
      cout<<t;
      a[t]=1;
    }
  cout<<endl;

  return 0;
}
```

[1117.cpp](/assets/src/ybt/1117.cpp)


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


struct rec
{
  int x1,y1,x2,y2;
};
const int N=10010;
rec a[N];

int main( void ) {

#ifdef DEBUG
  freopen("1118.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin>>n;
  int g,k,x,y,p=-1;
  for(int i=0;i<n;i++)
    {
      cin>>a[i].x1>>a[i].y1>>g>>k;
      a[i].x2=a[i].x1+g;
      a[i].y2=a[i].y1+k;
    }
  cin>>x>>y;
  for(int i=0;i<n;i++)
    {
      if(x>=a[i].x1 &&
         x<=a[i].x2 &&
         y>=a[i].y1 &&
         y<=a[i].y2) p=i+1;
    }
  cout<<p<<endl;

  return 0;
}
```

[1118.cpp](/assets/src/ybt/1118.cpp)


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


int main( void ) {

#ifdef DEBUG
  freopen("1119.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  double a[6][6];
  int m, n;
  for (int i=1;i<=5;i++)
    {
      for(int j=1;j<=5;j++)
        {
          cin>>a[i][j];
        }
    }
  cin>>m>>n;
  for(int i=1;i<=5;i++)
    {
      int t=i;
      if(i==m)t=n;
      else if(i==n)t=m;
      for(int j=1;j<=5;j++)
        {
          cout<<a[t][j];
          if(j==5)cout<<endl;
          else cout<< " ";
        }
    }

  return 0;
}
```

[1119.cpp](/assets/src/ybt/1119.cpp)


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


int main( void ) {

#ifdef DEBUG
  freopen("1120.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, I, J;
  cin>>n>>I>>J;
  for(int j=1;j<=n;j++)
    {
      cout<<"("<<I<<","<<j<<")";
      if(j==n)cout<<endl;
      else cout<<" ";
    }
  for(int i=1;i<=n;i++)
    {
      cout<<"("<<i<<","<<J<<")";
      if(i==n)cout<<endl;
      else cout<<" ";
    }
  for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=n;j++)
        {
          if(i-j==I-J)
            {
              cout<<"("<<i<<","<<j<<")";
              if(i==n||j==n)cout<<endl;
              else cout<<" ";
              break;
            }
        }
    }
  for(int i=n;i>=1;i--)
    {
      for(int j=1;j<=n;j++)
        {
          if(i+j==I+J)
            {
              cout<<"("<<i<<","<<j<<")";
              if(i==0||j==n)cout<<endl;
              else cout<<" ";
              break;
            }
        }
    }

  return 0;
}
```

[1120.cpp](/assets/src/ybt/1120.cpp)


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


int main( void ) {

#ifdef DEBUG
  freopen("1121.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int m,n;
  cin>>m>>n;
  LL s=0;
  for(int i=1;i<=m;i++)
    {
      for(int j=1;j<=n;j++)
        {
          int t;
          cin>>t;
          if(i==1||i==m||j==1||j==n)s+=t;
        }
    }
  cout<<s<<endl;

  return 0;
}
```

[1121.cpp](/assets/src/ybt/1121.cpp)


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


int main( void ) {

#ifdef DEBUG
  freopen("1122.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int a[6][6],l[6][6],c[6][6];
  for(int i=1;i<=5;i++)for(int j=1;j<=5;j++)l[i][j]=c[i][j]=0;
  for(int i=1;i<=5;i++)
    {
      int lm=-oo;
      for(int j=1;j<=5;j++)
        {
          cin>>a[i][j];
          if(a[i][j]>lm)
            {
              lm=a[i][j];
            }
        }
      for(int j=1;j<=5;j++)
        if(lm==a[i][j])
          l[i][j]=1;
    }
  for(int j=1;j<=5;j++)
    {
      int rm=oo;
      for(int i=1;i<=5;i++)
        {
          if(a[i][j]<rm)
            {
              rm=a[i][j];
            }
        }
      for(int i=1;i<=5;i++)
        if(rm==a[i][j])
          c[i][j]=1;
    }
  bool flag=false;
  for(int i=1;i<=5;i++)
    {
      for(int j=1;j<=5;j++)
        {
          if(c[i][j]&&l[i][j])
            {
              cout<<i<<" "<<j<<" "<<a[i][j]<<endl;
              flag=true;
            }
        }
    }
  if(!flag)cout<<"not found\n";

  return 0;
}
```

[1122.cpp](/assets/src/ybt/1122.cpp)


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


int main( void ) {

#ifdef DEBUG
  freopen("1123.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n,m,a[120][120],b[120][120], s=0;
  cin>>m>>n;
  for(int i=1;i<=m;i++)for(int j=1;j<=n;j++)cin>>a[i][j];
  for(int i=1;i<=m;i++)for(int j=1;j<=n;j++)cin>>b[i][j];
  cout.precision(2);
  cout.setf(ios::fixed, ios::floatfield);
  for(int i=1;i<=m;i++)for(int j=1;j<=n;j++)if(a[i][j]==b[i][j])s++;
  cout<<double(100.*s/(m*n))<<endl;

  return 0;
}
```

[1123.cpp](/assets/src/ybt/1123.cpp)


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


int main( void ) {

#ifdef DEBUG
  freopen("1124.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n,m,a[120][120],b[120][120];
  cin>>n>>m;
  for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>a[i][j];
  for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
                         {
                           cin>>b[i][j];
                           b[i][j]+=a[i][j];
                         }
  for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
        {
          cout<<b[i][j];
          cout<<(j==m?"\n":" ");
        }
    }

  return 0;
}
```

[1124.cpp](/assets/src/ybt/1124.cpp)


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


int main( void ) {

#ifdef DEBUG
  freopen("1125.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n,m,k,a[120][120],b[120][120],c[120][120];
  cin>>n>>m>>k;
  for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>a[i][j];
  for(int i=1;i<=m;i++)for(int j=1;j<=k;j++)cin>>b[i][j];
  for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=k;j++)
        {
          c[i][j]=0;
          for(int k1=1;k1<=m;k1++)
            {
              c[i][j]+=(a[i][k1]*b[k1][j]);
            }
        }
    }
  for(int i=1;i<=n;i++)for(int j=1;j<=k;j++)
                         {
                           cout<<c[i][j];
                           cout<<(j==k?"\n":" ");
                         }

  return 0;
}
```

[1125.cpp](/assets/src/ybt/1125.cpp)


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


int main( void ) {

#ifdef DEBUG
  freopen("1126.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n,m,a[120][120];
  cin>>n>>m;
  for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>a[j][i];
  for(int i=1;i<=m;i++)for(int j=1;j<=n;j++)
                         {
                           cout<<a[i][j];
                           cout<<(j==n?"\n":" ");
                         }

  return 0;
}
```

[1126.cpp](/assets/src/ybt/1126.cpp)


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


int main( void ) {

#ifdef DEBUG
  freopen("1127.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n,m,a[120][120];
  cin>>n>>m;
  for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>a[j][n+1-i];
  for(int i=1;i<=m;i++)for(int j=1;j<=n;j++)
                         {
                           cout<<a[i][j];
                           cout<<(j==n?"\n":" ");
                         }

  return 0;
}
```

[1127.cpp](/assets/src/ybt/1127.cpp)


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

static int dir[4][2]={ {0,1},{0,-1},{1,0},{-1,0} };

int main( void ) {

#ifdef DEBUG
  freopen("1128.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m, a[120][120], b[120][120];
  cin>>n>>m;
  for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
                         {
                           cin>>a[i][j];
                           b[i][j]=a[i][j];
                         }

  for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
        {
          if(i==1||i==n||
             j==1||j==m) continue;
          else
            {
              int cnt=1;
              b[i][j]=a[i][j];
              for(int c=0;c<4;c++)
                {
                  int i1=i+dir[c][0],j1=j+dir[c][1];
                  if(i1>=1&&i1<=n&&
                     j1>=1&&j1<=m)
                    {
                      cnt++;
                      b[i][j]+=a[i1][j1];
                    }
                }
              b[i][j] = int(round(b[i][j]*1./cnt));
            }
        }
    }
  for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
                         {
                           cout<<b[i][j];
                           cout<<(j==m?"\n":" ");
                         }

  return 0;
}
```

[1128.cpp](/assets/src/ybt/1128.cpp)


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


int main( void ) {

#ifdef DEBUG
  freopen("1129.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  char s[300];
  cin.getline(s, 260);
  int c=0;
  for(int i=0;s[i];i++)
    {
      if(s[i]>='0'&&s[i]<='9')c++;
    }
  cout<<c<<endl;

  return 0;
}
```

[1129.cpp](/assets/src/ybt/1129.cpp)


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

int a[27];

int main( void ) {

#ifdef DEBUG
  freopen("1130.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin>>s;
  for(int i=0;s[i];i++)
    {
      a[s[i]-'a']++;
    }
  bool flag=false;
  for(int i=0;i<26;i++)
    {
      if(a[i]==1)
        {
          flag=true;
          break;
        }
    }
  if(flag)
    {
      for(int i=0;s[i];i++)
        {
          if(a[s[i]-'a']==1)
            {
              cout<<s[i]<<endl;
              break;
            }
        }
    }
  else
    {
      cout<<"no\n";
    }

  return 0;
}
```

[1130.cpp](/assets/src/ybt/1130.cpp)


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


int main( void ) {

#ifdef DEBUG
  freopen("1131.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  double th, len, cnt=0;
  string a,b;
  cin>>th>>a>>b;
  len=a.size();
  for(int i=0;i<len;i++)
    {
      if(a[i]==b[i])cnt++;
    }
  if(cnt/len>=th)cout<<"yes\n";
  else cout<<"no\n";

  return 0;
}

```

[1131.cpp](/assets/src/ybt/1131.cpp)


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


int conv(string a)
{
  if(a=="Rock") return 1;
  else if(a=="Scissors") return 2;
  else return 4;
}

bool check(string a,string b)
{
  int a1=conv(a), b1=conv(b), c=a1|b1;
  switch(c)
    {
    case 3:
      return (a1==1);
    case 5:
        return (a1==4);
    case 6:
      return (a1==2);
    }
  return true;
}

int main( void ) {

#ifdef DEBUG
  freopen("1132.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin>>n;
  while(n--)
    {
      string s1,s2;
      cin>>s1>>s2;
      if(s1==s2)cout<<"Tie\n";
      else
          cout<<(check(s1,s2)?"Player1\n":"Player2\n");
    }

  return 0;
}
```

[1132.cpp](/assets/src/ybt/1132.cpp)


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


int main( void ) {

#ifdef DEBUG
  freopen("1133.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  string a, b="";
  cin>>a;
  for(int i=0;i<int(a.size()-1);i++)
    {
      b=b+char(int(a[i]+a[i+1]));
    }
  b=b+char(int(a[a.size()-1]+a[0]));
  cout<<b<<endl;

  return 0;
}
```

[1133.cpp](/assets/src/ybt/1133.cpp)


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


int main( void ) {

#ifdef DEBUG
  // freopen("1134.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  string words[50]={"auto", "break", "case", "char", "const",
    "continue", "default", "do",
    "double", "else", "enum", "extern", "float", "for", "goto",
    "if", "int", "long", "register",
    "return", "short", "signed", "sizeof", "static", "struct",
    "switch", "typedef", "union",
    "unsigned", "void", "volatile", "while"};
  string s;
  cin>>s;
  for(int i=0;i<32;i++)if(words[i]==s)
                                        {
                                          cout<<"no\n";
                                          return 0;
                                        }
  if(s.size()>0&&isdigit(s[0]))
    {
      cout<<"no\n";
      return 0;
    }
  for(int i=0;i<int(s.size());i++)
    {
      if(s[i]=='_'||isalnum(s[i])) continue;
      else
        {
          cout<<"no\n";
          return 0;
        }
    }
  cout<<"yes\n";

  return 0;
}
```

[1134.cpp](/assets/src/ybt/1134.cpp)


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


char conv(char c)
{
  switch(c)
    {
    case 'T': return 'A';
    case 'A': return 'T';
    case 'C': return 'G';
    case 'G': return 'C';
    }
  return 'A';
}

int main( void ) {

#ifdef DEBUG
  freopen("1135.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  string a, b;
  cin>>a;
  for(int i=0;i<int(a.size());i++)b+=conv(a[i]);
  cout<<b<<endl;

  return 0;
}
```

[1135.cpp](/assets/src/ybt/1135.cpp)


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


int main( void ) {

#ifdef DEBUG
  freopen("1136.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  char a[100];
  string b;
  cin.getline(a, 100);
  for(int i=0;a[i];i++)
    {
      if(isalpha(a[i]))
        {
          if(a[i]=='z')b+='a';
          else if(a[i]=='Z')b+='A';
          else b+=char(a[i]+1);
        }
      else b+=a[i];
    }
  cout<<b<<endl;

  return 0;
}
```

[1136.cpp](/assets/src/ybt/1136.cpp)


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


string rev(string a)
{
  string b="";
  for(int i=int(a.size()-1);i>=0;i--)b+=a[i];
  return b;
}

string uplow(string a)
{
  string b="";
  for(int i=0;i<int(a.size());i++)
    {
      if(isupper(a[i]))
        {
          b+=tolower(a[i]);
        }
      else
        {
          b+=toupper(a[i]);
        }
    }
  return b;
}

string rota(string a)
{
  string b;
  for(int i=0;i<int(a.size());i++)
    {
      int of;
      if(isupper(a[i]))
        {
          of=(a[i]-'A'+3)%26;
          b+=('A'+of);
        }
      else
        {
          of=(a[i]-'a'+3)%26;
          b+=('a'+of);
        }
    }
  return b;
}

int main( void ) {

#ifdef DEBUG
  freopen("1137.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  string a;
  cin>>a;
  cout<<rota(rev(uplow(a)))<<endl;

  return 0;
}
```

[1137.cpp](/assets/src/ybt/1137.cpp)


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


int main( void ) {

#ifdef DEBUG
  freopen("1138.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  char a[120];
  cin.getline(a, 110);
  string b;
  for(int i=0;a[i];i++)
    {
      if(islower(a[i]))b+=a[i]-32;
      else b+=a[i];
    }
  cout<<b<<endl;

  return 0;
}
```

[1138.cpp](/assets/src/ybt/1138.cpp)


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


int main( void ) {

#ifdef DEBUG
  freopen("1139.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin>>n;
  string a,b;
  for(int _i=0;_i<n;_i++)
    {
      cin>>a;
      b="";
      for(int i=0;i<int(a.size());i++)
        {
          if(i==0&&isalpha(a[i]))
            {
              b+=toupper(a[i]);
            }
          else if(isalpha(a[i]))
            b+=tolower(a[i]);
          else b+=a[i];
        }
      cout<<b<<endl;
    }

  return 0;
}
```

[1139.cpp](/assets/src/ybt/1139.cpp)


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


bool contains(string a,string b)
{
  int al=int(a.size()),bl=int(b.size());
  for(int i=0;i<al;i++)
    {
      int i1=i, j1=0;
      while(i1<al&&
            j1<bl&&
            a[i1]==b[j1])
        {
          i1++,j1++;
        }
      if(j1==bl)
        {
          return true;
        }
    }
  return false;
}

int main( void ) {

#ifdef DEBUG
  // freopen("1140.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  string a,b;
  cin>>a>>b;
  size_t al=a.size(),bl=b.size();
  if(al>=bl)
    {
      if(contains(a,b))
        {
          cout<<b<<" is substring of "<<a<<endl;
        }
      else cout<<"No substring\n";
    }
  else
    {
      if(contains(b, a))
        cout<<a<<" is substring of "<<b<<endl;
      else cout<<"No substring\n";
    }

  return 0;
}
```

[1140.cpp](/assets/src/ybt/1140.cpp)


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


int main( void ) {

#ifdef DEBUG
  freopen("1141.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  string s, b;
  cin>>s;
  int sl=int(s.size());
  if(sl<2)cout<<s<<endl;
  else
    {
      string su1, su2;
      su1=su1+s[sl-2]+s[sl-1];
      if(sl>=3)
        {
          su2+=s[sl-3];
          su2+=su1;
        }
      int li=sl;
      if(su1=="er"||su1=="ly") li=sl-2;
      else if(su2=="ing") li=sl-3;
      for(int i=0;i<li;i++)b+=s[i];
      cout<<b<<endl;
    }

  return 0;
}
```

[1141.cpp](/assets/src/ybt/1141.cpp)


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


int main( void ) {

#ifdef DEBUG
  freopen("1142.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  char a[1010];
  cin.getline(a,1009);
  bool flag=true;
  int cnt=0;
  for(int i=0;a[i];i++)
    {
      if(isspace(a[i]))
        {
          if(cnt)
            {
              if(!flag)cout<<","<<cnt;
              else
                {
                  cout<<cnt;flag=false;
                }

              cnt=0;
            }
        }
      else ++cnt;
    }
  if(cnt)
    {
      if(!flag)cout<<","<<cnt;
      else cout<<cnt;
    }
  cout<<endl;

  return 0;
}
```

[1142.cpp](/assets/src/ybt/1142.cpp)


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


const int N=200*100+200;
char a[N];

int main( void ) {

#ifdef DEBUG
  freopen("1143.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin.getline(a, N-10);
  int ma,mi;
  string mas, mis, t;
  ma=0;
  mi=oo;
  bool flag=false;
  for(int i=0;a[i];i++)
    {
      if(a[i]==','||isspace(a[i]))
        {
          if(!flag) continue;
          flag=false;
          int cl=int(t.size());
          if(cl>ma)
            {
              ma=cl;
              mas=t;
            }
          if(cl<mi)
            {
              mi=cl;
              mis=t;
            }
          t="";
        }
      if(isalpha(a[i]))
        {
          flag=true;
          t+=a[i];
        }
    }
  cout<<mas<<endl<<mis<<endl;

  return 0;
}
```

[1143.cpp](/assets/src/ybt/1143.cpp)


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


string rev(string a)
{
  string b;
  for(int i=int(a.size()-1);i>=0;i--)b+=a[i];
  return b;
}

int main( void ) {

#ifdef DEBUG
  // freopen("1144.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  char a[600];
  cin.getline(a, 500);
  string b, t;
  bool flag=false;
  for(int i=0;a[i];i++)
    {
      if(isalpha(a[i]))
        {
          flag=true;
          t+=a[i];
        }
      else
        {
          if(flag)
            {
              b+=rev(t);
              t="";
              flag=false;
            }
          b+=a[i];
        }
    }
  if(flag && t.size())
    {
      b+=rev(t);
    }
  cout<<b<<endl;

  return 0;
}
```

[1144.cpp](/assets/src/ybt/1144.cpp)


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


string conv(int n)
{
  stringstream ss;
  ss << n;
  string s1;
  ss>>s1;
  return s1;
}

int main( void ) {

#ifdef DEBUG
  // freopen("1145.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  string a,b;
  cin>>a;
  char c='\0';
  int cnt=0;
  for(int i=0;i<int(a.size());i++)
    {
      if(c==a[i])
        {
          cnt++;
        }
      else
        {
          if(c=='\0')
            {
              c=a[i];
              cnt=1;
              continue;
            }

          b+=conv(cnt);

          b+=c;
          cnt=1;
          c=a[i];
        }
    }
  b+=conv(cnt);
  b+=c;

  cout<<b<<endl;

  return 0;
}
```

[1145.cpp](/assets/src/ybt/1145.cpp)


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


int main( void ) {

#ifdef DEBUG
  freopen("1146.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  string a;
  cin>>a;
  int al=int(a.size());
  for(int i=0,j=al-1;i<j;i++,j--)
    {
      if(a[i]!=a[j])
        {
          cout<<"no\n";
          return 0;
        }
    }
  cout<<"yes\n";

  return 0;
}
```

[1146.cpp](/assets/src/ybt/1146.cpp)


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


int main( void ) {

#ifdef DEBUG
  freopen("1147.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int ri = -1, n, s;
  string rs, t;
  cin>>n;
  for(int i=0;i<n;i++)
    {
      cin>>s>>t;
      if(s>ri)
        {
          ri=s;
          rs=t;
        }
    }
  cout<<rs<<endl;

  return 0;
}
```

[1147.cpp](/assets/src/ybt/1147.cpp)


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


int main( void ) {

#ifdef DEBUG
  freopen("1148.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int k, cnt=0;
  string s;
  char c='\0', cur;
  cin>>k>>s;
  for(int i=0;i<int(s.size());i++)
    {
      if(cnt==0)
        {
          cur=s[i];
          cnt++;
          if(cnt>=k)
            {
              c=cur;
              break;
            }
          continue;
        }
      if(cur==s[i])
        {
          cnt++;
          if(cnt>=k)
            {
              c=cur;
              break;
            }
        }
      else
        {
          cur=s[i];
          cnt=1;
        }
    }
  if(c)
    cout<<c<<endl;
  else cout<<"No\n";

  return 0;
}
```

[1148.cpp](/assets/src/ybt/1148.cpp)


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


int main( void ) {

#ifdef DEBUG
  freopen("1149.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  char a[600];
  cin.getline(a, 500);
  string cur,res;
  int cnt=0, ma=0;
  for(int i=0;a[i];i++)
    {
      if(i==0)
        {
          if(isspace(a[i]))continue;
          cnt=1;
          cur+=a[i];
          res=cur;
          continue;
        }
      if(isspace(a[i]))
        {
          if(cnt>ma)
            {
              ma=cnt;
              res=cur;
            }
          cur="";
          cnt=0;
        }
      else
        {
          cnt++;
          cur+=a[i];
        }
    }
  if(cnt>ma)
    {
      res=cur;
    }
  if(res[res.size()-1]=='.')
    {
      string b;
      for(int i=0;i<int(res.size())-1;i++)b+=res[i];
      res=b;
    }
  cout<<res<<endl;

  return 0;
}
```

[1149.cpp](/assets/src/ybt/1149.cpp)


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


bool sum(int n){
  int s=1;
  for(int i=2;i<n;i++){
    if(n%i==0)s+=i;
  }
  return s==n;
}

int main( void ) {

#ifdef DEBUG
  freopen("1150.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin>>n;
  for (int i=2;i<=n;i++){
    if(sum(i))cout<<i<<endl;
  }

  return 0;
}
```

[1150.cpp](/assets/src/ybt/1150.cpp)


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


const int N=50000+100;
int a[N];

int main( void ) {

#ifdef DEBUG
  freopen("1151.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, s=0;
  cin>>n;
  for(int i=2;i<=n;i++){
    if(!a[i]){
      s++;
      for(int j=i<<1;j<=n;j+=i){
        a[j]=1;
      }
    }
  }
  cout<<s<<endl;

  return 0;
}
```

[1151.cpp](/assets/src/ybt/1151.cpp)


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


double Max(double a,double b,double c){
  return max_(a,max_(b, c));
}

int main( void ) {

#ifdef DEBUG
  freopen("1152.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  double a,b,c;
  cin>>a>>b>>c;
cout.precision(3);
cout.setf(ios::fixed,ios::floatfield);
cout<<Max(a,b,c)/(Max(a+b,b,c)*Max(a,b,b+c))<<endl;

  return 0;
}
```

[1152.cpp](/assets/src/ybt/1152.cpp)


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


int rev(int n){
  int r=0;
  while(n){
    r=r*10+n%10;
    n/=10;
  }
  return r;
}

int a[100];

int main( void ) {

#ifdef DEBUG
  freopen("1153.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  for(int i=2;i<=100;i++){
    if(!a[i]){
      for(int j=i<<1;j<=100;j+=i){
        a[j]=1;
      }
    }
  }
  for(int i=10;i<=100;i++){
    int r=rev(i);
    if(!a[r]&&!a[i]){
      cout<<i<<endl;
    }
  }

  return 0;
}
```

[1153.cpp](/assets/src/ybt/1153.cpp)


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


int sum(int n){
  int s=0;
  for(int i=1;i<n;i++){
    if(n%i==0){
      s+=i;
    }
  }
  return s;
}

bool check(int n){
  int n1=sum(n);
  return n==sum(n1);
}

int main( void ) {

#ifdef DEBUG
  freopen("1154.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  for(int i=2;;i++){
    if(check(i)){
      int i1=sum(i);
      if(i1==i) continue;
      if(i1<i){
        swap(i,i1);
      }
      cout<<i<<" "<<i1<<endl;
      break;
    }
  }

  return 0;
}
```

[1154.cpp](/assets/src/ybt/1154.cpp)


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


const int N=1000+10;
int a[N];
int rev(int n){
  int s=0;
  while(n){
    s=s*10+n%10;
    n/=10;
  }
  return s;
}

int main( void ) {

#ifdef DEBUG
  freopen("1155.in", "r", stdin);
#endif

  for(int i=2;i<=N;i++){
    for(int j=i<<1;j<=N;j+=i){
      if(!a[i]){
        a[j]=1;
      }
    }
  }

  for(int i=100;i<=999;i++){
    if(!a[i]&&(i==rev(i))){
      cout<<i<<endl;
    }
  }

  return 0;
}
```

[1155.cpp](/assets/src/ybt/1155.cpp)


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


double atanx(double x){
  double s=0, t, x1=x;
  int m=1;

  for(int i=1;;i+=2){
    t=m*x1/i;
    // NOTE:先判断精度!
    if(fabs(t)<1e-6)break;
    s+=t;
    m*=-1;
    x1*=(x*x);
  }
  return s;
}

int main( void ) {

#ifdef DEBUG
  freopen("1156.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cout.precision(10);
  cout.setf(ios::fixed, ios::floatfield);
  cout<<6*atanx(1/sqrt(3))<<endl;

  return 0;
}
```

[1156.cpp](/assets/src/ybt/1156.cpp)


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

const int N=100+100;
int a[N];
void pro(int n)
{
  for(int i=2;i<=n;i++)
    {
      if(!a[i]&&!a[n-i])
        {
          cout<<n<<"="<<i<<"+"<<n-i<<endl;
          break;
        }
    }
}

int main( void ) {

#ifdef DEBUG
  freopen("1157.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  a[0]=a[1]=1;
  for(int i=2;i<=N;i++)
    {
      if(!a[i])
        {
          for(int j=i<<1;j<=N;j+=i)
            a[j]=1;
        }
    }

  for(int i=6;i<=100;i+=2)
    {
      pro(i);
    }


  return 0;
}
```

[1157.cpp](/assets/src/ybt/1157.cpp)


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


int sum(int n)
{
  if(n<=0)return 0;
  return n+sum(n-1);
}

int main( void ) {

#ifdef DEBUG
  freopen("1158.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin>>n;
  cout<<sum(n)<<endl;

  return 0;
}
```

[1158.cpp](/assets/src/ybt/1158.cpp)


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


LL fa(int n)
{
  if(n==1)return 0;
  else if(n==2) return 1;
  return fa(n-1)+fa(n-2);
}

int main( void ) {

#ifdef DEBUG
  freopen("1159.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin>>n;
  cout<<fa(n)<<endl;

  return 0;
}
```

[1159.cpp](/assets/src/ybt/1159.cpp)


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


void rev(int n)
{
  if(!n)
    {
      cout<<endl;
      return;
    }
  cout<<n%10;
  rev(n/10);
}

int main( void ) {

#ifdef DEBUG
  freopen("1160.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin>>n;
  rev(n);

  return 0;
}
```

[1160.cpp](/assets/src/ybt/1160.cpp)


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


void conv(int n,int k)
{
  if(!n) return;
  conv(n/k, k);
  int r=n%k;
  if(r>=10)
    {
      cout<<char('A'+(r-10));
    }
  else
    cout<<r;
}

int main( void ) {

#ifdef DEBUG
  freopen("1161.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n,k;
  cin>>n>>k;
  conv(n,k);
  cout<<endl;

  return 0;
}
```

[1161.cpp](/assets/src/ybt/1161.cpp)


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


void pro()
{
  char c=getchar();
  if (c=='!')
    {
      return;
    }
  pro();
  putchar(c);
}

int main( void ) {

#ifdef DEBUG
  freopen("1162.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  pro();

  return 0;
}
```

[1162.cpp](/assets/src/ybt/1162.cpp)


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


int pro(int m, int n)
{
  if(!m)
    {
      return n+1;
    }
  if(m>0&&!n)
    {
      return pro(m-1,1);
    }
  else if(m>0&&n>0)
    {
      return pro(m-1,pro(m,n-1));
    }
  return 0;
}


int main( void ) {

#ifdef DEBUG
  freopen("1163.in", "r", stdin);
#endif

  int m,n;
  cin>>m>>n;
  cout<<pro(m,n)<<endl;

  return 0;
}
```

[1163.cpp](/assets/src/ybt/1163.cpp)


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


int digit(int n, int k)
{
  if(k==1)
    {
      return n%10;
    }
  return digit(n/10,k-1);
}

int main( void ) {

#ifdef DEBUG
  freopen("1164.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n,k;
  cin>>n>>k;
  cout<<digit(n,k)<<endl;

  return 0;
}
```

[1164.cpp](/assets/src/ybt/1164.cpp)


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


double pro(int n,int x)
{
  if(!n)return 1;
  if(n==1)return 2*x;
  if(n>1)return 2*x*pro(n-1,x)-2*(n-1)*pro(n-2,x);
  return 0;
}

int main( void ) {

#ifdef DEBUG
  freopen("1165.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n,x;
  cin>>n>>x;
  cout.precision(2);
  cout.setf(ios::fixed, ios::floatfield);
  cout<<pro(n,x)<<endl;

  return 0;
}
```

[1165.cpp](/assets/src/ybt/1165.cpp)


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


double pro(double x, int n)
{
  if(n==1)
    return sqrt(n+x);
  return sqrt(n+pro(x, n-1));
}

int main( void ) {

#ifdef DEBUG
  freopen("1166.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  double x; int n;
  cin>>x>>n;
  cout.precision(2);
  cout.setf(ios::fixed,ios::floatfield);
  cout<<pro(x,n)<<endl;

  return 0;
}
```

[1166.cpp](/assets/src/ybt/1166.cpp)


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


double pro(double x,int n)
{
  if(n==1)
    {
      return x/(1+x);
    }
  return x/(n+pro(x,n-1));
}

int main( void ) {

#ifdef DEBUG
  freopen("1167.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  double x;
  int n;
  cin>>x>>n;
  cout.precision(2);
  cout.setf(ios::fixed,ios::floatfield);
  cout<<pro(x,n)<<endl;

  return 0;
}
```

[1167.cpp](/assets/src/ybt/1167.cpp)


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
```

[1397.cpp](/assets/src/ybt/1397.cpp)


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


int main( void ) {

#ifdef DEBUG
  freopen("1398.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, t;
  double s=0;
  cin>>n;
  while(n--)
    {
      cin>>t;
      s+=0.1*ceil(t*1./70);
    }
  cout.precision(1);
  cout.setf(ios::fixed,ios::floatfield);
  cout<<s<<endl;

  return 0;
}
```

[1398.cpp](/assets/src/ybt/1398.cpp)


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


int main( void ) {

#ifdef DEBUG
  freopen("1399.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n,cnt=0,mark;
  cin>>n;
  string s;
  double t;
  while(n--)
    {
      cin>>s>>t>>mark;
      if(mark&&t>=37.5)
        {
          cnt++;
          cout<<s<<endl;
        }
    }
  cout<<cnt<<endl;

  return 0;
}
```

[1399.cpp](/assets/src/ybt/1399.cpp)


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

  // NOTE: 输入字符串的长度大于 10000，使用 string,不能预设长度。
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
```

[1400.cpp](/assets/src/ybt/1400.cpp)


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


const int N=2000;
int vi[N];

int main( void ) {

#ifdef DEBUG
  freopen("1401.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int m,n,t,cnt=0;
  cin>>m>>n;
  queue<int> q;
  for(int i=0;i<n;i++)
    {
      cin>>t;
      if(!vi[t])
        {
          cnt++;
          if(q.size()==size_t(m))
            {
              int t1=q.front();
              vi[t1]=0;
              q.pop();
              q.push(t);
              vi[t]=1;
            }
          else
            {
              q.push(t);
              vi[t]=1;
            }
        }
    }
  cout<<cnt<<endl;

  return 0;
}
```

[1401.cpp](/assets/src/ybt/1401.cpp)


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


char a[30][30];

int main( void ) {

#ifdef DEBUG
  freopen("1402.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  for(char i='A';i<='Z';i++)
    {
      for(char j='A';j<='Z';j++)
        {
          int i1=i-'A',j1=j-'A';
          a[i1][j1]=(i1+j1)%26;
        }
    }
  char k[200];
  cin>>k;
  for(int i=0;k[i];i++)k[i]=toupper(k[i]);
  char C[1100];
  cin>>C;
  string m;
  for(int i=0;C[i];i++)
    {
      int c1=toupper(C[i])-'A', k1=k[i%strlen(k)]-'A', m1=0;
      for(int j=0;j<26;j++)
        {
          if(a[j][k1]==c1)
            {
              m1=j;
              break;
            }
        }
      if(isupper(C[i]))
        {
          m1+='A';
        }
      else m1+='a';
      m+=char(m1);
    }
  cout<<m<<endl;

  return 0;
}
```

[1402.cpp](/assets/src/ybt/1402.cpp)


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

const int N=10000+100;
int a[N];


int main( void ) {

#ifdef DEBUG
  freopen("1403.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  a[0]=a[1]=1;
  for(int i=2;i<=N;i++)
    {
      if(!a[i])
        {
          for(int j=i<<1;j<=N;j+=i)
            a[j]=1;
        }
    }

  int n;
  cin>>n;
  bool flag=false;
  for(int i=2;i<=n-2;i++)
    {
      if(!a[i]&&!a[i+2])
        {
          flag=true;
          cout<<i<<" "<<i+2<<endl;
        }
    }
  if(!flag)cout<<"empty\n";

  return 0;
}
```

[1403.cpp](/assets/src/ybt/1403.cpp)


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


int main( void ) {

#ifdef DEBUG
  freopen("1404.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  LL n,x,m;
  cin>>n;
  for(m=2;;m++)
    {
      LL x1=m*(m+1)-(n<<1);
      x=x1/6;
      if(x1>0 && (x1%6==0) && x>0 && x<=m)
        {
          cout<<x<<" "<<m<<endl;
          break;
        }
    }

  return 0;
}
```

[1404.cpp](/assets/src/ybt/1404.cpp)


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


const int N=10000+100;
int a[N];

int main( void ) {

#ifdef DEBUG
  freopen("1405.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  a[0]=a[1]=1;
  for(int i=2;i<=N;i++)
    {
      if(!a[i])
        {
          for(int j=i<<1;j<=N;j+=i)
            a[j]=1;
        }
    }
  int n, res=0;
  cin>>n;
  for(int i=2;i<n;i++)
    {
      int j=n-i;
      if(!a[i] &&!a[j])
        {
          res=max_(res,i*j);
        }
    }
  cout<<res<<endl;

  return 0;
}
```

[1405.cpp](/assets/src/ybt/1405.cpp)


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


string a,b;
char s[300];
int pos;

void get_token()
{
  while(s[pos])
    {
      while(s[pos]&&isspace(s[pos]))
        {
          cout<<s[pos++];
        }
      string t="";
      while(s[pos]&&isalpha(s[pos]))
        {
          t+=s[pos++];
        }
      if(t==a)
        {
          cout<<b;
        }
      else cout<<t;
    }
  cout<<endl;
}

int main( void ) {

#ifdef DEBUG
  freopen("1406.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin.getline(s, 201);
  cin>>a>>b;

  get_token();

  return 0;
}
```

[1406.cpp](/assets/src/ybt/1406.cpp)


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


const int N=1000+100;
int a[N], w[30];

int main( void ) {

#ifdef DEBUG
  freopen("1407.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  a[0]=a[1]=1;
  for(int i=2;i<=N;i++)
    {
      if(!a[i])
        {
          for(int j=i<<1;j<=N;j+=i)
            a[j]=1;
        }
    }

  string s;
  while(cin>>s)
    {
      int ma=0,mi=1000;
      memset(w,0,sizeof(w));
      for(size_t i=0;i<s.size();i++)
        {
          if(!isalpha(s[i]))continue;
          if(s[i]>='a'&&s[i]<='z')
            {
              int t=s[i]-'a';
              w[t]++;

              // TODO:为什么这里不对???
              // ma=max_(ma,w[t]);
              // mi=min_(mi,w[t]);
            }
        }
      for(int i=0;i<26;i++)
        {
          if(!w[i])continue;
          ma=max_(ma,w[i]);
          mi=min_(mi,w[i]);
        }
      int t1=ma-mi;
      if(t1>=0&&!a[t1])
        {
          cout<<"Lucky Word\n"<<t1<<endl;
        }
      else cout<<"No Answer\n"<<0<<endl;
    }

  return 0;
}
```

[1407.cpp](/assets/src/ybt/1407.cpp)


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


int rev(int n)
{
  int s=0;
  while(n)
    {
      s=s*10+n%10;
      n/=10;
    }
  return s;
}
const int N=10000;
int a[N];


int main( void ) {

#ifdef DEBUG
  freopen("1408.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  a[0]=a[1]=1;
  for(int i=2;i<=N;i++)
    {
      if(!a[i])
        {
          for(int j=i<<1;j<=N;j+=i)
            a[j]=1;
        }
    }

  int n,cnt=0;
  cin>>n;
  for(int i=11;i<=n;i++)
    {
      if(rev(i)==i&&!a[i])cnt++;
    }
  cout<<cnt<<endl;

  return 0;
}
```

[1408.cpp](/assets/src/ybt/1408.cpp)


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

const int N=100000+100;
int a[N];


int main( void ) {

#ifdef DEBUG
  freopen("1409.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);


  a[0]=a[1]=1;
  for(int i=2;i<=N;i++)
    {
      if(!a[i])
        {
          for(int j=i<<1;j<=N;j+=i)
            a[j]=1;
        }
    }

  int x,y,cnt=0;
  cin>>x>>y;
  for(int i=x;i<=y;i++)
    {
      if(!a[i])cnt++;
    }
  cout<<cnt<<endl;

  return 0;
}
```

[1409.cpp](/assets/src/ybt/1409.cpp)


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

const int N=10000;
int a[N];

int pro(int n)
{
  for(int i=n;i>=2;i--)
    {
      if(!a[i]&&n%i==0) return i;
    }
  return 0;
}

int main( void ) {

#ifdef DEBUG
  freopen("1410.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  a[0]=a[1]=1;
  for(int i=2;i<=N;i++)
    {
      if(!a[i])
        {
          for(int j=i<<1;j<=N;j+=i)
            a[j]=1;
        }
    }

  int m,n;
  cin>>m>>n;
  for(int i=m;i<=n;i++)
    {
      cout<<pro(i);
      if(i==n)cout<<endl;
      else cout<<",";
    }

  return 0;
}
```

[1410.cpp](/assets/src/ybt/1410.cpp)


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


int rev(int n)
{
  int s=0;
  while(n)
    {
      s=s*10+n%10;
      n/=10;
    }
  return s;
}

const int N=100000+100;
int a[N];

int main( void ) {

#ifdef DEBUG
  freopen("1411.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  a[0]=a[1]=1;
  for(int i=2;i<=N;i++)
    {
      if(!a[i])
        {
          for(int j=i<<1;j<=N;j+=i)
            a[j]=1;
        }
    }

  int m,n;
  cin>>m>>n;
  bool flag=true;
  for(int i=m;i<=n;i++)
    {
      int j=rev(i);
      if(!a[i]&&!a[j])
        {
          if(!flag)cout<<",";
          cout<<i;
          flag=false;
        }
    }
  if(flag)cout<<"No\n";
  else cout<<endl;

  return 0;
}
```

[1411.cpp](/assets/src/ybt/1411.cpp)


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


bool check(int n)
{
  int c1=0,c0=0;
  while(n)
    {
      if(n&1)c1++;
      else c0++;
      n>>=1;
    }
  return c1>c0;
}

int main( void ) {

#ifdef DEBUG
  freopen("1412.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int ca=0,cb=0;
  for(int i=1;i<=1000;i++)
    {
      if(check(i))ca++;
      else cb++;
    }
  cout<<ca<<" "<<cb<<endl;

  return 0;
}
```

[1412.cpp](/assets/src/ybt/1412.cpp)

