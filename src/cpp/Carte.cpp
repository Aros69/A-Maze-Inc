#include <Carte.h>

// Nombre de Mini_Carte crée
const int nb_minicarte = 4 ;

Carte::Carte()
{
    Tab_Carte = NULL ;
    Tab_Mini_Carte = NULL ;
}

Carte::Carte(unsigned int nbX, unsigned int nbY)
{
    unsigned int i, j ;
    assert(nbX>=3) ;
    assert(nbY>=3) ;
    Nombre_Mini_Carte_X = nbX ;
    Nombre_Mini_Carte_Y = nbY ;
    Taille_Carte_X = 1+Nombre_Mini_Carte_X*2 ;
    Taille_Carte_Y = 1+Nombre_Mini_Carte_Y*2 ;
    Tab_Carte = new unsigned int [Taille_Carte_Y*Taille_Carte_X] ;
    for (i=0; i<(Taille_Carte_X); i++)
    {
        for(j=0; j<(Taille_Carte_Y); j++)
        {
            if(i==0||i==Taille_Carte_X-1||j==0||j==Taille_Carte_Y-1)
            {
                set_Tab_Carte(i,j,0) ;
            }
            else
            {
                set_Tab_Carte(i,j,9) ;
            }
        }
    }
    Tab_Mini_Carte = new Mini_Carte [Nombre_Mini_Carte_X*Nombre_Mini_Carte_Y] ;
}

Carte::~Carte()
{
    delete [] Tab_Carte ;
    Tab_Carte = NULL ;
    delete [] Tab_Mini_Carte ;
    Tab_Mini_Carte = NULL ;
}

unsigned int Carte::get_Tab_Carte(unsigned int x, unsigned int y) const
{
    assert(x>=0) ;
    assert(y>=0) ;
    assert(x<Taille_Carte_X) ;
    assert(y<Taille_Carte_Y) ;
    return Tab_Carte[x*(Taille_Carte_Y)+y] ;
}

void Carte::set_Tab_Carte(unsigned int x, unsigned int y, unsigned int entier_a_rajouter)
{
    assert(x>=0) ;
    assert(y>=0) ;
    assert(x<Taille_Carte_X) ;
    assert(y<Taille_Carte_Y) ;
    Tab_Carte[x*(Taille_Carte_Y)+y] = entier_a_rajouter ;
}

void Carte::get_Tab_Mini_Carte(unsigned int x, unsigned int y, class Mini_Carte & mc)
{
    mc.set_Mini_Carte(Tab_Mini_Carte[x*(Nombre_Mini_Carte_Y)+y]) ;
}

void Carte::set_Tab_Mini_Carte(unsigned int x, unsigned int y, const class Mini_Carte & mc)
{
    Tab_Mini_Carte[x*(Nombre_Mini_Carte_Y)+y].set_Mini_Carte(mc) ;
}

unsigned int Carte::get_Taille_Carte_X() const
{
    return Taille_Carte_X ;
}

unsigned int Carte::get_Taille_Carte_Y() const
{
    return Taille_Carte_Y ;
}

unsigned int Carte::get_Nombre_Mini_Carte_X () const
{
    return Nombre_Mini_Carte_X ;
}

unsigned int Carte::get_Nombre_Mini_Carte_Y () const
{
    return Nombre_Mini_Carte_Y ;
}

unsigned int Carte::get_Carte_Debut()
{
    return Carte_Debut ;
}

void Carte::Affiche_Carte()
{
    unsigned int i,j ;
    for (i=0; i<(Taille_Carte_Y); i++)
    {
        for (j=0; j<(Taille_Carte_X); j++)
        {
            cout << get_Tab_Carte(j,i) ;
        }
        cout << endl ;
    }
    cout << endl ;
}

void Carte::Affiche_Chemin()
{
    unsigned int i,j ;
    unsigned int entier_recup ;
    for (i=0; i<(Taille_Carte_Y); i++)
    {
        for (j=0; j<(Taille_Carte_X); j++)
        {
            entier_recup = get_Tab_Carte(j,i) ;
            if (entier_recup != 0)
            {
                cout << entier_recup ;
            }
            else
            {
                cout << " " ;
            }
        }
        cout << endl ;
    }
    cout << endl ;
}

