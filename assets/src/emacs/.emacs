;; Emacs Rocks!

;; add this to .zshrc or .bashrc
;; alias clean-emacs="HOME=$HOME/workspace/clean-emacs /usr/local/bin/emacs "

(setq package-archives '(("gnu"   . "http://elpa.emacs-china.org/gnu/")
                         ("melpa" . "http://elpa.emacs-china.org/melpa/")))

(defun paste-to-osx (text &optional push)
  (let ((process-connection-type nil))
    (let ((proc (start-process "pbcopy" "*Messages*" "pbcopy")))
      (process-send-string proc text)
      (process-send-eof proc))))

(setq interprogram-cut-function 'paste-to-osx)

(defun copy-from-osx ()
  (shell-command-to-string "pbpaste"))

(setq interprogram-paste-function 'copy-from-osx)

(message "Hello World")

(setq template-algorithm "// insert algorithm
")

(defun algorithm ()
  (interactive)
  (insert template-algorithm))

(require 'yasnippet)
(yas-global-mode t)

(require 'smartparens-config)
(add-hook 'prog-mode-hook #'smartparens-mode)
(smartparens-strict-mode nil)

(custom-set-variables
 ;; custom-set-variables was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 '(package-selected-packages
   '(magit smartparens ivy-yasnippet yasnippet-snippets yasnippet)))
(custom-set-faces
 ;; custom-set-faces was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 )

(when (eq system-type 'windows-nt)
  (load-theme 'manoj-dark t)
  (set-frame-font "Source Code Pro 13"))
