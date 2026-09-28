## Exercice3: les bornes

### 1. code source de l'exercice

```cpp
#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"

using namespace nkentseu;

int nkmain(const NkEntryState &state){

    NkWindowConfig cfg; // declaration de la struct pour les caractéristiques de le fenetre

    cfg.title= "première fenetre";
    cfg.width=1000;
    cfg.height= 720;
    cfg.minWidth=150;
    cfg.minHeight=150;
    
    // LES DIFFERENTS DROITS
    cfg.frame= true;
    cfg.resizable=true;
    cfg.minimizable=true;
    cfg.movable=true;
    cfg.closable=true;
    cfg.maximizable=true;
    cfg.canFullscreen=false;

    NkWindow window(cfg);
    math::NkVec2u sz = window.GetSize();

    std::cout<< sz.width <<std::endl;
    std::cout << sz.height <<std::endl;
    
    if (!window.IsOpen()) {
        logger.Error("[app] creation fenetre echouee");
        return -1;
    }
     while (window.IsOpen()) { 
        while (NkEvent* ev = NkEvents().PollEvent()) {
            if (ev->Is<NkWindowCloseEvent>()) {
                window.Close();
            }
            if(auto* vz= ev->As<NkWindowResizeEvent>()){
                math::NkVec2u sz=window.GetSize();

                std::cout<< "nouvelle taille:" << sz.width <<" ,"<<sz.height<<"."<<std::endl;
            }
      }
    }
    return 0;
}
```
### 2. explication des modifications

l'exercice 3 il nous a été demandé de mettre une taille minimum que la fenetre devra avoir et de redimensionner la fenetre pour voir la taille minimal à laquel on peut redimensionner la fenetre

**math::NkVec2u sz = window.GetSize()**: ici il s'agit d'une fonction qui recupère la taille de la fenetre (hauteur comme longueur)

**std::cout<< sz.width <<std::endl;std::cout << sz.height <<std::endl;**: afficher la taille de la fenetre au moyen de la variable sz qui contient la taille de la fenetre fourni par la propriété `window.Getsize`

**if(auto* vz= ev->As<NkWindowResizeEvent>())**: condition si l'evènement entrer par lutilisateur est un redimensionnement


### 3. taille minimale

dans le code suivant j'ai fixé la taille minimal à 150 pour la hauteur ainsi que la longueur . mais en redimensionnant je me suis rendu compte que la taille minimal de la fenetre après avoir reduit est de 
`134` en longueur et `111` en largeur

### 4. preuve ecrite

```
╔══════════════════════════════════════════════════════════════════╗
║                                                                  ║
║                ██╗███████╗███╗   ██╗ ██████╗  █████╗             ║
║                ██║██╔════╝████╗  ██║██╔════╝ ██╔══██╗            ║
║                ██║█████╗  ██╔██╗ ██║██║  ███╗███████║            ║
║           ██   ██║██╔══╝  ██║╚██╗██║██║   ██║██╔══██║            ║
║           ╚█████╔╝███████╗██║ ╚████║╚██████╔╝██║  ██║            ║
║            ╚════╝ ╚══════╝╚═╝  ╚═══╝ ╚═════╝ ╚═╝  ╚═╝            ║
║                                                                  ║
║             Multi-platform C/C++ Build System v2.8.0             ║
║                                                                  ║
╚══════════════════════════════════════════════════════════════════╝


━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  ▶  EXECUTION  —  window.exe
     C:\projetWindow\firstwindow\Build\Bin\Debug-Windows\window\window.exe
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

1000
720
nouvelle taille:1000 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,720.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.
nouvelle taille:134 ,111.

```