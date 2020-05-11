/* Abrir para leer la primera parte de la documentacion y consideraciones importantes sobre el programa
 *
 * Carpeta build del programa: "build-JaramilloRaquejoValentina_Parcial1V2-Desktop_Qt_5_12_2_MinGW_32_bit-Debug"
 *
 * RESUMEN DE LA ESTRUCTURA Y CONSIDERACIONES
 * Este programa cumple las funciones de un simulador de salas de cine, donde podemos encontrar dos perfiles, uno de
 * administrador y otro de usuario. El administrador puede registrar nuevas peliculas, puede registrar nuevos
 * precios para los asientos, y puede generar un reporte con las ventas del día. Las peliculas serán asignadas
 * a salas de cine dentro del programa. Cada pelicula corresponde a un objeto, o una clase, que como atributos tiene su
 * informacion general, como ID (un numero que asigna el administrador, unico para cada pelicula), su nombre, su genero, su
 * clasificacion y su duracion en minutos, asi como unos métodos que sirven para obtener y asignar esta información (en el
 * header de la clase se podrá encontrar mas documentación acerca de la clase). Las salas de cine tambien son un objeto o una
 * clase, y por medio de estás se gestionará gran parte de la información del cine. Las salas de cine tienen como atributo
 * su pelicula en proyeccion, su numero de sala, su hora de proyeccion, su numero de asientos total, asi como su numero de
 * asientos por tipo de zona (general, preferencial y vibrosound), y un vector de vectores con la visualizacion de los asientos
 * ocupados y disponibles (más información acerca de esta clase la encontrará en el header de la clase). El simulador de salas de
 * cine, el programa principal, guarda la informacion de las peliculas y las salas de cine por medio de un mapa, que como clave
 * tiene el ID de la pelicula, y como valor tiene un vector de salas donde se proyectará.
 *
 * La información de las peliculas de encuentra en un archivo dentro de la carpeta build del programa, con el nombre
 * "info_peliculas". La informacion de los precios de los asientos y sus nombres se encuentra en un archivo en la carpeta build
 * del programa, y este archivo se llama "precio_asientos". Y finalmente, cada sala guardará su información de asientos ocupados
 * y disponibles por medio de un archivo en la carpeta build, que se llamará "sala_..." y en vez de los tres puntos, tendrá el
 * numero de la sala.
 *
 * En estos archivos donde se guarda la información de los asientos, podrá observar que los asientos disponibles son representados
 * por 'o' y los asientos ocupados estan representados por una 'x'. Todas las salas están distribuidas de acuerdo a tres zonas.
 * Es decir, en el archivo de la sala, debajo del ultimo renglón está la "PANTALLA", y de ahí para arriba se guardan las filas
 * en tres grupos, el grupo de filas más cercano a la pantalla se llama la zona "General", el grupo del medio se llama la zona
 * "Preferencial" y el grupo de mas arriba se llama la zona "Vibrosound". Cuanto más arriba, más cara será la boleta. Estos precios
 * los puede asignar el administrador.
 *
 * INFORMACIÓN IMPORTANTE: CLAVE ADMINISTRADOR- La clave del administrador es "clavesudo123" sin las comillas. Esta clave se
 * encuentra guardada en formato codificado en el archivo de la carpeta build  con nombre del archivo: "clave_admin". El formato
 * de codificacion usado fue el primer metodo de codificacion de la practica 3, con semilla de codificación 4.
 */

#include "pelicula.h"
#include "sala.h"
#include <iostream>
#include <string>
#include <fstream>
#include <ios>
#include <cmath>
#include <vector>
#include<limits>
#include <map>

using namespace std;

//Declaración de funciones, su implementacion y definición las encontrará en la parte de abajo, despues del main
// En cada funcion encontrará su documentación (documentación de métodos se encuentra en la definición de los métodos)
short int opcini();
short int opcsudo();
short int opcuser(string&);
void codclave(string&);
bool validsudo(string&, void (string &));
bool ingresouser(string &cedulauser);
void registropeliculas(map<int, vector<sala>>&);
void guardarpeliculas(map<int, vector<sala>>);
void sacarinfocine(map<int, vector<sala>>&);
void registroprecios(map<string, int>&);
void guardarprecios(map<string, int>);
void sacarprecios(map<string, int>&);
vector<int> opcionespeli(map<int, vector<sala>>);
int eleccionpelicula(map<int, vector<sala>>, vector<int> (map<int, vector<sala>>));
int eleccionsalayhora(map<int, vector<sala>>, int);
void eleccionasiento(map<int, vector<sala>>&);
void guardarsalas(map<int, vector<sala>>);
void sacarsalas(map<int, vector<sala>>&);
void eleccionasiento(map<int, vector<sala>> &cine, int IDpelicula, int numerosala, bool (int, sala, map<string, int>), map<string, int>);
bool pagodeboleta(int, sala, map<string, int>);
void imprimirPrecios(map<string, int>, sala);

