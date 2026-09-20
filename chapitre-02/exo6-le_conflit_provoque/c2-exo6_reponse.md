## Exercice 6

### message du premier push

```
PS F:\exo2> git add .
PS F:\exo2> git commit -m "avancement"
[main a507cd4] avancement
 1 file changed, 1 insertion(+), 1 deletion(-)
PS F:\exo2> git push
Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 8 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 289 bytes | 289.00 KiB/s, done.
Total 3 (delta 2), reused 0 (delta 0), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (2/2), completed with 2 local objects.
To https://github.com/julienbeling2007-droid/exo2.git
   cef2a88..a507cd4  main -> main
PS F:\exo2> 

```
### message du second push pour le refus

```
PS C:\exo2> git add .
PS C:\exo2> git commit -m "ordonnance 2"
[main 6a0530f] ordonnance 2
 1 file changed, 1 insertion(+), 1 deletion(-)
PS C:\exo2> git push
To https://github.com/julienbeling2007-droid/exo2.git
 ! [rejected]        main -> main (fetch first)
error: failed to push some refs to 'https://github.com/julienbeling2007-droid/exo2.git'
hint: Updates were rejected because the remote contains work that you do not
hint: have locally. This is usually caused by another repository pushing to
hint: the same ref. If you want to integrate the remote changes, use
hint: 'git pull' before pushing again.
hint: See the 'Note about fast-forwards' in 'git push --help' for details.
PS C:\exo2> 

```

### conflit 

```
PS C:\exo2> git pull
remote: Enumerating objects: 5, done.
remote: Counting objects: 100% (5/5), done.
remote: Compressing objects: 100% (1/1), done.
remote: Total 3 (delta 2), reused 3 (delta 2), pack-reused 0 (from 0)
Unpacking objects: 100% (3/3), 269 bytes | 11.00 KiB/s, done.
From https://github.com/julienbeling2007-droid/exo2
   cef2a88..a507cd4  main       -> origin/main
Auto-merging main.cpp
CONFLICT (content): Merge conflict in main.cpp
Automatic merge failed; fix conflicts and then commit the result.
PS C:\exo2> 

#include <iostream>

int main(){
    int a;
    int b; 
    int c;
<<<<<<< HEAD
    std::cout <<"entrez un nombre decimal"<<std::endl;
=======
    std::cout <<"entrez un nombre entier"<<std::endl;
>>>>>>> a507cd48285dd80d8b2cbe8a47105d3133626441
    std::cin>> a;
    std::cout <<"entrez un nombre"<<std::endl;
    std::cin>> b;

    c= a+b;

    std::cout<<c;
}

```

### resolution du conflit 
il suffit ici simplement de prendre la ligne la plus adapté parmi celle provoquant le conflit
```
#include <iostream>

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

PS C:\exo2> git commit -m "ordonnance"
[main 40b9d8e] ordonnance
PS C:\exo2> git push
Enumerating objects: 10, done.
Counting objects: 100% (10/10), done.
Delta compression using up to 8 threads
Compressing objects: 100% (6/6), done.
Writing objects: 100% (6/6), 659 bytes | 219.00 KiB/s, done.
Total 6 (delta 4), reused 0 (delta 0), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (4/4), completed with 2 local objects.
To https://github.com/julienbeling2007-droid/exo2.git
   a507cd4..40b9d8e  main -> main
PS C:\exo2> 
```
