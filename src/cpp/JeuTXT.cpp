#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // WIN32
#include <winTxt.h>

#include <Jeu.h>


void txtAff(WinTXT & win, const Jeu & jeu) {
    const Carte& carte = jeu.get_Const_Jeu_Carte();
	const Mini_Carte& mini_carte = jeu.get_Const_Jeu_Mini_Carte();
	const Heros& Bob = jeu.get_Const_Jeu_Heros();
    // const Ennemis Tab_Ennemis[mini_carte.get_Nombre_Ennemis()] = jeu.get_Const_Jeu_Tab_Ennemis() ;

    // Système temporaire (j'espère) de récupération d'ennemis
    Ennemis * Tab_Ennemis = new Ennemis [mini_carte.get_Nombre_Ennemis()] ;
    for (unsigned int i=0; i<mini_carte.get_Nombre_Ennemis(); i++)
    {
        Tab_Ennemis[i].set_Ennemis(jeu.get_Jeu_Tab_Ennemis(i)) ;
    }


	unsigned int taille_mini_carte_x = mini_carte.get_Taille_Mini_Carte_X() ;
    unsigned int taille_mini_carte_y = mini_carte.get_Taille_Mini_Carte_Y() ;

	win.clear();

    // Affichage des murs
	for(unsigned int y=0;y<taille_mini_carte_y;y++)
	{
	    for(unsigned int x=0;x<taille_mini_carte_x;x++)
        {
            switch (mini_carte.get_Tab_Mini_Carte(x,y))
            {
                case 0 :
                    win.print(x,y,'0') ;
                    break;
                case 2 :
                        win.print(x,y,'2') ;
                        break;
                case 9 :
                    win.print(x,y,' ') ;
                    break;
                case 7 :
                    win.print(x,y,'|') ;
                    break ;
            }
        }
	}
	//Affichage de la carte à droite de la mini carte + position du personnage sur la map
    for(unsigned int y=0;y<carte.get_Taille_Carte_Y();y++)
	{
	    for(unsigned int x=2+taille_mini_carte_x;x<carte.get_Taille_Carte_X()+2+taille_mini_carte_x;x++)
        {
            switch (carte.get_Tab_Carte(x-2-taille_mini_carte_x,y))
            {
                case 0 :
                    win.print(x,y,'0') ;
                    break;
                case 1 :
                        win.print(x,y,' ') ;
                        break;
                case 8 :
                    win.print(x,y,' ') ;
                    break;
            }
        }
	}
    win.print(2+taille_mini_carte_x+Bob.get_Position_X_Carte(),(Bob.get_Position_Y_Carte()), 'B') ;

    // Affichage du héros
	win.print(Bob.get_Position_X_Mini_Carte(),Bob.get_Position_Y_Mini_Carte(),'B');
	// Affichage des Ennemis
	for(unsigned int i = 0; i<mini_carte.get_Nombre_Ennemis(); i++)
    {
        if (Tab_Ennemis[i].get_Stats_Ennemis_Point_De_Vie()!=0)
            {win.print(Tab_Ennemis[i].get_Position_X_Mini_Carte(),Tab_Ennemis[i].get_Position_Y_Mini_Carte(),'E');}
    }
    win.draw();

    delete [] Tab_Ennemis ;
    Tab_Ennemis = NULL ;
}

void txtBoucle (Jeu & jeu) {
	// Creation d'une nouvelle fenetre en mode texte
	// => fenetre de dimension et position (WIDTH,HEIGHT,STARTX,STARTY)
    WinTXT win (jeu.get_Const_Jeu_Mini_Carte().get_Taille_Mini_Carte_X()+2+
                jeu.get_Const_Jeu_Carte().get_Taille_Carte_X(),
                jeu.get_Const_Jeu_Mini_Carte().get_Taille_Mini_Carte_Y()+
                jeu.get_Const_Jeu_Carte().get_Taille_Carte_Y());
	bool ok = true;
	int c;
    unsigned int timer = 0 ;
    unsigned int vitesse_attaque=2;
    unsigned int position_attaque_magique_x;
    unsigned int position_attaque_magique_y;
    char orientation_attaque_magique;
	do {
	    txtAff(win,jeu);

        #ifdef _WIN32
        Sleep(100);
		#else
		usleep(100000);
        #endif // WIN32

        if (timer % 2 == 0)
        {
            jeu.Action_Automatique(vitesse_attaque,position_attaque_magique_x,position_attaque_magique_y, orientation_attaque_magique) ;

            if (timer == 1000000000)
            {
                timer = 0 ;
            }
        }
        timer++ ;

		c = win.getCh();
		switch (c) {
			case 'q':
				jeu.Action_Clavier('g',position_attaque_magique_x,position_attaque_magique_y,orientation_attaque_magique);
				break;
			case 'd':
				jeu.Action_Clavier('d',position_attaque_magique_x,position_attaque_magique_y,orientation_attaque_magique);
				break;
			case 's':
				jeu.Action_Clavier('b',position_attaque_magique_x,position_attaque_magique_y,orientation_attaque_magique);
				break;
			case 'z':
				jeu.Action_Clavier('h',position_attaque_magique_x,position_attaque_magique_y,orientation_attaque_magique);
				break;
            case ' ' :
                jeu.Action_Clavier(' ',position_attaque_magique_x,position_attaque_magique_y,orientation_attaque_magique);
                break;
            case 'n':
                jeu.Action_Clavier('n',position_attaque_magique_x,position_attaque_magique_y,orientation_attaque_magique);
                break;
			case 'p':
				ok = false;
				break;
            case '\e':
				ok = false;
				break;
		}

	} while (ok);

}
