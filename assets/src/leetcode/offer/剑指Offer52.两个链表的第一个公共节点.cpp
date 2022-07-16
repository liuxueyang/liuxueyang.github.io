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
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* p1 = headA, *p2 = headB;
    int len1 = 0, len2 = 0;
    while (p1 != nullptr) {
      p1 = p1->next;
      ++len1;
    }
    while (p2 != nullptr) p2 = p2->next, ++len2;

    p1 = headA, p2 = headB;
    int k;
    if (len1 > len2) {
      k = len1 - len2;
      while (k--) p1 = p1->next;
    } else if (len1 < len2) {
      k = len2 - len1;
      while (k--) p2 = p2->next;
    }

    while (p1 != nullptr && p2 != nullptr) {
      if (p1 == p2) return p1;
      p1 = p1->next, p2 = p2->next;
    }

    return nullptr;
  }
};
