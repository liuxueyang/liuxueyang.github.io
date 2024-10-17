+++
title = '不定长滑动窗口——求最长或最大 题单'
date = 2024-10-17T21:10:17+08:00
tags = [ "two pointers" ]
categories = [ "LeetCode" ]
+++

1. [3. 无重复字符的最长子串](https://leetcode.cn/problems/longest-substring-without-repeating-characters/)

维护一个不定长的滑动窗口：
- 加入右端点
- 当不满足条件的时候不断移动左端点
- 维护答案

```cpp
  int lengthOfLongestSubstring(string s) {
    int ans{}, n = SZ(s);
    map<char, int> m;

    for (int i = 0, j = 0; i < n; ++i) {
      m[s[i]]++;
      while (m[s[i]] > 1 && j < i) m[s[j++]]--;
      ckmax(ans, i - j + 1);
    }

    return ans;
  }
```

题解区的另外一种写法。
- 当右端点在窗口中已经存在的时候，不断移动左指针，直到窗口中不存在右端点。
- 插入右端点
- 维护答案

```cpp
  int lengthOfLongestSubstring(string s) {
    int ans{}, n = SZ(s);
    set<char> vis;

    for (int i = 0, j = 0; i < n; ++i) {
      while (has(vis, s[i])) {
        vis.erase(s[j++]);
      }
      vis.insert(s[i]);
      ckmax(ans, i - j + 1);
    }

    return ans;
  }
```

2. [3090. 每个字符最多出现两次的最长子字符串](https://leetcode.cn/problems/maximum-length-substring-with-two-occurrences/)

- 当窗口中的右端点对应的字符出现了至少两次的时候，移动左指针，直到它出现小于两次
- 加入右端点
- 维护答案

```cpp
  int maximumLengthSubstring(string s) {
    VI a(26);
    int n{SZ(s)}, ans{};

    for (int i = 0, j = 0; i < n; ++i) {
      while (a[s[i] - 'a'] >= 2) {
        a[s[j++] - 'a']--;
      }
      a[s[i] - 'a']++;
      ckmax(ans, i - j + 1);
    }

    return ans;
  }
```

3. [1493. 删掉一个元素以后全为 1 的最长子数组](https://leetcode.cn/problems/longest-subarray-of-1s-after-deleting-one-element/)

维护一个滑动窗口，满足窗口内部的 0 的个数最多有 1 个，求窗口内部去掉 1 个数字之后的连续的 1 的个数。

```cpp
  int longestSubarray(vector<int> &nums) {
    int n{SZ(nums)}, ans{}, cnt0{};

    for (int i = 0, j = 0; i < n; ++i) {
      if (nums[i] == 0) {
        while (cnt0) {
          if (nums[j] == 0) {
            cnt0--;
          }
          ++j;
        }
        cnt0++;
      }
      ckmax(ans, i - j);
    }

    return ans;
  }
```

4. [1208. 尽可能使字符串相等](https://leetcode.cn/problems/get-equal-substrings-within-budget/)

先预处理出每个位置的变更代价。

维护一个滑动窗口，使得窗口内部的代价和不超过给定值。求窗口的最大长度。

```cpp
  int equalSubstring(string s, string t, int maxCost) {
    int n{SZ(s)}, ans{}, cur{};
    VI a(n);

    For(i, 0, n) { a[i] = abs(s[i] - t[i]); }

    for (int i = 0, j = 0; i < n; ++i) {
      while (cur + a[i] > maxCost) {
        cur -= a[j++];
      }
      cur += a[i];
      ckmax(ans, i - j + 1);
    }

    return ans;
  }
```

5. [2730. 找到最长的半重复子字符串](https://leetcode.cn/problems/find-the-longest-semi-repetitive-substring/)

维护一个滑动窗口，要求窗口内部相邻字符相等的数对最多有一对，求窗口的最大长度。处理好窗口为空的情况即可。

```cpp
  int longestSemiRepetitiveSubstring(string s) {
    int n{SZ(s)}, ans{}, cnt{};

    for (int i = 0, j = 0; i < n; ++i) {
      if (i - 1 >= j) {
        if (s[i] == s[i - 1]) {
          while (cnt) {
            if (s[j] == s[j + 1]) cnt--;
            ++j;
          }
          cnt++;
        }
      }
      ckmax(ans, i - j + 1);
    }

    return ans;
  }
```

6. [904. 水果成篮](https://leetcode.cn/problems/fruit-into-baskets/)

维护一个滑动窗口，要求窗口内部不同数字的个数最多有 2 个，求窗口的最大长度。

```cpp
  int totalFruit(vector<int> &fruits) {
    int n{SZ(fruits)}, ans{};
    map<int, int> vis;

    for (int i = 0, j = 0; i < n; ++i) {
      while (SZ(vis) >= 2 && !has(vis, fruits[i])) {
        int &cnt = vis[fruits[j]];
        if (cnt == 1)
          vis.erase(fruits[j]);
        else
          cnt--;

        ++j;
      }
      vis[fruits[i]]++;
      ckmax(ans, i - j + 1);
    }

    return ans;
  }
```

7. [1695. 删除子数组的最大得分](https://leetcode.cn/problems/maximum-erasure-value/)

维护一个滑动窗口，要求窗口内部的所有数字都不相同，求窗口内部数字的最大和。
因为每个时刻窗口内部的数字都不同，因此使用 `set` 即可。

如果题目要求某个数字出现次数不超过多少次，此时需要使用 `map` 维护。

```cpp
  int maximumUniqueSubarray(vector<int> &nums) {
    int ans{}, n{SZ(nums)}, cur{};
    set<int> vis;

    for (int i = 0, j = 0; i < n; ++i) {
      while (has(vis, nums[i])) {
        cur -= nums[j];
        vis.erase(nums[j++]);
      }
      cur += nums[i];
      vis.insert(nums[i]);
      ckmax(ans, cur);
    }

    return ans;
  }
```

8. [2958. 最多 K 个重复元素的最长子数组](https://leetcode.cn/problems/length-of-longest-subarray-with-at-most-k-frequency/)

这道题目和 1695 几乎一样，只需要使用 `map` 维护每个数字出现的次数即可。

```cpp
  int maxSubarrayLength(vector<int> &nums, int k) {
    int n{SZ(nums)}, ans{};
    map<int, int> vis;

    for (int i = 0, j = 0; i < n; ++i) {
      while (has(vis, nums[i]) && vis[nums[i]] >= k) {
        vis[nums[j++]]--;
      }
      vis[nums[i]]++;
      ckmax(ans, i - j + 1);
    }

    return ans;
  }
```

9. [2779. 数组的最大美丽值](https://leetcode.cn/problems/maximum-beauty-of-an-array-after-applying-operation/)

要求的是子序列，不要求连续。
可以执行任意次操作，并且没有代价，要求操作之后子序列中的元素完全相等，这意味着操作之后子序列中元素的顺序可以任意交换，也就是说操作之前可以任意交换顺序。

因此想到把数组排序，求一段连续的子数组，要求子数组内部的数字操作之后的数字完全相等，求子数组的最大长度。

观察到这和子数组的左端点的值有关。设左端点的值是 `x`，那么要求子数组右端点值 `y` 满足条件：区间 `[x - k, x + k]` 与 `[y - k, y + k]` 的区间不为空，并且 $x \le y$。维护一个滑动窗口，维护这个条件即可，求出窗口的最大长度。上面的条件可以转化成 $y - k \le x + k$

```cpp
  int maximumBeauty(vector<int> &nums, int k) {
    int n{SZ(nums)}, ans{};

    sort(all(nums));

    for (int i = 0, j = 0; i < n; ++i) {
      if (i - 1 >= j) {
        while (!(nums[i] - k <= nums[j] + k)) ++j;
      }
      ckmax(ans, i - j + 1);
    }

    return ans;
  }
```

可以去掉检查窗口非空的判断，因为窗口为空时，`while` 中的条件一定不满足，此时左端点一定不移动。

```cpp
  int maximumBeauty(vector<int> &nums, int k) {
    int n{SZ(nums)}, ans{};

    sort(all(nums));

    for (int i = 0, j = 0; i < n; ++i) {
      while (!(nums[i] - k <= nums[j] + k)) ++j;
      ckmax(ans, i - j + 1);
    }

    return ans;
  }
```

10. [2024. 考试的最大困扰度](https://leetcode.cn/problems/maximize-the-confusion-of-an-exam/)

维护一个滑动窗口，要求窗口内部的字符相等，在代价不超过 `k` 的情况下，求窗口长度的最大值。

可以把窗口内部的字符全部变成 `F` 或者 `T`，因此可以对这两个字符分别做两遍。

```cpp
  int maxConsecutiveAnswers(string answerKey, int k) {
    int n{SZ(answerKey)}, ans{}, cnt{};

    for (int i = 0, j = 0; i < n; ++i) {
      if (answerKey[i] == 'T') {
        while (cnt >= k) {
          if (answerKey[j] == 'T') cnt--;
          ++j;
        }
        cnt++;
      }
      ckmax(ans, i - j + 1);
    }

    cnt = 0;
    for (int i = 0, j = 0; i < n; ++i) {
      if (answerKey[i] == 'F') {
        while (cnt >= k) {
          if (answerKey[j] == 'F') cnt--;
          ++j;
        }
        cnt++;
      }
      ckmax(ans, i - j + 1);
    }

    return ans;
  }
```

题解区的有趣做法，只需要做一遍。
上面每一遍的做法中，其实是求窗口中不超过 `k` 个 `T` 或者 `k` 个 `F` 的最大窗口长度。这两个条件可以合并为一个条件来维护窗口。

一个无聊的技巧：观察 `T` 和 `F` 的 ASCII 值，发现它们除以 2 之后的奇偶性不同，因此可以根据这一点来统计两个字母的个数。

涉及到两个字母的统计，条件判断中也包含对它们的判断，因此先加入右端点处理更方便，减少了一些条件判断。

```cpp
  int maxConsecutiveAnswers(string answerKey, int k) {
    int n{SZ(answerKey)}, ans{};
    VI cnt(2);

    for (int i = 0, j = 0; i < n; ++i) {
      cnt[(answerKey[i] / 2) & 1]++;

      while (cnt[0] > k && cnt[1] > k) {
        int idx = answerKey[j] / 2;
        cnt[idx & 1]--;
        ++j;
      }

      ckmax(ans, i - j + 1);
    }

    return ans;
  }
```

11. [1004. 最大连续 1 的个数 III](https://leetcode.cn/problems/max-consecutive-ones-iii/)

维护滑动窗口中 0 的个数不超过 `k` 的最大窗口长度。

同样地，先加入右端点比较自然，处理更方便。

先加入右端点还是先维护窗口，根据具体情况分析，哪种方便写哪种。

```cpp
  int longestOnes(vector<int> &nums, int k) {
    int n{SZ(nums)}, ans{}, cnt{};

    for (int i = 0, j = 0; i < n; ++i) {
      if (!nums[i]) cnt++;
      while (cnt > k) {
        if (nums[j] == 0) --cnt;
        ++j;
      }
      ckmax(ans, i - j + 1);
    }

    return ans;
  }
```

12. [1658. 将 x 减到 0 的最小操作数](https://leetcode.cn/problems/minimum-operations-to-reduce-x-to-zero/)

感觉常规和直接的做法是使用前缀和。

使用滑动窗口也是可以做的，维护一个滑动窗口，要求窗口内部的数字和恰好等于 `x`，并且可以把数组的前缀和后缀连起来，常规技巧是把数组加倍。

窗口长度不固定，因此要求窗口内部必须包含原来数组的第一个元素或者最后一个元素，同时窗口的长度不超过原数组的长度。

```cpp
  int minOperations(vector<int> &nums, int x) {
    int n = SZ(nums), ans{INF}, cur{}, n1{2 * n};
    VI a(n1);

    For(i, 0, n) { a[i] = a[i + n] = nums[i]; }

    for (int i = 0, j = 0; i < n1; ++i) {
      cur += a[i];
      while (cur > x) {
        cur -= a[j++];
      }
      if (cur == x && (i - j + 1 <= n) &&
          ((j <= 0 && 0 <= i) || (j <= n - 1 && n - 1 <= i)))
        ckmin(ans, i - j + 1);
    }

    if (ans == INF) return -1;
    return ans;
  }
```

题解区的好做法。
像这种只能取前缀和后缀的题目，可以考虑反着做：观察剩余元素的性质，在剩余元素上做。这道题目转化成了求剩余元素中，连续子数组和等于给定值的最大子数组的长度。

> 在剩余元素上求时，需要注意边界情况：要求的窗口长度可能是 0

```cpp
  int minOperations(vector<int> &nums, int x) {
    int sum{}, ans{-INF}, n{SZ(nums)}, cur{};

    for (auto &x : nums) sum += x;

    sum -= x;
    if (!sum) return n;

    for (int i = 0, j = 0; i < n; ++i) {
      while (cur + nums[i] > sum && j < i) {
        cur -= nums[j++];
      }
      cur += nums[i];
      if (cur == sum) ckmax(ans, i - j + 1);
    }

    if (ans == -INF) return -1;
    return n - ans;
  }
```

13. [1838. 最高频元素的频数](https://leetcode.cn/problems/frequency-of-the-most-frequent-element/)

求出现次数最多的元素的出现次数，这和顺序是无关的，因此先把数组排序，显然在连续的一段数组上做操作的代价最小。

维护一个滑动窗口，要求窗口内部的操作次数不能超过 `k`，求窗口的最大长度。

求窗口内部的操作次数可以使用前缀和。

```cpp
  int maxFrequency(vector<int> &nums, int k) {
    int n{SZ(nums)}, ans{};

    sort(all(nums));
    vector<ll> a(n + 1), b(n + 1);

    For(i, 0, n) {
      a[i + 1] = nums[i] + a[i];
      b[i + 1] = nums[i];
    }

    for (int i = 1, j = 1; i <= n; ++i) {
      while (b[i] * (i - j) - (a[i - 1] - a[j - 1]) > k) {
        ++j;
      }
      ckmax(ans, i - j + 1);
    }
    return ans;
  }
```

14. [2516. 每种字符至少取 K 个](https://leetcode.cn/problems/take-k-of-each-character-from-left-and-right/)

只能从前缀和后缀取，考虑剩下的元素。

先考虑一个字符，要求取走的数量 $p_1 \ge k$，设这个字符的总数量是 $t_1$，那么这个字符剩余的数量 $r_1 = t_1 - p_1$，可以得到 $r_1 \le t_1 - k$

因此问题转化成了，维护一个滑动窗口，要求窗口内部每个字符的出现次数不超过给定数字。这是一个经典的滑动窗口问题。

注意判断特殊情况：字符剩余个数小于 0，直接返回 -1。如果全为 0，意味着要求的滑动窗口为空，也直接返回数组长度。

```cpp
  int takeCharacters(string s, int k) {
    int n{SZ(s)}, ans{};
    VI cnt(3);

    for (auto c : s) cnt[c - 'a']++;

    bool ok{true};
    for (auto &c : cnt) {
      c -= k;
      if (c < 0) return -1;
      if (c) ok = false;
    }
    if (ok) return n;

    VI cnt1(3);
    for (int i = 0, j = 0; i < n; ++i) {
      cnt1[s[i] - 'a']++;
      while (cnt1[0] > cnt[0] || cnt1[1] > cnt[1] || cnt1[2] > cnt[2]) {
        cnt1[s[j++] - 'a']--;
      }
      ckmax(ans, i - j + 1);
    }

    return n - ans;
  }
```

因为对每个字符的出现次数有不同的要求 ，此时先维护窗口，再加入右端点比较好处理，因为只有右端点的字符的出现次数会发生改变。因此可以简化滑动窗口的维护条件。

```cpp
  int takeCharacters(string s, int k) {
    int n{SZ(s)}, ans{};
    VI cnt(3), cnt1(3);

    for (auto c : s) cnt[c - 'a']++;

    bool ok{true};
    for (auto &c : cnt) {
      c -= k;
      if (c < 0) return -1;
      if (c) ok = false;
    }
    if (ok) return n;

    for (int i = 0, j = 0; i < n; ++i) {
      int idx = s[i] - 'a';
      while (cnt1[idx] + 1 > cnt[idx]) {
        cnt1[s[j++] - 'a']--;
      }
      cnt1[idx]++;
      ckmax(ans, i - j + 1);
    }

    return n - ans;
  }
```

15. [2831. 找出最长等值子数组](https://leetcode.cn/problems/find-the-longest-equal-subarray/)

要求子数组中的元素相等，好像类似要求元素相等的题目都和元素的位置关系不大，因为最终答案子数组的元素一定相等，因此考虑先把数组排序。

维护一个滑动窗口，要求滑动窗口内部的元素都相等，并且把这些相等元素聚在一起的代价不超过 `k`，而这个代价是好求的，只需要记录这些相等元素原来的位置，它们的位置间隔的和就是代价。求窗口的最大长度即可。

当窗口中的代价超过 `k` 或者左端点的值和右端点的值不相等的时候，移动左端点。

`i - 1 >= j` 表示当窗口的大小非空（长度大于等于 1）的时候，才移动左端点。
加入右端点之后，如果窗口长度大于 1，那么累加代价。否则代价清空。

```cpp
  int longestEqualSubarray(vector<int> &nums, int k) {
    int n{SZ(nums)}, ans{}, cur{};
    vector<PII> a(n);

    For(i, 0, n) { a[i] = {nums[i], i}; }
    sort(all(a));

    auto cost = [&](int i, int j) { return a[i].f2 - a[j].f2 - 1; };

    for (int i = 0, j = 0; i < n; ++i) {
      if (i - 1 >= j) {
        while (cur + cost(i, i - 1) > k || a[i].f1 != a[j].f1) {
          cur -= cost(j + 1, j);
          ++j;
        }
      }

      if (i > j) {
        cur += cost(i, i - 1);
      } else
        cur = 0;

      ckmax(ans, i - j + 1);
    }

    return ans;
  }
```
