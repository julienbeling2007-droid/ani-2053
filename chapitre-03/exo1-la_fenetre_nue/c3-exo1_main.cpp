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
     while (window.IsOpen()) { /* les evenements arrivent ici */ }
    return 0;
}
