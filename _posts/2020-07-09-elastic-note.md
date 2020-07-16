---
layout: post
title:  elastic search note
date:   2020-07-09 17:31:23 +0800
---

```sh
bin/elasticsearch -E node.name=node0 -E cluster.name=cluster_name -E path.data=node0_data -d
bin/elasticsearch -E node.name=node1 -E cluster.name=cluster_name -E path.data=node1_data -d
bin/elasticsearch -E node.name=node2 -E cluster.name=cluster_name -E path.data=node2_data -d
bin/elasticsearch -E node.name=node3 -E cluster.name=cluster_name -E path.data=node3_data -d
```
