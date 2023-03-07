#ifndef _SDLLAB_H
#define _SDLLAB_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

class SdlLab {

private :

	Labyrinthe lab;

    SDL_Window * window;
    SDL_Renderer * renderer;

 /*   TTF_Font * font;
    Image font_im;
    SDL_Color font_color;

    Mix_Chunk * sound;
    bool withSound; */

    Image im_mur;
    Image im_vide;
    Image im_empcible;

    
public :

    SdlLab();
    ~SdlLab ();
    void sdlLabAfficher ();

};

#endif