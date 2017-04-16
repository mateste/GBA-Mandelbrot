#include "gba.h"
#include <random>
#include <limits>

float getPixelCoordsX(u32 x)
{
    auto minX = -2.5f;
    auto maxX = 1.f;

    auto result = (static_cast<float>(x) / static_cast<float>(SCREEN_WIDTH) * (maxX - minX)) + minX;
    return result;
}

float getPixelCoordsY(u32 y)
{
    auto minY = -1.f;
    auto maxY = 1.f;

    auto result = (static_cast<float>(y) / static_cast<float>(SCREEN_HEIGHT) * (maxY - minY)) + minY;
    return result;
}

void mandelbrot()
{
    for(auto i = 0u; i < SCREEN_HEIGHT; i++)
    {
        for(auto j = 0u; j < SCREEN_WIDTH; j++)
        {
            auto x0 = getPixelCoordsX(j);
            auto y0 = getPixelCoordsY(i);
            auto x = 0.f;
            auto y = 0.f;
            auto iteration = 0u;
            for(iteration; iteration < 62u && x*x + y*y < 4; iteration++)
            {
                auto xtemp = x*x - y*y + x0;
                y = 2*x*y + y0;
                x = xtemp;
            }
            MODE3_FB[i][j] = RGB5(31 - (iteration / 2), 0, 0);
        }
    }
}

int main()
{
    irqInit();
    irqEnable(IRQ_VBLANK);
    SetMode(MODE_3 | BG2_ON);

    mandelbrot();
    while(1)
    {
        VBlankIntrWait();
    }

    return 0;
}
