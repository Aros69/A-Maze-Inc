#include <Jeu.h>

Jeu::Jeu()
{
    Jeu_Tab_Ennemis = NULL ;
    /*unsigned int i,j;
    for (i=0;i<Taille;i++){
        for (j=0;j<Taille;j++){
            Jeu_Mini_Jeux.tab[i][j]=0;
                             }
                        }*/
    unsigned int i,j;
    for (i=1;i<Taille;i++){
        for (j=1;j<Taille;j++){
            Jeu_Mini_Jeux.set_Tab(j,i,0);
                             }
                        }
    for (i=0;i<Taille-1;i++){
        j=0;
        Jeu_Mini_Jeux.set_Tab(j,i,1);
        j=Taille-1;
        Jeu_Mini_Jeux.set_Tab(Taille-1,i,1);
            }
        i=Taille-1;
        for (unsigned int j=0;j<Taille;j++){
            Jeu_Mini_Jeux.set_Tab(j,i,1);
                }
        Jeu_Mini_Jeux.set_Position_X(5);
        Jeu_Mini_Jeux.set_Position_Y(Taille-2);
}


Jeu::~Jeu()
{
    delete [] Jeu_Tab_Ennemis ;
    Jeu_Tab_Ennemis = NULL ;
}

const Carte & Jeu::get_Const_Jeu_Carte() const
{
    return Jeu_Carte ;
}

const Mini_Carte& Jeu::get_Const_Jeu_Mini_Carte () const
{
    return Jeu_Mini_Carte ;
}

const Heros& Jeu::get_Const_Jeu_Heros () const
{
    return Jeu_Heros ;
}

const Ennemis & Jeu::get_Const_Jeu_Tab_Ennemis() const
{
    return *Jeu_Tab_Ennemis ;
}

Ennemis & Jeu::get_Jeu_Tab_Ennemis(unsigned int i) const
{
    return Jeu_Tab_Ennemis[i] ;
}

Mini_Jeux0  Jeu::get_Jeu_Mini_Jeux()const{
    return Jeu_Mini_Jeux;
}

void Jeu::Action_Clavier (const char touche,unsigned int & position_attaque_magique_x,
                          unsigned int & position_attaque_magique_y,char & orientation_attaque_magique)
{
	switch(touche)
	{
		case 'g' :
        {
		    Au_Bord() ;
            Jeu_Heros.Deplace_Gauche(Jeu_Mini_Carte);
            int i=Recherche_Ennemis(Jeu_Heros.get_Position_X_Mini_Carte(),
                                             Jeu_Heros.get_Position_Y_Mini_Carte());
            if(i!=-1)
            {
                Jeu_Heros.Prends_Degats(Jeu_Tab_Ennemis[i].get_Stats_Ennemis_Force());
            }
            Jeu_Heros.set_Orientation('g');
            break;
		}
		case 'd' :
        {
		    Au_Bord() ;
            Jeu_Heros.Deplace_Droite(Jeu_Mini_Carte);
            int i=Recherche_Ennemis(Jeu_Heros.get_Position_X_Mini_Carte(),Jeu_Heros.get_Position_Y_Mini_Carte());
            if(i!=-1)
            {
                Jeu_Heros.Prends_Degats(Jeu_Tab_Ennemis[i].get_Stats_Ennemis_Force());
            }
            Jeu_Heros.set_Orientation('d');
            break;
        }
		case 'h' :
            if (!Jeu_Heros.get_Dans_Air())
            {
                Jeu_Heros.set_Moment_Saut(2);
                int i=Recherche_Ennemis(Jeu_Heros.get_Position_X_Mini_Carte(),Jeu_Heros.get_Position_Y_Mini_Carte());
                if(i!=-1)
                {
                    Jeu_Heros.Prends_Degats(Jeu_Tab_Ennemis[i].get_Stats_Ennemis_Force());
                }
                Jeu_Heros.Saut(Jeu_Mini_Carte);
            }
            break;
		case 'b' :
        {
            Jeu_Heros.Deplace_Bas(Jeu_Mini_Carte);
            int i=Recherche_Ennemis(Jeu_Heros.get_Position_X_Mini_Carte(),Jeu_Heros.get_Position_Y_Mini_Carte());
            if(i!=-1)
            {
                Jeu_Heros.Prends_Degats(Jeu_Tab_Ennemis[i].get_Stats_Ennemis_Force());
            }
            Au_Bord() ;
            break ;
        }
        case ' ' :
        {
            int i=Recherche_Ennemis(Jeu_Heros.Attaque_Arme(Jeu_Mini_Carte),
                                    Jeu_Heros.get_Position_Y_Mini_Carte());
            if(i!=-1)
            {
                Jeu_Tab_Ennemis[i].Ennemis_Touche(Jeu_Heros.get_Force());
                if(Jeu_Tab_Ennemis[i].Ennemis_Mort())
                    {Supprime_Ennemis(i);}
            }
            break ;
        }
        case 'n':
        {
            if (Jeu_Heros.get_Recharge_Magique()==0)
            {
                position_attaque_magique_x=Jeu_Heros.Attaque_Magique(Jeu_Mini_Carte, position_attaque_magique_y);
                orientation_attaque_magique=Jeu_Heros.get_Orientation();
            }
            break ;
        }
        case 'e':
            Lance_Mini_Jeux();
            break;
    }
}


