#include <Ennemis.h>

unsigned int const Ennemis::get_Position_X_Mini_Carte()const
{
    return Position_X_Mini_Carte;
}

unsigned int const Ennemis::get_Position_Y_Mini_Carte()const
{
    return Position_Y_Mini_Carte;
}
char const Ennemis::get_Direction()const
{
    return Direction;
}
char const Ennemis::get_Direction_Attaque()const
{
    return Direction_Attaque;
}
Statistiques const Ennemis::get_Stats_Ennemis()const
{
    return Stats_Ennemis;
}

string const Ennemis::get_Stats_Ennemis_Nom()const{
    return Stats_Ennemis.get_Nom();
}
unsigned int const Ennemis::get_Stats_Ennemis_Point_De_Vie()const{
    return Stats_Ennemis.get_Point_De_Vie();
}
unsigned int const Ennemis::get_Stats_Ennemis_Point_De_Vie_Max()const{
    return Stats_Ennemis.get_Point_De_Vie_Max();
}
unsigned int const Ennemis::get_Stats_Ennemis_Mana()const{
    return Stats_Ennemis.get_Mana_Max();
}
unsigned int const Ennemis::get_Stats_Ennemis_Mana_Max()const{
    return Stats_Ennemis.get_Mana_Max();
}
unsigned int const Ennemis::get_Stats_Ennemis_Experience_Restant()const{
    return Stats_Ennemis.get_Experience_Restant();
}
unsigned int const Ennemis::get_Stats_Ennemis_Experience_Donne()const{
    return Stats_Ennemis.get_Experience_Donne();
}
unsigned int const Ennemis::get_Stats_Ennemis_Niveau()const{
    return Stats_Ennemis.get_Niveau();
}
unsigned int const Ennemis::get_Stats_Ennemis_Force()const{
    return Stats_Ennemis.get_Force();
}
unsigned int const Ennemis::get_Stats_Ennemis_Intelligence()const{
    return Stats_Ennemis.get_Intelligence();
}
unsigned int const Ennemis::get_Stats_Ennemis_Agilite()const{
    return Stats_Ennemis.get_Agilite();
}
string const Ennemis::get_Fichier()const{
    return Fichier;
}

void Ennemis::set_Position_X_Mini_Carte(unsigned int x)
{
    Position_X_Mini_Carte=x;
}

void Ennemis::set_Position_Y_Mini_Carte(unsigned int y)
{
    Position_Y_Mini_Carte=y;
}
void Ennemis::set_Direction(char direction)
{
    Direction=direction;
}
void Ennemis::set_Direction_Attaque(char direction)
{
    Direction_Attaque=direction;
}
void Ennemis::set_Stats_Ennemis(class Statistiques s)
{
    Stats_Ennemis.set_Nom(s.get_Nom());
    Stats_Ennemis.set_Point_De_Vie_Max(s.get_Point_De_Vie_Max());
    Stats_Ennemis.set_Point_De_Vie(s.get_Point_De_Vie());
    Stats_Ennemis.set_Mana_Max(s.get_Mana_Max());
    Stats_Ennemis.set_Mana(s.get_Mana());
    Stats_Ennemis.set_Experience_Restant(s.get_Experience_Donne());
    Stats_Ennemis.set_Experience_Donne(s.get_Experience_Donne());
    Stats_Ennemis.set_Niveau(s.get_Niveau());
    Stats_Ennemis.set_Force(s.get_Force());
    Stats_Ennemis.set_Intelligence(s.get_Intelligence());
    Stats_Ennemis.set_Agilite(s.get_Agilite());
}

