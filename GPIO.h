#ifndef __GPIO_H__
#define __GPIO_H__

/* Dependencies */
#include <stddef.h>
#include <avr/io.h>

/* Macros */
#ifndef INPUT
#define INPUT        (const uint8_t)0
#endif
#ifndef OUTPUT
#define OUTPUT       (const uint8_t)1
#endif
#ifndef INPUT_PULLUP
#define INPUT_PULLUP (const uint8_t)2
#endif
#ifndef LOW
#define LOW          (const uint8_t)0
#endif
#ifndef HIGH
#define HIGH         (const uint8_t)1
#endif
#ifndef TOGGLE
#define TOGGLE       (const uint8_t)2
#endif

/**
 * @brief GPIO class to control GPIO pins.
 */
class GPIO
{
    public:
        /**
         * @brief Constructor: Initializes the GPIO object with the given DDR, DOR, DIR registers and bit.
         * @param ddr Data Direction Register
         * @param dor Data Output Register
         * @param dir Data Input Register
         * @param bit Bit position in the registers
         */
        GPIO(volatile uint8_t* ddr, volatile uint8_t* dor, volatile uint8_t* dir, const uint8_t bit);

        /**
         * @brief Destructor: Cleans up the GPIO object.
         */
        ~GPIO();

        /**
         * @brief Sets the mode of the GPIO pin (INPUT, OUTPUT, INPUT_PULLUP).
         * @param mode Mode to set
         * @return True if successful, otherwise false if mode was invalid
         */
        const uint8_t setMode(const uint8_t mode);

        /**
         * @brief Writes a state to the GPIO pin (LOW, HIGH, TOGGLE).
         * @param state State to set
         * @return True if successful, otherwise false if state was invalid
         */
        const uint8_t write(const uint8_t state);

        /**
         * @brief Reads the current state of the GPIO pin.
         * @return The state of the GPIO pin
         */
        const uint8_t read(void);

    private:
        volatile uint8_t* ddr; /**< Data Direction Register */
        volatile uint8_t* dor; /**< Data Output Register */
        volatile uint8_t* dir; /**< Data Input Register */
        uint8_t bit;           /**< Bit position in the registers */
};

#endif
