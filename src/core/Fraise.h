/**
 * @file Fraise.h
 * @brief Module gérant les fonctionalités relatives à la création et aux déplacement des fraises par le gardien dans un labyrinthe
 */
#ifndef FRAISE_H
#define FRAISE_H

#include"Labyrinthe.h"
#include"Position.h"
#include"Gardien.h"



/**
 * @class Fraise
 * @brief classe representant la fraise, elle contient la position de la fraise 
 */

class Fraise {

private:
    Position pos_Fraise ;

public:

    /**
     * @brief <B>Construit</B> un objet Fraise.
     * Le  constructeur crée un objet Fraise par defaut à la position (1,1) d'un labyrinthe
     */
    Fraise();

    /**
     * @brief Accesseur de l'attribut pos_Fraise
     * @return la position de la fraise
     */
    Position  getPositionFraise()const;

    /**
     * @brief Mutateur de l'attribut pos_Fraise
     * @param p: la nouvelle position de la fraise  
     */
    void setPositionFraise(const Position & p);

    /**
     * @brief Permet de déplacé la fraise d'une case vers la gauche dans le labyrinthe
     * @param l objet de type Labyrinthe 
     * @param g objet Gardien pour connaitre la position du gardien par rapport à la fraise
     */
    void gauche(const Labyrinthe & l,const Gardien & g);

    /**
     * @brief Permet de déplacé la fraise d'une case vers la droite dans le labyrinthe
     * @param l objet de type Labyrinthe 
     * @param g objet Gardien pour connaitre la position du gardien par rapport à la fraise
     */
    void droite(const Labyrinthe & l,const Gardien & g);

    /**
     * @brief Permet de déplacé la fraise d'une case vers le haut dans le labyrinthe
     * @param l objet de type Labyrinthe 
     * @param g objet Gardien pour connaitre la position du gardien par rapport à la fraise
     */
    void haut(const Labyrinthe & l,const Gardien & g);

    /**
     * @brief Permet de déplacé la fraise d'une case vers le bas dans le labyrinthe
     * @param l objet de type Labyrinthe 
     * @param g objet Gardien pour connaitre la position du gardien par rapport à la fraise
     */
    void bas(const Labyrinthe &l,const Gardien & g);

    void testRegression(const Labyrinthe & l);

};


#endif
