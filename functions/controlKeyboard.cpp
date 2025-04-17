#include "../include/draw.h"
void controlKeyboard(unsigned char key, bool &rainActive,bool &showMemorial,bool &isNight, bool &snowActive, bool &fireActive )
{
    if (key == 'r' || key == 'R')
    {
        if (rainActive)
            rainActive = false;
        else
            initRain(rainActive);
    }

    if (key == 'm' || key == 'M')
    {
        showMemorial = !showMemorial;
    }

    if (key == 'n' || key == 'N')
    {
        isNight = !isNight;
    }

    if (key == 's' || key == 'S')
    {
        snowActive = !snowActive;
    }

    if (key == 'f' || key == 'F')
    {
        fireActive = !fireActive;
        if (fireActive)
            initFireParticles();
    }
}