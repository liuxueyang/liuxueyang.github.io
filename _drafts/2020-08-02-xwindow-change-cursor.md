---
layout: post
title:  Change cursor theme for X Window on Slackware
date:   2020-08-02 08:37:04 +0800
---

System-wide configuration, create/edit file: `/usr/share/icons/default/index.theme`:

```config
[Icon Theme]
Name = redglass
Inherits = redglass
```

For single user, create/edit file: `~/.icons/default/index.theme`:

```config
[icon theme]
Inherits=redglass
```

For GTK-2.0 or GTK-3.0 applications, create/edit file: `~/.config/gtk-2.0/settings.ini` and `~/.config/gtk-3.0/settings.ini`:

```config
[Settings]
gtk-theme-name=redglass
gtk-cursor-theme-name=redglass
```

Add config to `~/.Xresources`:

```config
Xcursor.theme: redglass
```

Add config to `~/.xprofile`:

```config
xrdb ~/.Xresources
```

System-wide icon themes path: `/usr/share/icons`. User-wide icon themes path: `~/.local/share/icons`
