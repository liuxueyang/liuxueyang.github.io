---
layout: post
title: "在 Emacs 中把时间戳转换成日期"
date: 2020-06-16 20:19:04 +0800
tags: elisp Emacs GNU
---

工作中经常有这样的需求，每次去工具网站上转换太麻烦，在 Emacs 中转换更方便：

```elisp
(defun ts-to-date (arg ts)
  "convert timestamp to date string"
  (interactive "P\nnEnter Timestamp(ms or s): ")
  (message
   (if (zerop (% ts 1000))
       (format-time-string "%Y-%m-%d %H:%M:%S %z" (/ ts 1000))
     (format-time-string "%Y-%m-%d %H:%M:%S %z" ts))))
```
