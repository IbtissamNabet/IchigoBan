#ifndef DIMENSION_H
#define DIMENSION_H

class Dimension {
    private:
        float largeur;
        float hauteur;

    public:
        Dimension();
        float getLargeur() const;
        float getHauteur() const;
        void setLargeur(float L);
        void setHauteur(float H);
    
};
  
#endif