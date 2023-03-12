/**
 * @file Position.h
 
 * @brief Module gérant les fonctionalités relatives à la position d'un composant dans le labyrinthe 

*/
//_______________________________________________________________________________________________________________________________________________________________

#ifndef POSITION_H
#define POSITION_H


/**
 
 * @brief la class position contient deux paramétres membres étant la position de la colonne x et la ligne y  .

*/

class Position {
    private :
    int x,y ;
    public: 
    /**
    @brief <B>Construit</B> un objet Position.
    Le  constructeur crée un objet Position par defaut (mets x et y a 0 );
*/

    Position();
//___________________________________________________________________________________________________________________________________________________________________
    /**
    @brief <B>Construit</B> un objet Position.
    Le  constructeur crée un objet Position en donnant à x et y les valeurs de a et b;
*/  
    Position(int a, int b);
//___________________________________________________________________________________________________________________________________________________________________
/**
    @brief
    La fonction getPosX récupere l'indice de la  colonne X 
*/
    int getPosX() const ;
//___________________________________________________________________________________________________________________________________________________________________
/**
    @brief
    La fonction getPosY récupere l'indice de la ligne Y
*/
    int getPosY() const ;
//___________________________________________________________________________________________________________________________________________________________________
/**
    @brief
    La procedure setPosX remplace l'indice de la  colonne X par a 
    @param a:la nouvelle colonne 

*/

    void setPosX( int a );
//___________________________________________________________________________________________________________________________________________________________________
/**
    @brief
    La procedure setPosX remplace l'indice de la  cligne Y par b
    @param b:la nouvelle ligne

*/

    void setPosY( int b);

    





};




#endif 

