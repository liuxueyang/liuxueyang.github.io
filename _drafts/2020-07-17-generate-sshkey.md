---
layout: post
title:  生成 Git ssh key 和配置
date:   2020-07-17 14:27:17 +0800
tags:   git
---

命令和配置记不住，记录在这里。

生成 key：

```sh
λ ssh-keygen -t rsa -b 4096 -C "your_email_address"
```

配置 `~/.ssh/config`：

```config
Host github-customized-name
     HostName github.com
     User git
     IdentityFile ~/.ssh/id_rsa_customized_name
```
