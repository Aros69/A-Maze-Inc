#include <JeuSDL.h>

const int TAILLE_MAX_MINI_CARTE_X = 22 /* Taille_X de la plus grande mini_carte */ ;
const int TAILLE_MAX_MINI_CARTE_Y = 22 /* Taille_Y de la plus grande mini_carte */ ;

// ============= CLASS IMAGE =============== //
Image::Image ()
{
    surface = NULL;
    texture = NULL;
    has_changed = false;
}

Image::~Image()
{

}

void Image::loadFromFile (const char* filename, SDL_Renderer * renderer)
{
    surface = IMG_Load(filename);
    if (surface == NULL) {
        string nfn = string("../") + filename;
        cout << "Error: cannot load "<< filename <<". Trying "<<nfn<<endl;
        surface = IMG_Load(nfn.c_str());
        if (surface == NULL) {
            nfn = string("../") + nfn;
            surface = IMG_Load(nfn.c_str());
        }
    }
    if (surface == NULL) {
        cout<<"Error: cannot load "<< filename <<endl;
        exit(1);
    }

    SDL_Surface * surfaceCorrectPixelFormat = SDL_ConvertSurfaceFormat(surface,SDL_PIXELFORMAT_ARGB8888,0);
    SDL_FreeSurface(surface);
    surface = surfaceCorrectPixelFormat;

    texture = SDL_CreateTextureFromSurface(renderer,surface);
    if (texture == NULL) {
        cout << "Error: problem to create the texture of "<< filename<< endl;
        exit(1);
    }

    SDL_FreeSurface(surfaceCorrectPixelFormat) ;
}

void Image::draw (SDL_Renderer * renderer, int x, int y, int w, int h)
{
    int ok;
    SDL_Rect r;
    r.x = x;
    r.y = y;
    r.w = (w<0)?surface->w:w;
    r.h = (h<0)?surface->h:h;

    if (has_changed) {
        ok = SDL_UpdateTexture(texture,NULL,surface->pixels,surface->pitch);
        assert(ok == 0);
        has_changed = false;
    }

    ok = SDL_RenderCopy(renderer,texture,NULL,&r);
    assert(ok == 0);
}

void Image::draw_ennemis_attaque(SDL_Renderer * renderer, int x, int y, int w, int h,
                                char orientation)
{
    int ok;
    SDL_Rect r;
    r.y = y-h;
    r.w = (w<0)?surface->w:w*2;
    r.h = (h<0)?surface->h:h*2;

    SDL_Rect attaque = {0,52,67,38} ;

    if (has_changed) {
        ok = SDL_UpdateTexture(texture,NULL,surface->pixels,surface->pitch);
        assert(ok == 0);
        has_changed = false;
    }
    if (orientation=='d')
    {
        ok = SDL_RenderCopyEx(renderer,texture,&attaque,&r,NULL,NULL,SDL_FLIP_HORIZONTAL);
        assert(ok == 0);
    }
    else
    {
        r.x = x-w;
        ok = SDL_RenderCopy(renderer,texture,&attaque,&r);
        assert(ok == 0);
    }
}

void Image::draw_ennemis(SDL_Renderer * renderer, int x, int y, int w, int h,
                        Uint32 time, char orientation)
{
    int ok;
    SDL_Rect r;
    r.x = x;
    r.y = y-h;
    r.w = (w<0)?surface->w:w;
    r.h = (h<0)?surface->h:h*2;
    int frame = time%12 ;
    SDL_Rect frame_rectangle = {49*frame,0,47,52} ;

    if (has_changed) {
        ok = SDL_UpdateTexture(texture,NULL,surface->pixels,surface->pitch);
        assert(ok == 0);
        has_changed = false;
    }
    if (orientation=='d')
    {
        ok = SDL_RenderCopyEx(renderer,texture,&frame_rectangle,&r,NULL,NULL,SDL_FLIP_HORIZONTAL);
        assert(ok == 0);
    }
    else
    {
        ok = SDL_RenderCopy(renderer,texture,&frame_rectangle,&r);
        assert(ok == 0);
    }
}

