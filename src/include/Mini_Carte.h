#ifndef MINI_CARTE_H
#define MINI_CARTE_H

#include <string>
#include <cassert>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std ;

class Mini_Carte
{
    private:
        /** @brief Nom (avec extension) du fichier qui permet d'ouvrir/sauvegarder une mini carte */
        string Nom_Fichier ;
        /** @brief Tableau représentant une zone jouable du jeu */
        unsigned int * Tab_Mini_Carte ;

        /** @brief Valeur représentant la taille horizontale de la mini-carte */
        unsigned int Taille_Mini_Carte_X ;
        /** @brief Valeur représentant la taille horizontale de la mini-carte */
        unsigned int Taille_Mini_Carte_Y ;

        /** @brief Nombre d'ennemis sur la mini carte */
        unsigned int Nombre_Ennemis ;


    public:
        /** @brief Constructeur par défaut */
        Mini_Carte();
        /** @brief Constructeur d'une carte par rapport à un fichier */
        Mini_Carte(string Nom_Fich) ;
        /** @brief Destructeur par défaut */
        ~Mini_Carte();
        /** @brief Désalloue les deux tableaux */
        void Desaloc_Tab() ;
        /** @brief Alloue le tableau (x et y dim de mini carte) */
        void Alloc_Tab(unsigned int x, unsigned int y) ;

        /** @brief */
        void Ouvrir_Mini_Carte(string nom_fichier) ;

        /** @brief Retourne l'entier du tableau de jeu de la xème ligne et yème colonne */
        unsigned int get_Tab_Mini_Carte(unsigned int x, unsigned int y) const ;
        /** @brief Retourne la longueur (taille horizontale) de la mini-carte */
        unsigned int get_Taille_Mini_Carte_X() const ;
        /** @brief Retourne la largeur (taille verticale) de la mini-carte */
        unsigned int get_Taille_Mini_Carte_Y() const ;
        /** @brief Retourne le nombre d'ennemis présents sur la mini-carte */
        unsigned int get_Nombre_Ennemis() const ;
        /** @brief Retouren le nom du fichier */
        void get_Nom_Fichier(string Nom_Fichier) const ;
        /** @brief Retourne dans mini_carte la mini carte actuelle */
        void get_Mini_Carte (Mini_Carte & mini_carte) const ;

        /** @brief Transforme l'entier de la xème ligne et yème colonne en entier_a_mettre */
        void set_Tab_Mini_Carte(unsigned int x, unsigned int y, unsigned int entier_a_mettre) ;
        /** @brief Modifie le nom du fichier */
        void set_Nom_Fichier (string nom_fichier) ;
        /** @brief Edite la taille horizontale de la mini-carte */
        void set_Taille_Mini_Carte_X (unsigned int x) ;
        /** @brief Edite la taille verticale de la mini-carte */
        void set_Taille_Mini_Carte_Y(unsigned int y) ;
        /** @brief Edite le nombre d'ennemis présents sur la mini-carte */
        void set_Nombre_Ennemis(unsigned int nb_ennemis) ;
        /** @brief Modification de la mini carte en mini_carte */
        void set_Mini_Carte(const Mini_Carte & mini_carte) ;

        /** @brief Affiche la mini carte de jeu en entier */
        void Affiche_Mini_Carte() const ;
        /** @brief Affiche les murs de la mini carte et met des espaces sur le(s) zones vides */
        void Affiche_Non_Vide() const ;

        /** @brief Vérifie s'il y a un mur en face du personnage (héros ou ennemi) */
        bool Est_Ce_Que_Mur(unsigned int x, unsigned int y) const ;
        /** @brief Vérifie s'il y a une plateforme accessible pour le personnage (héros ou ennemi) */
        bool Est_Ce_Que_Plateforme(unsigned int x, unsigned int y) const ;
        /** @brief Vérifie si l'emplacement est vide pour pouvoir y accéder */
        bool Est_Ce_Que_Vide(unsigned int x,unsigned int y)const;




    protected:

};

#endif // MINI_CARTE_H
