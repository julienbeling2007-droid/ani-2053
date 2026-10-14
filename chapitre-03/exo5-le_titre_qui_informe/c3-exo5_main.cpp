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