void Image::draw_mur(SDL_Renderer * renderer, int x, int y, int w, int h,
                    int type_mur)
{
    int ok;
    SDL_Rect r;
    r.x = x;
    r.y = y;
    r.w = (w<0)?surface->w:w;
    r.h = (h<0)?surface->h:h;
    SDL_Rect type_plateforme;

    if (has_changed) {
        ok = SDL_UpdateTexture(texture,NULL,surface->pixels,surface->pitch);
        assert(ok == 0);
        has_changed = false;
    }
    switch (type_mur){
        case 1:{
            type_plateforme = {128,0,128,128} ;
            break;
        }
        case 2:{
            type_plateforme = {256,0,128,128} ;
            r.h=h*3;
            break ;
        }
        case 3:{
            type_plateforme = {256,128,22,22} ;
            break ;
        }
        case 4:{
            type_plateforme = {256,150,18,18} ;
            break;
        }
        default:{
            type_plateforme = {0,0,128,128} ;
            break ;
        }
    }
    ok = SDL_RenderCopy(renderer,texture,&type_plateforme,&r);
    assert(ok == 0);
}

void Image::draw_heros(SDL_Renderer * renderer, int x, int y, int w, int h,
                      int moment_frame, char touche, char orientation, bool dans_air)
{
    int ok;
    SDL_Rect r;
    r.x = x;
    r.y = y;
    r.w = (w<0)?surface->w:w;
    r.h = (h<0)?surface->h:h;

    SDL_Rect heros ;

    if (has_changed) {
        ok = SDL_UpdateTexture(texture,NULL,surface->pixels,surface->pitch);
        assert(ok == 0);
        has_changed = false;
    }
    if  (touche=='d'&&dans_air==false)
    {
        heros = {25*(moment_frame%5),0,25,42} ;
        ok = SDL_RenderCopy(renderer,texture,&heros,&r);
        assert(ok == 0);
    }
    else if (touche=='g'&&dans_air==false)
        {
            heros = {25*(moment_frame%5),0,25,42} ;
            ok = SDL_RenderCopyEx(renderer,texture,&heros,&r,NULL,NULL,SDL_FLIP_HORIZONTAL);
            assert(ok == 0);
        }
        else if (touche == ' '||touche == 'n')
            {
                heros={25,42,50,42};
                if (orientation=='d')
                {
                    r.w = w*2 ;
                    r.x = x ;
                    ok = SDL_RenderCopy(renderer,texture,&heros,&r);
                    assert(ok == 0);
                }
                else
                {
                    r.w = w*2 ;
                    r.x = x-w ;
                    ok = SDL_RenderCopyEx(renderer,texture,&heros,&r,NULL,NULL,SDL_FLIP_HORIZONTAL);
                    assert(ok == 0);
                }
            }
            else if (touche=='b'||touche=='h'||dans_air==true)
            {
                heros = {0,42,25,42};
                if (orientation=='d')
                {
                    ok = SDL_RenderCopy(renderer,texture,&heros,&r);
                    assert(ok == 0);
                }
                else
                {
                    ok = SDL_RenderCopyEx(renderer,texture,&heros,&r,NULL,NULL,SDL_FLIP_HORIZONTAL);
                    assert(ok == 0);
                }
            }
}

void Image::draw_ecran(SDL_Renderer * renderer, int x,int y, int w, int h, int num_ecran)
{
    int ok;
    SDL_Rect r;
    r.x = x;
    r.y = y;
    r.w = (w<0)?surface->w:w;
    r.h = (h<0)?surface->h:h;

    SDL_Rect fond = {0,128,120,64};

    if (has_changed) {
        ok = SDL_UpdateTexture(texture,NULL,surface->pixels,surface->pitch);
        assert(ok == 0);
        has_changed = false;
    }
    switch(num_ecran)
    {
        case 0:
        {
            fond = {0,0,5120,2880} ;
            break ;
        }
        case 1:
        {
            fond = {0,2880,768,576} ;
            break ;
        }
        case 2:
        {
            fond = {0,3456,5120,2880};
            break ;
        }
    }
    ok = SDL_RenderCopy(renderer,texture,&fond,&r);
    assert(ok == 0);
}

