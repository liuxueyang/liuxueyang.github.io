---
layout: post
title: "Magit: not inside a git repository"
---

系统升级之后，使用 magit 报如下错误：

```
user-error: Not inside a Git repository
```

查看 magit 版本：

```
Magit 2.4.1, Git (unknown), Emacs 26.3
```

一番搜索，找到了原因，相关讨论在[这里](https://emacs.stackexchange.com/questions/31868/magit-version-post-installation-does-not-look-as-in-the-manual)。原因其实是没有安装 Xcode Command line tools。参见[这里](https://tips.tutorialhorizon.com/2015/10/01/xcrun-error-invalid-active-developer-path-library-developer-commandline-tools-missing-xcrun/)。
