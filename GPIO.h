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

class GPIO
{
    public:
        GPIO(volatile uint8_t* ddr, volatile uint8_t* dor, volatile uint8_t* dir, const uint8_t bit);
        ~GPIO();
        const uint8_t setMode       (const uint8_t mode);
        const uint8_t write         (const uint8_t state);
        const uint8_t read          (void);
    private:
        volatile uint8_t* ddr;
        volatile uint8_t* dor;
        volatile uint8_t* dir;
        uint8_t bit;
};

#endif
