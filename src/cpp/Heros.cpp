#include <Heros.h>

Heros::Heros()
{
	Position_X_Mini_Carte = 0;
	Position_Y_Mini_Carte = 0;
	Position_X_Carte = 0;
	Position_Y_Carte = 0;
	Dans_Air = false ;
	Moment_Saut = 0 ;
	Orientation = 'd' ;
	Recharge_Magique = 0;
}

Heros::~Heros()
{

}

void Heros::Deplace_Gauche(const Mini_Carte & mc)
{
   if (Position_X_Mini_Carte>0
        &&!mc.Est_Ce_Que_Mur(Position_X_Mini_Carte-1, Position_Y_Mini_Carte))
    {
        Position_X_Mini_Carte -= 1;
    }
}

void Heros::Deplace_Droite(const Mini_Carte & mc)
{
    if (Position_X_Mini_Carte<mc.get_Taille_Mini_Carte_X()-1
        &&!mc.Est_Ce_Que_Mur(Position_X_Mini_Carte+1, Position_Y_Mini_Carte))
    {
        Position_X_Mini_Carte += 1;
    }
}

void Heros::Saut(const Mini_Carte & mc)
{
    if  (Moment_Saut>0  && Moment_Saut <=2)
    {
        if(Position_Y_Mini_Carte-1>=0)
        {
            Dans_Air = true ;
            if (Position_Y_Mini_Carte-1==0
                &&!mc.Est_Ce_Que_Mur(Position_X_Mini_Carte,Position_Y_Mini_Carte-1))
            {
                Position_Y_Mini_Carte-=1 ;
                Moment_Saut=0 ;
            }
            else if(!mc.Est_Ce_Que_Mur(Position_X_Mini_Carte,Position_Y_Mini_Carte-1)
                    &&mc.Est_Ce_Que_Mur(Position_X_Mini_Carte,Position_Y_Mini_Carte-2))
                {
                    Position_Y_Mini_Carte-=1 ;
                    Moment_Saut=0 ;
                }
                else if(!mc.Est_Ce_Que_Mur(Position_X_Mini_Carte,Position_Y_Mini_Carte-1)
                        &&!mc.Est_Ce_Que_Mur(Position_X_Mini_Carte,Position_Y_Mini_Carte-2))
                    {
                        Position_Y_Mini_Carte-=2 ;
                        Moment_Saut-=1 ;
                    }
                    else
                        {Moment_Saut=0 ;}
        }
        else
        {Moment_Saut=0 ;}
    }
}

void Heros::Deplace_Haut(const Mini_Carte & mc)
{
    if((mc.Est_Ce_Que_Plateforme(Position_X_Mini_Carte, Position_Y_Mini_Carte-1))
       || (!mc.Est_Ce_Que_Mur(Position_X_Mini_Carte, Position_Y_Mini_Carte-1)))
    {
        Position_Y_Mini_Carte -= 1;
    }
}


void Heros::Deplace_Bas(const Mini_Carte & mc)
{
   if (mc.Est_Ce_Que_Plateforme(Position_X_Mini_Carte, Position_Y_Mini_Carte+1)
        ||!mc.Est_Ce_Que_Mur(Position_X_Mini_Carte, Position_Y_Mini_Carte+1))
        {
            Position_Y_Mini_Carte += 1;
        }

}

void Heros::Gravite(const Mini_Carte & mc)
{
    if (Position_Y_Mini_Carte==mc.get_Taille_Mini_Carte_Y()-1)
    {
        Dans_Air = false ;
    }
    else if(!mc.Est_Ce_Que_Mur(Position_X_Mini_Carte,Position_Y_Mini_Carte+1)
            &&!mc.Est_Ce_Que_Plateforme(Position_X_Mini_Carte,Position_Y_Mini_Carte+1)
            &&Moment_Saut==0)
        {
            Dans_Air = true ;
            set_Position_Y_Mini_Carte(Position_Y_Mini_Carte+1) ;
        }
        else
        {Dans_Air=false;}
}

unsigned int Heros::get_Position_X_Mini_Carte() const
{
    return Position_X_Mini_Carte;
}

unsigned int Heros::get_Position_Y_Mini_Carte() const
{
    return Position_Y_Mini_Carte;
}

unsigned int Heros::get_Position_X_Carte() const
{
    return Position_X_Carte;
}

unsigned int Heros::get_Position_Y_Carte() const
{
    return Position_Y_Carte;
}

char Heros::get_Orientation() const
{
    return Orientation ;
}

bool Heros::get_Dans_Air() const
{
    return Dans_Air ;
}

unsigned int Heros::get_Moment_Saut() const
{
        return Moment_Saut ;
}

