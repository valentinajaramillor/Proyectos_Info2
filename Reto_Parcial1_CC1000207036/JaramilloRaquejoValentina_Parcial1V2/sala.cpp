#include "sala.h"

sala::sala(int numerosala_, pelicula peliasignada, string tiposala_, int cantidadasientos_){

    this->numerosala=numerosala_;
    this->tiposala=tiposala_;
    this->cantidadasientos=cantidadasientos_;
    this->pelienproyeccion=peliasignada;

}

void sala::creacionAsientos(){
    vector<int> fila(10, 0);
    if (this->cantidadasientos==120){
        vector<vector<int>> asientos_(12, fila);
        this->asientos=asientos_;
    }
    else{
        vector<vector<int>> asientos_(6, fila);
        this->asientos=asientos_;
    }
}