void Carte::Affiche_Mur()
{
    unsigned int i,j ;
    unsigned int entier_recup ;
    for (i=0; i<(Taille_Carte_Y); i++)
    {
        for (j=0; j<(Taille_Carte_X); j++)
        {
            entier_recup = get_Tab_Carte(j,i) ;
            if (entier_recup == 0)
            {
                cout << entier_recup ;
            }
            else
            {
                cout << " " ;
            }
        }
        cout << endl ;
    }
    cout << endl ;
}

void Carte::Affiche_Mini_Carte(unsigned int x, unsigned int y)
{
    Tab_Mini_Carte[x*(Nombre_Mini_Carte_Y)+y].Affiche_Non_Vide() ;
}

void Carte::Creer_Carte()
{
    unsigned int i;
    srand(time(NULL)) ;
    Creer_Carte_Bordure() ;
    Creer_Carte_Milieu() ;

    Carte_Debut = ((rand()%(Nombre_Mini_Carte_Y-2))*2+1)+2 ;
    set_Tab_Carte(0, Carte_Debut, 1) ; //Pose de la zone de départ
    set_Tab_Carte(1, Carte_Debut-1, 0) ; //et de la mini map "couloir" de départ
    set_Tab_Carte(1, Carte_Debut+1, 0) ;
    set_Tab_Carte(1, Carte_Debut, 1) ;
    set_Tab_Carte(2, Carte_Debut, 1) ;
    for (i=2; i<=(Nombre_Mini_Carte_Y/2)+2; i++) // On s'assure de ne pas être bloqué au début
    {
            set_Tab_Carte(i*2, Carte_Debut, 1) ;
    }
    for (i=0;i<10;i++)
    {
        do //Eviter une zones remarquables sur celle de départ
        {
            Carte_Zone_Remarquable[i][0] = rand()%Nombre_Mini_Carte_X ;
            Carte_Zone_Remarquable[i][1] = rand()%Nombre_Mini_Carte_Y ;
        }
        while ((Carte_Zone_Remarquable[i][0]==Carte_Debut-1)&&(Carte_Zone_Remarquable[i][1]==1)) ;
        set_Tab_Carte(1+(Carte_Zone_Remarquable[i][0])*2,1+(Carte_Zone_Remarquable[i][1])*2,8) ;
    } // Pose de zones importantes
}

void Carte::Creer_Carte_Complet(unsigned int x, unsigned int y)
{
   unsigned int i, j ;
    assert(x>=3) ;
    assert(y>=3) ;
    Nombre_Mini_Carte_X = x ;
    Nombre_Mini_Carte_Y = y ;
    Taille_Carte_X = 1+Nombre_Mini_Carte_X*2 ;
    Taille_Carte_Y = 1+Nombre_Mini_Carte_Y*2 ;
    if (Tab_Carte != NULL)
    {
        delete [] Tab_Carte ;
        Tab_Carte = NULL ;
    }
    Tab_Carte = new unsigned int [Taille_Carte_Y*Taille_Carte_X] ;
    for (i=0; i<(Taille_Carte_X); i++)
    {
        for(j=0; j<(Taille_Carte_Y); j++)
        {
            if(i==0||i==Taille_Carte_X-1||j==0||j==Taille_Carte_Y-1)
            {
                set_Tab_Carte(i,j,0) ;
            }
            else
            {
                set_Tab_Carte(i,j,9) ;
            }
        }
    }
    if (Tab_Mini_Carte != NULL)
    {
        delete [] Tab_Mini_Carte ;
        Tab_Mini_Carte = NULL ;
    }
    Tab_Mini_Carte = new Mini_Carte [Nombre_Mini_Carte_X*Nombre_Mini_Carte_Y] ;
    Creer_Carte() ;
    Poser_Mini_Carte() ;
}

