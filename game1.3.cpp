//Плотников
#include "TXLib.h"
#include "time2.0.h"
#include "background.h"
#include "character.h"
#include "bot.h"
#include "functions.h"
#include "credit.h"


int main()
{
    fcheck("save.txt");

    txCreateWindow(1080, 720);
    FILE* save = fopen("save.txt","r");

    //Начальные титры
    credit("Через час меня казнят", 50);
    credit("Очевидно что я не виновен", 50);
    credit("Остается только пытаться искать выход", 50);
    credit("ЕСЛИ ОН ЕСТЬ", 150,255,0,0);

    //Экран загрузки
    loading();

    bool gsave;
    ch_t main(save);
    bg_t background(save);
    //time
    //{
    dt_t in_game_time(save);
    dt_t sit_time = {0,0,0,0};
    dt_t end_game_time = {0,0,0,1};
    dt_t easter_egg_time = {0,0,5,0};
    //}
    fclose(save);

    txBegin();
    int dt;
    bot_t bot(-100,-100,1);
    while(true)
    {

        dt = int(1 / (txGetFPS(1) + 1) * 1000);
        txClear();
        background.draw_background();
        main.draw_character();
        bot.draw();
        bot.swich_direction();
        bot.move_forward();
        sit_time = main.update_character(background, sit_time);
        in_game_time.update_time(dt);
        sit_time.update_time(dt);

        if(sit_time >= easter_egg_time)
        {
            easter_egg(main);
            sit_time = {0,0,0,0};
        }

        if(in_game_time >= end_game_time)
        {
            end_game(background, main);
            in_game_time = {0,0,0,0};
            gsave = 0;
            remove("save.txt");
            break;
        }

        if(main.check_border(&background))
        {
            bot.setx(rand() % 1080);
            bot.sety(rand() % 720);
            bot.setd(rand() % 4 + 1);
        }
        txSleep(100);

        if(GetAsyncKeyState(VK_ESCAPE))
        {
            gsave = 1;
            break;
        }

        if(GetAsyncKeyState(VK_F2) && GetAsyncKeyState(VK_SHIFT))
        {
            gsave = 0;
            break;
        }
    }
    txEnd();

    if (gsave)
    {
        save = fopen("save.txt", "w");
        main.put_to_file(save);
        background.put_to_file(save);
        in_game_time.put_to_file(save);
    }
    txDisableAutoPause();
    return 0;
}
