## Exercice5: mesurée branche

### 1- comptage initial
```
count: 15
size: 1.68 KiB
in-pack: 0
packs: 0
size-pack: 0 bytes
prune-packable: 0
garbage: 0
size-garbage: 0 bytes
```

### 2-creation de la branche et les 3 commits

```
PS F:\exo2> git checkout -b julien
fatal: a branch named 'julien' already exists
PS F:\exo2> git checkout -b essai 
Switched to a new branch 'essai'
PS F:\exo2> git branch
  bandit
* essai
  julien
  main
PS F:\exo2> git add .                      
warning: in the working copy of 'mano.cpp', LF will be replaced by CRLF the next time Git touches it
PS F:\exo2> git commit -m "premier placement"
[essai 893e35a] premier placement
 1 file changed, 15 insertions(+)
 create mode 100644 mano.cpp
PS F:\exo2> git push -u origin essai
Enumerating objects: 8, done.
Counting objects: 100% (8/8), done.
Delta compression using up to 8 threads
Compressing objects: 100% (5/5), done.
Writing objects: 100% (6/6), 703 bytes | 234.00 KiB/s, done.
Total 6 (delta 1), reused 0 (delta 0), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (1/1), done.
remote: 
remote: Create a pull request for 'essai' on GitHub by visiting:
remote:      https://github.com/julienbeling2007-droid/exo2/pull/new/essai
remote: 
To https://github.com/julienbeling2007-droid/exo2.git
 * [new branch]      essai -> essai
branch 'essai' set up to track 'origin/essai'.
PS F:\exo2> git add .                        
warning: in the working copy of 'mano.cpp', LF will be replaced by CRLF the next time Git touches it
PS F:\exo2> git commit -m "deuxième placement"
[essai 425b829] deuxième placement
 1 file changed, 1 insertion(+), 1 deletion(-)
PS F:\exo2> git push -u origin essai          
Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 8 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 322 bytes | 322.00 KiB/s, done.
Total 3 (delta 2), reused 0 (delta 0), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (2/2), completed with 2 local objects.
To https://github.com/julienbeling2007-droid/exo2.git
   893e35a..425b829  essai -> essai
branch 'essai' set up to track 'origin/essai'.
PS F:\exo2> git add .                         
warning: in the working copy of 'mano.cpp', LF will be replaced by CRLF the next time Git touches it
PS F:\exo2> git commit -m "troisième  placement"
[essai 530e2a0] troisième  placement
 1 file changed, 3 insertions(+), 3 deletions(-)
PS F:\exo2> git push -u origin essai            
Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 8 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 306 bytes | 306.00 KiB/s, done.
Total 3 (delta 2), reused 0 (delta 0), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (2/2), completed with 2 local objects.
To https://github.com/julienbeling2007-droid/exo2.git
   425b829..530e2a0  essai -> essai
branch 'essai' set up to track 'origin/essai'.
PS F:\exo2> git count-objects -vH

```
### 3- comptage final
```
PS F:\exo2> git count-objects -vH
count: 24
size: 3.03 KiB
in-pack: 0
packs: 0
size-pack: 0 bytes
prune-packable: 0
garbage: 0
size-garbage: 0 bytes
PS F:\exo2>
````

**explication du resultat**:  dans le comptage 1 la taille occupé par les differents objets dans le disque est de 4.77kib(size) alors que dans le comptage 2 il y a 6.00kib(size) occupé.cette difference s'explique par le fait que git enregistre des fichiers dans le disque dur en fonction des commit qu'on effectue et aussi on observe **un champ in packs** qui est de 0 qui est commun aux 2 comptages et cela s'explique par le fait le projet ne comporte pas de fichier paquet ce qui signifie que la taulle est nul d'où la valeur de pack size qui est la taille des fichiers paquets, **garbage** quand à lui c'est l'ensemble des fichiers corrompu qui donc de 0 dans les 02 decomptes et enfin **prunepackage** qui est l'ensemble des doublon qui est de 0 ici