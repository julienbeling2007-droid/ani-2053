#include "NKWindow/NKMain.h"
#include "NKWindow/NKWindow.h"
#include "NKLogger/NkLog.h"

// NKCanvas
#include "NKCanvas/Renderer/Targets/NkRenderWindow.h"
#include "NKCanvas/Core/NkContextDesc.h"
#include "NKCanvas/Core/NkGraphicsApi.h"
#include "NKCanvas/App/NkCanvasApp.h"
#include "NKCanvas/Renderer/Core/NkRenderer2D.h"


using namespace nkentseu;
using namespace nkentseu::renderer;

NKENTSEU_DEFINE_APP_DATA(([](){
    nkentseu::NkAppData d{};
    d.appName="fenetre2D";
    d.appVersion="1.0.0";
    return d;
})());

class fenetre2D : public NkCanvasApp{

   public: fenetre2D(){
    Config().title= "fenetre2D";
    Config().width= 1000;
    Config().height=720;
    Config().clearColor= NkColor2D{ 255, 0, 0 };
    }
};

int nkmain(const NkEntryState &state){
    return  NkCanvasApp::Run<fenetre2D>(state);
}