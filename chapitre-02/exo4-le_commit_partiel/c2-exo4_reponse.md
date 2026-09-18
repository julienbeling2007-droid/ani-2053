## Exercice4: Commit Partiel

### commit1

```
PS F:\exo1> git add -p .                      
diff --git a/ajout3.md b/ajout3.md
index 431a866..4fc4f76 100644
--- a/ajout3.md
+++ b/ajout3.md
@@ -1 +1 @@
-## aurevoir les amis
\ No newline at end of file
+## aurevoir les combis
\ No newline at end of file
(1/1) Stage this hunk [y,n,q,a,d,e,p,?]? y

PS F:\exo1> git commit -m "premier changement de ajout3.md"
[main 6cc7f70] premier changement de ajout3.md
 1 file changed, 1 insertion(+), 1 deletion(-)

```
### commit2

```
PS F:\exo1> git add -p .
diff --git a/ajout3.md b/ajout3.md
index 4fc4f76..c95ba62 100644
--- a/ajout3.md
+++ b/ajout3.md
@@ -1 +1 @@
-## aurevoir les combis
\ No newline at end of file
+## adieux les combis
\ No newline at end of file
(1/1) Stage this hunk [y,n,q,a,d,e,p,?]? y

PS F:\exo1> git commit -m "deuxième changement de ajout3.md" 
[main 3510878] deuxième changement de ajout3.md
 1 file changed, 1 insertion(+), 1 deletion(-)

```

### affichage de l'historique

```
PS F:\exo1> git log -p
commit 35108788328eee0416d436bf62c36ce0ac9a6c24 (HEAD -> main)
Author: Beling <julienbeling2007@gmail.com>
Date:   Fri Sep 18 21:24:33 2026 +0100

    deuxième changement de ajout3.md

diff --git a/ajout3.md b/ajout3.md
index 4fc4f76..c95ba62 100644
--- a/ajout3.md
+++ b/ajout3.md
@@ -1 +1 @@
-## aurevoir les combis
\ No newline at end of file
+## adieux les combis
\ No newline at end of file

commit 6cc7f7032d349f5e026b2786d5adce52796aa03b (origin/main, origin/HEAD)
Author: Beling <julienbeling2007@gmail.com>
Date:   Fri Sep 18 21:23:19 2026 +0100

    premier changement de ajout3.md
diff --git a/ajout3.md b/ajout3.md
index 431a866..4fc4f76 100644
--- a/ajout3.md
+++ b/ajout3.md
@@ -1 +1 @@
-## aurevoir les amis
\ No newline at end of file
+## aurevoir les combis
\ No newline at end of file

```
commande utilisés: `git add -p .`: ajouter des modifications de facon interactive.
`git log -p .`: afficher l'historique des commits de façon interactive