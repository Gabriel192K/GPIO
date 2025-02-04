# GPIO
- GPIO library to control GPIOs.

## Key features
- Compatible with `Arduino IDE` & `Microchip Studio IDE`.
- Able to sent the mode of operation such as `INPUT`, `OUTPUT`, `INPUT_PULLUP`.
- Able to set `LOW`, `HIGH`, `TOGGLE` output state.

## Tested on
- ATmega328P @16MHz with `Arduino IDE` & `Microchip Studio IDE`.

## Example Code

```cpp
#include <GPIO.h>

// Define the registers and bit for the GPIO pin
#define DDRB_REG &DDRB
#define PORTB_REG &PORTB
#define PINB_REG &PINB
#define PIN_BIT 5

int main()
{
    GPIO pin(DDRB_REG, PORTB_REG, PINB_REG, PIN_BIT);

    // Initialize pin as an output
    pin.setMode(OUTPUT);
    while (1)
    {
        // Toggle the state of the pin
        pin.write(TOGGLE);
    }

    return 0;
}