void Carte::Creer_Carte_Bordure()
{
    unsigned int i ;
    unsigned int Sortie_Ou_Pas ;
    unsigned int nbSortie ;

    set_Tab_Carte(1,1,1) ;
    set_Tab_Carte(1,Taille_Carte_Y-2,1) ;
    set_Tab_Carte(Taille_Carte_X-2,1,1) ;
    set_Tab_Carte(Taille_Carte_X-2,Taille_Carte_Y-2,1) ;

    // Pose des sorties des angles de la carte
    Sortie_Ou_Pas = get_Tab_Carte(2,1) ; //Angle haut gauche
    if (Sortie_Ou_Pas==9)
    {
        Sortie_Ou_Pas = rand()%2 ;
        set_Tab_Carte(2,1,Sortie_Ou_Pas) ;
    }
    if (Sortie_Ou_Pas == 0)
        { set_Tab_Carte(1,2,1) ; }
    else
        { set_Tab_Carte(1,2,rand()%2) ; }

    Sortie_Ou_Pas = get_Tab_Carte(1,Taille_Carte_Y-3) ; //Angle haut droit
    if (Sortie_Ou_Pas==9)
    {
        Sortie_Ou_Pas = rand()%2 ;
        set_Tab_Carte(1,Taille_Carte_Y-3,Sortie_Ou_Pas) ;
    }
    if (Sortie_Ou_Pas == 0)
        { set_Tab_Carte(2,Taille_Carte_Y-2,1) ; }
    else
        { set_Tab_Carte(2,Taille_Carte_Y-2,rand()%2) ; }

    Sortie_Ou_Pas = rand()%2 ; //Angle bas droit
    set_Tab_Carte(Taille_Carte_X-3,Taille_Carte_Y-2,Sortie_Ou_Pas) ;
    if (Sortie_Ou_Pas == 0)
        { set_Tab_Carte(Taille_Carte_X-2,Taille_Carte_Y-3,1) ; }
    else
        { set_Tab_Carte(Taille_Carte_X-2,Taille_Carte_Y-3,rand()%2) ; }

    Sortie_Ou_Pas = rand()%2 ; //Angle bas gauche
    set_Tab_Carte(Taille_Carte_X-3,1,Sortie_Ou_Pas) ;
    if (Sortie_Ou_Pas == 0)
        { set_Tab_Carte(Taille_Carte_X-2,2,1) ; }
    else
        { set_Tab_Carte(Taille_Carte_X-2,2,rand()%2) ; }

    // Pose des sortie des bords de la carte
    for (i=3; i<Taille_Carte_X-3; i+=2)
    {
        //Pose du bord gauche de la carte a la hauteur i de la carte
        nbSortie = 0 ;
        set_Tab_Carte(i,1,1) ;

        Sortie_Ou_Pas = get_Tab_Carte(i-1,1) ;
        if (Sortie_Ou_Pas == 9)
        {
            Sortie_Ou_Pas = rand()%2 ;
            set_Tab_Carte(i-1,1,Sortie_Ou_Pas) ;
        }
        nbSortie+=Sortie_Ou_Pas ;

        Sortie_Ou_Pas = get_Tab_Carte(i+1,1) ;
        if (Sortie_Ou_Pas == 9)
        {
            Sortie_Ou_Pas = rand()%2 ;
            set_Tab_Carte(i+1,1,Sortie_Ou_Pas) ;
        }
        nbSortie+=Sortie_Ou_Pas ;
        set_Tab_Carte(i,2,1); // On ouvre systematiquement vers le centre du donjon

        //Pose du bord droit de la carte a la hauteur i de la carte
        nbSortie = 0 ;
        set_Tab_Carte(i,Taille_Carte_Y-2,1) ;

        Sortie_Ou_Pas = get_Tab_Carte(i-1,Taille_Carte_Y-2) ;
        if (Sortie_Ou_Pas == 9)
        {
            Sortie_Ou_Pas = rand()%2 ;
            set_Tab_Carte(i-1,Taille_Carte_Y-2,Sortie_Ou_Pas) ;
        }
        nbSortie+=Sortie_Ou_Pas ;

        Sortie_Ou_Pas = get_Tab_Carte(i+1,Taille_Carte_Y-2) ;
        if (Sortie_Ou_Pas == 9)
        {
            Sortie_Ou_Pas = rand()%2 ;
            set_Tab_Carte(i+1,Taille_Carte_Y-2,Sortie_Ou_Pas) ;
        }
        nbSortie+=Sortie_Ou_Pas ;
        set_Tab_Carte(i,Taille_Carte_Y-3,1); // On ouvre systematiquement vers le centre du donjon

    }

    for (i=3; i<Taille_Carte_Y-3; i+=2)
    {
        //Pose du bord haut de la carte a la longueur i de la carte
        nbSortie = 0 ;
        set_Tab_Carte(1,i,1) ;

        Sortie_Ou_Pas = get_Tab_Carte(1,i-1) ;
        if (Sortie_Ou_Pas == 9)
        {
            Sortie_Ou_Pas = rand()%2 ;
            set_Tab_Carte(1,i-1,Sortie_Ou_Pas) ;
        }
        nbSortie+=Sortie_Ou_Pas ;

        Sortie_Ou_Pas = get_Tab_Carte(1,i+1) ;
        if (Sortie_Ou_Pas == 9)
        {
            Sortie_Ou_Pas = rand()%2 ;
            set_Tab_Carte(1,i+1,Sortie_Ou_Pas) ;
        }
        nbSortie+=Sortie_Ou_Pas ;
        set_Tab_Carte(2,i,1) ;// On ouvre systematiquement vers le centre du donjon

        //Pose du bord bas de la carte a la longueur i de la carte
        nbSortie = 0 ;
        set_Tab_Carte(Taille_Carte_X-2,i,1) ;

        Sortie_Ou_Pas = get_Tab_Carte(Taille_Carte_X-2,i-1) ;
        if (Sortie_Ou_Pas == 9)
        {
            Sortie_Ou_Pas = rand()%2 ;
            set_Tab_Carte(Taille_Carte_X-2,i-1,Sortie_Ou_Pas) ;
        }
        nbSortie+=Sortie_Ou_Pas ;

        Sortie_Ou_Pas = get_Tab_Carte(Taille_Carte_X-2,i+1) ;
        if (Sortie_Ou_Pas == 9)
        {
            Sortie_Ou_Pas = rand()%2 ;
            set_Tab_Carte(Taille_Carte_X-2,i+1,Sortie_Ou_Pas) ;
        }
        nbSortie+=Sortie_Ou_Pas ;
        set_Tab_Carte(Taille_Carte_X-3,i,1) ; // On ouvre systematiquement vers le centre du donjon
    }
}

