#include "NKWindow/NkWindow.h"
#include "NKWindow/NkMain.h"
#include "NKCanvas/App/NkCanvasApp.h"

// Un dessinable qui herite de NkDrawable et redefinit Draw.
// Il envoie quatre sommets a la cible, en NK_LINES.
class Lignes : public nkentseu::renderer::NkDrawable {
    public:
    Lignes(nkentseu::math::NkColor color) : mColor(color) { }

    void Draw(nkentseu::renderer::NkRenderTarget &target, const nkentseu::renderer::NkRenderStates &states) const override {
        nkentseu::renderer::NkVertex vk[6];

        auto makeVk = [&] (nkentseu::float32 x, nkentseu::float32 y) {
            nkentseu::renderer::NkVertex v;
            v.x = x;
            v.y = y;
            v.r = mColor.r;
            v.g = mColor.g;
            v.b = mColor.b;
            v.a = mColor.a;

            return v;
        };

        // NK_LINES prend les sommets deux par deux : deux segments
        vk[0] = makeVk(100.f, 300.f);
        vk[1] = makeVk(200.f, 400.f);
        vk[2] = makeVk(200.f, 400.f);
        vk[3] = makeVk(350.f, 200.f);
        vk[4] = makeVk(350.f, 200.f);
        vk[5] = makeVk(100.f, 300.f);


        // point d'arret ici pour relever la pile d'appels
        target.Draw(vk, 6, nkentseu::renderer::NkPrimitiveType::NK_LINES, states);
    }

    private:
    nkentseu::math::NkColor mColor;
};

class Appelants : public nkentseu::renderer::NkCanvasApp {
    public:
    Appelants() : mObj({3, 74, 97}) {
        Config().title        =    "sommet dessinés";
        Config().width        =    1200;
        Config().height       =    700;
        Config().clearColor   =    {246, 10, 24};
    }

    void OnRender(nkentseu::renderer::NkRenderWindow &target) override {
        target.Draw(mObj);
    }

    private:
    Lignes mObj;
};

int nkmain(const nkentseu::NkEntryState& state) {
    return nkentseu::renderer::NkCanvasApp::Run<Appelants>(state);
}