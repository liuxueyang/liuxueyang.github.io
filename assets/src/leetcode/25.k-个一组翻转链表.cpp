/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 */
#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
using VI = vector<int>;
using VS = vector<string>;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// @lc code=start
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr) return head;
        ListNode *h, *t, *q1, *q2, *p1, *p2, 
            *p3, *res = new ListNode(0, head), *cur;
        int K = --k;

        h = res, t = h->next;
        while (true) {
            cur = q1 = t;
            while (k-- && cur != nullptr) cur = cur->next;
            if (k > 0 || cur == nullptr) {
                h->next = t;
                return res->next;
            }

            t = cur->next;
            q2 = cur;
            h->next = q2, h = q1, k = K;

            p1 = q1, p2 = p1->next;
            while (p2 != t) {
                p3 = p2->next;
                p2->next = p1;
                p1 = p2;
                p2 = p3;
            }
        }

        return res->next;
    }
};
// @lc code=end

