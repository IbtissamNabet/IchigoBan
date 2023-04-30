/**
 * @file Jeu.h
 * @brief Module gérant les fonctionalités relatives à la création, au déroulement et à la terminaison d'une partie .
 * <br> une partie/Jeu contient un tableau de fraises (fraises), un gardien (gard), et un niveau (niv)
*/

#ifndef _JEU_H
#define _JEU_H

#include "Niveau.h"
#include "Fraise.h"
#include "Gardien.h"

/**
 * @class Jeu
 * @brief La classe Jeu contient un tableau de Fraise (fraises), un Gardien (gard), et un Niveau (niv)
 */

class Jeu {

private :
    
    Fraise * fraises;
	  
public :
    Gardien gard;
    Niveau niv;

    /**
     * @brief <B>Construit</B> un Jeu
     * <br> Le Jeu ne contiennant aucunes fraises
     */
    Jeu();

    /**
     * @brief <B>Detruit</B> un objet Labyrinthe .
     * <br> Le destucteur désaloue le tableau de Fraises et détruit tout les autres données membres
     */    
    ~Jeu();

    /**
     * @brief Accesseur de l'attribut niv représentant le niveau de la partie
     * @return un objet de type Niveau
     */    
    const Niveau & getNiveau () const;  

    /**
     * @brief Accesseur de l'attribut fraises représentant le tableau de fraises de la partie
     * @return un lien vers Fraise
     */                      
    Fraise* getFraise () const;  

    /**
     * @brief Accesseur de l'attribut gard représentant le gardien dans la partie
     * @return un objet de type Gardien
     */                               
    Gardien getGardien() const;

    /**   
     * @brief la fonction setNiveau modifie le niveau du jeu selon l'entier entré en paramètre
     * @param n: entier correspondant au numéro du niveau
     */
    void setNiveau(int n);

    /**   
     * @brief Fonction qui gère les déplacements des éléments au cours du jeu
     * @param touche caractère 'd' pour droite, 'g' pour gauche, 'h' haut pour haut et 'b' pour bas
     */    
    void toucheClavier(const char touche);

    /**   
     * @brief vérifie si la partie est terminée
     * @return tous les emplacements cibles contiennent une fraise
     */
    bool partie_terminee();

    /**   
     * @brief vérifie si une fraise a atteint un emplacement cible
     * @param f la fraise dont on veut vérifier si elle est placée
     */   
    bool placee(Fraise f);//renvoie true si la position de la fraise entrée en parametre correspond à un emplacement cible
    
    /**   
     * @brief Fonction permettant de rejouer la partie 
     * <br> le gardien est les fraises reviennent à leur position initiale
     */    
    void rejouer_partie();
};
#endif