int main()
{
    //Variables para controlar los ciclos de funcionamiento de la simulacion y los perfiles
    bool cinein=true;
    bool sudoin=true;
    bool userin;
    //Variables que guardarán las opciones escogidas por el usuario en los menus
    short int opci;
    short int opcs;
    short int opcu;
    //Strings auxiliares para la codificación y decodificación de la clave de administrador
    // Y de la clave ingresada por el usuario que quiere ingresar como administrador
    string original="";
    string poscontra="";

    // Clave: ID de pelicula - Valor: Vector con salas donde se proyecta
    // Aqui se guardarán las peliculas en proyeccion y sus salas correspondientes
    map<int, vector<sala>> cine;

    // Clave: Tipo de asiento - Valor: Costo de boleta.
    // Aqui se guardarán los precios de los asientos.
    map<string, int> precioasientos;

    while (cinein){ //Comienza el funcionamiento de la simulación

        // Se borra la información del cine para que sea actualizada por las funciones "sacarinfocine" y "sacarsalas"
        cine.clear();

        // Se borra la información de los precios para que sea actualizada por la función "sacarprecios"
        precioasientos.clear();

        // Funciones para sacar la información de los archivos y guardarla en las variables del programa
        // Detalles especificados dentro de las funciones
        sacarinfocine(cine);
        sacarsalas(cine);
        sacarprecios(precioasientos);

        opci=opcini();    // El usuario escoge su perfil

        if (opci==1){
            sudoin=validsudo(poscontra,codclave);  // La funcion "validsudo" pide la contraseña de admin y la valida

            while (sudoin){   // Si cumple con la contraseña, empieza el funcionamiento en el perfil "administrador"
                opcs=opcsudo();

                if (opcs==1){
                    cout << "\n...REGISTRO DE PELICULAS..." << endl;

                    // Se registran las peliculas en la variable del cine
                    registropeliculas(cine);
                    // Se guarda la información en los archivos
                    guardarpeliculas(cine);
                    guardarsalas(cine);
                    continue;
                }
                else if (opcs==2){
                    cout << "\n...MODIFICACION DE PRECIOS..." << endl;

                    // Se registran los nuevos precios de los asientos
                    registroprecios(precioasientos);
                    // Se guarda la información en el archivo de precios
                    guardarprecios(precioasientos);
                    continue;
                }
                else {
                    cout << "\n...HASTA LUEGO, ADMINISTRADOR..." << endl;
                    sudoin=false;
                }
            }
        }
        else if (opci==2){
            string cedulauser="";  // Aqui se guardará la cedula del usuario para identificarlo

            userin=ingresouser(cedulauser); // Se pide la cedula

            while (userin){
                opcu=opcuser(cedulauser);  // Se entregan las opciones de funciones y se recoge la decisión

                if (opcu==1){
                    cout << "\n...ELECCION DE PELICULA..." << endl;

                    // El usuario escoge la pelicula que desea
                    int IDpeliescogida=eleccionpelicula(cine, opcionespeli);

                    if (IDpeliescogida==-1){  // Se sale del ciclo si el usuario ingresa -1
                        continue;
                    }
                    // El usuario escoge la sala que desea, de las salas con disponibilidad
                    int salaescogida=eleccionsalayhora(cine, IDpeliescogida);

                    if (salaescogida==-1){   // Se sale del ciclo si el usuario ingresa -1
                        continue;
                    }

                    // Se le muestra al usuario los asientos y se le pone a escoger, validando que el asiento esté disponible
                    // Se procede a usar la función "pagodeboleta" para que se ingrese el dinero y se den las devueltas
                    eleccionasiento(cine, IDpeliescogida, salaescogida, pagodeboleta, precioasientos);

                    // Se guarda la información actualizada de los asientos en la informacion de las peliculas y las salas
                    guardarpeliculas(cine);
                    guardarsalas(cine);
                }
                else if (opcu==2){
                    cout << "\n...HASTA LUEGO, USUARIO..." << endl;
                    userin=false;
                }
            }
        }
        else {
            cout << "\n...VUELVA PRONTO..." << endl;
            cinein=false;
        }
    }
    return 0;
}

// Implementación y definicion de funciones
// Dentro de cada función se encuentran los comentarios
short int opcini(){
    /* Esta funcion imprime el menu inicial del programa y devuelve un entero con la opcion escogida,
     * validando que la opción si sea valida
     */
    short int opcini;
    cout << "\nSIMULACION DE SALAS DE CINE\n" << endl;
    cout << "\nBienvenido, que desea hacer?\n" << endl;
    cout << "1. Ingresar como administrador." << endl;
    cout << "2. Ingresar como usuario." << endl;
    cout << "3. Salir.\n" << endl;
    cout << "Por favor, escriba SOLO el numero de la opcion que desea: ";
    cin >> opcini;
    while((!cin) || opcini<1 || opcini>3)
    {
        cout << "\nAsegurese de ingresar una opcion valida (un numero entero positivo entre 1 y 3): ";
        cin.clear();
        cin.ignore();
        cin >> opcini;
    }
    return opcini;
}

short int opcsudo(){
    /* Esta funcion imprime el menu interno del administrador y devuelve un entero con la opcion escogida,
     * validando que la opción si sea valida
     */
    short int opcsudo;
    cout << "\nBienvenido administrador, que desea hacer?\n" << endl;
    cout << "1. Registrar peliculas." << endl;
    cout << "2. Modificar precios de boleteria (precio por asiento)." << endl;
    cout << "3. Generar reporte de venta de boleteria del dia." << endl;
    cout << "4. Salir.\n" << endl;
    cout << "Por favor, escriba SOLO el numero de la opcion que desea: ";
    cin >> opcsudo;
    while((!cin) || opcsudo<1 || opcsudo>4)
    {
        cout << "\nAsegurese de ingresar una opcion valida (un numero entero positivo 1, 2, 3 o 4): ";
        cin.clear();
        cin.ignore();
        cin >> opcsudo;
    }
    return opcsudo;
}

short int opcuser(string &cedulauser){
    /* Esta funcion imprime el menu interno del perfil usuario y devuelve un entero con la opcion escogida,
     * validando que la opción si sea valida. Además, se le da la bienvenida al usuario, imprimiendo
     * su numero de cedula guardado en "cedulauser"
     */
    short int opcuser;
    cout << "\nBienvenido usuario " << cedulauser << ", que desea hacer?\n" << endl;
    cout << "1. Comprar boleta." << endl;
    cout << "2. Salir.\n" << endl;
    cout << "Por favor, escriba SOLO el numero de la opcion que desea: ";
    cin >> opcuser;
    while((!cin) || opcuser<1 || opcuser>2)
    {
        cout << "\nAsegurese de ingresar una opcion valida (un numero entero positivo entre 1 y 3): ";
        cin.clear();
        cin.ignore();
        cin >> opcuser;
    }
    return opcuser;
}

