---
layout: post
title:  使用 Emacs 插件 easy-jekyll 创建 Jekyll 博客
date:   2020-06-24 18:50:15 +0800
tags: Jekyll blogging
---

这个插件的说明文档比较详细：[官方地址](https://github.com/masasam/emacs-easy-jekyll)

我只做了很少的配置:

```
(use-package easy-jekyll
  :ensure t
  :config
  (setq easy-jekyll-basedir "~/public_html/"))
```

我目前只是使用它的创建博客的功能。平常主要还是使用`magit`发布，使用原生的`github-pages`，不需要任何生成的步骤。
