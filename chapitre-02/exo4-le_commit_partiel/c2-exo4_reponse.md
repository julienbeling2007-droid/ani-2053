## Exercice4: Commit Partiel

### commit1

```
PS F:\exo1> git add -p ajout1.md
warning: in the working copy of 'ajout1.md', LF will be replaced by CRLF the next time Git touches it
warning: in the working copy of 'ajout1.md', LF will be replaced by CRLF the next time Git touches it
diff --git a/ajout1.md b/ajout1.md
index b1de865..fc47d2d 100644
--- a/ajout1.md
+++ b/ajout1.md
@@ -1,4 +1,4 @@
-## bonsoir les amis
+## bonsoir les gars
 comment vous allez ?
 moi bien en tout cas
 un champignon dans la rue
(1/2) Stage this hunk [y,n,q,a,d,j,J,g,/,e,p,?]? y
@@ -6,4 +6,4 @@ j'aime la banane et le plantain
 t'inquiète t'aura ton yaourt
 -bonjour les amis comment vous allez les gars
\ No newline at end of file
+bonjour les amis comment vous allez les filles
\ No newline at end of file
(2/2) Stage this hunk [y,n,q,a,d,K,g,/,e,p,?]? n
PS F:\exo1> git commit -m "premier changement au niveau de l'introduction"
[main db9125c] premier changement au niveau de l'introduction
 1 file changed, 1 insertion(+), 1 deletion(-)
 

```
### commit2

```
PS F:\exo1> git add -p ajout1.md                                          
warning: in the working copy of 'ajout1.md', LF will be replaced by CRLF the next time Git touches it
warning: in the working copy of 'ajout1.md', LF will be replaced by CRLF the next time Git touches it
diff --git a/ajout1.md b/ajout1.md
index 7d56ff4..fc47d2d 100644
--- a/ajout1.md
+++ b/ajout1.md
@@ -6,4 +6,4 @@ j'aime la banane et le plantain
 t'inquiète t'aura ton yaourt
 
 
-bonjour les amis comment vous allez les gars
\ No newline at end of file
+bonjour les amis comment vous allez les filles
\ No newline at end of file
(1/1) Stage this hunk [y,n,q,a,d,e,p,?]? y

PS F:\exo1> git commit -m "dernier changement en conclusion"
[main a6b1da4] dernier changement en conclusion
 1 file changed, 1 insertion(+), 1 deletion(-)

```

### affichage de l'historique

```
commit a6b1da433a1025ccb7cec54a0758ec895a2baf83 (HEAD -> main, origin/main, origin/HEAD)
Author: Beling <julienbeling2007@gmail.com>
Date:   Fri Sep 18 23:02:18 2026 +0100

    dernier changement en conclusion

diff --git a/ajout1.md b/ajout1.md
index 7d56ff4..fc47d2d 100644
--- a/ajout1.md
+++ b/ajout1.md
@@ -6,4 +6,4 @@ j'aime la banane et le plantain
 t'inquiète t'aura ton yaourt
 
 
-bonjour les amis comment vous allez les gars
\ No newline at end of file
+bonjour les amis comment vous allez les filles
\ No newline at end of file

commit db9125cbab50b6a635f429a80032449c4572a6b0
Author: Beling <julienbeling2007@gmail.com>
Date:   Fri Sep 18 23:01:20 2026 +0100

premier changement au niveau de l'introduction

diff --git a/ajout1.md b/ajout1.md
index b1de865..7d56ff4 100644
--- a/ajout1.md
+++ b/ajout1.md
@@ -1,4 +1,4 @@
-## bonsoir les amis
+## bonsoir les gars
 comment vous allez ?
 moi bien en tout cas
 un champignon dans la rue

commit c008f277434a368433c27ec5efe04671e4a65bed
Author: Beling <julienbeling2007@gmail.com>
Date:   Fri Sep 18 22:58:23 2026 +0100

```
