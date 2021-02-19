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
    if (h == nullptr) return h;

    bool flag = false;
    while (res->next != nullptr && res->next->val == res->val) {
      flag = true;
      res = res->next;
    }

    if (flag) res = res->next;

    if (res == h) return h;
    return truncate(res);
  }

  ListNode* deleteDuplicates(ListNode* head) {
    ListNode* res = new ListNode(0, head);
    ListNode* prev = res, *cur = prev->next;

    while (cur != nullptr) {
      cur = truncate(cur);
      prev->next = cur;
      prev = cur;
      if (cur != nullptr) cur = cur->next;
    }

    return res->next;
  }
};
