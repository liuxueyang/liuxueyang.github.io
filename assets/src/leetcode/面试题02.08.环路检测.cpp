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
  ListNode *detectCycle(ListNode *head) {
    ListNode *p1 = head, *p2 = head;

    while (p1 != nullptr && p2 != nullptr) {
      p1 = p1->next;
      p2 = p2->next;
      if (p2 == nullptr) return nullptr;
      p2 = p2->next;

      if (p1 == p2) break;
    }

    if (p1 == nullptr || p2 == nullptr) return nullptr;

    p2 = head;
    while (p1 != p2) {
      p2 = p2->next;
      p1 = p1->next;
    }

    return p2;
  }
};
