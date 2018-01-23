#ifndef Statistiques_H
#define Statistiques_H

#include <string>
#include <iostream>
#include <cassert>

using namespace std;


class Statistiques
{
    private:
        /** @brief Nom du porteur de ces stats */
        string Nom;
        /** @brief Points de vie actuelles */
        unsigned int Point_De_Vie;
        /** @brief Nombre de point vie que l'on peut avoir au maximun*/
        unsigned int Point_De_Vie_Max;
        /** @brief Mana actuelle */
        unsigned int Mana;
        /** @brief Nombre de Mana que l'on peut avoir au maximun  */
        unsigned int Mana_Max;
        /** @brief Nombre d'Experience restant avant le prochain niveau*/
        unsigned int Experience_Restant;
        /** @brief Nombre d'experience que les enemis donne*/
        unsigned int Experience_Donne;
        /** @brief Niveaux actuelle */
        unsigned int Niveau;
        /** @brief Force possedé */
        unsigned int Force;
        /** @brief Intelligence possedé*/
        unsigned int Intelligence;
        /** @brief Agilité possedé */
        unsigned int Agilite;



    public:

        /** @brief inititialise a 0 pour toute les stats et un blanc pour le nom*/
        Statistiques ();

        /** @brief inititialise a partir des valeur entre dans l'ordre*/
        Statistiques (string nom,unsigned int pv,unsigned int pv_max,
                      unsigned int mana,unsigned int mana_max,unsigned int xp_restant,unsigned int xp_donne,
                      unsigned int niveau,unsigned int force,unsigned int intel,
                      unsigned int agilite);
        /** @brief initialise a a partir d'une classe*/
        // Statistiques(Statistiques & s);

        /** @brief Destructeur */
        ~Statistiques();


        /** @brief Retourne le nom du porteur de c'est stats*/
        string get_Nom()const;
        /** @brief Retourne la valeur des point de vie */
        const unsigned int get_Point_De_Vie()const;
        /** @brief Retourne la valeur des point de vie max */
        const unsigned int get_Point_De_Vie_Max()const;
        /** @brief Retourne la valeur de la mana actuelle */
        const unsigned int get_Mana()const;
        /** @brief Retourne la valeur de la mana max possible */
        const unsigned int get_Mana_Max()const;
        /** @brief Retourne le nommbre d'experience */
        const unsigned int get_Experience_Restant()const;
        /** @brief Retourne le nombre d'experience que l'enemis donne*/
        const unsigned int get_Experience_Donne()const;
        /** @brief Retourne le niveau actuelle */
        const unsigned int get_Niveau()const;
        /** @brief Retourne la Statistique Force */
        const unsigned int get_Force()const;
        /** @brief Retourne la Statistique Intelligence */
        const unsigned int get_Intelligence()const;
        /** @brief Retourne la Statistique Agilité */
        const unsigned int get_Agilite()const;


        /** @brief Permet d'accéder nom du porteur de stats */
        void set_Nom(string nom);
        /** @brief Permet d'accér aux points de vie actuels */
        void set_Point_De_Vie(unsigned int i);
        /** @brief Permet d'accéder aux points de vie maximun */
        void set_Point_De_Vie_Max(unsigned int i);
        /** @brief Permet d'accéder aux points de mana actuelle */
        void set_Mana(unsigned int i);
        /** @brief Permet d'accéder aux points de mana maximun */
        void set_Mana_Max(unsigned int i);
        /** @brief Permet d'accéder a l'experience restant pour le prochain niveau du heros*/
        void set_Experience_Restant(unsigned int i);
        /** @brief Permet d'accéder au xp donne par le monstre*/
        void set_Experience_Donne(unsigned int i);
        /** @brief Permet d'accéder aux niveaux */
        void set_Niveau(unsigned int i);
        /** @brief Permet d'accéder a la stat Force*/
        void set_Force(unsigned int i);
        /** @brief Permet d'accéder a la stat Intelligence */
        void set_Intelligence(unsigned int i);
        /** @brief Permet d'accéder a la stat Agilité */
        void set_Agilite(unsigned int i);
        /** @brief Modifie toutes les statistiques sans effet de bords */
        void set_Statistiques(Statistiques stat) ;

        /** @brief Affiche les donne membre de la classe statistiques*/
        void Affiche_Statistiques()const;
        /** @brief Permet de teste si cela fonctionne corectement*/
        void Test_Regression();


};


#endif // STATISTIQUES_H
