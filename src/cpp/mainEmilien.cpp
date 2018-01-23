#include <iostream>
#include <Ennemis.h>
#include <Statistiques.h>
#include <Carte.h>
#include <Mini_Carte.h>
#include <string>
#include <Mini_Jeux0.h>

using namespace std;

int main()
{

    unsigned int a=3;
    unsigned int b=3;
    Mini_Jeux0 test;
    /*test.Set_Position_X(a);
    test.Set_Position_y(b);*/
    test.Jeu("data/Mini_Jeux/test.txt");
    /*
    Ennemis miaou;
    miaou.set_Fichier("data/core/Ennemis/miaou.txt");
    miaou.set_Ennemis_Fichier();
    miaou.Affiche_Ennemis();


    cout << "Coucou toi !" << endl ;

    Carte jeu;
    jeu.Creer_Carte_Complet(3,3);

    cout << "FIN" << endl ;
    */





    /*string miaou="miaou";
    Statistiques s_chat(miaou,1500,1500,1000,1000,0,1,99,5000,1500,7);
    Ennemis chat(1,1,1,1,'g',1,s_chat);
    Enemis tab[3][5];


    for(unsigned int k=0;k<=4;k++){
            tab[1][k].get_Stats_Ennemis().set_Agilite(1);
            cout<<tab[1][k].get_Stats_Ennemis().get_Agilite()<<"test";
    }

    for(unsigned int i=0;i<3;i++)
    {
        for(unsigned int j=0;j<=4;j++){
            cout<<tab[i][j].get_Stats_Ennemis().get_Agilite();
    }       cout<<endl;
    }
    tab[chat.get_Position_X()][chat.get_Position_Y()].get_Stats_Ennemis().set_Agilite(chat.get_Stats_Ennemis().get_Agilite());
    tab[chat.get_Position_X()][chat.get_Position_Y()].set_Position_X(chat.get_Position_X());
    tab[chat.get_Position_X()][chat.get_Position_Y()].set_Position_Y(chat.get_Position_Y());
    while(1){
        tab[chat.get_Position_X()][chat.get_Position_Y()].Deplacement_Ennemis_Automatique();
    for(unsigned int i=0;i<3;i++)
    {
        for(unsigned int j=0;j<=4;j++){
            cout<<tab[i][j].get_Stats_Ennemis().get_Agilite();
    }       cout<<endl;
    }
    }


    s_chat.Test_Regression();
    chat.Test_Regression();*/

    cout << "Bonjour je suis le main de Emilien ET je suis le meillieur" << endl;
    return 0;
}
