/*
 */

#ifndef PELICULA_H
#define PELICULA_H

#include <iostream>
#include <string>

using namespace std;

class pelicula
{
private:
    int ID;
    string nombre;
    string genero;
    int duracionmin;
    int clasificacion;

public:
    pelicula();
    void asignarInformacion(int ID_, string nombre_, string genero_, int duracionmin_, int clasificacion_);
    int obtenerID();
    string obtenerNombre();
    string obtenerGenero();
    int obtenerDuracionmin();
    int obtenerClasificacion();

};

#endif // PELICULA_H
