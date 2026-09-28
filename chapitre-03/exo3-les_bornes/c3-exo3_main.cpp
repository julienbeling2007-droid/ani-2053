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