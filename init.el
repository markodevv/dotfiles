;; TODO
;; Goto function
;; Display function signature immediately

(package-initialize)
(add-to-list 'package-archives
  '("melpa" . "http://melpa.org/packages/"))
(add-to-list 'package-archives
   '("org" . "http://orgmode.org/elpa/"))

(setq package-list
      '(eglot company))

; install the missing packages
(dolist (package package-list)
  (unless (package-installed-p package)
    (package-install package)))

;; Backup dir for files
(setq backup-directory-alist '(("." . "~/.emacs_backup")))

(require 'compile)
(require 'dabbrev)
(require 'eglot)
(require 'company)

(add-to-list 'eglot-server-programs '(c++-mode . ("ccls")))

;Stop Emacs from losing undo information by
; setting very high limits for undo buffers
(setq undo-limit 20000000)
(setq undo-strong-limit 40000000)

; Determine the underlying operating system
(setq os_linux (featurep 'x))

(if os_linux
    (setq build-script "../build.sh")
  (setq build-script "sh ../build.sh"))
 
; Turn off menu/tool bar etc
(tool-bar-mode -1)
(menu-bar-mode -1)
(toggle-scroll-bar -1)

; Font
(set-frame-font "DejaVu Sans Mono-10.5" nil t)

; Disable bell
(defun nil-bell ())
(setq ring-bell-function 'nil-bell)

; Compilation
(setq compilation-context-lines 0)
(setq compilation-error-regexp-alist
    (cons '("^\\([0-9]+>\\)?\\(\\(?:[a-zA-Z]:\\)?[^:(\t\n]+\\)(\\([0-9]+\\)) : \\(?:fatal error\\|warnin\\(g\\)\\) C[0-9]+:" 2 3 nil (4))
     compilation-error-regexp-alist))

(defun build-project ()
  (interactive)
  (compile build-script)
  (other-window 1))

; Colored TODO, NOTE's etc
 (setq fixme-modes '(c++-mode c-mode emacs-lisp-mode))
 (make-face 'font-lock-fixme-face)
 (make-face 'font-lock-study-face)
 (make-face 'font-lock-important-face)
 (make-face 'font-lock-note-face)
 (mapc (lambda (mode)
	 (font-lock-add-keywords
	  mode
	  '(("\\<\\(TODO\\)" 1 'font-lock-fixme-face t)
	    ("\\<\\(IMPORTANT\\)" 1 'font-lock-important-face t)
            ("\\<\\(NOTE\\)" 1 'font-lock-note-face t))))
	fixme-modes)
 (modify-face 'font-lock-fixme-face "Red" nil nil t nil t nil nil)
 (modify-face 'font-lock-important-face "Yellow" nil nil t nil t nil nil)
 (modify-face 'font-lock-note-face "Dark Green" nil nil t nil t nil nil)

; Accepted file extensions and their appropriate modes
(setq auto-mode-alist
      (append
       '(("\\.cpp$"    . c++-mode)
         ("\\.inl$"    . c++-mode)
         ("\\.h$"    . c++-mode)
         ("\\.c$"   . c++-mode)
         ("\\.cc$"   . c++-mode)
         ("\\.txt$" . indented-text-mode)
         ("\\.emacs$" . emacs-lisp-mode)
         ("\\.gen$" . gen-mode)
         ("\\.ms$" . fundamental-mode)
         ) auto-mode-alist))

; CC++ mode handling
(defun my-c++-hook ()
  (setq c++-basic-offset 4)
  (c-set-offset 'substatement-open 0)
  (c-set-offset 'statement-block-intro 4)
  (c-set-offset 'substatement 4)
  (c-set-offset 'topmost-intro 0)
  (c-set-offset 'defun-block-intro 4)
  (c-set-offset 'statement-block-intro 4)
  (c-set-offset 'brace-list-intro 4)
  
  (setq c++-indent-level 4)  
  (setq tab-width 4
        indent-tabs-mode nil)
)

(electric-pair-mode 1)
(setq electric-pair-preserve-balance nil)

; Setup my compilation mode
(defun my-compilation-hook ()
  (make-local-variable 'truncate-lines)
  (setq truncate-lines nil)
  )

(add-to-list 'auto-mode-alist '("\\.h\\'" . c++-mode))
(add-hook 'c++-mode-hook 'my-c++-hook)
(add-hook 'c++-mode-hook 'eglot-ensure)

(add-hook 'compilation-mode-hook 'my-compilation-hook)

(defun toggle-comment-region()
  (interactive)
  (comment-or-uncomment-region 0 0 'region)
)

; Company
(add-hook 'after-init-hook 'global-company-mode)
(add-hook 'after-init-hook 'company-tng-mode)

(defun goto-c-function ()
  (interactive)
  ;;(setq function (read-string "Goto function: "))
  (imenu "Function"))

; Startup windowing
(setq next-line-add-newlines nil)
(setq-default truncate-lines t)
(setq truncate-partial-width-windows nil)
; Smooth scroll
(setq scroll-step 10)

(define-minor-mode nav-mode
  "Navigation mode"
  :lighter " Navigation mode "
  :keymap (make-sparse-keymap))
(nav-mode)

;; Enables nav mode globaly for every new buffer
(define-globalized-minor-mode global-nav-mode nav-mode (lambda () (nav-mode)))
(global-nav-mode)


(define-minor-mode edit-mode
  "Edit mode"
  :lighter " Edit mode "
  :keymap (make-sparse-keymap))
(edit-mode)

(defun enter-edit-mode ()
  (interactive)
  (set-cursor-color "NavajoWhite1")
  (setq-default cursor-type 'bar)
  (edit-mode)
  (nav-mode -1))

(defun enter-nav-mode ()
  (interactive)
  (set-cursor-color "NavajoWhite1")
  (setq-default cursor-type 'box) 
  (deactivate-mark)
  (nav-mode)
  (edit-mode -1)
  )

;; This is used to exit out of nav mode when calling execute-extended-command (M-x)
(defun execute-my-extended-command (&rest args)
  (interactive)
  (if (interactive-p)
      (progn
        (setq unread-command-events (cons ?i unread-command-events))
        (call-interactively #'execute-extended-command))
    (funcall #'execute-extended-command args)))

(global-set-key (kbd "M-x") #'execute-my-extended-command)


					; Insert a newline at the end and enters edit mode"
(defun newline-indent ()
  (interactive)
  (move-end-of-line nil)
  (newline-and-indent)
  (enter-edit-mode))

(defun my-copy-line ()
  (interactive)
  (save-excursion
    (back-to-indentation)
    (kill-ring-save
     (point)
     (line-end-position))))    

(defun my-kill-line ()
  (interactive)
  (kill-line)
  (enter-edit-mode))

					; scroll down half the page"
(defun scroll-half-page-down ()
  (interactive)
  (scroll-down (/ (window-body-height) 2)))

					; scroll up half the page"
(defun scroll-half-page-up ()
  (interactive)
  (scroll-up (/ (window-body-height) 2)))

(defun select-text-start ()
  (interactive)
  (set-mark-command nil))

(defun cut-region ()
  (interactive)
  (kill-region 0 0 'region)
  (enter-edit-mode))

(defun end-of-line-edit ()
  (interactive)
  (end-of-line)
  (enter-edit-mode))

(defun beginning-of-line-edit ()
  (interactive)
  (beginning-of-line-text)
  (enter-edit-mode))

(defun multiline-edit ()
  (interactive)
  (rectangle-mark-mode))


(defun switch-to-previous-buffer ()
  (interactive)
  (switch-to-buffer (other-buffer)))

					; Start emacs maximized
(add-to-list 'default-frame-alist '(fullscreen . maximized))
					; Split window at startup
(split-window-horizontally)
; Highlight marked region
(transient-mark-mode)
; Colorscheme

(set-face-attribute 'font-lock-builtin-face nil :foreground "gray69")
(set-face-attribute 'font-lock-comment-face nil :foreground "gray38")
(set-face-attribute 'region nil :background "gray25")
(set-face-attribute 'font-lock-function-name-face nil :foreground "golden rod")
(set-face-attribute 'font-lock-keyword-face nil :foreground "gray69")
(set-face-attribute 'font-lock-type-face nil :foreground "tomato")
(set-face-attribute 'font-lock-constant-face nil :foreground "gray69")

(set-foreground-color "burlywood3")
(set-background-color "#161616")
(set-cursor-color "NavajoWhite1")
 
; I-Search
(defun isearch-repeat-forward+ ()
  (interactive)
  (unless isearch-forward
    (goto-char isearch-other-end))
  (isearch-repeat-forward)
  (unless isearch-success
    (isearch-repeat-forward)))

(defun isearch-repeat-backward+ ()
  (interactive)
  (when (and isearch-forward isearch-other-end)
    (goto-char isearch-other-end))
  (isearch-repeat-backward)
  (unless isearch-success
    (isearch-repeat-backward)))

(define-key nav-mode-map (kbd "j") 'next-line)
(define-key nav-mode-map (kbd "k") 'previous-line)
(define-key nav-mode-map (kbd "l") 'forward-char)
(define-key nav-mode-map (kbd "h") 'backward-char)
(define-key nav-mode-map (kbd "w") 'forward-word)
(define-key nav-mode-map (kbd "b") 'backward-word)
(define-key nav-mode-map (kbd "I") 'beginning-of-line-edit)
(define-key nav-mode-map (kbd "A") 'end-of-line-edit)
(define-key nav-mode-map (kbd "D") 'kill-whole-line)
(define-key nav-mode-map (kbd "u") 'undo)
(define-key nav-mode-map (kbd "p") 'yank)
(define-key nav-mode-map (kbd "Y") 'my-copy-line)
(define-key nav-mode-map (kbd "o") 'newline-indent)
(define-key nav-mode-map (kbd "i") 'enter-edit-mode)
(define-key nav-mode-map (kbd "x") 'delete-char)
(define-key nav-mode-map (kbd "g g") 'beginning-of-buffer)
(define-key nav-mode-map (kbd "G") 'end-of-buffer)
(define-key nav-mode-map (kbd "C") 'my-kill-line)
(define-key nav-mode-map (kbd "v") 'select-text-start)
(define-key nav-mode-map (kbd "V") 'rectangle-mark-mode)
(define-key nav-mode-map (kbd "d") 'delete-region)
(define-key nav-mode-map (kbd "y") 'copy-region-as-kill)
(define-key nav-mode-map (kbd "c") 'cut-region)
(define-key nav-mode-map (kbd ">") 'indent-region)
(define-key nav-mode-map (kbd "M-R") 'replace-string)
(define-key nav-mode-map (kbd "/") 'isearch-forward)
(define-key nav-mode-map (kbd "M-/") 'isearch-forward-symbol-at-point)
(define-key nav-mode-map (kbd "n") 'isearch-repeat-forward+)
(define-key nav-mode-map (kbd "N") 'isearch-repeat-backward+)
(define-key nav-mode-map (kbd ":") 'goto-line)

(define-key edit-mode-map (kbd "C-v") 'yank)

(define-key global-map (kbd "M-f") 'find-file)
(define-key global-map (kbd "M-e") 'next-error)
(define-key global-map (kbd "M-q") 'previous-error)

(define-key nav-mode-map (kbd "M-r") 'eglot-rename)
(define-key company-active-map (kbd "TAB") 'company-complete-common-or-cycle)
(define-key company-active-map (kbd "S-TAB") 'company-complete)
(define-key global-map (kbd "M-m") 'build-project)

(define-key global-map (kbd "M-v") 'multiline-edit)
(define-key nav-mode-map (kbd "r") 'string-rectangle)
;; Buffers
(define-key global-map (kbd "M-s") 'save-buffer)
(define-key global-map (kbd "M-b") 'switch-to-buffer)
(define-key nav-mode-map (kbd "C-b") 'switch-to-previous-buffer)

;; Windows
(define-key global-map (kbd "C-q") 'delete-window)
(define-key global-map (kbd "M-w") 'other-window)

;; Movement
(define-key global-map (kbd "M-k") 'scroll-half-page-down)
(define-key global-map (kbd "M-j") 'scroll-half-page-up)
(define-key global-map [escape] 'enter-nav-mode)
(define-key global-map (kbd "M-p") '(lambda () (interactive) (imenu 'Function))) 

(custom-set-variables
 ;; custom-set-variables was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 '(package-selected-packages '(company ## corfu eglot)))
(custom-set-faces
 ;; custom-set-faces was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 )
