# Exercice1

## affichage de chaque historique de commit

### commit1

```
ddeb1fc (HEAD -> main, origin/main)  mise en place de la salutation des amis

```
### commit2

```
4772970 (HEAD -> main, origin/main) implementation de l'addition de 2 nombres
ddeb1fc  mise en place de la salutation des amis
```

### commit 3

```
1ca7a84 (HEAD -> main, origin/main)  la separation des amis
4772970 implementation de l'addition de 2 nombres
ddeb1fc  mise en place de la salutation des amis

```
**`commande utilisé`**: `git log --oneline`

## construction du graphe

```
* commit 1ca7a849fb73646390e898d5c227f608b772bcdd (HEAD -> main, origin/main)
| Author: Beling <julienbeling2007@gmail.com>
| Date:   Fri Sep 18 07:02:50 2026 +0100
| 
|      la separation des amis
* commit 47729705a557b4f30127b1b7aec59fbb09e8a97f
| Author: Beling <julienbeling2007@gmail.com>
| Date:   Fri Sep 18 06:59:25 2026 +0100
| 
|     implementation de l'addition de 2 nombres
| 
* commit ddeb1fc44c481d41eb3c8ade666e7faa492b0407
  Author: Beling <julienbeling2007@gmail.com>
  Date:   Fri Sep 18 06:54:58 2026 +0100
  
       mise en place de la salutation des amis
```


**`commande utilisée`**: `git log --graph`
