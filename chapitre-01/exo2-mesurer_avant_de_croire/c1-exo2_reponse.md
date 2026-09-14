nombre de fichier source du projet: 1371


commande utilisé qui compte les fichiers source: (git ls-files *.cpp *.cxx *.cc *.c).Count

nombre de ligne de code du projet: 1427011

commande utilisé pour compter le nombre de ligne de tout le projet :  Get-Content (git ls-files *.cpp *.cxx *.cc *.c *.hpp *.h *.hxx) | Measure-Object -Line

comparaison: 1371 <2641 car tout d'abord les fichiers entetes n'ont pas été compté dans la commande de plus cette commande sert à compter tout les fichiers sources ayant des extensions .c, .cpp .cc et .cxx ajouté sur github grace à la commande git add y compris ceux n'ayant pas été écrit par le programmeur lui meme.parlant des dossiers de build cette commande ne les gère pas mais pour les  fichiers tests ça compte  car ce sont des fichiers .cpp et .h pour certains 

fichier entetes: 1914

commande utilisée pour compter les fichiers entetes: (git ls-files *.hpp *.h *.hxx).count

commande qui compte les fichiers sources et entetes: (git ls-files *.cpp *.c *.cc *.cxx *.hpp *.h *.hxx).count

conclusion: en faisant 1914+1371= 3485>2641 car la commande compte toute les fichiers ayant des extensions .cpp , .c, .cc, .cxx, .hpp, .h, .hxx  faisant parti du projet meme ceux n'ayant pas été ecris par le programmeur 