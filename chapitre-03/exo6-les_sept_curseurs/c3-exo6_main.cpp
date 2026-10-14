#include "NKWindow/NKMain.h"
#include "NKWindow/NKWindow.h"
#include "NKEvent/NkEventSystem.h"
#include "NKEvent/NkWindowEvent.h"


using namespace nkentseu;

int nkmain(const NkEntryState& state) {
    NkWindowConfig cfg;
    cfg.width   =   1000;
    cfg.height  =   720;
    cfg.title   =   "exercice6 7 zones";

    NkWindow window;
    if(!window.Create(cfg)) {
        logger.Error("[APP] : Erreur de creation de la fenetre");
        return -1;
    }

    while (window.IsOpen()) {
        while(NkEvent* e = NkEvents().PollEvent()) {
            if (e->Is<NkWindowCloseEvent>())
                window.Close();
            if(auto* m = e->As<NkMouseMoveEvent>()) {
                if (m->GetX() < window.GetSize().width / 7) {
                    window.SetCursor(NkWindow::NkCursorType::Arrow);
                }
                if (m->GetX() >= window.GetSize().width / 7 && m->GetX() < window.GetSize().width * 2 / 7) {
                    window.SetCursor(NkWindow::NkCursorType::Hand);
                }
                if (m->GetX() >= window.GetSize().width * 2 / 7 && m->GetX() < window.GetSize().width * 3 / 7) {
                    window.SetCursor(NkWindow::NkCursorType::ResizeNESW);
                }
                if (m->GetX() >= window.GetSize().width * 3 / 7 && m->GetX() < window.GetSize().width * 4 / 7) {
                    window.SetCursor(NkWindow::NkCursorType::ResizeNS);
                }
                if (m->GetX() >= window.GetSize().width * 4 / 7 && m->GetX() < window.GetSize().width * 5 / 7) {
                    window.SetCursor(NkWindow::NkCursorType::ResizeNWSE);
                }
                if (m->GetX() >= window.GetSize().width * 5 / 7 && m->GetX() < window.GetSize().width * 6 / 7) {
                    window.SetCursor(NkWindow::NkCursorType::ResizeWE);
                }
                if (m->GetX() >= window.GetSize().width * 6 / 7) {
                    window.SetCursor(NkWindow::NkCursorType::TextInput);
                }
            }
        }
    }
    

    return 0;
}