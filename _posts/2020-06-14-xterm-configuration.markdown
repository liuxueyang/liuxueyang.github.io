---
layout:		post
title:		"Simple XTerm Configuration"
date:		2020-06-14 19:31:11 +0800
tags:		XTerm configuration Xwindow Linux
---

A simple XTerm configuration.

![My XTerm in FVWM](/assets/2020-06-14_XTerm_scrot.png)

{% highlight %}
XTerm*scrollBar: off
XTerm*rightScrollBar: on
XTerm*title: XTerm

! XTerm*font: 10x20
! XTerm*faceName: Monaco
XTerm*faceSize: 12
XTerm*faceName: FantasqueSansMono Nerd Font Mono
XTerm*renderFont: true

XTerm*savelines: 4000
Xterm*geometry: 120x40
XTerm*background: black
XTerm*foreground: white
XTerm*colorMode:  on
XTerm*dynamicColors:  on
XTerm*underLine:  off
XTerm*colorBDMode: on
XTerm*colorBD: cyan
XTerm*colorULMode:  on
XTerm*colorUL: magenta
XTerm*customization: -color
XTerm*reverseWrap: true
XTerm*color0: #000000
XTerm*color1: #b21818
XTerm*color2: #18b218
XTerm*color3: #BE5F00
XTerm*color4: #6D85BA
XTerm*color5: #b218b2
XTerm*color6: #18b2b2
XTerm*color7: #b2b2b2
XTerm*color8: #686868
XTerm*color9: #FF5454
XTerm*color10: #54FF54
XTerm*color11: #FFFF54
XTerm*color12: #73A5FF
XTerm*color13: #FF54FF
XTerm*color14: #54FFFF
XTerm*color15: #FFFFFF

XTerm*metaSendsEscape: true
XTerm*termName: xterm-color

XTerm*VT100.Translations: #override \
    Shift <KeyPress> Insert: insert-selection(CLIPBOARD) \n\
    Ctrl Shift <Key>V:    insert-selection(CLIPBOARD) \n\
    Ctrl Shift <Key>C:    copy-selection(CLIPBOARD) \n\
    Ctrl <Btn1Up>: exec-formatted("xdg-open '%t'", PRIMARY)

XTerm*ttyModes: erase ^?
XTerm*VT100*translations: #override \
			 <Key>BackSpace: string(0x7f)
XTerm*backarrowKeyIsErase: true
{% endhighlight %}
