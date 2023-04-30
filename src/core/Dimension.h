/**
 * @file Dimension.h
 * @brief Module gérant les fonctionalités relatives à la Dimension d'un  labyrinthe 
 */
#ifndef DIMENSION_H
#define DIMENSION_H

/**
 * @class Dimension
 * @brief classe représentant deux données membres: la largeur et la hauteur 
 */
class Dimension {
    private:
        int largeur;
        int hauteur;

    public:
        /**
         * @brief <B>Construit</B> un objet Dimension
         * Le  constructeur crée un objet dimension par defaut avec une hauteur et une largeur nulles 
         */
        Dimension();

        /**
         * @brief Accesseur de l'attribut Largeur représentant la largeur du labyrinthe 
         * @return la largeur du labyrinthe
         */
        int  getLargeur() const;

        /**
         * @brief Accesseur de l'attribut Hauteur représentant la Hauteur du labyrinthe 
         * @return la hauteur du labyrinthe
         */
        int getHauteur() const;

        /**
         * @brief Mutateur de l'attribut Largeur représentant la largeur du labyrinthe 
         * @param L La nouvelle largeur 
         */
        void setLargeur(int L);

        /**
         * @brief Mutateur de l'attribut Hauteur représentant la hauteur du labyrinthe 
         * @param L La nouvelle hauteur
         */
        void setHauteur(int H);
    
};
  
#endif