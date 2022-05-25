---
layout:		post
title:		"Create Screenshot In Linux"
date:		2020-06-14 20:00:15 +0800
tags:		Linux screenshot scrot
---

The simple way:

{% highlight bash %}
scrot "%Y-%m-%d_scrot.png" -b -c -d 10 -q 100 -s -e 'mv $f ~/Pictures/shots/'
{% endhighlight %}

Refer to `scrot` help message for more options.