void Image::draw_attaque_magique(SDL_Renderer * renderer, int x,int y, int w, int h)
{
    int ok;
    SDL_Rect r;
    r.x = x;
    r.y = y;
    r.w = (w<0)?surface->w:w;
    r.h = (h<0)?surface->h:h;

    SDL_Rect magie = {75,42,32,42};

    if (has_changed) {
        ok = SDL_UpdateTexture(texture,NULL,surface->pixels,surface->pitch);
        assert(ok == 0);
        has_changed = false;
    }

    ok = SDL_RenderCopy(renderer,texture,&magie,&r);
    assert(ok == 0);
}
// ============= CLASS SDLJEU =============== //
sdlJeu::sdlJeu () : jeu()
{
    // Initialisation de la SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << endl;SDL_Quit();exit(1);
    }

    if (TTF_Init() != 0) {
        cout << "Erreur lors de l'initialisation de la SDL_ttf : " << SDL_GetError() << endl;SDL_Quit();exit(1);
    }

    int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
    if( !(IMG_Init(imgFlags) & imgFlags)) {
        cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << endl;SDL_Quit();exit(1);
    }


	int dimx = 600, dimy = 600; // On et en plein écran (infos pas utile)

    // Creation de la fenetre
    window = SDL_CreateWindow ("A-Maze-Inc", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                dimx, dimy, SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN_DESKTOP);

    // int plein_ecran = SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP) ;

    if (window == NULL) {
        cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << endl; SDL_Quit(); exit(1);
    }

    //SDL_RENDERER_SOFTWARE à la place de SDL_RENDERER_ACCELERATED (pour éliminer fuite memoire)
    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_SOFTWARE);

    im_Carte_Mini_Carte.loadFromFile("data/sdl/Carte_Mini_Carte.png",renderer);
    im_Heros.loadFromFile("data/sdl/Heros.png",renderer) ;
    im_Ennemis.loadFromFile("data/sdl/Ennemis.png",renderer);
    im_Ecran_Titre.loadFromFile("data/sdl/Ecran_Titre.png",renderer) ;
}

sdlJeu::~sdlJeu ()
{
    TTF_Quit() ;
    // SDL_FreeSurface(texte) ;
    SDL_DestroyRenderer(renderer) ;
    SDL_DestroyWindow(window) ;
    SDL_Quit() ;
}

string to_string2(unsigned int i)
{
    char tx[128];
    sprintf(tx,"%d", i);
    return string(tx);
}

void sdlJeu::sdlAff_Mini_Jeux()
{
    //Remplir l'écran d'une couleur
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    int * dimx,* dimy ;
    dimx = new int ;
    dimy = new int ;
    SDL_GetWindowSize(window, dimx, dimy) ;//remplie les donné de la taille de ton ecran

    const int TAILLE_SPRITE_X = *dimx / Taille ;//taille d'une case calcul a partir de la taille de ton ecran
    const int TAILLE_SPRITE_Y = *dimy / Taille ;
    // cout << *x << " " << *y << endl ;

	unsigned int x,y;

    const Mini_Jeux0 & carte=jeu.get_Jeu_Mini_Jeux();

    //affiche la map de la carte
    for(y=0;y<Taille;y++)
    {
        for(x=0;x<Taille;x++)
        {
            if (carte.get_Tab(x,y)==1)
            {
                im_Carte_Mini_Carte.draw_mur(renderer,x*TAILLE_SPRITE_X,
                                             y*TAILLE_SPRITE_Y,TAILLE_SPRITE_X,
                                             TAILLE_SPRITE_Y,0);
            }
        }
    }

    //affiche le heros il n'esst pas annimer

    im_Heros.draw_heros(renderer,
                        carte.get_Position_X()*TAILLE_SPRITE_X,
                        carte.get_Position_Y()*TAILLE_SPRITE_Y,
                        TAILLE_SPRITE_X,TAILLE_SPRITE_Y,0,'d','d') ;

    delete dimx ;
    dimx = NULL ;
    delete dimy ;
    dimy = NULL ;
    SDL_RenderPresent(renderer);
}

