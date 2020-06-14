---
layout: post
title: "ACM Notheastern European Regional Programming Contest Problem B"
date: 2020-06-12 10:17:14 +0800
tags: ACM/ICPC algorithm UVa
---

[Regionals 2001 :: Europe - Northeastern](https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=98&page=show_problem&problem=452)

[UVa 1626 Brackets sequences](https://vjudge.net/problem/UVA-1626/origin)

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

相关历年题库：[Northern Eurasia Map](https://neerc.ifmo.ru/subregions/index.html)
