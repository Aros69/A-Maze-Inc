#include <iostream>
#include <JeuTXT.h>
#include <winTxt.h>


using namespace std ;

int main (int argc, char** argv )
{
    cout << "Avant de commencer le jeu nous vous recommandons d'agrandir la fenetre de jeu" << endl <<
     "puis d'appuyer sur entrée pour démarrer" << endl ;

    cin.get() ;
    termClear() ;
    Jeu jeu ;
    cout << "On crée le labyrinthe" << endl ;
    jeu.Labyrinthe() ;
    // cout << "On lance la boucle" << endl ;
    txtBoucle(jeu) ;
    termClear() ;

    cout << "Merci d'avoir joué !" << endl ;

    return 0 ;
}
