(package-initialize)
(add-to-list 'package-archives
  '("melpa" . "http://melpa.org/packages/"))
(add-to-list 'package-archives
   '("org" . "http://orgmode.org/elpa/"))

(setq package-list
    '(corfu irony))

; install the missing packages
(dolist (package package-list)
  (unless (package-installed-p package)
    (package-install package)))

(require 'compile)
(require 'dabbrev)

; Autocompletion
(corfu-global-mode)
(setq corfu-auto t)

;Stop Emacs from losing undo information by
; setting very high limits for undo buffers
(setq undo-limit 20000000)
(setq undo-strong-limit 40000000)

; Determine the underlying operating system
(setq os_linux (featurep 'x))

(if os_linux
    (setq build-script "../build.sh")
  (setq build-script "sh ../build.sh")
  )
 
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
    (c-add-style "my-c-style"
    (c-set-offset 'substatement-open 0)
    (c-set-offset 'statement-block-intro 4)
    (c-set-offset 'topmost-intro 2)
    (c-set-offset 'defun-block-intro 4)
    (c-set-offset 'statement-block-into 4)
  )
  (setq c++-indent-level 4)  
  (setq tab-width 4
        indent-tabs-mode nil)
  
  (c-set-style my-c-stype)

)

(electric-pair-mode 1)
(setq electric-pair-preserve-balance nil)

; Setup my compilation mode
(defun my-compilation-hook ()
  (make-local-variable 'truncate-lines)
  (setq truncate-lines nil)
 )

(add-hook 'c++-mode-common-hook 'my-c++-hook)
(add-hook 'compilation-mode-hook 'my-compilation-hook)

;(setq-default display-buffer-reuse-frames t)

(defun toggle-comment-region()
  (interactive)
  (comment-or-uncomment-region 0 0 'region)
)

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
  (edit-mode -1))

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

(defun cd-file-dir ()
  (interactive)
  (cd (file-name-directory (buffer-file-name))))

(defun switch-to-previous-buffer ()
  (interactive)
  (switch-to-buffer (other-buffer)))

; Add hook so buffers start in nav mode
;(add-hook 'buffer_list_update_hook 'enter-nav-mode)
(add-hook 'find-file-hook 'enter-nav-mode)

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
(define-key nav-mode-map (kbd "d") 'delete-region)
(define-key nav-mode-map (kbd "y") 'copy-region-as-kill)
(define-key nav-mode-map (kbd "c") 'cut-region)
(define-key nav-mode-map (kbd "> >") 'indent-region)
(define-key nav-mode-map (kbd "M-R") 'replace-string)
(define-key nav-mode-map (kbd "/") 'isearch-forward)
(define-key nav-mode-map (kbd "C-/") 'isearch-yank-symbol-or-char)
(define-key nav-mode-map (kbd "n") 'isearch-repeat-forward+)
(define-key nav-mode-map (kbd "N") 'isearch-repeat-backward+)
(define-key nav-mode-map (kbd "M-b") 'switch-to-previous-buffer)
(define-key nav-mode-map (kbd ":") 'goto-line)

(define-key global-map (kbd "M-f") 'find-file)
(define-key global-map (kbd "M-w") 'other-window)
(define-key global-map (kbd "M-e") 'next-error)
(define-key global-map (kbd "M-q") 'previous-error)

(define-key edit-mode-map [tab] 'dabbrev-completion)
(define-key edit-mode-map [shift-tab] 'dabbrev-expand)

(define-key global-map (kbd "M-m") 'build-project)

; Buffers
(define-key global-map (kbd "M-s") 'save-buffer)

(define-key global-map (kbd "M-k") 'scroll-half-page-down)
(define-key global-map (kbd "M-j") 'scroll-half-page-up)
(define-key global-map [escape] 'enter-nav-mode)

(custom-set-variables
 ;; custom-set-variables was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 '(package-selected-packages '(irony corfu ##))
 '(safe-local-variable-values
   '((company-clang-arguments "-I/home/marko/spark/libs/glfw/include/" "-I/home/marko/spark/libs/stb/" "-I/home/marko/spark/libs/glm/" "-I/home/marko/spark/libs/imgui/"))))
(custom-set-faces
 ;; custom-set-faces was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 )
