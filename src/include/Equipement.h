#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H

#include "Statistiques.h"

#include <iostream>
#include <string>

using namespace std;


class Equipement
{
    private:
        /**  @brief Caractéristiques de l'arme du personnage */
        Statistiques Arme;
        /**  @brief Caractéristiques du bouclier du personnage */
        Statistiques Bouclier;
        /**  @brief Caractéristiques du casque du personnage */
        Statistiques Casque;



    public:
        /** @brief Constructeur */
        Equipement();
        /** *@brief Destructeur */
        ~Equipement();

        /** @brief Retourne les statistiques de l'arme */
        class Statistiques get_Stats_Arme()const;

        /** @brief Retourne les statistiques du bouclier */
        class Statistiques get_Stats_Bouclier()const;

        /** @brief Retourne les statistiques du casque */
        class Statistiques get_Stats_Casque()const;

        /** @brief Modifie les staistiques de l'arme */
        void set_Stats_Arme(class Statistiques Arme_nouv);

        /** @brief Modifie les staistiques du bouclier */
        void set_Stats_Bouclier(class Statistiques Bouclier_nouv);

        /** @brief Modifie les staistiques du casque */
        void set_Stats_Casque(class Statistiques Casque_nouv);

        /** @brief Test de régression de la classe */
        void Test_Regression();
};

#endif // EQUIPEMENT_H
