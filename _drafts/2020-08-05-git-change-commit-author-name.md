---
layout: post
title:  Change the author of a commit
date:   2020-08-05 21:04:20 +0800
tags:   Git
---

其实这个问题遇到过很多次。

我使用的是 Magit 操作，方法也很简单。从想要更改的 commit 的前一个提交开始 rebase --interactive，然后对指定的 commit 执行 e（edit）操作，然后进行 rebase，过程中按`c`，然后按`-R`（`--reset-author`），然后按`a`（`--amend`）即可。

Refer to: [How can I change the author name / email of a commit?](https://www.git-tower.com/learn/git/faq/change-author-name-email)
