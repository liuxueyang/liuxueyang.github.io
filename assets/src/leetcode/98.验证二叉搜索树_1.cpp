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
  using ll = long long;
  const ll INF = 1ll << 35;

  bool dfs(TreeNode* root, ll left, ll right) {
    if (root == nullptr) return true;
    if (root->val <= left || root->val >= right) return false;
    bool l = dfs(root->left, left, root->val),
      r = dfs(root->right, root->val, right);
    return l && r;
  }

  bool isValidBST(TreeNode* root) {
    if (root == nullptr) return true;
    bool left = dfs(root->left, -INF, root->val),
      right = dfs(root->right, root->val, INF);
    return left && right;
  }
};
