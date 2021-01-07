/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
 */

#include <iostream>
#include <vector>
#include <queue>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
using namespace std;
using VI = vector<int>;

class Solution
{

public:
    VI res;
    vector<int> rightSideView(TreeNode *root)
    {
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            auto cur = que.front();
            res.push_back(cur->val);
        }
        return res;
    }
};
// @lc code=end
