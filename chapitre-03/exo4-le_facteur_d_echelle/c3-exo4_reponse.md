## exercice4: le facteur d'echelle

### code source 

```cpp
#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"

using namespace nkentseu;

void infosurface(NkWindow& window){
    math:: NkVec2u windowsize= window.GetSize(); // taille de la fenetre
    float32 dpi   = window.GetDpiScale();  // facteur d'exhelle
    float rendererw =window.GetSurfaceDesc().width;
    float rendererh =window.GetSurfaceDesc().height;

    std::cout<< windowsize.width <<" , "<< windowsize.height<<std::endl;
    std::cout<< rendererw <<" , "<< rendererh << std::endl;
    std::cout << dpi<<std::endl;
}

int nkmain(const NkEntryState &state){

    NkWindowConfig cfg; // declaration de la struct pour les caractéristiques de le fenetre

    cfg.title= "facteur d'echelle";
    cfg.width=1000;
    cfg.height= 720;
    
    NkWindow window(cfg);
    
    if (!window.IsOpen()) {
        logger.Error("[app] creation fenetre echouee");
        return -1;
    }

    infosurface(window);
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

### explication des ajouts

* `void infosurface(NkWindow& window)`: fonction qui ne retourne rien et qui a pour paramètre un type nkwindow

* `math:: NkVec2u windowsize= window.GetSize():`taille de la fenetre

* `float rendererw =window.GetSurfaceDesc().width:` taille du  rendu graphique en longueur

* `float rendererh =window.GetSurfaceDesc().height:` taille du rendu graphique en hauteur

* ` float32 dpi   = window.GetDpiScale():`facteur d'echelle de l'ecran

### preuve

#### test1
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

Loading workspace...

Configuration: Debug
Target:        Windows x86_64
Toolchain:     clang-mingw

Build Order (1 projects):
  1. window [CONSOLE_APP]


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: window                                                          Kind: CONSOLE_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: main.cpp
ℹ Linking...
✓ Built: Build\Bin\Debug-Windows\window\window.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 3.10s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  1/1
Time:           3.10s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════

PS C:\projetWindow\firstwindow> jenga run  

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

1000 , 720
1000 , 720
1
```

ici le facteur d'echelle vaut 1, la taille de la fenetre: `1000x720`, et le rendu graphique est de: `1000x720`

#### test2

```
PS C:\projetWindow\firstwindow> jenga run

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

998 , 712
998 , 712
1.25
```
ici la taille de l'ecran est pareil qu'au test 1 ainsi que le rendu graphique mais ce qui change ici est le facteur d'echelle de l'ecran qui est de 1.25 car elle a été modifié dans les paramètres d'ecran du système

