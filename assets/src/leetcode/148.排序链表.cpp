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
  void merge_list(ListNode *p1, ListNode *p2, ListNode *q1, ListNode *q2) {
    ListNode *h1 = p1, *h2 = q1;
    while (h1 != p2 && h2 != q2) {
      if (h1->val <= h2->val) h1 = h1->next;
      else swap(h1->val, h2->val), h1 = h1->next;
    }
  }

  void merge_sort(ListNode *h, ListNode* t, int len) {
    if (len == 1) return;
    
  }

  ListNode* sortList(ListNode* head) {
    if (head == nullptr) return head;
    int len = 0;
    ListNode *cur = head;
    while (cur != nullptr) cur = cur->next, ++len;

  }
};
