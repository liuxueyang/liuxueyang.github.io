+++
title = '【题单】二叉树自顶向下 DFS'
date = 2024-10-17T21:00:05+08:00
tags = [ "dfs" ]
categories = [ "LeetCode" ]
+++

1. [104. 二叉树的最大深度](https://leetcode.cn/problems/maximum-depth-of-binary-tree/)

深度从根开始往下递增，到达叶子的时候，深度达到最深，更新答案。

```cpp
  int ans;

  void dfs(TNP root, int d) {
    if (!root)
      return;

    auto [_, l, r] = *root;
    if (!l && !r)
      ckmax(ans, d);

    dfs(l, d + 1);
    dfs(r, d + 1);
  }

  int maxDepth(TreeNode *root) {
    ans = 0;
    dfs(root, 1);
    return ans;
  }
```

2. [111. 二叉树的最小深度](https://leetcode.cn/problems/minimum-depth-of-binary-tree/)

从根往下访问，访问到孩子节点的时候，深度加一。到达叶子节点的时候更新答案。

```cpp
  int ans;

  void dfs(TNP root, int d) {
    if (!root)
      return;

    auto [_, l, r] = *root;
    if (!l && !r)
      ckmin(ans, d);
    dfs(l, d + 1);
    dfs(r, d + 1);
  }

  int minDepth(TreeNode *root) {
    ans = INF;
    dfs(root, 1);
    if (ans == INF)
      ans = 0;

    return ans;
  }
```


3. [112. 路径总和](https://leetcode.cn/problems/path-sum/)

从根开始累加当前路径的和，如果到叶子的和与目标值相等，那么找到答案。
如果不是叶子，那么分别递归的左右子树。

```cpp
  int target;
  bool ans;

  void dfs(TNP root, int cur) {
    if (ans)
      return;

    if (!root)
      return;

    int val = root->val;

    auto left = root->left, right = root->right;
    if (!left && !right) {
      if (cur + val == target) {
        ans = true;
        return;
      }
    } else if (!left) {
      dfs(right, cur + val);
    } else if (!right) {
      dfs(left, cur + val);
    } else {
      dfs(left, cur + val);
      dfs(right, cur + val);
    }
  }

  bool hasPathSum(TreeNode *root, int targetSum) {
    target = targetSum;
    ans = false;
    dfs(root, 0);

    return ans;
  }
```

另外一种更好的思路：从根节点到叶子节点的过程中，不断从 targetSum 中减去当前节点的值，如果到达叶子的时候 targetSum 恰好等于叶子节点的值，那么找到了答案。否则递归左子树或者右子树。

```cpp
  bool hasPathSum(TreeNode *root, int targetSum) {
    if (!root)
      return false;

    int val = root->val;
    auto left = root->left, right = root->right;

    if (!left && !right && val == targetSum)
      return true;
    return hasPathSum(left, targetSum - val) ||
           hasPathSum(right, targetSum - val);
  }
```

4. [129. 求根节点到叶节点数字之和](https://leetcode.cn/problems/sum-root-to-leaf-numbers/)

从根节点往下访问的同时累加当前的数字，遇到叶子的时候累计答案。递归访问左右子树。

```cpp
  int ans;

  void dfs(TNP root, int cur) {
    if (!root)
      return;

    auto left = root->left, right = root->right;
    cur = 10 * cur + root->val;

    if (!left && !right) {
      ans += cur;
    } else if (!left) {
      dfs(right, cur);
    } else if (!right) {
      dfs(left, cur);
    } else {
      dfs(left, cur);
      dfs(right, cur);
    }
  }

  int sumNumbers(TreeNode *root) {
    ans = 0;
    dfs(root, 0);
    return ans;
  }
```

其实只需要当前节点是否是叶子节点即可，如果当前节点是空，那么直接返回。因此把判断左右子树是否为空的逻辑可以去掉：

```cpp
  int ans;

  void dfs(TNP root, int cur) {
    if (!root)
      return;

    auto left = root->left, right = root->right;
    cur = cur * 10 + root->val;

    if (!left && !right) {
      ans += cur;
      return;
    }
    dfs(left, cur);
    dfs(right, cur);
  }

  int sumNumbers(TreeNode *root) {
    ans = 0;
    dfs(root, 0);
    return ans;
  }
```

如果当前节点是叶子节点，那么直接返回。如果当前节点是空，返回 0. 如果当前节点不是叶子，返回左右子树得到数字的和。 因此有下面的更好的写法：

```cpp
  int dfs(TNP root, int cur) {
    if (!root)
      return 0;

    auto left = root->left, right = root->right;
    cur = cur * 10 + root->val;

    if (!left && !right)
      return cur;
    return dfs(left, cur) + dfs(right, cur);
  }

  int sumNumbers(TreeNode *root) { return dfs(root, 0); }
```

5. [199. 二叉树的右视图](https://leetcode.cn/problems/binary-tree-right-side-view/)

使用 BFS 遍历树的每一层，把每一层最右侧的值追加到答案中。BFS 过程中从左到右做，暴力的做法是使用 map 更新每一层的值，最后留下的就是最右侧的值。

```cpp
  vector<int> rightSideView(TreeNode *root) {
    using PPI = pair<TNP, int>;
    queue<PPI> q;
    VI ans;

    q.push({root, 1});
    int cur = -1, x = -1;
    map<int, int> m;

    while (nemp(q)) {
      auto [p, d] = q.front();
      q.pop();

      if (!p)
        continue;

      if (d == cur) {
        x = p->val;
      } else {
        cur = d;
        x = p->val;
      }
      m[cur] = x;

      auto left = p->left, right = p->right;
      if (left)
        q.push({left, d + 1});
      if (right)
        q.push({right, d + 1});
    }

    if (cur != -1)
      m[cur] = x;
    for (auto [_, x] : m)
      ans.pb(x);

    return ans;
  }
```

更好的做法是记录当前的层数，当层数变化的时候，把上一层的结果追加到答案中。注意边界条件：树为空。循环结束之后，需要把最后一层的答案加到答案中。

```cpp
  vector<int> rightSideView(TreeNode *root) {
    using PPI = pair<TNP, int>;
    queue<PPI> q;
    q.push({root, 1});

    int val = -1, depth = -1;
    VI ans;

    while (nemp(q)) {
      auto [p, d] = q.front();
      q.pop();

      if (!p)
        continue;

      if (d == depth)
        val = p->val;
      else {
        if (depth != -1)
          ans.pb(val);

        depth = d;
        val = p->val;
      }

      auto l = p->left, r = p->right;
      if (l)
        q.push({l, d + 1});
      if (r)
        q.push({r, d + 1});
    }

    if (depth != -1)
      ans.pb(val);

    return ans;
  }
```

另外一个神奇的做法：标记当前层是否访问过，从右儿子开始遍历树，如果当前层第一次访问，那么把当前节点值追加到答案中，然后递归访问右子树、左子树。因为是从右儿子开始访问的，因此第一次访问当前层的时候的节点就是最右边的节点。

注意如果当前层第一次访问，或者当前层已经被访问过，那么这个点极其儿子也是需要访问的，原因是儿子可能存在深度最深的点，此时右视图应该包含它。

```cpp
  VI ans;
  VI vis;

  void dfs(TNP root, int depth) {
    if (!root)
      return;

    if (!vis[depth]) {
      ans.pb(root->val);
      vis[depth] = 1;
    }

    auto l = root->left, r = root->right;
    dfs(r, depth + 1);
    dfs(l, depth + 1);
  }

  vector<int> rightSideView(TreeNode *root) {
    ans = VI{};
    vis = VI(150, 0);
    dfs(root, 0);

    return ans;
  }
```

vis 数组也可以省略，使用当前答案数组的长度来标记当前层是否访问过。具体来说就是用当前答案长度代表当前的层数，如果第一次到新的一层，那么当前层数恰好等于答案长度，把节点追加到答案中。此时答案长度 +1，这样当前层的其他节点都不会被追加到答案中。

> 还是要注意当访问到本层最右边的节点之后，不要直接返回，当前节点的孩子还是应该继续访问下去。

```cpp
  VI ans;

  void dfs(TNP root, int depth) {
    if (!root)
      return;

    if (depth == SZ(ans)) {
      ans.pb(root->val);
    }

    dfs(root->right, depth + 1);
    dfs(root->left, depth + 1);
  }

  vector<int> rightSideView(TreeNode *root) {
    ans = VI{};

    dfs(root, 0);

    return ans;
  }
```

6. [1448. 统计二叉树中好节点的数目](https://leetcode.cn/problems/count-good-nodes-in-binary-tree/)

从根节点开始往下递归，维护当前的最大值，如果当前节点的值大于等于之前节点的最大值，那么这是一个符合条件的节点，更新答案。

```cpp
  int ans{};

  void dfs(TNP root, int cur) {
    if (!root)
      return;

    int val = root->val;
    auto l = root->left, r = root->right;

    if (cur <= val) {
      ans++;
    }

    dfs(l, max(cur, val));
    dfs(r, max(cur, val));
  }

  int goodNodes(TreeNode *root) {
    ans = 0;

    dfs(root, -INF);

    return ans;
  }
```

另外一种更好的写法：设 `dfs(root, cur)` 返回以 `root` 为根的好节点的数目，如果当前节点为空，返回 0，否则递归计算左右子树，再检查当前节点是否是好节点，它们的和就是答案。

这是自顶向下的思考方式，原因是顶部节点的答案不会受到下面节点的影响。

7. [1457. 二叉树中的伪回文路径](https://leetcode.cn/problems/pseudo-palindromic-paths-in-a-binary-tree/)

只要求排列中有一个是回文的，观察性质发现这要求序列中出现次数是奇数的个数不能超过 1. 由于值域范围只有 9，因此可以使用数组记录每个数字出现的次数。访问到叶子节点的时候，统计每个数字出现的次数即可。如果不是叶子，那么访问左子树和右子树，它们的和就是答案。如果是空节点，直接返回 0.

```cpp
  int dfs(TNP root, VI cnt) {
    if (!root)
      return 0;

    auto l = root->left, r = root->right;
    int val = root->val;
    cnt[val]++;

    if (!l && !r) {
      int sum{};
      For1(i, 1, 9) {
        if (cnt[i] & 1)
          sum++;
      }
      return sum <= 1;
    }

    return dfs(l, cnt) + dfs(r, cnt);
  }

  int pseudoPalindromicPaths(TreeNode *root) {
    VI cnt(10, 0);
    return dfs(root, cnt);
  }
```

观察到值域范围很小，并且我们只关心每个数字出现次数的奇偶性，因此可以使用位运算压缩到一个整数里面：

```cpp
  int dfs(TNP root, int mask) {
    if (!root)
      return 0;

    auto l = root->left, r = root->right;
    int val = root->val;

    mask ^= (1 << val);
    if (!l && !r) {
      int sum{};
      For1(i, 1, 9) {
        if ((mask >> i) & 1)
          sum++;
      }
      return sum <= 1;
    }

    return dfs(l, mask) + dfs(r, mask);
  }

  int pseudoPalindromicPaths(TreeNode *root) { return dfs(root, 0); }
```

又观察到我们要求最终出现奇数的个数不能超过 1，也就是这个整数中，最终只有一个二进制位是 1，也就是整数的 `lowbit` 恰好等于这个整数：

```cpp
  int lowbit(int x) { return x & -x; }

  int dfs(TNP root, int mask) {
    if (!root)
      return 0;

    auto l = root->left, r = root->right;
    int val = root->val;

    mask ^= (1 << val);
    if (!l && !r) {
      return mask == lowbit(mask);
    }

    return dfs(l, mask) + dfs(r, mask);
  }

  int pseudoPalindromicPaths(TreeNode *root) { return dfs(root, 0); }
```

8. [1315. 祖父节点值为偶数的节点和](https://leetcode.cn/problems/sum-of-nodes-with-even-valued-grandparent/)

仿照遍历无根树的思路，可以带上父节点，这道题目需要祖父节点的信息，因此可以增加一个参数指向祖父节点。根据祖父节点的信息判定是否累加当前节点到答案，继续访问左右子树即可。

```cpp
  int dfs(TNP root, TNP p1, TNP p2) {
    if (!root)
      return 0;

    auto [val, l, r] = *root;
    int cur{};

    if (p2 && p2->val % 2 == 0)
      cur = val;
    return dfs(l, root, p1) + dfs(r, root, p1) + cur;
  }

  int sumEvenGrandparent(TreeNode *root) { return dfs(root, nullptr, nullptr); }
```

9. [988. 从叶结点开始的最小字符串](https://leetcode.cn/problems/smallest-string-starting-from-leaf/)

这道题目的陷阱是字典序最小。对于两个字符串，容易想到把子树的字符串构造出来，然后拼接上根的字符，选取最小的。可惜这样是错误的，原因是上面成立的条件是两个子树的字符串的长度相等，长度不等的字符串，往后面各追加一个相同的字符，它们字典序并不会保持不变，也就是说子树的最小值并不能推出根的最小值。因此上述做法不对，并不能划分成两个独立的子问题。

考虑最基础的做法：遍历树的过程中，维护迄今为止得到的字符串，当遇到叶子的时候，更新答案。否则递归两个子树。

```cpp
  string ans;

  void dfs(TNP root, string s) {
    if (!root)
      return;

    auto [val, l, r] = *root;
    s += char('a' + val);

    if (!l && !r) {
      reverse(all(s));
      if (ans.empty())
        ans = s;
      else
        ckmin(ans, s);
      return;
    }

    dfs(l, s);
    dfs(r, s);
  }

  string smallestFromLeaf(TreeNode *root) {
    ans = "";
    dfs(root, "");
    return ans;
  }
```

10. [1026. 节点与其祖先之间的最大差值](https://leetcode.cn/problems/maximum-difference-between-node-and-ancestor/)

注意题目祖先的定义是一个节点是另外一个节点的祖先的祖先也可以。其实这就是本来的祖先的定义。

注意到当我们遍历到空节点的时候，从根节点到达这个空节点的路径上的最大值和最小值已经得到了。最终的答案一定在所有到空节点的路径中的某一个。因此可以自顶向下做。

遍历树的过程中，维护遇到的最小值和最大值。遇到空节点的时候，返回答案。否则返回左右子树的答案的最大值。

```cpp
  int dfs(TNP root, int mi, int mx) {
    if (!root) {
      return mx - mi;
    }

    auto [val, l, r] = *root;

    ckmin(mi, val);
    ckmax(mx, val);

    return max(dfs(l, mi, mx), dfs(r, mi, mx));
  }
  int maxAncestorDiff(TreeNode *root) { return dfs(root, INF, -INF); }
```

11. [1022. 从根到叶的二进制数之和](https://leetcode.cn/problems/sum-of-root-to-leaf-binary-numbers/)

函数 dfs 返回这个子树所有叶子代表的二进制数字之和。这是一个子问题，因此可以自顶向下求。cur 维护从根到达当前节点的数字，只有当到达叶子节点的时候才返回答案。当到达空节点的时候，返回 0。否则返回两个子树的答案的和。

```cpp
  int dfs(TNP root, int cur) {
    if (!root)
      return 0;

    auto [val, l, r] = *root;
    cur = cur * 2 + val;

    if (!l && !r)
      return cur;

    return dfs(l, cur) + dfs(r, cur);
  }

  int sumRootToLeaf(TreeNode *root) { return dfs(root, 0); }
```

12. [623. 在二叉树中增加一行](https://leetcode.cn/problems/add-one-row-to-tree/)

找到对应的深度，记录父节点，添加节点的时候，还需要考虑当前层的节点是父节点的左孩子还是右孩子，最后记录当前的层数。

当找到指定的层数之后，更新父节点的左儿子或者右儿子。如果当前的层数大于目标层数，直接退出。如果当前层数小于目标层数，那么递归左子树或者右子树。如果当前层数小于目标层数，并且节点为空，此时可以判定父节点不是叶子节点，直接返回。

```cpp
  void dfs(TNP root, int val, int depth, TNP p, bool is_left, int d) {
    if (depth == d) {
      if (is_left) {
        p->left = new TN(val, root, nullptr);
      } else {
        p->right = new TN(val, nullptr, root);
      }
      return;
    } else if (d > depth)
      return;

    if (!root) {
      return;
    }
    auto [_, l, r] = *root;
    dfs(l, val, depth, root, true, d + 1);
    dfs(r, val, depth, root, false, d + 1);
  }

  TreeNode *addOneRow(TreeNode *root, int val, int depth) {
    if (depth == 1) {
      TNP res = new TN(val, root, nullptr);
      return res;
    }
    dfs(root, val, depth, NULL, false, 1);

    return root;
  }
```

其实这道题目并不太需要父节点的信息，因此我们可以直接找到 depth - 1 层，对这层的每个节点添加新的子节点即可。此时可以维护更少的信息。

当找到 depth - 1 层时，更新当前节点并返回。如果当前深度大于 depth - 1，此时不需要更新下面的所有节点，直接返回。否则递归左右子树。这种做法遇到空节点直接返回，因为给定的 depth - 1 小于等于树的高度。

```cpp
  void dfs(TNP root, int val, int depth, int d) {
    if (!root)
      return;

    if (d == depth - 1) {
      auto [_, l, r] = *root;
      root->left = new TN(val, l, nullptr);
      root->right = new TN(val, nullptr, r);

      return;
    } else if (d >= depth)
      return;

    auto [_, l, r] = *root;
    dfs(l, val, depth, d + 1);
    dfs(r, val, depth, d + 1);
  }

  TreeNode *addOneRow(TreeNode *root, int val, int depth) {
    if (depth == 1) {
      TNP res = new TN(val, root, nullptr);
      return res;
    }
    dfs(root, val, depth, 1);
    return root;
  }
```

另外一种做法是使用 BFS，涉及到树的深度，BFS 是一种比较通用的做法，事实上代码写起来比 DFS 更清晰。

```cpp
  TreeNode *addOneRow(TreeNode *root, int val, int depth) {
    if (depth == 1) {
      TNP res = new TN(val, root, nullptr);
      return res;
    }

    using PPI = pair<TNP, int>;
    queue<PPI> q;
    q.push({root, 1});

    while (nemp(q)) {
      auto [p, d] = q.front();
      q.pop();
      if (d > depth - 1)
        continue;
      else if (d < depth - 1) {
        auto [_, l, r] = *p;
        if (l)
          q.push({l, d + 1});
        if (r)
          q.push({r, d + 1});
      } else {
        auto [_, l, r] = *p;
        p->left = new TN(val, l, nullptr);
        p->right = new TN(val, nullptr, r);
      }
    }

    return root;
  }
```

题解评论区看到的神奇写法。递归的过程中不断递减 depth，直到 depth = 1，此时应该新建一个节点，新建节点的子节点就是当前节点。dfs 返回修改后的树的根。如果 depth < 1，说明当前节点以及下面的节点都不需要修改，直接返回原节点。否则把当前节点的左右子树修改为 dfs 的结果。

由于新建节点的时候需要直到当前节点是父节点的左子树还是右子树，因此需要在参数中加一个标记。

同样的，如果当前节点是空并且父节点不是叶子节点，直接返回。如果当前节点是空，并且父节点是叶子节点的情况，在 depth == 1 的情况处理过了。

好像这种新增节点或者带修改节点题目都可以用类似的思路解决。链表类的题目也有类似的递归解法。

```cpp
  TNP dfs(TNP root, int val, int depth, bool is_left) {
    if (depth == 1) {
      if (is_left)
        return new TN(val, root, nullptr);
      else
        return new TN(val, nullptr, root);
    }
    if (depth < 1)
      return root;
    if (!root)
      return root;

    root->left = dfs(root->left, val, depth - 1, true);
    root->right = dfs(root->right, val, depth - 1, false);
    return root;
  }

  TreeNode *addOneRow(TreeNode *root, int val, int depth) {
    return dfs(root, val, depth, true);
  }
```

13. [1372. 二叉树中的最长交错路径](https://leetcode.cn/problems/longest-zigzag-path-in-a-binary-tree/)

考虑维护 zigzag 路径中的节点数量。考虑到达当前节点是左走还是右走，维护到达当前节点的最长路径的点的数量。如果当前节点是父节点的左儿子，当它往左儿子走的时候，路径点数回到初始值 2。当它往右儿子走的时候，路径点数 +1。如果当前节点是父节点的右儿子同理。

因为最长路径的终点可能是树中的某个节点，因此在递归到每个节点处都需要更新答案。

```cpp
  int ans;

  void dfs(TNP root, bool is_left, int cur) {
    if (!root) {
      return;
    }

    auto [_, l, r] = *root;
    if (is_left) {
      if (r) {
        dfs(r, false, cur + 1);
        ckmax(ans, cur + 1);
      }
      if (l) {
        dfs(l, true, 2);
        ckmax(ans, 2);
      }
    } else {
      if (l) {
        dfs(l, true, cur + 1);
        ckmax(ans, cur + 1);
      }
      if (r) {
        dfs(r, false, 2);
        ckmax(ans, 2);
      }
    }
  }

  int longestZigZag(TreeNode *root) {
    if (!root)
      return 0;

    ans = 1;

    if (root->left)
      dfs(root->left, true, 2);
    if (root->right)
      dfs(root->right, false, 2);
    return ans - 1;
  }
```

评论区看到的神奇写法。
思路是维护到达当前节点时，左走和右走的长度 l 和 r。如果到左儿子，那么此时到达左儿子的路径长度是 l = r + 1, r = 0。到达右儿子同理。

这道题目是树形 DP 的思路。当前状态只能由上一个状态得到，状态转移方程很简单。

```cpp
  int ans;

  void dfs(TNP root, int l, int r) {
    ckmax(ans, max(l, r));

    if (root->left)
      dfs(root->left, r + 1, 0);
    if (root->right)
      dfs(root->right, 0, l + 1);
  }

  int longestZigZag(TreeNode *root) {
    ans = 0;
    dfs(root, 0, 0);
    return ans;
  }
```

14. [971. 翻转二叉树以匹配先序遍历](https://leetcode.cn/problems/flip-binary-tree-to-match-preorder-traversal/)

先序遍历需要先访问根，对于给定的数组，如果第一个元素和根不同，那么肯定不匹配。否则访问左右子树，题目有一个很明显的条件，树中的每个节点互不相同，数组中的每个元素互不相同，因此从根开始，只能走左边或者走右边，如果都不能走，说明不匹配。如果走左边，那么不需要翻转根，如果走右边，那么需要翻转根。

访问完左子树之后，再访问右子树。因为我们需要在访问的过程中记录当前应该匹配数组中的哪个元素，因此参数使用引用。

```cpp
class Solution {
public:
  VI a;
  VI ans;
  bool ok;
  int n;

  bool dfs(TNP root, int &idx) {
    if (!root || idx == n)
      return true;

    auto [val, l, r] = *root;
    if (!ok)
      return false;

    if (val != a[idx]) {
      return ok = false;
    } else {
      if (l && l->val == a[idx + 1]) {
        bool lb = dfs(l, ++idx);
        bool rb = true;
        if (r)
          rb = dfs(r, ++idx);
        return ok = lb && rb;
      } else if (r && r->val == a[idx + 1]) {
        if (l)
          ans.pb(val);

        bool rb = dfs(r, ++idx);
        bool lb{true};
        if (l)
          lb = dfs(l, ++idx);
        return lb && rb;
      } else if (!l && !r)
        return true;
      else
        return ok = false;
    }
  }

  vector<int> flipMatchVoyage(TreeNode *root, vector<int> &voyage) {
    ans = VI{};
    ok = true;
    a = voyage;
    n = SZ(a);
    int idx{};

    dfs(root, idx);
    if (!ok)
      ans = VI{-1};

    return ans;
  }
```

题解区另外一个比较好的写法。只有左子树存在并且值不等于数组中下一个值的时候，此时必定需要翻转根。`idx` 只在和根比较完之后递增，其他的时候不需要改变。

> 当条件 `l && l->val != a[idx]` 不满足的时候，不一定需要翻转，因为如果此时左子树为空。

```cpp
  VI a, ans;

  bool dfs(TNP root, int &idx) {
    if (!root)
      return true;
    auto [val, l, r] = *root;

    if (val != a[idx])
      return false;
    idx++;

    if (l && l->val != a[idx]) {
      ans.pb(a[idx - 1]);
      return dfs(r, idx) && dfs(l, idx);
    } else {
      return dfs(l, idx) && dfs(r, idx);
    }
  }

  vector<int> flipMatchVoyage(TreeNode *root, vector<int> &voyage) {
    a = voyage;
    int idx = 0;
    if (!dfs(root, idx)) {
      return {-1};
    }
    return ans;
  }
```
