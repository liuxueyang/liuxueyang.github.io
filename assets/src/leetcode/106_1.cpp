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
  using TN = TreeNode;
  using TNP = TN*;

  map<int, int> m;
  VI in_order, post_order;

  TNP dfs(int l1, int r1, int l2, int r2) {
    if (l1 > r1) return nullptr;

    TNP root = new TN();
    int val = post_order[r2], idx = m[val], cnt1 = idx - l1, cnt2 = r1 - idx;

    root->val = val;

    if (cnt1 > 0) {
      root->left = dfs(l1, idx - 1, l2, l2 + cnt1 - 1);
    }
    if (cnt2 > 0) {
      root->right = dfs(idx + 1, r1, l2 + cnt1, r2 - 1);
    }

    return root;
  }

  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int n = inorder.size();

    if (!n) return nullptr;

    in_order = inorder;
    post_order = postorder;

    for (int i = 0; i < n; ++i) m[in_order[i]] = i;

    return dfs(0, n - 1, 0, n - 1);
  }
};
