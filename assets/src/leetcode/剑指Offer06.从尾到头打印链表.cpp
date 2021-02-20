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
  vector<int> res;
  void dfs(ListNode* head) {
    if (head == nullptr) return;
    dfs(head->next);
    res.push_back(head->val);
  }
  vector<int> reversePrint(ListNode* head) {
    dfs(head);
    return res;
  }
};
