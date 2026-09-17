# Exercice1

## affichage de chaque historique de commit

### commit1

```
fb185d9 (HEAD -> main, origin/main, origin/HEAD) ajout1
a0b51a8 Initial commit

```
### commit2

```
46800b4 (HEAD -> main, origin/main, origin/HEAD) ajout2
fb185d9 ajout1
a0b51a8 Initial commit

```

### commit 3

```
b09112f (HEAD -> main, origin/main, origin/HEAD) ajout3
46800b4 ajout2
fb185d9 ajout1
a0b51a8 Initial commit

```
**`commande utilisé`**: `git log --oneline`

## construction du graphe

```
commit b09112fb84a938a59acc4e43a8bf6b71e1ae6817 (HEAD -> main, origin/main, origin/HEAD)
| Author: Beling <julienbeling2007@gmail.com>
| Date:   Thu Sep 17 22:23:05 2026 +0100
| 
|     ajout3
| 
* commit 46800b4df201276f21328e2c77a81e6c3f0e5ced
| Author: Beling <julienbeling2007@gmail.com>
| Date:   Thu Sep 17 22:22:00 2026 +0100
| 
|     ajout2
| 
* commit fb185d9b64dfc622a1699a74464544dd553731ce
| Author: Beling <julienbeling2007@gmail.com>
| Date:   Thu Sep 17 22:18:21 2026 +0100
| 
|     ajout1
| 
* commit a0b51a8245e891fefad8fd6fe92d04c4ce8f12f4
  Author: JULIEN BELING <julienbeling2007@gmail.com>
  Date:   Thu Sep 17 21:55:11 2026 +0100
  
      Initial commit

```

**`commande utilisée`**: `git log --graph`
