;; Emacs Rocks!

;; add this to .zshrc or .bashrc
;; alias clean-emacs="HOME=$HOME/workspace/clean-emacs /usr/local/bin/emacs "

(global-linum-mode)

(setq package-archives '(("gnu"   . "http://elpa.emacs-china.org/gnu/")
                         ("melpa" . "http://elpa.emacs-china.org/melpa/")))

(defun paste-to-osx (text &optional push)
  (let ((process-connection-type nil))
    (let ((proc (start-process "pbcopy" "*Messages*" "pbcopy")))
      (process-send-string proc text)
      (process-send-eof proc))))

(defun paste-to-win (text &optional push)
  (let ((process-connection-type nil))
    (let ((proc (start-process "clip.exe" "*Messages*" "clip.exe")))
      (process-send-string proc text)
      (process-send-eof proc))))

(defun copy-from-osx ()
  (shell-command-to-string "pbpaste"))

(defun copy-from-win ()
  (shell-command-to-string "powershell.exe Get-Clipboard"))

(when (eq system-type 'darwin)
  (setq interprogram-paste-function 'copy-from-osx)
  (setq interprogram-cut-function 'paste-to-osx))

(when (eq system-type 'windows-nt)
  (load-theme 'manoj-dark t)
  (set-frame-font "Source Code Pro 13"))

(when (eq system-type 'cygwin)
    (setq interprogram-paste-function 'copy-from-win)
    (setq interprogram-cut-function 'paste-to-win))

(use-package yasnippet
	     :ensure t)

(require 'yasnippet)
(yas-global-mode t)

(use-package smartparens
	     :ensure t)

(require 'smartparens-config)
(add-hook 'prog-mode-hook #'smartparens-mode)
(smartparens-strict-mode nil)

(defun xah-html-escape-char-to-entity (@begin @end &optional @entity-to-char-p)
  "Replace HTML chars & < > to HTML entities on current text block or selection.
The string replaced are:
 & ⇒ &amp;
 < ⇒ &lt;
 > ⇒ &gt;

Highlight changed places.
If `universal-argument' is called first, the replacement direction is reversed.

When called in lisp code, @begin @end are region begin/end positions. If @entity-to-char-p is true, reverse change direction.

URL `http://ergoemacs.org/emacs/elisp_replace_html_entities_command.html'
Version 2020-08-30"
  (interactive
   (save-excursion
     (list
      (if (use-region-p)
          (region-beginning)
        (progn
          (re-search-backward "\n[ \t]*\n" nil "move")
          (re-search-forward "\n[ \t]*\n" nil "move")
          (point)))
      (if (use-region-p)
          (region-end)
        (progn
          (re-search-forward "\n[ \t]*\n" nil "move")
          (re-search-backward "\n[ \t]*\n" nil "move")
          (point)))
      (if current-prefix-arg t nil))))
  (let (($changedItems '())
        ($findReplaceMap
         (if @entity-to-char-p
             ;; this to prevent creating a replacement sequence out of blue
             [
              ["&amp;" "螽⛫1"] ["&lt;" "螽⛫2"] ["&gt;" "螽⛫3"]
              ["螽⛫1" "&"] ["螽⛫2" "<"] ["螽⛫3" ">"]
              ]
           [ ["&" "&amp;"] ["<" "&lt;"] [">" "&gt;"] ]
           )))
    (save-excursion
      (save-restriction
        (narrow-to-region @begin @end)
        (let ( (case-fold-search nil))
          (mapc
           (lambda ($x)
             (goto-char (point-min))
             (while (search-forward (elt $x 0) nil t)
               (push (format "%s %s" (point) $x) $changedItems)
               (replace-match (elt $x 1) "FIXEDCASE" "LITERAL")
               (overlay-put (make-overlay (- (point) (length (elt $x 1))) (point)) 'font-lock-face '(:foreground "red"))))
           $findReplaceMap))))))

(custom-set-variables
 ;; custom-set-variables was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 '(package-selected-packages
   '(0x0 magit smartparens ivy-yasnippet yasnippet-snippets yasnippet)))
(custom-set-faces
 ;; custom-set-faces was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 )
