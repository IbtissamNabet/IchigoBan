
#include "Position.h"

    Position::Position(){
        x=y=0;
    }

    Position::Position(int a, int b): x(a), y(b){}

    int Position::getPosX() const{
        return x ;
    }
    int Position::getPosY() const{
        return y;
    }
    void Position::setPosX( int a ){
        x=a;

    }
    void Position::setPosY( int b){
        y=b;
    }