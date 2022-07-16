/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
  int val;
  ListNode *next;
  ListNode()
    : val(0),
      next(nullptr){}
  ListNode(int x)
    : val(x),
      next(nullptr){}
  ListNode(int x, ListNode *next) : val(x), next(next){}
};

#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
  ListNode *swapNodesV2(ListNode *head, int k) {
    auto dummy = new ListNode(-1);
    dummy->next = head;
    auto i = head, j = head;
    ListNode* ri = nullptr, *rj = nullptr;
    auto m = k - 1;
    while (m--) {
      j = j->next;
    }
    rj = j;
    while (j->next) {
      j = j->next;
      i = i->next;
    }
    ri = i;
    swap(ri->val, rj->val);

    return dummy->next;
  }
  ListNode *swapNodes(ListNode *head, int k) {
    auto dummy = new ListNode(-1);
    dummy->next = head;
    auto i = dummy, j = dummy;
    ListNode *ri = nullptr, *rj = nullptr;
    auto m = k - 1;
    while (m--) {
      j = j->next;
    }
    rj = j;

    // k+1. gap: k-1 -> k
    if (j)
      j = j->next;

    while (j->next) {
      j = j->next;
      i = i->next;
    }
    ri = i;

    auto t_i = ri->next, t_j = rj->next;
    auto t_in = t_i->next, t_jn = t_j->next;

    if (t_j != ri && t_i != rj) {
      ri->next = t_j;
      t_j->next = t_in;

      rj->next = t_i;
      t_i->next = t_jn;
    } else if (t_j == ri) {
      rj->next = t_i;
      t_i->next = t_j;
      t_j->next = t_in;
    } else if (t_i == rj) {
      ri->next = t_j;
      t_j->next = t_i;
      t_i->next = t_jn;
    }

    return dummy->next;
  }
};
