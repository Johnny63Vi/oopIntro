#include "GpioPin.h"
#include <thread>
#include <chrono>

void wacht(unsigned int w) {
    std::this_thread::sleep_for(std::chrono::seconds(w));
}

int main() {
    GpioPin led("led-app", 21);

    led.pinAan();
    wacht(4);
    led.pinUit();
    
    return 0;
}
