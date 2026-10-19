#include "NKWindow/NKMain.h"
#include "NKWindow/NKWindow.h"
#include "NKThreading/NkThreadPool.h"
#include "NKThreading/NkThread.h"
#include "NKContainers/Sequential/NkVector.h"
#include "NKTime/NkChrono.h"
#include "NKTime/NkElapsedTime.h"


void repetition(int i) {
    int somme=0;
    for (int j = 0; j< i; j++)
        somme+=i;
}

int nkmain(const nkentseu::NkEntryState& state) {
    nkentseu::NkChrono chrono;
    nkentseu::NkElapsedTime elapsed = chrono.Elapsed();

    // std::cout << "frfrfr";
    nkentseu::threading::NkThreadPool threadPool;
    int a = 100;
    for (int i = 0; i < 200; ++i) {
        threadPool.Enqueue([&] () {
            repetition(a);
        });
    }
    threadPool.Join();
    std::cout << "[VERSION 01] : temps ecoule : " << elapsed.milliseconds << " --  Ouvriers : " << threadPool.GetNumWorkers() << std::endl;

    a = 100;
    nkentseu::NkVector<nkentseu::threading::NkThread> threadList;
    for (int i = 0; i < 200; i++) {
        threadList.EmplaceBack([&] (auto&&...) {
                    repetition(a);
        });
    }
    for (int i = 0; i < threadList.size(); i++) {
        threadList[i].Join();
    }
    std::cout << "[VERSION 0] : temps ecoule : " << elapsed.milliseconds <<" -- Ouvriers : " << threadList.size();
    return 0;
}