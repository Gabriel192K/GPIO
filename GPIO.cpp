/* Dependencies */
#include "GPIO.h"

/*!
 * @brief  GPIO constructor
 * @param  ddr
 *         The data direction register address
 * @param  dor
 *         The data output register address
 * @param  ddr
 *         The data input register address
 * @param  bit
 *         The bit value
 */
GPIO::GPIO(volatile uint8_t* ddr, volatile uint8_t* dor, volatile uint8_t* dir, const uint8_t bit)
{
    this->ddr = ddr;
    this->dor = dor;
    this->dir = dir;
    this->bit = bit;
}

/*!
 * @brief  GPIO destructor
 */
GPIO::~GPIO()
{
    this->ddr = NULL;
    this->dor = NULL;
    this->dir = NULL;
    this->bit = 0xFF;
}

/*!
 * @brief  Setting the mode of operation of GPIO
 * @param  mode
 *         The mode of operation of GPIO
 * @return True if was succesfull, otherwise false if mode of operation was invalid
 */
const uint8_t GPIO::setMode(const uint8_t mode)
{
    switch (mode)
    {
        case INPUT:
            *this->ddr = *this->ddr & ~(1 << this->bit);
            break;
        case OUTPUT:
            *this->ddr = *this->ddr | (1 << this->bit);
            break;
        case INPUT_PULLUP:
            *this->ddr = *this->ddr & ~(1 << this->bit);
            *this->dor = *this->dor | (1 << this->bit);
            break;
        default:
            return (0);
    }
    return (1);
}

/*!
 * @brief  Setting the state of GPIO
 * @param  state
 *         The state of GPIO
 * @return True if was succesfull, otherwise false if state was invalid
 */
const uint8_t GPIO::write(const uint8_t state)
{
    if ((this->ddr == NULL) || (this->dor == NULL))
        return (0);
    switch (state)
    {
        case LOW:
            *this->dor = *this->dor & ~(1 << this->bit);
            break;
        case HIGH:
            *this->dor = *this->dor | (1 << this->bit);
            break;
        case TOGGLE:
            *this->dor = *this->dor ^ (1 << this->bit);
            break;
        default:
            return (0);
    }
    return (1);
}

/*!
 * @brief  Reading the state of GPIO
 * @return The state of GPIO
 */
const uint8_t GPIO::read(void)
{
    return ((*this->dir >> this->bit) & 1);
}
