# Exercice3

## git status après modification net

```
On branch main
Your branch is up to date with 'origin/main'.

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   ajout3.md

no changes added to commit (use "git add" and/or "git commit -a")

```

## git status après un git add

```
On branch main
Your branch is up to date with 'origin/main'.

Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
        modified:   ajout3.md

```

## git status après commit

```
On branch main
Your branch is ahead of 'origin/main' by 1 commit.
  (use "git push" to publish your local commits)

nothing to commit, working tree clean

```

`conclusion`
**le git status après modification ici  le fichier après en rouge car git à detecter que le fichier est modifié mais  les changements ne sont pas préparés
le git status après git add ici le fichier est en vert et spécifie que la modification est déjà presente dans l'index 
le git status après git commit ici les modifications sont dejà mais git attend déjà une autre modificaation**