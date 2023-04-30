/**
 * @file sdlLab.h
 * @brief Module gérant l'affichage graphique du jeu IchigoBan
*/

#ifndef _SDLLAB_H
#define _SDLLAB_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include "Jeu.h" 


/**
 * @class Image
 * @brief Classe gérant les images
 * Contient une surface m_surface et une texture m_texture
 */
class Image {

private:

    SDL_Surface * m_surface;
    SDL_Texture * m_texture;
    bool m_hasChanged;

public:
    Image () ;
    ~Image();
    void loadFromFile (const char* filename, SDL_Renderer * renderer);
    void loadFromCurrentSurface (SDL_Renderer * renderer);
    void draw (SDL_Renderer * renderer, int x, int y, int w=-1, int h=-1);
    SDL_Texture * getTexture() const;
    void setSurface(SDL_Surface * surf);
};

/**
 * @class SdlLab
 * @brief Classe gérant l'affichage du labyrinthe et des autres éléments du jeu avec SDL
 * Contient les images des différents composants du labyrinthe et du jeu
 */
class SdlLab {

private :

    SDL_Window * window;
    SDL_Renderer * renderer;
    Mix_Music * son;

    Image im_mur;
    Image im_vide;
    Image im_empcible;
    Image im_gardien;
    Image im_fraise;
    Image im_touches;
    Image im_victoire ;

    
public :
	Jeu jeu;

    /**
     * @brief <B>Construit</B> un objet SdlLab
     * charge tout les images
     * initialise le niveau du jeu à 0
     */
    SdlLab();
    ~SdlLab ();

    void sdlLabAfficher();
    void sdlLabBoucle();

    /**
     * @brief Fonction qui fait passer le Jeu au niveau suivant
     */
    void nouvellePartie();
};

#endif
