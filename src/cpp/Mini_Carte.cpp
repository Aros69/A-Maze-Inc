#include <Mini_Carte.h>

Mini_Carte::Mini_Carte()
{
    Tab_Mini_Carte = NULL ;
}

Mini_Carte::Mini_Carte(string Nom_Fich)
{
    unsigned int i, j, nouveau_entier ;
    Nom_Fichier = Nom_Fich ;
    ifstream fichier(Nom_Fichier.c_str()) ;
    assert(fichier.is_open()) ;
    fichier >> Taille_Mini_Carte_X >> Taille_Mini_Carte_Y >> Nombre_Ennemis ;
    assert(Taille_Mini_Carte_X > 0) ;
    assert(Taille_Mini_Carte_Y > 0) ;
    Tab_Mini_Carte = new unsigned int [Taille_Mini_Carte_X*Taille_Mini_Carte_Y] ;
    for (i=0; i<(Taille_Mini_Carte_Y); i++)
    {
        for(j=0; j<(Taille_Mini_Carte_X); j++)
        {
            fichier >> nouveau_entier ;
            set_Tab_Mini_Carte(j,i,nouveau_entier) ;
        }
    }
    fichier.close() ;
    assert(!fichier.is_open()) ;
}

Mini_Carte::~Mini_Carte()
{
    delete [] Tab_Mini_Carte ;
    Tab_Mini_Carte = NULL ;
}

void Mini_Carte::Desaloc_Tab()
{
    delete [] Tab_Mini_Carte ;
    Tab_Mini_Carte = NULL ;
}

void Mini_Carte::Alloc_Tab(unsigned int x, unsigned int y)
{
    if (Tab_Mini_Carte != NULL)
    {
        Desaloc_Tab() ;
    }
    Taille_Mini_Carte_X = x ;
    Taille_Mini_Carte_Y = y ;
    Tab_Mini_Carte = new unsigned int [x*y] ;
}

void Mini_Carte::Ouvrir_Mini_Carte(string nom_fichier)
{
    unsigned int i,j, nouveau_entier ;
    unsigned int taille_mini_carte_x, taille_mini_carte_y, nb_ennemis ;
    set_Nom_Fichier(nom_fichier) ;
    ifstream fichier(Nom_Fichier.c_str()) ;
    assert(fichier.is_open()) ;
    fichier >> taille_mini_carte_x >> taille_mini_carte_y >> nb_ennemis ;
    set_Taille_Mini_Carte_X(taille_mini_carte_x) ;
    set_Taille_Mini_Carte_Y(taille_mini_carte_y) ;
    set_Nombre_Ennemis(nb_ennemis) ;
    assert(Taille_Mini_Carte_X > 0) ;
    assert(Taille_Mini_Carte_Y > 0) ;
    Alloc_Tab(Taille_Mini_Carte_X, Taille_Mini_Carte_Y) ;
    for (i=0; i<(Taille_Mini_Carte_Y); i++)
    {
        for(j=0; j<(Taille_Mini_Carte_X); j++)
        {
            fichier >> nouveau_entier ;
            set_Tab_Mini_Carte(j,i,nouveau_entier) ;
        }
    }
    fichier.close() ;
    assert(!fichier.is_open()) ;
}

unsigned int Mini_Carte::get_Tab_Mini_Carte(unsigned int x, unsigned int y) const
{
    assert(x>=0) ;
    assert(y>=0) ;
    assert(x<Taille_Mini_Carte_X) ;
    assert(y<Taille_Mini_Carte_Y) ;
    return Tab_Mini_Carte[x*(Taille_Mini_Carte_Y)+y] ;
}

void Mini_Carte::set_Tab_Mini_Carte(unsigned int x, unsigned int y, unsigned int entier_a_rajouter)
{
    assert(x>=0) ;
    assert(y>=0) ;
    assert(x<Taille_Mini_Carte_X) ;
    assert(y<Taille_Mini_Carte_Y) ;
    Tab_Mini_Carte[x*(Taille_Mini_Carte_Y)+y] = entier_a_rajouter ;
}

unsigned int Mini_Carte::get_Taille_Mini_Carte_X() const
{
    return Taille_Mini_Carte_X ;
}

unsigned int Mini_Carte::get_Taille_Mini_Carte_Y() const
{
    return Taille_Mini_Carte_Y ;
}

