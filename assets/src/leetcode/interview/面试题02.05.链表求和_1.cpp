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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* res = new ListNode(0);

    ListNode *p1 = l1, *p2 = l2, *prev = res;
    int t = 0;
    while (l1 != nullptr && l2 != nullptr) {
      t += l1->val + l2->val;
      l1->val = t % 10; t /= 10;
      prev->next = l1; prev = l1;
      l1 = l1->next, l2 = l2->next;
    }
    while (l1 != nullptr) {
      t += l1->val; l1->val = t % 10; t /= 10;
      prev->next = l1; prev = l1; l1 = l1->next;
    }
    while (l2 != nullptr) {
      t += l2->val, l2->val = t % 10, t /= 10;
      prev->next = l2, prev = l2; l2 = l2->next;
    }
    if (t) {
      prev->next = new ListNode(t), prev = prev->next; prev->next = nullptr;
    }
    if (prev != nullptr) prev->next = nullptr;

    return res->next;
  }
};
