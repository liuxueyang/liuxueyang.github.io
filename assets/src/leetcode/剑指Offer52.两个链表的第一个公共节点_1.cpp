#include <cstdio>
#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};


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
    ListNode *p1 = headA, *p2 = headB;
    if (p1 == nullptr || p2 == nullptr) return nullptr;
    bool flag1 = false, flag2 = false;

    while (true) {
      if (p1 == nullptr) {
        if (!flag1) p1 = headB, flag1 = true;
        else return nullptr;
      }
      if (p2 == nullptr) {
        if (!flag2) p2 = headA, flag2 = true;
        else return nullptr;
      }

      if (p1 == p2) return p1;

      p1 = p1->next;
      p2 = p2->next;
    }

    return nullptr;
  }
};

int main() {
  ListNode* a = new ListNode(3);
  ListNode* b = new ListNode(2);
  b->next = a;
  Solution A;

  auto x = A.getIntersectionNode(a, b);
  cout << x << endl;
  if (x != nullptr) cout << x->val << endl;

  return 0;
}
