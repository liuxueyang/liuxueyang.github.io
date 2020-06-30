---
layout: post
title:  Emacs 在中英文之间插入空白
date:   2020-06-30 20:05:49 +0800
tags:   Emacs
---

之前使用过 pangu-spacing 这个插件，后来换了 Emacs 配置，就没再用了，中英文之间的空格就完全靠手打，过了一段时间感觉还是太麻烦了，所以重新配置了一下。配置如下：

```elisp
(defun pangu-custom ()
  "Real insert space."
  (set (make-local-variable 'pangu-spacing-real-insert-separtor) t))

(use-package pangu-spacing
  :ensure t
  :config
  (set (make-local-variable 'pangu-spacing-real-insert-separtor) t)
  :hook
  ((TeX-mode org-mode markdown-mode) . pangu-spacing-mode)
  :init
  (add-hook 'org-mode-hook #'pangu-custom)
  (add-hook 'TeX-mode-hook #'pangu-custom)
  (add-hook 'markdown-mode-hook #'pangu-custom))
```

只在 org, TeX, markdown 三种模式中开启这个功能。

来源：[讓你的 emacs 自動在英文與中文之間加入空白](https://coldnew.github.io/d2d60fe2/)
