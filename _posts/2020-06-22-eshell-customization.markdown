---
layout: post
title: "eshell Configuration"
date: 2020-06-22 17:43:11 +0800
tags: Emacs GNU eshell
---

在 Emacs 中做题的时候，需要一种方式快速切换到`eshell`，同时也需要快速切换回源码。添加了这些简单的配置，支持按下`f12`切换到`eshell`，并且在`eshell`中按下`f12`快速切换回之前的`buffer`。

```elisp
(global-set-key [f12] 'eshell)

(defun eshell/disable-linum ()
  "Disable line numbers."
  (display-line-numbers-mode -1))

(defun eshell/customize-binding ()
  "Customize binding for eshell."
  (define-key eshell-mode-map (kbd "<f12>") 'switch-to-prev-buffer))

(add-hook 'eshell-mode-hook
          #'eshell/disable-linum)

(add-hook 'eshell-mode-hook
          #'eshell/customize-binding)
```
