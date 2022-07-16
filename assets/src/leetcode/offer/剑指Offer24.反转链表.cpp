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
  ListNode* reverseList(ListNode* head) {
    if (head == nullptr) return head;

    ListNode *p1, *p2, *p3;

    p1 = nullptr;
    p2 = head;
    p3 = p2->next;

    while (p2 != nullptr) {
      p3 = p2->next;
      p2->next = p1;
      p1 = p2;
      p2 = p3;
    }

    return p1;
  }
};
