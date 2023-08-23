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
  BT.begin("ESP32_LED_Control"); // Nombre de su dispositivo Bluetooth y en modo esclavo

}

void loop() { 
    /*int aleatorio1 = random(0, 1000);
    int aleatorio2 = random(1, 6);
    int aleatorio3 = random(20, 200);
    int aleatorio4 = random(0, 10);*/
    BT.print(aleatorio1);
    BT.print("|");
    BT.print(aleatorio2);
    BT.print("|"); 
    /*BT.print(aleatorio3);
    BT.print("|");
    BT.print(aleatorio4);
    BT.print("|");*/
    BT.print("\n"); // Fin de línea. Importante.
    delay(300); // It should be slower than the Clock Interval.
}
