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
  using LN = ListNode;
  using LNP = LN*;

  void dfs(LNP p1, LNP p2) {
    if (!p2) return;

    LNP p3 = p2->next;
    if (p3) {
      while (p3 && p3->val == p2->val) {
        p3 = p3->next;
      }

    } else {
      p1->next = p2;
    }
  }

  ListNode* deleteDuplicates(ListNode* head) {
    LNP du = new LN(0, head);
    dfs(du, head);

    return du->next;
  }
};
