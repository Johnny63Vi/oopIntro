#ifndef LED_H
#define LED_H

#include <string>
#include "GpioPin.h"

using namespace std;
#pragma once

#define OUTPUT 1

class Led
{
  public:
    Led(GpioPin);
    ~Led();
    void zetAan();
    void zetUit();
    string ledKleur()const;
    int isLedAan()const;
    int pinNummer() const;
    string deEigenaar() const;

  private:
    string kleur;
    int pinNr;
    int status;  
    string eigenaar;
    GpioPin pin;
};
#endif
