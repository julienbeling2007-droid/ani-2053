#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

// Fonction pour nettoyer une ligne (retirer commentaires et espaces)
string nettoyer_ligne(string ligne) {
    // 1. Couper au premier //
    size_t pos = ligne.find("//");
    if (pos != string::npos) {
        ligne = ligne.substr(0, pos);
    }
    // 2. Retirer tous les espaces
    string resultat = "";
    for (char c : ligne) {
        if (!isspace(c)) {
            resultat += c;
        }
    }
    return resultat;
}

// Fonction pour déterminer l'état d'une ligne
string determiner_etat(const string& ligne) {
    if (ligne.length() >= 8 && ligne.substr(ligne.length() - 8) == "=delete;") return "SUPPRIME";
    if (ligne.length() >= 9 && ligne.substr(ligne.length() - 9) == "=default;") return "DEFAUT";
    return "ECRIT";
}

int main() {
    string nom_classe;
    if (!getline(cin, nom_classe)) return 0;

    // Initialisation des 5 états
    string etat_destructeur = "ABSENT";
    string etat_copie = "ABSENT";
    string etat_affectation_copie = "ABSENT";
    string etat_deplacement = "ABSENT";
    string etat_affectation_deplacement = "ABSENT";

    string ligne_brute;
    while (getline(cin, ligne_brute)) {
        string ligne = nettoyer_ligne(ligne_brute);
        if (ligne.empty()) continue;

        // Préparation des motifs de recherche en remplaçant 'C' par le nom de la classe
        string motif_destructeur = "~" + nom_classe + "(";
        string motif_copie = nom_classe + "(const" + nom_classe + "&";
        string motif_affectation_copie = nom_classe + "&operator=(const" + nom_classe + "&";
        string motif_deplacement = nom_classe + "(" + nom_classe + "&&";
        string motif_affectation_deplacement = nom_classe + "&operator=(" + nom_classe + "&&";

        // --- ANALYSE ---
        
        // 1. Destructeur
        if (ligne.find(motif_destructeur) != string::npos) {
            etat_destructeur = determiner_etat(ligne);
        }
        // 2. Déplacement (on vérifie avant la copie car les motifs sont proches)
        else if (ligne.rfind(motif_deplacement, 0) == 0) { // rfind(..., 0) == 0 vérifie que ça commence par
            etat_deplacement = determiner_etat(ligne);
        }
        // 3. Affectation par déplacement
        else if (ligne.rfind(motif_affectation_deplacement, 0) == 0) {
            etat_affectation_deplacement = determiner_etat(ligne);
        }
        // 4. Copie (Attention au piège du second &)
        else if (ligne.rfind(motif_copie, 0) == 0) {
            // On vérifie que le caractère juste après le motif n'est pas un '&'
            size_t pos = motif_copie.length();
            if (pos >= ligne.length() || ligne[pos] != '&') {
                etat_copie = determiner_etat(ligne);
            }
        }
        // 5. Affectation par copie (Même piège)
        else if (ligne.rfind(motif_affectation_copie, 0) == 0) {
            size_t pos = motif_affectation_copie.length();
            if (pos >= ligne.length() || ligne[pos] != '&') {
                etat_affectation_copie = determiner_etat(ligne);
            }
        }
    }

    // --- AFFICHAGE DES ETATS ---
    cout << "DESTRUCTEUR " << etat_destructeur << endl;
    cout << "COPIE " << etat_copie << endl;
    cout << "AFFECTATION_COPIE " << etat_affectation_copie << endl;
    cout << "DEPLACEMENT " << etat_deplacement << endl;
    cout << "AFFECTATION_DEPLACEMENT " << etat_affectation_deplacement << endl;

    // --- APPLICATION DES REGLES ---
    bool destructeur_declare = (etat_destructeur != "ABSENT");
    bool copie_declaree = (etat_copie != "ABSENT");
    bool affectation_copie_declaree = (etat_affectation_copie != "ABSENT");
    bool deplacement_declare = (etat_deplacement != "ABSENT");
    bool affectation_deplacement_declaree = (etat_affectation_deplacement != "ABSENT");

    int nb_declares = destructeur_declare + copie_declaree + affectation_copie_declaree + deplacement_declare + affectation_deplacement_declaree;

    string regle = "INCOMPLETE";
    if (nb_declares == 0) {
        regle = "ZERO";
    } else if (nb_declares == 5) {
        regle = "CINQ";
    } else if (destructeur_declare && copie_declaree && affectation_copie_declaree && !deplacement_declare && !affectation_deplacement_declaree) {
        regle = "TROIS";
    }

    cout << "REGLE " << regle << endl;

    // --- AFFICHAGE DES MANQUES (si INCOMPLETE) ---
    if (regle == "INCOMPLETE") {
        bool au_moins_un_deplacement = deplacement_declare || affectation_deplacement_declaree;
        
        // Ordre demandé : DESTRUCTEUR, COPIE, AFFECTATION_COPIE, DEPLACEMENT, AFFECTATION_DEPLACEMENT
        if (!destructeur_declare) cout << "MANQUE DESTRUCTEUR" << endl;
        if (!copie_declaree) cout << "MANQUE COPIE" << endl;
        if (!affectation_copie_declaree) cout << "MANQUE AFFECTATION_COPIE" << endl;
        
        // On ne cite les manques de déplacements que si au moins un déplacement est déclaré
        if (au_moins_un_deplacement) {
            if (!deplacement_declare) cout << "MANQUE DEPLACEMENT" << endl;
            if (!affectation_deplacement_declaree) cout << "MANQUE AFFECTATION_DEPLACEMENT" << endl;
        }
    }

    // --- POSSEDE & UNIQUE ---
    cout << "POSSEDE " << (etat_destructeur == "ECRIT" ? "OUI" : "NON") << endl;
    
    bool unique = (etat_copie == "SUPPRIME" && (etat_deplacement == "ECRIT" || etat_deplacement == "DEFAUT"));
    cout << "UNIQUE " << (unique ? "OUI" : "NON") << endl;

    return 0;
}