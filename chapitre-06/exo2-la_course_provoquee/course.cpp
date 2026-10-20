#include "NKWindow/NKMain.h"
#include "NKWindow/NKWindow.h"
#include "NKThreading/NkThreadPool.h"
#include "NKThreading/NkThread.h"
#include "NKContainers/Sequential/NkVector.h"
#include "NKTime/NkChrono.h"
#include "NKTime/NkElapsedTime.h"

int nkmain(const nkentseu::NkEntryState& state) {
    //creation du compteur
    int compteur = 0;
    //creation des 8 thread
    nkentseu::NkVector<nkentseu::threading::NkThread> thread;
    thread.Reserve(8);
    for (int i = 0; i < 8; i++) {
        thread.EmplaceBack([&] (auto&&...) {
            for (int j = 0; j < 1000000; j++)
            compteur++;
        });
    }
    //join des thread
    for (auto& t: thread)
        t.Join();
    std::cout << "Valeur du compteur attendue : 8000000  valeur obtenue : " << compteur << std::endl;

    //cas sur  un Thread
    compteur=0;
    for(int i=0; i<1000000; i++){
        compteur+=1;
    }
    std::cout<<"la valeur attendue:1000000 valeur obtenu: " <<compteur<<std::endl;
   return 0;
}