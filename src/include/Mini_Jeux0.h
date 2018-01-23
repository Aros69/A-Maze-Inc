#ifndef MINI_JEUX0_H
#define MINI_JEUX0_H
#include<iostream>
#include<cassert>
#include<string.h>
#include<fstream>
#include <cstdlib>
const  unsigned int Taille=10;

using namespace std;

class Mini_Jeux0
{
    public:

        /** @brief renvoie la position x du heros du minijeux*/
        const unsigned int get_Position_X()const;
        /** @brief renvoie la position y du heros du minijeux */
        const unsigned int get_Position_Y()const;
        /** @brief Retourne l'entier du tableau de jeu de la xème ligne et yème colonne */
        const unsigned int get_Tab(unsigned int x,unsigned int y)const;

        /** @brief accede à la position x du heros du minijeux  */
        void set_Position_X(unsigned int Position_X);
        /** @brief accede à la position y du heros du minijeux  */
        void set_Position_Y(unsigned int Position_Y);
        /** @brief modifie l'entier de la xème ligne et yème colonne en entier_a_mettre */
        void set_Tab(unsigned int x,unsigned int y,unsigned int entier);
        /** @brief fais tomber les meteorite d'une ligne*/
        bool Tombe(unsigned int k);
        /** @brief fais bouger le perso sur les comande g gauche et d droite et rien le perso ne bouge pas (changer par le sdl qui l'apel) */
        void Bouger(char deplacement);
        /** @brief ancien fonctionnement du jeu quelque modifications du mini_jeux pour s'implementer dans un autre jeu
        il suis l'implementation du jeu*/
        bool Jeu(string filename);
        /** @brief remplie la premier ligne d'un tableau a partir d'un fichier PAS UTILISER */
        void Tour(unsigned int tab[Taille][Taille],string & filename);
        /** @brief sert a afficher le jeu*/
        void Afficher(unsigned int tab[Taille][Taille]);

        void Test_Regression();

        /** Default constructor */
        Mini_Jeux0();
        /** Default destructor */
        virtual ~Mini_Jeux0();

    protected:

    private:
        unsigned int tab[Taille][Taille];
        unsigned int Position_X;
        unsigned int Position_Y;
};

#endif // MINI_JEUX0_H
