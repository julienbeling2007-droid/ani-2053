nombre de fichier source du projet: 1371


commande utilisé qui compte les fichiers source: (git ls-files *.cpp *.cxx *.cc *.c).Count

nombre de ligne de code du projet: 1427011

commande utilisé pour compter le nombre de ligne de tout le projet :  Get-Content (git ls-files *.cpp *.cxx *.cc *.c *.hpp *.h *.hxx) | Measure-Object -Line

comparaison: concernant le nombre de ligne de code celui donné par la commande est supérieur à celui du cours car cela inclu en plus des lignes de code des fichiers sources et entetes de ceux des fichiers tests et  et meme pour celle des dossier de build. concernant les fichiers du projet j'ai denombrés 1371 qui est inférieur avec celui donné en cours car j'ai restreint les fichiers entetes et aussi les fichiers tests

fichier entetes: 1914

commande utilisée pour compter les fichiers entetes: (git ls-files *.hpp *.h *.hxx).count

conclusion: en faisant 1914+1371= 3485>2641