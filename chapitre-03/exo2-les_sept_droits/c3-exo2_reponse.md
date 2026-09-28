# Exercice2: les seps droits

## code de la fenetre avec les septs droits activés

```cpp
#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"

using namespace nkentseu;

int nkmain(const NkEntryState &state){

    NkWindowConfig cfg; // declaration de la struct pour les caractéristiques de le fenetre

    cfg.title= "première fenetre";
    cfg.width=1000;
    cfg.height= 720;
    
    // LES DIFFERENTS DROITS
    cfg.frame= true;
    cfg.resizable=true;
    cfg.minimizable=true;
    cfg.movable=true;
    cfg.closable=true;
    cfg.maximizable=true;
    cfg.canFullscreen=true;

    NkWindow window(cfg);
    
    if (!window.IsOpen()) {
        logger.Error("[app] creation fenetre echouee");
        return -1;
    }
     while (window.IsOpen()) { 
        while (NkEvent* ev = NkEvents().PollEvent()) {
            if (ev->Is<NkWindowCloseEvent>()) {
                window.Close();
            }
      }
    }
    return 0;
}

```

### 1. première fenetre avec desactivation de frame(false)

* effet observé  :
ici nous avons la fenetre qui n'a aucune option de fermeture ni de d'agrandissement ni de repli en gros ici on ferme la porte avec `ctrl+c`

* effet attendu :
quand frame est à false on s'attend qu'il n'est plus la barre de titre et les bordures

### 2. deuxième fenetre avec desactivation de rezisable(false)

* effet observé :
ici on remarque que meme en mettant resizable à false la comportement ne change pas 
* effet attendu :
la fenetre devrai normalement ne plus pouvoir se redimensionner mais c'est toujours les cas

### 3. troisième fenetre avec desactivation de minimizable

* effet observé : le comportement de la fenetre est toujours pareil ça ne change pas 

*effet attendu : ici l'utilisateur en temps normal ne pourra pas diminuer la taille de la fenetre ce qui n'est pas le cas

### 4. quatrième fenètre avec desactivation de maximizable

* effet observé : le comportement de la fenetre ne change pas il reste le meme comme si c'tait à true

* effet attendu : ici l'utilisateur dans les normes ne pourra pas agrandir ce qui n'est pas le cas on en deduis que l'effet observé est en desaccord avec l'effet attendu

### 5. cinquième fenetre avec desactivation de movable

* effet observé : ici la fenetre est toujours pareil , le comportement ne change pas


* effet attendu : l'utilisateur ici doit normalement ne plus pouvoir deplacé la fenetre en maintenant le clique sur la barre de titre mais cela n'est pas le cas la fenetre est toujours deplaceable

### 6. sixième fenetre avec desactivation de closable 

* effet observé : comportement inchangée de la fenetre 


* effet attendu : l'utilisateur ne devrais pas pouvoir fermé la fenetre avec la croix mais il peut au contraire

### 7. septième fenetre avec desactivation de canfullscreen

* effet observé : ici le  comportement de la fenetre reste inchangée


* effet attendu :  l'utilisateur ne devra plus faire en sorte que la fenetre prenne tout l'ecran mais au contraire en appuyant sur le bouton d'agrandissement dans la barre de titre cela est bien possible
