(setq gnutls-algorithm-priority "NORMAL:-VERS-TLS1.3")

(require 'package)
(add-to-list 'package-archives '("melpa" . "https://melpa.org/packages/") t)
;; Comment/uncomment this line to enable MELPA Stable if desired.  See `package-archive-priorities`
;; and `package-pinned-packages`. Most users will not need or want to do this.
;; (add-to-list 'package-archives '("melpa-stable" . "https://stable.melpa.org/packages/") t)
(package-initialize)
(custom-set-variables
 ;; custom-set-variables was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 '(ansi-color-faces-vector
   [default default default italic underline success warning error])
 '(ansi-color-names-vector
   ["black" "#d55e00" "#009e73" "#f8ec59" "#0072b2" "#cc79a7" "#56b4e9" "white"])
 '(custom-enabled-themes (quote (graham)))
 '(custom-safe-themes
   (quote
	("96998f6f11ef9f551b427b8853d947a7857ea5a578c75aa9c4e7c73fe04d10b4" "c48551a5fb7b9fc019bf3f61ebf14cf7c9cdca79bcb2a4219195371c02268f11" "987b709680284a5858d5fe7e4e428463a20dfabe0a6f2a6146b3b8c7c529f08b" "e0d42a58c84161a0744ceab595370cbe290949968ab62273aed6212df0ea94b4" "3cd28471e80be3bd2657ca3f03fbb2884ab669662271794360866ab60b6cb6e6" "3cc2385c39257fed66238921602d8104d8fd6266ad88a006d0a4325336f5ee02" "e9776d12e4ccb722a2a732c6e80423331bcb93f02e089ba2a4b02e85de1cf00e" "72a81c54c97b9e5efcc3ea214382615649ebb539cb4f2fe3a46cd12af72c7607" "58c6711a3b568437bab07a30385d34aacf64156cc5137ea20e799984f4227265" "3d5ef3d7ed58c9ad321f05360ad8a6b24585b9c49abcee67bdcbb0fe583a6950" "b3775ba758e7d31f3bb849e7c9e48ff60929a792961a2d536edec8f68c671ca5" "9b59e147dbbde5e638ea1cde5ec0a358d5f269d27bd2b893a0947c4a867e14c1" "fa3421ccbda08b353187c92854cbc1e2a35cc679efbd8cc9c09215b373d49c81" "c480b0e01234fff322965cd70548af6a28632dd4f435c3f4fe70d034e4ae859d" "26b312c3f8dd5b486adaed3dd127f6ccbdc27923dbe08e99fc18bb84ab9af0d6" "291317ddf8ff89a050903ce439e7e48949a060fb8dbcdaa2ea07cdbe884d157c" "981ce452904c470310f92f318490774e0423a5999851e9a3cc771eec603e0782" "b14e381e2fee488e48ad5b9bc48b287253e309d78e6bd7b64a0a473b49a52eca" "f44debfeeee7e0748f1194066401854ad71cd983c1355df099ce07fe3c796c90" "a96055ad8c33bf1518ca5e891524ff2d1cf57a061725dbceed5a66cd0d7df865" "cf2cd8400eb5835dc54d69943c5f17e6028cbbb37e157ef8492e4890bfb6e794" "09b4401ec3c92f8a562fe9187d7f8f760b777db8e3885c340907209577203a92" "0ee723810dd7a3b44ec7b232d8e931ec1cef20cd8f972784aed7b9229427052d" "015a8d121542f860a6e6bd1144330220436fd9e59d0d90be58e61a6060803639" "046c8e4766ccd7d1c7318ded8e3de8c56683188d03bdbc423dcc598e74540801" "59426e39b58263f4c45deacdd64b93db7321aca3fc0ae806a7bc41eeb38afed6" default)))
 '(flymake-error-bitmap
   (quote
	(flymake-double-exclamation-mark modus-theme-fringe-red)))
 '(flymake-note-bitmap (quote (exclamation-mark modus-theme-fringe-cyan)))
 '(flymake-warning-bitmap (quote (exclamation-mark modus-theme-fringe-yellow)))
 '(highlight-tail-colors (quote (("#aecf90" . 0) ("#c0efff" . 20))))
 '(hl-sexp-background-color "#efebe9")
 '(hl-todo-keyword-faces
   (quote
	(("HOLD" . "#70480f")
	 ("TODO" . "#721045")
	 ("NEXT" . "#5317ac")
	 ("THEM" . "#8f0075")
	 ("PROG" . "#00538b")
	 ("OKAY" . "#30517f")
	 ("DONT" . "#315b00")
	 ("FAIL" . "#a60000")
	 ("BUG" . "#a60000")
	 ("DONE" . "#005e00")
	 ("NOTE" . "#863927")
	 ("KLUDGE" . "#813e00")
	 ("HACK" . "#813e00")
	 ("TEMP" . "#5f0000")
	 ("FIXME" . "#a0132f")
	 ("XXX+" . "#972500")
	 ("REVIEW" . "#005a5f")
	 ("DEPRECATED" . "#201f55"))))
 '(ibuffer-deletion-face (quote modus-theme-mark-del))
 '(ibuffer-filter-group-name-face (quote modus-theme-mark-symbol))
 '(ibuffer-marked-face (quote modus-theme-mark-sel))
 '(ibuffer-title-face (quote modus-theme-header))
 '(linum-format " %7i ")
 '(package-selected-packages
   (quote
	(which-key evil sublime-themes helm-projectile fzf helm-core helm find-file-in-project elpa-find-file-in-project company-glsl glsl-mode gsls-mode gsls-mode\.el lua-mode pdf-tools yasnippet-snippets yasnippet flycheck lsp-ui projectile lsp-mode)))
 '(vc-annotate-background nil)
 '(vc-annotate-background-mode nil)
 '(vc-annotate-color-map
   (quote
	((20 . "#a60000")
	 (40 . "#721045")
	 (60 . "#8f0075")
	 (80 . "#972500")
	 (100 . "#813e00")
	 (120 . "#70480f")
	 (140 . "#5d3026")
	 (160 . "#184034")
	 (180 . "#005e00")
	 (200 . "#315b00")
	 (220 . "#005a5f")
	 (240 . "#30517f")
	 (260 . "#00538b")
	 (280 . "#093060")
	 (300 . "#0030a6")
	 (320 . "#223fbf")
	 (340 . "#0000bb")
	 (360 . "#5317ac"))))
 '(vc-annotate-very-old-color nil)
 '(xterm-color-names
   ["#000000" "#a60000" "#005e00" "#813e00" "#0030a6" "#721045" "#00538b" "#f0f0f0"])
 '(xterm-color-names-bright
   ["#505050" "#972500" "#315b00" "#70480f" "#223fbf" "#8f0075" "#30517f" "#ffffff"]))
