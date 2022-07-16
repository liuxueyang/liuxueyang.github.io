/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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

// 注意这道题目要求的是 *任意两个节点* 之间的最长的距离。
class Solution
{
public:
    int res = -1;
    int max_depth(TreeNode *root) {
        if (root == nullptr) return -1;
        int left = max_depth(root->left) + 1,
            right = max_depth(root->right) + 1;
        int tmp = left + right;
        res = max(res, tmp);
        return max(left, right);
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        if (root == nullptr) return 0;
        max_depth(root);
        return res;
    }
};

// @lc code=end