void codclave(string &poscontra){
    /* Esta funcion codifica la contraseña que es ingresada por la persona que desea entrar al perfil administrador.
     * El string con la información codificada será comparado en otra función llamada "validsudo" son la contraseña del admin.
     * La contraseña del admin es leida desde el archivo "clave_admin".
     *
     * Esta función codifica por medio del método 1 de la practica 3, con semilla de codificación 4.
     */
    int semilla=4,n,max,i2;
    string line="";
    string binposcontra="";
    char auxhex[3]="";
    string auxdec="";
    string auxbin;

    for (unsigned int i=0; i<(poscontra.length()); i++){
        // Aqui pasamos la contraseña ingresada a numeros binarios, paa ser guardada en la variable string "binposcontra"
        auxbin="";
        n=(int)poscontra[i];
        itoa(n,auxhex,16);
        if (n<16){
            auxhex[1]=auxhex[0];
            auxhex[0]=48;
        }
        n=(int)auxhex[0]-48;
        for (int j=0; j<4; j++){
            auxbin=(char)((n%2)+48)+auxbin;
            n=n/2;
        }
        binposcontra=binposcontra+auxbin;
        if ((int)auxhex[1]>=97 && (int)auxhex[1]<=102){
            n=(int)auxhex[1]-87;
        }
        else {
            n=(int)auxhex[1]-48;
        }
        auxbin="";
        for (int j=0; j<4; j++){
            auxbin=(char)((n%2)+48)+auxbin;
            n=n/2;
        }
        binposcontra=binposcontra+auxbin;
    }

    poscontra=binposcontra;
    max=binposcontra.length()/semilla;
    i2=0;

    // A continuacion se realiza la codificación, iterando en los caracteres de binposcontra y codificandolos de acuerdo
    // al metodo 1 de la practica 3, con semilla de codificación 4
        int cont0=0;
        int cont1=0;

        for (int i=0; i<=max; i++){
            i2=i*semilla;
            cont0=0;
            cont1=0;
            if (i==0){
                for (int j=0; j<semilla; j++){
                    if (binposcontra[i2+j]==48)
                        poscontra[i2+j]=49;
                    else
                        poscontra[i2+j]=48;
                }
            }

            else {
                for (int j=0; j<semilla; j++){
                    if (binposcontra[(i2-semilla)+j]==48)
                        cont0++;
                    else
                        cont1++;
                }
                if (cont0==cont1){
                    for (int j=0; j<semilla; j++){
                        if (binposcontra[i2+j]==48)
                            poscontra[i2+j]=49;
                        else
                            poscontra[i2+j]=48;
                    }
                }
                else if (cont0>cont1){
                    for (int j=1; j<semilla; j+=2){
                        if (binposcontra[i2+j]==48)
                            poscontra[i2+j]=49;
                        else
                            poscontra[i2+j]=48;
                    }
                }
                else {
                    for (int j=2; j<semilla; j+=3){
                        if (binposcontra[i2+j]==48)
                            poscontra[i2+j]=49;
                        else
                            poscontra[i2+j]=48;
                    }
                }
            }
        }
}

bool validsudo(string &poscontra, void codclave(string&)){
    /* La función recibe la contraseña codificada, ingresada por la persona, en el string poscontra. Luego, lee la contraseña
     * correcta del administrador, que se encuentra codificada en el archivo "clave_admin". Finalmente compara las dos contraseñas
     * y devuelve true si son iguales, para pasar al ciclo de funcionamiento del perfil administrador, y devuelve false si la
     * persona desea salirse del proceso de validación de contraseña.
     */
    bool valids=false;
    string validcontra="";

    ifstream infile;
    infile.open("clave_admin.txt");
    if (!infile.is_open())
       {
         std::cout << "Error opening file" << endl;
         exit(1);
       }
    getline(infile, validcontra);
    infile.close();
    validcontra.resize(validcontra.size() - 8);
    while (true){
        poscontra="";
        cout << "\nIngrese la clave de administrador o x para salir: ";
        cin >> poscontra;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        codclave(poscontra);
        if (validcontra==poscontra){
            valids=true;
            break;
        }
        else if (poscontra=="10001010" || poscontra=="10100111")
            break;
        else
            cout << "\n***** CLAVE INCORRECTA *****\n" << endl;
    }
    return valids;
}

bool ingresouser(string &cedulauser){
    /* La función le permite al usuario ingresar su numero de cedula para que realice la compra de la boleta.
     * Esta cedula quedará guardada en el string cedulauser. Además, se realiza la validación de que la cedula sea un
     * numero positivo. Si el usuario ingresa -1, la funcion retorna false, en caso contrario, y si el usuario ingresó
     * su cedula correctamente, la función devuelve true, lo que permite ingresar el ciclo de funcionamiento del perfil usuario.
     */
    string cedula="";
    cout << "\nIngrese su cedula o escriba -1 para salir: ";
    cin >> cedula;

    if (stoi(cedula)==-1){
        return false;
    }

    while(!cin || stoi(cedula)<0)
    {
        cout << "\nAsegurese de ingresar una cedula valida o escriba 1 para salir: ";
        cin.clear();
        cin.ignore();
        cin >> cedula;
        if (stoi(cedula)==1){
            return false;
        }
    }
    cedulauser=cedula;
    return true;
}

