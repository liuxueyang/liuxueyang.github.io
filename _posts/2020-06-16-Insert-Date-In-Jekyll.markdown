---
layout: post
title: "Insert Date to Jekyll header"
date: 2020-06-16 20:14:05 +0800
tags: jekyll Emacs GNU
---

使用 Jekyll 在开始一篇博客的时候，需要在 Markdown 文件的开头的 header 部分添加日期，格式类似这样：`2020-06-16 20:16:14 +0800`。每次手写太麻烦，所以写了一个 Emacs 函数：

```elisp
(defun abel-insert-ts ()
  (interactive)
  (insert (format-time-string "%Y-%m-%d %H:%M:%S %z")))
```
