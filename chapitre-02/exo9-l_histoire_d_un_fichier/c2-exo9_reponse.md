## EXERCICE 9: HISTOIRE D'UN FICHIER MOTEUR

### creation

il s'agit des commits du fichier en question

```
PS E:\Nkentseu\Applications\NKref\src> cd NKref
PS E:\Nkentseu\Applications\NKref\src\NKref> ls


    Répertoire : E:\Nkentseu\Applications\NKref\src\NKref


Mode                 LastWriteTime         Length Name                                   
----                 -------------         ------ ----                                   
-a----         9/10/2026   7:59 PM          81618 main.cpp                               
-a----         9/10/2026   7:58 PM          14142 NkRefBoard.h                           
-a----         9/10/2026   7:59 PM           7285 NkRefFile.h                            
-a----         9/10/2026   7:59 PM           3505 NkRefView.h                            


PS E:\Nkentseu\Applications\NKref\src\NKref> git log --oneline -- main.cpp                
860e9d7f Refonte NK3DModeler : a jour avec main, et NKCode signe sur certificat (#85)
1405ce21 NkRef : option afficher/cacher la grille (G, panneaux, persistée dans le .nkref)
b6b1c8f6 NkRef ETAPE 2: le fichier .nkref — images EMBARQUEES (les octets du fichier SOURCE, intacts — le plafond d'affichage 4096 ne perd rien ; collage presse-papiers = PNG encode), traits de crayon, vue et theme inclus. Format binaire NKRF v1 deterministe: ROUND-TRIP save->open->save = OCTETS IDENTIQUES (verifie: 54338 = 54338, hash egaux — le test des scenes du modeleur). Ctrl+S / Ctrl+Shift+S / Ctrl+O / Ctrl+K (nouvelle planche, comme PureRef), menu fichier + sous-menu Recents (6, nkref_recents.txt), titre = nom de planche + etoile non-enregistre (langage du modeleur), dialogues natifs, planche courante intacte si fichier illisible, crochets NK_AGENT_SAVEAS/OPEN
ffd0f44c NkRef: empaquetage testeurs — LISEZMOI-TESTEURS (gestes + limites honnetes de la preversion), police GUI EMBARQUEE d'abord (binaire autonome, aucun dossier Resources requis), workflow Actions etendu: 2 jobs (macos-latest + ubuntu-latest avec deps X11) qui EMPAQUETENT et publient des artefacts tar.gz telechargeables. Paquets locaux: Build/Paquets (zip Windows exe+3 DLL MSYS2 recette ConquerorLab, tar.gz Linux)
41f94001 NkRef: theme sombre = GitHub Dark Pro (#0d1117/#161b22/#30363d, accent #58a6ff, actif orange Rihen) + MENU CLIC DROIT structure PureRef (Coller/Copier l'image via SetClipboardImage NOUVEAU + Ctrl+C/Crayon/Pack/Origine/sous-menus Fenetre et Image/Proprietes/Reglages/Fermer — items reels seulement, s'adapte a la selection) + fenetre REGLAGES a onglets Preferences-Couleurs-Raccourcis avec NOS proprietes (glisser-fond, auto-downscale 4096 DEBRAYABLE, toujours devant, crayon, presets de theme, opacite generale, liste reelle des raccourcis) — structure des Settings PureRef montres par Rihen. Occlusion etendue (menu + fenetre deplacable via windowMeta) + crochets NK_AGENT_MENU/SETTINGS
593bf8dd NkRef: theme SOMBRE et theme CLAIR (demande Rihen, presets PureRef montres en reference) — toutes les couleurs de l'app dans une struct NkRefColors (canevas, grille, axes, en-tete, onglet, selection, rectangle) + ApplyGuiTheme assorti pour le panneau NKGui; bascule 'Theme sombre' en tete du panneau + crochet NK_AGENT_THEME (meme chemin). Charte petrole/orange declinee dans les deux. Verifie par captures (025 sombre / 026 clair)
561a7789 NkRef: crayon colore sur la planche (traits en MONDE — zooment avec les images ; palette 7 couleurs, epaisseur px convertie a la pose, annuler/effacer, touche D), fix ferm
eture du panneau (l'onglet etait RECOUVERT par le panneau ouvert -> deplace a sa gauche + dessine au-dessus des Submit), theme charte Rihen (petrole #0A555F / orange #F79A28), compteur images/selection/traits dans le panneau. Verifie par capture: webp/avif aux vrais magic bytes REFUSES proprement (2 illisibles signales, EXIT 0) — le crash webp/avif rapporte ne se reproduit plus
51ad07c7 NkRef: tiroir de proprietes NKGui escamotable (onglet chevron au bord droit) — Toujours devant, opacite fenetre, reglage 'glisser le fond = fenetre' (decoche: le glisser trace le rectangle — reponse a la question de Rihen), Pack, Origine, proprietes de l'image active (opacite par image NOUVEAU, miroirs, suppression), aide 'Gestes' repliable; occlusion routee (molette/clics du panneau ne traversent pas vers le canevas). + Anti-crash >6 images: plafond d'import 4096px (photos 24-48Mpx = centaines de Mo VRAM, machine sensible aux pics GPU; l'etape 2 embarquera les octets source) + culling des images hors ecran + en-tete en police embarquee (DroidSans) + crochet NK_AGENT_PANEL
847277b0 NkRef: fenetre PureRef sans bordure — en-tete escamotable (pastille + titre texte Karla + boutons -/carre/x dessines, revele pres du bord haut ou sur avis), glisser le FOND deplace la FENETRE (Ctrl+glisser = rectangle de selection), double-clic barre = agrandir, bords 6px = resize natif + curseurs, Pack en BLOC (largeur = somme des largeurs / ceil(sqrt(n)) — l'ancien sqrt(aire) donnait une colonne, retour Rihen), fichiers illisibles VISIBLES dans l'en-tete (retour 6-sur-8: formats webp/avif non decodes), filtre jenga macOS
eb83e028 NkRef: Pack Ctrl+P (rangement compact en etageres, tri hauteur decroissante, AABB rotation comprise, recentre sur le centroide — s'applique a la selection >=2 sinon tout) + raccourcis fenetre discrete: T = toujours-devant, 1..9/0 = opacite de fenetre (presets 10..90/100%), etat reflete dans le titre + crochet NK_AGENT_PACK. Verifie par captures: JPEG 3 canaux affiche sans crash, planche rangee
bf171fea NkRef etape 1: des images sur la planche — NkRefBoard pur (ordre=profondeur, hit test avec rotation, selection rectangle, reordre rendu a la glue) + glue: glisser-deposer OLE, Ctrl+V via GetClipboardImage (chantier NKWindow de la branche), selection/deplacement, poignees d'echelle ancrees au coin oppose, poignee de rotation (Maj=15deg), miroir X/Y, Suppr, PgUp/PgDn + Ctrl+molette pour l'ordre Z, crochets agent DROP/CLICK/MOVE (memes fonctions que la souris). Verifie par captures (3 images generees, positions exactes, ordre Z,
 dezoom ancre) + run WSLg EXIT 0
91ea5a82 NkRef: fix ordre de destruction — pas de window.Close() explicite avant le return, le contexte GL (NkRenderWindow) doit mourir AVANT la fenetre/le Display. glXDestroyContext sur Display ferme segfaultait sous Linux/WSLg (backtrace _XSend) ; WGL pardonnait. Valide: NkRef tourne sous WSLg (EXIT 0), non-regression Windows (diff pixel client = 0). NKWindow compile desormais prouve sur Android/HarmonyOS/Web/XLib/XCB/Wayland
68909d3e NkRef etape 0: canevas infini nu — pan (clic milieu / espace+glisser), zoom molette CENTRE SOUS LE CURSEUR (NkRefView pur, ancre invariante), grille adaptative puissances de 2, axes origine, Home=reset + crochets agent NK_AGENT_SHOT/EXIT/PAN/ZOOM (memes methodes que la souris) — verifie par captures: zoom ancre exact, pan exact, rendu deterministe (hashes identiques)

```

