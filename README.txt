Projet Damibin réalisé par : 

- BENSOUSSAN-BOHM Daniel ("daniel.bensoussan--bohm@etu.univ-lyon1.fr")

- DONNAY Robin ("robin.donnay@etu.univ-lyon1.fr")

- N'GUYEN Emilien ("emilien.n'guyen@etu.univ-lyon1.fr")

Cette librairie permet de jouer au jeu A-Maze-Inc, une jeu 2D de platforme/action/rogue-like

Le code a été écrit en C++, se compile avec g++.


Le code fonctionne normalent sous Linux et Windows, et il n'est pas nécessaire de modifier quoi que ce soit entre les deux plateformes.


Dépendances :
 - SDL2 : http://www.libsdl.org/


La compilation se fait soit avec la commande $ make ou via codeblocks en ouvrant le projet ModuleImage.cbp puis ctrl+f11 pour recompiler tout le projet et enfin ctrl+f9.

Si lors de la compilation sous Windows, il y a un problème de "dll", il faut alors copier tout les dll du dossier extern/dll/ dans bin/ 

L'éxecution du doit se faire par la racine du projet (quelque soit la plateforme) puis : $ ./bin/JeuSDL.exe ou via codeblocks via la "buildtarget" JeuSDL
Remarques : L'execution ne fonctionne pas avec codeblocks sous Windows.

Pour générer la documentation du code si elle n'existe pas déja

Dépendance : Doxygen : http://www.stack.nl/~dimitri/doxygen/
$ doxygen doc/images.doxy 
Puis ouvrir doc/html/index.html avec firefox
