---
layout: post
title: "fish ls 没有颜色高亮"
date: 2020-06-18 13:17:24 +0800
tags: fish
---

原因可能是安装了 `grc` 这个 omf 插件。卸载就好了：

```shell
omf r grc
```
