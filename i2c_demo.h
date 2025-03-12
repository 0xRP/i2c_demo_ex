#ifdef EMULATOR
#else
#include <neorv32.h>
#endif

#include <stdint.h>
#include <string.h>

#define ACK 0
#define NACK 1

#define READ 1
#define WRITE 0

void print_hex_byte(uint8_t data);
uint32_t aht20_begin(void);
uint32_t aht20_measure(uint8_t *data, uint8_t len);
uint32_t aht20_getHumidity(const uint8_t *data);
uint32_t aht20_getTemperature(const uint8_t *data);
