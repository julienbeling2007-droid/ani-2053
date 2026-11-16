
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
    vector<string> modele;
    vector<string> textures;
    vector<string> sources;

    bool ajoutTextures = false;
    bool ajoutSources = false;

    bool supTextures = false;
    bool supSources = false;

    bool echTextures = false;
    bool echSources = false;

    // Lecture des trois lignes de configuration
    string ligne;
    string operation, nomTableau;

    getline(cin, ligne);
    {
        stringstream ss(ligne);
        ss >> operation;

        while (ss >> nomTableau) {
            if (nomTableau == "textures")
                ajoutTextures = true;
            else if (nomTableau == "sources")
                ajoutSources = true;
        }
    }

    getline(cin, ligne);
    {
        stringstream ss(ligne);
        ss >> operation;

        while (ss >> nomTableau) {
            if (nomTableau == "textures")
                supTextures = true;
            else if (nomTableau == "sources")
                supSources = true;
        }
    }

    getline(cin, ligne);
    {
        stringstream ss(ligne);
        ss >> operation;

        while (ss >> nomTableau) {
            if (nomTableau == "textures")
                echTextures = true;
            else if (nomTableau == "sources")
                echSources = true;
        }
    }

    int N;
    cin >> N;

    // Exécution des opérations du modèle
    for (int k = 0; k < N; k++) {
        string op;
        cin >> op;

        if (op == "AJOUTE") {
            string nom;
            cin >> nom;

            modele.push_back(nom);

            if (ajoutTextures)
                textures.push_back(nom);

            if (ajoutSources)
                sources.push_back(nom);
        }

        else if (op == "SUPPRIME") {
            int c;
            cin >> c;

            vector<int> indices(c);

            for (int j = 0; j < c; j++) {
                cin >> indices[j];
            }

            // Suppression du plus grand index au plus petit
            for (int j = c - 1; j >= 0; j--) {
                int i = indices[j];

                modele.erase(modele.begin() + i);

                if (supTextures && i < (int)textures.size())
                    textures.erase(textures.begin() + i);

                if (supSources && i < (int)sources.size())
                    sources.erase(sources.begin() + i);
            }
        }

        else if (op == "MONTE") {
            int i;
            cin >> i;

            // Vérifier que la voisine existe dans le modèle
            if (i + 1 < (int)modele.size()) {
                swap(modele[i], modele[i + 1]);

                if (echTextures && i + 1 < (int)textures.size())
                    swap(textures[i], textures[i + 1]);

                if (echSources && i + 1 < (int)sources.size())
                    swap(sources[i], sources[i + 1]);
            }
        }

        else if (op == "DESCEND") {
            int i;
            cin >> i;

            if (i > 0 && i < (int)modele.size()) {
                swap(modele[i], modele[i - 1]);

                if (echTextures && i < (int)textures.size())
                    swap(textures[i], textures[i - 1]);

                if (echSources && i < (int)sources.size())
                    swap(sources[i], sources[i - 1]);
            }
        }
    }

    // Déterminer la longueur du plus grand tableau
    int L = max({modele.size(), textures.size(), sources.size()});

    int decales = 0;

    // Affichage des trois tableaux alignés
    for (int i = 0; i < L; i++) {
        string m = "-";
        string t = "-";
        string s = "-";

        bool existeM = i < (int)modele.size();
        bool existeT = i < (int)textures.size();
        bool existeS = i < (int)sources.size();

        if (existeM) m = modele[i];
        if (existeT) t = textures[i];
        if (existeS) s = sources[i];

        cout << i << " " << m << " " << t << " " << s << "\n";

        if (!existeM || !existeT || !existeS ||
            m != t || m != s) {
            decales++;
        }
    }

    cout << "DECALES " << decales << "\n";

    return 0;
}
