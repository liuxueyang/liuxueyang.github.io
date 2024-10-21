+++
title = '【题单】对顶堆'
date = 2024-10-19T22:03:46+08:00
tags = [ "heap" ]
categories = [ "LeetCode" ]
+++

[数据结构题单](https://leetcode.cn/circle/discuss/mOr1u6/)

1. [2102. 序列顺序查询](https://leetcode.cn/problems/sequentially-ordinal-rank-tracker/)

维护一个小顶堆 `q1`，代表前 `k` 大的元素。
维护一个大顶堆 `q2`，代表其它元素。

当新加一个元素的时候，首先加入 `q2`，当 `q1` 中不足 `k` 个元素的时候，把 `q2` 的最大元素移动到 `q1`。如果 `q1` 的堆顶小于 `q2` 的堆顶，此时应该交换堆顶，这个交换操作在一次函数调用中最多会发生一次，因为新加入元素的时候，只会产生一个元素的变化。

另外需要注意自定义对象的比较函数的时候，因为是求第 `k` 大，并且字典序最小，应该让分数正序排序，名字逆序排序，这样当分数相同的时候，靠后的是字典序更小的。

```cpp
class SORTracker {
public:
  struct node {
    int val;
    string name;

    bool operator<(const node &rh) const {
      if (val != rh.val)
        return val < rh.val;
      return name > rh.name;
    }

    bool operator>(const node &rh) const {
      if (val != rh.val)
        return val > rh.val;
      return name < rh.name;
    }
  };

  pqg<node> q1;
  pq<node> q2;
  int cur;

  SORTracker() : q1{}, q2{}, cur{1} {}

  void add(string name, int score) {
    node tmp = {score, name};
    q2.push(tmp);

    while (SZ(q1) < cur && nemp(q2)) {
      q1.push(q2.top());
      q2.pop();
    }

    while (nemp(q1) && nemp(q2) && q1.top() < q2.top()) {
      auto t1 = q1.top();
      q1.pop();

      auto t2 = q2.top();
      q2.pop();

      q1.push(t2);
      q2.push(t1);
    }
  }

  string get() {
    while (SZ(q1) < cur && nemp(q2)) {
      auto t = q2.top();
      q1.push(t);
      q2.pop();
    }

    cur++;
    return q1.top().name;
  }
};
```

题解区的神奇思路。

注意到询问的第 `k` 大比较特殊，它是连续的，并且只在询问的时候才会递增。考虑使用 `set` 维护，因为询问的是第 `k` 大，应该使用 `reverse_iterator`，询问的时候直接返回 `it` 指向的值。

插入的时候需要注意，如果插入的值比 `it` 指向的值大，此时应该让 `it` 递减，保证它指向的还是第 `k` 大的值。

为了保证 `set` 中的顺序正确，需要对结构体自定义小于运算符，首先按照分数排序，如果分数相同，那么按照名字递减排序。这样可以保证当分数相同的时候，`set` 中较后面的值的字典序最小。

另外一个技巧是，在最开始的时候，`set` 是空的，为了让迭代器有效，先插入一个非法的哨兵元素即可，只需要保证它不和其它元素产生冲突。

```cpp
class SORTracker {
public:
  struct node {
    int val;
    string name;

    bool operator<(const node &rh) const {
      if (val != rh.val)
        return val < rh.val;
      return name > rh.name;
    }
  };

  set<node> s;
  set<node>::reverse_iterator it;
  SORTracker() {
    s = {};
    s.insert({-INF, "no"});
    it = s.rbegin();
  }

  void add(string name, int score) {
    auto tmp = node{score, name};
    s.insert(tmp);

    if (*it < tmp)
      it--;
  }

  string get() {
    auto res = it->name;
    it++;
    return res;
  }
};
```

题解区另外一个有趣的做法。
小顶堆 `q1` 保存前 `k - 1` 个数字。
大顶堆 `q2` 保存其它数字。

当新加入元素 $x$ 时，先把 $x$ 加入 `q1` 中，因为此时没有询问，此时应该保证 `q1` 的大小不变，并且此时 `q1` 的堆顶元素不一定是第 `k` 大的元素（因为此时 `q2` 的堆顶可能比 `q1` 大），此时把 `q1` 堆顶元素移除，并且放到 `q2` 中。

当询问第 `k` 大的时候，`q1` 中保证了保存的是前 `k - 1` 大的元素，那么 `q2` 的堆顶元素一定是第 `k` 大的元素，把它从 `q2` 移除，放到 `q1` 中。

```cpp
class SORTracker {
public:
  struct node {
    int val;
    string name;

    bool operator<(const node &rh) const {
      if (val != rh.val)
        return val < rh.val;
      return name > rh.name;
    }

    bool operator>(const node &rh) const {
      if (val != rh.val)
        return val > rh.val;
      else
        return name < rh.name;
    }
  };

  pqg<node> q1;
  pq<node> q2;

  SORTracker() : q1{}, q2{} {}

  void add(string name, int score) {
    auto t = node{score, name};
    q1.push(t);

    q2.push(q1.top());
    q1.pop();
  }

  string get() {
    auto t = q2.top();
    q2.pop();
    q1.push(t);

    return t.name;
  }
};
```

2. [295. 数据流的中位数](https://leetcode.cn/problems/find-median-from-data-stream/)

使用两个堆：`q1` 是大顶堆，保存前 `k` 个数字。`q2` 是小顶堆，保存后 `k + 1` 或 `k` 个数字。其中 $k = \frac{len}{2}$，保证 $q2.top() \ge q1.top()$

对于新加入的数字，首先加入到 `q2` 中，如果两个堆的大小差值超过了 1，那么把 `q2` 堆顶的元素移动到 `q1`. 然后检查两个堆顶元素是否满足上面的不等式，如果不满足，交换两个堆顶。

对于询问，如果总个数是偶数，那么中位数是两个堆顶的平均值。否则是 `q2` 的堆顶。

因为每次操作只加入一个数字，这保证了只需要交换一次堆顶就能满足上面的性质。

```cpp
class MedianFinder {
public:
  pq<int> q1;
  pqg<int> q2;

  MedianFinder() : q1{}, q2{} {}

  void addNum(int x) {
    q2.push(x);

    if (SZ(q2) - SZ(q1) > 1) {
      q1.push(q2.top());
      q2.pop();
    }

    if (nemp(q1) && nemp(q2) && q1.top() > q2.top()) {
      int v1 = q1.top(), v2 = q2.top();
      q1.pop(), q2.pop();
      q1.push(v2), q2.push(v1);
    }
  }

  double findMedian() {
    int cnt = SZ(q1) + SZ(q2);

    if (cnt & 1)
      return q2.top();
    else
      return (1.0 * q1.top() + q2.top()) / 2;
  }
};
```

3. [480. 滑动窗口中位数](https://leetcode.cn/problems/sliding-window-median/)

数组中可以包含重复的数字，并且需要在对顶堆中加入数字，删除数字。使用 `priority_queue` 不能实现删除给定数字。因此考虑使用 `multiset`。

具体维护对顶堆的思路和 295 完全一样。
只需要额外加一个滑动窗口就可以，这个是定长的滑动窗口，参考 [[LeetCode 定长滑动窗口]]，先创建一个长度为 `k - 1` 的窗口，然后加入右端点，维护答案，最后把左端点移出窗口。

因为窗口定长，只需要维护右端点，根据长度计算左端点即可。

> 在 `multiset` 中插入元素之后，在插入之前创建的迭代器依然是有效的。

```cpp
  vector<double> medianSlidingWindow(vector<int> &a, int k) {
    multiset<int> q1, q2;
    vector<double> ans;
    int n{SZ(a)};

    For(j, 0, n) {
      q2.insert(a[j]);

      if (SZ(q2) - SZ(q1) > 1) {
        auto it2 = q2.begin();
        q1.insert(*it2);
        q2.erase(it2);
      }

      if (nemp(q2) && nemp(q1) && *q1.rbegin() > *q2.begin()) {
        auto it2 = q2.begin();
        auto it1 = prev(q1.end());

        q2.insert(*it1);
        q1.insert(*it2);

        q2.erase(it2);
        q1.erase(it1);
      }

      if (j < k - 1)
        continue;

      int cnt = SZ(q1) + SZ(q2);
      if (cnt & 1)
        ans.pb(*q2.begin());
      else
        ans.pb((1.0 * *q2.begin() + *q1.rbegin()) / 2);

      int x = a[j - k + 1];
      if (has(q1, x)) {
        auto it = q1.find(x);
        q1.erase(it);
      } else {
        auto it = q2.find(x);
        q2.erase(it);
      }
    }
    return ans;
  }
```

4. [703. 数据流中的第 K 大元素](https://leetcode.cn/problems/kth-largest-element-in-a-stream/)

找第 `k` 大的元素，只需要维护一个大小是 `k` 的小顶堆。

不需要使用对顶堆，不知道为什么这道题在这个题单里面。

```cpp
  int k;
  pqg<int> q;

  KthLargest(int k_, vector<int> &a) : k{k_}, q{} {
    for (auto x : a) {
      add(x);
    }
  }

  int add(int val) {
    int cnt = {SZ(q)};

    if (cnt < k)
      q.push(val);
    else if (val > q.top()) {
      q.pop();
      q.push(val);
    }

    return q.top();
  }
```

求第 `k` 大或者第 `k` 小的另外一个经典做法是『快速选择』。
