/**
 * @file Dimension.h
 
 * @brief Module gérant les fonctionalités relatives à la Dimension d'un  labyrinthe 

*/
//_______________________________________________________________________________________________________________________________________________________________



#ifndef DIMENSION_H
#define DIMENSION_H

/**
 
 * @brief la class Dimension p contient deux paramétres membres étant la de la chauteur et la largeur du labyrinthe 

*/
class Dimension {
    private:
        int largeur;
        int hauteur;

    public:
/**
    @brief <B>Construit</B> un objet Dimension
    Le  constructeur crée un objet DImension par defaut avec hauteur et largeur nulles 
*/

        Dimension();
//___________________________________________________________________________________________________________________________________________________________________
/**
    @brief
    La fonction getLargeur  récupere la largeur du labyrinthe 
*/
        int  getLargeur() const;
//___________________________________________________________________________________________________________________________________________________________________
/**
    @brief
    La fonction getHauteur récupere la hauteur du labyrinthe 
*/
        int getHauteur() const;
//___________________________________________________________________________________________________________________________________________________________________
/**
    @brief
    La procedure  setLargeur remplace la largeur initiale avec celle donnée en paramétre 
    @param a:la nouvelle largeur 
*/
        void setLargeur(int L);
//___________________________________________________________________________________________________________________________________________________________________
/**
    @brief
    La procedure setHauteur remplace la hauteur initiale avec celle donnée en paramétre 
    @param a:la nouvelle hauteur
*/
        void setHauteur(int H);
    
};
  
#endif