void Carte::Creer_Carte_Milieu()
{
    unsigned int i,j ;
    unsigned int Sortie_Ou_Pas ;
    unsigned int nbSortie ;

    for (i=3; i<Taille_Carte_X-3; i+=2)
    {
        for (j=3; j<Taille_Carte_Y-3;j+=2)
        {
                nbSortie = 0 ;
                set_Tab_Carte(i-1,j-1,0) ; // Création des 4 angles des minicartes
                set_Tab_Carte(i+1,j-1,0) ;
                set_Tab_Carte(i-1,j+1,0) ;
                set_Tab_Carte(i+1,j+1,0) ;
                set_Tab_Carte(i,j,1) ;

                Sortie_Ou_Pas = get_Tab_Carte(i-1,j) ; // Création de l'entrée/sortie du haut
                if (Sortie_Ou_Pas == 9)
                {
                    Sortie_Ou_Pas = rand()%2 ;
                    set_Tab_Carte(i-1,j,Sortie_Ou_Pas) ;
                }
                nbSortie+=Sortie_Ou_Pas ;

                Sortie_Ou_Pas = get_Tab_Carte(i+1,j) ; // Création de l'entrée/sortie du bas
                if (Sortie_Ou_Pas == 9)
                {
                    Sortie_Ou_Pas = rand()%2 ;
                    set_Tab_Carte(i+1,j,Sortie_Ou_Pas) ;
                }
                nbSortie+=Sortie_Ou_Pas ;

                Sortie_Ou_Pas = get_Tab_Carte(i,j-1) ; // Création de l'entrée/sortie de gauche
                if (Sortie_Ou_Pas == 9)
                {
                    Sortie_Ou_Pas = rand()%2 ;
                    set_Tab_Carte(i,j-1,Sortie_Ou_Pas) ;
                }
                nbSortie+=Sortie_Ou_Pas ;

                Sortie_Ou_Pas = get_Tab_Carte(i,j+1) ; // Création de l'entrée/sortie de droite
                if (Sortie_Ou_Pas == 9)
                {
                    Sortie_Ou_Pas = rand()%2 ;
                    set_Tab_Carte(i,j+1,Sortie_Ou_Pas) ;
                }
                nbSortie+=Sortie_Ou_Pas ;

                if (nbSortie<2) //Si il y a au milieu des cases avec une seul sortie/entrée, alors on ouvre tout les cotés
                {
                    set_Tab_Carte(i,j+1,1) ;
                    set_Tab_Carte(i,j-1,1) ;
                    set_Tab_Carte(i+1,j,1) ;
                    set_Tab_Carte(i-1,j,1) ;
                }
        }
    }
}