void sdlJeu::sdlAff (Uint32 t, int repetition_touche_heros, char touche_heros,
                    int pos_att_mag_x, int pos_att_mag_y)
{
	//Remplir l'écran d'une couleur
    SDL_SetRenderDrawColor(renderer, 98, 99, 106, 255);
    SDL_RenderClear(renderer);

    int * dimx,* dimy ;
    dimx = new int ;
    dimy = new int ;
    SDL_GetWindowSize(window, dimx, dimy) ;

    const int Decalage_hud = 5 ;

    const int TAILLE_SPRITE_X = *dimx / (TAILLE_MAX_MINI_CARTE_X+Decalage_hud) ;
    const int TAILLE_SPRITE_Y = *dimy / (TAILLE_MAX_MINI_CARTE_Y+Decalage_hud) ;
    // cout << *x << " " << *y << endl ;

	unsigned int x,y;
	const Mini_Carte & mini_carte = jeu.get_Const_Jeu_Mini_Carte();
	const Heros & heros = jeu.get_Const_Jeu_Heros() ;

	int Decalage_x = (TAILLE_MAX_MINI_CARTE_X-mini_carte.get_Taille_Mini_Carte_X()+Decalage_hud)/2 ;
    int Decalage_y = (TAILLE_MAX_MINI_CARTE_Y-mini_carte.get_Taille_Mini_Carte_Y()+Decalage_hud)/2 ;

	Ennemis * Tab_Ennemis = new Ennemis [mini_carte.get_Nombre_Ennemis()] ;
    for (unsigned int i=0; i<mini_carte.get_Nombre_Ennemis(); i++)
    {
        Tab_Ennemis[i].set_Ennemis(jeu.get_Jeu_Tab_Ennemis(i)) ;
    }

	// Afficher les sprites des murs de la mini carte
	for (x=0; x<mini_carte.get_Taille_Mini_Carte_X(); ++x)
		for (y=0; y<mini_carte.get_Taille_Mini_Carte_Y(); ++y)
		{
		    if (mini_carte.get_Tab_Mini_Carte(x,y)==0)
				{im_Carte_Mini_Carte.draw_mur(renderer,(Decalage_x+x)*TAILLE_SPRITE_X,
                     (Decalage_y+y)*TAILLE_SPRITE_Y,TAILLE_SPRITE_X,
                     TAILLE_SPRITE_Y,0);}
            else if (mini_carte.get_Tab_Mini_Carte(x,y)==2)
                {
                    im_Carte_Mini_Carte.draw_mur(renderer,(Decalage_x+x)*TAILLE_SPRITE_X,
                                                (Decalage_y+y)*TAILLE_SPRITE_Y,TAILLE_SPRITE_X,
                                                TAILLE_SPRITE_Y,1);
                    im_Carte_Mini_Carte.draw_mur(renderer,(Decalage_x+x)*TAILLE_SPRITE_X,
                                                (Decalage_y+y)*TAILLE_SPRITE_Y,TAILLE_SPRITE_X,
                                                TAILLE_SPRITE_Y,2);
                }
            else
                    {im_Carte_Mini_Carte.draw_mur(renderer,(Decalage_x+x)*TAILLE_SPRITE_X,
                                                (Decalage_y+y)*TAILLE_SPRITE_Y,
                                                TAILLE_SPRITE_X,TAILLE_SPRITE_Y,1);}
		}

	// Afficher le sprite du héros dans la carte
    im_Heros.draw_heros(renderer,
                        (Decalage_x+heros.get_Position_X_Mini_Carte())*TAILLE_SPRITE_X,
                        (Decalage_y+heros.get_Position_Y_Mini_Carte())*TAILLE_SPRITE_Y,
                        TAILLE_SPRITE_X,TAILLE_SPRITE_Y,repetition_touche_heros,touche_heros,
                        heros.get_Orientation(),heros.get_Dans_Air()) ;

    // Affiche si elle existe l'attaque magique du héros
    if ((pos_att_mag_x!=0)&&(pos_att_mag_y!=0))
    {
        im_Heros.draw_attaque_magique(renderer, (Decalage_x+pos_att_mag_x)*TAILLE_SPRITE_X,
                                      (Decalage_y+pos_att_mag_y)*TAILLE_SPRITE_Y,
                                      TAILLE_SPRITE_X,TAILLE_SPRITE_Y);
    }

	// Afficher le sprite des ennemis
	for (x=0 ; x<mini_carte.get_Nombre_Ennemis(); x++ )
    {
        if(Tab_Ennemis[x].Toucher_Heros(Tab_Ennemis[x].Attaque_Ennemis(mini_carte),
                Tab_Ennemis[x].get_Position_Y_Mini_Carte(),
                heros.get_Position_X_Mini_Carte(),heros.get_Position_Y_Mini_Carte()))
        {
            im_Ennemis.draw_ennemis_attaque(renderer,
                                            (Decalage_x+Tab_Ennemis[x].get_Position_X_Mini_Carte())*TAILLE_SPRITE_X,
                                            (Decalage_y+Tab_Ennemis[x].get_Position_Y_Mini_Carte())*TAILLE_SPRITE_Y,
                                            TAILLE_SPRITE_X,TAILLE_SPRITE_Y,Tab_Ennemis[x].get_Direction()) ;
        }
        else
        {
            im_Ennemis.draw_ennemis(renderer,
                                    (Decalage_x+Tab_Ennemis[x].get_Position_X_Mini_Carte())*TAILLE_SPRITE_X,
                                    (Decalage_y+Tab_Ennemis[x].get_Position_Y_Mini_Carte())*TAILLE_SPRITE_Y,
                                    TAILLE_SPRITE_X,TAILLE_SPRITE_Y,t,Tab_Ennemis[x].get_Direction());
        }
    }

    // Chargement de la police
    font = TTF_OpenFont("data/sdl/RobotoCondensed-Regular.ttf", 90) ;
    /* texte = TTF_RenderUTF8_Solid(font, "Bonjour voyageur !", color) ;
    SDL_Texture * test = SDL_CreateTextureFromSurface(renderer,message_ttf) ;
    SDL_RenderCopy(renderer, test, NULL, &message_rect); */

    // Barre du HUD
    rectangle.x= Decalage_hud/2*TAILLE_SPRITE_X ;
    rectangle.y= 0 ;
    rectangle.w= TAILLE_MAX_MINI_CARTE_X*TAILLE_SPRITE_X ;
    rectangle.h= Decalage_hud/2*TAILLE_SPRITE_Y ;
    SDL_SetRenderDrawColor(renderer, 169, 167, 183, 255);
    SDL_RenderFillRect(renderer, &rectangle);

    // Barre de vie et texte
    double pv = heros.get_Point_De_Vie() ;
    double rapport_pdv = (pv/heros.get_Point_De_Vie_Max()) ;
    string vie = "Vie :   " + to_string2(heros.get_Point_De_Vie()) +
                " / " + to_string2(heros.get_Point_De_Vie_Max()) ;
    const char * vie_char = vie.c_str() ;
    //double rapport_pdv = (heros.get_Point_De_Vie()/heros.get_Point_De_Vie_Max()) ;
    texte = TTF_RenderUTF8_Solid(font, vie_char, color) ;

    rectangle.x= ((Decalage_hud/2)+2)*TAILLE_SPRITE_X + 5 ;
    rectangle.y= (((Decalage_hud/2)-1)*TAILLE_SPRITE_Y)/2 -5 ;
    rectangle.w= 6*TAILLE_SPRITE_X ;
    rectangle.h= ((Decalage_hud/2)-1)*TAILLE_SPRITE_Y + 15 ;
    SDL_SetRenderDrawColor(renderer, 56, 55, 59, 255);
    SDL_RenderFillRect(renderer, &rectangle);

    rectangle.x= ((Decalage_hud/2)+2)*TAILLE_SPRITE_X + 8 ;
    rectangle.y= (((Decalage_hud/2)-1)*TAILLE_SPRITE_Y)/2 -3 ;
    rectangle.w= (6*TAILLE_SPRITE_X)*rapport_pdv -5 ;
    rectangle.h= ((Decalage_hud/2)-1)*TAILLE_SPRITE_Y + 10 ;
    SDL_SetRenderDrawColor(renderer, 221, 14, 17, 255);
    SDL_RenderFillRect(renderer, &rectangle);

    SDL_Texture * texture_texte = SDL_CreateTextureFromSurface(renderer,texte) ;
    rectangle.x= (Decalage_hud/2)*TAILLE_SPRITE_X ;
    rectangle.y= 0 ;
    rectangle.w= (TAILLE_MAX_MINI_CARTE_X/3)*TAILLE_SPRITE_X ;
    rectangle.h= Decalage_hud/2*TAILLE_SPRITE_Y ;
    SDL_RenderCopy(renderer, texture_texte, NULL, &rectangle);

    SDL_FreeSurface(texte) ;
    TTF_CloseFont(font) ;

    delete dimx ;
    dimx = NULL ;
    delete dimy ;
    dimy = NULL ;
    delete [] Tab_Ennemis ;
    Tab_Ennemis = NULL ;
}