void Jeu::Action_Automatique(unsigned int & vitesse_attaque,unsigned int & position_attaque_magique_x,
                             unsigned int position_attaque_magique_y,const char orientation_attaque_magique)
{
    Au_Bord() ; //Doit être avant saut et gravité
    Jeu_Heros.Saut(Jeu_Mini_Carte) ;
    Jeu_Heros.Gravite(Jeu_Mini_Carte) ;
    if (Jeu_Heros.get_Recharge_Magique()==1)
    {
        if(((!Jeu_Mini_Carte.Est_Ce_Que_Mur(position_attaque_magique_x,position_attaque_magique_y))&&
           ((position_attaque_magique_x+1<Jeu_Mini_Carte.get_Taille_Mini_Carte_X())&&
            (position_attaque_magique_x-1>0))))
        {
            // On test les position à gauche et à droite de l'attaque magique pour être sur
            int i=Recherche_Ennemis(position_attaque_magique_x,position_attaque_magique_y);
            if(i!=-1)
            {
                Jeu_Tab_Ennemis[i].Ennemis_Touche(Jeu_Heros.get_Intelligence());//prends degats de l'attaque magique
                Jeu_Heros.set_Recharge_Magique(0);
                position_attaque_magique_x=0;
                position_attaque_magique_y=0;
                if(Jeu_Tab_Ennemis[i].Ennemis_Mort())
                    {Supprime_Ennemis(i);}
            }
            else
            {
                i = Recherche_Ennemis(position_attaque_magique_x+1,position_attaque_magique_y);
                if(i!=-1)
                {
                    Jeu_Tab_Ennemis[i].Ennemis_Touche(Jeu_Heros.get_Intelligence());//prends degats de l'attaque magique
                    Jeu_Heros.set_Recharge_Magique(0);
                    position_attaque_magique_x=0;
                    position_attaque_magique_y=0;
                    if(Jeu_Tab_Ennemis[i].Ennemis_Mort())
                        {Supprime_Ennemis(i);}
                }
                else
                {
                    i = Recherche_Ennemis(position_attaque_magique_x-1,position_attaque_magique_y);
                    if(i!=-1)
                    {
                        Jeu_Tab_Ennemis[i].Ennemis_Touche(Jeu_Heros.get_Intelligence());//prends degats de l'attaque magique
                        Jeu_Heros.set_Recharge_Magique(0);
                        position_attaque_magique_x=0;
                        position_attaque_magique_y=0;
                        if(Jeu_Tab_Ennemis[i].Ennemis_Mort())
                            {Supprime_Ennemis(i);}

                    }
                    else if (orientation_attaque_magique=='d')
                            {position_attaque_magique_x+=1;}
                        else
                            {position_attaque_magique_x-=1;}
                }

            }

        }
        else
        {
            Jeu_Heros.set_Recharge_Magique(0);
            position_attaque_magique_x=0;
            position_attaque_magique_y=0;
        }

    }
    for(unsigned int i = 0; i<Jeu_Mini_Carte.get_Nombre_Ennemis(); i++)
    {
        if(Jeu_Tab_Ennemis[i].Heros_Visible_Par_Ennemis(Jeu_Heros.get_Position_X_Mini_Carte(),
                Jeu_Heros.get_Position_Y_Mini_Carte()))
        {
            vitesse_attaque-=1;
            if(vitesse_attaque == 0)
                {vitesse_attaque=2;

             if(Jeu_Tab_Ennemis[i].Toucher_Heros(Jeu_Tab_Ennemis[i].Attaque_Ennemis(Jeu_Mini_Carte),
                Jeu_Tab_Ennemis[i].get_Position_Y_Mini_Carte(),
                Jeu_Heros.get_Position_X_Mini_Carte(),Jeu_Heros.get_Position_Y_Mini_Carte()))
                {
                    if(Jeu_Heros.get_Point_De_Vie()>Jeu_Tab_Ennemis[i].get_Stats_Ennemis_Force())
                    {
                        Jeu_Heros.set_Point_De_Vie(Jeu_Heros.get_Point_De_Vie()-
                                                   Jeu_Tab_Ennemis[i].get_Stats_Ennemis_Force());
                        if (Jeu_Tab_Ennemis[i].get_Direction()=='g'){
                        Jeu_Heros.Deplace_Haut(Jeu_Mini_Carte);
                        Jeu_Heros.Deplace_Haut(Jeu_Mini_Carte);
                        Jeu_Heros.Deplace_Gauche(Jeu_Mini_Carte);
                        Jeu_Heros.Deplace_Gauche(Jeu_Mini_Carte);
                        }
                        else
                        {
                        Jeu_Heros.Deplace_Haut(Jeu_Mini_Carte);
                        Jeu_Heros.Deplace_Haut(Jeu_Mini_Carte);
                        Jeu_Heros.Deplace_Droite(Jeu_Mini_Carte);
                        Jeu_Heros.Deplace_Droite(Jeu_Mini_Carte);
                        }
                    }
                    else
                    {
                        Jeu_Heros.set_Point_De_Vie(0);
                        Recommence_Jeu();
                    }
                }
            }
        }
        else
            {Jeu_Tab_Ennemis[i].Deplacement_Ennemis_Script(Jeu_Mini_Carte) ;}
    }
}
void Jeu::Au_Bord()
{       //Passer sur la mini carte à gauche de l'actuel
    if(Jeu_Heros.get_Position_X_Mini_Carte()==0)
    {
        Jeu_Carte.set_Tab_Mini_Carte((Jeu_Heros.get_Position_X_Carte()-1)/2,
                                     (Jeu_Heros.get_Position_Y_Carte()-1)/2,
                                     Jeu_Mini_Carte) ; //Sauvegarde de la mini carte actuelle
        Jeu_Heros.set_Position_X_Carte(Jeu_Heros.get_Position_X_Carte()-2) ; //déplacement du héros sur la carte
        Jeu_Carte.get_Tab_Mini_Carte((Jeu_Heros.get_Position_X_Carte()-1)/2,
                                     (Jeu_Heros.get_Position_Y_Carte()-1)/2,
                                     Jeu_Mini_Carte) ; //Chargement de la nouvelle mini carte
        Recupe_Ennemis_Mini_Carte() ;
        Jeu_Heros.set_Position_X_Mini_Carte(Jeu_Mini_Carte.get_Taille_Mini_Carte_X()-2) ;
        Jeu_Heros.set_Position_Y_Mini_Carte(Jeu_Mini_Carte.get_Taille_Mini_Carte_Y()/2) ;
    }
    // Passer sur la mini carte à droite de l'actuel
    else if(Jeu_Heros.get_Position_X_Mini_Carte()==Jeu_Mini_Carte.get_Taille_Mini_Carte_X()-1)
        {
            Jeu_Carte.set_Tab_Mini_Carte((Jeu_Heros.get_Position_X_Carte()-1)/2,
                                         (Jeu_Heros.get_Position_Y_Carte()-1)/2,
                                         Jeu_Mini_Carte) ; //Sauvegarde de la mini carte actuelle
            Jeu_Heros.set_Position_X_Carte(Jeu_Heros.get_Position_X_Carte()+2) ; //déplacement du héros sur la carte
            Jeu_Carte.get_Tab_Mini_Carte((Jeu_Heros.get_Position_X_Carte()-1)/2,
                                         (Jeu_Heros.get_Position_Y_Carte()-1)/2,
                                         Jeu_Mini_Carte) ; //Chargement de la nouvelle mini carte
            Recupe_Ennemis_Mini_Carte() ;
            Jeu_Heros.set_Position_X_Mini_Carte(1) ;
            Jeu_Heros.set_Position_Y_Mini_Carte(Jeu_Mini_Carte.get_Taille_Mini_Carte_Y()/2) ;
        }
        // Passer sur la mini carte en haut de l'actuel
        else if(Jeu_Heros.get_Position_Y_Mini_Carte()==0)
            {
                Jeu_Carte.set_Tab_Mini_Carte((Jeu_Heros.get_Position_X_Carte()-1)/2,
                                             (Jeu_Heros.get_Position_Y_Carte()-1)/2,
                                             Jeu_Mini_Carte) ; //Sauvegarde de la mini carte actuelle
                Jeu_Heros.set_Position_Y_Carte(Jeu_Heros.get_Position_Y_Carte()-2);  //déplacement du héros sur la carte
                Jeu_Carte.get_Tab_Mini_Carte((Jeu_Heros.get_Position_X_Carte()-1)/2,
                                             (Jeu_Heros.get_Position_Y_Carte()-1)/2,
                                             Jeu_Mini_Carte) ; //Chargement de la nouvelle mini carte
                Recupe_Ennemis_Mini_Carte() ;
                Jeu_Heros.set_Position_X_Mini_Carte(Jeu_Mini_Carte.get_Taille_Mini_Carte_X()/2) ;
                Jeu_Heros.set_Position_Y_Mini_Carte(Jeu_Mini_Carte.get_Taille_Mini_Carte_Y()-1) ;
                Jeu_Heros.set_Moment_Saut(1) ;
            }
            // Passe sur la mini carte en bas de l'actuel
            else if(Jeu_Heros.get_Position_Y_Mini_Carte()==Jeu_Mini_Carte.get_Taille_Mini_Carte_Y()-1)
                {
                    Jeu_Carte.set_Tab_Mini_Carte((Jeu_Heros.get_Position_X_Carte()-1)/2,
                                                 (Jeu_Heros.get_Position_Y_Carte()-1)/2,
                                                 Jeu_Mini_Carte) ; //Sauvegarde de la mini carte actuelle
                    Jeu_Heros.set_Position_Y_Carte(Jeu_Heros.get_Position_Y_Carte()+2) ; //déplacement du héros sur la carte
                    Jeu_Carte.get_Tab_Mini_Carte((Jeu_Heros.get_Position_X_Carte()-1)/2,
                                                 (Jeu_Heros.get_Position_Y_Carte()-1)/2,
                                                 Jeu_Mini_Carte) ; //Chargement de la nouvelle mini carte
                    Recupe_Ennemis_Mini_Carte() ;
                    Jeu_Heros.set_Position_X_Mini_Carte(Jeu_Mini_Carte.get_Taille_Mini_Carte_X()/2) ;
                    Jeu_Heros.set_Position_Y_Mini_Carte(0) ;
                }
}

