## Exercice7: conflit pour ne provoquer aucun conflit

### code initial(main.cpp) sur la branch main
```
int main(){
    int a;
    int b;
    int c;
    std::cout <<"entrez un nombre decimal"<<std::endl;
    std::cin>> a;
    std::cout <<"entrez un nombre"<<std::endl;
    std::cin>> b;

    c= a+b;

    std::cout<<c;
}
```
### premiere modification et sa sortie lors du push sur une branche nouvelle branche pour simuler la première personne

**nom de la branche: julien**
creation de la branche git switch -c julien
```
int main(){
    int a;
    int b;
    float c;
    std::cout <<"entrez un nombre decimal"<<std::endl;
    std::cin>> a;
    std::cout <<"entrez un nombre"<<std::endl;
    std::cin>> b;

    c= a+b;

    std::cout<<c;
}
```
**sortie attendu**
PS C:\exo2> git switch -c julien
Switched to a new branch 'julien'
PS C:\exo2> git add .
PS C:\exo2> git commit -m "premier changement de main.cpp"
[julien 4e7d17a] premier changement de main.cpp
 1 file changed, 1 insertion(+), 1 deletion(-)

 ### deuxième modification et sortie du push

 **nom de la branche: bob**
 creation de la branche:git switch -c bob

 ```
int main(){
    int a;
    int b; 
    int c;
    std::cout <<"entrez un nombre decimal"<<std::endl;
    std::cin>> a;
    std::cout <<"entrez un nombre"<<std::endl;
    std::cin>> b;

    c= a*b;

    std::cout<<c;
}
 ```
**sortie attendu**
 PS C:\exo2> git switch main
Switched to branch 'main'
Your branch is up to date with 'origin/main'.
PS C:\exo2> git switch -c bob
Switched to a new branch 'bob'
PS C:\exo2> git add .
PS C:\exo2> git commit -m "deuxième changement de main.cpp

### fusion et resultat final qui fusionne les deux branches qui representent des personnes sur la branche principal main 
 
#### fusion de bob et julien sur main
```
int main(){
    int a;
    int b; 
    float c;
    std::cout <<"entrez un nombre decimal"<<std::endl;
    std::cin>> a;
    std::cout <<"entrez un nombre"<<std::endl;
    std::cin>> b;

    c= a*b;

    std::cout<<c;
}
```
**sortie attendu**
PS C:\exo2> git switch main
Switched to branch 'main'
Your branch is up to date with 'origin/main'.
PS C:\exo2> git merge julien
Updating 8e0685c..4e7d17a
Fast-forward
 main.cpp | 2 +-
 1 file changed, 1 insertion(+), 1 deletion(-)
PS C:\exo2> git merge bob
Auto-merging main.cpp
Merge made by the 'ort' strategy.
 main.cpp | 2 +-
 1 file changed, 1 insertion(+), 1 deletion(-)


 **conclusion**: pour cet exercice j'ai crée 2 branches correspondant à 2 personnes et de plus il y avait la branche mère main pour recevoir les fusions