void Ennemis::set_Stats_Ennemis_Nom(string nom){
    Stats_Ennemis.set_Nom(nom);
}
void Ennemis::set_Stats_Ennemis_Point_De_Vie(unsigned int pv){
    Stats_Ennemis.set_Point_De_Vie(pv);
}
void Ennemis::set_Stats_Ennemis_Point_De_Vie_Max(unsigned int pv_max){
    Stats_Ennemis.set_Point_De_Vie_Max(pv_max);
}
void Ennemis::set_Stats_Ennemis_Mana(unsigned int mana){
    Stats_Ennemis.set_Mana(mana);
}
void Ennemis::set_Stats_Ennemis_Mana_Max(unsigned int mana_max){
    Stats_Ennemis.set_Mana_Max(mana_max);
}
void Ennemis::set_Stats_Ennemis_Experience_Restant(unsigned int xp_restant){
    Stats_Ennemis.set_Experience_Restant(xp_restant);
}
void Ennemis::set_Stats_Ennemis_Experience_Donne(unsigned int xp_donne){
    Stats_Ennemis.set_Experience_Donne(xp_donne);
}
void Ennemis::set_Stats_Ennemis_Niveau(unsigned int niv){
    Stats_Ennemis.set_Niveau(niv);
}
void Ennemis::set_Stats_Ennemis_Force(unsigned int force){
    Stats_Ennemis.set_Force(force);
}
void Ennemis::set_Stats_Ennemis_Intelligence(unsigned int inteligence){
    Stats_Ennemis.set_Intelligence(inteligence);
}
void Ennemis::set_Stats_Ennemis_Agilite(unsigned int agilite){
    Stats_Ennemis.set_Agilite(agilite);
}
void Ennemis::set_Ennemis(class Ennemis ennemis)
{

    Position_X_Mini_Carte = ennemis.get_Position_X_Mini_Carte();
    Position_Y_Mini_Carte = ennemis.get_Position_Y_Mini_Carte();
    Direction_Attaque = ennemis.get_Direction_Attaque();
    Direction=ennemis.get_Direction();
    Stats_Ennemis.set_Statistiques(ennemis.Stats_Ennemis);
    Fichier=ennemis.get_Fichier();
    /* ifstream fichier(Fichier.c_str());
    assert(fichier.is_open());
    char direction_attaque;
    string nom;
    unsigned int pv,pv_max,mana,mana_max,xp_donne,niv,force,intelligence,agilite;
    fichier>>direction_attaque>>nom>>pv>>pv_max>>mana>>mana_max>>xp_donne>>niv>>force>>intelligence>>agilite;
    set_Direction_Attaque(direction_attaque);
    set_Stats_Ennemis_Nom(nom);
    // set_Stats_Ennemis_Point_De_Vie_Max(pv_max);
    // set_Stats_Ennemis_Point_De_Vie(pv);
    // set_Stats_Ennemis_Mana_Max(mana_max);
    // set_Stats_Ennemis_Mana(mana);
    set_Stats_Ennemis_Experience_Donne(xp_donne);
    set_Stats_Ennemis_Niveau(niv);
    set_Stats_Ennemis_Force(force);
    set_Stats_Ennemis_Intelligence(intelligence);
    set_Stats_Ennemis_Agilite(agilite);
    fichier.close(); */
}

void Ennemis::set_Ennemis(string nom_fichier){
    ifstream fichier(nom_fichier.c_str());
    assert(fichier.is_open());
    Direction='d';
    char direction_attaque;
    string nom;
    unsigned int pv,pv_max,mana,mana_max,xp_donne,niv,force,intelligence,agilite;
    fichier>>direction_attaque>>nom>>pv>>pv_max>>mana>>mana_max>>xp_donne>>niv>>force>>intelligence>>agilite;
    set_Direction_Attaque(direction_attaque);
    set_Stats_Ennemis_Nom(nom);
    set_Stats_Ennemis_Point_De_Vie_Max(pv_max);
    set_Stats_Ennemis_Point_De_Vie(pv);
    set_Stats_Ennemis_Mana_Max(mana_max);
    set_Stats_Ennemis_Mana(mana);
    set_Stats_Ennemis_Experience_Donne(xp_donne);
    set_Stats_Ennemis_Niveau(niv);
    set_Stats_Ennemis_Force(force);
    set_Stats_Ennemis_Intelligence(intelligence);
    set_Stats_Ennemis_Agilite(agilite);
    fichier.close() ;
}

