#include "sala.h"

sala::sala(int numerosala_, pelicula peliasignada, string tiposala_, int cantidadasientos_, int horaproyeccion_){
    /* Este es el constructor de las salas. Este recibe el numero que se le quiere asignar a la sala, la pelicula
     * que será proyectada en la sala, el tipo de la sala (2D o 3D), la cantidad de asientos que tendrá la sala (120 o 60),
     * y la hora de proyección de la película, y le asigna esta información a los atributos de la sala creada
     */

    this->numerosala=numerosala_;
    this->tiposala=tiposala_;
    this->cantidadasientos=cantidadasientos_;
    this->asientosdisp["General"]=cantidadasientos_/3;
    this->asientosdisp["Preferencial"]=cantidadasientos_/3;
    this->asientosdisp["Vibrosound"]=cantidadasientos_/3;
    this->pelienproyeccion=peliasignada;
    this->horaproyeccion=horaproyeccion_;

    // Aqui se crea el vector de vectores tipo char que guardará el estado de los asientos de la sala
    // (Si están ocupados o disponibles)
    creacionAsientos();
}

void sala::creacionAsientos(){
    /* Este método crea el vector de vectores de tipo char que almacenará el estado de los asientos.
     * Como se está creando la sala, todos los asientos están disponibles, por lo que todos los elementos del atributo
     * asientos serán el símbolo 'o', que significa disponible.
     * Este método revisa el numero de asientos de la sala, y dependiendo de esto crea los asientos, que cada fila de
     * asientos tendrá 10 asientos, y si la sala tiene 120 asientos entonces serán 12 filas, y si la sala tiene 60 asientos
     * entonces serán 6 filas.
     */
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
    /* Este método devuelve o retorna el numero de la sala
     */
    return this->numerosala;
}

int sala::obtenerHoraproyeccion(){
    /* Este método devuelve o retorna la hora de proyección de la película que se proyecta en la sala
     */
    return this->horaproyeccion;
}

int sala::obtenerCantidadasientos(){
    /* Este método devuelve o retorna el numero total de asientos de la sala
     */
    return this->cantidadasientos;
}

map<string, int> sala::obtenerNumasientosdisp(){
    /* Este método devuelve o retorna un mapa con la cantidad de asientos disponibles dependiendo de la zona
     * Las claves del mapa son un string con el nombre de la zona (General, Preferencial o Vibrosound), y el valor será
     * un entero con la cantidad de asientos disponibles de la zona
     */
    return this->asientosdisp;
}

int sala::obtenerTotalasientosdisp(){
    /* Este método devuelve o retorna el numero total de asientos disponibles en la sala.
     * El método hace uso del mapa de asientos disponibles por zona, y suma los asientos disponibles para obtener
     * la cantidad total.
     */
    int totalasientosdisp=0;
    for (auto pareja : this->obtenerNumasientosdisp()){
        totalasientosdisp+=pareja.second;
    }
    return totalasientosdisp;
}

string sala::obtenerTiposala(){
    /* Este método devuelve o retorna un string con el tipo de la sala (2D o 3D)
     */
    return this->tiposala;
}

pelicula sala::obtenerPelienproyeccion(){
    /* Este método devuelve o retorna un objeto película que corresponde a la película que se proyecta en la sala
     */
    return this->pelienproyeccion;
}

void sala::modificarAsientosdisp(int asientosgen, int asientospref, int asientosvibro){
    /* Este método recibe tres enteros correspondientes a la nueva cantidad de asientos disponibles de cada zona, y estos
     * numeros se los asigna como valor de cada clave del mapa de asientos disponibles de la sala, dependiendo de la zona
     */
    this->asientosdisp["General"]=asientosgen;
    this->asientosdisp["Preferencial"]=asientospref;
    this->asientosdisp["Vibrosound"]=asientosvibro;
}