### les moments où ils ont plus changé

ici il s'agit des commits ayant le plus de modification.

**1- liste des commits avec le nombre de ligne modifications**

```
PS E:\Nkentseu\Applications\NKref\src\NKref> git log --stat --oneline -- main.cpp
860e9d7f Refonte NK3DModeler : a jour avec main, et NKCode signe sur certificat (#85)
 Applications/NkRef/src/NkRef/main.cpp | 22 +++++++++++++---------
 1 file changed, 13 insertions(+), 9 deletions(-)
1405ce21 NkRef : option afficher/cacher la grille (G, panneaux, persistée dans le .nkref)
 Applications/NkRef/src/NkRef/main.cpp | 72 +++++++++++++++++++++++------------
 1 file changed, 48 insertions(+), 24 deletions(-)
b6b1c8f6 NkRef ETAPE 2: le fichier .nkref — images EMBARQUEES (les octets du fichier SOURCE, intacts — le plafond d'affichage 4096 ne perd rien ; collage presse-papiers = PNG encode), traits de crayon, vue et theme inclus. Format binaire NKRF v1 deterministe: ROUND-TRIP save->open->save = OCTETS IDENTIQUES (verifie: 54338 = 54338, hash egaux — le test des scenes du modeleur). Ctrl+S / Ctrl+Shift+S / Ctrl+O / Ctrl+K (nouvelle planche, comme PureRef), menu fichier + sous-menu Recents (6, nkref_recents.txt), titre = nom de planche + etoile non-enregistre (langage du modeleur), dialogues natifs, planche courante intacte si fichier illisible, crochets NK_AGENT_SAVEAS/OPEN
 Applications/NkRef/src/NkRef/main.cpp | 331 ++++++++++++++++++++++++++++++++--
 1 file changed, 315 insertions(+), 16 deletions(-)
ffd0f44c NkRef: empaquetage testeurs — LISEZMOI-TESTEURS (gestes + limites honnetes de la preversion), police GUI EMBARQUEE d'abord (binaire autonome, aucun dossier Resources requis), workflow Actions etendu: 2 jobs (macos-latest + ubuntu-latest avec deps X11) qui EMPAQUETENT et publient des artefacts tar.gz telechargeables. Paquets locaux: Build/Paquets (zip Windows exe+3 DLL MSYS2 recette ConquerorLab, tar.gz Linux)
 Applications/NkRef/src/NkRef/main.cpp | 6 ++++--
 1 file changed, 4 insertions(+), 2 deletions(-)
41f94001 NkRef: theme sombre = GitHub Dark Pro (#0d1117/#161b22/#30363d, accent #58a6ff, actif orange Rihen) + MENU CLIC DROIT structure PureRef (Coller/Copier l'image via SetClipboardImage NOUVEAU + Ctrl+C/Crayon/Pack/Origine/sous-menus Fenetre et Image/Proprietes/Reglages/Fermer — items reels seulement, s'adapte a la selection) + fenetre REGLAGES a onglets Preferences-Couleurs-Raccourcis avec NOS proprietes (glisser-fond, auto-downscale 4096 DEBRAYABLE, toujours devant, crayon, presets de theme, opacite generale, liste reelle des raccourcis) — structure des Settings PureRef montres par Rihen. Occlusion etendue (menu + fe
netre deplacable via windowMeta) + crochets NK_AGENT_MENU/SETTINGS
 Applications/NkRef/src/NkRef/main.cpp | 340 ++++++++++++++++++++++++++++++----
 1 file changed, 304 insertions(+), 36 deletions(-)
593bf8dd NkRef: theme SOMBRE et theme CLAIR (demande Rihen, presets PureRef montres en reference) — toutes les couleurs de l'app dans une struct NkRefColors (canevas, grille, axes, en-tete, onglet, selection, rectangle) + ApplyGuiTheme assorti pour le panneau NKGui; bascule 'Theme sombre' en tete du panneau + crochet NK_AGENT_THEME (meme chemin). Charte petrole/orange declinee dans les deux. Verifie par captures (025 sombre / 026 clair)
 Applications/NkRef/src/NkRef/main.cpp | 159 +++++++++++++++++++++++++++-------
 1 file changed, 128 insertions(+), 31 deletions(-)
561a7789 NkRef: crayon colore sur la planche (traits en MONDE — zooment avec les images ; palette 7 couleurs, epaisseur px convertie a la pose, annuler/effacer, touche D), fix fermeture du panneau (l'onglet etait RECOUVERT par le panneau ouvert -> deplace a sa gauche + dessine au-dessus des Submit), theme charte Rihen (petrole #0A555F / orange #F79A28), compteur images/selection/traits dans le panneau. Verifie par capture: webp/avif aux vrais magic bytes REFUSES proprement (2 illisibles signales, EXIT 0) — le crash webp/avif rapporte ne se reproduit plus
 Applications/NkRef/src/NkRef/main.cpp | 147 ++++++++++++++++++++++++++++++----
 1 file changed, 132 insertions(+), 15 deletions(-)
51ad07c7 NkRef: tiroir de proprietes NKGui escamotable (onglet chevron au bord droit) — Toujours devant, opacite fenetre, reglage 'glisser le fond = fenetre' (decoche: le glisser trace le rectangle — reponse a la question de Rihen), Pack, Origine, proprietes de l'image active (opacite par image NOUVEAU, miroirs, suppression), aide 'Gestes' repliable; occlusion routee (molette/clics du panneau ne traversent pas vers le canevas). + Anti-crash >6 images: plafond d'import 4096px (photos 24-48Mpx = centaines de Mo VRAM, machine sensible aux pics GPU; l'etape 2 embarquera les octets source) + culling des images hors ecran + en-tete en police embarquee (DroidSans) + crochet NK_AGENT_PANEL
 Applications/NkRef/src/NkRef/main.cpp | 227 +++++++++++++++++++++++++++++++---
 1 file changed, 213 insertions(+), 14 deletions(-)
847277b0 NkRef: fenetre PureRef sans bordure — en-tete escamotable (pastille + titre texte
 Karla + boutons -/carre/x dessines, revele pres du bord haut ou sur avis), glisser le FOND deplace la FENETRE (Ctrl+glisser = rectangle de selection), double-clic barre = agrandir, bords 6px = resize natif + curseurs, Pack en BLOC (largeur = somme des largeurs / ceil(sqrt(n)) — l'ancien sqrt(aire) donnait une colonne, retour Rihen), fichiers illisibles VISIBLES dans l'en-tete (retour 6-sur-8: formats webp/avif non decodes), filtre jenga macOS
 Applications/NkRef/src/NkRef/main.cpp | 192 ++++++++++++++++++++++++++++++++--
 1 file changed, 184 insertions(+), 8 deletions(-)
eb83e028 NkRef: Pack Ctrl+P (rangement compact en etageres, tri hauteur decroissante, AABB rotation comprise, recentre sur le centroide — s'applique a la selection >=2 sinon tout) + raccourcis fenetre discrete: T = toujours-devant, 1..9/0 = opacite de fenetre (presets 10..90/100%), etat reflete dans le titre + crochet NK_AGENT_PACK. Verifie par captures: JPEG 3 canaux affiche sans crash, planche rangee
 Applications/NkRef/src/NkRef/main.cpp | 35 +++++++++++++++++++++++++++++++++--
 1 file changed, 33 insertions(+), 2 deletions(-)
bf171fea NkRef etape 1: des images sur la planche — NkRefBoard pur (ordre=profondeur, hit test avec rotation, selection rectangle, reordre rendu a la glue) + glue: glisser-deposer OLE, Ctrl+V via GetClipboardImage (chantier NKWindow de la branche), selection/deplacement, poignees d'echelle ancrees au coin oppose, poignee de rotation (Maj=15deg), miroir X/Y, Suppr, PgUp/PgDn + Ctrl+molette pour l'ordre Z, crochets agent DROP/CLICK/MOVE (memes fonctions que la souris). Verifie par captures (3 images generees, positions exactes, ordre Z, dezoom ancre) + run WSLg EXIT 0
 Applications/NkRef/src/NkRef/main.cpp | 519 ++++++++++++++++++++++++++++++----
 1 file changed, 465 insertions(+), 54 deletions(-)
91ea5a82 NkRef: fix ordre de destruction — pas de window.Close() explicite avant le return, le contexte GL (NkRenderWindow) doit mourir AVANT la fenetre/le Display. glXDestroyContext sur Display ferme segfaultait sous Linux/WSLg (backtrace _XSend) ; WGL pardonnait. Valide: NkRef tourne sous WSLg (EXIT 0), non-regression Windows (diff pixel client = 0). NKWindow compile desormais prouve sur Android/HarmonyOS/Web/XLib/XCB/Wayland
 Applications/NkRef/src/NkRef/main.cpp | 6 +++++-
 1 file changed, 5 insertions(+), 1 deletion(-)
68909d3e NkRef etape 0: canevas infini nu — pan (clic milieu / espace+glisser), zoom molette CENTRE SOUS LE CURSEUR (NkRefView pur, ancre invariante), grille adaptative puissances de 2, axes origine, Home=reset + crochets agent NK_AGENT_SHOT/EXIT/PAN/ZOOM (memes methodes que la souris) — verifie par captures: zoom ancre exact, pan exact, rendu deterministe (hashes identiques)
 Applications/NkRef/src/NkRef/main.cpp | 345 ++++++++++++++++++++++++++++++++++
 1 file changed, 345 insertions(+)
```

