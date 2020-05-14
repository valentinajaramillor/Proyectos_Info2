#include "pelicula.h"

pelicula::pelicula(){
}

void pelicula::asignarInformacion(int ID_, string nombre_, string genero_, int duracionmin_, int clasificacion_){
    /* Este método recibe la información de la película y se la asigna a sus atributos
     */
    this->ID=ID_;
    this->nombre=nombre_;
    this->genero=genero_;
    this->duracionmin=duracionmin_;
    this->clasificacion=clasificacion_;
}
int pelicula::obtenerID(){
    /* Este método retorna o devuelve el ID de la pelicula
     */
    return this->ID;
}

string pelicula::obtenerNombre(){
    /* Este método retorna o devuelve el nombre de la pelicula
     */
    return this->nombre;
}

string pelicula::obtenerGenero(){
    /* Este método retorna o devuelve el genero de la pelicula
     */
    return this->genero;
}

int pelicula::obtenerDuracionmin(){
    /* Este método retorna o devuelve la duracion en minutos de la pelicula
     */
    return this->duracionmin;
}

int pelicula::obtenerClasificacion(){
    /* Este método retorna o devuelve la clasificación de la pelicula
     */
    return this->clasificacion;
}
