## Exercice 11: le fichier donc je n'aurai pas du

### COMMIT DU FICHIER DE 10MO(bigfile.dat)
```
PS F:\exo1> git add bigfile.dat
PS F:\exo1> git commit -m "Ajout volontaire d'un fichier de 10 Mo"
[main 51680a5] Ajout volontaire d'un fichier de 10 Mo
 1 file changed, 0 insertions(+), 0 deletions(-)
 create mode 100644 bigfile.dat

 PS F:\exo1> (Get-ChildItem -Path .git -Recurse | Measure-Object -Property Length -Sum).Sum / 1MB // stockage du .git 
10.0776262283325
```
### suppression du fichier dans le prochain commit et taille du .git final
```
PS F:\exo1> git rm bigfile.dat
rm 'bigfile.dat'
PS F:\exo1> git rm bigfile.dat
rm 'bigfile.dat'
PS F:\exo1> git commit -m "Suppression du gros fichier"
[main 8e633ea] Suppression du gros fichier
 1 file changed, 0 insertions(+), 0 deletions(-)
 delete mode 100644 bigfile.dat
PS F:\exo1> (Get-ChildItem -Path .git -Recurse | Measure-Object -Property Length -Sum).Sum / 1MB
10.0780305862427
```

**conclusion**
meme après avoir supprimer le fichier bigfile.bat dans le dernier commit cela n'affecte pas la taille du .git car github etant une plateforme de versionning stocke de façon immuable toute les versions du projet