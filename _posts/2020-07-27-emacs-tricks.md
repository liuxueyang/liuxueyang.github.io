---
layout: post
title:  Emacs 技巧集锦
date:   2020-07-27 11:00:57 +0800
tags:   Emacs
---

收集一些 Emacs 的技巧，经常学习到某个技巧之后，过一段时间就忘记了。

在 dired 模式下，可以按`s`键切换文件的时间、字母序排序。[帮助文档][dired-sort]

使用`sort-lines`或者`sort-numeric-fields`函数来排序 region 中的行。[博客][sort-lines]

    The files in a Dired buffers are normally listed in alphabetical order by file names. Alternatively Dired can sort them by date/time. The Dired command s (dired-sort-toggle-or-edit) switches between these two sorting modes. The mode line in a Dired buffer indicates which way it is currently sorted—by name, or by date.

在有些 buffer 中，可以使用`C-x C-q`打开编辑模式，做一些编辑，然后`C-c C-c`提交编辑结果。使用这个技巧可以使用`counsel-git-grep`搜索，然后`C-c C-o`进入搜索结果的 buffer，然后`C-x C-q`进入编辑模式，这样就可以对搜索结果做比较灵活的变更。

[dired-sort]: https://www.gnu.org/software/emacs/manual/html_node/emacs/Dired-Updating.html
[sort-lines]: http://pragmaticemacs.com/emacs/sort-lines-in-a-region/
