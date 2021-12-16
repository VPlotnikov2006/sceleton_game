//Плотников
#include "TXLib.h"
#include "time2.0.h"
#include "background.h"
#include "character.h"
#include "bot.h"
#include "functions.h"
#include "button.h"


int main()
{
    fcheck("save.txt");

    txCreateWindow(1080, 720);
    txDisableAutoPause();
    FILE* save = fopen("save.txt","r");

    loading();


    bool gsave = 0;
    int action;
    int dt;
    bot_t bot(-100,-100,1);
    ch_t main(save);
    bg_t background(save);
    dt_t in_game_time(save);
    dt_t sit_time = {0,0,0,0};
    dt_t end_game_time = {0,0,0,1};
    dt_t easter_egg_time = {0,0,5,0};

    fclose(save);
    txBegin();

    txPlaySound("bgsound.wav",SND_LOOP);
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
        bot.screamer(main);

        if(sit_time >= easter_egg_time)
        {
            easter_egg(main);
            sit_time = {0,0,0,0};
        }

        if(in_game_time >= end_game_time)
        {
            end_game(background, main);
            in_game_time = {0,0,0,0};
            remove("save.txt");
            break;
        }

        if(main.check_border(&background))
        {
            bot.setx(rand() % 1080);
            bot.sety(rand() % 720);
            bot.setd(rand() % 4 + 1);
        }

        if(GetAsyncKeyState(VK_ESCAPE))
        {
            txSelectFont ("Times New Roman", 60);
            action = settings();
            while (action != 4)
            {
                if (action == 1)
                {
                    loading();
                    game_save(background, main, in_game_time);
                    gsave = 1;
                }
                if (action == 2)
                {
                    if (gsave)
                        return 0;
                    if (txMessageBox("Ваш прогресс не сохранен\nЖелаете продолжить?","Нет сохранения") == 1)
                        return 0;
                }
                if (action == 3)
                {
                    txMessageBox("w - вперед\na - влево\ns - назад\nd - вправо", "Управление");
                }
                action = settings();
            }
            gsave = 0;
        }

        txSleep(100);
    }
    txEnd();
    return 0;
}
