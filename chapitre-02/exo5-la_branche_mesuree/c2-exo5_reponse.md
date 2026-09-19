## Exercice5: mesurée branche

### 1- comptage initial
```
PS F:\exo1> git count-objects -vH
count: 34
size: 4.77 KiB
in-pack: 5
packs: 1
size-pack: 3.07 KiB
prune-packable: 0
garbage: 0
size-garbage: 0 bytes
```

### 2-creation de la branche et les 3 commits

```
PS F:\exo1> git branch
  julien
* main
PS F:\exo1> git switch julien
Switched to branch 'julien'
Your branch is up to date with 'origin/julien'.
PS F:\exo1> git add .
PS F:\exo1> git commit -m "première modification sur ajout2.md"
[julien 0543ac7] première modification sur ajout2.md
 1 file changed, 1 insertion(+), 1 deletion(-)
PS F:\exo1> git push -u origin julien
Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 8 threads
Compressing objects: 100% (2/2), done.
Writing objects: 100% (3/3), 304 bytes | 76.00 KiB/s, done.
Total 3 (delta 1), reused 0 (delta 0), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (1/1), completed with 1 local object.
To https://github.com/julienbeling2007-droid/exo1.git
   de121e3..0543ac7  julien -> julien
branch 'julien' set up to track 'origin/julien'.
PS F:\exo1> git add .                                          
PS F:\exo1> git commit -m "deuxième modification sur ajout2.md" 
[julien 31ccfc7] deuxième modification sur ajout2.md
 1 file changed, 1 insertion(+), 1 deletion(-)
PS F:\exo1> git push
Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 8 threads
Compressing objects: 100% (2/2), done.
Writing objects: 100% (3/3), 302 bytes | 151.00 KiB/s, done.
Total 3 (delta 1), reused 0 (delta 0), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (1/1), completed with 1 local object.
To https://github.com/julienbeling2007-droid/exo1.git
   0543ac7..31ccfc7  julien -> julien
PS F:\exo1> git add .
PS F:\exo1> git commit -m "troisième modification"
[julien b4dff57] troisième modification
 1 file changed, 1 insertion(+), 1 deletion(-)
PS F:\exo1> git push
Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 8 threads
Compressing objects: 100% (2/2), done.
Writing objects: 100% (3/3), 287 bytes | 287.00 KiB/s, done.
Total 3 (delta 1), reused 0 (delta 0), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (1/1), completed with 1 local object.
To https://github.com/julienbeling2007-droid/exo1.git
   31ccfc7..b4dff57  julien -> julien
PS F:\exo1> git switch main
Switched to branch 'main'
Your branch is up to date with 'origin/main'.
```
### 3- comptage final
```
PS F:\exo1> git count-objects -vH
count: 43
size: 6.00 KiB
in-pack: 5
packs: 1
size-pack: 3.07 KiB
prune-packable: 0
garbage: 0
size-garbage: 0 bytes
````

**explication du resultat**:  dans le comptage 1 la taille occupé par les differents objets dans le disque est de 4.77kib alors que dans le comptage 2 il y a 6.00kib occupé.cette difference s'explique par le fait que git enregistre des fichiers dans le disque dur en fonction des commit qu'on effectue