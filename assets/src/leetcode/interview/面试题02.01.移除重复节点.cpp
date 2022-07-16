/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

const int N = 200010;
int vis[N];

class Solution {
public:
  ListNode* removeDuplicateNodes(ListNode* head) {
    if (head == nullptr) return head;
    ListNode *res = new ListNode(0);

    memset(vis, 0, sizeof vis);
    ListNode *prev = res, *cur = head;
    while (cur != nullptr) {
      if (!vis[cur->val]) {
        prev->next = cur;
        prev = cur;
        vis[cur->val] = 1;
      }
      cur = cur->next;
    }
    prev->next = nullptr;

    return res->next;
  }
};
