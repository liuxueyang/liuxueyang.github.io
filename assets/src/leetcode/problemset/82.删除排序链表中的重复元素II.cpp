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

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include <cstdio>

using namespace std;

class Solution {
public:
  ListNode* truncate(ListNode* h) {
    if (h == nullptr) return h;

    ListNode* res = h;
    bool flag = false;
    while (res->next != nullptr && res->next->val == res->val) {
      res = res->next;
      flag = true;
    }
    if (flag) res = res->next;
    if (h == res) return res;
    else return truncate(res);
  }

  ListNode* deleteDuplicates(ListNode* head) {
    ListNode* res = new ListNode(0, head);
    ListNode* cur = res->next, *prev = res;

    while (cur != nullptr) {
      cur = truncate(cur);
      prev->next = cur;
      prev = cur;
      if (cur != nullptr)
        cur = cur->next;
    }

    return res->next;
  }
};

int main() {
  Solution a;
  int v[7] = {1, 2, 3, 3, 4, 4, 5};
  ListNode* h = new ListNode();
  ListNode* cur = h;
  for (int i = 0; i < 7; ++i) {
    ListNode* t = new ListNode(v[i]);
    cur->next = t;
    cur = t;
    printf("insert: %d\n", cur->val);
  }

  a.deleteDuplicates(h->next);

  return 0;
}
