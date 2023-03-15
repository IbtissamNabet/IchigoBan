/**
 * @file Labyrinthe.h
 
 * @brief Module gérant les fonctionalités relatives à la création d'un labyrinthe..
   un labyrinthe est un tableau 2D constitué de Murs(#),des cases vides (.) et des emplacement cibles (*).

*/

#ifndef LABY_H
#define LABY_H 
#include "Dimension.h"
#include <string>
#include "Position.h"


//________________________________________________________________________________________________________________________________________________________________________
/**
   @brief La classe Labyrinthe contient une enumération pour indiqué le type de case figurante dans le labyrinthe , sa dimention et un tableau 2D
   de ses types de cases  .
*/
enum TypeLab { VIDE = '.' , MUR = '#' ,EMPCIBLE='*' };

class Labyrinthe {

    private : 

    Dimension dimL;

    TypeLab * tabLab;
//________________________________________________________________________________________________________________________________________________________________________
    public:

    /**
    @brief <B>Construit</B> un objet Labyrinthe .
    Le le constructeur crée un objet labyrinthe par defaut 
    */

    Labyrinthe();
 
 //________________________________________________________________________________________________________________________________________________________________________

  /**
    @brief <B>Detruit</B> un objet Labyrinthe .
    Le destucteur désalouele tableau 2D crée et met la dimension a 0
 
*/


    ~Labyrinthe();
   //________________________________________________________________________________________________________________________________________________________________________

   /**
    
    @brief la fonction getTypeLab renvoie le type de case qui se trouve dans la position donnée en parametre 
    @param p: la position (ligne et colonne) de la case que l'on veut savoir son type 
    */

    TypeLab getTypeLab (const Position & p )const ;
     
     /**
    
    //________________________________________________________________________________________________________________________________________________________________________

    @brief la fonction setTypeLab modifie  le type de case qui se trouve dans la position donnée en parametre en le type donné en paramétre  
    @param p: la position (ligne et colonne) de la case que l'on veut modifier son type 
    @param lab : le type de la case que l'on veut mettre dans cette position(mur , objectifs ...)

    */

    void setTypeLab(Position & p , TypeLab lab );

   //________________________________________________________________________________________________________________________________________________________________________

   /**
    @brief  la fonction getDim renvoie la dimension du labyrinthe (hauteur et largeur )
    */

    Dimension  getDim() const ;


    bool estPositionValide(const Position & p)const;
   //________________________________________________________________________________________________________________________________________________________________________

    /**
     * @brief Effectue une série de tests vérifiant que le module fonctionne sans problémes , il crée un labyrinthe  avec le premier 
     * constructeur, et verifie si sa dimension est égale a 0 , et donc le tableau de cases  pointe sur rien ,
     * crée un second avec le 2eme constructeur en lui donnant une dimension , et teste si la dimension est egale a celle donnée en 
     * paramétres et que le tableau ne pointe pas sur rien .
  */
   void testRegression() const ;
};

#endif