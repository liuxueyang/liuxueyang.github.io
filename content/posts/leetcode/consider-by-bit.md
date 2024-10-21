+++
title = '【题单】位运算——拆位法'
date = 2024-10-17T22:02:51+08:00
tags = [ "bitmasks" ]
categories = [ "LeetCode" ]
+++

[位运算题单](https://leetcode.cn/circle/discuss/dHn9Vk/)

1. [477. 汉明距离总和](https://leetcode.cn/problems/total-hamming-distance/)

先考虑两个数字的情况，按位考虑，如果二进制位不同，那么对答案的贡献是 1.
接下来考虑多个数字的情况，同样按位考虑，对于某一位来说，设 0 的个数是 $c_1$，1 的个数是 $c_2$，那么这一位对答案的贡献是 $c_1 \cdot c_2$

```cpp
  int totalHammingDistance(vector<int> &a) {
    int ans{};

    For1(i, 0, 30) {
      int c1{}, c2{};
      for (auto x : a) {
        if ((x >> i) & 1)
          c1++;
        else
          c2++;
      }

      ans += c1 * c2;
    }
    return ans;
  }
```

2. [1863. 找出所有子集的异或总和再求和](https://leetcode.cn/problems/sum-of-all-subset-xor-totals/)

因为数组长度只有 12，考虑暴力，枚举所有的子集，暴力计算每个子集的异或和。

```cpp
  int subsetXORSum(vector<int> &a) {
    int n{SZ(a)}, ans{};

    For(i, 0, (1 << n)) {
      int cur{};
      For(j, 0, n) {
        if ((i >> j) & 1) {
          cur ^= a[j];
        }
      }
      ans += cur;
    }
    return ans;
  }
```

题解区的神奇做法。
按位考虑，先考虑第 $i$ 位，如果一个集合中，第 $i$ 位是 1 的数字的个数是奇数，那么这个集合在第 $i$ 位对答案有贡献，并且贡献等于 $2^i$。

接下来考虑有多少个集合在第 $i$ 位对答案有贡献。也就是求有多少个集合，满足集合内的所有数字在第 $i$ 位是 1 的个数是奇数。设数组内所有数字在第 $i$ 位是 1 的个数是 $m$，那么包含至少一个 1 的集合的个数是 $2^m - 1$ 个。其中包含奇数个 1 的集合的个数是 $\sum{2^{n - m} {m \choose k}}$ 其中 $k$ 是奇数。根据二项式公式，能够得到当 $k$ 是奇数的二项式系数之和是 $2^{m - 1}$，因此上面的和是 $2^{n - 1}$.

因此只要第 $i$ 位包含至少一个 1，那么包含奇数个 1 的集合的个数是 $2^{n - 1}$. 因此这一位对答案的贡献是 $2^{n - 1} \cdot 2^i$

包含偶数个 1 的集合在第 $i$ 位对答案无贡献。
也就是只需要求每一位上，是否有一个元素在这一位上是 1，把贡献累加起来。

```cpp
  int subsetXORSum(vector<int> &a) {
    int n{SZ(a)}, cur{};

    for (auto x : a)
      cur |= x;
    return cur << (n - 1);
  }
```

3. [2425. 所有数对的异或和](https://leetcode.cn/problems/bitwise-xor-of-all-pairings/)

模拟过程中观察两个数组长度的奇偶性，发现答案和奇偶性有关，分类讨论即可。

```cpp
  int xorAllNums(vector<int> &a, vector<int> &b) {
    int n1{SZ(a)}, n2{SZ(b)}, ans{}, sum1{}, sum2{};

    for (auto x : a)
      sum1 ^= x;
    for (auto x : b)
      sum2 ^= x;

    if (n2 % 2 == 0) {
      if (n1 % 2 == 0)
        return 0;
      else
        return sum2;
    } else {
      ans = sum1;
      if (n1 % 2 == 0)
        return ans;
      else
        return ans ^ sum2;
    }
  }
```

题解区的好写法。
考虑对答案的贡献，如果数组 $b$ 的长度是奇数，那么数组 $a$ 的异或和对答案有贡献。
如果数组 $a$ 的长度是奇数，那么数组 $b$ 的异或和对答案有贡献。

```cpp
  int xorAllNums(vector<int> &a, vector<int> &b) {
    int ans{}, n1{SZ(a)}, n2{SZ(b)};

    if (n1 & 1) {
      for (auto x : b)
        ans ^= x;
    }
    if (n2 & 1) {
      for (auto x : a)
        ans ^= x;
    }
    return ans;
  }
```

4. [2275. 按位与结果大于零的最长组合](https://leetcode.cn/problems/largest-combination-with-bitwise-and-greater-than-zero/)

只要求按位与大于 0，那么考虑贪心，只需要考虑有一位等于 1 即可，也就是要求这些数字的第 $i$ 位全部是 1，那么不妨统计每一位为 1 的数字的个数，把这些数字放在一起。

```cpp
  int largestCombination(vector<int> &a) {
    int ans{};

    For(i, 0, 31) {
      int cnt{};
      for (auto x : a) {
        if ((x >> i) & 1)
          cnt++;
      }
      ckmax(ans, cnt);
    }

    return ans;
  }
```

5. [1835. 所有数对按位与结果的异或和](https://leetcode.cn/problems/find-xor-sum-of-all-pairs-bitwise-and/)

按位考虑，对于第 $i$ 位，先让 $a_1$ 中的第 $i$ 位和 $b_j$ 的第 $i$ 位进行按位与，得到结果之后进行按位异或。最后的异或结果只取决于 $a_1$ 与多少个 $b_j$ 按位与之后，得到的结果是 1. 如果个数是奇数，那么 $a_1$ 在第 $i$ 位对答案的贡献是 1。

推广到所有的 $a_i$，也就是求数组 $a$ 中第 $i$ 位是 1 的个数 $c_1$ 与数组 $b$ 中第 $i$ 位是 1 的个数 $c_2$，它们会两两相与，然后异或，如果 $c_1 \cdot c_2$ 是奇数，那么这一位对答案有贡献。

如果 $c_1 \cdot c_2$ 是奇数，这要求这两个数字都是奇数。也就是要求数组 $a$ 中第 $i$ 位是 1 的个数是奇数。这可以异或和得到。

最后的答案要求对于第 $i$ 位，$c_1 \cdot c_2$ 是奇数，也就是要求两个数组的异或和的第 $i$ 位同时是 1，只需要把 $sum_1, sum_2$ 进行按位与。

```cpp
  int getXORSum(vector<int> &a, vector<int> &b) {
    int sum1{}, sum2{};

    for (auto x : a)
      sum1 ^= x;
    for (auto x : b)
      sum2 ^= x;
    return sum1 & sum2;
  }
```
