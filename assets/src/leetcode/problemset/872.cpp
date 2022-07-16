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
  using VI = vector<int>;
  VI le1, le2;

  void dfs(TreeNode* root, VI& le) {
    if (!root) return;

    if (!root->left && !root->right) {
      le.push_back(root->val);
      return;
    }

    if (root->left) dfs(root->left, le);
    if (root->right) dfs(root->right, le);
  }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
      le1 = VI();
      le2 = VI();
      dfs(root1, le1);
      dfs(root2, le2);

      return le1 == le2;
    }
};
