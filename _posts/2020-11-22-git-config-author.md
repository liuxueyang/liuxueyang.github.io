---
layout: post
title:  更改 Git Commit 的 Author
date:   2020-09-14 21:21:07 +0800
tags:   git
---

有几种方法，如果只是更改最近的提交，可以这样：

```
git commit --amend --author="John Doe <john@doe.org>"
```

如果是只更改几个 commit，使用 git rebase edit。

如果需要改很多 commit，可以使用这个脚本：

```sh
#!/usr/bin/env bash

git filter-branch --env-filter '
WRONG_EMAIL="old-email@old.com"
NEW_NAME="liuxueyang"
NEW_EMAIL="liuxueyang457@gmail.com"

if [ "$GIT_COMMITTER_EMAIL" = "$WRONG_EMAIL" ]
then
    export GIT_COMMITTER_NAME="$NEW_NAME"
    export GIT_COMMITTER_EMAIL="$NEW_EMAIL"
fi
if [ "$GIT_AUTHOR_EMAIL" = "$WRONG_EMAIL" ]
then
    export GIT_AUTHOR_NAME="$NEW_NAME"
    export GIT_AUTHOR_EMAIL="$NEW_EMAIL"
fi
' --tag-name-filter cat -- --branches --tags
```

来自 [How can I change the author name / email of a commit?](https://www.git-tower.com/learn/git/faq/change-author-name-email/)
