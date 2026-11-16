
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

struct Image {
    string nom;
    double x, y;
    double largeur, hauteur;
    double echelle;
};

int main() {
    int N;
    cin >> N;

    vector<Image> images(N);

    // Lecture des images
    for (int i = 0; i < N; i++) {
        cin >> images[i].nom
            >> images[i].x
            >> images[i].y
            >> images[i].largeur
            >> images[i].hauteur
            >> images[i].echelle;
    }

    int Q;
    cin >> Q;

    int erreurs = 0;

    // Traitement des clics
    for (int k = 1; k <= Q; k++) {
        double px, py;
        cin >> px >> py;

        string A = "AUCUN";
        string B = "AUCUN";

        // Recherche à rebours : dernière image vers la première
        for (int i = N - 1; i >= 0; i--) {

            double demiLargeur =
                images[i].largeur * images[i].echelle / 2.0;

            double demiHauteur =
                images[i].hauteur * images[i].echelle / 2.0;

            if (abs(px - images[i].x) <= demiLargeur && abs(py - images[i].y) <= demiHauteur) {

                A = images[i].nom;
                break;
            }
        }

        // Recherche à l'endroit : première image vers la dernière
        for (int i = 0; i < N; i++) {

            double demiLargeur =
                images[i].largeur * images[i].echelle / 2.0;

            double demiHauteur =
                images[i].hauteur * images[i].echelle / 2.0;

            if (abs(px - images[i].x) <= demiLargeur &&
                abs(py - images[i].y) <= demiHauteur) {

                B = images[i].nom;
                break;
            }
        }

        // Comptage des erreurs
        if (A != B) {
            erreurs++;
        }

        cout << "CLIC " << k << " " << A << " " << B << "\n";
    }

    cout << "ERREURS " << erreurs << "\n";

    return 0;
}
