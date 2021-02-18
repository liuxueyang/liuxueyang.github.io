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
  ListNode* swapPairs(ListNode* head) {
    if (head == nullptr) return head;
    ListNode* res = new ListNode(0, head);

    ListNode* p1, *p2, *p3, *prev = res;
    p1 = prev->next;

    while (p1 != nullptr) {
      p2 = p1->next;
      if (p2 != nullptr) p3 = p2->next;
      else return res->next;

      prev->next = p2;
      p2->next = p1;
      p1->next = p3;

      prev = p1;
      p1 = prev->next;
    }

    return res->next;
  }
};
