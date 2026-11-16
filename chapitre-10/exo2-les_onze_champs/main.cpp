
#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;

    int restent = 0;
    int changes = 0;

    for (int i = 1; i <= N; i++) {
        int id;
        double x, y, echelle, rotation, opacite;
        int miroirX, miroirY;
        int largeur, hauteur;
        int selectionne;
        string chemin;
        int octets;

        cin >> id >> x >> y >> echelle >> rotation
            >> opacite >> miroirX >> miroirY
            >> largeur >> hauteur >> selectionne
            >> chemin >> octets;

        if (octets == 0) {
            cout << "ITEM " << i << " SAUTE\n";
            continue;
        }

        restent++;

        cout << "ITEM " << i << " " << restent;

        int compteur = 0;

        if (id != 0) {
            cout << " id";
            compteur++;
        }

        if (selectionne != 0) {
            cout << " selected";
            compteur++;
        }

        if (chemin != "-") {
            cout << " sourcePath";
            compteur++;
        }

        if (compteur == 0) {
            cout << " AUCUN";
        }

        cout << "\n";

        changes += compteur;
    }

    cout << "RESTENT " << restent << "\n";
    cout << "CHANGES " << changes << "\n";

    return 0;
}
