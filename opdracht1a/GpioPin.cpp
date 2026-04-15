#include "GpioPin.h"
#include <stdexcept>

/**
 * @brief Constructor implementatie
 */
GpioPin::GpioPin(int pin) {
    gpio = new mraa::Gpio(pin);

    if (gpio == nullptr) {
        throw std::runtime_error("Kan GPIO niet initialiseren");
    }

    gpio->dir(mraa::DIR_OUT);
}

/**
 * @brief Destructor implementatie
 */
GpioPin::~GpioPin() {
    if (gpio != nullptr) {
        delete gpio;
        gpio = nullptr;
    }
}

/**
 * @brief Zet de pin aan (HIGH)
 */
void GpioPin::pinAan() {
    gpio->write(1);
}

/**
 * @brief Zet de pin uit (LOW)
 */
void GpioPin::pinUit() {
    gpio->write(0);
}
