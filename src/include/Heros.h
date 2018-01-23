#ifndef HEROS_H
#define HEROS_H

#include "Statistiques.h"
#include "Equipement.h"
#include "Mini_Carte.h"
#include "Ennemis.h"

#include <iostream>
#include <string>

using namespace std;

class Heros
{
    private:
        /**  @brief Lien sur l'�quipement du h�ros */
         Equipement Equip ;
        /**  @brief Valeur repr�sentant la position horizontale du h�ros sur la mini carte */
        unsigned int Position_X_Mini_Carte;
        /**  @brief Valeur repr�sentant la position verticale du h�ros sur la mini carte */
        unsigned int Position_Y_Mini_Carte;
        /**  @brief Valeur repr�sentant la position horizontale du h�ros sur la carte */
        unsigned int Position_X_Carte;
        /**  @brief Valeur repr�sentant la position verticale du h�ros sur la carte */
        unsigned int Position_Y_Carte;
        /** Valeur repr�sentant l'orientation du h�ros g ou d */
        char Orientation;
        /** @brief Bool�en vrai si le h�ros est dans les airs */
        bool Dans_Air ;
        /** @brief Entier entre 0 et 2 indiquant le nombres de frames avant d'atteindre la hauteur maximale du saut */
        unsigned int Moment_Saut ;
        /** @brief Indique si l'attaque magique � d�j� �t� utilis�e */
        unsigned int Recharge_Magique;
        /**  @brief Lien sur les statistiques du h�ros */
        Statistiques Stats;


    public:
        /**  @brief Constructeur par d�faut */
        Heros();
        /**  @brief Destructeur */
        ~Heros();

        /**  @brief D�place le h�ros vers la gauche */
        void Deplace_Gauche(const class Mini_Carte & mc);
        /**  @brief D�place le h�ros vers la droite */
        void Deplace_Droite(const class Mini_Carte & mc);
        /**  @brief D�place le h�ros vers le bas */
        void Deplace_Bas(const class Mini_Carte & mc);
        /**  @brief D�place le h�ros vers le haut */
        void Saut(const class Mini_Carte & mc);
        /**  @brief D�place le h�ros vers le haut */
        void Deplace_Haut(const class Mini_Carte & mc);
        /**  @brief D�place automatiquement le joueur vers le bas s'il y a du vide sous lui */
        void Gravite(const class Mini_Carte & mc);

        /**  @brief Le h�ros donne un coup d'�p�e */
        unsigned int Attaque_Arme(const Mini_Carte & mini_carte);
        /**  @brief Le h�ros utilise une attaque magique */
        unsigned int Attaque_Magique(const Mini_Carte & mini_carte,unsigned int & posy);

        /**  @brief V�rifie si le h�ros est sur la m�me case que l'ennemi */
        bool Est_Sur_La_Meme_Case_Que_Ennemi(const class Mini_Carte & mc);

        /** @brief Retourne la position horizontale du h�ros sur la mini carte */
        unsigned int get_Position_X_Mini_Carte() const ;
        /** @brief Retourne la position verticale du h�ros sur la mini carte */
        unsigned int get_Position_Y_Mini_Carte() const ;
        /** @brief Retourne la position horizontale du h�ros sur la carte */
        unsigned int get_Position_X_Carte() const ;
        /** @brief Retourne la position verticale du h�ros sur la carte */
        unsigned int get_Position_Y_Carte() const ;

        /** @brief Retourne l'�quipement du h�ros */
        class Equipement get_Equip() const;

        /** @brief Valeur repr�sentant l'orientation du h�ros (droite ou gauche) */
        char get_Orientation() const ;

        /** @brief Retourne vrai si le h�ros est en l'air */
        bool get_Dans_Air() const ;

        /** @brief Retourne la valeur indiquant le nombres de frames avant d'atteindre la hauteur maximale du saut */
        unsigned int get_Moment_Saut() const ;

        /** @brief Modifie la position horizontale du h�ros sur la mini carte */
        void set_Position_X_Mini_Carte(unsigned int Pos_X_Mini_Carte_nouv);

        /** @brief Modifie la position verticale du h�ros sur la mini carte */
        void set_Position_Y_Mini_Carte(unsigned int Pos_Y_Mini_Carte_nouv);

        /** @brief Modifie la position horizontale du h�ros sur la carte */
        void set_Position_X_Carte(unsigned int Pos_X_Carte_nouv);

