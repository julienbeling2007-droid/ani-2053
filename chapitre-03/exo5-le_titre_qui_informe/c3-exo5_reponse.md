## exercice 5 : modification du texte d'etat en fonction du moment

code source:
```cpp
#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"
#include "NKEvent/NkKeyboardEvent.h"
#include "NKEvent/NkWindowEvent.h"
#include <iostream>
#include <string>

using namespace nkentseu;

// Fonction dédiée à la mise à jour du titre
void modifiertitre(NkWindow& window, const std::string& document, bool isModified) {
    math::NkVec2u size = window.GetSize();
    
    // Construction de la chaîne : Document * (Largeur x Hauteur)
    std::string title = document;
    if (isModified) {
        title += " *";
    }
    title += " - (" + std::to_string(size.x) + "x" + std::to_string(size.y) + ")";

    window.SetTitle(title.c_str());
}

int nkmain(const NkEntryState& state) {
    NkWindowConfig cfg;
    cfg.width  = 1280;
    cfg.height = 800;

    NkWindow window(cfg);
    if (!window.IsOpen()) {
        return -1;
    }

    // État du document
    std::string document = "exo_5.docx";
    bool isModified     = false;

    // 1. Initialisation du titre au démarrage
    modifiertitre(window, document, isModified);

    while (window.IsOpen()) {
        while (NkEvent* ev = NkEvents().PollEvent()) {
            if (ev->Is<NkWindowCloseEvent>()) {
                window.Close();
            }
            else if (auto* kp = ev->As<NkKeyPressEvent>()) {
                if (kp->GetKey() == NkKey::NK_ESCAPE) {
                    window.Close();
                }
                // Appuyer sur 'I' simule une modification du document
                else if (kp->GetKey() == NkKey::NK_I) {
                    if (!isModified) {
                        isModified = true;
                        modifiertitre(window, document, isModified); 
                        std::cout <<"\ndocument modifie !!";
                    }
                }
                // Appuyer sur 'A' pour enlever l'asterix 
                else if (kp->GetKey() == NkKey::NK_A) {
                    if (isModified) {
                        isModified = false;
                        modifiertitre(window, document, isModified);
                        std::cout <<"\ndocument sauvegarde !!";
                    }
                }
            }
            // 2. Mise à jour lors du redimensionnement de la fenêtre
            else if (ev->Is<NkWindowResizeEvent>()) {
                modifiertitre(window, document, isModified);

                math::NkVec2u size = window.GetSize();
                std::cout << "\nla taille : ( "<< size.height<<"H , "<<size.width<<" W ) redimentionne"; 
            }
        }
    }

    return 0;
}

````

### explication des grandes lignes

```cpp
void modifiertitre(NkWindow& window, const std::string& document, bool isModified) {
    math::NkVec2u size = window.GetSize();
    
    // Construction de la chaîne : Document * (Largeur x Hauteur)
    std::string title = document;
    if (isModified) {
        title += " *";
    }
    title += " - (" + std::to_string(size.x) + "x" + std::to_string(size.y) + ")";

    window.SetTitle(title.c_str());
}
```
fonction qui consiste à afficher une asterix devant le nom de la fenetre  en fonction de la valeur de la variable modified et le retourne le titre en question avec l'asterix

```cpp
int nkmain(const NkEntryState& state) 
    NkWindowConfig cfg;
    cfg.width  = 1280;
    cfg.height = 800;
```
ici on definit l'entrée du programme et les caractéristiques de la fenetre

```cpp
NkWindow window(cfg);
    if (!window.IsOpen()) {
        return -1;
    }
```
ici on crée la fenetre et on verifie si elle est ouverte si c'est pas le cas le programme retourne -1

```cpp
    std::string document = "exo_5.docx";
    bool isModified     = false;
```
on definit le nom du titre ainsi que la valeur initial de la variable modified

```cpp
 modifiertitre(window, document, isModified);
