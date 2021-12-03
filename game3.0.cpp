//Плотников
#include "TXLib.h"
#include "time2.0.h"
#include "background.h"
#include "character.h"
#include "functions.h"


using namespace std;

int main()
{
    fcheck("save.txt");

    txCreateWindow(1080, 720);
    FILE* save = fopen("save.txt","r");

    bool gsave;
    ch_t main(save);
    bg_t background(save);
    //time
    //{
    dt_t in_game_time;
    in_game_time.get_from_file(save);
    dt_t sit_time = {0,0,0,0};
    dt_t end_game_time = {0,0,0,1};
    dt_t easter_egg_time = {0,0,5,0};
    //}
    fclose(save);

    txBegin();
    while(true)
    {
        txClear();

        background.draw_background();
        main.draw_character();

        sit_time = main.update_character(background, sit_time);
        in_game_time.update_time(200);
        sit_time.update_time(200);

        if(sit_time >= easter_egg_time)
        {
            easter_egg(main);
            sit_time = {0,0,0,0};
        }
        if(in_game_time >= end_game_time)
        {
            end_game(background,main);
            in_game_time = {0,0,0,0};
            gsave = 0;
            remove("save.txt");
            break;
        }

        main.check_border(&background);
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
