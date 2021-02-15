; Stop Emacs from losing undo information by
; setting very high limits for undo buffers
(setq undo-limit 20000000)
(setq undo-strong-limit 40000000)

; Determine the underlying operating system
(setq marko-linux (featurep 'x))

(global-hl-line-mode 1)

(setq compilation-directory-locked nil)
(scroll-bar-mode -1)
(setq shift-select-mode nil)
(setq enable-local-variables nil)
(setq marko-font "outline-DejaVu Sans Mono")

(when marko-linux
  (setq marko-makescript "./build.sh")
)

; Turn off the toolbar
(tool-bar-mode 0)

(load-library "view")
(require 'cc-mode)
(require 'ido)
(require 'compile)
(ido-mode t)


(defun marko-ediff-setup-windows (buffer-A buffer-B buffer-C control-buffer)
  (ediff-setup-windows-plain buffer-A buffer-B buffer-C control-buffer)
)
(setq ediff-window-setup-function 'marko-ediff-setup-windows)
(setq ediff-split-window-function 'split-window-horizontally)

(defun nil-bell ())
(setq ring-bell-function 'nil-bell)

; Setup my compilation mode
(defun marko-big-fun-compilation-hook ()
  (make-local-variable 'truncate-lines)
  (setq truncate-lines nil)
 )

(add-hook 'compilation-mode-hook 'marko-big-fun-compilation-hook)


(defun insert-timeofday ()
   (interactive "*")
   (insert (format-time-string "---------------- %a, %d %b %y: %I:%M%p")))
(defun load-log ()
  (interactive)
  (find-file marko-log-file)
  (if (boundp 'longlines-mode) ()
    (longlines-mode 1)
    (longlines-show-hard-newlines))
  (if (equal longlines-mode t) ()
    (longlines-mode 1)
    (longlines-show-hard-newlines))
  (end-of-buffer)
  (newline-and-indent)
  (insert-timeofday)
  (newline-and-indent)
  (newline-and-indent)
  (end-of-buffer)
)
(define-key global-map "\e-" 'load-log)

; no screwing with my middle mouse button
(global-unset-key [mouse-2])

; Bright-red TODOs
 (setq fixme-modes '(c++-mode c-mode emacs-lisp-mode))
 (make-face 'font-lock-fixme-face)
 (make-face 'font-lock-study-face)
 (make-face 'font-lock-important-face)
 (make-face 'font-lock-note-face)
 (mapc (lambda (mode)
	 (font-lock-add-keywords
	  mode
	  '(("\\<\\(TODO\\)" 1 'font-lock-fixme-face t)
	    ("\\<\\(STUDY\\)" 1 'font-lock-study-face t)
	    ("\\<\\(IMPORTANT\\)" 1 'font-lock-important-face t)
            ("\\<\\(NOTE\\)" 1 'font-lock-note-face t))))
	fixme-modes)
 (modify-face 'font-lock-fixme-face "Red" nil nil t nil t nil nil)
 (modify-face 'font-lock-study-face "Yellow" nil nil t nil t nil nil)
 (modify-face 'font-lock-important-face "Yellow" nil nil t nil t nil nil)
 (modify-face 'font-lock-note-face "Dark Green" nil nil t nil t nil nil)

; Accepted file extensions and their appropriate modes
(setq auto-mode-alist
      (append
       '(("\\.cpp$"    . c++-mode)
         ("\\.hin$"    . c++-mode)
         ("\\.cin$"    . c++-mode)
         ("\\.inl$"    . c++-mode)
         ("\\.rdc$"    . c++-mode)
         ("\\.h$"    . c++-mode)
         ("\\.c$"   . c++-mode)
         ("\\.cc$"   . c++-mode)
         ("\\.c8$"   . c++-mode)
         ("\\.txt$" . indented-text-mode)
         ("\\.emacs$" . emacs-lisp-mode)
         ("\\.gen$" . gen-mode)
         ("\\.ms$" . fundamental-mode)
         ("\\.m$" . objc-mode)
         ("\\.mm$" . objc-mode)
         ) auto-mode-alist))

; C++ indentation style
(defconst marko-big-fun-c-style
  '((c-electric-pound-behavior   . nil)
    (c-tab-always-indent         . t)
    (c-comment-only-line-offset  . 0)
    (c-hanging-braces-alist      . ((class-open)
                                    (class-close)
                                    (defun-open)
                                    (defun-close)
                                    (inline-open)
                                    (inline-close)
                                    (brace-list-open)
                                    (brace-list-close)
                                    (brace-list-intro)
                                    (brace-list-entry)
                                    (block-open)
                                    (block-close)
                                    (substatement-open)
                                    (statement-case-open)
                                    (class-open)))
    (c-hanging-colons-alist      . ((inher-intro)
                                    (case-label)
                                    (label)
                                    (access-label)
                                    (access-key)
                                    (member-init-intro)))
    (c-cleanup-list              . (scope-operator
                                    list-close-comma
                                    defun-close-semi))
    (c-offsets-alist             . ((arglist-close         .  c-lineup-arglist)
                                    (label                 . -4)
                                    (access-label          . -4)
                                    (substatement-open     .  0)
                                    (statement-case-intro  .  4)
                                    (statement-block-intro .  c-lineup-for)
                                    (case-label            .  4)
                                    (block-open            .  0)
                                    (inline-open           .  0)
                                    (topmost-intro-cont    .  0)
                                    (knr-argdecl-intro     . -4)
                                    (brace-list-open       .  0)
                                    (brace-list-intro      .  4)))
    (c-echo-syntactic-information-p . t))
    "Marko's Big Fun C++ Style")


; CC++ mode handling
(defun marko-big-fun-c-hook ()
  ; Set my style for the current buffer
  (c-add-style "BigFun" marko-big-fun-c-style t)
  
  ; 4-space tabs
  (setq tab-width 4
        indent-tabs-mode nil)

  ; Additional style stuff
  (c-set-offset 'member-init-intro '++)

  ; No hungry backspace
  (c-toggle-auto-hungry-state -1)

  ; semi-colon doesn't indent
  (setq c-hanging-semi&comma-criteria '((lambda () 'stop)))

  ; Handle super-tabbify (TAB completes, shift-TAB actually tabs)
  (setq dabbrev-case-replace t)
  (setq dabbrev-case-fold-search t)
  (setq dabbrev-upcase-means-case-search t)

  ; Abbrevation expansion
  (abbrev-mode 1)
 
  (defun marko-header-format ()
     "Format the given file as a header file."
     (interactive)
     (setq BaseFileName (file-name-sans-extension (file-name-nondirectory buffer-file-name)))
     (insert "#if !defined(")
     (push-mark)
     (insert BaseFileName)
     (upcase-region (mark) (point))
     (pop-mark)
     (insert "_H)\n")
     (insert "/* ========================================================================\n")
     (insert "   $File: $\n")
     (insert "   $Date: $\n")
     (insert "   $Creator: Marko Bisevac $\n")
     (insert "   $Notice: (C) Copyright 2021. All Rights Reserved. $\n")
     (insert "   ======================================================================== */\n")
     (insert "\n")
     (insert "#define ")
     (push-mark)
     (insert BaseFileName)
     (upcase-region (mark) (point))
     (pop-mark)
     (insert "_H\n")
     (insert "#endif")
  )

  (defun marko-source-format ()
     "Format the given file as a source file."
     (interactive)
     (setq BaseFileName (file-name-sans-extension (file-name-nondirectory buffer-file-name)))
     (insert "/* ========================================================================\n")
     (insert "   $File: $\n")
     (insert "   $Date: $\n")
     (insert "   $Creator: Marko Bisevac $\n")
     (insert "   $Notice: (C) Copyright 2021. All Rights Reserved. $\n")
     (insert "   ======================================================================== */\n")
  )

  (cond ((file-exists-p buffer-file-name) t)
        ((string-match "[.]hin" buffer-file-name) (marko-source-format))
        ((string-match "[.]cin" buffer-file-name) (marko-source-format))
        ((string-match "[.]h" buffer-file-name) (marko-header-format))
        ((string-match "[.]cpp" buffer-file-name) (marko-source-format)))

  (defun marko-find-corresponding-file ()
    "Find the file that corresponds to this one."
    (interactive)
    (setq CorrespondingFileName nil)
    (setq BaseFileName (file-name-sans-extension buffer-file-name))
    (if (string-match "\\.c" buffer-file-name)
       (setq CorrespondingFileName (concat BaseFileName ".h")))
    (if (string-match "\\.h" buffer-file-name)
       (if (file-exists-p (concat BaseFileName ".c")) (setq CorrespondingFileName (concat BaseFileName ".c"))
	   (setq CorrespondingFileName (concat BaseFileName ".cpp"))))
    (if (string-match "\\.hin" buffer-file-name)
       (setq CorrespondingFileName (concat BaseFileName ".cin")))
    (if (string-match "\\.cin" buffer-file-name)
       (setq CorrespondingFileName (concat BaseFileName ".hin")))
    (if (string-match "\\.cpp" buffer-file-name)
       (setq CorrespondingFileName (concat BaseFileName ".h")))
    (if CorrespondingFileName (find-file CorrespondingFileName)
       (error "Unable to find a corresponding file")))
  (defun marko-find-corresponding-file-other-window ()
    "Find the file that corresponds to this one."
    (interactive)
    (find-file-other-window buffer-file-name)
    (marko-find-corresponding-file)
    (other-window -1))
  
  

  ; Turn on line numbers
  ;(linum-mode)
)

(defun marko-replace-string (FromString ToString)
  "Replace a string without moving point."
  (interactive "sReplace: \nsReplace: %s  With: ")
  (save-excursion
    (replace-string FromString ToString)
  ))
(define-key global-map [f8] 'marko-replace-string)

(add-hook 'c-mode-common-hook 'marko-big-fun-c-hook)

(defun marko-save-buffer ()
  "Save the buffer after untabifying it."
  (interactive)
  (save-excursion
    (save-restriction
      (widen)
      (untabify (point-min) (point-max))))
  (save-buffer))



(define-key global-map "\eq" 'quick-calc)
(define-key global-map "\ew" 'other-window)

; Navigation
(defun previous-blank-line ()
  "Moves to the previous line containing nothing but whitespace."
  (interactive)
  (search-backward-regexp "^[ \t]*\n")
)

(defun next-blank-line ()
  "Moves to the next line containing nothing but whitespace."
  (interactive)
  (forward-line)
  (search-forward-regexp "^[ \t]*\n")
  (forward-line -1)
)


; Compilation
(setq compilation-context-lines 0)
(setq compilation-error-regexp-alist
    (cons '("^\\([0-9]+>\\)?\\(\\(?:[a-zA-Z]:\\)?[^:(\t\n]+\\)(\\([0-9]+\\)) : \\(?:fatal error\\|warnin\\(g\\)\\) C[0-9]+:" 2 3 nil (4))
     compilation-error-regexp-alist))

(defun find-project-directory-recursive ()
  "Recursively search for a makefile."
  (interactive)
  (if (file-exists-p marko-makescript) t
      (cd "../")
      (find-project-directory-recursive)))

(defun lock-compilation-directory ()
  "The compilation process should NOT hunt for a makefile"
  (interactive)
  (setq compilation-directory-locked t)
  (message "Compilation directory is locked."))

(defun unlock-compilation-directory ()
  "The compilation process SHOULD hunt for a makefile"
  (interactive)
  (setq compilation-directory-locked nil)
  (message "Compilation directory is roaming."))

(defun find-project-directory ()
  "Find the project directory."
  (interactive)
  (setq find-project-from-directory default-directory)
  (switch-to-buffer-other-window "*compilation*")
  (if compilation-directory-locked (cd last-compilation-directory)
  (cd find-project-from-directory)
  (find-project-directory-recursive)
  (setq last-compilation-directory default-directory)))

(defun make-without-asking ()
  "Make the current build."
  (interactive)
  (if (find-project-directory) (compile marko-makescript))
  (other-window 1))

; Commands
(set-variable 'grep-command "grep -irHn ")

; Smooth scroll
(setq scroll-step 10)

; Clock
(display-time)

; Startup windowing
(setq next-line-add-newlines nil)
(setq-default truncate-lines t)
(setq truncate-partial-width-windows nil)

(custom-set-variables
 ;; custom-set-variables was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 '(auto-save-default nil)
 '(auto-save-interval 0)
 '(auto-save-list-file-prefix nil)
 '(auto-save-timeout 0)
 '(auto-show-mode t t)
 '(delete-auto-save-files nil)
 '(delete-old-versions (quote other))
 '(imenu-auto-rescan t)
 '(imenu-auto-rescan-maxout 500000)
 '(kept-new-versions 5)
 '(kept-old-versions 5)
 '(make-backup-file-name-function (quote ignore))
 '(make-backup-files nil)
 '(mouse-wheel-follow-mouse nil)
 '(mouse-wheel-progressive-speed nil)
 '(mouse-wheel-scroll-amount (quote (15)))
 '(version-control nil))

(add-to-list 'default-frame-alist '(font . "Liberation Mono-11.5"))
(set-face-attribute 'default t :font "Liberation Mono-11.5")
(set-face-attribute 'font-lock-builtin-face nil :foreground "#DAB98F")
(set-face-attribute 'font-lock-comment-face nil :foreground "gray50")
(set-face-attribute 'font-lock-constant-face nil :foreground "coral1")
(set-face-attribute 'font-lock-doc-face nil :foreground "gray50")
(set-face-attribute 'font-lock-function-name-face nil :foreground "chocolate")
(set-face-attribute 'font-lock-keyword-face nil :foreground "DarkGoldenrod3")
(set-face-attribute 'font-lock-string-face nil :foreground "olive drab")
(set-face-attribute 'font-lock-type-face nil :foreground "DarkGoldenrod3")
(set-face-attribute 'font-lock-variable-name-face nil :foreground "burlywood3")
(set-face-attribute 'region nil :background "grey18")
(set-face-background 'hl-line "grey12")

(defun post-load-stuff ()
  (interactive)
  (menu-bar-mode -1)
  (set-foreground-color "burlywood3")
  (set-background-color "#161616")
  (set-cursor-color "#40FF40")
)
(add-hook 'window-setup-hook 'post-load-stuff t)

(define-minor-mode marko-nav-mode
  "Navigation mode"
  :lighter " Navigation mode "
  :keymap (make-sparse-keymap))
(marko-nav-mode)

(defun marko-enter-edit-mode ()
  (interactive)
  (set-cursor-color "#ffffff")
  (marko-nav-mode -1))

(defun marko-exit-edit-mode ()
  (interactive)
  (set-cursor-color "#b68100")
  (marko-nav-mode))

(defun marko-newline-indent ()
   (interactive)
   (move-end-of-line nil)
   (newline-and-indent)
   (marko-enter-edit-mode))

(defun marko-kill-line ()
  (interactive)
  (kill-line)
  (marko-enter-edit-mode))

(defun marko-copy-line ()
  (interactive)
  (save-excursion
    (back-to-indentation)
    (kill-ring-save
     (point)
     (line-end-position))))    


(define-minor-mode marko-visual-mode
  "Visual mode"
  :lighter " Visual mode "
  :keymap (make-sparse-keymap))

(defun marko-enter-visual-mode ()
  (interactive)
  (marko-nav-mode -1)
  (marko-visual-mode)
  (set-mark-command nil)
  )
  
(defun marko-exit-visual-mode ()
  (interactive)
  (marko-visual-mode -1)
  (deactivate-mark)
  (marko-nav-mode))
  

(defun marko-kill-region ()
  (interactive)
  (kill-region 0 0 'region)
  (marko-exit-visual-mode))


(defun marko-comment-region()
  (interactive)
  (comment-or-uncomment-region 0 0 'region)
  (marko-exit-visual-mode))

(defun marko-replace-in-region (old-word new-word)
  "Perform a replace-string in the current region."
  (interactive "sReplace: \nsReplace: %s  With: ")
  (save-excursion (save-restriction
		    (narrow-to-region (mark) (point))
		    (beginning-of-buffer)
		    (replace-string old-word new-word)
		    ))
  (marko-exit-visual-mode)
  )

(defun marko-indent-region ()
  (interactive)
  (marko-exit-visual-mode))

(define-key global-map (kbd "`") 'marko-exit-edit-mode)

(define-key marko-nav-mode-map (kbd "j") 'next-line)
(define-key marko-nav-mode-map (kbd "k") 'previous-line)
(define-key marko-nav-mode-map (kbd "l") 'forward-char)
(define-key marko-nav-mode-map (kbd "h") 'backward-char)
(define-key marko-nav-mode-map (kbd "w") 'forward-word)
(define-key marko-nav-mode-map (kbd "b") 'backward-word)
(define-key marko-nav-mode-map (kbd "d d") 'kill-whole-line)
(define-key marko-nav-mode-map (kbd "u") 'undo)
(define-key marko-nav-mode-map (kbd "p") 'yank)
(define-key marko-nav-mode-map (kbd "y y") 'marko-copy-line)
(define-key marko-nav-mode-map (kbd "o") 'marko-newline-indent)
(define-key marko-nav-mode-map (kbd "i") 'marko-enter-edit-mode)
(define-key marko-nav-mode-map (kbd "x") 'delete-char)
(define-key marko-nav-mode-map (kbd "g g") 'beginning-of-buffer)
(define-key marko-nav-mode-map (kbd "C") 'marko-kill-line)

(define-key marko-nav-mode-map (kbd "v") 'marko-enter-visual-mode)
(define-key marko-visual-mode-map (kbd "`") 'marko-exit-visual-mode)
(define-key marko-visual-mode-map [escape] 'marko-exit-visual-mode)
(define-key marko-visual-mode-map (kbd "j") 'next-line)
(define-key marko-visual-mode-map (kbd "k") 'previous-line)
(define-key marko-visual-mode-map (kbd "l") 'forward-char)
(define-key marko-visual-mode-map (kbd "h") 'backward-char)
(define-key marko-visual-mode-map (kbd "d") 'marko-kill-region)
(define-key marko-visual-mode-map (kbd "c") 'marko-comment-region)
(define-key marko-visual-mode-map (kbd "r r") 'marko-replace-in-region)
(define-key marko-visual-mode-map (kbd ">") 'marko-indent-region)

(define-key c++-mode-map "\ec" 'marko-find-corresponding-file)
(define-key c++-mode-map "\eC" 'marko-find-corresponding-file-other-window)

(define-key c++-mode-map "\es" 'marko-save-buffer)
(define-key c++-mode-map "\t" 'dabbrev-expand)
(define-key c++-mode-map "\ep" 'imenu)

(define-key global-map "\t" 'dabbrev-expand)
(define-key global-map [S-tab] 'indent-for-tab-command)
(define-key global-map [backtab] 'indent-for-tab-command)
(define-key global-map "\C-y" 'indent-for-tab-command)
(define-key global-map "\em" 'make-without-asking)

(define-key global-map "\eo" 'query-replace)
(define-key global-map "\eO" 'marko-replace-string)

; \377 is alt-backspace
(define-key global-map "\377" 'backward-kill-word)
(define-key global-map [M-delete] 'kill-word)

(define-key global-map "\e[" 'start-kbd-macro)
(define-key global-map "\e]" 'end-kbd-macro)
(define-key global-map "\e'" 'call-last-kbd-macro)

; Buffers
(define-key global-map "\er" 'revert-buffer)
(define-key global-map "\eH" 'kill-this-buffer)
(define-key global-map "\es" 'save-buffer)
(define-key global-map [M-up] 'previous-blank-line)
(define-key global-map [M-down] 'next-blank-line)
(define-key global-map [M-right] 'forward-word)
(define-key global-map [M-left] 'backward-word)

(define-key global-map [f9] 'first-error)
(define-key global-map [f10] 'previous-error)
(define-key global-map [f11] 'next-error)

(define-key global-map "\en" 'next-error)
(define-key global-map "\eN" 'previous-error)

(define-key global-map "\eg" 'goto-line)
(define-key global-map "\ep" 'imenu)

(define-key global-map [C-right] 'forward-word)
(define-key global-map [C-left] 'backward-word)
(define-key global-map [C-up] 'previous-blank-line)
(define-key global-map [C-down] 'next-blank-line)
(define-key global-map [home] 'beginning-of-line)
(define-key global-map [end] 'end-of-line)
(define-key global-map [pgup] 'forward-page)
(define-key global-map [pgdown] 'backward-page)
(define-key global-map [C-next] 'scroll-other-window-down-window)
(define-key global-map [C-prior] 'scroll-other-window-down)

(define-key global-map "" 'nil)
(define-key global-map "" 'rotate-yank-pointer)
(define-key global-map "\e6" 'upcase-word)
(define-key global-map "\e^" 'captilize-word)
(define-key global-map "\e." 'fill-paragraph)
; Setup my find-files
(define-key global-map "\ef" 'find-file)
(define-key global-map "\eF" 'find-file-other-window)

(global-set-key (read-kbd-macro "\eb")  'ido-switch-buffer)
(global-set-key (read-kbd-macro "\eB")  'ido-switch-buffer-other-window)
