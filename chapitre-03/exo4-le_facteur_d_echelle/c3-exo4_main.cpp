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