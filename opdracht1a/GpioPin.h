#ifndef GPIOPIN_H
#define GPIOPIN_H

#include <mraa/gpio.hpp>

/**
 * @class GpioPin
 * @brief Klasse voor het aansturen van een GPIO pin via MRAA.
 *
 * Deze klasse maakt gebruik van de MRAA library om een GPIO pin
 * te initialiseren en eenvoudig aan of uit te zetten.
 */
class GpioPin {
public:
    /**
     * @brief Constructor
     * @param pin Nummer van de GPIO pin
     *
     * Initialiseert de GPIO pin en zet deze als output.
     */
    GpioPin(int pin);

    /**
     * @brief Destructor
     *
     * Ruimt de GPIO resource op.
     */
    ~GpioPin();

    /**
     * @brief Zet de pin aan (HIGH)
     *
     * Schrijft een logische 1 naar de GPIO pin.
     */
    void pinAan();

    /**
     * @brief Zet de pin uit (LOW)
     *
     * Schrijft een logische 0 naar de GPIO pin.
     */
    void pinUit();

private:
    mraa::Gpio* gpio; /**< Pointer naar MRAA GPIO object */
};

#endif // GPIOPIN_H
