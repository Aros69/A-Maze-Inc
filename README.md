# A Maze Inc
* Un jeu de plateforme fait avec SDL2.0*

![Écran de début de jeu](/doc/CaptureEcran/Debut.png "Écran d'acceuil")


## Projet Damibin réalisé par :
- BENSOUSSAN-BOHM Daniel ("daniel.bensoussan--bohm@etu.univ-lyon1.fr")
- DONNAY Robin ("robin.donnay@etu.univ-lyon1.fr")
- N'GUYEN Emilien ("emilien.n'guyen@etu.univ-lyon1.fr")

## Information techniques :
Cette librairie permet de jouer au jeu A-Maze-Inc, une jeu 2D de platforme/action/rogue-like  
Le code a été écrit en C++, se compile avec g++.  
Le code fonctionne normalent sous Linux et Windows, et il n'est pas nécessaire de modifier quoi que ce soit entre les deux plateformes.  

### Dépendances :
- SDL2 : http://www.libsdl.org/ (Sous linux : `$> sudo apt-get install libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev libsdl2-mixer-dev`)

### Compilation :
La compilation se fait soit avec la commande `$> make`.  
Si lors de la compilation sous Windows, il y a un problème de "dll", il faut alors copier tout les dll du dossier extern/dll/ dans bin/  

### Execution
L'éxecution du doit se faire par la racine du projet (quelque soit la plateforme) puis : `$> ./bin/JeuSDL.exe`  

### Documentation
Dépendance : Doxygen : http://www.stack.nl/~dimitri/doxygen/  
Pour générer la documentation du code si elle n'existe pas déjà `$> doxygen doc/images.doxy`  
Puis ouvrir doc/html/index.html avec firefox  

## Informations pour le jeu :
*Jeu développé pour le cours LIFAP4 de de l'universite Claude Bernard Lyon 1 pour la deuxième année de licence*

![Le jeu](/doc/CaptureEcran/Jeu.png "Le jeu")
![La carte](/doc/CaptureEcran/Carte.png "La carte")

### Touches :
- "Croix directionnelle" pour bouger et sauter
- "Espace" pour attaquer avec l'épée
- "n" pour attaquer avec la magie
- "m" pour afficher la carte
- "echap" pour sortir à tout moment du jeu
- "e" pour lancer un mini-jeu
