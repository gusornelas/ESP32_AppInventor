// Juan A. Villalpando
// http://kio4.com/appinventor/9A01_Bluetoot_Conec_Desco.htm

#include "BluetoothSerial.h"
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

int value_pot0;

BluetoothSerial BT; // Objeto Bluetooth
void setup() { 
  Serial.begin(9600); // Inicialización de la conexión en serie para la depuración
  BT.begin("Nivelitos_de_agua"); // Nombre de su dispositivo Bluetooth y en modo esclavo
  //Serial.println("El dispositivo Bluetooth esta listo para emparejarse");
}

void loop() { 
    int aleatorio1 = random(0, 5);
    int aleatorio2 = random(0, 5);
    BT.print(aleatorio1); //aleatorio1
    BT.print("|");
    BT.print(aleatorio2);
    BT.print("|");
    BT.print("100%"); //aleatorio1
    BT.print("|");
    BT.print("90%");
    BT.print("|");
    BT.print("\n"); // Fin de línea. Importante.
    delay(10000); // It should be slower than the Clock Interval.
}
