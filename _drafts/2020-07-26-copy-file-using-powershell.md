---
layout: post
title:  PowerShell 拷贝文件
date:   2020-07-26 21:27:59 +0800
---

拷贝一个目录新创建的几个文件到指定目录：

```powershell
$src_dir = "~/Workspace/powershell/tmp/a"
$dst_dir = "~/Workspace/powershell/b"

Get-ChildItem -Path $src_dir | Sort-Object CreateTime -Descending | Select-Object -First 3 | Copy-Item -Dest $dst_dir -ea 0
```
