/**
 * @file wintxt.h
 * @brief Module gérant une fenetre texte 
 */
 
#ifndef WINTXT_H
#define WINTXT_H

/**
 * @class WinTXT
 * @brief classe représentant une fenetre texte avec un tableau 2D de caractères
 */
class WinTXT
{
private:

    int dimx;       //!< \brief largeur
    int dimy;       //!< \brief heuteur
    char* win;      //!< \brief stocke le contenu de la fentre dans un tableau 1D mais on y accede en 2D

public:

    WinTXT (int dx, int dy);
    void clear (char c=' ');
    void print (int x, int y, char c);
    void print (int x, int y, char* c);
    void draw (int x=0, int y=0);
    void pause();
    char getCh();

};

void termClear ();

#endif