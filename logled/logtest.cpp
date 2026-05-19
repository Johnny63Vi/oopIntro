#include <iostream> // nodig voor cout (schrijven naar scherm)
#include <unistd.h>
#include "Logled.h"
using namespace std;
#define RODELEDPIN 40
#define GROENELEDPIN 36
#define TWEE_SEC 2000000
#define DRIE_SEC 3000000

int main() {
  //Een object van de klasse Logled met een maximale ’aan’ tijd van 2 seconde
   Logled logger(RODELEDPIN,"rood","Pietje Puk",0,2);
   logger.zetAan("rood");
   usleep(DRIE_SEC); //wacht 3 seconden
   logger.zetUit();
   logger.zetAan("rood");//led gaat niet meer aan.
   return 0;
}
