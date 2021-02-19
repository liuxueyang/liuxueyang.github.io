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
  ListNode* getKthFromEnd(ListNode* head, int k) {
    ListNode* p1 = head, *p2 = head;
    k--;
    while (k-- && p2 != nullptr) {
      p2 = p2->next;
    }

    if (p2 == nullptr) return nullptr;

    while (p2->next != nullptr) {
      p2 = p2->next;
      p1 = p1->next;
    }

    return p1;
  }
};
