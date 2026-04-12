#include "GpioPin.h"
#include <iostream>
#include <stdexcept>

/**
 * @brief Constructor implementatie
 */
GpioPin::GpioPin(const std::string& name, int pin)
    : name(name), pin(pin), chip(nullptr), request(nullptr)
{
    chip = gpiod_chip_open("/dev/gpiochip0");
    if (!chip) {
        throw std::runtime_error("Kan gpiochip niet openen");
    }

    struct gpiod_line_settings* settings = gpiod_line_settings_new();
    gpiod_line_settings_set_direction(settings, GPIOD_LINE_DIRECTION_OUTPUT);
    gpiod_line_settings_set_output_value(settings, GPIOD_LINE_VALUE_INACTIVE);

    struct gpiod_line_config* line_cfg = gpiod_line_config_new();
    unsigned int offsets[] = { (unsigned int)pin };

    gpiod_line_config_add_line_settings(line_cfg, offsets, 1, settings);

    struct gpiod_request_config* req_cfg = gpiod_request_config_new();
    gpiod_request_config_set_consumer(req_cfg, name.c_str());

    request = gpiod_chip_request_lines(chip, req_cfg, line_cfg);
    if (!request) {
        gpiod_chip_close(chip);
        throw std::runtime_error("GPIO request mislukt");
    }

    // Opruimen tijdelijke configuratie structuren
    gpiod_line_settings_free(settings);
    gpiod_line_config_free(line_cfg);
    gpiod_request_config_free(req_cfg);
}

/**
 * @brief Destructor implementatie
 */
GpioPin::~GpioPin()
{
    if (request)
        gpiod_line_request_release(request);

    if (chip)
        gpiod_chip_close(chip);
}

/**
 * @brief Zet pin HIGH
 */
void GpioPin::pinAan()
{
    gpiod_line_request_set_value(request, pin, GPIOD_LINE_VALUE_ACTIVE);
}

/**
 * @brief Zet pin LOW
 */
void GpioPin::pinUit()
{
    gpiod_line_request_set_value(request, pin, GPIOD_LINE_VALUE_INACTIVE);
}