```
ici on initialise la fonction au depart

```cpp

    while (window.IsOpen()) {
        while (NkEvent* ev = NkEvents().PollEvent()) {
            if (ev->Is<NkWindowCloseEvent>()) {
                window.Close();
            }
            else if (auto* kp = ev->As<NkKeyPressEvent>()) {
                if (kp->GetKey() == NkKey::NK_ESCAPE) {
                    window.Close();
                }
                // Appuyer sur 'I' simule une modification du document
                else if (kp->GetKey() == NkKey::NK_I) {
                    if (!isModified) {
                        isModified = true;
                        modifiertitre(window, document, isModified); 
                        std::cout <<"\ndocument modifie !!";
                    }
                }
                // Appuyer sur 'A' pour enlever l'asterix 
                else if (kp->GetKey() == NkKey::NK_A) {
                    if (isModified) {
                        isModified = false;
                        modifiertitre(window, document, isModified);
                        std::cout <<"\ndocument sauvegarde !!";
                    }
                }
            }
            // 2. Mise à jour lors du redimensionnement de la fenêtre
            else if (ev->Is<NkWindowResizeEvent>()) {
                modifiertitre(window, document, isModified);

                math::NkVec2u size = window.GetSize();
                std::cout << "\nla taille : ( "<< size.height<<"H , "<<size.width<<" W ) redimentionne"; 
            }
        }
    }
```
ici en fonction de l'evenement il y a apparition ou disparition de l'asterix

### demonstration
```
la taille : ( 800H , 1280 W ) redimentionne
document modifie !!
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  ◀  FIN D'EXECUTION  —  termine normalement  (4.65s)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
PS C:\projetWindow\firstwindow\window> jenga run

╔══════════════════════════════════════════════════════════════════╗
║                                                                  ║
║                ██╗███████╗███╗   ██╗ ██████╗  █████╗             ║
║                ██║██╔════╝████╗  ██║██╔════╝ ██╔══██╗            ║
║                ██║█████╗  ██╔██╗ ██║██║  ███╗███████║            ║
║           ██   ██║██╔══╝  ██║╚██╗██║██║   ██║██╔══██║            ║
║           ╚█████╔╝███████╗██║ ╚████║╚██████╔╝██║  ██║            ║
║            ╚════╝ ╚══════╝╚═╝  ╚═══╝ ╚═════╝ ╚═╝  ╚═╝            ║
║                                                                  ║
║             Multi-platform C/C++ Build System v2.8.4             ║
║                                                                  ║
╚══════════════════════════════════════════════════════════════════╝


━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  ▶  EXECUTION  —  window.exe
     C:\projetWindow\firstwindow\Build\Bin\Debug-Windows\window\window.exe
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━


la taille : ( 800H , 1280 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
la taille : ( 800H , 750 W ) redimentionne
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  ◀  FIN D'EXECUTION  —  termine normalement  (11.50s)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
PS C:\projetWindow\firstwindow\window> jenga run

╔══════════════════════════════════════════════════════════════════╗
║                                                                  ║
║                ██╗███████╗███╗   ██╗ ██████╗  █████╗             ║
║                ██║██╔════╝████╗  ██║██╔════╝ ██╔══██╗            ║
║                ██║█████╗  ██╔██╗ ██║██║  ███╗███████║            ║
║           ██   ██║██╔══╝  ██║╚██╗██║██║   ██║██╔══██║            ║
║           ╚█████╔╝███████╗██║ ╚████║╚██████╔╝██║  ██║            ║
║            ╚════╝ ╚══════╝╚═╝  ╚═══╝ ╚═════╝ ╚═╝  ╚═╝            ║
║                                                                  ║
║             Multi-platform C/C++ Build System v2.8.4             ║
║                                                                  ║
╚══════════════════════════════════════════════════════════════════╝


━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  ▶  EXECUTION  —  window.exe
     C:\projetWindow\firstwindow\Build\Bin\Debug-Windows\window\window.exe
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━


la taille : ( 800H , 1280 W ) redimentionne
document modifie !!
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  ◀  FIN D'EXECUTION  —  termine normalement  (311.58s)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
PS C:\projetWindow\firstwindow\window> 
```
```