void registropeliculas(map<int, vector<sala>> &cine){
    /* Esta función le permite al administrador ingresar la información de la pelicula que desea registrar.
     * Le pide el ID, validando que no esté repetido, luego le pide el nombre, la duracion, el genero, la clasificación,
     * y luego se procede a escoger en que salas se proyectará la pelicula, dependiendo si serán 2D o 3D, y dependiendo de la
     * elección, se ingresa el numero de la sala, la hora de proyección y el numero de asientos de la sala.
     * Cada pelicula es guardada en el mapa "cine", con clave su ID, y como valor se guarda el vector de salas donde será
     * proyectada la pelicula. Esta información será utilizada posteriormente para actualizar los archivos.
     */
    int ID,duracionmin,clasificacion;
    string nombre;
    string genero;
    string tiposala;
    int numerosala, hora, cantidadasientos;

    bool validid=true;

    cout << "Ingrese el ID de la pelicula (un numero entero positivo) o -1 para salir: ";
    cin >> ID;

    if (ID==-1){
        return;
    }

    while (true){
        // Se valida que el ID no esté repetido
        validid=true;
        for (auto pareja : cine){
            if (pareja.first == ID){
                validid=false;
            }
        }
        if ( (!cin) || validid==false || ID<=0){
            cout << "Asegurese de ingresar un ID valido (que no este repetido)" << endl;
            cout << "Ingrese el ID de la pelicula (un numero entero positivo) o -1 para salir: ";
            cin.clear();
            cin.ignore();
            cin >> ID;
            if (ID==-1){
                return;
            }
        }
        else{
            break;
        }
    }

    cout << "Ingrese el nombre de la pelicula: ";
    std::getline(std::cin >> std::ws, nombre);
    cout << "Ingrese el genero de la pelicula: ";
    cin >> genero;
    cout << "Ingrese la duracion en minutos de la pelicula: ";
    cin >> duracionmin;
    cout << "Ingrese la clasificacion de la pelicula: ";
    cin >> clasificacion;

    // Se crea el objeto pelicula y se le asigna su información como atributos
    pelicula nuevapelicula;
    nuevapelicula.asignarInformacion(ID, nombre, genero, duracionmin, clasificacion);

    //  El usuario puede escoger si la pelicula se proyectará en 2D o 3D o ambos
    int opctipo;
    cout << "\nLa pelicula va a ser proyectada en que tipo de sala" << endl;
    cout << "1. Solo 2D" << endl;
    cout << "2. Solo 3D" << endl;
    cout << "3. 2D y 3D\n" << endl;
    cout << "Ingrese el numero de la opcion deseada o 0 para salir: " << endl;
    cin >> opctipo;

    if (opctipo==0){  // Se sale de la función y esto provoca que termine el proceso de registro de peliculas
        return;
    }

    while(!cin || opctipo<0 || opctipo>3){
        cout << "\nAsegurese de ingresar una opcion valida o escriba 0 para salir: ";
        cin.clear();
        cin.ignore();
        cin >> opctipo;
        if (opctipo==0){
            return;
        }
    }

    if (opctipo==1 || opctipo==3){
        cout << "Ingrese el numero de la sala 2D en la cual se va a proyectar la pelicula (numero entero positivo) o -1 para salir: ";
        cin >> numerosala;

        if (numerosala==-1){
            return;
        }

        while (true){
            bool validnumero=true;
            for (auto pareja : cine){
                vector<sala>::iterator it;
                it = pareja.second.begin();
                for (; it!=pareja.second.end(); it++){
                    if ((*it).obtenerNumerosala() == numerosala){
                        validnumero=false;
                    }
                }
            }
            if (validnumero==false || numerosala<=0){
                cout << "Asegurese de ingresar un numero de sala valido (que no este repetido)" << endl;
                cout << "Ingrese el numero de la sala 2D en la cual se va a proyectar la pelicula (numero entero positivo) o -1 para salir: ";
                cin.clear();
                cin.ignore();
                cin >> numerosala;
                if (numerosala==-1){
                    return;
                }
            }
            else{
                break;
            }
        }
        cout << "Ingrese la hora a la cual se va a proyectar la pelicula (formato 24 hr): ";
        cin >> hora;
        cout << "Cual sera la cantidad de asientos de la sala?" << endl;
        cout << "1. 120" << endl;
        cout << "2. 60" << endl;
        cout << "Ingrese el numero de la opcion deseada: ";
        cin >> cantidadasientos;
        if (cantidadasientos==1){

            // Se crea el objeto sala y se le asigna la información, para luego ingresarlo en el mapa "cine"
            sala nuevasala(numerosala, nuevapelicula, "2D", 120, hora);
            cine[ID].push_back(nuevasala);
        }
        else{

            // Se crea el objeto sala y se le asigna la información, para luego ingresarlo en el mapa "cine"
            sala nuevasala(numerosala, nuevapelicula, "2D", 60, hora);
            cine[ID].push_back(nuevasala);
        }

    }
    if (opctipo==2 || opctipo==3){
        cout << "Ingrese el numero de la sala 3D en la cual se va a proyectar la pelicula (numero entero positivo) o -1 para salir: ";
        cin >> numerosala;
        if (numerosala==-1){
            return;
        }

        while (true){
            bool validnumero=true;
            for (auto pareja : cine){
                vector<sala>::iterator it;
                it = pareja.second.begin();
                for (; it!=pareja.second.end(); it++){
                    if ((*it).obtenerNumerosala() == numerosala){
                        validnumero=false;
                    }
                }
            }
            if (validnumero==false || numerosala<=0){
                cout << "Asegurese de ingresar un numero de sala valido (que no este repetido)" << endl;
                cout << "Ingrese el numero de la sala 3D en la cual se va a proyectar la pelicula (numero entero positivo) o -1 para salir: ";
                cin.clear();
                cin.ignore();
                cin >> numerosala;
                if (numerosala==-1){
                    return;
                }
            }
            else{
                break;
            }
        }
        cout << "Ingrese la hora a la cual se va a proyectar la pelicula (formato 24 hr): ";
        cin >> hora;
        cout << "Cual sera la cantidad de asientos de la sala?" << endl;
        cout << "1. 120" << endl;
        cout << "2. 60" << endl;
        cout << "Ingrese el numero de la opcion deseada: ";
        cin >> cantidadasientos;
        if (cantidadasientos==1){

            // Se crea el objeto sala y se le asigna la información, para luego ingresarlo en el mapa "cine"
            sala nuevasala(numerosala, nuevapelicula, "3D", 120, hora);
            cine[ID].push_back(nuevasala);
        }
        else{

            // Se crea el objeto sala y se le asigna la información, para luego ingresarlo en el mapa "cine"
            sala nuevasala(numerosala, nuevapelicula, "3D", 60, hora);
            cine[ID].push_back(nuevasala);
        }
    }
}

