## Exercice6: 6 manières de defaire

## I provocation et defaire  d'une modification non voulue

### 1-provocation
```
PS F:\exo1> `git add ajout2.md`
PS F:\exo1> git status
On branch main
Your branch is up to date with 'origin/main'.

Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
        modified:   ajout2.md

```
### 2-defaire

```
PS F:\exo1> `git restore --staged ajout2.md`
PS F:\exo1> `git status`
On branch main
Your branch is up to date with 'origin/main'.

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   ajout2.md

no changes added to commit (use "git add" and/or "git commit -a")

PS F:\exo1> `git restore ajout2.md`
PS F:\exo1> `git status`
On branch main
Your branch is up to date with 'origin/main'.

nothing to commit, working tree clean
```

## II provocation et defaire d'un git add en trop

### 1-provocation
```
PS F:\exo1>` git add ajout2.md`
PS F:\exo1> `git status`
On branch main
Your branch is up to date with 'origin/main'.

Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
        modified:   ajout2.md

PS F:\exo1> `git add ajout3.md`
PS F:\exo1> `git status`
On branch main
Your branch is up to date with 'origin/main'.

Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
        modified:   ajout2.md
        modified:   ajout3.md
```

### 2-defaire

```
PS F:\exo1> `git restore --staged ajout3.md`
PS F:\exo1> `git status`
On branch main
Your branch is up to date with 'origin/main'.

Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
        modified:   ajout2.md
```

## III provocation et defaire un commit en trop

### 1-provocation

```
PS F:\exo1> `git add .`
PS F:\exo1> `git commit -m "effacement commit"`
[main 7cba6ed] effacement commit
```

### 2-defaire

```
PS F:\exo1> git reset --soft HEAD~1
PS F:\exo1> git log --oneline
23f351a (HEAD -> main, origin/main, origin/HEAD) changement involontaire
eeb9a8c gigantesque
de6a6fb amélioration push
1dcf758 refait push
f409d1e premier push
a6b1da4 dernier changement en conclusion
db9125c premier changement au niveau de l'introduction
c008f27 3
7ebd9db 2
4a8beb5 1
3510878 deuxième changement de ajout3.md
6cc7f70 premier changement de ajout3.md
de121e3 julien debut
f4ee8ae ajout v2
b09112f ajout3
46800b4 ajout2
fb185d9 ajout1
a0b51a8 Initial commit
PS F:\exo1> 
```

## IV provocation et defaire Un commit poussé qu'il faut annuler

### 1- provocation

```
PS F:\exo1> `git add .`
PS F:\exo1> `git commit -m "commit poussé sur github"`
[main 3fdb6f2] commit poussé sur github
 1 file changed, 1 insertion(+), 1 deletion(-)
PS F:\exo1> `git push`
Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 8 threads
Compressing objects: 100% (2/2), done.
Writing objects: 100% (3/3), 291 bytes | 145.00 KiB/s, done.
Total 3 (delta 1), reused 0 (delta 0), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (1/1), completed with 1 local object.
To https://github.com/julienbeling2007-droid/exo1.git
   b67bce6..3fdb6f2  main -> main

```

### 2- defaire

```
PS F:\exo1> git revert HEAD
[main c6e1847] Revert "commit poussé sur github"
 1 file changed, 1 insertion(+), 1 deletion(-)
PS F:\exo1> git push
Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 8 threads
Compressing objects: 100% (2/2), done.
Writing objects: 100% (3/3), 319 bytes | 319.00 KiB/s, done.
Total 3 (delta 1), reused 0 (delta 0), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (1/1), completed with 1 local object.
To https://github.com/julienbeling2007-droid/exo1.git
   3fdb6f2..c6e1847  main -> main

```

## V- provocation et defaire  Travail en cours qu'on doit mettre de coté

### 1-provocation

```
PS F:\exo1> `git status`
On branch main
Your branch is up to date with 'origin/main'.

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   ajout3.md

```

### 2- defaire 

```
PS F:\exo1> git stash
Saved working directory and index state WIP on main: b36349d Revert "Reapply "commit poussé sur github""
 pour aller plus loin voici la commande pour recuperer les modifications: `git stash pop`

 PS F:\exo1> `git stash pop`
On branch main
Your branch is up to date with 'origin/main'.

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   ajout3.md

no changes added to commit (use "git add" and/or "git commit -a")
Dropped refs/stash@{0} (4b8afad13030b318c5f49118c89a22a31df15ee9)

```


### VI provocation et defaire  d'un commit perdu qu'il faut retrouver avec reflog

## 1- provocation