void sdlJeu::sdlAff_Carte()
{
    SDL_RenderClear(renderer);

    unsigned int x,y;
    int * dimx,* dimy ;
    dimx = new int ;
    dimy = new int ;
    SDL_GetWindowSize(window, dimx, dimy) ;
    SDL_Event events;

    const Carte & carte = jeu.get_Const_Jeu_Carte() ;
    const Heros & heros = jeu.get_Const_Jeu_Heros() ;

    const int TAILLE_SPRITE_X = *dimx / carte.get_Taille_Carte_X() ;
    const int TAILLE_SPRITE_Y = *dimy / carte.get_Taille_Carte_Y() ;

    // Afficher les sprites des murs de la carte
	for (x=0; x<carte.get_Taille_Carte_X(); ++x)
		for (y=0; y<carte.get_Taille_Carte_Y(); ++y)
			if (carte.get_Tab_Carte(x,y)==0)
				{im_Carte_Mini_Carte.draw_mur(renderer,x*TAILLE_SPRITE_X,
                                              y*TAILLE_SPRITE_Y,TAILLE_SPRITE_X,TAILLE_SPRITE_Y);}
            else if (carte.get_Tab_Carte(x,y)==1)
                    {im_Carte_Mini_Carte.draw_mur(renderer,x*TAILLE_SPRITE_X,
                                                  y*TAILLE_SPRITE_Y,TAILLE_SPRITE_X,TAILLE_SPRITE_Y,1);}
                else
                {
                    im_Carte_Mini_Carte.draw_mur(renderer,x*TAILLE_SPRITE_X,
                                                y*TAILLE_SPRITE_Y,TAILLE_SPRITE_X,TAILLE_SPRITE_Y,1);
                    im_Carte_Mini_Carte.draw_mur(renderer,x*TAILLE_SPRITE_X,
                                                y*TAILLE_SPRITE_Y,TAILLE_SPRITE_X,TAILLE_SPRITE_Y,3);
                }
    // Afficher la position du heros dans la carte
    im_Carte_Mini_Carte.draw_mur(renderer,heros.get_Position_X_Carte()*TAILLE_SPRITE_X,
                                heros.get_Position_Y_Carte()*TAILLE_SPRITE_Y,
                                 TAILLE_SPRITE_X,TAILLE_SPRITE_Y,4);

    SDL_RenderPresent(renderer);
    while (SDL_WaitEvent(&events)) {
        if (events.type == SDL_KEYDOWN)
        {
            if (events.key.keysym.scancode==SDL_SCANCODE_SEMICOLON||
                events.key.keysym.scancode==SDL_SCANCODE_ESCAPE||
                events.key.keysym.scancode==SDL_SCANCODE_UP||
                events.key.keysym.scancode==SDL_SCANCODE_DOWN||
                events.key.keysym.scancode==SDL_SCANCODE_LEFT||
                events.key.keysym.scancode==SDL_SCANCODE_RIGHT||
                events.key.keysym.scancode==SDL_SCANCODE_SPACE)
            {
                break;
            }
        }
    }
}

