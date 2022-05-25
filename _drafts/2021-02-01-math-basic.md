---
layout: post
title:  "数学模板"
date:   2021-02-01 13:19:15 +0800
categories: algorithm math
---

## 质数判定

`O(sqrt(n))`

```cpp
#include <cstdio>

bool is_prime(int n) {
  for (int i = 2; i <= n / i; ++i) {
    if (n % i == 0) return false;
  }
  return true;
}

int main() {
  int n = 100;
  for (int i = 2; i < n; ++i) {
    if (is_prime(i)) {
      printf("%d ", i);
    }
  }
  puts("");

  return 0;
}
```

## 筛法打素数表

`O(n * log(log(n)) )`

```cpp
#include <cstdio>

const int N = 1010;
int a[N];

int main() {
  int n = 100;
  for (int i = 2; i <= n; i++) {
    if (!a[i]) {
      printf("%d ", i);
      for (int j = i << 1; j <= n; j += i) {
	a[j] = 1;
      }
    }
  }
  puts("");
  
  return 0;
}
```

## 分解质因数

`O(n)`

```cpp
#include <cstdio>

void factor(int n) {
  for (int i = 2; i <= n; ++i) {
    int s = 0;
    while (n % i == 0) {
      ++s;
      n /= i;
    }
    if (s) {
      printf("%d^%d\n", i, s);
    }
  }
}

int main() {
  int n = 1880;
  factor(n);

  return 0;
}
```

方法二：

`O(sqrt(n))`

```cpp
#include <cstdio>

void factor(int n) {
  // n 中最多只包含一个大于 sqrt(n) 的质因子
  for (int i = 2; i <= n / i; ++i) {
    int s = 0;
    while (n % i == 0) {
      ++s;
      n /= i;
    }
    if (s) {
      printf("%d^%d\n", i, s);
    }
  }
  if (n > 1) {
    printf("%d^%d\n", n, 1);
  }
}

int main() {
  int n = 1880;
  factor(n);

  return 0;
}
```
