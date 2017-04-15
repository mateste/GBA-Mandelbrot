#include "gba.h"
#include <random>
#include <limits>

int main()
{
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<u16> dis;
    std::uniform_int_distribution<u32> widthDis(0, SCREEN_WIDTH);
    std::uniform_int_distribution<u32> heightDis(0, SCREEN_HEIGHT);

    irqInit();
    irqEnable(IRQ_VBLANK);
    SetMode(MODE_3 | BG2_ON);

    while(1)
    {
        VBlankIntrWait();
        for(auto i = 0u; i < 1000; i++)
        {
            MODE3_FB[heightDis(gen)][widthDis(gen)] = dis(gen);
        }
    }

    return 0;
}
