/* Esta clase representa las peliculas de mi simulación. Como atributos tiene su ID, su nombre, su genero, su duracion en minutos,
 * y su clasificacion.
 *
 * La documentación o los comentarios de cada método se encuentran dentro del archivo .cpp de la clase, dentro de cada una
 * de sus implementaciones o definiciones.
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