void Jeu::set_Jeu_Mini_Carte(Mini_Carte & mc)
{
    Jeu_Mini_Carte.set_Mini_Carte(mc) ;
}

void Jeu::Desaloc_Jeu()
{
    Jeu_Mini_Carte.Desaloc_Tab();
    Jeu_Carte.Desaloc_Carte();
    Desaloc_Jeu_Tab_Ennemis() ;
}

void Jeu::Desaloc_Jeu_Tab_Ennemis()
{
    if(!Jeu_Tab_Ennemis==NULL)
    {
        delete [] Jeu_Tab_Ennemis ;
        Jeu_Tab_Ennemis = 0 ;
    }
}

void Jeu::Recommence_Jeu()
{
    Desaloc_Jeu() ;
    Labyrinthe() ;
}

void Jeu::Debut_Partie()
{
    /* Jeu_Carte.Creer_Carte_Complet(15,7) ;
    Mini_Carte mc("data/core/Mini_map/mini_map_hall") ;
    Jeu_Mini_Carte.set_Mini_Carte(mc) ;
    Jeu_Heros.set_Position_X_Carte(1);
    Jeu_Heros.set_Position_Y_Carte(1);
    Jeu_Heros.set_Position_X_Mini_Carte(2) ;
    Jeu_Heros.set_Position_Y_Mini_Carte(Jeu_Mini_Carte.get_Taille_Mini_Carte_Y()-3) ;
    Jeu_Heros.set_Point_De_Vie_Max(100);
    Jeu_Heros.set_Point_De_Vie(100); */
}


