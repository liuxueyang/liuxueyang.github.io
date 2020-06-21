---
layout: post
title: "Git 撤销最近的提交"
date: 2020-06-21 13:03:33 +0800
tags: Git
---

常见的场景是，对程序做了比较小的改动，使用`magit`迅速提交，发现提交错了分支，此时需要把最近做的提交撤销，做法如下：

```bash
git reset --soft HEAD~1
```

详情见[这里](https://www.git-tower.com/learn/git/faq/undo-last-commit)。

在`magit`中的做法是在`log`页面，把光标放在上一个提交，先按下`X`（代表 reset）再选择`s`（代表`soft`选项）。

然后再把改动放到`stash`中，提交到正确的分支。
