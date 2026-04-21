#include <unistd.h>
#include <iostream>
#include "Led.h"

using namespace std;
#define RODELED 40
#define GROENELED 38
#define GELELED 36

int main() {

    cout<<"Hi NSE"<<endl;
    Led rood(RODELED);
    Led geel(GELELED);
    Led groen(GROENELED);

    groen.zetAan();
    usleep(1000000);
    groen.zetUit();
    geel.zetAan();
    usleep(1000000);
    geel.zetUit();
    rood.zetAan();
    usleep(1000000);  
    rood.zetUit();

    cout<<"einde"<<endl;
}
