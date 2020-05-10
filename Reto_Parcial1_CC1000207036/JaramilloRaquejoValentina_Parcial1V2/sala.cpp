#include "sala.h"

sala::sala(int numerosala_, pelicula peliasignada, string tiposala_, int cantidadasientos_, int horaproyeccion_){

    this->numerosala=numerosala_;
    this->tiposala=tiposala_;
    this->cantidadasientos=cantidadasientos_;
    this->asientosdisp["General"]=cantidadasientos_/3;
    this->asientosdisp["Preferencial"]=cantidadasientos_/3;
    this->asientosdisp["Vibrosound"]=cantidadasientos_/3;
    this->pelienproyeccion=peliasignada;
    this->horaproyeccion=horaproyeccion_;
    creacionAsientos();
}

void sala::creacionAsientos(){

    if (this->cantidadasientos==120){
        vector<char> fila(10, 'o');
        vector<vector<char>> asientos_(12, fila);
        this->asientos=asientos_;
    }
    else{
        vector<char> fila(10, 'o');
        vector<vector<char>> asientos_(6, fila);
        this->asientos=asientos_;
    }
}
int sala::obtenerNumerosala(){
    return this->numerosala;
}
int sala::obtenerHoraproyeccion(){
    return this->horaproyeccion;
}
int sala::obtenerCantidadasientos(){
    return this->cantidadasientos;
}
map<string, int> sala::obtenerNumasientosdisp(){
    return this->asientosdisp;
}

int sala::obtenerTotalasientosdisp(){
    int totalasientosdisp=0;
    for (auto pareja : this->obtenerNumasientosdisp()){
        totalasientosdisp+=pareja.second;
    }
    return totalasientosdisp;
}
string sala::obtenerTiposala(){
    return this->tiposala;
}
pelicula sala::obtenerPelienproyeccion(){
    return this->pelienproyeccion;
}

void sala::modificarAsientosdisp(int asientosgen, int asientospref, int asientosvibro){
    this->asientosdisp["General"]=asientosgen;
    this->asientosdisp["Preferencial"]=asientospref;
    this->asientosdisp["Vibrosound"]=asientosvibro;
}
void sala::imprimirAsientos(){
    char letra='J';
    cout << "\nA continuacion se muestran los asientos disponibles en la sala" << endl;
    cout << "x: Asiento ocupado         o: Asiento disponible\n" << endl;

    for (unsigned int i=0; i<this->asientos.size()+1; i++){
        if (i==0){
            cout << "      ";
            for (int j=this->asientos[i-1].size(); j>=1; j--){
                cout << j << "  ";
            }
        }
        cout << " " << letra << "    ";
        for (unsigned int j=0; j<this->asientos[i-1].size(); j++){
            cout << asientos[i][j] << " ";
        }
        letra--;
        cout << endl;
    }
}
vector<vector<char>> sala::obtenerAsientos(){
    return this->asientos;
}
void sala::asignarAsientos(vector<vector<char>> actualizado){
    this->asientos=actualizado;
}
void sala::actualizarCantasientos(){
    vector<vector<char>> asientos=this->asientos;

    int contocupados=0;
    for (unsigned int i=0; i<asientos.size(); i++){
        for (unsigned int j=0; j<asientos[i].size(); j++){
            if (i>=0 && i<(unsigned int)(this->cantidadasientos)/30){

            }
            else if (i>=(unsigned int)(this->cantidadasientos)/30 && i<(unsigned int)(this->cantidadasientos)/60){

            }

        }
    }

}



