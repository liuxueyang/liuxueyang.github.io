+++
title = '反转链表题单'
date = 2024-10-17T19:49:25+08:00
tags = [ "linked list" ]
categories = [ "LeetCode" ]
+++

1. [206. 反转链表](https://leetcode.cn/problems/reverse-linked-list/)

p1 指向前一个节点，p2 指向当前节点，p3 指向下一个节点。

每次只修改 p2 节点，使它指向 p1，然后向右移动 p1, p2，p3 的作用是记录下一个 p2 的位置。

当 p2 为空时，说明整个链表反转结束。记得把原链表头的 next 指针置为空。

```cpp
  ListNode *reverseList(ListNode *head) {
    if (!head)
      return head;

    LNP p1 = head;
    LNP p2 = p1->next;
    LNP p3{NULL};

    while (p2) {
      p3 = p2->next;
      p2->next = p1;
      p1 = p2;
      p2 = p3;
    }

    head->next = NULL;
    return p1;
  }
```

2. [92. 反转链表 II](https://leetcode.cn/problems/reverse-linked-list-ii/)

这道题目使用一次遍历看起来复杂，其实只要观察到边界条件，其实是不难，多使用几个变量保存需要保存的信息更清晰。

首先我们需要找到要反转区间的前一个位置 st，然后找到反转区间的起点和终点 q1, q2，然后找到反转区间的下一个节点 en。找到 st 需要从 ro 节点走 left - 1 步，找到 q2 节点需要从 ro 节点走 r 步。这两步可以使用一次遍历得到。接下来就是常规的反转链表。

```cpp
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    LNP ro{new LN(0, head)};
    LNP p1{ro};
    int cnt{};

    while (cnt < left - 1) {
      cnt++;
      p1 = p1->next;
    }

    LNP st = p1;
    LNP q1{st->next};
    LNP p2{p1->next};
    LNP p3{};

    while (cnt < right) {
      p3 = p2->next;
      p2->next = p1;
      p1 = p2;
      p2 = p3;
      cnt++;
    }

    LNP q2{p1};
    LNP en{p2};

    st->next = q2;
    q1->next = en;

    LNP res = ro->next;
    delete ro;
    return res;
  }
```

3. [24. 两两交换链表中的节点](https://leetcode.cn/problems/swap-nodes-in-pairs/)

这道题和反转一个区间内的链表类似，只不过区间长度是 2。

首先找到区间的前一个节点 p0，p1, p2 分别是区间的起点和终点，p3 是区间的下一个节点。

对一个区间反转之后，p0 指向上一个区间的终点，p1 指向下一个区间的起点。这是一个循环节。考虑循环结束条件：当前区间只有一个节点，此时 p2 = NULL。当前区间没有任何节点，此时 p1 = NULL。

```cpp
  ListNode *swapPairs(ListNode *head) {
    if (!head)
      return head;

    LNP ro{new LN(0, head)};
    LNP p0{ro};
    LNP p1{p0->next};
    LNP p2{p1->next};
    LNP p3{};

    while (p1 && p2) {
      p3 = p2->next;
      p0->next = p2;
      p2->next = p1;
      p1->next = p3;
      p0 = p1;
      p1 = p3;
      if (p1)
        p2 = p1->next;
    }

    LNP res = ro->next;
    delete ro;
    return res;
  }
```

4. [25. K 个一组翻转链表](https://leetcode.cn/problems/reverse-nodes-in-k-group/)

先找到一个恰好长度等于 k 的区间，区间起点是 st, 终点是 en，然后对区间进行反转。p0 指向区间的上一个节点，反转结束后，p2 指向区间的下一个节点。反转结束后，p0 指向反转之后的上一个区间的结尾。这是一个循环节，循环结束条件：下一个区间的起点是空；下一个区间的长度小于 k。

判定当前区间长度的时候，统计节点个数需要检查 en->next 是否存在，而不是 en。因为要保证第 k 个节点非空。如果判断 en 是否存在，最终 en 可能指向空，此时还需要检查 en 是否为空。

```cpp
  ListNode *reverseKGroup(ListNode *head, int k) {
    LNP ro{new LN(0, head)};
    LNP p0{ro};
    LNP st{p0->next};
    LNP en{st};

    int cnt{};

    while (st) {
      en = st;
      cnt = 1;
      while (cnt < k && en->next) {
        en = en->next;
        cnt++;
      }
      if (cnt < k)
        break;

      LNP p1{p0};
      LNP p2{st};
      LNP p3{};

      while (p1 != en) {
        p3 = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p3;
      }
      p0->next = en;
      p0 = st;
      st = p2;
      p0->next = st;
    }

    LNP res = ro->next;
    delete ro;
    return res;
  }
```

指针 `q0` 指向上一个区间的最后一个结点，当前区间的头尾指针分别是 `h0` 和 `t0`.
先把区间 `[h0, t0]` 链表反转，然后把反转后的链表头部接到上一段：`q0->next = t0`，当前答案的最后一个结点变成了 `h0`. 下一个区间的开头是当前区间的下一个结点，恰好是 `p2`.

> 最后一个不足 `k` 的区间不需要反转，`while` 条件中不能先进行个数递减，这里有边界问题。

```cpp
  ListNode *reverseKGroup(ListNode *head, int k) {
    LNP du{new LN(0, head)};
    LN *h0{}, *t0{}, *p1{}, *p2{}, *p3{}, *q0{};

    q0 = du;
    h0 = q0->next;
    while (h0) {
      int k1 = k - 1;
      t0 = h0;
      while (k1 && t0->next) {
        k1--;
        t0 = t0->next;
      }

      if (k1) {
        break;
      }

      p1 = q0, p2 = h0;
      while (t0 != p1) {
        p3 = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p3;
      }

      q0->next = t0;
      q0 = h0;
      h0 = p2;
    }

    q0->next = h0;
    auto res = du->next;
    delete du;
    return res;
  }
```

5. [2074. 反转偶数长度组的节点](https://leetcode.cn/problems/reverse-nodes-in-even-length-groups/)

这种反转中间某一段链表的题目，把反转链表的过程单独写成一个函数能够极大降低题目难度。

```cpp
  void reverse_list(LNP head, LNP tail) {
    if (!head)
      return;

    LNP p1{head}, p2{p1->next}, p3{};

    while (p1 != tail) {
      p3 = p2->next;
      p2->next = p1;
      p1 = p2;
      p2 = p3;
    }

    head->next = NULL;
    return;
  }

  ListNode *reverseEvenLengthGroups(ListNode *head) {
    LNP ro{new LN(0, head)};
    LNP p0{ro}, q0{}, p1{p0->next}, st{p1}, en{p1};
    int len{1};

    while (st) {
      int k = 1;
      en = st;

      while (k < len && en->next) {
        k++;
        en = en->next;
      }
      q0 = en->next;

      if (k % 2 == 0) {
        reverse_list(st, en);
        p0->next = en;
        st->next = q0;
        p0 = st;
      } else {
        p0 = en;
      }

      if (k < len)
        break;

      st = p0->next;
      len++;
    }

    LNP res = ro->next;
    delete ro;
    return res;
  }
```