unsigned int Mini_Carte::get_Nombre_Ennemis() const
{
    return Nombre_Ennemis ;
}

void Mini_Carte::get_Nom_Fichier(string nom_fic) const
{
    nom_fic = Nom_Fichier ;
}

void Mini_Carte::get_Mini_Carte(Mini_Carte & mini_carte) const
{
    unsigned int i,j ;
    mini_carte.set_Nom_Fichier(Nom_Fichier) ;
    mini_carte.Alloc_Tab(Taille_Mini_Carte_X,Taille_Mini_Carte_Y) ;
    for (i=0; i<Taille_Mini_Carte_X; i++)
    {
        for (j=0; j<Taille_Mini_Carte_Y; j++)
        {
            mini_carte.set_Tab_Mini_Carte(i,j,get_Tab_Mini_Carte(i,j)) ;
        }
    }
    mini_carte.set_Nombre_Ennemis(Nombre_Ennemis) ;
}

void Mini_Carte::set_Nom_Fichier (string nom_fichier)
{
    Nom_Fichier = nom_fichier ;
}

void Mini_Carte::set_Taille_Mini_Carte_X (unsigned int x)
{
    Taille_Mini_Carte_X = x ;
}

void Mini_Carte::set_Taille_Mini_Carte_Y(unsigned int y)
{
    Taille_Mini_Carte_Y = y ;
}

void Mini_Carte::set_Nombre_Ennemis(unsigned int nb_ennemis)
{
    Nombre_Ennemis = nb_ennemis ;
}

void Mini_Carte::set_Mini_Carte(const Mini_Carte & mini_carte)
{
    unsigned int i,j ;
    mini_carte.get_Nom_Fichier(Nom_Fichier) ;
    Taille_Mini_Carte_X = mini_carte.get_Taille_Mini_Carte_X() ;
    Taille_Mini_Carte_Y = mini_carte.get_Taille_Mini_Carte_Y() ;
    if (Tab_Mini_Carte != NULL)
    {
        delete [] Tab_Mini_Carte ;
        Tab_Mini_Carte = NULL ;
    }
    Tab_Mini_Carte = new unsigned int [Taille_Mini_Carte_X*Taille_Mini_Carte_Y] ;
    for (i=0; i<Taille_Mini_Carte_X; i++)
    {
        for (j=0; j<Taille_Mini_Carte_Y; j++)
        {
            set_Tab_Mini_Carte(i,j,mini_carte.get_Tab_Mini_Carte(i,j)) ;
        }
    }
    Nombre_Ennemis = mini_carte.get_Nombre_Ennemis() ;
    // cout << Nom_Ficher << " " << Taille_Mini_Carte_X << " " << Taille_Mini_Carte_Y << " " << Nombre_Ennemis << endl ;
}

void Mini_Carte::Affiche_Mini_Carte() const
{
    unsigned int i,j ;
    for (i=0; i<(Taille_Mini_Carte_Y); i++)
    {
        for (j=0; j<(Taille_Mini_Carte_X); j++)
        {
            cout << get_Tab_Mini_Carte(j,i) ;
        }
        cout << endl ;
    }
    cout << endl ;
}

void Mini_Carte::Affiche_Non_Vide() const
{
    unsigned int i,j ;
    unsigned int entier_recup ;
    for (i=0; i<(Taille_Mini_Carte_Y); i++)
    {
        for (j=0; j<(Taille_Mini_Carte_X); j++)
        {
            entier_recup = get_Tab_Mini_Carte(j,i) ;
            if (entier_recup != 1)
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

bool Mini_Carte::Est_Ce_Que_Mur(unsigned int x, unsigned int y) const
{
    if (get_Tab_Mini_Carte(x,y)==0)
        {return true ;}
    return false ;
}

bool Mini_Carte::Est_Ce_Que_Plateforme(unsigned int x, unsigned int y) const
{
    if (get_Tab_Mini_Carte(x,y)==2)
        {return true ;}
    return false ;
}

bool Mini_Carte::Est_Ce_Que_Vide(unsigned int x,unsigned int y)const
{
    if((get_Tab_Mini_Carte(x,y)==1)||(get_Tab_Mini_Carte(x,y)==9))
        {return true;}
        else {return false;}
}


