#ifndef ENNEMIS_H
#define ENNEMIS_H

#include <Statistiques.h>
#include <Objet.h>
#include <Mini_Carte.h>

using namespace std ;

class Ennemis
{
    private:
        /** @brief Position horizontale de l'ennemi sur la Mini-carte */
        unsigned int Position_X_Mini_Carte;
        /** @brief Position verticale de l'ennemi sur la Mini-carte */
        unsigned int Position_Y_Mini_Carte;
        /** @brief Direction de l'ennemis */
        char Direction;
        /** @brief Donne la direction de l'attaque h=horizontal, l=lateral,d= diagonal */
        char Direction_Attaque;
        /** @brief Statistiques de l'ennemi */
        Statistiques Stats_Ennemis;
        /** @brief Le fichier qui contient les statistiques, la Direction,la direction de l'attaque*/
        string Fichier;


    public:
        /** @brief Initialise l'ennemi tout a 0 sauf le nom " " */
        Ennemis();
        /** @brief Initialise l'ennemi par les données */
        Ennemis(unsigned int x_mini_carte,unsigned int y_Mini_carte,
                char direction,char direction_attaque,class Statistiques stats);
        /** Default Destructeur */
        virtual ~Ennemis();

        /** @brief Renvoie la position horizontal de l'ennemi sur la mini-carte  */
        const unsigned int get_Position_X_Mini_Carte()const;
        /** @brief Renvoie la position verticale de l'ennemi sur la mini-carte */
        const unsigned int get_Position_Y_Mini_Carte()const;
        /** @brief Renvoie la direction de l'ennemi */
        const char get_Direction()const;
        /** @brief Renvoie la valeur de la direction de l'attaque */
        const char get_Direction_Attaque()const;
        /** @brief Renvoi la mergingstatistique de l'ennemi */
        const class Statistiques get_Stats_Ennemis()const;

        /** @brief Retourne le nom de l'ennemi */
        const string get_Stats_Ennemis_Nom()const;
        /** @brief Retourne les pv de l'ennemi */
        const unsigned int get_Stats_Ennemis_Point_De_Vie()const;
        /** @brief Retourne les pv_max de l'ennemi */
        const unsigned int get_Stats_Ennemis_Point_De_Vie_Max()const;
        /** @brief Retourne les mana de l'ennemi */
        const unsigned int get_Stats_Ennemis_Mana()const;
        /** @brief Retourne la Mana_max de l'ennemi */
        const unsigned int get_Stats_Ennemis_Mana_Max()const;
        /** @brief Retourne les pv de l'ennemi */
        const unsigned int get_Stats_Ennemis_Experience_Restant()const;
        /** @brief Retourne les xp_donne de l'ennemi */
        const unsigned int get_Stats_Ennemis_Experience_Donne()const;
        /** @brief Retourne le niveau de l'ennemi */
        const unsigned int get_Stats_Ennemis_Niveau()const;
        /** @brief Retourne les forces de l'ennemi */
        const unsigned int get_Stats_Ennemis_Force()const;
        /** @brief Retourne l'intelligence de l'ennemi */
        const unsigned int get_Stats_Ennemis_Intelligence()const;
        /** @brief Retourne l'agilite de l'ennemi */
        const unsigned int get_Stats_Ennemis_Agilite()const;
        /** @brief Retourne l'emplacement du fichier*/
        const string get_Fichier()const;


        /** @brief Accède à la position horizontale de l'ennemi sur la mini-carte */
        void set_Position_X_Mini_Carte(unsigned int x);
        /** @brief Accède à la position verticale de l'ennemi sur la minicarte */
        void set_Position_Y_Mini_Carte (unsigned int y);
        /** @brief Accède à la direction de l'ennemi */
        void set_Direction(char direction);
        /** @brief Modifie la valeur de la direction de l'attaque */
        void set_Direction_Attaque(char direction);
        /** @brief Accède au donnée de la classe statistique de l'ennemi */
        void set_Stats_Ennemis(class Statistiques s);
		/** @brief Copie complètement l'ennemi en parametre (copie profonde) */
        void set_Ennemis(class Ennemis ennemis) ;
        /** @brief Charge le fichier pour remplir les caracteristique de ennemis*/
        void set_Ennemis(string nom_fichier);
        /** @brief Charge uniquement le fichier dans les donnée corespondants*/
        void set_Ennemis_Fichier();
        /** @brief remplie le nom du fichier*/
        void set_Fichier(string nom_fichier);
        /** @brief Modifie le nom de l'ennemi */
        void set_Stats_Ennemis_Nom(string nom);
        /** @brief Modifie les pv de l'ennemi */
        void set_Stats_Ennemis_Point_De_Vie(unsigned int pv);
        /** @brief Modifie les pv_max de l'ennemi */
        void set_Stats_Ennemis_Point_De_Vie_Max(unsigned int pv_max);
        /** @brief Modifie les mana de l'ennemi */
        void set_Stats_Ennemis_Mana(unsigned int mana);
        /** @brief Modifie la Mana_max de l'ennemi */
        void set_Stats_Ennemis_Mana_Max(unsigned int mana_max);
        /** @brief Modifie les xp restants pour le prochain niveau de l'ennemi */
        void set_Stats_Ennemis_Experience_Restant(unsigned int xp_restant);
        /** @brief Modifie les xp_donne de l'ennemi */
        void set_Stats_Ennemis_Experience_Donne(unsigned int xp_donne);
        /** @brief Modifie le niveau de l'ennemi */
        void set_Stats_Ennemis_Niveau(unsigned int niv);
        /** @brief Modifie les forces de l'ennemi */
        void set_Stats_Ennemis_Force(unsigned int force);
        /** @brief Modifie l'intelligence de l'ennemi */
        void set_Stats_Ennemis_Intelligence(unsigned int intelligence);
        /** @brief Modifie l'agilite de l'ennemi */
        void set_Stats_Ennemis_Agilite(unsigned int agilite);

        /** @brief Fait bouger le monstre */
        void Deplacement_Ennemis_Automatique(class Mini_Carte & mini_carte) ;
        /** @brief Fait bouger l'ennemi selon un script */
        void Deplacement_Ennemis_Script(const class Mini_Carte & mini_carte);
        /** @brief Peut renvoyer un objet quand il meurt */
        Objet Lache_Objet(Objet objet);
        /** @brief Renvoie true si heros est dans le champ de vision de l'ennemis prend l'agrro ou pas */
        bool Heros_Visible_Par_Ennemis(unsigned int Position_Heros_X,unsigned int Position_Heros_Y);
        /** @brief Attaque ennemis en fonction de sa capacité à attaquer diagonale laterale horizontale ... */
        unsigned int Attaque_Ennemis(const Mini_Carte & mini_carte);
        /** @brief Affiche toutes les données membres */
        void Affiche_Ennemis()const;
        /** @brief renvoie si l'ennemi est toucher*/
        bool Ennemis_Touche(unsigned int x,unsigned int y);
        /** @brief modifie les points de vie de l'attaque*/
        void Ennemis_Touche(unsigned int degats);

        /** @brief Vérifie toutes les fonctions */
        void Test_Regression();
        /** @brief Verifie attaque touche heros */
        bool Toucher_Heros(unsigned int position_x,unsigned int position_y,
                           unsigned int position_heros_x,unsigned int position_heros_y);
        /** @brief verifie si ennemis mort ou pas*/
        bool Ennemis_Mort();

};

#endif // ENNEMIS_H


