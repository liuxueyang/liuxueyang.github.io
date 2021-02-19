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
  int kthToLast(ListNode* head, int k) {
    ListNode* p1 = head, *p2 = head;
    k--;
    while (k--) {
      p2 = p2->next;
    }

    while (p2->next != nullptr) {
      p1 = p1->next;
      p2 = p2->next;
    }

    return p1->val;
  }
};
