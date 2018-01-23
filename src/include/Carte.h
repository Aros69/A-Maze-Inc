#ifndef CARTE_H
#define CARTE_H
#include <string>
#include <cassert>
#include <stdlib.h>
#include <time.h>
#include <iostream>

#include <Mini_Carte.h>

//Passage de 2D à 1D : tab2D[x][y] = tab1D[x*dimy+y]

class Carte
{
    private:

        /** @brief Tableau représentant le donjon dans sa globalité */
        unsigned int * Tab_Carte ;
        /** @brief Nombre de mini carte en longueur */
        unsigned int Nombre_Mini_Carte_X ;
        /** @brief Nombre de mini carte en hauteur */
        unsigned int Nombre_Mini_Carte_Y ;
        /** @brief Tableau représentant toutes les mini cartes du donjon */
        class Mini_Carte * Tab_Mini_Carte ;
        /** @brief Longueur du tableau de jeu en prenant en compte les murs exterieurs */
        unsigned int Taille_Carte_X ;
        /** @brief Hauteur du tableau de jeu en prenant en compte les murs exterieurs */
        unsigned int Taille_Carte_Y ;
        /** @brief Numéro de la mini carte de début (en hauteur puisque son début est à 0 en longueur) */
        unsigned int Carte_Debut ;
        /** @brief Tableau des zones notables du jeu (boss et mini jeu) */
        unsigned int Carte_Zone_Remarquable[10][2] ;

        /** @brief Crée le contour jouable de la carte (exception de la boucle) */
        void Creer_Carte_Bordure() ;
        /** @brief Crée la zone jouable de la carte (hors contour) */
        void Creer_Carte_Milieu() ;

    public:

        /** @brief Constructeur par défault (pas forcément utile) */
        Carte();
        /** @brief Construit le tableau de jeu de nbX mini carte de haut et nbY mini carte de long */
        Carte(unsigned int nbX, unsigned int nbY);
        /** @brief Destructeur */
        ~Carte();

        /** @brief Retourne l'entier du tableau de jeu de la xème ligne et yème colonne */
        unsigned int get_Tab_Carte(unsigned int x, unsigned int y) const ;
        /** @brief Transforme l'entier de la xème ligne et yème colonne en entier_a_mettre */
        void set_Tab_Carte(unsigned int x, unsigned int y, unsigned int entier_a_mettre) ;

        /** @brief Met dans mc la mini carte du tableau de la xème ligne et yème colonne */
        void get_Tab_Mini_Carte(unsigned int x, unsigned int y,class Mini_Carte & mc) ;
        /** @brief Transforme la mini carte de la xème ligne et yème colonne en mc */
        void set_Tab_Mini_Carte(unsigned int x, unsigned int y,const class Mini_Carte & mc) ;

        /** @brief Retourne la longueur de la carte */
        unsigned int get_Taille_Carte_X () const ;
        /** @brief Retourne la hauteur de la carte */
        unsigned int get_Taille_Carte_Y() const ;
        /** @brief Retourne le nombre de mini carte en longueur */
        unsigned int get_Nombre_Mini_Carte_X () const ;
        /** @brief Retourne le nombre de mini carte en hauteur */
        unsigned int get_Nombre_Mini_Carte_Y() const ;


        /** @brief Retourne à l'entrée de la carte */
        unsigned int get_Carte_Debut() ;

        /** @brief Affiche le tableau de jeu en entier */
        void Affiche_Carte() ;
        /** @brief Affiche le(s) chemin(s) du tableau de jeu et met des espaces à la place des murs */
        void Affiche_Chemin() ;
        /** @brief Affiche les murs du tableau de jeu et met des espaces sur le(s) chemin(s)*/
        void Affiche_Mur() ;
        /** @brief Affiche la mini-carte */
        void Affiche_Mini_Carte(unsigned int x, unsigned int y) ;

        /** @brief Crée un tableau de jeu "jouable" */
        void Creer_Carte() ;
        /** @brief Crée un tableau de jeu comprenant carte et mini-cartes*/
        void Creer_Carte_Complet(unsigned int x, unsigned int y) ;
        /** @brief Créer toute les mini cartes en utilisant les carte présente dans "data/core/mini_map" */
        void Poser_Mini_Carte() ;
        /** @brief Desalou la carte*/
        void Desaloc_Carte();
        /** @brief renvoi vraix si Heros est dans zone remarquable*/
        bool Est_Ce_Que_Zone_Remarquable(unsigned int x,unsigned int y);

        /** @brief Nombreux tests pour vérifier le bon fonctionnement de la classe */
        void Test_Regression() ;

    protected:
};

#endif // CARTE_H
