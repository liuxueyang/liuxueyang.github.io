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
class Solution {
public:
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    if (!root) return res;

    stack<TreeNode*> stk;
    while (root) {
      stk.push(root);
      root = root->left;
    }

    while (!stk.empty()) {
      TreeNode* tmp = stk.top(); stk.pop();
      res.push_back(tmp->val);
      tmp = tmp->right;
      while (tmp) {
        stk.push(tmp);
        tmp = tmp->left;
      }
    }
    return res;
  }
};
