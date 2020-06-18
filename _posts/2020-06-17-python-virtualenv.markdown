---
layout: post
title: "virtualenv 配置代理"
date: 2020-06-17 23:52:06 +0800
tags: Python virtualenv
---

新建文件 `~/.pip/pip.conf`:

```conf
[global]

index-url = https://pypi.tuna.tsinghua.edu.cn/simple
```
