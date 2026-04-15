#include "GpioPin.h"
#include <unistd.h>

/**
 * @brief Er wordt een object aangemaakt van de klasse GpioPin 
 * Deze gaat 4 seconde aan.
 */
int main() {
	
    GpioPin ledR(40); // fysieke pin 40, rockpi 135.

    ledR.pinAan();
    sleep(4);
    ledR.pinUit();

    return 0;
}
