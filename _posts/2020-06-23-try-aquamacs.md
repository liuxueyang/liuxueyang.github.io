---
layout: post
title: "Try Aquamacs"
date: 2020-06-23 17:37:29 +0800
tags: Emacs
---

这是 macos 版本的 Emacs，界面设计接近原生 macos 软件，默认支持 macos 风格的一些快捷键。想要把它的配置和 GNU Emacs 的配置分离开，在`~/.emacs`文件中这样配置：

```elisp
;; ____________________________________________________________________________
;; Aquamacs custom-file warning:
;; Warning: After loading this .emacs file, Aquamacs will also load
;; customizations from `custom-file' (customizations.el). Any settings there
;; will override those made here.
;; Consider moving your startup settings to the Preferences.el file, which
;; is loaded after `custom-file':
;; ~/Library/Preferences/Aquamacs Emacs/Preferences
;; _____________________________________________________________________________

;; Added by Package.el.  This must come before configurations of
;; installed packages.  Don't delete this line.  If you don't want it,
;; just comment it out by adding a semicolon to the start of the line.
;; You may delete these explanatory comments.
(package-initialize)

(unless (boundp 'aquamacs-version)
  (load-file "~/.emacs.d/init.el"))
```

![Default Aquamacs](/assets/2020-06-23-try-Aquamacs.png)

### Links

- [Features: Why use Aquamacs?](https://aquamacs.org/features.html)
- [For My Friends With Macs](https://formyfriendswithmacs.com/aquamacs.html)