        /** @brief Modifie la position verticale du h�ros sur la carte */
        void set_Position_Y_Carte(unsigned int Pos_Y_Carte_nouv);

        /** @brief Charge les caract�ristiques du h�ros par un fichier pass� en param�tre */
        void set_Heros(string Nom_Fic);

        /** @brief Retourne le nom du porteur de ces statistiques */
        string get_Nom()const;

        /** @brief Retourne le nombre de point de vie */
        unsigned int get_Point_De_Vie()const;

        /** @brief Retourne le nombre de point de vie maximal */
        unsigned int get_Point_De_Vie_Max()const;

        /** @brief Retourne la valeur de la mana */
        unsigned int get_Mana()const;

        /** @brief Retourne la valeur de la mana maximale */
        unsigned int get_Mana_Max()const;

        /** @brief Retourne la valeur de l'exp�rience restante pour atteindre le niveau sup�rieur */
        unsigned int get_Experience_Restant()const;

        /** @brief Retourne la valeur de l'exp�rience */
        unsigned int get_Experience_Donne()const;

        /** @brief Retourne la valeur repr�sentant le niveau actuel */
        unsigned int get_Niveau()const;

        /** @brief Retourne la valeur de la force actuelle */
        unsigned int get_Force()const;

        /** @brief Retourne la valeur de l'intelligence actuelle */
        unsigned int get_Intelligence()const;

        /** @brief Retourne la valeur de l'agilit� actuelle */
        unsigned int get_Agilite()const;

        /** @brief Retourne 0 si l'attaque magique n'a pas �t� utilis�e, 1 autrement */
        unsigned int get_Recharge_Magique()const;

        /** @brief Edite le nom du porteur de ces statistiques */
        void set_Nom(string nom);

        /** @brief Edite le nombre de point de vie actuel */
        void set_Point_De_Vie(unsigned int Pv);

        /** @brief Edite le nombre de point de vie maximal */
        void set_Point_De_Vie_Max(unsigned int Pv_Max);

        /** @brief Edite la valeur de la mana actuelle */
        void set_Mana(unsigned int Mana_nouv);

        /** @brief Edite la valeur de la mana maximale */
        void set_Mana_Max(unsigned int Mana_Max_nouv);

        /** @brief Edite la valeur de l'exp�rience restante */
        void set_Experience_Restant(unsigned int Exp_rest);

        /** @brief Edite la valeur de l'exp�rience donn�e */
        void set_Experience_Donne(unsigned int Exp_don);

        /** @brief Edite la valeur repr�sentant le niveau actuel */
        void set_Niveau(unsigned int Niveau_nouv);

        /** @brief Edite la valeur repr�sentant la force */
        void set_Force(unsigned int Force_nouv);

        /** @brief Edite la valeur repr�sentant l'intelligence */
        void set_Intelligence(unsigned int Intel_nouv);

        /** @brief Edite la valeur repr�sentant l'agilit� */
        void set_Agilite(unsigned int Agilite_nouv);

        /** @brief Retourne les statistiques du h�ros */
        class Statistiques get_Stats()const;

        /** @brief Modifie les staistiques du h�ros */
        void set_Stats(class Statistiques sta);

        /** @brief Modifie l'�quipement du h�ros*/
        void set_Equip(class Equipement Equip_nouv);

        /** @brief Modifier le bool�en dans les airs */
        void set_Dans_Air (bool dans_air) ;

        /** @brief Edite la valeur indiquant le nombres de frames avant d'atteindre la hauteur max du saut*/
        void set_Moment_Saut (unsigned int moment_saut) ;

        /** @brief Edite la valeur repr�sentant l'orientation du h�ros*/
        void set_Orientation (char orientation) ;

        /** @brief Edite la valeur de recharge pour l'attaque magique */
        void set_Recharge_Magique(unsigned int Rech_Mag_nouv);

        /** @brief V�rifie si le heros est sur la m�me case que un ennemis */
        bool Est_Sur_Meme_Case_Que_Ennemi(Ennemis mechant) ;

        /** @brief V�rifie si l'ennemi est mort (s'il n'a plus de point de vie) */
        bool Meurt();

        /** @brief procedure qui modifie les points de vie (prend des degats)*/
        void Prends_Degats(unsigned int degats);

        /** @brief Test de r�gression de la classe */
        void Test_Regression();

};

#endif // HEROS_H
