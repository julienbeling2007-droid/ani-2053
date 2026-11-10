#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>

using namespace std;

int main() {
    int N;
    if (!(cin >> N)) return 0;
    cin.ignore(); // Pour vider le buffer après la lecture de N

    // On stocke toutes les lignes pour pouvoir les traiter 2 fois :
    // une fois pour vérifier les COPY, et une fois pour simuler.
    vector<string> lignes(N);
    for (int i = 0; i < N; ++i) {
        getline(cin, lignes[i]);
    }

    // --- 1. Vérification des COPY ---
    vector<int> refuses;
    for (int i = 0; i < N; ++i) {
        stringstream ss(lignes[i]);
        string cmd, a, b;
        ss >> cmd;
        if (cmd == "COPY") {
            ss >> a >> b;
            refuses.push_back(i + 1);
        }
    }

    if (!refuses.empty()) {
        for (int k : refuses) {
            cout << "REFUSE " << k << endl;
        }
        return 0; // On s'arrête net
    }

    // --- 2. Simulation ---
    // assoc : variable -> id de l'objet possédé (0 = nul)
    map<string, int> assoc;
    
    // ordre : liste des variables dans l'ordre de première apparition
    vector<string> ordre;
    
    // Pour savoir si une variable a déjà été vue
    map<string, bool> vue;
    
    int prochain_id = 1; // Prochain objet à créer
    int crees = 0;
    int detruits = 0;
    int nuls = 0;

    // Fonction utilitaire pour "faire apparaître" une variable (l'ajouter à ordre si pas encore vue)
    auto apparaitre = [&](const string& v) {
        if (!vue[v]) {
            vue[v] = true;
            ordre.push_back(v);
        }
    };

    // Fonction utilitaire pour détruire l'objet tenu par une variable (si elle en a un)
    auto detruire = [&](const string& v) {
        int id = assoc[v];
        if (id != 0) {
            cout << "DETRUIT " << id << endl;
            detruits++;
            assoc[v] = 0;
        }
    };

    for (int i = 0; i < N; ++i) {
        stringstream ss(lignes[i]);
        string cmd;
        ss >> cmd;

        if (cmd == "NEW") {
            string a;
            ss >> a;
            apparaitre(a);
            // Si a tenait un objet, il meurt
            detruire(a);
            // Création du nouvel objet
            int nouvel_id = prochain_id++;
            assoc[a] = nouvel_id;
            crees++;
        }
        else if (cmd == "MOVE") {
            string a, b;
            ss >> a >> b;
            apparaitre(a);
            apparaitre(b);
            
            // b meurt s'il tenait un objet
            detruire(b);
            
            // b prend ce que a tenait
            assoc[b] = assoc[a];
            assoc[a] = 0;
        }
        else if (cmd == "RESET") {
            string a;
            ss >> a;
            apparaitre(a);
            detruire(a);
        }
        else if (cmd == "USE") {
            string a;
            ss >> a;
            apparaitre(a);
            if (assoc[a] == 0) {
                cout << "NUL " << (i + 1) << " " << a << endl;
                nuls++;
            }
        }
    }

    // --- 3. Fin du programme : destruction dans l'ordre inverse ---
    for (int i = ordre.size() - 1; i >= 0; --i) {
        const string& v = ordre[i];
        detruire(v);
    }

    // --- 4. Bilan ---
    cout << "CREES " << crees << endl;
    cout << "DETRUITS " << detruits << endl;
    cout << "NULS " << nuls << endl;

    return 0;
}