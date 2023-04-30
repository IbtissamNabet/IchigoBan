/**
 * @file Position.h
 * @brief Module gérant les fonctionalités relatives à la position d'un composant dans le labyrinthe 
 */
#ifndef POSITION_H
#define POSITION_H


/**
 * @class Position 
 * @brief Classe contenant deux données membres représentant la position x et la position y.
 */

class Position {

    private :
    int x,y ;

    public: 

    /**
     * @brief <B>Construit</B> un objet Position.
     * Le  constructeur crée un objet Position par defaut (mets x et y a 0 );
     */
    Position();

    /**
     * @brief <B>Construit</B> un objet Position.
     * Le  constructeur crée un objet Position en donnant à x et y les valeurs de a et b;
     * @param a valeur à affecter à la position x
     * @param b valeur à affecter à la position y
     */  
    Position(int a, int b);

    /**
     * @brief Accesseur de l'attribut x
     * @return un entier représentant la position x
     */
    int getPosX() const ;

    /**
     * @brief Accesseur de l'attribut y
     * @return un entier représentant la position y
     */
    int getPosY() const ;

    /**
     * @brief Mutateur de l'attribut x
     * @param a un entier à affecter à x  
     */
    void setPosX( int a );

    /**
     * @brief Mutateur de l'attribut y
     * @param b un entier à affecter à y 
     */
    void setPosY( int b);
};

#endif 

