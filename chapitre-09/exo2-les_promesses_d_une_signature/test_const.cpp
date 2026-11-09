#include <iostream>
// L'include fonctionnera car on a configuré le chemin ci-dessus
#include "NkRef/NkRefView.h" 

int main() {
    // Déclaration d'un objet CONSTANT (la promesse du compilateur)
    const nkref::NkRefView vue{};

    // Appel de méthodes qui ont le "const final" (autorisé)
    // Remplace les arguments par ceux attendus par la vraie signature
    auto resultat = vue.PixelToWorld({0.0f, 0.0f}); 
    auto espace = vue.GridSpacing();

    std::cout << "Les methodes const fonctionnent sur un objet const." << std::endl;

    // --- LA LIGNE A DECOMMENTER POUR PROVOQUER L'ERREUR ---
    // vue.PanByPixels(1.0f, 0.0f); 
    
    return 0;
}