# EXERCICE1: FENETRE A NUE

## 1. code d'ouverture de la fenetre

```cpp
#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"

using namespace nkentseu;

int nkmain(const NkEntryState &state){

    NkWindowConfig cfg; // declaration de la struct pour les caractéristiques de le fenetre

    cfg.title= "première fenetre";
    cfg.width=1000;
    cfg.height= 720;

    NkWindow window(cfg);
    
    if (!window.IsOpen()) {
        logger.Error("[app] creation fenetre echouee");
        return -1;
    }
     while (window.IsOpen()) { 
        while (window.IsOpen()) { 
        while (NkEvent* ev = NkEvents().PollEvent()) {
            if (ev->Is<NkWindowCloseEvent>()) {
                window.Close();
            }
      }
    }
      }
    return 0;
}
```
## 2. explication du code 

ce programme  compte 24 lignes de code donc 2 lignes pour les includes l'autre pour le namespace et le reste pour le programme proprement dit

` #include "NKWindow/NKWindow.h` : permet d'inclure les fichiers d'entetes de Nkwindow

`#include "NKWindow/NKMain.h"`: permet inclure le point d'entrée portable+ prototype nkmain

`using namespace nkentseu`: definition du namespace pour les classes et les types sans avoir besoin de nkentseu::

`int nkmain(const NkEntryState &state)`: point d'entrée du programme

`NkWindowConfig cfg:` declaration du type NkwindowConfig pour les caractéristiques de la fenetre

` cfg.title=` "première fenetre": titre de la fenetre

`cfg.width=1000:` longueur de la fenetre

`cfg.height= 720:` largeur de le fenetre

`NkWindow window(cfg):` declaration de la fenetre Nkwindow pour par le système d'exploitation ayant pour argument les caractéristiques de la fenetre

` if (!window.IsOpen():` condition lorsque la fenetre n'est pas ouverte

`logger.Error("[app] creation fenetre echouee"):` message d'erreur lors de l'echec d'ouverture de la fenetre de NKwindow

`return -1`: valeur retourner en cas d'echec

`while (window.IsOpen())`: boucle lorsque la fenetre est ouverte
`while (NkEvent* ev = NkEvents().PollEvent()) `: boucle qui consiste à stocké les eventuels evènements
`  if (ev->Is<NkWindowCloseEvent>())`: condition lorsque l'on clique sur la croix de la fenetre
` window.Close();`: fermeture de la fenetre


`return 0`: sortie du programme

## 3. conclusion

le programme fenetre à nue ouvre effectivement une fenetre mais cette fenetre n'est pas doté des evènements notamment celle pour faire le programme. ici la seul façon par exemple de fermé un programme est soit `ctrl+c` soit lorsque tu veux ferme le programme tu clique sur `ferme programme`