void guardarpeliculas(map<int, vector<sala>> cine){

    /* Esta función transcribe la información de las peliculas y las salas, que esta guardada en el mapa "cine"
     * para ser escrita en el archivo "info_peliculas", y asi mantener la información actualizada y guardada luego del cierre
     * del programa
     */
    ofstream outfile;
    outfile.open("info_peliculas.txt");
    string auxtxt="";

    // Se abre el archivo
    if (!outfile.is_open())
       {
         std::cout << "Error abriendo el archivo" << endl;
         exit(1);
       }
    // Se ingresa a la información del cine y se le acomoda en un string, de acuerdo al formato
    // "ID-nombre-genero-duracionenminutos-clasificacion-(tipodesala-numerodesala-horaproyeccion-...
    // ...numeroasientosdisponiblesgeneral/numerodeasientosdisponiblespreferencial/numerodeasientosdisponiblesvibrosound...
    // .../numerodeasientostotales)"
    for (auto pareja : cine){
        pelicula peliaguardar=pareja.second[0].obtenerPelienproyeccion();
        string lineaparte1=to_string(peliaguardar.obtenerID())+"-"+peliaguardar.obtenerNombre()+"-"+peliaguardar.obtenerGenero()+
                "-"+to_string(peliaguardar.obtenerDuracionmin())+"-"+to_string(peliaguardar.obtenerClasificacion());
        string infosala;
        string lineaparte2="";
        for (unsigned int i=0; i<cine[peliaguardar.obtenerID()].size(); i++){
            infosala="-("+cine[peliaguardar.obtenerID()][i].obtenerTiposala()+"-";
            infosala=infosala+to_string(cine[peliaguardar.obtenerID()][i].obtenerNumerosala())+"-";
            infosala=infosala+to_string(cine[peliaguardar.obtenerID()][i].obtenerHoraproyeccion())+"-";
            infosala=infosala+to_string(cine[peliaguardar.obtenerID()][i].obtenerNumasientosdisp()["General"])+"/";
            infosala=infosala+to_string(cine[peliaguardar.obtenerID()][i].obtenerNumasientosdisp()["Preferencial"])+"/";
            infosala=infosala+to_string(cine[peliaguardar.obtenerID()][i].obtenerNumasientosdisp()["Vibrosound"])+"/";
            infosala=infosala+to_string(cine[peliaguardar.obtenerID()][i].obtenerCantidadasientos())+")";
            lineaparte2=lineaparte2+infosala;
        }
        auxtxt=auxtxt+lineaparte1+lineaparte2+"\n";
    }

    outfile << auxtxt;  // Se escribe la información en el archivo y luego se cierra
    outfile.close();
}

void sacarinfocine(map<int, vector<sala>> &cine){
    /* La función abre el archivo "info_peliculas" y saca la información de las peliculas, para guardarla en el mapa "cine"
     * y de esta forma mantener la información actualizada
     */
    ifstream infile;
    infile.open("info_peliculas.txt");
    // Se abre el archivo
    if (!infile.is_open())
       {
         std::cout << "Error abriendo el archivo" << endl;
         exit(1);
       }
    string linea;
    // Se lee la información linea por linea
    while (getline(infile, linea)){
        pelicula peliaguardar;
        string aux1="";
        string aux2="";
        int cont=0;
        vector<string> infopeli;
        vector<string> infosala;
        unsigned int icont=0;

        // A continuacion se separa la información y se le asigna a las peliculas y a las salas
        for (unsigned int i=0; i<linea.size(); i++){
            if (linea[i]=='-' && cont<5){
                infopeli.push_back(aux1);
                aux1="";
                cont++;
            }
            else if (cont>=5){
                peliaguardar.asignarInformacion(stoi(infopeli[0]), infopeli[1], infopeli[2], stoi(infopeli[3]), stoi(infopeli[4]));
                icont=i+1;
                break;
            }
            else {
                aux1=aux1+linea[i];
            }
        }
        for (; icont<linea.size(); icont++){
            if (linea[icont]=='-' || linea[icont]=='/' || linea[icont]==')'){
                infosala.push_back(aux2);
                aux2="";
                if (linea[icont]==')'){
                    sala nuevasala(stoi(infosala[1]), peliaguardar, infosala[0], stoi(infosala[6]), stoi(infosala[2]));
                    nuevasala.modificarAsientosdisp(stoi(infosala[3]), stoi(infosala[4]), stoi(infosala[5]));
                    cine[peliaguardar.obtenerID()].push_back(nuevasala);
                    icont+=2;
                    infosala.clear();
                }
            }
            else {
                aux2=aux2+linea[icont];
            }
        }

    }
    infile.close();  // Se cierra el archivo
}

void registroprecios(map<string, int> &precioasientos){
    /* Esta funcion le permite al administrador asignarle o modificarle los precios a los asientos.
     * Se le dan las opciones de los asientos al administrador, y él escoge cual quiere modificar
     */
    int opcprecio;
    int precio;
    cout << "Escoja el tipo de asiento al cual le quiere asignar o modificar el precio" << endl;
    cout << "1. Asiento General." << endl;
    cout << "2. Asiento Preferencial." << endl;
    cout << "3. Asiento Vibrosound." << endl;
    cout << "4. Salir.\n" << endl;
    cout << "Por favor, escriba SOLO el numero de la opcion que desea: ";
    cin >> opcprecio;
    if (opcprecio==4){
        return;
    }
    // Se valida que la opcion pertenezca al rango de opciones
    while((!cin) || opcprecio<1 || opcprecio>4)
    {
        cout << "\nAsegurese de ingresar una opcion valida (un numero entero positivo 1, 2, 3 o 4): ";
        cin.clear();
        cin.ignore();
        cin >> opcprecio;
        if (opcprecio==4){
            return;
        }
    }
    cout << "Ingrese el precio que quiere asignarle: ";
    cin >> precio;

    // A continuacion se procede a guardar el nuevo precio en el mapa de precio de los asientos
    if (opcprecio==1){
        precioasientos["General"]=precio;
    }
    else if (opcprecio==2){
        precioasientos["Preferencial"]=precio;
    }
    else {
        precioasientos["Vibrosound"]=precio;
    }

}

