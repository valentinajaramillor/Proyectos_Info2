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

map<int, vector<sala>> cine;

short int opcini();
short int opcsudo();
short int opcuser(string&);
void decod(string&,string&);
void sacardatos(vector<vector<string>>&,string&);
void codclave(string&);
bool validsudo(string&, void (string &));
bool ingresouser(string &cedulauser);
void registropeliculas(map<int, vector<sala>>);

int main()
{
    bool cajeroin=true;
    bool sudoin=true;
    bool userin;
    short int opci;
    short int opcs;
    short int opcu;
    string binarchivocod="";
    string original="";
    string poscontra="";

    while (cajeroin){
        //datos.clear();
        //sacardatos(datos,original);
        opci=opcini();

        if (opci==1){
            sudoin=validsudo(poscontra,codclave);
            while (sudoin){
                opcs=opcsudo();
                if (opcs==1){
                    cout << "\n...REGISTRO DE PELICULAS..." << endl;
                    registropeliculas(cine);
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
                cout << cedulauser << endl;
                opcu=opcuser(cedulauser);
                if (opcu==1){
                    continue;
                }
                else if (opcu==2){
                    cout << "\n...HASTA LUEGO, USUARIO..." << endl;
                    userin=false;
                }
            }
        }
        else {
            cout << "\n...VUELVA PRONTO..." << endl;
            cajeroin=false;
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
    cout << "2. Generar reporte de venta de boleteria del dia." << endl;
    cout << "3. Salir.\n" << endl;
    cout << "Por favor, escriba SOLO el numero de la opcion que desea: ";
    cin >> opcsudo;
    while((!cin) || opcsudo<1 || opcsudo>3)
    {
        cout << "\nAsegurese de ingresar una opcion valida (un numero entero positivo 1 o 2): ";
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
void sacardatos(vector<vector<string>> &datos,string &original){
    string line;
    int cont1=0;
    int cont2=0;
    int contp=0;
    vector<string> aux1{"","",""};
    unsigned int i=0;
    string aux2="";
    while (i<original.size()){
        cont1=0;
        cont2=0;
        line="";
        while (true){
            if (original[i]!='\n')
                line+=original[i];
            else
                break;
            i++;
        }
        int length=line.length();
        while (true){
            aux2=aux2+line[cont1];
            if (line[cont1+1]==',' || cont1==length-1){
                aux1[cont2]=aux2;
                aux2="";
                cont2++;
                cont1+=2;
                if (cont2==3){
                    datos.push_back(aux1);
                    aux1={"","",""};
                    i++;
                    break;
                }
            }
            cont1++;
        }
        contp++;
    }
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
    infile.open("sudo.txt");
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
    cout << "\nIngrese su cedula o escriba 1 para salir: ";
    cin >> cedula;

    if (stoi(cedula)==1){
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

void registropeliculas(map<int, vector<sala>> cine){
    int ID,duracionmin,clasificacion;
    string nombre,genero;
    string tiposala;
    int numerosala;
    int cantidadasientos;

    bool validid=true;

    cout << "Ingrese el ID de la pelicula (un numero entero mayor a cero): ";
    cin >> ID;

    while (true){
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
    cin >> nombre;
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
        cout << "¿Cual sera la cantidad de asientos de la sala?" << endl;
        cout << "1. 120" << endl;
        cout << "2. 60" << endl;
        cout << "Ingrese el numero de la opcion deseada: ";
        cin >> cantidadasientos;
        if (cantidadasientos==1){
            sala nuevasala(numerosala, nuevapelicula, "2D", 120);
            cine[ID].push_back(nuevasala);
        }
        else{
            sala nuevasala(numerosala, nuevapelicula, "2D", 60);
            cine[ID].push_back(nuevasala);
        }

    }
    if (opctipo==2 || opctipo==3){
        cout << "Ingrese el numero de la sala 3D en la cual se va a proyectar la pelicula: ";
        cin >> numerosala;
        cout << "¿Cual sera la cantidad de asientos de la sala?" << endl;
        cout << "1. 120" << endl;
        cout << "2. 60" << endl;
        cout << "Ingrese el numero de la opcion deseada: ";
        cin >> cantidadasientos;
        if (cantidadasientos==1){
            sala nuevasala(numerosala, nuevapelicula, "3D", 120);
            cine[ID].push_back(nuevasala);
        }
        else{
            sala nuevasala(numerosala, nuevapelicula, "3D", 60);
            cine[ID].push_back(nuevasala);
        }
    }


}

void guardarpeliculas(pelicula peliaguardar){

    ofstream outfile;
    outfile.open("peliculas.txt", std::ios_base::app | std::ios_base::out);
    if (!outfile.is_open())
       {
         std::cout << "Error abriendo el archivo" << endl;
         exit(1);
       }
    string linea=to_string(peliaguardar.obtenerID())+"-"+peliaguardar.obtenerNombre()+peliaguardar.

    outfile << linea;
    outfile.close();
}





