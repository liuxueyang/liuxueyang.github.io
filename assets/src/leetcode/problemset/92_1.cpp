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

class Solution {
public:
  using LN = ListNode;
  using LNP = LN*;

  ListNode* reverseBetween(ListNode* head, int left, int right) {
    LNP du = new LN(0, head), p1, p2, p3, st, en;

    st = en = du;
    left--, right++;
    while (left--) st = st->next;
    while (right--) en = en->next;

    p1 = st, p2 = p1->next;
    while (p2 != en) {
      p3 = p2->next;
      p2->next = p1;
      p1 = p2;
      p2 = p3;
    }
    p2 = st->next;
    st->next = p1;
    p2->next = en;

    LNP res = du->next;
    delete du;
    return res;
  }
};
