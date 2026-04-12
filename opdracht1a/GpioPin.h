#ifndef GPIOPIN_H
#define GPIOPIN_H

#include <string>
#include <gpiod.h>

/**
 * @brief Klasse voor het aansturen van een GPIO pin via libgpiod
 *
 * Deze klasse maakt gebruik van de moderne GPIO interface (character device)
 * zoals gebruikt op de Raspberry Pi 4. Elke instantie beheert één GPIO pin.
 */
class GpioPin {
public:
    /**
     * @brief Constructor
     *
     * Initialiseert de GPIO pin als output en zet deze standaard op LOW.
     *
     * @param name Naam van de applicatie (consumer name, zichtbaar in gpioinfo)
     * @param pin GPIO pin nummer (BCM numbering, bijv. 16)
     *
     * @throws std::runtime_error als initialisatie mislukt
     */
    GpioPin(const std::string& name, int pin);

    /**
     * @brief Destructor
     *
     * Geeft de GPIO pin vrij en sluit de chip netjes af.
     */
    ~GpioPin();

    /**
     * @brief Zet de GPIO pin HIGH
     *
     * Activeert de pin (3.3V op Raspberry Pi).
     */
    void pinAan();

    /**
     * @brief Zet de GPIO pin LOW
     *
     * Deactiveert de pin (0V).
     */
    void pinUit();

private:
    std::string name;                 ///< Naam van de consumer (applicatie)
    int pin;                          ///< GPIO pin nummer (BCM)

    struct gpiod_chip* chip;          ///< GPIO chip handle
    struct gpiod_line_request* request; ///< GPIO request handle
};

#endif