void Jeu::Labyrinthe()
{
    // On crée la carte et pose le héros dessus
    Jeu_Carte.Creer_Carte_Complet(15,7) ;
    Jeu_Heros.set_Position_X_Carte(1);
    Jeu_Heros.set_Position_Y_Carte(Jeu_Carte.get_Carte_Debut()) ;
    // On pose le héros sur la minicarte
    Jeu_Carte.get_Tab_Mini_Carte(Jeu_Heros.get_Position_X_Carte()-1,
                                 (Jeu_Heros.get_Position_Y_Carte())/2,Jeu_Mini_Carte) ;
    Jeu_Heros.set_Position_X_Mini_Carte(2) ;
    Jeu_Heros.set_Position_Y_Mini_Carte(Jeu_Mini_Carte.get_Taille_Mini_Carte_Y()-3) ;
    // On met des stats au héros (Doit être enlevé dés que le chargement de jeu est bon !!!)
    Jeu_Heros.set_Mana_Max(1000);
    Jeu_Heros.set_Mana(1000);
    Jeu_Heros.set_Point_De_Vie_Max(100);
    Jeu_Heros.set_Point_De_Vie(100);
    Jeu_Heros.set_Force(50);
    Jeu_Heros.set_Intelligence(50);

    //On s'occupe des ennemis
    Recupe_Ennemis_Mini_Carte() ;
}

