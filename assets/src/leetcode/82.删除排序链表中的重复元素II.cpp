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
  ListNode* truncate(ListNode* h) {
    ListNode* res = h;
    bool flag = false;
    while (res->next != nullptr && res->val == res->next->val) {
      res = res->next;
      flag = true;
    }
    if (flag) res = res->next;
    return res;
  }

  ListNode* deleteDuplicates(ListNode* head) {
    ListNode* res;
    res = truncate(head);
    ListNode* cur = res, *prev = nullptr;
    while (cur != nullptr) {
      ListNode* tmp = truncate(cur);
      if (tmp == cur) {
        prev = cur;
        cur = cur->next;
      } else {
        prev->next = tmp;
        prev = tmp;
        cur = tmp;
      }
    }
    return res;
  }
};