void sala::imprimirAsientos(){

    /* Este método imprime la visualización de los asientos de la sala. Imprime también una guía de el nombre de las filas
     * y el numero de los asientos, y muestra el estado del asiento, si aparece 'o' es porque el asiento está disponible,
     * y si aparece 'x' es porque el asiento está ocupado.
     */

    // Se asigna la letra de la última fila de asientos (que es una letra mayúscula y será visualizada en la parte
    // superior de la visualización de asientos
    char letra;
    letra=(char)((this->cantidadasientos/10)+64);

    cout << "\nA continuacion se muestran los asientos disponibles en la sala" << endl;
    cout << "x: Asiento ocupado         o: Asiento disponible\n" << endl;

    // Se itera con respecto al numero de filas de la sala
    for (unsigned int i=0; i<this->asientos.size(); i++){

        if (i==0){   // Se imprime la guía con los numeros de los asientos
            cout << "      ";
            for (int j=this->asientos[i].size(); j>=1; j--){
                cout << j << "  ";
            }
            cout << endl;
        }
        cout << " " << letra << "     ";  // Por cada renglón o fila se imprime la letra guía de la fila
        // Se itera con respecto a los asientos de cada fila
        for (int j=this->asientos[i].size()-1; j>=0; j--){
            cout << asientos[i][j] << "  ";    // Se imprime el estado del asiento
        }
        letra--;   // Se modifica la letra de guía de forma descendente hasta llegar a la "A"
        cout << endl;
    }
    cout << "       ----------PANTALLA----------\n" << endl;
}

vector<vector<char>> sala::obtenerAsientos(){
    /* Este método devuelve o retorna el vector de vectores de tipo char que guarda el estado de los asientos de la sala
     */
    return this->asientos;
}

void sala::asignarAsientos(vector<vector<char>> actualizado){
    /* Este método recibe un vector de vectores de tipo char, que corresponde a los asientos actualizados, y estos asientos
     * son entregados como atributo de la sala, para actualizar la variable que guarda el estado de los asientos
     */
    this->asientos=actualizado;
}

void sala::actualizarCantasientos(){
    /* Este método actualiza la cantidad de asientos disponibles por zona. Para esto, itera sobre su vector de vectores
     * que guarda el estado de los asientos, y dependiendo de la posición de la fila que esté analizando, le suma asientos
     * disponibles a las variables "contdisp...". Estas variables al final guardarán la cantidad de asientos disponibles
     * de cada zona, y luego serán entregadas como valor de cada zona en el mapa de asientos disponibles por zona
     */


    vector<vector<char>> asientos=this->asientos; // Se guarda el vector de asientos de la sala

    // Se inicializan las variables que guardarán la cantidad de asientos disponibles
    int contdisp1=0;
    int contdisp2=0;
    int contdisp3=0;

    // Se itera con respecto a la cantidad de filas de la sala
    for (unsigned int i=0; i<asientos.size(); i++){
        // Se itera con respecto a la cantidad de asientos de cada fila de la sala
        for (unsigned int j=0; j<asientos[i].size(); j++){

            // Analizamos si la fila corresponde a la última zona de la sala, la más superior, la zona Vibrosound
            if (i<(unsigned int)(this->cantidadasientos)/30){
                if (asientos[i][j]=='o'){   // Si se encuentra que el asiento está disponible...
                    contdisp1++;            // Se suma 1 a la cantidad de asientos disponibles
                }

            }
            // Analizamos si la fila corresponde a la zona del medio de la sala, la zona Preferencial
            else if (i>=(unsigned int)(this->cantidadasientos)/30 && i<(unsigned int)(this->cantidadasientos)/15){
                if (asientos[i][j]=='o'){   // Si se encuentra que el asiento está disponible...
                    contdisp2++;            // Se suma 1 a la cantidad de asientos disponibles
                }
            }
            // Analizamos si la fila corresponde a la primera zona de la sala, la más cerca a la pantalla, la zona General
            else{
                if (asientos[i][j]=='o'){   // Si se encuentra que el asiento está disponible...
                    contdisp3++;            // Se suma 1 a la cantidad de asientos disponibles
                }
            }

        }
    }
    // Le asignamos la cantidad de asientos disponibles actualizada a cada zona, en el mapa de asientos disponibles
    this->asientosdisp["General"]=contdisp3;
    this->asientosdisp["Preferencial"]=contdisp2;
    this->asientosdisp["Vibrosound"]=contdisp1;
}




