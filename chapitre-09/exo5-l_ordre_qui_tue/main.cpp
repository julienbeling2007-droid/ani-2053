#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>

using namespace std;

// Structure pour stocker l'état d'un objet
struct Objet {
    string nom;
    bool libere = false;
};

// Fonction pour tenter de libérer un objet.
// Renvoie true si PLANTAGE (le programme doit s'arrêter).
// action : "FERME" ou "DETRUIT" (pour l'affichage).
bool liberer_objet(const string& nom, 
                   vector<Objet*>& tous_les_objets,
                   const map<string, vector<string>>& dependances,
                   const string& action) {
    
    // Trouver l'objet
    Objet* obj = nullptr;
    for (Objet* o : tous_les_objets) {
        if (o->nom == nom) { obj = o; break; }
    }
    
    if (!obj) return false; // Ne devrait pas arriver si l'entrée est valide
    if (obj->libere) return false; // Déjà libéré : on ignore silencieusement

    // Vérifier les dépendances
    auto it = dependances.find(nom);
    if (it != dependances.end()) {
        for (const string& dep : it->second) {
            // Trouver l'objet dépendant
            Objet* o_dep = nullptr;
            for (Objet* o : tous_les_objets) {
                if (o->nom == dep) { o_dep = o; break; }
            }
            if (o_dep && o_dep->libere) {
                cout << "PLANTAGE " << nom << " " << dep << endl;
                return true;
            }
        }
    }
    
    // Tout va bien : on libère
    obj->libere = true;
    cout << action << " " << nom << endl;
    return false;
}

int main() {
    // On stocke les objets par bloc.
    // Pile de blocs : chaque bloc est un vector<Objet*>.
    // Le bloc 0 est la fonction (racine).
    vector<vector<Objet*>> pile_blocs;
    pile_blocs.push_back({}); // Bloc principal
    
    vector<Objet*> tous_les_objets; // Pour les recherches
    map<string, vector<string>> dependances; // a -> liste de b
    
    string ligne;
    while (getline(cin, ligne)) {
        if (ligne.empty()) continue;
        
        stringstream ss(ligne);
        string cmd;
        ss >> cmd;
        
        if (cmd == "DECL") {
            string nom;
            ss >> nom;
            Objet* o = new Objet();
            o->nom = nom;
            pile_blocs.back().push_back(o); // Ajouter au bloc courant
            tous_les_objets.push_back(o);
        }
        else if (cmd == "DEPEND") {
            string a, b;
            ss >> a >> b;
            dependances[a].push_back(b); // Ordre de lecture conservé
        }
        else if (cmd == "FERME") {
            string x;
            ss >> x;
            if (liberer_objet(x, tous_les_objets, dependances, "FERME")) {
                return 0; // Plantage
            }
        }
        else if (cmd == "{") {
            pile_blocs.push_back({}); // Nouveau bloc
        }
        else if (cmd == "}") {
            // Fermer le bloc courant : détruire ses objets en ordre inverse
            if (pile_blocs.size() > 1) { // Sécurité
                vector<Objet*> bloc = pile_blocs.back();
                pile_blocs.pop_back();
                
                // Ordre inverse
                for (int i = bloc.size() - 1; i >= 0; --i) {
                    if (liberer_objet(bloc[i]->nom, tous_les_objets, dependances, "DETRUIT")) {
                        return 0;
                    }
                }
            }
        }
    }
    
    // --- FIN DE L'ENTRÉE : fermer le bloc principal ---
    // On ferme tous les blocs restants (normalement un seul, mais sécurité)
    while (pile_blocs.size() > 0) {
        vector<Objet*> bloc = pile_blocs.back();
        pile_blocs.pop_back();
        
        for (int i = bloc.size() - 1; i >= 0; --i) {
            if (liberer_objet(bloc[i]->nom, tous_les_objets, dependances, "DETRUIT")) {
                return 0;
            }
        }
    }
    
    cout << "PROPRE" << endl;
    return 0;
}