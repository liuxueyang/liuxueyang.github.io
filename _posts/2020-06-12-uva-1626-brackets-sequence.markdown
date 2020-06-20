---
layout: post
title: "UVa 1626. Brackets sequence"
date: 2020-06-12 10:17:14 +0800
tags: ACM/ICPC algorithm UVa DP
---

[Regionals 2001 :: Europe - Northeastern](https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=98&page=show_problem&problem=452)

[UVa 1626 Brackets sequences](https://vjudge.net/problem/UVA-1626/origin)

`d[i][j]`表示使`[i, j]`区间规范的需要添加括号的最小个数。`path[i][j]`用来记录状态路径。

动态规划的第一种动机：记忆化搜索。

第一种方法：记忆化搜索

{% highlight cpp %}
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int N = 100 + 10;
const int INF = 0x7fffffff;

int d[N][N];
int path[N][N];
bool mark[N][N];
string a;
char paren[129];

void print_result(int I, int J) {
  if (I == J) {
    if (a[I] == '(' || a[I] == ')') cout << "()";
    else cout << "[]";
    return;
  }
  if (I > J) return;

  if (d[I][J] == d[I+1][J-1] &&
      // WARN: bugs solve here!
      // wasted me a lot of time!
      ((a[I] == '(' && a[J] == ')') ||
       (a[I] == '[' && a[J] == ']'))
      ) {
    cout << a[I];
    print_result(I+1, J-1);
    cout << a[J];
  }
  else if ((a[I] == '(' || a[I] == '[')
	   &&  d[I][J] == d[I+1][J] + 1) {
    cout << a[I];
    print_result(I+1, J);
    cout << paren[int(a[I])];
  }
  else if ((a[J] == ')' || a[J] == ']')
	   && d[I][J] == d[I][J-1] + 1) {
    cout << paren[int(a[J])];
    print_result(I, J-1);
    cout << a[J];
  }
  else {
    int k = path[I][J];

    print_result(I, k-1);
    print_result(k, J);
  }
}

int brackets(int I, int J) {
  if (mark[I][J]) {
    return d[I][J];
  }

  if (I == J) {
    mark[I][J] = true;
    d[I][J] = 1;

    return d[I][J];
  }

  int ans = d[I][J];

  if (I > J) {
    d[I][J] = 0;
    return 0;
  }

  if ((a[I] == '(' && a[J] == ')') ||
      (a[I] == '[' && a[J] == ']'))
    ans = min(ans, brackets(I + 1, J - 1));

  if (a[I] == '(' || a[I] == '[')
    ans = min(ans, brackets(I + 1, J) + 1);

  if (a[J] == ')' || a[J] == ']')
    ans = min(ans, brackets(I, J - 1) + 1);

  int k;
  for (int i = I + 1; i <= J; i++) {
    int tmp;
    tmp = brackets(I, i - 1) + brackets(i, J);
    if (ans > tmp) {
      ans = tmp;
      k = i;
      path[I][J] = k;
    }
  }

  mark[I][J] = true;
  d[I][J] = ans;

  return ans;
}

int main() {

  #ifdef DEBUG
  freopen("brackets.in", "r", stdin);
  #endif

  // ios_base::sync_with_stdio(false);
  int n_case;
  cin >> n_case;
  cin.get();
  int first_line = 1;
  paren['('] = ')';
  paren[')'] = '(';
  paren['['] = ']';
  paren[']'] = '[';

  while (n_case--) {
    cin.get();
    getline(cin, a);
    int len;

    len = a.size();

    if (first_line == 1) first_line = 0;
    else cout << endl;

    if (len == 0) {
      cout << endl;
      continue;
    }

    for (int i = 0; i < len; i++)
      for (int j = 0; j < len; j++)
	{
	  if (i == j) {
	    d[i][j] = 1;
	    mark[i][j] = true;
	  }
	  else {
	    d[i][j] = INF;
	    mark[i][j] = false;
	  }
	  path[i][j] = 0;
	}

    brackets(0, len - 1);
    print_result(0, len - 1);
    cout << endl;
  }


  return 0;
}
{% endhighlight %}

第二种方法：自底向上的递推。

```cpp
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int N = 100 + 10;
const int INF = 0x7fffffff;

int d[N][N];
int path[N][N];
string a;

void print_res(int I, int J) {
  if (I == J) {
    if (a[I] == '(' || a[J] == ')') cout << "()";
    else cout << "[]";
    return;
  }
  if (I > J) return;
  if (((a[I] == '(' && a[J] == ')') ||
       (a[I] == '[' && a[J] == ']')) &&
      d[I][J] == d[I+1][J-1]) {
    cout << a[I];
    print_res(I + 1, J - 1);
    cout << a[J];
  }
  else {
    int k = path[I][J];
    print_res(I, k);
    print_res(k + 1, J);
  }
}

int main() {

#ifdef DEBUG
  freopen("brackets.in", "r", stdin);
#endif
  int n_case;
  cin >> n_case;
  cin.get();
  bool fst = true;

  while (n_case--) {
    cin.get();
    getline(cin, a);
    int len = a.size();

    if (fst) fst = false;
    else cout << endl;

    if (!len) {
      cout << endl;
      continue;
    }

    for (int i = 0; i < len; i++)
      for (int j = 0; j < len; j++)
        if (i < j)
          d[i][j] = INF - 1;
        else if (i == j)
          d[i][j] = 1;
        else
          d[i][j] = 0;

    for (int l = 1; l <= len - 1; l++) {
      for (int i = 0; i < len - l; i++) {
        int j = i + l;

        if ((a[i] == '(' && a[j] == ')') ||
            (a[i] == '[' && a[j] == ']')) {
          d[i][j] = min(d[i][j], d[i+1][j-1]);
        }

        for (int k = i; k < j; k++) {
          int tmp = d[i][k] + d[k+1][j];
          if (tmp < d[i][j]) {
            d[i][j] = tmp;
            path[i][j] = k;
          }
        }
      }
    }

    print_res(0, len - 1);
    cout << endl;
  }

  return 0;
}
```

[uva1626.cpp](/assets/src/uva1626.cpp)

有了状态转移方程，就很容易写出一个三重循环：
1. 按照一定的顺序计算每个状态
2. 计算每个状态的时候考虑不同的递推路径
3. 对每个状态进行状态转移

相关历年题库：[Northern Eurasia Map](https://neerc.ifmo.ru/subregions/index.html)
