#include <TXLib.h>
#include <time.h>

#ifndef __VOVACREDIT__
#define __VOVACREDIT__

void credit(char *str, int scale, int r = 255, int g = 255, int b = 255)
{
    txSetFillColor(TX_BLACK);
    txSelectFont("Times New Roman", scale);
    txSetTextAlign(TA_CENTER);
    int xsize = txGetTextExtentX(str);
    int ysize = txGetTextExtentY(str);
    while (!GetAsyncKeyState(VK_LBUTTON))
    {

        txClear();
        txSetColor(RGB(r,g,b));
        txTextOut(540,360 - ysize / 2,str);
        txSleep(5);
        if(r > 0)
            r--;
        if(b > 0)
            b--;
        if(g > 0)
            g--;
        if(r == 0 && b == 0 && g == 0)
            break;
    }
}

void loading()
{
    srand(time(NULL));
    txSetColor(TX_WHITE,5);
    for (int arc = 1; arc < 360; arc++)
    {
        txSetFillColor(TX_BLACK);
        txClear();
        txSetFillColor(TX_WHITE);
        txArc(515,335,565,385,0,arc);
        txSleep(0);

    }

    for (int arc = 0; arc < 360; arc++)
    {
        txSetFillColor(TX_BLACK);
        txClear();
        txSetFillColor(TX_WHITE);
        txArc(515,335,565,385,arc, 360 - arc);
        txSleep(0);
    }
    while (true)
    {
        for (int arc = 1; arc < 360; arc++)
        {
            txSetFillColor(TX_BLACK);
            txClear();
            txSetFillColor(TX_WHITE);
            txArc(515,335,565,385,0,arc);
            txSleep(0);
            if (rand()%100 == 1)
                return;

        }

        for (int arc = 0; arc < 360; arc++)
        {
            txSetFillColor(TX_BLACK);
            txClear();
            txSetFillColor(TX_WHITE);
            txArc(515,335,565,385,arc, 360 - arc);
            txSleep(0);
            if (rand()%100 == 1)
                return;
        }

    }
}

#endif
