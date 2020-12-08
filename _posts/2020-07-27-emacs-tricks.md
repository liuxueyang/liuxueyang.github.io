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

----

Added at: 2020年12月 8日 星期二 11时17分49秒 CST

话说平时自己的 Emacs 配置用腻了，偶尔尝试一下别人的 Emacs 配置也是很不错的体验。事实上我一直没找到比较好的方式，昨天又稍微折腾了一下，觉得以下这些方案还算是可用的，比较适合偶尔试用一些配置。

### 使用 alias

首先把对应的 Emacs 配置 clone 到对应目录的 `.emacs.d` 中，譬如：

```shell
mkdir -p ~/fun/prelude
git clone git@github.com:bbatsov/prelude.git ~/fun/prelude/.emacs.d
```

然后在 `~/.zshrc` 中配置 alias，例如：

```shell
alias prelude_emacs="env HOME=$HOME/fun/prelude/ emacs &"
```

这个方法的好处是各个 Emacs 互相不影响，缺点是 HOME 在 Emacs 中被改变了，不过对于临时尝试来说，是够用了。

### 使用 emacs bootloader

参考这个项目 [chemacs][chemacs]。如果想要长期使用多个配置，只是偶尔想要更换配置的话，可以使用这个项目。具体方法在项目的 `README.org` 中有比较详细的说明。

----

最近我在使用 Spacemacs，加上了非常少的一些个性化的配置，写 6.824 的作业还是非常舒服的。不是很想维护自己的配置了，毕竟这个要想配置得很舒服还是太花时间了，总是感觉不好用，还不如在 Spacemacs 的基础上配置一个相对好用的开发环境省事。可能是人老了，折腾不动了。

偶尔也使用上面的方法尝试一下有趣的配置，比如写这篇博客正在使用的 [elegant-emacs][elegant-emacs]，如图：

![Elegant Emacs](/assets/2020-12-08-am-11.35.02-elegant-emacs.png)

这种配置看起来就很漂亮，清爽，适合做一些比较轻量的文本编辑（例如写博客、写笔记）的事情。

[dired-sort]: https://www.gnu.org/software/emacs/manual/html_node/emacs/Dired-Updating.html
[sort-lines]: http://pragmaticemacs.com/emacs/sort-lines-in-a-region/
[chemacs]: https://github.com/plexus/chemacs
[elegant-emacs]: https://github.com/rougier/elegant-emacs
