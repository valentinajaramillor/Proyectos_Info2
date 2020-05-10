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
sala busquedasala(map<int, vector<sala>>, int, int);
void eleccionasiento(map<int, vector<sala>>&);
void guardarsalas(map<int, vector<sala>>);
void sacarsalas(map<int, vector<sala>>&);

int main()
{
    bool cinein=true;
    bool sudoin=true;
    bool userin;
    short int opci;
    short int opcs;
    short int opcu;
    string original="";
    string poscontra="";

    map<int, vector<sala>> cine;  // Clave: ID de pelicula - Valor: Vector con salas donde se proyecta
    map<string, int> precioasientos; // Clave: Tipo de asiento - Valor: Costo de boleta.

    while (cinein){
        cine.clear();
        precioasientos.clear();
        sacarinfocine(cine);
        sacarprecios(precioasientos);
        opci=opcini();

        if (opci==1){
            sudoin=validsudo(poscontra,codclave);
            while (sudoin){
                opcs=opcsudo();
                if (opcs==1){
                    cout << "\n...REGISTRO DE PELICULAS..." << endl;
                    registropeliculas(cine);
                    guardarpeliculas(cine);
                    guardarsalas(cine);
                    continue;
                }
                else if (opcs==2){
                    cout << "\n...MODIFICACION DE PRECIOS..." << endl;
                    registroprecios(precioasientos);
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
            string cedulauser="";
            userin=ingresouser(cedulauser);
            while (userin){
                opcu=opcuser(cedulauser);
                if (opcu==1){
                    cout << "\n...ELECCION DE PELICULA..." << endl;
                    int IDpeliescogida=eleccionpelicula(cine, opcionespeli);
                    if (IDpeliescogida==-1){
                        continue;
                    }
                    int salaescogida=eleccionsalayhora(cine, IDpeliescogida);
                    if (salaescogida==-1){
                        continue;
                    }

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

short int opcini(){
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

    int semilla=4,n,max,i2;
    string line="";
    string binposcontra="";
    char auxhex[3]="";
    string auxdec="";
    string auxbin;

    for (unsigned int i=0; i<(poscontra.length()); i++){
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
    int ID,duracionmin,clasificacion;
    string nombre;
    string genero;
    string tiposala;
    int numerosala, hora, cantidadasientos;

    bool validid=true;

    cout << "Ingrese el ID de la pelicula (un numero entero mayor a cero): ";
    cin >> ID;

    while (true){
        validid=true;
        for (auto pareja : cine){
            if (pareja.first == ID){
                validid=false;
            }
        }
        if (validid==false){
            cout << "Asegurese de ingresar un ID que no este repetido" << endl;
            cout << "Ingrese el ID de la pelicula (un numero entero mayor a cero): ";
            cin >> ID;
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

    pelicula nuevapelicula;
    nuevapelicula.asignarInformacion(ID, nombre, genero, duracionmin, clasificacion);

    int opctipo;
    cout << "\nLa pelicula va a ser proyectada en que tipo de sala" << endl;
    cout << "1. Solo 2D" << endl;
    cout << "2. Solo 3D" << endl;
    cout << "3. 2D y 3D\n" << endl;
    cout << "Ingrese el numero de la opcion deseada o 0 para salir: " << endl;
    cin >> opctipo;

    if (opctipo==0){
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
        cout << "Ingrese el numero de la sala 2D en la cual se va a proyectar la pelicula: ";
        cin >> numerosala;
        cout << "Ingrese la hora a la cual se va a proyectar la pelicula (formato 24 hr): ";
        cin >> hora;
        cout << "Cual sera la cantidad de asientos de la sala?" << endl;
        cout << "1. 120" << endl;
        cout << "2. 60" << endl;
        cout << "Ingrese el numero de la opcion deseada: ";
        cin >> cantidadasientos;
        if (cantidadasientos==1){
            sala nuevasala(numerosala, nuevapelicula, "2D", 120, hora);
            cine[ID].push_back(nuevasala);
        }
        else{
            sala nuevasala(numerosala, nuevapelicula, "2D", 60, hora);
            cine[ID].push_back(nuevasala);
        }

    }
    if (opctipo==2 || opctipo==3){
        cout << "Ingrese el numero de la sala 3D en la cual se va a proyectar la pelicula: ";
        cin >> numerosala;
        cout << "Ingrese la hora a la cual se va a proyectar la pelicula (formato 24 hr): ";
        cin >> hora;
        cout << "Cual sera la cantidad de asientos de la sala?" << endl;
        cout << "1. 120" << endl;
        cout << "2. 60" << endl;
        cout << "Ingrese el numero de la opcion deseada: ";
        cin >> cantidadasientos;
        if (cantidadasientos==1){
            sala nuevasala(numerosala, nuevapelicula, "3D", 120, hora);
            cine[ID].push_back(nuevasala);
        }
        else{
            sala nuevasala(numerosala, nuevapelicula, "3D", 60, hora);
            cine[ID].push_back(nuevasala);
        }
    }
}

void guardarpeliculas(map<int, vector<sala>> cine){

    ofstream outfile;
    outfile.open("info_peliculas.txt");
    string auxtxt="";
    if (!outfile.is_open())
       {
         std::cout << "Error abriendo el archivo" << endl;
         exit(1);
       }
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

    outfile << auxtxt;
    outfile.close();
}

void sacarinfocine(map<int, vector<sala>> &cine){
    ifstream infile;
    infile.open("info_peliculas.txt");
    if (!infile.is_open())
       {
         std::cout << "Error abriendo el archivo" << endl;
         exit(1);
       }
    string linea;
    while (getline(infile, linea)){
        pelicula peliaguardar;
        string aux1="";
        string aux2="";
        int cont=0;
        vector<string> infopeli;
        vector<string> infosala;
        unsigned int icont=0;
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
                    nuevasala.modificarAsientosdisp(stoi(infosala[0]), stoi(infosala[1]), stoi(infosala[2]));
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
    infile.close();
}

void registroprecios(map<string, int> &precioasientos){
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

    ofstream outfile;
    outfile.open("precio_asientos.txt");
    string auxtxt="";
    if (!outfile.is_open())
       {
         std::cout << "Error abriendo el archivo" << endl;
         exit(1);
       }
    for (auto pareja : precioasientos){
        auxtxt=auxtxt+pareja.first+"-"+to_string(pareja.second)+"\n";
    }

    outfile << auxtxt;
    outfile.close();
}

void sacarprecios(map<string, int> &precioasientos){
    ifstream infile;
    infile.open("precio_asientos.txt");
    if (!infile.is_open())
       {
         std::cout << "Error abriendo el archivo" << endl;
         exit(1);
       }
    string linea;
    while (getline(infile, linea)){
        string aux1="";
        string tipo="";
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
    infile.close();
}

vector<int> opcionespeli(map<int, vector<sala>> cine){
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
    int opcpeli;
    cout << "\nEstas son las peliculas en cartelera: " << endl;
    vector<int> opciones=imprimirpeliculas(cine);
    cout << "\nPor favor, escriba SOLO el ID de la pelicula que desea o -1 para salir: ";
    cin >> opcpeli;

    if (opcpeli==-1){
        return -1;
    }

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

    int opcsala;
    cout << "\n Horarios y salas disponibles: " << endl;
    vector<int> opciones;
    vector<sala>::iterator it;
    it= cine[IDpeliculaescogida].begin();
    for (; it != cine[IDpeliculaescogida].end(); it++){
        if ((*it).obtenerTotalasientosdisp()>0){
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

sala busquedasala(map<int, vector<sala>> cine, int IDpelicula, int numerosala){

    vector<sala>::iterator it;
    it=cine[IDpelicula].begin();
    for (; it!= cine[IDpelicula].end(); it++){
        if ((*it).obtenerNumerosala() == numerosala){
            break;
        }
    }
    return *it;
}

void guardarsalas(map<int, vector<sala>> cine){

    ofstream outfile;
    for (auto pareja : cine){
        vector<sala>::iterator it;
        it=pareja.second.begin();
        for (;it!=pareja.second.end(); it++){
            vector<vector<char>> asientos=(*it).obtenerAsientos();
            outfile.open("sala_"+to_string((*it).obtenerNumerosala())+".txt");
            string auxtxt="";

            if (!outfile.is_open())
               {
                 std::cout << "Error abriendo el archivo" << endl;
                 exit(1);
               }
            for (unsigned int i=0; i<asientos.size(); i++){
                for (unsigned int j=0; j<asientos[i].size(); j++){
                    auxtxt=auxtxt+asientos[i][j]+" ";
                }
                auxtxt=auxtxt+"\n";
            }
            outfile << auxtxt;
            outfile.close();

        }
    }
}

void sacarsalas(map<int, vector<sala>> &cine){
    ifstream infile;
    for (auto &pareja : cine){
        vector<sala>::iterator it;
        it=pareja.second.begin();
        for (;it!=pareja.second.end(); it++){
            vector<vector<char>> asientos;
            infile.open("sala_"+to_string((*it).obtenerNumerosala())+".txt");
            if (!infile.is_open())
               {
                 std::cout << "Error abriendo el archivo" << endl;
                 exit(1);
               }
            string linea;
            while (getline(infile, linea)){
                vector<char> fila;
                for (unsigned int i=0; i<linea.size(); i++){
                    fila.push_back(linea[i]);
                }
                asientos.push_back(fila);
            }
            (*it).asignarAsientos(asientos);
            infile.close();

        }

    }
}