```
PS F:\exo1> `git add .`
PS F:\exo1> `git commit -m "commit à debusqué"`
[main 29fa76c] commit à debusqué
 1 file changed, 3 insertions(+)
PS F:\exo1> `git log --oneline`
29fa76c (HEAD -> main) commit à debusqué
b36349d (origin/main, origin/HEAD) Revert "Reapply "commit poussé sur github""
e1b8718 Reapply "commit poussé sur github"
c6e1847 Revert "commit poussé sur github"
3fdb6f2 commit poussé sur github
b67bce6 eau
23f351a changement involontaire
eeb9a8c gigantesque
de6a6fb amélioration push
1dcf758 refait push
f409d1e premier push
a6b1da4 dernier changement en conclusion
db9125c premier changement au niveau de l'introduction
c008f27 3
7ebd9db 2
4a8beb5 1
3510878 deuxième changement de ajout3.md
6cc7f70 premier changement de ajout3.md
de121e3 julien debut
f4ee8ae ajout v2
b09112f ajout3
46800b4 ajout2
fb185d9 ajout1
a0b51a8 Initial commit



PS F:\exo1> `git reset --hard HEAD~1`
HEAD is now at b36349d Revert "Reapply "commit poussé sur github""
PS F:\exo1> git log --oneline
b36349d (HEAD -> main, origin/main, origin/HEAD) Revert "Reapply "commit poussé sur github""
e1b8718 Reapply "commit poussé sur github"
c6e1847 Revert "commit poussé sur github"
3fdb6f2 commit poussé sur github
b67bce6 eau
23f351a changement involontaire
eeb9a8c gigantesque
de6a6fb amélioration push
1dcf758 refait push
f409d1e premier push
a6b1da4 dernier changement en conclusion
db9125c premier changement au niveau de l'introduction
c008f27 3
7ebd9db 2
4a8beb5 1
3510878 deuxième changement de ajout3.md
6cc7f70 premier changement de ajout3.md
de121e3 julien debut
f4ee8ae ajout v2
b09112f ajout3
46800b4 ajout2
fb185d9 ajout1
a0b51a8 Initial commit

```

### 2- defaire 

```
PS F:\exo1> `git reflog`
b36349d (HEAD -> main, origin/main, origin/HEAD) HEAD@{0}: reset: moving to HEAD~1
29fa76c HEAD@{1}: commit: commit à debusqué
b36349d (HEAD -> main, origin/main, origin/HEAD) HEAD@{2}: reset: moving to HEAD
b36349d (HEAD -> main, origin/main, origin/HEAD) HEAD@{3}: revert: Revert "Reapply "commit poussé sur github""
e1b8718 HEAD@{4}: revert: Reapply "commit poussé sur github"
c6e1847 HEAD@{5}: revert: Revert "commit poussé sur github"
3fdb6f2 HEAD@{6}: commit: commit poussé sur github
b67bce6 HEAD@{7}: commit: eau
23f351a HEAD@{8}: reset: moving to HEAD~1
7cba6ed HEAD@{9}: commit: effacement commit
23f351a HEAD@{10}: commit: changement involontaire
eeb9a8c HEAD@{11}: commit: gigantesque
de6a6fb HEAD@{12}: commit: amélioration push
1dcf758 HEAD@{13}: commit: refait push
f409d1e HEAD@{14}: commit: premier push
a6b1da4 HEAD@{15}: checkout: moving from julien to main
b4dff57 (origin/julien, julien) HEAD@{16}: commit: troisième modification
31ccfc7 HEAD@{17}: commit: deuxième modification sur ajout2.md
0543ac7 HEAD@{18}: commit: première modification sur ajout2.md
de121e3 HEAD@{19}: checkout: moving from main to julien
a6b1da4 HEAD@{20}: commit: dernier changement en conclusion
db9125c HEAD@{21}: commit: premier changement au niveau de l'introduction
c008f27 HEAD@{22}: commit: 3
7ebd9db HEAD@{23}: commit: 2
4a8beb5 HEAD@{24}: commit: 1
3510878 HEAD@{25}: commit: deuxième changement de ajout3.md
6cc7f70 HEAD@{26}: commit: premier changement de ajout3.md
de121e3 HEAD@{27}: merge julien: Fast-forward
f4ee8ae HEAD@{28}: checkout: moving from julien to main
de121e3 HEAD@{29}: checkout: moving from julien to julien
de121e3 HEAD@{30}: commit: julien debut
f4ee8ae HEAD@{31}: checkout: moving from main to julien
f4ee8ae HEAD@{32}: commit: ajout v2
b09112f HEAD@{33}: commit: ajout3
46800b4 HEAD@{34}: commit: ajout2
fb185d9 HEAD@{35}: commit: ajout1
a0b51a8 HEAD@{36}: clone: from https://github.com/julienbeling2007-droid/exo1.git



PS F:\exo1> `git reset --hard 29fa76c`
HEAD is now at 29fa76c commit à debusqué
PS F:\exo1> `git log --oneline`
29fa76c (HEAD -> main) commit à debusqué
b36349d (origin/main, origin/HEAD) Revert "Reapply "commit poussé sur github""
e1b8718 Reapply "commit poussé sur github"
c6e1847 Revert "commit poussé sur github"
3fdb6f2 commit poussé sur github
b67bce6 eau
23f351a changement involontaire
eeb9a8c gigantesque
de6a6fb amélioration push
1dcf758 refait push
f409d1e premier push
a6b1da4 dernier changement en conclusion
db9125c premier changement au niveau de l'introduction
c008f27 3
7ebd9db 2
4a8beb5 1
3510878 deuxième changement de ajout3.md
6cc7f70 premier changement de ajout3.md
de121e3 julien debut
f4ee8ae ajout v2
b09112f ajout3
46800b4 ajout2
fb185d9 ajout1
a0b51a8 Initial commit
````



