//A01644376
//Edwin Mojarras
#ifndef VIDEO_H
#define VIDEO_H
#include <iostream>
//clase abstracta padre

class Video
{

public:
    virtual std::string getGenero()=0;
    virtual float getCalificacion()=0;
    virtual void setCalificacion(std::string id, float calificacion)=0;
    // virtual void imprime() =0;
    virtual std::string getId()=0;

     friend std::ostream& operator<<(std::ostream& os, const Video& video) {
        return os;
    }
};


#endif