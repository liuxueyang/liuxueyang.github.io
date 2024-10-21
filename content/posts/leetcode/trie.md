+++
title = '【题单】字典树基础'
date = 2024-10-21T21:49:55+08:00
tags = [ "Trie" ]
categories = [ "LeetCode" ]
+++

[数据结构题单](https://leetcode.cn/circle/discuss/mOr1u6/)

1. [208. 实现 Trie (前缀树)](https://leetcode.cn/problems/implement-trie-prefix-tree/)

总共有 $3 \cdot 10^4$ 次插入，每个单词长度 $2000$，字母个数最多是 $6 \cdot 10^7$ 个，考虑到前缀重复的情况，估算字典树中的节点是 $3 \cdot 10^5$ 个

```cpp
const int N = 300100;

struct TrieTree {
  int n, idx;
  vector<VI> son;
  VI cnt;

  TrieTree() {}
  TrieTree(int _n) : n(_n), idx(0) {
    son = vector<VI>(n, VI(26, -1));
    cnt = VI(n, 0);
  }

  void insert(string &s) {
    int p = 0;
    for (auto c : s) {
      int u = c - 'a';
      if (son[p][u] == -1)
        son[p][u] = ++idx;
      p = son[p][u];
    }
    cnt[p]++;
  }

  bool search(string &s) {
    int p = 0;
    for (auto c : s) {
      int u = c - 'a';
      if (son[p][u] == -1)
        return false;
      p = son[p][u];
    }
    return cnt[p] > 0;
  }

  bool starts_with(string &s) {
    int p = 0;
    for (auto c : s) {
      int u = c - 'a';
      if (son[p][u] == -1)
        return false;
      p = son[p][u];
    }
    return true;
  }
};

class Trie {
public:
  TrieTree tr;
  Trie() { tr = TrieTree(N); }

  void insert(string word) { tr.insert(word); }

  bool search(string word) { return tr.search(word); }

  bool startsWith(string prefix) { return tr.starts_with(prefix); }
};
```

更好的做法是使用动态创建节点的方式，避免估算不准确。

```cpp
class Trie {
public:
  struct node {
    int cnt;
    vector<struct node *> son;

    node() {
      cnt = 0;
      son = vector<node *>(26);
    }
  };

  node *root;

  Trie() { root = new node(); }

  void insert(string s) {
    node *p = root;

    for (auto c : s) {
      int id = c - 'a';
      if (!p->son[id])
        p->son[id] = new node();
      p = p->son[id];
    }
    p->cnt++;
  }

  bool search(string s) {
    node *p = root;

    for (auto c : s) {
      int id = c - 'a';
      if (!p->son[id])
        return false;
      p = p->son[id];
    }
    return p->cnt > 0;
  }

  bool startsWith(string s) {
    node *p = root;

    for (auto c : s) {
      int id = c - 'a';
      if (!p->son[id])
        return false;
      p = p->son[id];
    }
    return true;
  }
};
```

2. [211. 添加与搜索单词 - 数据结构设计](https://leetcode.cn/problems/design-add-and-search-words-data-structure/)

这道题目复杂度是 $26^{25}$

插入的单词中只有英文小写字母。
查找的单词中包含字符 `.`，枚举 `.` 的每种可能，在字典树上 dfs。当恰好找到能够匹配的完整的单词的时候返回 `true`，当到达字符串的最后一个字符的时候，判断当前字典树的结点是否是某个单词的终止结点。

```cpp
class WordDictionary {
public:
  struct node {
    int cnt;
    vector<node *> son;

    node() { cnt = 0, son = vector<node *>(26); }
  };

  node *root;

  WordDictionary() { root = new node(); }

  void addWord(string s) {
    node *p = root;

    for (auto c : s) {
      int id = c - 'a';
      if (!p->son[id])
        p->son[id] = new node();
      p = p->son[id];
    }
    p->cnt++;
  }

  bool dfs(string &s, int idx, node *p) {
    bool ok = (idx + 1 == SZ(s));

    if (s[idx] == '.') {
      For(i, 0, 26) {
        auto child = p->son[i];
        if (!child)
          continue;

        if (ok) {
          if (child->cnt > 0)
            return true;
        } else {
          auto res = dfs(s, idx + 1, child);
          if (res)
            return true;
        }
      }
    } else {
      int id = s[idx] - 'a';

      auto child = p->son[id];
      if (!child)
        return false;

      if (ok) {
        return child->cnt > 0;
      }

      return dfs(s, idx + 1, child);
    }
    return false;
  }

  bool search(string s) {
    node *p = root;
    return dfs(s, 0, p);
  }
};
```

题解区更好的写法。

其实不需要当前结点是否是最后一个结点，当下标到达字符串的最后一个结点的下一个结点的时候，此时指针 `p` 恰好指向的是查找字符串的上一个结点，只需要判断 `p` 是否是某个字符串的终止结点即可。这样可以少写很多条件判断。

```cpp
class WordDictionary {
public:
  struct node {
    int cnt;
    vector<node *> son;

    node() { cnt = 0, son = vector<node *>(26); }
  };

  node *root;

  WordDictionary() { root = new node(); }

  void addWord(string s) {
    node *p{root};
    for (auto c : s) {
      int id = c - 'a';
      if (!p->son[id])
        p->son[id] = new node();
      p = p->son[id];
    }
    p->cnt++;
  }

  bool dfs(string &s, int idx, node *p) {
    if (idx == SZ(s))
      return p->cnt > 0;

    if (s[idx] == '.') {
      For(i, 0, 26) {
        auto child = p->son[i];
        if (!child)
          continue;
        auto res = dfs(s, idx + 1, child);
        if (res) {
          return true;
        }
      }
    } else {
      int id = s[idx] - 'a';
      auto child = p->son[id];
      if (!child)
        return false;
      return dfs(s, idx + 1, child);
    }
    return false;
  }
  bool search(string s) {
    return dfs(s, 0, root);
  }
};
```

3. [14. 最长公共前缀](https://leetcode.cn/problems/longest-common-prefix/)

这道题目的常规做法是暴力。

也可以使用字典树，先把所有的字符串插入到字典树，插入的过程中记录每个结点被多少字符串包含。要寻找最长的公共前缀，只需要从根结点开始，如果包含当前结点的字符串数量和全部字符串数量相等，那么当前结点是公共前缀的一部分。

```cpp
class Solution {
public:
  struct node {
    int cnt;
    vector<node *> son;

    node() { cnt = 0, son = vector<node *>(26); }
  };

  node *root;
  int sz;

  void insert(string &s) {
    node *p{root};

    p->cnt++;
    for (auto c : s) {
      int id = c - 'a';
      if (!p->son[id])
        p->son[id] = new node();
      p = p->son[id];
      p->cnt++;
    }
  }

  string find_common() {
    string ans;
    node *p{root};

    while (true) {
      bool ok{false};

      For(i, 0, 26) {
        if (!p->son[i])
          continue;

        auto child = p->son[i];
        if (child && child->cnt == sz) {
          ok = true;
          ans += ('a' + i);
          p = child;
          break;
        }
      }
      if (!ok)
        break;
    }
    return ans;
  }

  string longestCommonPrefix(vector<string> &ss) {
    root = new node();
    sz = SZ(ss);

    for (auto &s : ss)
      insert(s);
    return find_common();
  }
};
```

4. [648. 单词替换](https://leetcode.cn/problems/replace-words/)

对于给定的单词，如果不存在对应的前缀时，直接返回原来的单词。

先把词根插入到字典树，对于给定的单词，在字典树中找到第一个匹配的词根。

```cpp
class Solution {
public:
  struct node {
    int cnt;
    vector<node *> son;

    node() {
      cnt = 0;
      son = vector<node *>(26);
    }
  };

  node *root;

  void insert(string &s) {
    node *p{root};

    for (auto c : s) {
      int id = c - 'a';
      if (!p->son[id])
        p->son[id] = new node();
      p = p->son[id];
    }
    p->cnt++;
  }

  string search(string &s) {
    node *p{root};
    string ans;

    for (auto c : s) {
      ans += c;
      int id = c - 'a';
      if (!p->son[id])
        return s;
      p = p->son[id];
      if (p->cnt)
        return ans;
    }

    return ans;
  }

  string replaceWords(vector<string> &dictionary, string sentence) {
    root = new node();
    string ans;

    for (auto &s : dictionary)
      insert(s);

    stringstream ss(sentence);
    string tmp;
    while (ss >> tmp) {
      auto t = search(tmp);
      if (ans.empty())
        ans = t;
      else
        ans += " " + t;
    }

    return ans;
  }
};
```

5. [677. 键值映射](https://leetcode.cn/problems/map-sum-pairs/)

这道题目的数据范围比较小，感觉查询的时候在字典树上暴力查询也可以。

下面是一种更好的做法。
新建字典树，插入每个键值对，键值只保存在键对应的终止结点。同时结点中还需要保存 `sum`，保存以到当前结点的字符串为前缀的所有键值对的值的和。

考虑如何维护 `sum`，一个常见的技巧是当插入一个结点的时候，如果当前结点被更新，那么把当前结点产生的增量 `delta` 更新到这个结点的所有祖先结点上，实现的时候可以使用递归，也可以使用栈或者任意集合保存当前结点的所有祖先结点。这样查找函数只需要找到 `prefix` 对应的终止结点，`sum` 就是所求，如果找不到 `prefix` 应该返回 0.

```cpp
class MapSum {
public:
  struct node {
    int cnt, val, sum;
    vector<node *> son;

    node() {
      cnt = val = sum = 0;
      son = vector<node *>(26);
    }
  };

  node *root;

  MapSum() { root = new node(); }

  void insert(string s, int val) {
    node *p{root};
    stack<node *> stk;

    stk.push(p);
    for (auto c : s) {
      int id = c - 'a';
      if (!p->son[id])
        p->son[id] = new node();
      p = p->son[id];
      stk.push(p);
    }

    int delta = 0;
    if (p->cnt) {
      int old = p->val;
      delta = val - old;
    } else
      delta = val;

    p->cnt++;
    p->val = val;

    while (nemp(stk)) {
      p = stk.top();
      p->sum += delta;
      stk.pop();
    }
  }

  int sum(string s) {
    node *p{root};

    for (auto c : s) {
      int id = c - 'a';
      if (!p->son[id])
        return 0;
      p = p->son[id];
    }

    return p->sum;
  }
};
```

6. [720. 词典中最长的单词](https://leetcode.cn/problems/longest-word-in-dictionary/)

把单词都插入字典树，要判定一个单词是否满足题意，只需要检查单词中的每个字母在字典树上都是一个终止结点。找到长度最大的单词，并且字典序最小，维护答案即可。

```cpp
  struct node {
    int cnt;
    vector<node *> son;

    node() { cnt = 0, son = vector<node *>(26); }
  };

  node *root;

  void insert(string &s) {
    node *p{root};

    for (auto c : s) {
      int id = c - 'a';
      if (!p->son[id])
        p->son[id] = new node();
      p = p->son[id];
    }

    p->cnt++;
  }

  bool check(string &s) {
    node *p{root};

    for (auto c : s) {
      int id = c - 'a';
      if (!p->son[id])
        return false;
      p = p->son[id];
      if (!p->cnt)
        return false;
    }

    return true;
  }

  string longestWord(vector<string> &ss) {
    root = new node();

    for (auto &s : ss)
      insert(s);

    string ans{};
    bool ok{false};
    int len{};

    for (auto &s : ss) {
      if (check(s)) {
        if (!ok) {
          ok = true;
          ans = s;
          len = SZ(ans);
        } else {
          int cur = SZ(s);
          if (cur > len) {
            ans = s, len = cur;
          } else if (cur == len) {
            ckmin(ans, s);
          }
        }
      }
    }

    return ans;
  }
```

7. [1268. 搜索推荐系统](https://leetcode.cn/problems/search-suggestions-system/)

先考虑最暴力的方法。

先把单词都插入字典树，在遍历给定的单词的过程中，从每个结点开始在字典树上进行搜索，找到字典序最小的三个字符串。这个做法的复杂度是 $2 \cdot 10^7$，是勉强可以过的。

```cpp
class Solution {
public:
  struct node {
    int cnt;
    vector<node *> son;

    node() { cnt = 0, son = vector<node *>(26); }
  };

  node *root;

  void insert(string &s) {
    node *p{root};

    for (auto c : s) {
      int id = c - 'a';
      if (!p->son[id])
        p->son[id] = new node();
      p = p->son[id];
    }

    p->cnt++;
  }

  void dfs(node *p, string cur, vector<string> &ans) {
    if (SZ(ans) >= 3)
      return;

    For(i, 0, 26) {
      auto child = p->son[i];
      if (!child)
        continue;
      if (child->cnt && SZ(ans) < 3) {
        ans.pb(cur + char('a' + i));
      }
      dfs(child, cur + char('a' + i), ans);
    }
  }

  vector<vector<string>> search(string s) {
    node *p{root};
    vector<vector<string>> ans;
    string cur;
    int n{SZ(s)};

    For(i, 0, n) {
      int id = s[i] - 'a';
      if (!p->son[id]) {
        For(j, i, n) ans.pb({});
        return ans;
      }
      cur += s[i];
      p = p->son[id];

      vector<string> res{};
      if (p->cnt)
        res.pb(cur);
      dfs(p, cur, res);
      ans.pb(res);
    }

    return ans;
  }

  vector<vector<string>> suggestedProducts(vector<string> &ss,
                                           string searchWord) {
    root = new node();

    for (auto &s : ss) {
      insert(s);
    }

    return search(searchWord);
  }
};
```

题解区的好做法。

注意到我们只需要找到 3 个前缀和给定单词相同的字符串，这是一个很小的范围，我们可以考虑在每个结点上维护这个信息：暴力维护以当前结点为前缀的字典序最小的三个字符串，使用 `vector` 即可。这种在字典树上暴力维护小范围数据的方法很常见，之前 AtCoder 也出现过。

当然也有别的维护这个信息的方式，采用一种好写的即可。

```cpp
class Solution {
public:
  struct node {
    int cnt;
    vector<node *> son;
    vector<string> can;

    node() {
      cnt = 0, son = vector<node *>(26);
      can = {};
    }
  };

  node *root;

  void insert(string &s) {
    node *p{root};

    for (auto c : s) {
      int id = c - 'a';
      if (!p->son[id])
        p->son[id] = new node();

      p = p->son[id];

      p->can.pb(s);
      sort(all(p->can));
      if (SZ(p->can) > 3)
        p->can.resize(3);
    }

    p->cnt++;
  }

  vector<vector<string>> search(string s) {
    node *p{root};
    vector<vector<string>> ans;
    string cur;
    int n{SZ(s)};

    For(i, 0, n) {
      int id = s[i] - 'a';
      if (!p->son[id]) {
        For(j, i, n) ans.pb({});
        return ans;
      }
      cur += s[i];
      p = p->son[id];

      ans.pb(p->can);
    }

    return ans;
  }

  vector<vector<string>> suggestedProducts(vector<string> &ss,
                                           string searchWord) {
    root = new node();

    for (auto &s : ss) {
      insert(s);
    }

    return search(searchWord);
  }
};
```

8. [1233. 删除子文件夹](https://leetcode.cn/problems/remove-sub-folders-from-the-filesystem/)

如果 `x` 是 `y` 的子文件夹，那么 `y` 是 `x` 的前缀。这不是充要条件，样例中有一个反例：`y = /a/b/c` 和 `x = /a/b/ca`，此时 `y` 是 `x` 的前缀，但是却不是子文件夹。

为了解决这个问题，不妨在文件夹后面统一添加一个 `/` 代表文件夹的结尾。
此时为了判断子文件夹，只需要判断在 `/` 的结点上是否是某个字符串的终止即可。

为了处理方便，不妨先把数组排序，这样父文件夹一定在前面，把每个字符串插入到字典树，插入当前字符串的过程中，遇到了父文件夹，此时不插入当前结点。插入成功的就是答案。

```cpp
class Solution {
public:
  struct node {
    int cnt;
    vector<node *> son;

    node() { cnt = 0, son = vector<node *>(128); }
  };

  node *root;

  bool insert(string &s) {
    node *p{root};

    for (auto c : s) {
      int id = int(c);
      if (!p->son[id])
        p->son[id] = new node();
      p = p->son[id];
      if (p->cnt && c == '/')
        return false;
    }

    int id = int('/');
    if (!p->son[id])
      p->son[id] = new node();
    p = p->son[id];

    p->cnt++;
    return true;
  }

  vector<string> removeSubfolders(vector<string> &ss) {
    vector<string> ans;
    root = new node();
    sort(all(ss));

    for (auto &s : ss) {
      if (insert(s))
        ans.pb(s);
    }
    return ans;
  }
};
```

题解区有一个排序的做法。

思路是排序+双指针。
先把字符串排序，父文件夹在前面，如果 `i` 指向的字符串是 `j` 指向的字符串的前缀，并且 `j` 的下一个字符是 `/`，此时 `j` 指向的字符串是子文件夹。如果 `j` 不是 `i` 的子文件夹，此时把 `i` 移动到 `j`。

```cpp
  vector<string> removeSubfolders(vector<string> &a) {
    sort(all(a));
    vector<string> ans;

    int n{SZ(a)};
    ans.pb(a[0]);

    for (int i = 0, j = 1; j < n; ++j) {
      int len = SZ(a[i]);
      if (SZ(a[j]) > len && a[j].substr(0, len) == a[i] && a[j][len] == '/')
        continue;

      ans.pb(a[j]);
      i = j;
    }
    return ans;
  }
```

9. [820. 单词的压缩编码](https://leetcode.cn/problems/short-encoding-of-words/)

为了让答案字符串的长度最小，需要尽可能复用相同的后缀。不妨把所有的字符串逆序这样问题转化成了需要尽可能复用前缀。然后把数组按照字典序从大到小排序，这样会先插入字典序大的字符串。

如果插入当前字符串的时候，没有新加任何结点，说明这个字符串是之前插入的某个字符串的前缀，此时这个字符串可以完全复用。

如果插入成功，此时这个字符串对答案的贡献是它的长度加一。

```cpp
class Solution {
public:
  struct node {
    int cnt;
    vector<node *> son;

    node() { cnt = 0, son = vector<node *>(26); }
  };

  node *root;

  bool insert(string &s) {
    node *p{root};
    bool ok{false};

    for (auto c : s) {
      int id = c - 'a';
      if (!p->son[id]) {
        p->son[id] = new node();
        ok = true;
      }
      p = p->son[id];
    }

    p->cnt++;
    return ok;
  }

  int minimumLengthEncoding(vector<string> &a) {
    for (auto &s : a)
      reverse(all(s));

    sort(all(a), greater<string>());

    int ans{};
    root = new node();
    for (auto &s : a) {
      if (insert(s)) {
        ans += SZ(s) + 1;
      }
    }

    return ans;
  }
};
```

因为每个字符串的长度只有 7，因此也可以暴力。

10. [2416. 字符串的前缀分数和](https://leetcode.cn/problems/sum-of-prefix-scores-of-strings/)

先把字符串全部插入字典树，记录每个结点被访问的次数，因为如果当前结点在插入的时候被访问，说明当前结点是正在插入的字符串的前缀，这正是我们要求的答案。

然后对每个字符串，在字典树查询，把访问到的结点中的次数累加起来就是答案。

> 这道题目增加过数据，在结点中存储 26 个字符的数组会超内存。把 `vector` 修改成 `map` 就可以了。

```cpp
class Solution {
public:
  struct node {
    int cnt;
    map<int, node *> son;

    node() {
      cnt = 0;
      son = {};
    }
  };

  node *root;

  void insert(string &s) {
    node *p{root};

    for (auto c : s) {
      int id = c - 'a';
      if (!p->son[id])
        p->son[id] = new node();
      p = p->son[id];
      p->cnt++;
    }
  }

  int search(string &s) {
    node *p{root};
    int ans{};

    for (auto c : s) {
      int id = c - 'a';
      p = p->son[id];
      ans += p->cnt;
    }
    return ans;
  }

  vector<int> sumPrefixScores(vector<string> &a) {
    root = new node();
    int n{SZ(a)};
    VI ans(n);

    for (auto &s : a)
      insert(s);

    For(i, 0, n) { ans[i] = search(a[i]); }

    return ans;
  }
};
```
