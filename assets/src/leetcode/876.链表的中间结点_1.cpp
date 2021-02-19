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
  ListNode* middleNode(ListNode* head) {
    ListNode *p1 = head, *p2 = head;
    while (p2 != nullptr && p2->next != nullptr) {
      p2 = p2->next;
      p1 = p1->next;
      if (p2 != nullptr) p2 = p2->next;
    }

    return p1;
  }
};
