## EXERCICE10: FUSIONNER OU REJOUER

### ajout par fusion
```
PS F:\exo1> git checkout -b fusion // creation de la branche fusion
Switched to a new branch 'fusion'
PS F:\exo1> git add text.txt
PS F:\exo1> git commit -m "première fusion"
[fusion faa920e] première fusion
 1 file changed, 1 insertion(+)
 create mode 100644 text.txt
PS F:\exo1> git switch main // basculer sur la branche main pour faire diverger les 02 branches
Switched to branch 'main' 
Your branch is ahead of 'origin/main' by 1 commit.
  (use "git push" to publish your local commits)
PS F:\exo1> git add .
PS F:\exo1> git commit -m "divergence"
[main 86cd3ca] divergence
 1 file changed, 1 insertion(+)
 create mode 100644 action.txt
PS F:\exo1> git switch main
Already on 'main'
Your branch is ahead of 'origin/main' by 2 commits.
  (use "git push" to publish your local commits)
PS F:\exo1> git merge fusion
Merge made by the 'ort' strategy.
 text.txt | 1 +
 1 file changed, 1 insertion(+)
 create mode 100644 text.txt
 ```
 ### graphe de fusion

 ```
 PS F:\exo1> git log --graph --oneline --all
*   fa8a1aa (HEAD -> main) Merge branch 'fusion'
|\  
| * faa920e (fusion) première fusion
* | 86cd3ca divergence
|/  
* 29fa76c commit à debusqué
* b36349d (origin/main, origin/HEAD) Revert "Reapply "commit poussé sur github""
* e1b8718 Reapply "commit poussé sur github"
* c6e1847 Revert "commit poussé sur github"
* 3fdb6f2 commit poussé sur github
* b67bce6 eau
* 23f351a changement involontaire
* eeb9a8c gigantesque
* de6a6fb amélioration push
* 1dcf758 refait push
* f409d1e premier push
* a6b1da4 dernier changement en conclusion
* db9125c premier changement au niveau de l'introduction
* c008f27 3
* 7ebd9db 2
* 4a8beb5 1
* 3510878 deuxième changement de ajout3.md
* 6cc7f70 premier changement de ajout3.md
| * b4dff57 (origin/julien, julien) troisième modification
| * 31ccfc7 deuxième modification sur ajout2.md
| * 0543ac7 première modification sur ajout2.md
|/  
* de121e3 julien debut
* f4ee8ae ajout v2
* b09112f ajout3
* 46800b4 ajout2
* fb185d9 ajout1
* a0b51a8 Initial commit
```

### ajout en rejouant

```
PS F:\exo1> git reset --hard HEAD^ // REMETTRE LE DEPOT DANS SON ETAT AVANT LE MERGE
HEAD is now at 86cd3ca divergence
PS F:\exo1> git switch fusion
Switched to branch 'fusion'
PS F:\exo1> git rebase main
Successfully rebased and updated refs/heads/fusion.
PS F:\exo1> git switch main
Switched to branch 'main'
Your branch is ahead of 'origin/main' by 2 commits.
  (use "git push" to publish your local commits)
PS F:\exo1> git merge fusion --ff-only          
Updating 86cd3ca..7a237f5
Fast-forward
 text.txt | 1 +
 1 file changed, 1 insertion(+)
 create mode 100644 text.txt
```

### GRAPHE DE REJOUANT

```
PS F:\exo1> git log --graph --oneline --all
* 7a237f5 (HEAD -> main, fusion) première fusion
* 86cd3ca divergence
* 29fa76c commit à debusqué
* b36349d (origin/main, origin/HEAD) Revert "Reapply "commit poussé sur github""
* e1b8718 Reapply "commit poussé sur github"
* c6e1847 Revert "commit poussé sur github"
* 3fdb6f2 commit poussé sur github
* b67bce6 eau
* 23f351a changement involontaire
* eeb9a8c gigantesque
* de6a6fb amélioration push
* 1dcf758 refait push
* f409d1e premier push
* a6b1da4 dernier changement en conclusion
* db9125c premier changement au niveau de l'introduction
* c008f27 3
* 7ebd9db 2
* 4a8beb5 1
* 3510878 deuxième changement de ajout3.md
* 6cc7f70 premier changement de ajout3.md
| * b4dff57 (origin/julien, julien) troisième modification
| * 31ccfc7 deuxième modification sur ajout2.md
| * 0543ac7 première modification sur ajout2.md
|/  
* de121e3 julien debut
* f4ee8ae ajout v2
* b09112f ajout3
* 46800b4 ajout2
* fb185d9 ajout1
* a0b51a8 Initial commit

```

*CONCLUSION: le meilleur integration ici est celui par fusion car il montre les differents commit des branches parallèles avec leur commit dans le graphe pour une meilleure visualisation pour les debutant tandis que celle en **rejouant** prend les modificaions des branches parallèles pour les coller au dernier sur le dernier commit de la branche principal(main). donc ici la difference est plus dans l'organisation des commits 