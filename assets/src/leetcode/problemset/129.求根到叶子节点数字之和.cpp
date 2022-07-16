/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根到叶子节点数字之和
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

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

using VI = vector<int>;
using VS = vector<string>;

class Solution
{
public:
    int res;
    void dfs(TreeNode * root, int cur) {
        if (root == NULL) return;
        cur = cur * 10 + root->val;
        if (root->left != nullptr)
            dfs(root->left, cur);
        if (root->right != nullptr)
            dfs(root->right, cur);
        if (root->left == nullptr && root->right == nullptr)
            res += cur;
    }
    int sumNumbers(TreeNode *root)
    {
        res = 0;
        dfs(root, 0);
        return res;
    }
};
// @lc code=end
