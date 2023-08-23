/*
  Program to control LED (ON/OFF) from ESP32 using Serial Bluetooth
  by Daniel Carrasco -> https://www.electrosoftcloud.com/
*/
#include "BluetoothSerial.h"
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif
#define LED 2
//define sound speed in cm/uS
#define SOUND_SPEED 0.034
#define CM_TO_INCH 0.393701

const int trigPin = 5;
const int echoPin = 18;

long duration;
float distanceCm;
float distanceInch;

BluetoothSerial BT; // Objeto Bluetooth
void setup() {
  Serial.begin(9600); // Inicialización de la conexión en serie para la depuración
  BT.begin("ESP32_LED_Control"); // Nombre de su dispositivo Bluetooth y en modo esclavo
  Serial.println("El dispositivo Bluetooth esta listo para emparejarse");
  pinMode (LED, OUTPUT); // Cambie el pin LED a OUTPUT
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
}
void loop() {
  /*if (BT.available()) // Compruebe si recibimos algo de Bluetooth
  {
    int incoming = BT.read(); // Lee lo que recibimos
    Serial.print("Recibido: ");
    Serial.println(incoming);
    if (incoming == 49){ // 1 en ASCII
      digitalWrite(LED, HIGH); // LED Encendido
      BT.println("LED encendido"); // Envía el mensaje de texto a través de BT Serial
    }
    if (incoming == 48){ // 0 en ASCII
      digitalWrite(LED, LOW); // LED Apagado
      BT.println("LED apagado"); // Envía el mensaje de texto a través de BT Serial
    } 
  }
  */
  //delay(20);
  //SENSOR ULTRASONICO
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance
  distanceCm = duration * SOUND_SPEED/2;
  BT.println (distanceCm);
  if(distanceCm<20){
    //BT.println("d");
    //Serial.print("d");
    //if (bandera=!1)
    //BT.print("d");
    digitalWrite(LED,HIGH);
    
    //delay(600);
  }else{
    //BT.println("n");
    //if (bandera!=2)
    //BT.print("n");
    digitalWrite(LED,LOW);
  
   // delay(600);    
  }
   delay(1000);

  
  // Convert to inches
//  Prints the distance in the Serial Monitor
  Serial.print("Distance (cm): ");
  Serial.println(distanceCm);
//  Serial.print("Distance (inch): ");
//  Serial.println(distanceInch); 
  //delay(500);
}