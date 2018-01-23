#include <Mini_Jeux0.h>

Mini_Jeux0::Mini_Jeux0()
{
    /*unsigned int i,j;
    for (i=0;i<Taille;i++){
        for (j=0;j<Taille;j++){
            evite_meteore.tab[i][j]=0;
                             }
                        }*/
    //cree les contours de la map a gauche
    unsigned int i,j;
    for (i=1;i<Taille;i++){
        for (j=1;j<Taille;j++){
            tab[i][j]=0;
                             }
                        }
    //cree les contours de la map en bas
    for (i=0;i<Taille-1;i++){
        j=0;
        tab[i][0]=1;
        j=Taille-1;
        tab[i][Taille-1]=1;
            }
        //cree les contours de la map a droite
        i=Taille-1;
        for (j=0;j<Taille;j++){
            tab[i][j]=1;
                }
        //initialise le heros a sa positio initial
        Position_X=5;
        Position_Y=Taille-2;

}

Mini_Jeux0::~Mini_Jeux0()
{
    //dtor
}


unsigned int const Mini_Jeux0::get_Position_X()const{
    return Position_X;
}

unsigned int const Mini_Jeux0::get_Position_Y()const{
    return Position_Y;
}
unsigned int const Mini_Jeux0::get_Tab(unsigned int x, unsigned int y)const{
    assert(x>=0);
    assert(y>=0);
    assert(x<Taille);
    assert(y<Taille);
    return tab[y][x];
}

void Mini_Jeux0::set_Position_X(unsigned int posx){
    Position_X=posx;
}

void Mini_Jeux0::set_Position_Y(unsigned int posy){
    Position_Y=posy;
}
void Mini_Jeux0::set_Tab(unsigned int x,unsigned int y,unsigned int entier){
    tab[y][x]=entier;
}


void Mini_Jeux0::Tour(unsigned int tab[Taille][Taille],string & filename){
    unsigned int a;
    ifstream fichier (filename.c_str());
    assert(fichier.is_open());
        for(unsigned int j=1;j<Taille-1;j++){
            //cout<<"donnez si espace vide 0 sinon 1"<<j<<endl;
            fichier>>a;
            assert(a==0 ||a==1);
            tab[0][j]=a;
        }
    fichier.close();

}

void Mini_Jeux0::Afficher(unsigned int tab[Taille][Taille]){
    //astuce pour faire afficher la position du heros
    tab[Position_Y][Position_X]=7;
    for (unsigned int i=0;i<Taille;i++){
         for (unsigned int j=0;j<Taille;j++){
            cout<<tab[i][j];
         }
        cout<<endl;
    }
    tab[Position_Y][Position_X]=0;

}

bool Mini_Jeux0::Tombe(unsigned int k){
    for (unsigned int j=1;j<Taille-1;j++){
            //cout<<endl<<tab[k][j]<<endl;
            if (tab[k][j]==1){
              //  cout<<endl<<tab[k+1][j]<<endl;
        if (tab[k+1][j]==0){
            tab[k][j]=0;
            tab[k+1][j]=1;
            if((k+1==Position_Y)&&(j==Position_X)){
                return true;
            }
    }
    }

    }
    return false;
}

bool Mini_Jeux0::Jeu(string filename){
    bool continu=1;
    unsigned int k=Taille-1;
    //Afficher(tab);
    ifstream fichier (filename.c_str());
    assert(fichier.is_open());
    while(continu==1){
        if (k==Taille-1){
            unsigned int a;
        for(unsigned int j=0;j<Taille;j++){
            //cout<<"donnez si espace vide 0 sinon 1"<<j<<endl;
            fichier>>a;
            assert(a==0 ||a==1);
            tab[0][j]=a;
        }

        k=0;
        }
        //Afficher(tab);
        char deplacement;
        cin>>deplacement;
        system("cls");
        Afficher(tab);
        Bouger(deplacement);
        system("cls");
        Afficher(tab);
        continu=!Tombe(k);
        k+=1;
        if (Position_Y==0){continu=1;
        return true;}




    }

    fichier.close();


}

void Mini_Jeux0::Bouger(char deplacement)
{
    bool vide=false;

    //if (Position_Y!=7)
    while ((tab[Position_Y+1][Position_X]==0)&&(Position_Y!=Taille-1))
    {
        Position_Y+=1;
        vide=true;
    }
    if (!vide){

        switch (deplacement) {
                            case('g'): if( ((Position_X<Taille)&&(Position_X>0)) && (Position_Y<Taille) ){

                                    if (tab[Position_Y][Position_X-1]==0)
                                        {
                                        //    cout<<"je suis dans la bonne fonction";
                                            Position_X=Position_X-1;
                                        //    cout<<Position_X<<" "<<Position_Y;
                                    }

                                else {//cout << "bonne Position";
                                        if (tab[Position_Y-1][Position_X-1]==0)
                                        {
                                            Position_Y-=1;
                                            Position_X-=1;
                                    }
                                }
                            }
                            break;
                            case('d'):
                            if( ((Position_X<Taille-1)&&(Position_X>=0)) && (Position_Y<Taille) ){
                            if (tab[Position_Y][Position_X+1]!=1){
                                            Position_X+=1;
                                }else {if (tab[Position_Y-1][Position_X+1]!=1){
                                            Position_Y-=1;
                                            Position_X+=1;
                                }else {cout<<"Erreur";}
                                }
                            }
                            break;

    }
    //cout<<Position_X<<" "<<Position_Y;
}}


void Mini_Jeux0::Test_Regression(){

    for (unsigned int i=0;i<Taille;i++){
         for (unsigned int j=0;j<Taille;j++){
            tab[i][j]=0;
         }
    }
    Position_X=3;
    Position_Y=Taille-1;
    tab[Position_Y][Position_X]=Taille-1;// avant le heros etait reconnu par un chiffre different
    // ne fonctionne plus du a un changement dans la facon d'apercevoir le heros
    //Jeu("test.txt");

}
