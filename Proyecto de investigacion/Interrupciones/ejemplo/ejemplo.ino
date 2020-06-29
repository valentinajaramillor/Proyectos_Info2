/* EJEMPLO DE USO DE INTERRUPCIONES EN ARDUINO
 * Desarrollado en Tinkercad (Adjunto se encuentra el enlace para ingresar a
 * la simulación.
 * 
 * En este circuito, se usa el concepto de interrupción para que cada vez que 
 * se presione el boton, el led se encienda, y si se presiona de nuevo, se apague. 
 * Es un sistema muy simple que podría ser implementado con revisar en un ciclo si
 * se presionó el botón o no, y de acuerdo con eso modificar el estado del led, pero
 * aquí se decide usar una interrupción para ilustrar el concepto.
 * 
 * Los pines que pueden hacer uso de interrupciones en el arduino uno son el pin 2
 * y el pin 3. Por esta razón se conecta el botón como input en el pin 3, para que
 * en el momento en que el usuario presione el botón, se haga uso de la función
 *¨attachInterrupt, la cual está configurada en modo RISING, para que active la 
 * interrupción cuando sienta que la señal pasó de LOW a HIGH por parte del botón.
 * En este momento se detiene la ejecución del programa principal (el cual puede 
 * ser configurado dependiendo de qué se quiera hacer con el programa en el loop),
 * y una vez suceda esto se activa la función ISR iluminarled, que cambia el estado
 * del led y lo prende.
 */

// Se define la macro del pin digital para el led, que controla su estado
#define PINLED 9
// Se define la macro del pin digital para el botón, que activa la interrupción
#define PINBOTON 3

/* Se define el estado del led como un byte volatil, ya que será modificado dentro
 * de la función ISR en la interrupción, y esto asegura que siempre obtengamos
 * el valor real de la variable y no una copia, y que el compilador no vaya a 
 * remover la variable por no ser usada en el loop
 */    
volatile byte estadoled=LOW;

void setup(){
  // Se configura el pin del led como output, para que reciba el cambio de estado
  //   luego de la interrupción
  pinMode(PINLED, OUTPUT);
  // Se configura el pin del botón como input, para que dependiendo del estado
  //   del botón, active la interrupción
  pinMode(PINBOTON, INPUT);

  // Se configura la interrupción con respecto al pin que la activa (el pin del 
  //   boton), al ISR que funcionará en la interrupción (iluminarled), y al modo
  //   de activación (cuando la señal pase de LOW a HIGH)
  attachInterrupt(digitalPinToInterrupt(PINBOTON), iluminarled, RISING);
  
}

void loop(){
  // Si se requiere se puede crear una secuencia de instrucciones en el loop, que
  //   se ejecutarán y se verán interrumpidas o pausadas por la interrupción
  //   activada al presionar el botón 
}

void iluminarled(){
  // Esta es la función que se activará cuando se presente la interrupción

  // Aqui se cambia el estado del led, al contrario de su estado anterior
  estadoled=!estadoled;
  // Se asigna el estado del led al pin correspondiente, para que se prenda o
  //   apague de acuerdo a lo indicado
  digitalWrite(PINLED, estadoled);
}
