---
layout: post
title:  Synchronize files using Unison
date:   2020-08-02 16:15:11 +0800
tags:   Linux
---

需求：想要在笔记本和树莓派之间实时同步文件。

本机作为客户端，树莓派作为服务器。两端的 Unison 的大版本必须一致。本机的版本是 2.51，树莓派的软件源里面的 Unison 的版本是 2.48.所以树莓派必须重新编译安装。方法也很简单，下载[源代码](https://github.com/bcpierce00/unison/releases/tag/v2.51.2)。（不过首先要安装 Ocaml 编译器）

```sh
make
mkdir ~/bin
make install
```

会把编译之后的可执行文件放到`~/bin`中，可以安装多版本，Unison 服务端也支持多版本，参见文档选项`-addversionno`。然后把可执行文件放到`$PATH`中的某个目录中，我放到了`/usr/local/bin`。如果没有 file watcher，可以使用 Unison 自带的：把源码目录中的文件`src/fsmonitor.py`也放到`/usr/local/bin`中：

```sh
sudo cp ~/bin/unison* /usr/local/bin
sudo cp unison-src/src/fsmonitor.py /usr/local/bin
```

举个例子

在本机和树莓派 Home 目录创建目录`a.tmp`

```
mkdir ~/a.tmp
```

然后在本机执行：

```sh
unison $HOME/a.tmp ssh://pi@pi-ip-addr//home/pi/a.tmp/ -repeat watch
```

此时就完成配置了。对本地的`a.tmp`目录中做更改也会同步到树莓派上。

如果想查看更高级的配置可以参阅 Unison [官方文档](https://www.cis.upenn.edu/~bcpierce/unison/download/releases/stable/unison-manual.html#afterinstall)
