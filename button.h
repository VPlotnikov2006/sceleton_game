#ifndef __VOVACREDIT__
#define __VOVACREDIT__
#include <time.h>

typedef class Button butt_t;
class Button
{
private:
    int x1;
    int y1;
    char* name;
    int y2 = y1 + txGetTextExtentY(name);
    int x2 = x1 + txGetTextExtentX(name);
public:
    Button(int x, int y, char* Name): x1(x), y1(y), name(Name)
    {}
    bool get_condition()
    {
        int mx = txMouseX();
        int my = txMouseY();
        if(x1 <= mx && mx <= x2 && y1 <= my && my <= y2 && GetAsyncKeyState(VK_LBUTTON))
        {
            while(GetAsyncKeyState(VK_LBUTTON));
            mx = txMouseX();
            my = txMouseY();
            return (x1 <= mx && mx <= x2 && y1 <= my && my <= y2);
        }
    }
    void draw()
    {
        txSetColor(RGB(243, 202, 32), 5);
        txSetTextAlign(TA_LEFT);
        txSelectFont ("Times New Roman", 60);
        txDrawText(x1,y1,x2,y2,name,TA_LEFT);
        txLine(x1-10,y1, x2+10, y1);
        txLine(x2+10,y1, x2+10, y2);
        txLine(x2+10,y2, x1-10,y2);
        txLine(x1-10,y2, x1-10, y1);
    }
};

int settings()
{


    txPlaySound(NULL);
    butt_t b1(100, 100, "Сохранить");
    butt_t b2(100, 200, "Выйти");
    butt_t b3(100, 300, "Управление");
    butt_t b4(100, 400, "Продолжить");

    txSetFillColor(RGB(53, 22, 70));
    txClear();
    b1.draw();
    b2.draw();
    b3.draw();
    b4.draw();
    while (true)
    {
        txClear();
        b1.draw();
        b2.draw();
        b3.draw();
        b4.draw();
        if(b1.get_condition())
        {
            return 1;
        }
        if(b2.get_condition())
        {
            return 2;
        }
        if(b3.get_condition())
        {
            return 3;
        }
        if(b4.get_condition())
        {
            return 4;
        }
        txSleep(50);
    }
}

void game_save(bg_t &bg, ch_t &ch, dt_t &t)
{
    FILE* save = fopen("save.txt", "w");
    ch.put_to_file(save);
    bg.put_to_file(save);
    t.put_to_file(save);
}

void loading()
{
    srand(time(NULL));
    txSetColor(TX_WHITE,5);
    /*for (int arc = 1; arc < 360; arc++)
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
    }*/
    while (true)
    {
        for (int arc = 1; arc < 360; arc++)
        {
            txSetFillColor(TX_BLACK);
            txClear();
            txSetFillColor(TX_WHITE);
            txArc(515,335,565,385,0,arc);
            txSleep(0);
            if (rand()%500 == 1)
                return;

        }

        for (int arc = 0; arc < 360; arc++)
        {
            txSetFillColor(TX_BLACK);
            txClear();
            txSetFillColor(TX_WHITE);
            txArc(515,335,565,385,arc, 360 - arc);
            txSleep(0);
            if (rand()%500 == 1)
                return;
        }

    }
}

#endif
