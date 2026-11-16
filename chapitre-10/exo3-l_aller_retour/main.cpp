
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    double W, H;
    cin >> W >> H;

    double cx = 0.0;
    double cy = 0.0;
    double zoom = 1.0;

    string commande;

    while (cin >> commande) {

        if (commande == "VERS_MONDE") {
            double px, py;
            cin >> px >> py;

            double mx = cx + (px - W / 2.0) / zoom;
            double my = cy + (py - H / 2.0) / zoom;

            if (mx == 0) mx = 0;
            if (my == 0) my = 0;

            cout << fixed << setprecision(2);
            cout << "MONDE " << mx << " " << my << "\n";
        }

        else if (commande == "VERS_PIXEL") {
            double mx, my;
            cin >> mx >> my;

            double px = (mx - cx) * zoom + W / 2.0;
            double py = (my - cy) * zoom + H / 2.0;

            if (px == 0) px = 0;
            if (py == 0) py = 0;

            cout << fixed << setprecision(2);
            cout << "PIXEL " << px << " " << py << "\n";
        }

        else if (commande == "DEPLACE") {
            double dx, dy;
            cin >> dx >> dy;

            cx = cx - dx / zoom;
            cy = cy - dy / zoom;
        }

        else if (commande == "ZOOM") {
            double f, px, py;
            cin >> f >> px >> py;

            // Point du monde sous le curseur avant le zoom
            double ax = cx + (px - W / 2.0) / zoom;
            double ay = cy + (py - H / 2.0) / zoom;

            zoom = zoom * f;

            // Limitation du zoom
            if (zoom < 0.02) zoom = 0.02;
            if (zoom > 64.0) zoom = 64.0;

            // Conservation du point sous le curseur
            cx = ax - (px - W / 2.0) / zoom;
            cy = ay - (py - H / 2.0) / zoom;
        }

        else if (commande == "GRILLE") {
            double m;
            cin >> m;

            double s = 1.0;

            while (s * zoom < m) {
                s *= 2.0;
            }

            while (s * 0.5 * zoom >= m) {
                s *= 0.5;
            }

            if (s == 0) s = 0;

            cout << fixed << setprecision(6);
            cout << "GRILLE " << s << "\n";
        }

        else if (commande == "ORIGINE") {
            cx = 0.0;
            cy = 0.0;
            zoom = 1.0;
        }
    }

    // Affichage de l'état final
    if (cx == 0) cx = 0;
    if (cy == 0) cy = 0;

    cout << fixed << setprecision(2);
    cout << "CENTRE " << cx << " " << cy << "\n";
    cout << "ZOOM " << zoom << "\n";

    return 0;
}
