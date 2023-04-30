/**
 * @file Gardien.h
 * @brief Module gérant les fonctionalités relatives à la création et aux déplacements du gardien (joueur) dans un labyrinthe 
 * dont le but est de pousser les fraises vers leurs emplacements cibles.
 */

//_______________________________________________________________________________________________________________________________________________________________
#ifndef GARD_
#define GARD_
#include"Position.h"
#include"Labyrinthe.h"

/**
 * @class Gardien
 * @brief classe representant le gardien, elle contient la position du gardien
 */
class Gardien {
    
public :
    Position pos_gardien; 

    /**
     * @brief <B>Construit</B> un objet Gardien.
     * Le  constructeur crée un objet Gardien par defaut à la position (1,1) d'un labyrinthe
     */
    Gardien();

    /**
     * @brief Accesseur de l'attribut pos_Gardien
     * @return la position du Gardien
     */
    Position  getPositionGardien()const;

    /**
     * @brief Mutateur de l'attribut pos_Gardien
     * @param p: la nouvelle position du Gardien 
     */
    void  setPositionGardien(const Position & p);

    /**
     * @brief Permet de déplacé le gardien d'une case vers la gauche dans le labyrinthe
     * @param l objet de type Labyrinthe 
     */
    void gauche(const Labyrinthe & l);

    /**
     * @brief Permet de déplacé le gardien d'une case vers la droite dans le labyrinthe
     * @param l objet de type Labyrinthe 
     */
    void droite(const Labyrinthe & l );

    /**
     * @brief Permet de déplacé le gardien d'une case vers le haut dans le labyrinthe
     * @param l objet de type Labyrinthe 
     */
    void haut(const Labyrinthe & l );

    /**
     * @brief Permet de déplacé le gardien d'une case vers le bas dans le labyrinthe
     * @param l objet de type Labyrinthe 
     */
    void bas(const Labyrinthe &l);

    void testRegression(const Labyrinthe & l);

};

#endif
