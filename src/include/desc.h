/** \mainpage Damibin/A-Maze-Inc


\section intro Introduction

Projet Damibin réalisé par : <br>
- BENSOUSSAN-BOHM Daniel ("daniel.bensoussan--bohm@etu.univ-lyon1.fr") <br>
- DONNAY Robin ("robin.donnay@etu.univ-lyon1.fr") <br>
- N'GUYEN Emilien ("emilien.n'guyen@etu.univ-lyon1.fr")<br>

Cette librairie permet de jouer au jeu A Maze Inc un plateforme/aventure/rogue-like <br>

Le code a été écrit en C++, se compile avec g++. <br> 

Le code fonctionne normalent sous Linux et Windows, et il n'est pas nécessaire de modifier quoi que ce soit entre les deux plateformes. <br>

Dépendance(s) : <br>
 - SDL2 : http://www.libsdl.org/ <br> <br>
 
\section compil Pour compiler

La compilation se fait soit avec la commande $ make ou via codeblocks en ouvrant le projet Damibin.cbp puis ctrl+f11 pour recompiler tout le projet à faire seulement une fois) puis ctrl+f9. <br>
Si lors de la compilation sous Windows, il y a un problème de "dll", il faut alors copier tout les dll du dossier extern/dll/ dans bin/ <br> <br>


\section exec Pour executer

L'éxecution du jeu doit se faire dans la racine du projet puis : $ ./bin/JeuSDL, ou via codeblocks via la buildtarget JeuSDL. <br> <br>


\section doc Pour regénérer la documentation de code

Dépendance : Doxygen : http://www.stack.nl/~dimitri/doxygen/ <br>
$ doxygen doc/images.doxy <br> 
Puis ouvrir doc/html/index.html avec firefox <br> 


*/
