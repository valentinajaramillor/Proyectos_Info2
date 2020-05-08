#include "pelicula.h"

pelicula::pelicula(){
}

void pelicula::asignarInformacion(int ID_, string nombre_, string genero_, int duracionmin_, int clasificacion_){
    this->ID=ID_;
    this->nombre=nombre_;
    this->genero=genero_;
    this->duracionmin=duracionmin_;
    this->clasificacion=clasificacion_;
}
int pelicula::obtenerID(){
    return this->ID;
}

string pelicula::obtenerNombre(){
    return this->nombre;
}

string pelicula::obtenerGenero(){
    return this->genero;
}

int pelicula::obtenerDuracionmin(){
    return this->duracionmin;
}

int pelicula::obtenerClasificacion(){
    return this->clasificacion;
}
