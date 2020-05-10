#ifndef SALA_H
#define SALA_H

#include "pelicula.h"
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class sala
{
private:
    int numerosala;
    pelicula pelienproyeccion;
    string tiposala;
    vector<vector<char>> asientos;
    int cantidadasientos;
    map<string, int> asientosdisp;
    int horaproyeccion;

public:
    sala(int numerosala_, pelicula peliasignada, string tiposala_, int cantidadasientos_, int horaproyeccion_);
    void creacionAsientos();
    int obtenerNumerosala();
    int obtenerHoraproyeccion();
    int obtenerCantidadasientos();
    map<string, int> obtenerNumasientosdisp();
    int obtenerTotalasientosdisp();
    void modificarAsientosdisp(int asientosgen, int asientospref, int asientosvibro);
    string obtenerTiposala();
    pelicula obtenerPelienproyeccion();
    void imprimirAsientos();
    vector<vector<char>> obtenerAsientos();
    void asignarAsientos(vector<vector<char>> actualizado);
    void actualizarCantasientos();

};

#endif // SALA_H