void Heros::set_Position_X_Mini_Carte(unsigned int Pos_X_Mini_Carte_nouv)
{
    Position_X_Mini_Carte = Pos_X_Mini_Carte_nouv;
}

void Heros::set_Position_Y_Mini_Carte(unsigned int Pos_Y_Mini_Carte_nouv)
{
    Position_Y_Mini_Carte = Pos_Y_Mini_Carte_nouv;
}

void Heros::set_Position_X_Carte(unsigned int Pos_X_Carte_nouv)
{
    Position_X_Carte = Pos_X_Carte_nouv;
}

void Heros::set_Position_Y_Carte(unsigned int Pos_Y_Carte_nouv)
{
    Position_Y_Carte = Pos_Y_Carte_nouv;
}

void Heros::set_Heros(string Nom_Fic)
{
    ifstream fic(Nom_Fic.c_str());
    assert(fic.is_open());
    string nom;
    char orientation;
    unsigned int pv, pv_max, mana, mana_max, exp_res, exp_don, niveau, force, intelligence, agilite;
    fic >> orientation >> nom >> pv_max >> pv >> mana_max >> mana >> exp_res >> exp_don >> niveau >> force >> intelligence >> agilite;
    set_Orientation(orientation);
    set_Point_De_Vie_Max(pv_max);
    set_Point_De_Vie(pv);
    set_Mana_Max(mana_max);
    set_Mana(mana);
    set_Experience_Restant(exp_res);
    set_Experience_Donne(exp_don);
    set_Niveau(niveau);
    set_Force(force);
    set_Intelligence(intelligence);
    set_Agilite(agilite);
    fic.close();
}

string Heros::get_Nom()const
{
    return Stats.get_Nom();
}
unsigned int Heros::get_Point_De_Vie()const
{
    return Stats.get_Point_De_Vie();
}
unsigned int Heros::get_Point_De_Vie_Max()const
{
    return Stats.get_Point_De_Vie_Max();
}
unsigned int Heros::get_Mana()const
{
    return Stats.get_Mana();
}
unsigned int Heros::get_Mana_Max()const
{
    return Stats.get_Mana_Max();
}
unsigned int Heros::get_Experience_Restant()const
{
    return Stats.get_Experience_Restant();
}
unsigned int Heros::get_Experience_Donne()const
{
    return Stats.get_Experience_Donne();
}
unsigned int Heros::get_Niveau()const
{
    return Stats.get_Niveau();
}
unsigned int Heros::get_Force()const
{
    return Stats.get_Force();
}
unsigned int Heros::get_Intelligence()const
{
    return Stats.get_Intelligence();
}
unsigned int Heros::get_Agilite()const
{
    return Stats.get_Agilite();
}

unsigned int Heros::get_Recharge_Magique()const
{
    return Recharge_Magique;
}

void Heros::set_Nom(string nom)
{
    Stats.set_Nom(nom);
}
void Heros::set_Point_De_Vie(unsigned int Pv)
{
    assert(Pv <= Stats.get_Point_De_Vie_Max());
    Stats.set_Point_De_Vie(Pv);
}
void Heros::set_Point_De_Vie_Max(unsigned int Pv_Max)
{
    assert(Pv_Max >= Stats.get_Point_De_Vie());
    Stats.set_Point_De_Vie_Max(Pv_Max);
}

void Heros::set_Mana(unsigned int Mana_nouv)
{
    assert(Mana_nouv <= Stats.get_Mana_Max());
    Stats.set_Mana(Mana_nouv);
}
void Heros::set_Mana_Max(unsigned int Mana_Max_nouv)
{
    assert(Mana_Max_nouv >= Stats.get_Mana());
    Stats.set_Mana_Max(Mana_Max_nouv);
}
void Heros::set_Experience_Restant(unsigned int Exp_rest)
{
    Stats.set_Experience_Restant(Exp_rest);
}
void Heros::set_Experience_Donne(unsigned int Exp_don)
{
    Stats.set_Experience_Donne(Exp_don);
}
void Heros::set_Niveau(unsigned int Niveau_nouv)
{
    Stats.set_Niveau(Niveau_nouv);
}
void Heros::set_Force(unsigned int Force_nouv)
{
    Stats.set_Force(Force_nouv);
}
void Heros::set_Intelligence(unsigned int Intel_nouv)
{
    Stats.set_Intelligence(Intel_nouv);
}
void Heros::set_Agilite(unsigned int Agilite_nouv)
{
    Stats.set_Agilite(Agilite_nouv);
}

void Heros::set_Dans_Air(bool dans_air)
{
    Dans_Air = dans_air ;
}

void Heros::set_Moment_Saut(unsigned int moment_saut)
{
    assert(moment_saut>=0) ;
    assert(moment_saut<=2) ;
    Moment_Saut=moment_saut ;
}

