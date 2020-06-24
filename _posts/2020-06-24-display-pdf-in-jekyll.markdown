---
layout: post
title: "在 Jekyll 中展示 PDF 文件"
date: 2020-06-24 15:54:25 +0800
tags: Jekyll
---

解决方式在[A simple pdf embedding solution for Jekyll via Google Drive](https://jamesonzimmer.com/simple-pdf-embed-for-jekyll/)

其实我没有创建`pdf`的`layout`，可以直接像下面这样插入文件：

```
<iframe src="/assets/docs/uva1291.pdf" width="100%" height="500em"></iframe>
```

效果如下：

<iframe src="/assets/docs/uva1291.pdf" width="100%" height="500em"></iframe>
