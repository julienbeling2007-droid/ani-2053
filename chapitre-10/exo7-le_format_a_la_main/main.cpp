
#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <cstring>
#include <iomanip>
#include <cmath>

using namespace std;

// Lire un octet
bool lireU8(const vector<unsigned char>& data,
            size_t& position, uint8_t& valeur) {

    if (position >= data.size())
        return false;

    valeur = data[position];
    position++;

    return true;
}

// Lire un entier non signe sur 4 octets
bool lireU32(const vector<unsigned char>& data,
             size_t& position, uint32_t& valeur) {

    if (data.size() - position < 4)
        return false;

    valeur = 0;

    for (int i = 0; i < 4; i++) {
        valeur |= (uint32_t)data[position] << (8 * i);
        position++;
    }

    return true;
}

// Lire un flottant IEEE 754 sur 4 octets
bool lireF32(const vector<unsigned char>& data,
             size_t& position, float& valeur) {

    uint32_t bits;

    if (!lireU32(data, position, bits))
        return false;

    memcpy(&valeur, &bits, sizeof(float));

    return true;
}

// Sauter un nombre d'octets
bool sauter(const vector<unsigned char>& data,
            size_t& position, uint32_t nombre) {

    if (nombre > data.size() - position)
        return false;

    position += nombre;

    return true;
}

// Structure d'une image
struct Image {
    float x, y, echelle, rotation, opacite;
    int mx, my;
    uint32_t largeur, hauteur, taille;
};

// Structure d'un point
struct Point {
    float x, y;
};

// Structure d'un trait
struct Trait {
    uint8_t r, g, b, a;
    float epaisseur;
    vector<Point> points;
};

// Afficher un flottant avec deux chiffres après la virgule
void afficherFloat(float valeur) {
    if (fabs(valeur) < 0.005)
        valeur = 0.0f;

    cout << fixed << setprecision(2) << valeur;
}

int main() {
    int T;
    cin >> T;

    vector<unsigned char> data;

    for (int i = 0; i < T; i++) {
        string hexadecimal;

        if (!(cin >> hexadecimal))
            break;

        unsigned int octet = stoul(hexadecimal, nullptr, 16);
        data.push_back((unsigned char)octet);
    }

    size_t position = 0;

    // Vérifier la signature NKRF
    if (data.size() < 4) {
        cout << "TRONQUE\n";
        return 0;
    }

    if (data[0] != 0x4E ||
        data[1] != 0x4B ||
        data[2] != 0x52 ||
        data[3] != 0x46) {

        cout << "PAS_UNE_PLANCHE\n";
        return 0;
    }

    position = 4;

    // Lire la version
    uint32_t version;

    if (!lireU32(data, position, version)) {
        cout << "TRONQUE\n";
        return 0;
    }

    if (version != 1) {
        cout << "VERSION_INCONNUE " << version << "\n";
        return 0;
    }

    // Lire la vue
    float cx, cy, zoom;

    if (!lireF32(data, position, cx) ||
        !lireF32(data, position, cy) ||
        !lireF32(data, position, zoom)) {

        cout << "TRONQUE\n";
        return 0;
    }

    // Lire le thème et la grille
    uint8_t theme, grille, ignore;

    if (!lireU8(data, position, theme) ||
        !lireU8(data, position, grille) ||
        !lireU8(data, position, ignore) ||
        !lireU8(data, position, ignore)) {

        cout << "TRONQUE\n";
        return 0;
    }

    // Lire le nombre d'images
    uint32_t nombreImages;

    if (!lireU32(data, position, nombreImages)) {
        cout << "TRONQUE\n";
        return 0;
    }

    vector<Image> images;

    // Lire chaque image
    for (uint32_t i = 0; i < nombreImages; i++) {
        Image image;
        uint8_t miroirX, miroirY;

        if (!lireF32(data, position, image.x) ||
            !lireF32(data, position, image.y) ||
            !lireF32(data, position, image.echelle) ||
            !lireF32(data, position, image.rotation) ||
            !lireF32(data, position, image.opacite) ||
            !lireU8(data, position, miroirX) ||
            !lireU8(data, position, miroirY) ||
            !lireU8(data, position, ignore) ||
            !lireU8(data, position, ignore) ||
            !lireU32(data, position, image.largeur) ||
            !lireU32(data, position, image.hauteur) ||
            !lireU32(data, position, image.taille)) {

            cout << "TRONQUE\n";
            return 0;
        }

        image.mx = (miroirX != 0) ? 1 : 0;
        image.my = (miroirY != 0) ? 1 : 0;

        // Sauter les octets de la source
        if (!sauter(data, position, image.taille)) {
            cout << "TRONQUE\n";
            return 0;
        }

        images.push_back(image);
    }

    // Lire le nombre de traits
    uint32_t nombreTraits;

    if (!lireU32(data, position, nombreTraits)) {
        cout << "TRONQUE\n";
        return 0;
    }

    vector<Trait> traits;

    // Lire chaque trait
    for (uint32_t i = 0; i < nombreTraits; i++) {
        Trait trait;
        uint32_t nombrePoints;

        if (!lireU8(data, position, trait.r) ||
            !lireU8(data, position, trait.g) ||
            !lireU8(data, position, trait.b) ||
            !lireU8(data, position, trait.a) ||
            !lireF32(data, position, trait.epaisseur) ||
            !lireU32(data, position, nombrePoints)) {

            cout << "TRONQUE\n";
            return 0;
        }

        // Lire les points du trait
        for (uint32_t j = 0; j < nombrePoints; j++) {
            Point point;

            if (!lireF32(data, position, point.x) ||
                !lireF32(data, position, point.y)) {

                cout << "TRONQUE\n";
                return 0;
            }

            trait.points.push_back(point);
        }

        traits.push_back(trait);
    }

    // Tout a été lu correctement : afficher le résultat

    cout << "VUE ";
    afficherFloat(cx);
    cout << " ";
    afficherFloat(cy);
    cout << " ";
    afficherFloat(zoom);
    cout << "\n";

    cout << "THEME "
         << (theme != 0 ? "SOMBRE" : "CLAIR") << "\n";

    cout << "GRILLE "
         << (grille == 0 ? "AFFICHEE" : "CACHEE") << "\n";

    cout << "IMAGES " << images.size() << "\n";

    for (size_t i = 0; i < images.size(); i++) {
        const Image& image = images[i];

        cout << "IMAGE " << i + 1 << " ";

        afficherFloat(image.x);
        cout << " ";
        afficherFloat(image.y);
        cout << " ";
        afficherFloat(image.echelle);
        cout << " ";
        afficherFloat(image.rotation);
        cout << " ";
        afficherFloat(image.opacite);

        cout << " " << image.mx
             << " " << image.my
             << " " << image.largeur
             << " " << image.hauteur
             << " " << image.taille << "\n";
    }

    cout << "TRAITS " << traits.size() << "\n";

    for (size_t i = 0; i < traits.size(); i++) {
        const Trait& trait = traits[i];

        cout << "TRAIT " << i + 1 << " "
             << (int)trait.r << " "
             << (int)trait.g << " "
             << (int)trait.b << " "
             << (int)trait.a << " ";

        afficherFloat(trait.epaisseur);

        cout << " " << trait.points.size() << "\n";

        for (const Point& point : trait.points) {
            cout << "POINT ";
            afficherFloat(point.x);
            cout << " ";
            afficherFloat(point.y);
            cout << "\n";
        }
    }

    return 0;
}
