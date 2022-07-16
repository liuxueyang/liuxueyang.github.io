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
  ListNode* deleteNode(ListNode* head, int val) {
    ListNode* res = new ListNode(0);
    res->next = head;

    ListNode* prev = res, *cur = prev->next;
    while (cur != nullptr) {
      if (cur->val == val) {
        prev->next = cur->next;
        break;
      }
      prev = cur;
      cur = cur->next;
    }

    return res->next;
  }
};
