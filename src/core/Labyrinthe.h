/**
 * @file Labyrinthe.h
 * @brief Module gérant les fonctionalités relatives à la création d'un labyrinthe.
 * <br> un labyrinthe est un tableau 2D constitué de Murs(#),des cases vides (.) et des emplacement cibles (*).
*/

#ifndef LABY_H
#define LABY_H 
#include "Dimension.h"
#include <string>
#include "Position.h"

enum TypeLab { VIDE = '.' , MUR = '#' ,EMPCIBLE='*' };

/**
 * @class Labyrinthe
 * @brief La classe contenant les caractéristiques d'un labyrinthe
 * <br> Dont une Dimension dimension dimL
 * <br> Et un tableau 2D tabLab de TypeLab (VIDE, MUR, EMPCIBLE)
*/
class Labyrinthe {

   private : 
      Dimension dimL;

   public:
      TypeLab * tabLab;
    
      /**
       * @brief <B>Construit</B> un objet Labyrinthe
       * <br> Le le constructeur crée un objet labyrinthe par defaut 
       */
       Labyrinthe();
 
      /**
       * @brief <B>Detruit</B> un objet Labyrinthe .
       * <br> Le destucteur désaloue le tableau 2D crée et met les dimensions a 0
       */
      ~Labyrinthe();

      /**
       * @brief la fonction getTypeLab renvoie le type de case qui se trouve dans la position donnée en parametre 
       * @param p: la position de la case dont on veut savoir type 
       */
      TypeLab getTypeLab (const Position & p )const ;
     
      /**
       * @brief Accesseur de l'attribut DimL du labyrinthe
       * @return Un objet de type Dimension
       */
      Dimension  getDim() const ;

      /**
       * @brief Mutateur de l'attribut dimL du labyrinthe
       * @param hauteur un entier à affecter à dimL.Hauteur
       * @param largeur un entier à affecter à dimL.Largeur
       */
      void setDim(int hauteur, int largeur);
   
      /**
       * @brief  Renvoie un pointeur sur un tableau de TypeLab
       * @return l'attribut tabLab
       */
      TypeLab * getTabLab() const ;
   
      /**
       * @brief Teste si une position est valide elle est dans le labyrinthe et n'est pas un mur
       * @param p la position à tester 
       */
      bool estPositionValide(const Position & p)const;
 
      void testRegression() const ;
};

#endif