---
layout: post
title: "如何下载 Coursera 课程"
date: 2020-06-17 23:25:32 +0800
tags: Coursera
---

项目地址：[coursera-dl](https://github.com/coursera-dl/coursera-dl)

推荐的安装方式：

```bash
cd /directory/where/I/want/my/courses
virtualenv my-coursera
cd my-coursera
source bin/activate
git clone https://github.com/coursera-dl/coursera-dl
cd coursera-dl
pip install -r requirements.txt
./coursera-dl -n -- suanfa-jichu
```

使用过程中遇到了 SSL 的一个错误，解决方式在[这里](https://github.com/coursera-dl/coursera-dl#sslerror-errno-1-_ssl c504-error14094410ssl-routinesssl3_read_bytessslv3-alert-handshake-failure)。

下载课程需要登录。新建文件 `~/.netrc`，输入 Coursera 的帐号密码，如下：

```
machine coursera-dl login <user> password <pass>
```

如果还有登录问题，可以使用 Cookie，参考[这里](https://github.com/coursera-dl/coursera-dl/issues/702)。
