/* Esta clase representa las salas de cine de mi simulación. Como atributos tiene su numero de sala, su pelicula en
 * proyección, su tipo de sala (2D o 3D), y sus asientos, es decir, un vector de vectores de tipo char que almacena el estado
 * de los asientos de la sala. Además de estos atributos, también tiene otros como la cantidad total de asientos (120 o 60),
 * la hora de proyección de la película, y finalmente tiene un mapa que almacena la cantidad de asientos disponibles de cada zona.
 * Este mapa tiene como clave un string con el nombre de la zona (General, Preferencial o Vibrosound) y como valor tiene un entero
 * que representa el numero de asientos disponibles.
 *
 * Cada sala esta distribuida dependiendo de sus filas, las filas correspondientes al primer tercio de la sala, las más cercanas
 * a la pantalla, son la zona General. Las del medio son la zona Preferencial, y las más alejadas de la pantalla, el último tercio
 * de la sala, es la zona Vibrosound.
 *
 * La documentación o los comentarios de cada método se encuentran dentro del archivo .cpp de la clase, dentro de cada una
 * de sus implementaciones o definiciones.
 */

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
