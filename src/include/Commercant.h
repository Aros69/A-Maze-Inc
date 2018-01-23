#ifndef COMMERCANT_H
#define COMMERCANT_H

#include "Objet.h"
#include "Heros.h"
#include "Statistiques.h"

#include <iostream>
#include <string>

using namespace std

/** @brief Le commerçant se trouve uniquement dans le ahll d'entrée de l'A-Maze-Inc */
class Commercant
{
    private:
        /** @brief Script du commerçant */
        string Script;
        /** @brief Position horizontale du commerçant dans le hall d'entrée*/
        unsigned int Position_X_Mini_Carte;
        /** Position verticale du commercant dans le hall d'entrée */
        unsigned int Position_Y_Mini_Carte;
        /** @brief Valeur représentant l'orientation du commerçant */
        char Orientation;

    public:
        /** @brief Constructeur par défaut */
        Commercant();
        /** @brief Destructeur */
        ~Commercant();

        /** @brief Modifie la position horizontale du commerçant sur la mini carte */
        void set_Position_X_Mini_Carte(unsigned int Pos_X_Mini_Carte_nouv);
        /** @brief Modifie la position verticale du commerçant sur la mini carte */
        void set_Position_Y_Mini_Carte(unsigned int Pos_Y_Mini_Carte_nouv);
        /** @brief Modifie la valeur représentant l'orientation du héros*/
        void set_Orientation (char orientation) ;


        /** @brief Retourne la position horizontale du commerçant sur la mini carte */
        unsigned int get_Position_X_Mini_Carte() const ;
        /** @brief Retourne la position verticale du commerçant sur la mini carte */
        unsigned int get_Position_Y_Mini_Carte() const;
        /** @brief Valeur représentant l'orientation du héros (droite ou gauche) */
        char get_Orientation() const ;

        /** @brief Le commerçant s'enfuit s'il s'est fait attaqué par le héros*/
        void Fuite(Mini_Carte & mc);

};

#endif // COMMERCANT_H
