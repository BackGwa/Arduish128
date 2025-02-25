#include <inttypes.h>
#include <avr/io.h>
#include <avr/delay.h>

#define delay(ms) _delay_ms(ms)

#define IO_SIZE 8

#define HIGH    1
#define LOW     0

#define INPUT   0
#define OUTPUT  1

const unsigned short PORTS[][8] = {
    {{0,0}, {0,1}, {0,2}, {0,3}, {0,4}, {0,5}, {0,6}, {0,7}},
    {{1,0}, {1,1}, {1,2}, {1,3}, {1,4}, {1,5}, {1,6}, {1,7}},
    {{2,0}, {2,1}, {2,2}, {2,3}, {2,4}, {2,5}, {2,6}, {2,7}},
    {{3,0}, {3,1}, {3,2}, {3,3}, {3,4}, {3,5}, {3,6}, {3,7}},
    {{4,0}, {4,1}, {4,2}, {4,3}, {4,4}, {4,5}, {4,6}, {4,7}},
    {{5,0}, {5,1}, {5,2}, {5,3}, {5,4}, {5,5}, {5,6}, {5,7}}
};

int PORT_MODE[6][IO_SIZE] = {{0}}, PORT_OUT[6][IO_SIZE] = {{0}};

static inline int ArrHex(const int arr[]) {
    int value = 0;
    for (int i = 0; i < IO_SIZE; i++) {
        if (arr[i]) {
            value |= (1 << ((IO_SIZE - 1) - i));
        }
    }
    return value;
}

#define pinMode(PORT, MODE) do { \
    int addr = IO_SIZE - (PORT)[1] - 1; \
    PORT_MODE[(PORT)[0]][addr] = (MODE); \
    *((volatile uint8_t*)&DDRA + (PORT)[0]) = ArrHex(PORT_MODE[(PORT)[0]]); \
} while(0)

#define digitalWrite(PORT, MODE) do { \
    int addr = IO_SIZE - (PORT)[1] - 1; \
    PORT_OUT[(PORT)[0]][addr] = (MODE); \
    *((volatile uint8_t*)&PORTA + (PORT)[0]) = ArrHex(PORT_OUT[(PORT)[0]]); \
} while(0)