void Ennemis::set_Ennemis_Fichier(){
    ifstream fichier(Fichier.c_str());
    assert(fichier.is_open());
    char direction_attaque;
    string nom;
    unsigned int pv,pv_max,mana,mana_max,xp_donne,niv,force,intelligence,agilite;
    fichier>>direction_attaque>>nom>>pv>>pv_max>>mana>>mana_max>>xp_donne>>niv>>force>>intelligence>>agilite;
    set_Direction_Attaque(direction_attaque);
    set_Stats_Ennemis_Nom(nom);
    set_Stats_Ennemis_Point_De_Vie_Max(pv_max);
    set_Stats_Ennemis_Point_De_Vie(pv);
    set_Stats_Ennemis_Mana_Max(mana_max);
    set_Stats_Ennemis_Mana(mana);
    set_Stats_Ennemis_Experience_Donne(xp_donne);
    set_Stats_Ennemis_Niveau(niv);
    set_Stats_Ennemis_Force(force);
    set_Stats_Ennemis_Intelligence(intelligence);
    set_Stats_Ennemis_Agilite(agilite);
    fichier.close();
}
void Ennemis::set_Fichier(string nom_fichier){
    Fichier=nom_fichier;
}
Ennemis::Ennemis(unsigned int x_mini_carte,unsigned int y_mini_carte,
                 char direction,char direction_attaque,Statistiques stats)
{
    Position_X_Mini_Carte=x_mini_carte;
    Position_Y_Mini_Carte=y_mini_carte;
    Direction=direction;
    Direction_Attaque=direction_attaque;
    set_Stats_Ennemis(stats);
    Fichier=' ';
}
Ennemis::Ennemis()
{
    Position_X_Mini_Carte=0;
    Position_Y_Mini_Carte=0;
    Direction='g';
    Direction_Attaque='l';//pour qu'il attaque horizontalement par defaut
    Stats_Ennemis.set_Nom(" ");
    Stats_Ennemis.set_Point_De_Vie(0);
    Stats_Ennemis.set_Point_De_Vie_Max(0);
    Stats_Ennemis.set_Mana(0);
    Stats_Ennemis.set_Experience_Restant(0);
    Stats_Ennemis.set_Experience_Donne(0);
    Stats_Ennemis.set_Niveau(0);
    Stats_Ennemis.set_Force(0);
    Stats_Ennemis.set_Intelligence(0);
    Stats_Ennemis.set_Agilite(0);
    Fichier=' ';
}

Ennemis::~Ennemis()
{
    //dtor
}


bool Ennemis::Heros_Visible_Par_Ennemis(unsigned int Position_Heros_X,unsigned int Position_Heros_Y){
    if(Direction=='g'){
        if ((Position_Heros_Y==Position_Y_Mini_Carte)&&(Position_Heros_X+1==Position_X_Mini_Carte)){
            return true;
        }else{return false;}
    }else{if ((Position_Heros_Y==Position_Y_Mini_Carte)&&(Position_Heros_X-1==Position_X_Mini_Carte)){
            return true;
        }else{return false;}
        }
}
//abs(Ennemis_X-Heros_X)
//abs (y-Y)
//(dist X+dist Y)/2 calcul si ne peux pas diagonal
// (dist X>dist Y)=Dist X calcul si ne peux pas diagonal
// (dist X<dist y)=dist Y
void Ennemis::Deplacement_Ennemis_Automatique(Mini_Carte & mini_carte)
{
    if(!mini_carte.Est_Ce_Que_Mur(Position_X_Mini_Carte,Position_Y_Mini_Carte+1))
       {
           Position_Y_Mini_Carte+=1;//deplace l'ennemi tombe si il n'y'a pas de sol
       }
       else{

            if (Stats_Ennemis.get_Point_De_Vie()<=Stats_Ennemis.get_Point_De_Vie_Max()/10){
                Position_X_Mini_Carte=Position_X_Mini_Carte+1;//l'enemi fuis si il a moins de 10%hp
            }
            else{
                  if (((mini_carte.Est_Ce_Que_Mur(Position_X_Mini_Carte-1,Position_Y_Mini_Carte))&&
                      (mini_carte.Est_Ce_Que_Mur(Position_X_Mini_Carte-1,Position_Y_Mini_Carte+1)))
                       &&(Direction=='g')){
                            Position_X_Mini_Carte-=1;//deplace a gauche
                  }else{if (((mini_carte.Est_Ce_Que_Mur(Position_X_Mini_Carte+1,Position_Y_Mini_Carte))
                            &&(mini_carte.Est_Ce_Que_Mur(Position_X_Mini_Carte-1,Position_Y_Mini_Carte+1)))
                            &&(Direction=='d')) {
                            Position_X_Mini_Carte-=1;//deplace a droite
                            Direction='d';
                        }else{
                            if(mini_carte.Est_Ce_Que_Mur(Position_X_Mini_Carte-1,Position_Y_Mini_Carte-1))
                            {
                                if(mini_carte.Est_Ce_Que_Mur(Position_X_Mini_Carte+1,Position_Y_Mini_Carte-1))
                                {
                                    // le monstre ne peus plus bouger c'est beuguer
                                }else{
                                        Position_X_Mini_Carte+=1;
                                        Position_Y_Mini_Carte-=1;
                                        //deplace l'enemis haut+droite
                                    }
                            }else{
                                Position_X_Mini_Carte-=1;
                                Position_Y_Mini_Carte-=1;
                                //Deplace l'ennemis haut+gauche
                            }
                        }

                    }
            }
}
}

