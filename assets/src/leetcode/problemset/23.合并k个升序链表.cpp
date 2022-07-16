/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



// @lc code=start
using namespace std;
using VI = vector<int>;
using VS = vector<string>;
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
    struct Node {
        ListNode* r;
        bool operator>(const Node& other) const { 
            return this->r->val > other.r->val; 
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<Node, vector<Node>, greater<Node>> q;
        ListNode* res = new ListNode();
        for (auto &x : lists) {
            if (x) {
                Node t; t.r = x; q.push(t);
            }
        }
        ListNode* cur = res;
        while (!q.empty()) {
            Node t = q.top(); q.pop();
            cur->next = t.r; cur = cur->next;
            if (cur->next) {
                Node x; x.r = cur->next; q.push(x);
            }
        }
        return res->next;
    }
};
// @lc code=end