void guardarprecios(map<string, int> precioasientos){
    /* La función ingresa a la información del mapa precioasientos, y guarda esta información en el archivo "precio_asientos".
     * El formato para guardar la información en el archivo es:
     * "nombredelasiento-precio"
     */
    ofstream outfile;
    // Se abe el archivo
    outfile.open("precio_asientos.txt");
    string auxtxt="";
    if (!outfile.is_open())
       {
         std::cout << "Error abriendo el archivo" << endl;
         exit(1);
       }
    // Por cada pareja de elementos del mapa, se realiza la escritura en el string auxtxt, con la información
    for (auto pareja : precioasientos){
        auxtxt=auxtxt+pareja.first+"-"+to_string(pareja.second)+"\n";
    }

    outfile << auxtxt;  // Se escribe la información en el archivo y se cierra
    outfile.close();
}

void sacarprecios(map<string, int> &precioasientos){
    /* Esta funcion abre el archivo "precio_asientos", lee la información guardada en el, y guarda esta información en
     * el mapa de precioasientos, para mantener la información actualizada dentro del programa
     */
    ifstream infile;
    // Se abre el archivo
    infile.open("precio_asientos.txt");
    if (!infile.is_open())
       {
         std::cout << "Error abriendo el archivo" << endl;
         exit(1);
       }
    string linea;
    // Se lee linea por linea
    while (getline(infile, linea)){
        string aux1="";
        string tipo="";
        // A continuacion se identifica y separa la informacion de la linea
        // para guardarla en su posición correspondiente del mapa precioasientos
        for (unsigned int i=0; i<linea.size()+1; i++){
            if (linea[i]=='-'){
                tipo=aux1;
                aux1="";
            }
            else if (i==linea.size()){
                precioasientos[tipo]=stoi(aux1);

            }
            else {
                aux1=aux1+linea[i];
            }
        }

    }
    infile.close(); // Se cierra el archivo
}

vector<int> opcionespeli(map<int, vector<sala>> cine){
    /* Esta funcion recibe el mapa "cine", para sacar la información de las diferentes peliculas en proyección,
     * e imprime esta información en pantalla. Además de esto, guarda cada ID de cada pelicula en el vector
     * IDs. Este vector guardará las opciones de peliculas disponibles para que en la función "eleccionpelicula", el usuario
     * pueda escoger. La función devuelve este vector.
     */
    vector<int> IDs;
    for (auto pareja : cine){
        pelicula pelienproyeccion= pareja.second[0].obtenerPelienproyeccion();
        cout << "\nID: " << pelienproyeccion.obtenerID() << " " << endl;
        cout << "Nombre: " << pelienproyeccion.obtenerNombre() << " " << endl;
        cout << "Genero: " << pelienproyeccion.obtenerGenero() << " " << endl;
        cout << "Duracion: " << pelienproyeccion.obtenerDuracionmin() << " min " << endl;
        cout << "Clasificacion: " << pelienproyeccion.obtenerClasificacion() << "+" << endl;

        IDs.push_back(pelienproyeccion.obtenerID());
    }

    return IDs;
}

int eleccionpelicula(map<int, vector<sala>> cine, vector<int> imprimirpeliculas(map<int, vector<sala>>)){
    /* La función recibe el mapa "cine", y además recibe la función "imprimirpeliculas", que será usada para imprimir
     * las peliculas en cartelera y devolver el vector con las opciones. Al usuario se le pedirá que ingrese el ID de la
     * pelicula que desea, validando que sea un ID valido, y la función devolvera un entero con el ID de la película escogida
     * por el usuario o -1 si el usuario quiere salir de la elección
     */
    int opcpeli;
    cout << "\nEstas son las peliculas en cartelera: " << endl;
    // Se usa la función imprimirpeliculas para imprimir las peliculas y guardar las opciones
    vector<int> opciones=imprimirpeliculas(cine);
    cout << "\nPor favor, escriba SOLO el ID de la pelicula que desea o -1 para salir: ";
    cin >> opcpeli;

    if (opcpeli==-1){
        return -1;
    }
    // Se valida que la opcion escogida esté dentro de las opciones de películas
    while(true){
        bool validid=false;
        vector<int>::iterator it;
        it=opciones.begin();
        for (; it!= opciones.end(); it++){
            if ( *it == opcpeli){
                validid=true;
            }
        }
        if (validid==true){
            break;
        }
        else {
            cout << "\nAsegurese de ingresar un ID valido o -1 para salir: ";
            cin.clear();
            cin.ignore();
            cin >> opcpeli;
            if (opcpeli==-1){
                return -1;
            }
        }
    }

    return opcpeli;

}

int eleccionsalayhora(map<int, vector<sala>> cine, int IDpeliculaescogida){
    /* Esta funcion recibe el mapa "cine" y el entero con el ID de la película escogida. Posteriormente, el usuario podrá
     * visualizar las salas que tienen asientos disponibles, y se le pedirá al usuario que ingrese el numero de la sala que
     * desea, luego de mostrarle cada sala y su hora de proyección. Luego, se valida que el usuario si haya ingresado
     * un numero de sala dentro de las opciones disponibles, y finalmente la función devuelve un entero con la sala escogida
     * o -1 si el usuario quiere salir de la elección
     */

    int opcsala;
    cout << "\n Horarios y salas disponibles: " << endl;
    vector<int> opciones; // Se crea el vector que guardará las opciones de salas

    vector<sala>::iterator it; // Se crea el iterador para buscar las salas con asientos disponibles

    it= cine[IDpeliculaescogida].begin();
    for (; it != cine[IDpeliculaescogida].end(); it++){

        if ((*it).obtenerTotalasientosdisp()>0){   // Se identifican las salas son asientos disponibles
            // Se imprime la información de cada sala
            cout << "\n***** En " << (*it).obtenerTiposala() << " *****" << endl;
            cout << "Sala #" << (*it).obtenerNumerosala() << " --- Hora: " << (*it).obtenerHoraproyeccion() << ":00 hr" << endl;
            opciones.push_back((*it).obtenerNumerosala());
        }
    }

    cout << "\nPor favor ingrese SOLO el numero de la sala que desea o -1 para salir: ";
    cin >> opcsala;
    if (opcsala==-1){
        return -1;
    }
    // Se valida que el numero ingresado por el usuario si corresponda a una sala disponible
    while(true){
        bool validid=false;
        vector<int>::iterator it;
        it=opciones.begin();
        for (; it!= opciones.end(); it++){
            if ( *it == opcsala){
                validid=true;
            }
        }
        if (validid==true){
            break;
        }
        else {
            cout << "\nAsegurese de ingresar un ID valido o -1 para salir: ";
            cin.clear();
            cin.ignore();
            cin >> opcsala;
            if (opcsala==-1){
                return -1;
            }
        }
    }

    return opcsala;
}

