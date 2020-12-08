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
 '(custom-enabled-themes '(misterioso))
 '(custom-safe-themes
   '("fa3421ccbda08b353187c92854cbc1e2a35cc679efbd8cc9c09215b373d49c81" "c480b0e01234fff322965cd70548af6a28632dd4f435c3f4fe70d034e4ae859d" "26b312c3f8dd5b486adaed3dd127f6ccbdc27923dbe08e99fc18bb84ab9af0d6" "291317ddf8ff89a050903ce439e7e48949a060fb8dbcdaa2ea07cdbe884d157c" "981ce452904c470310f92f318490774e0423a5999851e9a3cc771eec603e0782" "b14e381e2fee488e48ad5b9bc48b287253e309d78e6bd7b64a0a473b49a52eca" "f44debfeeee7e0748f1194066401854ad71cd983c1355df099ce07fe3c796c90" "a96055ad8c33bf1518ca5e891524ff2d1cf57a061725dbceed5a66cd0d7df865" "cf2cd8400eb5835dc54d69943c5f17e6028cbbb37e157ef8492e4890bfb6e794" "09b4401ec3c92f8a562fe9187d7f8f760b777db8e3885c340907209577203a92" "0ee723810dd7a3b44ec7b232d8e931ec1cef20cd8f972784aed7b9229427052d" "015a8d121542f860a6e6bd1144330220436fd9e59d0d90be58e61a6060803639" "046c8e4766ccd7d1c7318ded8e3de8c56683188d03bdbc423dcc598e74540801" "59426e39b58263f4c45deacdd64b93db7321aca3fc0ae806a7bc41eeb38afed6" default))
 '(package-selected-packages
   '(helm-projectile fzf helm-core helm find-file-in-project elpa-find-file-in-project company-glsl glsl-mode gsls-mode gsls-mode\.el lua-mode pdf-tools yasnippet-snippets yasnippet flycheck lsp-ui projectile lsp-mode)))
(custom-set-faces
 ;; custom-set-faces was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 )
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