void Jeu::Recupe_Ennemis_Mini_Carte()
{
    Desaloc_Jeu_Tab_Ennemis() ;
    unsigned int nb_ennemis = Jeu_Mini_Carte.get_Nombre_Ennemis() ;
    unsigned int nb_ennemis_init = 0 ;
    Jeu_Tab_Ennemis = new Ennemis [nb_ennemis] ;
    for(unsigned int i=0; i<Jeu_Mini_Carte.get_Taille_Mini_Carte_Y();i++)
    {
        for(unsigned int j=0; j<Jeu_Mini_Carte.get_Taille_Mini_Carte_X();j++)
        {

            if(Jeu_Mini_Carte.get_Tab_Mini_Carte(j,i)==9)
            {
                Jeu_Tab_Ennemis[nb_ennemis_init].set_Ennemis("data/core/Ennemis/faible.txt") ;
                Jeu_Tab_Ennemis[nb_ennemis_init].set_Position_X_Mini_Carte(j) ;
                Jeu_Tab_Ennemis[nb_ennemis_init].set_Position_Y_Mini_Carte(i) ;
                nb_ennemis_init++ ;
            }
        }
    }
}

int Jeu::Recherche_Ennemis(unsigned int Position_X, unsigned int Position_Y)
{
    for(unsigned int i = 0 ; i < Jeu_Mini_Carte.get_Nombre_Ennemis() ; i++)
    {
        if((Position_X == Jeu_Tab_Ennemis[i].get_Position_X_Mini_Carte()) && (Position_Y == Jeu_Tab_Ennemis[i].get_Position_Y_Mini_Carte()))
        {
            return i;
        }
    }
    return -1;
}