Statistiques Heros::get_Stats () const
{
    return Stats;
}


void Heros::set_Stats (class Statistiques sta)
{
    Stats.set_Nom(sta.get_Nom());
    Stats.set_Point_De_Vie(sta.get_Point_De_Vie());
    Stats.set_Point_De_Vie_Max(sta.get_Point_De_Vie_Max());
    Stats.set_Mana(sta.get_Mana());
    Stats.set_Mana_Max(sta.get_Mana_Max());
    Stats.set_Experience_Donne(sta.get_Experience_Donne());
    Stats.set_Experience_Restant(sta.get_Experience_Restant());
    Stats.set_Niveau(sta.get_Niveau());
    Stats.set_Force(sta.get_Force());
    Stats.set_Intelligence(sta.get_Intelligence());
    Stats.set_Agilite(sta.get_Agilite());
}

Equipement Heros::get_Equip() const
{
    return Equip;
}

void Heros::set_Equip(class Equipement Equip_nouv)
{
    Equip.set_Stats_Arme(Equip_nouv.get_Stats_Arme());
    Equip.set_Stats_Bouclier(Equip_nouv.get_Stats_Bouclier());
    Equip.set_Stats_Casque(Equip_nouv.get_Stats_Casque());
}

void Heros::set_Orientation(char orientation)
{
    assert(orientation == 'd' || orientation == 'g') ;
    Orientation = orientation ;
}

void Heros::set_Recharge_Magique(unsigned int Rech_Mag_nouv)
{
    Recharge_Magique = Rech_Mag_nouv;
}

unsigned int Heros::Attaque_Arme(const Mini_Carte & mini_carte)
{
    if(Orientation == 'g') {
        if (Position_X_Mini_Carte!=0)
        {
            return Position_X_Mini_Carte-1;
        }
    }
        else{
            if(Position_X_Mini_Carte!=mini_carte.get_Taille_Mini_Carte_X())
                {
                    return Position_X_Mini_Carte+1;
                }else{
                    return Position_X_Mini_Carte;
                }
        }
    return 0;
}


/*unsigned int Heros::Attaque_Magique(const Mini_Carte & mini_carte, Ennemis mechant)
{
    unsigned int posx = Position_X_Mini_Carte;
    if(get_Mana() != 0)
    {
        if(Orientation == 'g')
        {
            while(posx != mechant.get_Position_X_Mini_Carte())
            {
                posx += 1;
            }
        }
    }
    return 0;
}*/

unsigned int Heros::Attaque_Magique (const Mini_Carte & mc,unsigned int & posy)
{
    unsigned int posx = Position_X_Mini_Carte; // Emplacement de l'attaque magique
    if(get_Mana() != 0)
    {
        if(!get_Recharge_Magique())
        {
            if(Orientation == 'd')
            {
                    posx += 1;
            }
            else if(Orientation == 'g')
            {
                    posx -= 1;
            }
            Recharge_Magique=1;
            posy=Position_Y_Mini_Carte;
        }
    }
    return posx;
}


bool Heros::Est_Sur_Meme_Case_Que_Ennemi(Ennemis mechant)
{
   if((Position_X_Mini_Carte == mechant.get_Position_X_Mini_Carte()) && (Position_Y_Mini_Carte == mechant.get_Position_Y_Mini_Carte()))
   {
	if(Orientation == 'g')
	{
	   Position_X_Mini_Carte += 2;
	}else{
	   Position_X_Mini_Carte -= 2;
	}
   }
}

bool Heros::Meurt()
{
    if(Stats.get_Point_De_Vie() == 0)
    {
        return true;
    }
    return false;
}

void Heros::Prends_Degats(unsigned int degats){
    if(degats>=Stats.get_Point_De_Vie()){
        Stats.set_Point_De_Vie(0);
    }
    else
    {
        Stats.set_Point_De_Vie(Stats.get_Point_De_Vie()-degats);
    }
}

void Heros::Test_Regression()
{
    cout << "Début du texte de régression du héros" << endl;
    cout << "Appel du constructeur" << endl;
    Heros h1;
    cout << "Utilisation des set" << endl;
    string nomH = "Goku";
    Statistiques statsH(nomH, 500, 500, 2000, 2000, 10, 10, 99, 5000, 1500, 7);
    h1.set_Position_X_Carte(2);
    h1.set_Position_Y_Carte(2);
    h1.set_Position_X_Mini_Carte(2);
    h1.set_Position_Y_Mini_Carte(2);

    cout << "Utilisation des get" << endl;
    h1.get_Position_X_Carte();
    h1.get_Position_Y_Carte();
    h1.get_Position_X_Mini_Carte();
    h1.get_Position_Y_Mini_Carte();
    h1.get_Stats();
    cout << "Fin du test de régression du héros" << endl;
}
