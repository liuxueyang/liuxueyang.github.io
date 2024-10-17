+++
title = '【题单】链表快慢指针'
date = 2024-10-17T19:53:49+08:00
tags = [ "linked list" ]
categories = [ "LeetCode" ]
draft = true
+++

1. [876. 链表的中间结点](https://leetcode.cn/problems/middle-of-the-linked-list/)

神奇的技巧。

使用两个指针 p1, p2，p1 每次移动一步，p2 每次移动 2 步，直到 p2 或者 p2->next 是空。

最终状态是当链表长度是奇数的时候，p1 指向中间节点，p2 为空。
当链表长度是偶数的时候，p1 指向第 $\frac{len}{2}$ 个节点，p2->next 为空。此时按照题意应该返回 p1 的下一个节点。

```cpp
  ListNode *middleNode(ListNode *head) {
    LNP ro = new LN(0, head);
    LNP p1{ro};
    LNP p2{ro};

    while (p2 && p2->next) {
      p1 = p1->next;
      p2 = p2->next->next;
    }

    LNP res{p1};
    if (p2)
      res = res->next;

    delete ro;
    return res;
  }
```

其实这道题目不需要使用额外的头结点，实现更优雅：

```cpp
  ListNode *middleNode(ListNode *head) {
    LNP p1{head};
    LNP p2{head};

    while (p2 && p2->next) {
      p1 = p1->next;
      p2 = p2->next->next;
    }

    return p1;
  }
```

2. [2095. 删除链表的中间节点](https://leetcode.cn/problems/delete-the-middle-node-of-a-linked-list/)

这道题目和 876 几乎完全一样。只需要找到的中间节点的上一个节点，只需要对 876 的做法做一点修改。

当链表长度是偶数的时候，876 的做法可行。

当链表长度是奇数的时候，我们需要让 p1 少前进一步，因为最终的 p2 为空，因此考虑让 p2 后退一个单位长度，也等价于让 p2 少走一步，因此起始的时候，先让 p2 抢先一个单位长度，最终 p2 指向链表最后一个节点，最终走的步数恰好少了一步，此时 p1 的位置也恰好少走了一步。

如果 p2 抢先一个单位长度，当链表长度是偶数的时候，p2 为空，此时 p2 走的步数并不变。因此也满足题意。

```cpp
  ListNode *deleteMiddle(ListNode *head) {
    LNP ro = new LN(0, head);
    LNP p1{ro};
    LNP p2{ro->next};

    while (p2 && p2->next) {
      p1 = p1->next;
      p2 = p2->next->next;
    }

    LNP p3 = p1->next;
    p1->next = p3->next;
    delete p3;

    LNP res{ro->next};
    delete ro;
    return res;
  }
```

另外一种写法是，在 876 的第二种方法的基础上，记录 p1 的上一个节点即可。

```cpp
  ListNode *deleteMiddle(ListNode *head) {
    LNP ro = new LN(0, head);
    LNP p1{head};
    LNP p2{head};
    LNP p3{ro};

    while (p2 && p2->next) {
      p3 = p1;
      p1 = p1->next;
      p2 = p2->next->next;
    }

    p3->next = p1->next;
    delete p1;

    LNP res = ro->next;
    delete ro;

    return res;
  }
```

3. [234. 回文链表](https://leetcode.cn/problems/palindrome-linked-list/)

先找到链表的中间节点，然后把右半段链表反转，比较前后两个链表是否相等。

找链表中点可以使用快慢指针的技巧，也可以先找到链表长度。

```cpp
  int get_length(LNP head) {
    int ans{};
    while (head) {
      head = head->next;
      ans++;
    }
    return ans;
  }

  LNP reverse_list(LNP head) {
    if (!head)
      return head;

    LNP p1{};
    LNP p2{head};
    LNP p3{};

    while (p2) {
      p3 = p2->next;
      p2->next = p1;
      p1 = p2;
      p2 = p3;
    }

    return p1;
  }

  bool check(LNP l, LNP r, int len) {
    if (!len)
      return true;
    while (len--) {
      if (l->val != r->val)
        return false;
      l = l->next, r = r->next;
    }
    return true;
  }

  bool isPalindrome(ListNode *head) {
    int n = get_length(head);
    LNP ro{new LN(0, head)};

    int mid{};

    if (n & 1) {
      mid = (n + 1) / 2;
    } else {
      mid = n / 2;
    }

    LNP p1{ro};
    int cnt{mid};

    while (cnt--)
      p1 = p1->next;

    LNP right = reverse_list(p1->next);

    auto res = check(right, ro->next, n / 2);
    p1->next = reverse_list(right);

    return res;
  }
```

4. [2130. 链表最大孪生和](https://leetcode.cn/problems/maximum-twin-sum-of-a-linked-list/)

链表长度规定是偶数，处理就变得简单了。先使用快慢指针找到链表的终点，然后把链表的前半部分反转。同时遍历左右两个链表找到答案。最终把前半部分链表还原。

```cpp
  LNP reverse_list(LNP head) {
    LNP p1{};
    LNP p2{head};

    while (p2) {
      LNP p3 = p2->next;
      p2->next = p1;
      p1 = p2;
      p2 = p3;
    }
    return p1;
  }

  int pairSum(ListNode *head) {
    LNP ro{new LN(0, head)};
    LNP p1{ro};
    LNP p2{ro};

    while (p2 && p2->next) {
      p1 = p1->next;
      p2 = p2->next->next;
    }

    LNP right = p1->next;

    p1->next = NULL;

    LNP left = reverse_list(head);

    int ans{};
    while (left) {
      int tmp = left->val + right->val;
      ckmax(ans, tmp);
      left = left->next, right = right->next;
    }

    head = reverse_list(left);
    p1->next = right;

    delete ro;
    return ans;
  }
```

5. [143. 重排链表](https://leetcode.cn/problems/reorder-list/)

先使用快慢指针找到链表的中点，把链表的后半段反转，然后合并两个链表。注意合并之前把两个链表的最后一个节点的 next 设置成空（**进行链表反转或者合并的时候，尽量把链表做成规范形式：链表的最后一个节点的 next 为空。这样可以减少很多 Bug**）。最后根据奇偶性判定是否要加入中间的节点。

```cpp
  LNP reverse_list(LNP head) {
    if (!head)
      return head;

    LNP p1{};
    LNP p2{head};

    while (p2) {
      LNP p3 = p2->next;
      p2->next = p1;
      p1 = p2;
      p2 = p3;
    }

    return p1;
  }

  void reorderList(ListNode *head) {
    LNP ro{new LN(0, head)};
    LNP p1{ro};
    LNP p2{ro};

    while (p2 && p2->next) {
      p1 = p1->next;
      p2 = p2->next->next;
    }

    bool odd = (p2 == NULL);

    LNP right = reverse_list(p1->next);
    p1->next = NULL;

    p2 = head;
    LNP p3 = right;
    while (p3) {
      LNP p2_ = p2->next;
      LNP p3_ = p3->next;

      p2->next = p3;
      p3->next = p2_;
      p2 = p2_;
      p3 = p3_;
    }

    if (odd) {
      p2->next = p1;
      p1->next = NULL;
    }
  }
```

6. [141. 环形链表](https://leetcode.cn/problems/linked-list-cycle/)

使用快慢指针，p1 每次走 1 步，p2 每次走 2 步。如果存在环，那么最终 p1, p2 都在环内，此时 p2 相对于 p1 的速度是 1，最终 p2 一定能够追上 p1。

```cpp
  bool hasCycle(ListNode *head) {
    if (!head)
      return false;

    LNP p1{head};
    LNP p2{head->next};

    while (p2 && p2->next) {
      p2 = p2->next->next;
      p1 = p1->next;

      if (p1 == p2)
        return true;
    }
    return false;
  }
```

7. [142. 环形链表 II](https://leetcode.cn/problems/linked-list-cycle-ii/)

慢指针 p1 和快指针 p2 一定会相遇上题已经证明。接下来需要找到环的起点。

设链表开头到环起点的距离是 $z$，p1 和 p2 相遇位置是 A 点，从环起点到 A 的距离是 $x$，从 A 到环起点的距离是 $y$。

先证明 p1 和 p2 相遇的时候，p1 沿着环走的距离必定小于环的周长 $x + y$。考虑最差情况：当 p1 刚到达环起点的时候，p2 恰好在 p1 的 next，由于 p2 相对于 p1 的速度是 1，因此 p2 在 $x + y - 1$ 时间之后恰好追上 p1，此时 p1 走的距离恰好是 $x + y - 1$。

接下来找环的起点。当 p1 和 p2 相遇的时候，p1 走的距离是：$z + x$，p2 走的距离是 $z + k(x + y) + x$，有 $z + k(x + y) + x = 2(z + x)$，得到：$z = y + (x + y)(k - 1)$，它的几何含义是，$z$ 恰好等于 $y$ 加上整数倍的环的周长。因此一个速度为 1 的点走 $z$ 的长度所花费的时间，恰好等于另外一个速度为 1 的点走 $y$ 的长度加上环周长的整数倍。也就是一个点从起点开始，另外一个点从相遇点开始，两个点恰好在环的入口相遇。

为了根据上面的关系找到环的起点，p1 和 p2 的起点应该从 ro 开始，而不是 p1，否则找环的起点的过程中两个速度相同的点永远也不会相遇。

```cpp
  ListNode *detectCycle(ListNode *head) {
    if (!head)
      return head;

    LNP ro{new LN(0, head)};
    LNP p1{ro};
    LNP p2{ro};

    while (p2 && p2->next) {
      p2 = p2->next->next;
      p1 = p1->next;

      if (p1 == p2) {
        p1 = ro;
        while (p1 != p2) {
          p1 = p1->next;
          p2 = p2->next;
        }

        delete ro;
        return p1;
      }
    }

    delete ro;
    return NULL;
  }
```

8. [457. 环形数组是否存在循环](https://leetcode.cn/problems/circular-array-loop/)

从每一个点开始判定从当前点出发，是否有长度大于 1 的环。
特殊情况是当到达起点的时候，如果访问过的点的数量大于 1，那么存在环，否则不存在。复杂度 $O(n^2)$

```cpp
  int n;
  VI a;

  bool check(int i) {
    int cnt{1};
    bool sign = a[i] > 0;
    int pre = i;

    while (true) {
      int j = (((pre + a[pre]) % n) + n) % n;

      if (j == i)
        return cnt > 1;
      if ((sign && a[j] < 0) || (!sign && a[j] > 0))
        return false;
      if (cnt > n)
        return false;

      pre = j;
      ++cnt;
    }
  }

  bool circularArrayLoop(vector<int> &nums) {
    a = nums;
    n = SZ(a);

    For(i, 0, n) {
      if (check(i)) {
        dbg(i);
        return true;
      }
    }

    return false;
  }
```

另外一种方法：使用 `vis` 数组标记当前点被访问的轮数。更本质的是标记当前点被访问的过程中，出边是正数还是负数。

检查下一个节点 `ne`，当 `ne` 已经被访问过，并且访问的轮数和当前轮数相等，那么存在环。特殊情况是下一个节点和当前节点一样，此时不符合条件。如果不相等，说明 `ne` 已经被访问过，并且从 `ne` 访问下去并没有出现环，再访问一次也不会出现环，因此停止遍历。

当 `ne` 没有被访问过，查看 `ne` 的出边是否和起点的正负一致。如果不一致则停止。
否则从 `ne` 开始继续遍历。（细节是当 `ne` 和**出边正负一致**的时候才设置 `ne` 被访问，不能直接设置它被访问过。因为如果出边不一致，`ne` 也被设置为访问过，那么 `ne` 这个点相当于被浪费了。）

因为每个点最多被访问一次，总的复杂度是 $O(n)$。

```cpp
  bool circularArrayLoop(vector<int> &a) {
    int n = SZ(a);
    VI vis(n, -1);

    For(i, 0, n) {
      if (vis[i] != -1)
        continue;
      bool sign = a[i] > 0;
      int cur = i;

      while (true) {
        int ne = ((cur + a[cur] % n) + n) % n;
        if (ne == cur)
          break;

        if (vis[ne] != -1) {
          if (vis[ne] == i)
            return true;
          else
            break;
        }

        if ((sign && a[ne] < 0) || (!sign && a[ne] > 0))
          break;

        cur = ne;
        vis[ne] = i;
      }
    }

    return false;
  }
```