#ifdef _WIN32
string to_string(unsigned int i)
        {
            char tx[128];
            sprintf(tx,"%d", i);
            return string(tx);
        }
#endif // WIN32

void Carte::Poser_Mini_Carte()
{
    unsigned int i,j, hasard ;
    unsigned int taille_mini_carte_x, taille_mini_carte_y ;
    unsigned int position_mini_carte ;
    Mini_Carte mini_carte;
    string Nom_Mini_Carte = "data/core/Mini_map/mini_map_" ;
    for (i=0; i<Nombre_Mini_Carte_X; i++)
    {
        for (j=0; j<Nombre_Mini_Carte_Y; j++)
        {
            if(((i==0)&&(j==(Carte_Debut)/2)))
            {
                mini_carte.Ouvrir_Mini_Carte(Nom_Mini_Carte+"depart");
                set_Tab_Mini_Carte(i,j,mini_carte) ;
                position_mini_carte = i*(Nombre_Mini_Carte_Y)+j ;
                taille_mini_carte_x = Tab_Mini_Carte[position_mini_carte].get_Taille_Mini_Carte_X() ;
                taille_mini_carte_y = Tab_Mini_Carte[position_mini_carte].get_Taille_Mini_Carte_Y() ;
            }
            else
            {
                hasard = rand()%(nb_minicarte) +1 ;

                mini_carte.Ouvrir_Mini_Carte(Nom_Mini_Carte + to_string(hasard)) ;
                set_Tab_Mini_Carte(i,j,mini_carte) ;
                position_mini_carte = i*(Nombre_Mini_Carte_Y)+j ;
                taille_mini_carte_x = Tab_Mini_Carte[position_mini_carte].get_Taille_Mini_Carte_X() ;
                taille_mini_carte_y = Tab_Mini_Carte[position_mini_carte].get_Taille_Mini_Carte_Y() ;

                if (get_Tab_Carte(2*i+1,2*j)==0) // Fermeture de la sortie haute de la mini carte si necessaire
                {
                    Tab_Mini_Carte[position_mini_carte].set_Tab_Mini_Carte((taille_mini_carte_x/2)-1,0,0) ;
                    Tab_Mini_Carte[position_mini_carte].set_Tab_Mini_Carte(taille_mini_carte_x/2,0,0) ;
                    Tab_Mini_Carte[position_mini_carte].set_Tab_Mini_Carte((taille_mini_carte_x/2)-1,1,0) ;
                    Tab_Mini_Carte[position_mini_carte].set_Tab_Mini_Carte(taille_mini_carte_x/2,1,0) ;
                }

                if (get_Tab_Carte(2*i+1,2*j+2)==0) // Fermeture de la sortie basse de la mini carte si necessaire
                {
                    Tab_Mini_Carte[position_mini_carte].set_Tab_Mini_Carte((taille_mini_carte_x/2)-1,taille_mini_carte_y-1,0) ;
                    Tab_Mini_Carte[position_mini_carte].set_Tab_Mini_Carte(taille_mini_carte_x/2,taille_mini_carte_y-1,0) ;
                    Tab_Mini_Carte[position_mini_carte].set_Tab_Mini_Carte((taille_mini_carte_x/2)-1,taille_mini_carte_y-2,0) ;
                    Tab_Mini_Carte[position_mini_carte].set_Tab_Mini_Carte(taille_mini_carte_x/2,taille_mini_carte_y-2,0) ;
                }

                if (get_Tab_Carte(2*i,2*j+1)==0) // Fermeture de la sortie gauche de la mini carte si necessaire
                {
                    Tab_Mini_Carte[position_mini_carte].set_Tab_Mini_Carte(0,(taille_mini_carte_y/2)-1,0) ;
                    Tab_Mini_Carte[position_mini_carte].set_Tab_Mini_Carte(0,taille_mini_carte_y/2,0) ;
                    Tab_Mini_Carte[position_mini_carte].set_Tab_Mini_Carte(1,(taille_mini_carte_y/2)-1,0) ;
                    Tab_Mini_Carte[position_mini_carte].set_Tab_Mini_Carte(1,taille_mini_carte_y/2,0) ;
                }

                if (get_Tab_Carte(2*i+2,2*j+1)==0) // Fermeture de la sortie droite de la mini carte si necessaire
                {
                    Tab_Mini_Carte[position_mini_carte].set_Tab_Mini_Carte(taille_mini_carte_x-1,(taille_mini_carte_y/2)-1,0) ;
                    Tab_Mini_Carte[position_mini_carte].set_Tab_Mini_Carte(taille_mini_carte_x-1,taille_mini_carte_y/2,0) ;
                    Tab_Mini_Carte[position_mini_carte].set_Tab_Mini_Carte(taille_mini_carte_x-2,(taille_mini_carte_y/2)-1,0) ;
                    Tab_Mini_Carte[position_mini_carte].set_Tab_Mini_Carte(taille_mini_carte_x-2,taille_mini_carte_y/2,0) ;
                }
            }
        }
    }
}

