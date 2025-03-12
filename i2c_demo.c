#ifdef EMULATOR
  #include "emulator.h"
#else
  #include <neorv32.h>
#endif

#include "i2c_demo.h"

/*===========================================================
  Tarea 1: Funciones de Inicio y Parada del I2C
  -----------------------------------------------------------
  Funciones inline para generar las condiciones de inicio y 
  parada en el bus I2C.
=============================================================*/
static inline void i2c_start(void) {
  // Genera la condición de inicio en I2C.
}

static inline void i2c_stop(void) {
  // Genera la condición de parada en I2C.
}

/*===========================================================
  Tarea 2: Impresión de un Byte en Formato Hexadecimal
  -----------------------------------------------------------
  Función para imprimir un byte en formato hexadecimal usando la UART.
=============================================================*/
void print_hex_byte(uint8_t data) {
  static const char symbols[] = "0123456789abcdef";
  
  // Imprime el nibble superior (4 bits).

  // Imprime el nibble inferior (4 bits).

}

/*===========================================================
  Tarea 3: Función para Escribir un Byte en I2C
  -----------------------------------------------------------
  Se envía un byte por I2C y se verifica el acuse de recibo (ACK/NACK)
  mostrando mensajes de depuración.
=============================================================*/
static inline uint32_t i2c_write_byte(uint8_t byte) {
  // Transmitir el byte y almacenar el acuse de recibo del dispositivo.

  // Depuración (OPCIONAL): imprime el byte transmitido en hexadecimal.

  // Imprime la respuesta: "ACK" para 0, "NACK" para cualquier otro valor.

  return device_ack;
}

/*===========================================================
  Tarea 5: Función para Leer un Byte en I2C
  -----------------------------------------------------------
  Se lee un byte del bus I2C, utilizando un parámetro para configurar el
  acuse de recibo (ACK/NACK).
=============================================================*/
static inline uint8_t i2c_read_byte(int ack) {
  // Inicializa la variable con un valor por defecto.

  // Lee el byte utilizando la función de transmisión con el parámetro "ack".

  return byte;
}

/*===========================================================
  Tarea 4: Escritura de Múltiples Bytes en I2C
  -----------------------------------------------------------
  Función que envía múltiples bytes, empezando 
  por la dirección del dispositivo, luego los datos.
=============================================================*/
static uint32_t i2c_write(uint8_t dev_addr, const uint8_t *data, uint8_t len) {
  // Condición de inicio en I2C.
  
  // Envía la dirección del dispositivo (7 bits desplazados y bit de escritura 0) y se comprueba que hay ACK.
  
  // Envía cada uno de los bytes de datos, comprobando que hay ACK
  
  // Condición de parada en I2C.

  return 0;
}

/*===========================================================
  Tarea 6: Lectura de Múltiples Bytes en I2C
  -----------------------------------------------------------
  Función para leer múltiples bytes desde un 
  dispositivo I2C, enviando ACK para todos excepto el último.
=============================================================*/
static uint32_t i2c_read(uint8_t dev_addr, uint8_t *data, uint8_t len) {
  // Condición de inicio en I2C.
  
  // Envía la dirección del dispositivo con el bit de lectura (1) y se comprueba que hay ACK.
  
  // Lee 'len' bytes: Envía ACK para todos excepto el último.
  
  // Condición de parada en I2C.

  return 0;
}

/*===========================================================
  Tarea 7: Inicialización del Sensor AHT20
  -----------------------------------------------------------
  Se inicializa el sensor AHT20 enviando el comando de 
  inicialización y comprobando el estado de calibración.
=============================================================*/
#define AHT20_ADDRESS 0x38

uint32_t aht20_begin(void) {
  uint8_t init_cmd[3] = {0xBE, 0x08, 0x00};

  // Envía el comando de inicialización al sensor.
  
  // Espera para la inicialización y calibración.

  // Lee el byte de estado para comprobar la calibración.
  
  // Verifica que el bit de calibración (bit 3) esté activado.
  
  return 1;
}

/*===========================================================
  Tarea 8: Disparar una Medición
  -----------------------------------------------------------
  Se implementa la función que dispara una medición, 
  espera la medición y lee 6 bytes de datos.
  [SS] [HH] [HH] [HT] [TT] [TT]
=============================================================*/
uint32_t aht20_measure(uint8_t *data, uint8_t len) {
  uint8_t meas_cmd[3] = {0xAC, 0x33, 0x00};

  // Envía el comando para disparar la medición.
  
  // Espera a que la conversión se complete (~100 ms).

  // Lee 6 bytes de datos de medición.
  
  return 0;
}

/*===========================================================
  Tarea 9: Interpretación de los Datos de Humedad
  -----------------------------------------------------------
  Se extrae y convierte el valor en bruto de 20 bits de 
  humedad a porcentaje. [SS] [HH] [HH] [HT] [TT] [TT]
=============================================================*/
uint32_t aht20_getHumidity(const uint8_t *data) {
  uint32_t raw_hum = ((uint32_t)data[1] << 12) | ((uint32_t)data[2] << 4) | ((data[3] >> 4) & 0x0F);
  // Se realiza la conversión y se retorna la humedad en porcentaje.
  return ;
}

/*===========================================================
  Tarea 10: Interpretación de los Datos de Temperatura
  -----------------------------------------------------------
  Se extrae y convierte el valor en bruto de 20 bits de 
  temperatura a grados Celsius, incluyendo mensajes de 
  depuración para el valor obtenido. [SS] [HH] [HH] [HT] [TT] [TT]
=============================================================*/
uint32_t aht20_getTemperature(const uint8_t *data) {
  uint32_t raw_temp = (((uint32_t)(data[3] & 0x0F)) << 16) | ((uint32_t)data[4] << 8) | data[5];

  // Mensajes de depuración para el valor en bruto (OPCIONAL).
  neorv32_uart0_printf("DEBUG: raw_temp = %u\n", raw_temp);
  neorv32_uart0_printf("DEBUG: (raw_temp*200)/1048576 = %u\n", (raw_temp * 200) / 1048576 - 50);
  
  // Se realiza la conversión y se retorna la temperatura en celsius.
  return ;
}
