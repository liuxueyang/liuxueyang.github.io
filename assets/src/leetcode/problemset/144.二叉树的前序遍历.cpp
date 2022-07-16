/*
            * @lc app=leetcode.cn id=144 lang=cpp
            *
            * [144] 二叉树的前序遍历
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
    vector<int> preorderTraversal(TreeNode *root)
    {
        const int N = 120;
        TreeNode *s[N];
        int tt = 0;
        VI res;
        s[++tt] = root;
        while (tt)
        {
            TreeNode *t = s[tt--];
            if (t == nullptr)
                continue;
            res.push_back(t->val);
            s[++tt] = t->right;
            s[++tt] = t->left;
        }
        return res;
    }
};
// @lc code=end