void Carte::Test_Regression()
{
    cout << "======   Début du test de regression    ======" << endl << endl ;
    cout << "======     Appel des constructeurs      ======" << endl ;

    Carte carte_vide ;
    cout << "Une carte vide n'étant pas intéréssante dans le jeu, celle ci ne sera" <<
        " utile que pour créer un jeu sur un carte déja déclarée." << endl ;
    Carte carte_init(5,5) ;

    cout << "====== Affichage de la carte initialisé ======" << endl ;

    carte_init.Affiche_Carte() ;

    cout << "======    Utilisation des get et set    ======" << endl ;

    carte_init.set_Tab_Carte(1,1,1) ;
    carte_init.Affiche_Chemin() ;
    cout << "L'entier en 2,2 est : " << carte_init.get_Tab_Carte(2,2) << "." << endl ;
    cout << "La carte fait " << carte_init.get_Taille_Carte_X() << " pixel de long et " <<
            carte_init.get_Taille_Carte_Y() << " pixel de haut." << endl ;

    cout << "======   Création d'une carte de jeu    ======" << endl ;

    carte_vide.Creer_Carte_Complet(10,8) ;
    carte_init.Creer_Carte() ;
    carte_init.Poser_Mini_Carte() ;
    cout << "A partir d'une carte vide : " << endl ;
    carte_vide.Affiche_Mur() ;
    cout << "A partir d'un carte déja initialisée" << endl;
    carte_vide.Affiche_Mur() ;

    cout << "===== Affichage d'une Mini Carte du jeu ======" << endl ;

    carte_init.Affiche_Mini_Carte(2,2) ;

    cout << "======    Fin du test de regression     ======" << endl ;
}

void Carte::Desaloc_Carte()
{
    delete [] Tab_Carte ;
    Tab_Carte = NULL ;
    Nombre_Mini_Carte_X=0 ;
    Nombre_Mini_Carte_Y=0 ;
    Carte_Debut=0 ;
    delete [] Tab_Mini_Carte ;
    Tab_Mini_Carte = NULL ;
}

bool  Carte::Est_Ce_Que_Zone_Remarquable(unsigned int x,unsigned int y)
{
    for (unsigned int i=0;i<10;i++){
        if ((Carte_Zone_Remarquable[i][0]==x)&&(Carte_Zone_Remarquable[i][1]=y))
            return true;
    }
    return false;
}