(custom-set-faces
 ;; custom-set-faces was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 '(default ((t (:background nil)))))
;;--------------------------------------------------------------------
;; function that installs package if not installed and requires it
(defun marko-install-package (package)
  (unless (package-installed-p package)
	(package-install package))
  (require package))

;; -----------------------------------
;; https://github.com/emacs-evil/evil-collection/issues/60 for more details.
(setq evil-want-keybinding nil)
(marko-install-package 'evil)
(marko-install-package 'which-key)

;; C++
(defun marko-c++-mode-hook ()
  (setq c-basic-offset 4)
  (c-set-offset 'substatement-open 0))
(add-hook 'c++-mode-hook 'marko-c++-mode-hook)

(defun marko-make-project ()
  (interactive)
  (shell)
  (insert "make")
  )
(global-set-key (kbd "C-c c") 'marko-make-project)

;; create empthy buffer
(defun marko-new-empty-buffer ()
  (interactive)
  (let (($buf (generate-new-buffer "untitled")))
    (switch-to-buffer-other-window $buf)

    (setq buffer-offer-save t)
    $buf
    ))

(global-set-key (kbd "C-c n") 'marko-new-empty-buffer)



;; startup buffer
(setq initial-buffer-choice 'marko-new-empty-buffer)

;; change default tab size
(setq-default tab-width 4)
;; Backup files directory
(setq backup-directory-alist `(("." . "~/.saves_emacs")))
;; start maximized
(add-to-list 'default-frame-alist '(fullscreen . maximized))
;; display number line
(global-display-line-numbers-mode)
;; Set cursor color
(set-cursor-color "#ffffff") 
;; Disable hardware beep
(setq visible-bell 1)
;; Disable top menu bar and scrollbar
(menu-bar-mode -1)
(toggle-scroll-bar -1)
(tool-bar-mode -1)
;; Enable autopair
(electric-pair-mode 1)
(setq electric-pair-preserve-balance nil)
;; Evil
(evil-mode 1)
;; which-key
(which-key-mode)
