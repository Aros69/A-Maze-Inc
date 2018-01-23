#ifndef OBJET_H
#define OBJET_H
#include<string>
#include"Statistiques.h"

using namespace std;

class Objet
{
private:
    /** @brief Représente la catégorie de l'objet : casque, arme ... */
    string Categorie;
    /** @brief Statistique de l'objet */
    Statistiques Stats_Objet;




    public:
        /** Constructeur par défaut */
        Objet();
        /** @brief Constructeur par paramètre */
        Objet(string categorie,Statistiques stats_objet);
        /** Desctructeur */
        virtual ~Objet();
        /** @brief Retourne la catégorie */
        string get_Categorie()const;
        /** @brief Retourne la catégorie */
        Statistiques get_Stats_Objet()const;

        /** @brief Modifie la donnée membre Stats_Objet.Nom */
        string get_Stats_Objet_Nom()const;
        /** @brief Modifie la donnée membre Stats_Objet.Point_De_Vie */
        unsigned int get_Stats_Objet_Point_De_Vie()const;
        /** @brief Modifie la donnée membre Stats_Objet.Point_De_Vie_Max */
        unsigned int get_Stats_Objet_Point_De_Vie_Max()const;
        /** @brief Modifie la donnée membre Stats_Objet.Mana */
        unsigned int get_Stats_Objet_Mana()const;
        /** @brief Modifie la donnée membre Stats_Objet.Mana_Max */
        unsigned int get_Stats_Objet_Mana_Max()const;
        /** @brief Modifie la donnée membre Stats_Objet.Experience_Restant */
        unsigned int get_Stats_Objet_Experience_Restant()const;
        /** @brief Retourne la donnée membre Stats_Objet.Experience_Restant */
        unsigned int get_Stats_Objet_Experience_Donne()const;
        /** @brief Retourne la donnée membre Stats_Objet.Niveaux */
        unsigned int get_Stats_Objet_Niveau()const;
        /** @brief Retourne la donnée membre Stats_Objet.Force */
        unsigned int get_Stats_Objet_Force()const;
        /** @brief Retourne la donnée membre Stats_Objet.Intelligence*/
        unsigned int get_Stats_Objet_Intelligence()const;
        /** @brief Retourne la donnée membre Stats_Objet.agilite*/
        unsigned int get_Stats_Objet_Agilite()const;

        /** @brief Modifie a la donné membre Categorie**/
        void set_Categorie(string categorie);
        /** @brief Modifie a la donné membre Stats_Item**/
        void set_Stats_Objet(Statistiques stats_objet);

        /** @brief Modifie la donnée membre Stats_Objet.Nom*/
        void set_Stats_Objet_Nom(string nom);
        /** @brief Modifie la donnée membre Stats_Objet.Point_De_Vie*/
        void set_Stats_Objet_Point_De_Vie(unsigned int pv);
        /** @brief Modifie la donnée membre Stats_Objet.Point_De_Vie_Max*/
        void set_Stats_Objet_Point_De_Vie_Max(unsigned int pv_max);
        /** @brief Modifie la donnée membre Stats_Objet.Mana*/
        void set_Stats_Objet_Mana(unsigned int mana);
        /** @brief Modifie la donnée membre Stats_Objet.Mana_Max*/
        void set_Stats_Objet_Mana_Max(unsigned int mana_max);
        /** @brief Modifie la donnée membre Stats_Objet.Experience_Restant*/
        void set_Stats_Objet_Experience_Restant(unsigned int xp_restant);
        /** @brief Modifie la donnée membre Stats_Objet.Experience_Restant*/
        void set_Stats_Objet_Experience_Donne(unsigned int xp_donne);
        /** @brief Modifie la donnée membre Stats_Objet.Niveaux*/
        void set_Stats_Objet_Niveau(unsigned int niv);
        /** @brief Modifie la donnée membre Stats_Objet.Force*/
        void set_Stats_Objet_Force(unsigned int force);
        /** @brief Modifie la donnée membre Stats_Objet.Intelligence*/
        void set_Stats_Objet_Intelligence(unsigned int intelligence);
        /** @brief Modifie la donnée membre Stats_Objet.*/
        void set_Stats_Objet_Agilite(unsigned int agilite);


};

#endif // OBJET_H