void Jeu::Supprime_Ennemis(unsigned int i)
{
    unsigned int j,k,compteur = 0;
    for (j=i;j<Jeu_Mini_Carte.get_Nombre_Ennemis()-1;j++)
    {
        Jeu_Tab_Ennemis[j]=Jeu_Tab_Ennemis[j+1];
    }
    Jeu_Mini_Carte.set_Nombre_Ennemis(Jeu_Mini_Carte.get_Nombre_Ennemis()-1) ;

    for(k=0; k<Jeu_Mini_Carte.get_Taille_Mini_Carte_Y();k++)
    {
        for(j=0; j<Jeu_Mini_Carte.get_Taille_Mini_Carte_X();j++)
        {
            if(Jeu_Mini_Carte.get_Tab_Mini_Carte(j,k)==9)
            {
                if (compteur == i)
                {
                    Jeu_Mini_Carte.set_Tab_Mini_Carte(j,k,1) ;
                }
                compteur ++ ;
            }
        }
    }
}


void Jeu::Lance_Mini_Jeux(){


}


void Jeu::Mini_Jeux_Bouger(char deplacement){
    Jeu_Mini_Jeux.Bouger(deplacement);
}

bool Jeu::Mini_Jeux_Action_Auto_Apres_Bouger(unsigned int k){
    Jeu_Mini_Jeux.Tombe(k);
}

void Jeu::Mini_Jeux_Action_Auto_Avant_Bouger(unsigned int j,unsigned int a){
    Jeu_Mini_Jeux.set_Tab(j,0,a);
}
void Jeu::Mini_Jeux_Reinitialiser(){
    unsigned int i,j;
    for (i=0;i<Taille;i++){
        for (j=0;j<Taille;j++){
            Jeu_Mini_Jeux.set_Tab(j,i,0);
                             }
                        }
    for (i=1;i<Taille;i++){
        for (j=1;j<Taille;j++){
            Jeu_Mini_Jeux.set_Tab(j,i,0);
                             }
                        }
    for (i=0;i<Taille-1;i++){
        j=0;
        Jeu_Mini_Jeux.set_Tab(j,i,1);
        j=Taille-1;
        Jeu_Mini_Jeux.set_Tab(Taille-1,i,1);
            }
        i=Taille-1;
        for (unsigned int j=0;j<Taille;j++){
            Jeu_Mini_Jeux.set_Tab(j,i,1);
                }
        Jeu_Mini_Jeux.set_Position_X(5);
        Jeu_Mini_Jeux.set_Position_Y(Taille-2);
}

void Jeu::Modifie_Stats_heros(unsigned int pourcentage){
    pourcentage=pourcentage/100;
    Jeu_Heros.set_Point_De_Vie_Max(Jeu_Heros.get_Point_De_Vie_Max()+pourcentage*Jeu_Heros.get_Point_De_Vie_Max());
    Jeu_Heros.set_Point_De_Vie(Jeu_Heros.get_Point_De_Vie()+pourcentage*Jeu_Heros.get_Point_De_Vie());
    Jeu_Heros.set_Point_De_Vie(Jeu_Heros.get_Point_De_Vie_Max());// si le heros a ete blesser avant le lancement du mini jeux il est guerri
    Jeu_Heros.set_Mana_Max(Jeu_Heros.get_Mana_Max()+pourcentage*Jeu_Heros.get_Mana_Max());
    Jeu_Heros.set_Mana(Jeu_Heros.get_Mana()+pourcentage*Jeu_Heros.get_Mana());
    Jeu_Heros.set_Mana(Jeu_Heros.get_Mana_Max());
    Jeu_Heros.set_Force(Jeu_Heros.get_Force()+pourcentage*Jeu_Heros.get_Force());
    Jeu_Heros.set_Intelligence(Jeu_Heros.get_Intelligence()+pourcentage*Jeu_Heros.get_Intelligence());
    Jeu_Heros.set_Agilite(Jeu_Heros.get_Agilite()+pourcentage*Jeu_Heros.get_Agilite());
}
bool Jeu::Active_Mini_Jeux(){
    bool test=Jeu_Carte.Est_Ce_Que_Zone_Remarquable(Jeu_Heros.get_Position_X_Carte(),Jeu_Heros.get_Position_Y_Carte());
    return test;
}