bool sdlJeu::sdlBoucle_mini_jeux(string filename)
{
    sdlAff_Mini_Jeux();
    bool quit_mini_jeux=false;
    //string filename="data/Mini_Jeux/test.txt";
    unsigned int k=Taille-2;
    SDL_Event events;
        //deja initialiser dans le constructeur par defaut du Jeu
        sdlAff_Mini_Jeux();
        ifstream fichier (filename.c_str());
        assert(fichier.is_open());
        while(!quit_mini_jeux)
        {
            sdlAff_Mini_Jeux();
            // la boucle doit atteindre un certain nombre pour remplir la premiere ligne du tableau avec un fichier
            if(k==Taille-2)
            {
                unsigned int a;
                for(unsigned int j=1;j<Taille-1;j++)
                {
                    fichier>>a;
                    assert(a==0 ||a==1);
                    jeu.Mini_Jeux_Action_Auto_Avant_Bouger(j,a);//remplie juste les fonction
                }
                k=0;
            }
            if(SDL_PollEvent(&events))
            {
                if (events.type == SDL_KEYDOWN){
                        //ici ce n'est pas une boucle car le mini-jeu se veut etre tour par tour
                    switch (events.key.keysym.scancode)
                    {
                        case (SDL_SCANCODE_LEFT):
                        {
                            jeu.Mini_Jeux_Bouger('g');
                            break;
                        }
                        case (SDL_SCANCODE_RIGHT):
                        {
                            jeu.Mini_Jeux_Bouger('d');
                            break ;
                        }
                        case (SDL_SCANCODE_ESCAPE):
                        {
                            quit_mini_jeux=true;
                            fichier.close();
                            return false;
                            break;
                        }
                        default:
                            jeu.Mini_Jeux_Bouger(' ');

                    }
                    sdlAff_Mini_Jeux();
            //fais juste tomber ligne par ligne les blocks
                    if (quit_mini_jeux==false)
                        {quit_mini_jeux=jeu.Mini_Jeux_Action_Auto_Apres_Bouger(k);}
            k+=1;//ce compteur permet de savoir quand remmetre une deuxieme ligne
            // verifie si on a gagner ou non
                    unsigned int test_win=jeu.get_Jeu_Mini_Jeux().get_Position_Y();
                    if (test_win==0)
                    {
                        quit_mini_jeux=true;
                        fichier.close();
                        return true;
                    }
                }
            }
        }
            return false;//si on sort de cette boucle sans avoir gagner alors cela sinifie que l'on a perdu
}

