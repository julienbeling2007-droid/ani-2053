# Exercice2

## git status après modification
```
On branch main
Your branch is up to date with 'origin/main'.

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   ajout3.md
```
## git status après git add 
```
On branch main
Your branch is up to date with 'origin/main'.

Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
        modified:   ajout3.md
```
## git status après git commit
```
On branch main
Your branch is ahead of 'origin/main' by 1 commit.
  (use "git push" to publish your local commits)

nothing to commit, working tree clean

```
`conclusion`
**`le git status après modification` ici le fichier se met en rouge pour dire que git à detecter les modifications mais cela n'est pas encore dans l'index tandis que `git status après git add` ici le fichier est vert et spécifie que les modifications sont dejà pousser dans le transit(index)  alors que `git status après git commit` ici le fichier est enregistré localement et une modification est en attente**

## autre sortie

```
On branch main
Your branch is up to date with 'origin/main'.

nothing to commit, working tree clean
```
ici il s'agit d'un git status après publication en ligne donc après un git push et cela spécifie que le code local est synchronisé au depot distant