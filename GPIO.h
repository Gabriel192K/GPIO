#ifndef __GPIO_H__
#define __GPIO_H__

/* Dependencies */
#include <stddef.h>
#include <avr/io.h>

/* Macros */
#define INPUT  (uint8_t)0
#define OUTPUT (uint8_t)1
#define LOW    (uint8_t)0
#define HIGH   (uint8_t)1
#define TOGGLE (uint8_t)2

class GPIO
{
    public:
        GPIO(volatile uint8_t* ddr, volatile uint8_t* dor, volatile uint8_t* dir, const uint8_t bit);
        ~GPIO();
        const uint8_t setMode(const uint8_t mode);
        const uint8_t write  (const uint8_t state);
        const uint8_t read   (void);
    private:
        volatile uint8_t* ddr;
        volatile uint8_t* dor;
        volatile uint8_t* dir;
        uint8_t bit;
};

#endif
