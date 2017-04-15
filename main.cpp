#include "gba.h"

int main()
{
    SetMode(MODE_3 | BG2_ON);

    MODE3_FB[80][120] = RGB5(31, 0, 0);
    MODE3_FB[80][136] = RGB5(0, 31, 0);
    MODE3_FB[96][120] = RGB5(0, 0, 31);

    while(1);

    return 0;
}
