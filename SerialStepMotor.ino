#include <AccelStepper.h>

AccelStepper stepper(AccelStepper::FULL4WIRE, 5, 4); // Define el motor paso a paso y los pines que usará (2 y 4 en este caso)

void setup() {
  Serial.begin(115200); // Inicia la comunicación serial


  
  // Configura el motor paso a paso
      stepper.setMaxSpeed(20000000);
  stepper.setAcceleration(2000000);
    stepper.setPinsInverted(true, true, true); // Invierte la dirección del eje X (puede variar según la configuración física de tu motor)

 
}

void loop() {
  // Lee los datos de entrada de la comunicación serial
  if (Serial.available() > 0) {
    String data = Serial.readStringUntil('\n'); // Lee hasta que encuentre un salto de línea ('\n')
    Serial.println("Datos recibidos:");
    Serial.println(data); // Muestra los datos recibidos por serial
    Serial.println("Respuesta enviada.");

    // Realiza alguna acción con los datos recibidos
    // Por ejemplo, podrías interpretar los datos para mover el motor paso a paso
    int stepsToMove = data.toInt(); // Convierte la cadena recibida en un número entero
    stepper.moveTo(stepsToMove); // Mueve el motor paso a paso
    Serial.println("Mover");
    
  }
  stepper.run(); // Realiza el movimiento del motor paso a paso
}