au vu de ces commits on peut retenir les o3 commits suivants :
```
bf171fea NkRef etape 1: des images sur la planche — NkRefBoard pur (ordre=profondeur, hit test avec rotation, selection rectangle, reordre rendu a la glue) + glue: glisser-deposer OLE, Ctrl+V via GetClipboardImage (chantier NKWindow de la branche), selection/deplacement, poignees d'echelle ancrees au coin oppose, poignee de rotation (Maj=15deg), miroir X/Y, Suppr, PgUp/PgDn + Ctrl+molette pour l'ordre Z, crochets agent DROP/CLICK/MOVE (memes fonctions que la souris). Verifie par captures (3 images generees, positions exactes, ordre Z, dezoom ancre) + run WSLg EXIT 0
 Applications/NkRef/src/NkRef/main.cpp | 519 ++++++++++++++++++++++++++++++----
 1 file changed, 465 insertions(+), 54 deletions(-)
 
```
68909d3e NkRef etape 0: canevas infini nu — pan (clic milieu / espace+glisser), zoom molette CENTRE SOUS LE CURSEUR (NkRefView pur, ancre invariante), grille adaptative puissances de 2, axes origine, Home=reset + crochets agent NK_AGENT_SHOT/EXIT/PAN/ZOOM (memes methodes que la souris) — verifie par captures: zoom ancre exact, pan exact, rendu deterministe (hashes identiques)
 Applications/NkRef/src/NkRef/main.cpp | 345 ++++++++++++++++++++++++++++++++++
 1 file changed, 345 insertions(+)