void guardarsalas(map<int, vector<sala>> cine){
    /* La función recibe el mapa "cine", y luego procede a guardar la información contenida en el mapa, en el archivo de cada sala.
     * El archivo de cada sala será identificado por su numero de sala, con el nombre "sala_..." y en los tres puntos irá
     * el numero de la sala. Esta funcion itera en el mapa "cine", y entra a la información de cada sala, para guardar en su
     * archivo una visualización de los asientos, asignando 'o' a los asientos disponibles, y 'x' a los asientos ocupados.
     * La filas van de la "L" a la "A"; si la sala es de 120 asientos, y de la "F" a la "A"; si la sala es de 60 asientos.
     * En el archivo irán guardadas las filas de forma descendente, siendo la fila "A", el último renglon del archivo.
     * Luego, los asientos van numerados del 1 al 10, y en el archivo, y en la "realidad" de las salas, la numeración va de forma
     * descendente de izquierda a derecha, es decir "10 9 8 7...". Entre cada "asiento" se imprime un espacio vacío.
     */
    ofstream outfile;
    for (auto pareja : cine){   // Se itera por cada pareja del mapa "cine"
        vector<sala>::iterator it;
        it=pareja.second.begin();
        for (;it!=pareja.second.end(); it++){  // Luego se itera por cada sala del vector interno de salas de cada película
            // Se guardan los asientos
            vector<vector<char>> asientos=(*it).obtenerAsientos();

            // Se abre o se crea el archivo de la sala
            outfile.open("sala_"+to_string((*it).obtenerNumerosala())+".txt");
            string auxtxt="";

            if (!outfile.is_open())
               {
                 std::cout << "Error abriendo el archivo" << endl;
                 exit(1);
               }
            // Se guarda el string de la fila de asientos en auxtxt
            for (unsigned int i=0; i<asientos.size(); i++){
                for (int j=asientos[i].size()-1; j>=0; j--){
                    auxtxt=auxtxt+asientos[i][j]+" ";
                }
                auxtxt=auxtxt+"\n";
            }
            outfile << auxtxt;  // Se escribe el string auxtxt en el archivo y se cierra
            outfile.close();

        }
    }
}

void sacarsalas(map<int, vector<sala>> &cine){
    /* La función recibe el mapa "cine", y abre cada uno de los archivos de las salas, para sacar la información de los asientos
     * ocupados y disponibles, y guardar esta información en el atributo de asientos que es un vector de vectores en cada sala.
     */
    ifstream infile;
    for (auto &pareja : cine){  // Se itera en cada pareja del mapa "cine"
        vector<sala>::iterator it;
        it=pareja.second.begin();  // Luego se itera por cada sala del vector de salas la película

        for (;it!=pareja.second.end(); it++){
            vector<vector<char>> asientos;  // Se crea el vector de vectores donde irán los asientos de la sala
            // Se abre el archivo de la sala
            infile.open("sala_"+to_string((*it).obtenerNumerosala())+".txt");
            if (!infile.is_open())
               {
                 std::cout << "Error abriendo el archivo" << endl;
                 exit(1);
               }
            string linea;
            // Se lee el archivo linea por linea
            while (getline(infile, linea)){
                vector<char> fila;
                for (int i=linea.size()-1; i>=0; i--){
                    if (i%2==0){  // Se identifican los caracteres de la linea, correspondientes a "asientos"
                       fila.push_back(linea[i]);  // Se guarda el simbolo de los asientos en el vector fila
                    }
                }
                asientos.push_back(fila);  // Y luego se guarda cada fila en el vector de vectores "asientos"
            }
            (*it).asignarAsientos(asientos);  // Se le asignan los asientos al atributo de la sala
            (*it).actualizarCantasientos();   // Se actualiza la cantidad de asientos de la sala, por zona
            infile.close();                   // Se cierra el archivo

        }

    }
}

