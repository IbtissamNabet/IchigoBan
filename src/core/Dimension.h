#ifndef DIMENSION_H
#define DIMENSION_H

class Dimension {
    private:
        int largeur;
        int hauteur;

    public:
        Dimension();
        int  getLargeur() const;
        int getHauteur() const;
        void setLargeur(int L);
        void setHauteur(int H);
    
};
  
#endif