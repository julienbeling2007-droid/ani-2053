## exo7: les septs zone

code source

```cpp
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
```

## explication des grandes lignes

```cpp
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
```
ici on a l'entrée du programme , les caractéristiques de la fenetre et une  erreur au cas où la fenetre ne se crée pas

```cpp
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
```
au cas où la fenetre  s'ouvre  on mets les evenement dans la file grace à  `NkEvents().PollEvent())`
et maintenant l'evènement quand on ferme avec la croix cela est possible avec `e->Is<NkWindowCloseEvent`
, l'evenement de detection de la souris et les conditions pour limiter les espaces en divisant la fenetre en 7