void eleccionasiento(map<int, vector<sala>> &cine, int IDpelicula, int numerosala, bool pagodeboleta(int, sala, map<string, int>), map<string, int> precioasientos){
    /* Esta funcion recibe el mapa "cine", el ID de la pelicula escogida, el numero de la sala escogida, el mapa
     * de precio de los asientos, y la función de pago de boleta. Dentro de la función se usa el método "imprimirAsientos" de
     * la sala, este método imprime los asientos de la sala para que el usuario pueda escoger el asiento que desea
     * comprar. La función le pide al usuario que ingrese la fila y el numero del asiento que quiere comprar,
     * y luego de verificar que esté desocupado, procede a realizarse la compra usando la funcion "pagodeboleta", en la cual
     * se le pedirá al usuario que ingrese el dinero y se le entregará la devuelta, informándole la cantidad de billetes
     * y el faltante. La función de pago de boleta devolverá un booleano que si es true, es porque la compra se realizó
     * exitosamente, y si esto sucede, se crea un vector de vectores que guardará los asientos actualizados, y se le asigna
     * un símbolo 'x' al asiento comprado. Luego, se le llevan estos asientos actualizados al método "asignarAsientos" de la
     * sala, y luego se actualiza la cantidad de asientos de la sala.
     */
    vector<sala>::iterator it;  // Se itera en el vector de salas de la pelicula escogida, y se identifica la sala escogida
    it=cine[IDpelicula].begin();
    for (; it!= cine[IDpelicula].end(); it++){
        if ((*it).obtenerNumerosala() == numerosala){
            break;
        }
    }
    imprimirPrecios(precioasientos, *it); // Se imprimen los precios
    (*it).imprimirAsientos();  // Se imprimen los asientos de la sala

    char letra;
    cout << "Por favor escoja la fila del asiento que desea (solo letras mayusculas): ";
    cin >> letra;

    // Se valida que la letra ingresada si pertenezca a una fila de la sala
    while (true){
        if (letra>=(char)65 && letra<=(char)(((*it).obtenerCantidadasientos()/10)+64)){
            break;
        }
        else{
            cout << "Asegurese de ingresar una fila valida: ";
            cin >> letra;
        }
    }
    int numeroasiento;
    cout << "Ahora ingrese un numero de asiento que se encuentre disponible o -1 para salir: ";
    cin >> numeroasiento;

    if (numeroasiento==-1){
        return;
    }
    int posicionfila;

    // Se valida que la posición del asiento si sea correcta (un asiento disponible)
    while (true){
        posicionfila=((*it).obtenerCantidadasientos()/10)-(((int)letra)-64);
        if (numeroasiento>0 && numeroasiento<=10 && (*it).obtenerAsientos()[posicionfila][numeroasiento-1]=='o'){
            break;
        }
        else{
            cout << "Asegurese de ingresar una numero de asiento valido (que este disponible): ";
            cin >> numeroasiento;
            if (numeroasiento==-1){
                return;
            }
        }
    }
    // Si se realizó el pago correctamente, si procede a actualizar la información
    if (pagodeboleta(posicionfila, *it, precioasientos)==true){
        vector<vector<char>> nuevosasientos=(*it).obtenerAsientos(); // Creación de nuevo vector de vectores con asientos
        nuevosasientos[posicionfila][numeroasiento-1]='x';  // Reservación del asiento
        (*it).asignarAsientos(nuevosasientos);              // Asignación de los asientos a la sala
        (*it).actualizarCantasientos();                     // Actualización de la cantidad de asientos disponibles
        cout << "\nBoleta comprada con exito" << endl;
    }
    else {
        return;
    }
}

bool pagodeboleta(int fila, sala sala, map<string, int> precioasientos){
    /* Esta funcion recibe el numero de la fila, convertido a su codigo para ser accedido desde el vector de vectores
     * correspondiente a los asientos de la sala, y dependiendo de su ubicacion, se le asigna un precio a la boleta
     * y se usa el algoritmo 1 de la practica 2 para hacer el procedimiento de devueltas
     */
    int precio;
    string zona;
    // Se asigna el precio de la boleta dependiendo de la zona donde esté ubicado el asiento
    // Si está en el primer tercio de la sala (de forma vertical), será asiento "Vibrosound"
    // Si está en el segundo tercio de la sala, será asiento "Preferencial"
    // Si está en el tercer tercio de la sala, será asiento "General"
    if (fila<(sala.obtenerCantidadasientos())/30){
        precio=precioasientos["Vibrosound"];
        zona="Vibrosound";

    }
    else if (fila>=(sala.obtenerCantidadasientos())/30 && fila<(sala.obtenerCantidadasientos())/15){
        precio=precioasientos["Preferencial"];
        zona="Preferencial";
    }
    else{
          precio=precioasientos["General"];
          zona="General";
    }

    cout << "\nEl precio de la boleta en el asiento escogido (Zona" << zona << ") es: " << precio << endl;

    // Se le pide al usuario que ingrese el dinero
    int dinero;
    cout << "\nIngrese el dinero para pagar la boleta o -1 para salir: ";
    cin >> dinero;

    if (dinero==-1){ // Se devuelve false si el usuario ingresa -1
        return false;
    }
    while (true){
        // Se verifica que la cantidad ingresada sea suficiente para pagar el precio de la boleta
        if (dinero>=precio){
            break;
        }
        else{
            cout << "\nAsegurese de ingresar suficiente dinero para pagar: ";
            cin >> dinero;
            if (dinero==-1){ // Se devuelve false si el usuario ingresa -1
                return false;
            }
        }
    }
    // Se calcula el sobrante
    int sobrante=dinero-precio;

    // Si el sobrante es mayor a cero, se calcula la cantidad de billetes a devolver, y el faltante
    if (sobrante>0){
        int denom[10]={50000,20000,10000,5000,2000,1000,500,200,100,50};
        int canti[10]={};
        cout << "\nEsta es su devuelta: " << endl;
        for (int i=0; i<10 ; i++){
            canti[i]=sobrante/denom[i];
            sobrante=sobrante%denom[i];
            if (canti[i]>0){
                cout << "Denominacion " << denom[i] << ": Cantidad " << canti[i] << endl;
            }
        }
        cout << "Faltante: " << sobrante << endl;
    }

    return true; // Se devuelve true si la compra se realizó con éxito
}

void imprimirPrecios(map<string, int> precioasientos, sala sala){
    /* Esta funcion recibe el mapa con los precios de los asientos, y recibe la sala de la cual se obtendrán los precios
     * La función imprime los precios dependiendo de la partición de las filas, ya que esta determina la zona en la sala
     */
    cout << "\nPRECIOS: " << endl;
    cout << "Zona General (Filas de la " << char(65) << " a la " << char(64+sala.obtenerCantidadasientos()/30) << "): ";
    cout << precioasientos["General"] << endl;
    cout << "Zona Preferencial (Filas de la " << char(65+sala.obtenerCantidadasientos()/30) << " a la " << char(64+2*sala.obtenerCantidadasientos()/30) << "): ";
    cout << precioasientos["Preferencial"] << endl;
    cout << "Zona Vibrosound (Filas de la " << char(65+2*sala.obtenerCantidadasientos()/30) << " a la " << char(64+3*sala.obtenerCantidadasientos()/30) << "): ";
    cout << precioasientos["Vibrosound"] << endl;
}




