
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n, c, a;

    // Lecture de la liste AVANT
    string mot;
    cin >> mot >> n;

    vector<string> avant(n);

    for (int i = 0; i < n; i++) {
        cin >> avant[i];
    }

    // Lecture de la liste CORRIGE
    cin >> mot >> c;

    vector<string> corrige(c);

    for (int i = 0; i < c; i++) {
        cin >> corrige[i];
    }

    // Lecture de la liste APRES
    cin >> mot >> a;

    vector<string> apres(a);

    for (int i = 0; i < a; i++) {
        cin >> apres[i];
    }

    // Compteurs
    int v = 0;
    int f = 0;
    int o = 0;
    int nouvelles = 0;

    // Parcours de la liste AVANT
    for (int i = 0; i < n; i++) {

        bool estCorrige = find(corrige.begin(), corrige.end(), avant[i]) != corrige.end();

        bool estApres = find(apres.begin(), apres.end(), avant[i]) != apres.end();

        cout << i + 1 << " " << avant[i] << " ";

        if (estCorrige) {
            cout << "DEVENUE_FAUSSE" << endl;
            f++;
        }
        else if (estApres) {
            cout << "ENCORE_VRAIE" << endl;
            v++;
        }
        else {
            cout << "OUBLIEE" << endl;
            o++;
        }
    }

    // Comptage des nouvelles clés
    for (int i = 0; i < a; i++) {
        if (find(avant.begin(), avant.end(), apres[i]) == avant.end()) {
            nouvelles++;
        }
    }

    // Calcul de la part oubliée
    int p = 0;

    if (v + o != 0) {
        p = (100 * o) / (v + o);
    }

    // Affichage des résultats
    cout << "VRAIES " << v << endl;
    cout << "FAUSSES " << f << endl;
    cout << "OUBLIEES " << o << endl;
    cout << "NOUVELLES " << nouvelles << endl;
    cout << "PART_OUBLIEE " << p << endl;

    return 0;
}
