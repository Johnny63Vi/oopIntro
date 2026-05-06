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
    Led(int);
    ~Led();
    void zetAan();
    void zetUit();
    string ledKleur()const;
    int isLedAan()const;
    string deEigenaar() const;

  private:
    string kleur;
    int status;  
    string eigenaar;
    GpioPin pin;
};
#endif
