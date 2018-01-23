#include <iostream>
#include <Carte.h>
#include <Mini_Carte.h>
#include <Ennemis.h>

using namespace std;

int main()
{
    cout << "Coucou toi connard !" << endl ;

    /* Mini_Carte mc("data/core/Mini_map/mini_map_3") ;
    Mini_Carte mv("data/core/Mini_map/mini_map_4") ;
    mc.Affiche_Non_Vide() ;
    mv.Affiche_Non_Vide() ; */

    /* Carte jeu ;
    jeu.Creer_Carte_Complet(5,5) ; */
    int * test ;
    test = new int ;
    cout << *test << " " << &test << endl ;


    cout << "FIN" << endl ;
    return 0 ;
}

/*  Carte jeu ;
    jeu.Test_Regression() ; */

/* Carte jeu(20,9) ;
    jeu.Creer_Carte() ;

    jeu.Affiche_Carte() ;
    jeu.Affiche_Chemin() ;
    jeu.Affiche_Mur() ; */

/*  Mini_Carte mc("data/core/mini_map_2") ;
    Mini_Carte mv("data/core/mini_map_1") ;
    mc.Affiche_Non_Vide() ;
    mc.set_Mini_Carte(mv) ;
    mc.Affiche_Non_Vide() ; */

/*  Mini_Carte mc("data/core/mini_map_2") ;
    Mini_Carte mk ;
    jeu.set_Tab_Mini_Carte(0, 0, mc) ;
    jeu.get_Tab_Mini_Carte(0, 0, mk) ;
    mk.Affiche_Non_Vide() ; */
