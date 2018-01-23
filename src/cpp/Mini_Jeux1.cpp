#include<iostream>
#include<cassert>
#include<string.h>
#include<fstream>
#include<cstdlib>

const  unsigned int Taille=8;

using namespace std;
/** @brief remplie la premiere ligne du tableau de 0(rien) et 1(meteorite)*/

void Tour(unsigned int tab[Taille][Taille],string & filename){
    unsigned int a;
    ifstream fichier (filename.c_str());
    assert(fichier.is_open());
        for(unsigned int j=0;j<Taille;j++){
            //cout<<"donnez si espace vide 0 sinon 1"<<j<<endl;
            fichier>>a;
            cout<<a<<" ";
            assert(a==0 ||a==1);
            tab[0][j]=a;
        }
    fichier.close();

}

void Afficher(unsigned int tab[Taille][Taille]){
    for (unsigned int i=0;i<8;i++){
         for (unsigned int j=0;j<8;j++){
            cout<<tab[i][j];
         }
        cout<<endl;
    }

}

/** @brief fais bouger le perso sur les comande q gauche et d droite et rien le perso ne bouge pas */
void Bouger(unsigned int tab[Taille][Taille],unsigned int & Position_X,unsigned int & Position_Y)
{
    bool vide=false;
    char deplacement;

    //if (Position_Y!=7)
    while ((tab[Position_Y+1][Position_X]==0)&&(Position_Y!=Taille-1))
    {
        tab[Position_Y][Position_X]=0;
        Position_Y+=1;
        tab[Position_Y][Position_X]=Taille-1;
        vide=true;
    }
    if (!vide){
        cin>>deplacement;
        system("cls");
        switch (deplacement) {
                            case('q'): if( ((Position_X<Taille)&&(Position_X>0)) && (Position_Y<Taille) ){

                                    if (tab[Position_Y][Position_X-1]==0)
                                        {
                                        //    cout<<"je suis dans la bonne fonction";
                                            Position_X=Position_X-1;
                                            tab[Position_Y][Position_X+1]=0;
                                        //    cout<<Position_X<<" "<<Position_Y;
                                    }

                                else {//cout << "bonne Position";
                                        if (tab[Position_Y-1][Position_X-1]==0)
                                        {
                                            Position_Y-=1;
                                            Position_X-=1;
                                            tab[Position_Y+1][Position_X+1]=0;
                                    }
                                }
                            }
                            break;
                            case('d'):
                            if( ((Position_X<Taille-1)&&(Position_X>=0)) && (Position_Y<Taille) ){
                            if (tab[Position_Y][Position_X+1]!=1){
                                            Position_X+=1;
                                             tab[Position_Y][Position_X-1]=0;
                                }else {if (tab[Position_Y-1][Position_X+1]!=1){
                                            Position_Y-=1;
                                            Position_X+=1;
                                            tab[Position_Y+1][Position_X-1]=0;
                                }else {cout<<"Erreur";}
                                }
                            }
                            break;

    }
    tab[Position_Y][Position_X]=7;
    //cout<<Position_X<<" "<<Position_Y;
}}

/** @brief fais tomber les meteorite d'une ligne*/
void Tombe(unsigned int tab[Taille][Taille],unsigned int k,bool &continu){
    for (unsigned int j=0;j<Taille;j++){
            //cout<<endl<<tab[k][j]<<endl;
            if (tab[k][j]==1){
              //  cout<<endl<<tab[k+1][j]<<endl;
        if (tab[k+1][j]==0){
            tab[k][j]=0;
            tab[k+1][j]=1;
    }else if(tab[k+1][j]==Taille-1){
    cout<<"PERDU!!!!!!!!!!!!!!!";
    continu=0;
    }
    }
    }
}

/** @brief lance le jeu et verifie si gagner perdu*/
void Jeu(unsigned int tab[Taille][Taille],unsigned int & Position_X,unsigned int & Position_Y,string filename){
    bool continu=1;
    unsigned int k=Taille-1;
    Afficher(tab);
    ifstream fichier (filename.c_str());
    assert(fichier.is_open());
    while(continu==1){
        if (k==Taille-1){
            unsigned int a;
        for(unsigned int j=0;j<Taille;j++){
            //cout<<"donnez si espace vide 0 sinon 1"<<j<<endl;
            fichier>>a;
            cout<<a<<" ";
            assert(a==0 ||a==1);
            tab[0][j]=a;
        }

        k=0;
        }
        //Afficher(tab);
        Bouger(tab,Position_X,Position_Y);
        system("cls");
        Afficher(tab);
        Tombe(tab,k,continu);
        k+=1;
        if (Position_Y==0){continu=0;
        cout<<"Gagner";}




    }

    fichier.close();


}


int main(void){
    unsigned int tab[Taille][Taille];
    for (unsigned int i=0;i<Taille;i++){
         for (unsigned int j=0;j<Taille;j++){
            tab[i][j]=0;
         }
    }
    unsigned int Position_X,Position_Y;
    Position_X=3;
    Position_Y=Taille-1;
    tab[Position_Y][Position_X]=Taille-1;
    Jeu(tab,Position_X,Position_Y,"test.txt");

        return 0;

}
