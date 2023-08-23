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
  Serial.println("El dispositivo Bluetooth esta listo para emparejarse");
}

void loop() { 
    // value_pot0 = analogRead(A0);
    value_pot0 = (int) random(0,500);
    BT.println(value_pot0);
    delay(100); // It should be slower than the Clock Interval.
}
