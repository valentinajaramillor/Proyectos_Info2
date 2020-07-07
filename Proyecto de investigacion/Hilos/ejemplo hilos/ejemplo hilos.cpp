/* Este programa hace uso de los hilos, y de tres tipos diferentes de implementación (con funciones, con objetos y con expresiones
 * lambda) para imprimir una serie de mensajes en pantalla y mostrar como se ejecutan los hilos de manera "simultanea".
 */

#include <iostream>
#include <thread>    // Una de las librerías que permite la implementación de los hilos en C++

using namespace std;

// Esta función es una función de prueba, que dependiendo del número entregado n, imprime el mensaje n veces
// La función será llamada posteriormente en el hilo correspondiente
void funcionprueba(int n)
{
    for (int i = 0; i < n; i++) {
        cout << "Mensaje de la funcion" << endl;

    }
}

// Este objeto tiene un método u operador de prueba, que dependiendo del número entregado x, imprime el mensaje x veces
// El método u operador del objeto será llamada posteriormente en el hilo correspondiente
class objetoprueba{
public:
    void operator()(int x)
    {
        for (int i = 0; i < x; i++)
            cout << "Mensaje del objeto" << endl;
    }
};

int main()
{
    cout << "Los hilos 1, 2 y 3 van a operar de manera independiente" << endl;

    // El hilo 1 se crea y se empieza a ejecutar usando un puntero a la función funcionprueba
    // Esta función seguirá su ejecución de manera "simultanea" con respecto al resto de hilos y sus ejecuciones

    thread hilo1(funcionprueba, 3);   // Se indica el nombre de la función y el argumento a entregarle (el número 3)

    // El hilo 2 se crea y se empieza a ejecutar usando la llamada al método u operador del objeto objetoprueba
    // Este método u operador seguirá su ejecución de manera "simultanea" con respecto al resto de hilos y sus ejecuciones

    thread hilo2(objetoprueba(), 3);   // Se indica el método u operador y el argumento a entregarle (el número 3)

    // Se define una expresión lambda de nombre f
    // Esta expresión lambda imprime el mensaje x veces, dependiendo del número entregado x
    auto f = [](int x) {
        for (int i = 0; i < x; i++)
            cout << "Mensaje de la expresion lambda" << endl;
    };

    // El hilo 3 se crea y se empieza a ejecutar usando la llamada a la expresión lambda f
    // f seguirá su ejecución de manera "simultanea" con respecto al resto de hilos y sus ejecuciones

    thread hilo3(f, 3);    // Se indica la expresión a usar y el argumento para entregarle (el número 3)

    // A continuación esperamos que todos los hilos terminen de ejecutarse (usando join()), para asegurar la correcta
    //    ejecución de las instrucciones siguientes (si las hay)

    hilo1.join(); // Se espera a que termine la ejecución del hilo 1

    hilo2.join(); // Se espera a que termine la ejecución del hilo 2

    hilo3.join(); // Se espera a que termine la ejecución del hilo 3

    return 0;
}