void sdlJeu::sdlBoucle ()
{
    SDL_Event events;
	bool quit = false;

    Uint32 t = SDL_GetTicks(), nt;

    char touche = 'd' ;
    unsigned int repetition_touche=0 ;

    unsigned int vitesse_attaque=1;//juste utile pour que l'attaque se fasse en plusieur temps
    unsigned int position_attaque_magique_x=0;
    unsigned int position_attaque_magique_y=0;
    char orientation_attaque_magique='d';
	// tant que ce n'est pas la fin ...
	while (!quit)
    {

        nt = SDL_GetTicks();
        if (nt-t>200)
        {
            jeu.Action_Automatique(vitesse_attaque,position_attaque_magique_x,
                                   position_attaque_magique_y,orientation_attaque_magique);
            t = nt;
        }
		// tant qu'il y a des evenements à traiter (cette boucle n'est pas bloquante)
		while (SDL_PollEvent(&events))
        {
            if (events.type == SDL_KEYDOWN)
            {// Si une touche est enfoncee
                switch (events.key.keysym.scancode)
                {
                    case SDL_SCANCODE_UP: // car Y inverse
                        jeu.Action_Clavier('h',position_attaque_magique_x,
                                           position_attaque_magique_y,orientation_attaque_magique);
                        touche = 'h';
                        break;
                    case SDL_SCANCODE_DOWN: // car Y inverse
                        jeu.Action_Clavier('b',position_attaque_magique_x,
                                           position_attaque_magique_y,orientation_attaque_magique);
                        touche = 'b';
                        break;
                    case SDL_SCANCODE_LEFT:
                        jeu.Action_Clavier('g',position_attaque_magique_x,
                                           position_attaque_magique_y,orientation_attaque_magique);
                        if (touche =='g')
                            {repetition_touche++;}
                        else
                        {
                            touche ='g' ;
                            repetition_touche=0;
                        }
                        break;
                    case SDL_SCANCODE_RIGHT:
                        jeu.Action_Clavier('d',position_attaque_magique_x,
                                           position_attaque_magique_y,orientation_attaque_magique);
                        if (touche =='d')
                            {repetition_touche++;}
                        else
                        {
                            touche ='d';
                            repetition_touche=0;
                        }
                        break;
                    case SDL_SCANCODE_SPACE:
                        jeu.Action_Clavier(' ',position_attaque_magique_x,
                                           position_attaque_magique_y,orientation_attaque_magique);
                        touche = ' ';
                        break;
                    case SDL_SCANCODE_N:
                        jeu.Action_Clavier('n',position_attaque_magique_x,
                                           position_attaque_magique_y,orientation_attaque_magique);
                        touche = 'n' ;
                        break;
                    case SDL_SCANCODE_SEMICOLON: //appuyer sur 'm'
                        sdlAff_Carte();
                        break;
                    case SDL_SCANCODE_E:
                    { // pour savoir si on applique le bonus ou pas
                            jeu.Mini_Jeux_Reinitialiser();
                            if (sdlBoucle_mini_jeux("data/Mini_Jeux/test.txt"))
                            {
                                jeu.Modifie_Stats_heros(100);
                            }
                            break;
                    }
                    case SDL_SCANCODE_ESCAPE:
                        quit = true;
                        break;
                    default:
                        break;
				}
			}
		}
		// on affiche le jeu sur le buffer caché
		sdlAff(t, repetition_touche, touche, position_attaque_magique_x,position_attaque_magique_y);

		// on permute les deux buffers (cette fonction ne doit se faire qu'une seule fois dans la boucle)
        SDL_RenderPresent(renderer);
	}
}

void sdlJeu::Debut_Jeu()
{
    //Remplir l'écran d'une couleur
    SDL_SetRenderDrawColor(renderer, 98, 99, 106, 255);
    SDL_RenderClear(renderer);
    SDL_Event events ;

    int * dimx,* dimy ;
    dimx = new int ;
    dimy = new int ;
    SDL_GetWindowSize(window, dimx, dimy) ;

    //Affiche le fond du jeux pas très joli donc pas insérer mais fonctionnel
    im_Ecran_Titre.draw_ecran(renderer,0,0,*dimx,*dimy,0);

    SDL_RenderPresent(renderer);
    while (SDL_WaitEvent(&events)) {
        if (events.type == SDL_KEYDOWN)
        {
            if (events.key.keysym.scancode==SDL_SCANCODE_SPACE)
            {
                Debut_Partie();
                break;
            }
        }
    }
    delete dimx ;
    delete dimy ;
}

void sdlJeu::Debut_Partie()
{
    jeu.Labyrinthe() ;
    sdlBoucle();
}
