
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int main() {

    int H;
    cin >> H;

    vector<string> hashes(H);
    vector<unordered_set<string>> historique;

    unordered_map<string, int> position;

    unordered_set<string> fonctions;

    // Lecture des commits
    for (int i = 0; i < H; i++) {

        string action;
        int k;

        cin >> hashes[i] >> action >> k;

        position[hashes[i]] = i;

        for (int j = 0; j < k; j++) {

            string f;
            cin >> f;

            if (action == "AJOUTE") {
                fonctions.insert(f);
            }
            else if (action == "RETIRE") {
                fonctions.erase(f);
            }
        }

        // Sauvegarder l'etat apres chaque commit
        historique.push_back(fonctions);
    }

    // Lecture des annonces
    int A;
    cin >> A;

    int mensonges = 0;

    for (int i = 0; i < A; i++) {

        string hash, etat, fonction;

        cin >> hash >> etat >> fonction;

        int debut = position[hash];

        // Verifier si l'annonce est vraie a un commit
        auto estFausse = [&](int commit) {

            bool presente =
                historique[commit].find(fonction)
                != historique[commit].end();

            if (etat == "A_VENIR") {
                return presente;
            }
            else {
                return !presente;
            }
        };

        cout << "ANNONCE " << i + 1 << " ";

        // Verification au dernier commit
        if (!estFausse(H - 1)) {

            cout << "VRAI" << endl;

        }
        else {

            mensonges++;

            int j = H - 1;

            // Remonter tant que l'annonce reste fausse
            while (j > debut && estFausse(j - 1)) {
                j--;
            }

            cout << "MENT " << hashes[j] << endl;
        }
    }

    // Affichage du nombre total de mensonges
    cout << "MENSONGES " << mensonges << endl;

    return 0;
}
