/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  ListNode* partition(ListNode* head, int x) {
    if (head == nullptr) return head;
    ListNode *q1, *q2, *p1, *p2, *cur, *res = new ListNode(0);

    q1 = q2 = p1 = p2 = nullptr;
    res->next = head, cur = res;

    while (cur ->next != nullptr) {
      cur = cur->next;
      if (cur->val >= x) {
        if (p1 == nullptr) p1 = cur;
        if (p2 == nullptr) p2 = cur;
        else p2->next = cur, p2 = cur;
      } else {
        if (q1 == nullptr) q1 = cur;
        if (q2 == nullptr) q2 = cur;
        else q2->next = cur, q2 = cur;
      }
    }

    if (q2 != nullptr) q2->next = p1;
    if (p2 != nullptr) p2->next = nullptr;
    if (q1 != nullptr) res->next = q1;
    else res->next = p1;

    return res->next;
  }
};
