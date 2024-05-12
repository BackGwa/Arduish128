// Header Files
#include <inttypes.h>
#include <avr/io.h>
#include <avr/delay.h>

// Redefine Function
#define delay(ms) _delay_ms(ms)

// Const Value
#define IO_SIZE 8

#define HIGH    1
#define LOW     0

#define INPUT   0
#define OUTPUT  1

// PORTA Digital IO
const unsigned short A0[] = {0, 0};
const unsigned short A1[] = {0, 1};
const unsigned short A2[] = {0, 2};
const unsigned short A3[] = {0, 3};
const unsigned short A4[] = {0, 4};
const unsigned short A5[] = {0, 5};
const unsigned short A6[] = {0, 6};
const unsigned short A7[] = {0, 7};

// PORTB Digital IO (SPI Interface / PWM Output)
const unsigned short B0[] = {1, 0};
const unsigned short B1[] = {1, 1};
const unsigned short B2[] = {1, 2};
const unsigned short B3[] = {1, 3};
const unsigned short B4[] = {1, 4};
const unsigned short B5[] = {1, 5};
const unsigned short B6[] = {1, 6};
const unsigned short B7[] = {1, 7};

// PORTC Digital IO
const unsigned short C0[] = {2, 0};
const unsigned short C1[] = {2, 1};
const unsigned short C2[] = {2, 2};
const unsigned short C3[] = {2, 3};
const unsigned short C4[] = {2, 4};
const unsigned short C5[] = {2, 5};
const unsigned short C6[] = {2, 6};
const unsigned short C7[] = {2, 7};

// PORTD Digital IO
const unsigned short D0[] = {3, 0};
const unsigned short D1[] = {3, 1};
const unsigned short D2[] = {3, 2};
const unsigned short D3[] = {3, 3};
const unsigned short D4[] = {3, 4};
const unsigned short D5[] = {3, 5};
const unsigned short D6[] = {3, 6};
const unsigned short D7[] = {3, 7};

// PORTE Digital IO
const unsigned short E0[] = {4, 0};
const unsigned short E1[] = {4, 1};
const unsigned short E2[] = {4, 2};
const unsigned short E3[] = {4, 3};
const unsigned short E4[] = {4, 4};
const unsigned short E5[] = {4, 5};
const unsigned short E6[] = {4, 6};
const unsigned short E7[] = {4, 7};

// PORTF 8bit IO (Analog Input)
const unsigned short F0[] = {5, 0};
const unsigned short F1[] = {5, 1};
const unsigned short F2[] = {5, 2};
const unsigned short F3[] = {5, 3};
const unsigned short F4[] = {5, 4};
const unsigned short F5[] = {5, 5};
const unsigned short F6[] = {5, 6};
const unsigned short F7[] = {5, 7};


// PORT PinMode Status
int PORTA_MODE[IO_SIZE] = { 0 }, PORTB_MODE[IO_SIZE] = { 0 }, PORTC_MODE[IO_SIZE] = { 0 },
    PORTD_MODE[IO_SIZE] = { 0 }, PORTE_MODE[IO_SIZE] = { 0 }, PORTF_MODE[IO_SIZE] = { 0 };

// PORT Output Status
int PORTA_OUT[IO_SIZE] = { 0 }, PORTB_OUT[IO_SIZE] = { 0 }, PORTC_OUT[IO_SIZE] = { 0 },
    PORTD_OUT[IO_SIZE] = { 0 }, PORTE_OUT[IO_SIZE] = { 0 }, PORTF_OUT[IO_SIZE] = { 0 };


// # ArrHex
// - Convert binary in an array to Hex
int ArrHex(int arr[]) {
    int i, value = 0;
    for (i = 0; i < IO_SIZE; i++) {
        if (arr[i] == 1) {
            value |= (1 << ((IO_SIZE - 1) - i));
        }
    }
    return value;
}

// # pinMode
// - Set the PORT IO mode
void pinMode(int PORT[], int MODE) {
    const unsigned short ADDRESS = IO_SIZE - PORT[1] - 1;
    switch (PORT[0]) {
        case 0:
            PORTA_MODE[ADDRESS] = MODE;
            DDRA = ArrHex(PORTA_MODE);
            break;
        case 1:
            PORTB_MODE[ADDRESS] = MODE;
            DDRB = ArrHex(PORTB_MODE);
            break;
        case 2:
            PORTC_MODE[ADDRESS] = MODE;
            DDRC = ArrHex(PORTC_MODE);
            break;
        case 3:
            PORTD_MODE[ADDRESS] = MODE;
            DDRD = ArrHex(PORTD_MODE);
            break;
        case 4:
            PORTE_MODE[ADDRESS] = MODE;
            DDRE = ArrHex(PORTE_MODE);
            break;
        case 5:
            PORTF_MODE[ADDRESS] = MODE;
            DDRF = ArrHex(PORTF_MODE);
            break;
    }
}

// # digitalWrite
// - Set the PORT Output
void digitalWrite(int PORT[], int MODE) {
    const unsigned short ADDRESS = IO_SIZE - PORT[1] - 1;
    switch (PORT[0]) {
        case 0:
            PORTA_OUT[ADDRESS] = MODE;
            PORTA = ArrHex(PORTA_OUT);
            break;
        case 1:
            PORTB_OUT[ADDRESS] = MODE;
            PORTB = ArrHex(PORTB_OUT);
            break;
        case 2:
            PORTC_OUT[ADDRESS] = MODE;
            PORTC = ArrHex(PORTC_OUT);
            break;
        case 3:
            PORTD_OUT[ADDRESS] = MODE;
            PORTD = ArrHex(PORTD_OUT);
            break;
        case 4:
            PORTE_OUT[ADDRESS] = MODE;
            PORTE = ArrHex(PORTE_OUT);
            break;
        case 5:
            PORTF_OUT[ADDRESS] = MODE;
            PORTF = ArrHex(PORTF_OUT);
            break;
    }
}

