#ifndef SALA_H
#define SALA_H

#include "pelicula.h"
#include <iostream>
#include <vector>

using namespace std;

class sala
{
private:
    int numerosala;
    pelicula pelienproyeccion;
    string tiposala;
    vector<vector<int>> asientos;
    int cantidadasientos;

public:
    sala(int numerosala_, pelicula peliasignada, string tiposala_, int cantidadasientos_);
    void creacionAsientos();
    void obtenerNumerosala();
};

#endif // SALA_H
