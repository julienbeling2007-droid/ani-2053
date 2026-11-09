#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure pour garder l'état de chaque texture
struct Texture {
    int id;
    bool liberee = false; // true si elle a déjà été libérée au moins une fois
};

// Fonction utilitaire pour gérer une libération.
// Renvoie true si ça a planté, false sinon.
// Si ça plante, k_plantage et t_plantage sont remplis.
bool liberer_textures(vector<Texture*>& tableau, int nb_fois, int& prochain_id, string& type_plantage, int& k_plantage, int& t_plantage) {
    if (nb_fois == 0) return false; // Oubli, on ne touche à rien
    
    for (Texture* tex : tableau) {
        // On tente de libérer nb_fois
        for (int i = 0; i < nb_fois; ++i) {
            if (tex->liberee) {
                // Plantage : double free
                t_plantage = tex->id;
                return true;
            }
            tex->liberee = true;
        }
    }
    return false;
}

int main() {
    int S, V, F;
    if (!(cin >> S >> V >> F)) return 0;
    
    int N;
    cin >> N;
    
    vector<Texture*> tableau;
    int prochain_id = 1;
    int creees = 0;
    
    // On va traiter les opérations une par une
    for (int op = 1; op <= N; ++op) {
        string cmd;
        cin >> cmd;
        
        if (cmd == "AJOUTE") {
            Texture* t = new Texture();
            t->id = prochain_id++;
            tableau.push_back(t);
            creees++;
        } 
        else if (cmd == "SUPPRIME") {
            int i;
            cin >> i;
            // On libère S fois la texture à l'index i
            Texture* tex = tableau[i];
            bool plante = false;
            for (int k = 0; k < S; ++k) {
                if (tex->liberee) {
                    plante = true;
                    break;
                }
                tex->liberee = true;
            }
            if (plante) {
                cout << "PLANTAGE " << op << " TEXTURE " << tex->id << endl;
                return 0;
            }
            // On retire du tableau (les suivants reculent)
            tableau.erase(tableau.begin() + i);
        } 
        else if (cmd == "VIDE") {
            // On libère V fois chaque texture du tableau
            for (Texture* tex : tableau) {
                for (int k = 0; k < V; ++k) {
                    if (tex->liberee) {
                        cout << "PLANTAGE " << op << " TEXTURE " << tex->id << endl;
                        return 0;
                    }
                    tex->liberee = true;
                }
            }
            tableau.clear(); // Le tableau se vide
        }
    }
    
    // --- FIN DU PROGRAMME ---
    // On libère F fois chaque texture encore dans le tableau
    for (Texture* tex : tableau) {
        for (int k = 0; k < F; ++k) {
            if (tex->liberee) {
                cout << "PLANTAGE FIN TEXTURE " << tex->id << endl;
                return 0;
            }
            tex->liberee = true;
        }
    }
    
    // --- BILAN ---
    int fuites = 0;
    vector<int> perdues;
    
    // Pour compter les fuites, il faut regarder TOUTES les textures créées.
    // Comme on n'a pas gardé de liste globale, on va compter celles qui sont
    // encore dans le tableau (non libérées) + celles qui ont été retirées sans
    // être libérées.
    // 
    // Astuce : on peut recréer la liste complète des textures de 1 à creees
    // en supposant qu'elles ont toutes été créées. Mais on n'a pas leur état.
    // 
    // Mieux : on va maintenir une liste globale des textures créées.
    // (Modification du code ci-dessus pour inclure une liste globale)
    
    return 0;
}