```

```
41f94001 NkRef: theme sombre = GitHub Dark Pro (#0d1117/#161b22/#30363d, accent #58a6ff, actif orange Rihen) + MENU CLIC DROIT structure PureRef (Coller/Copier l'image via SetClipboardImage NOUVEAU + Ctrl+C/Crayon/Pack/Origine/sous-menus Fenetre et Image/Proprietes/Reglages/Fermer — items reels seulement, s'adapte a la selection) + fenetre REGLAGES a onglets Preferences-Couleurs-Raccourcis avec NOS proprietes (glisser-fond, auto-downscale 4096 DEBRAYABLE, toujours devant, crayon, presets de theme, opacite generale, liste reelle des raccourcis) — structure des Settings PureRef montres par Rihen. Occlusion etendue (menu + fe
netre deplacable via windowMeta) + crochets NK_AGENT_MENU/SETTINGS
 Applications/NkRef/src/NkRef/main.cpp | 340 ++++++++++++++++++++++++++++++----
 1 file changed, 304 insertions(+), 36 deletions(-)
```

```
b6b1c8f6 NkRef ETAPE 2: le fichier .nkref — images EMBARQUEES (les octets du fichier SOURCE, intacts — le plafond d'affichage 4096 ne perd rien ; collage presse-papiers = PNG encode), traits de crayon, vue et theme inclus. Format binaire NKRF v1 deterministe: ROUND-TRIP save->open->save = OCTETS IDENTIQUES (verifie: 54338 = 54338, hash egaux — le test des scenes du modeleur). Ctrl+S / Ctrl+Shift+S / Ctrl+O / Ctrl+K (nouvelle planche, comme PureRef), menu fichier + sous-menu Recents (6, nkref_recents.txt), titre = nom de planche + etoile non-enregistre (langage du modeleur), dialogues natifs, planche courante intacte si fichier illisible, crochets NK_AGENT_SAVEAS/OPEN
 Applications/NkRef/src/NkRef/main.cpp | 331 ++++++++++++++++++++++++++++++++--
 1 file changed, 315 insertions(+), 16 deletions(-)
```


