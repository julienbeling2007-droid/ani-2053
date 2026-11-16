#include <iostream>
#include "NkRef/NkRefView.h"
#include "NKMath/NKMath.h"

using namespace nkref;
using nkentseu::math::NkVec2f;

int main() {
    // 1. Déclaration d'un objet CONST
    const NkRefView vue{};
    
    // 2. Appel des méthodes const (autorisé)
    NkVec2f pixel{100.0f, 200.0f};
    NkVec2f viewport{800.0f, 600.0f};
    
    NkVec2f world = vue.PixelToWorld(pixel, viewport);
    float32 spacing = vue.GridSpacing(10.0f);
    
    std::cout << "world = (" << world.x << ", " << world.y << ")\n";
    std::cout << "spacing = " << spacing << "\n";
    
    // 3. LA LIGNE À DÉCOMMENTER POUR PROVOQUER L'ERREUR
     //vue.PanByPixels(1.0f, 0.0f);
    
    return 0;
}