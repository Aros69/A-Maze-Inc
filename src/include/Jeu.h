#ifndef JEU_H
#define JEU_H

#include <Ennemis.h>
#include <Mini_Carte.h>
#include <Carte.h>
#include <Heros.h>
#include <string>
#include<Mini_Jeux0.h>

using namespace std ;

class Jeu
{
    private:
        Carte Jeu_Carte ;
        Heros Jeu_Heros ;
        Ennemis * Jeu_Tab_Ennemis ;
        Mini_Carte Jeu_Mini_Carte ;

    public:
        Mini_Jeux0 Jeu_Mini_Jeux;
        Jeu() ;
        ~Jeu() ;

        Carte & get_Jeu_Carte() ;
        Mini_Carte & get_Jeu_Mini_Carte() ;
        Heros & get_Jeu_Heros() ;
        Ennemis & get_Jeu_Tab_Ennemis(unsigned int i) const ;
        Mini_Jeux0  get_Jeu_Mini_Jeux()const;

        const Carte & get_Const_Jeu_Carte () const;
        const Mini_Carte & get_Const_Jeu_Mini_Carte () const;
        const Heros & get_Const_Jeu_Heros () const;
        const Ennemis & get_Const_Jeu_Tab_Ennemis() const  ;
        const Mini_Jeux0  get_Const_Jeu_Mini_Jeux() const;

        void Action_Clavier(const char touche,unsigned int & position_attaque_magique_x,
                            unsigned int & position_attaque_magique_y,char & orientation_attaque_magique);
        void Action_Automatique(unsigned int & vitesse_attaque,unsigned int & position_attaque_magique_x,
                                const unsigned int position_attaque_magique_y,const char orientation_attaque_magique);

        /** @brief Double les statistiques du héros après avoir gagné le mini jeu */
        void Modifie_Stats_heros(unsigned int pourcentage);
        /** @brief Remplit la première ligne de blocs ou reste vide */
        void Mini_Jeux_Action_Auto_Avant_Bouger(unsigned int j,unsigned int a);
        /** @brief Permet au mini jeu de changer la position x,y du héros */
        void Mini_Jeux_Bouger(char deplacement);
        /** @brief Fait tomber les blocs d'une case et renvoie si le héros est écrasé ou non */
        bool Mini_Jeux_Action_Auto_Apres_Bouger(unsigned int k);
        /** @brief Permet de remettre les données à leur état initial */
        void Mini_Jeux_Reinitialiser();
        /** @brief renvoie vraix si heros est dans zone remarquable ou pas*/
        bool Active_Mini_Jeux();


        void Au_Bord() ;

        void set_Jeu_Mini_Carte(class Mini_Carte & mini_carte) ;

        /** @brief Définit comment le jeu est lancé : avec une sauvegarde ou en nouvelle partie PAS ENCORE FAIT */
        void Lancement_Jeu() ;
        /** @brief Amène le héros dans le hall et attend qu'il franchise la porte du donjon */
        void Debut_Partie() ;
        /** @brief Créer le labyrinthe */
        void Labyrinthe() ;
        /** @brief Lance un mini-jeu */
        void Lance_Mini_Jeux();

        void Desaloc_Jeu() ;
        void Desaloc_Jeu_Tab_Ennemis() ;

        void Recommence_Jeu() ;


        void Recupe_Ennemis_Mini_Carte() ;
        /** @brief Fonction qui recherche itérativement l'ennemi qui possède ces coordonnées */
        int Recherche_Ennemis(unsigned int Position_X, unsigned int Position_Y) ;
        /** @brief Permet d'éliminer définitivement un ennemi(pas de réanimation lors du jeux sauf cas ou recommence jeu */
        void Supprime_Ennemis(unsigned int i) ;

    protected:
};

#endif // JEU_H
