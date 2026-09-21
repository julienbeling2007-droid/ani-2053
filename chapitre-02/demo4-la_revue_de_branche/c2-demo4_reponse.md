## demo4 : revu de la branche

### les branches et basculement chez le voisin

```
PS F:\ani-2053_Demo4> git branch -r
  origin/HEAD -> origin/main
  origin/feat/adding-calculator // branche coequipier
  origin/feature/resolveur-equations // ma branche
  origin/main
  // basculement vers l'autre branche

PS F:\ani-2053_Demo4> git switch feat/adding-calculator
branch 'feat/adding-calculator' set up to track 'origin/feat/adding-calculator'.
Switched to a new branch 'feat/adding-calculator'
```

### les commits
```
PS F:\ani-2053_Demo4> git log  --oneline
56cb5d1 (HEAD -> feat/adding-calculator, origin/feat/adding-calculator) fix: math.h include path
12ef236 test: Adding 5 and 7
d833d7a Adding Multiplication and Division funtions
198ebf9 feat: Adding Addition and Substraction functions
3ecb6f2 (main) feature: Commit initial comportant l'espace initial du travail
11bb1d5 Initialisation du dépot
200ef50 Delete regles-de-travail.md
ab3c4a8 doc: Ajoute les règles de travail du dépot
```
en fait cette branche implementais une mini calculatrice basé sur l'addition soustraction, multiplication et division. les commits inutiles ici sont:Ajoute les règles de travail du dépot,
manque: bon agencement des commit notamment le dernier adding 5 and 7