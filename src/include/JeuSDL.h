#ifndef JEUSDL_H
#define JEUSDL_H

#ifdef _WIN32
    #include <SDL.h>
    #include <SDL_ttf.h>
    #include <SDL_image.h>
#else
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_ttf.h>
    #include <SDL2/SDL_image.h>
#endif // WIN32

#include <stdlib.h>
#include <cassert>
#include <time.h>
#include <Jeu.h>

//! \brief Pour gérer une image avec SDL2
class Image {

private:

    SDL_Surface * surface;
    SDL_Texture * texture;
    bool has_changed;

public:
    Image () ;
    ~Image () ;
    void loadFromFile (const char* filename, SDL_Renderer * renderer);
    void draw (SDL_Renderer * renderer, int x, int y, int w=-1, int h=-1);
    void draw_heros(SDL_Renderer * renderer, int x, int y, int w=-1, int h=-1, int moment_frame=0, char touche='d', char orientation='d', bool dans_air=false);
    void draw_ennemis_attaque(SDL_Renderer * renderer, int x, int y, int w=-1, int h=-1, char orientation='d');
    void draw_ennemis(SDL_Renderer * renderer, int x, int y, int w=-1, int h=-1, Uint32 time=0, char orientation='d');
    void draw_mur(SDL_Renderer * renderer, int x, int y, int w=-1, int h=-1, int type_mur=0);
    void draw_ecran(SDL_Renderer * renderer, int x, int y, int w=-1, int h=-1, int num_ecran=0);
    void draw_attaque_magique(SDL_Renderer * renderer, int x, int y, int w=-1, int h=-1);
};


/** La classe gérant le jeu avec un affichage SDL */
class sdlJeu {

private :

	Jeu jeu;
    SDL_Window * window;
    SDL_Renderer * renderer;
    SDL_Color color = {0,0,0} ;

    TTF_Font * font;
    SDL_Surface * texte = NULL ;
    SDL_Rect rectangle ;

    Image im_Heros;
    Image im_Carte_Mini_Carte;
    Image im_Ennemis;
    Image im_Ecran_Titre;

public :

    sdlJeu ();
    ~sdlJeu ();

    void sdlBoucle ();
    void sdlAff (Uint32 t, int repetition_touche_heros, char touche_heros, int pos_att_mag_x, int pos_att_mag_y);

    /** @brief lance le mini jeux et gere l'implementation du mini jeux grace aux fonction du jeu et de son mini jeux*/
    bool sdlBoucle_mini_jeux(string filename);
    /** @brief utile pour afficher le mini jeux remplace l'ecran du jeu pour le mini jeux utiliser uniquement lors du mini jeux*/
    void sdlAff_Mini_Jeux();

    void sdlAff_Carte() ;

    void Debut_Partie() ;
    void Debut_Jeu() ;

};

#endif // JEUSDL_H