void Ennemis::Deplacement_Ennemis_Script(const class Mini_Carte & mini_carte){
    if (!mini_carte.Est_Ce_Que_Mur(Position_X_Mini_Carte,Position_Y_Mini_Carte+1)
        &&!mini_carte.Est_Ce_Que_Plateforme(Position_X_Mini_Carte,Position_Y_Mini_Carte+1))
        {Position_Y_Mini_Carte+=1 ;}
    else
    {
        switch (Direction){
                                case('d'):
                                    if (mini_carte.Est_Ce_Que_Vide(Position_X_Mini_Carte+1,Position_Y_Mini_Carte)
                                        &&Position_X_Mini_Carte+1<mini_carte.get_Taille_Mini_Carte_X()-1
                                        &&!mini_carte.Est_Ce_Que_Vide(Position_X_Mini_Carte+1,Position_Y_Mini_Carte+1))
                                    {Position_X_Mini_Carte+=1;}
                                    else{Direction='g';}
                                    break ;
                                case('g'):
                                    if (mini_carte.Est_Ce_Que_Vide(Position_X_Mini_Carte-1,Position_Y_Mini_Carte)
                                        &&Position_X_Mini_Carte-1>0
                                        &&!mini_carte.Est_Ce_Que_Vide(Position_X_Mini_Carte-1,Position_Y_Mini_Carte+1))
                                    {Position_X_Mini_Carte-=1;}
                                    else{Direction='d';}
                                    break ;
            }
    }
}


Objet Ennemis::Lache_Objet(Objet objet){
    if(Stats_Ennemis.get_Point_De_Vie()==0){
        return objet;
    }
        return objet;
}


unsigned int Ennemis::Attaque_Ennemis(const Mini_Carte & mini_carte){
    if (Direction_Attaque=='l'){
    if (Direction=='g'){
        if (Position_X_Mini_Carte!=0)
            {
                return Position_X_Mini_Carte-1;
            }
            else{
                    return Position_X_Mini_Carte;
                }
            }
            else {
                    if(Position_X_Mini_Carte!=mini_carte.get_Taille_Mini_Carte_X())
                    {
                        return Position_X_Mini_Carte+1;
                    }
                        else{
                                return Position_X_Mini_Carte;
                            }
                    }
        }
        return 0;
}

void Ennemis::Affiche_Ennemis()const{
    cout<<"Position_X "<<get_Position_X_Mini_Carte()<<" Position_Y: "<<get_Position_Y_Mini_Carte()
    <<" Attaque: "<<get_Direction_Attaque()<<" Direction: "<<get_Direction()<<" Stats_Ennemis: "<<endl;
    Stats_Ennemis.Affiche_Statistiques();
}

bool Ennemis::Toucher_Heros(unsigned int position_x,unsigned int position_y,unsigned int position_heros_x,
                            unsigned int position_heros_y)
{
    if((position_heros_x==position_x)&&(position_heros_y==position_y))
        {return true;}
    else{return false;}
}

void Ennemis::Ennemis_Touche(unsigned int degats){
    if(degats>Stats_Ennemis.get_Point_De_Vie()){
        set_Stats_Ennemis_Point_De_Vie(0);
    }else
        {
            set_Stats_Ennemis_Point_De_Vie(Stats_Ennemis.get_Point_De_Vie()-degats);
        }
}
bool Ennemis::Ennemis_Touche(unsigned int x,unsigned int y){
    if ((Position_X_Mini_Carte==x)&&(Position_Y_Mini_Carte==y)){
        return true;
    }else{
        return false;
        }


}
bool Ennemis::Ennemis_Mort(){
    if (Stats_Ennemis.get_Point_De_Vie()==0)
    {
        return true;
    }else   {
                return false;
            }
}

void Ennemis::Test_Regression(){
    string miaou="miaou";
    Statistiques s_chat(miaou,1500,1500,1000,1000,0,1,99,5000,1500,7);
    Affiche_Ennemis();
    set_Position_X_Mini_Carte(4);
    set_Position_Y_Mini_Carte(3);
    set_Direction_Attaque(0);
    set_Stats_Ennemis(s_chat);
    Affiche_Ennemis();
    Mini_Carte mini_carte("data/core/mini_map_1");
    Deplacement_Ennemis_Script(mini_carte);
    Deplacement_Ennemis_Automatique(mini_carte);
    Affiche_Ennemis();
}

