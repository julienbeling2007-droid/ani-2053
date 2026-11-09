#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;

// Structure pour stocker les infos d'une méthode
struct Methode {
    string nom;
    bool declaree_const; // true si "const", false si "-"
    bool modifie;        // true si 1
    vector<string> appels;
    
    // Pour la simulation des passes
    bool est_const_simule;
    bool peut_etre_const;
};

int main() {
    int n;
    if (!(cin >> n)) return 0;
    
    map<string, Methode> methodes;
    vector<string> ordre_lecture; // Pour garder l'ordre d'affichage
    
    // --- 1. LECTURE DES DONNÉES ---
    for (int i = 0; i < n; ++i) {
        string nom;
        string declaree;
        int modifie;
        int k;
        cin >> nom >> declaree >> modifie >> k;
        
        Methode m;
        m.nom = nom;
        m.declaree_const = (declaree == "const");
        m.modifie = (modifie == 1);
        m.est_const_simule = m.declaree_const; // On initialise avec l'état de base
        m.peut_etre_const = true; // On suppose que oui au début
        
        for (int j = 0; j < k; ++j) {
            string appel;
            cin >> appel;
            m.appels.push_back(appel);
        }
        
        methodes[nom] = m;
        ordre_lecture.push_back(nom);
    }

    // --- 2. CALCUL DE "POURRAIT" ---
    // Une méthode ne peut pas être const si elle modifie l'objet.
    // On propage ensuite l'incapacité : si A appelle B, et B ne peut pas, A ne peut pas.
    // On fait une propagation jusqu'à stabilité (algorithme du point fixe).
    
    bool changement = true;
    while (changement) {
        changement = false;
        for (auto& pair : methodes) {
            Methode& m = pair.second;
            if (!m.peut_etre_const) continue;
            
            if (m.modifie) {
                m.peut_etre_const = false;
                changement = true;
                continue;
            }
            
            for (const string& appel : m.appels) {
                if (!methodes[appel].peut_etre_const) {
                    m.peut_etre_const = false;
                    changement = true;
                    break;
                }
            }
        }
    }

    // --- 3. AFFICHAGE POURRAIT ---
    // Liste des méthodes non déclarées const mais qui pourraient l'être
    vector<string> pourrait;
    for (const string& nom : ordre_lecture) {
        if (!methodes[nom].declaree_const && methodes[nom].peut_etre_const) {
            pourrait.push_back(nom);
        }
    }
    
    cout << "POURRAIT";
    if (pourrait.empty()) {
        cout << " AUCUN";
    } else {
        for (const string& nom : pourrait) cout << " " << nom;
    }
    cout << endl;

    // --- 4. CALCUL DE "RACINES" ---
    // Une racine est une méthode de POURRAIT qui n'appelle QUE des méthodes const (déjà déclarées).
    vector<string> racines;
    for (const string& nom : pourrait) {
        bool ok = true;
        for (const string& appel : methodes[nom].appels) {
            if (!methodes[appel].declaree_const) {
                ok = false;
                break;
            }
        }
        if (ok) racines.push_back(nom);
    }
    
    cout << "RACINES";
    if (racines.empty()) {
        cout << " AUCUN";
    } else {
        for (const string& nom : racines) cout << " " << nom;
    }
    cout << endl;

    // --- 5. CALCUL DE "PASSES" ---
    // Simulation : à chaque passe, on déclare const toutes les méthodes de POURRAIT
    // qui ne sont pas encore const mais dont tous les appels sont déjà const.
    
    int passes = 0;
    int restant = pourrait.size();
    
    if (restant > 0) {
        while (restant > 0) {
            vector<string> a_declarer;
            
            // Identifier celles qu'on peut déclarer à cette passe
            for (const string& nom : pourrait) {
                if (methodes[nom].est_const_simule) continue; // Déjà const
                
                bool pret = true;
                for (const string& appel : methodes[nom].appels) {
                    if (!methodes[appel].est_const_simule) {
                        pret = false;
                        break;
                    }
                }
                if (pret) a_declarer.push_back(nom);
            }
            
            // Si on ne peut rien déclarer, c'est une boucle infinie (ne devrait pas arriver
            // selon les garanties de l'énoncé, mais on évite le crash).
            if (a_declarer.empty()) break;
            
            // Appliquer les déclarations (en même temps)
            for (const string& nom : a_declarer) {
                methodes[nom].est_const_simule = true;
                restant--;
            }
            passes++;
        }
    }
    
    cout << "PASSES " << passes << endl;

    return 0;
}