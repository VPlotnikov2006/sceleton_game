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
    FILE* save = fopen("save.txt","r");
    ch_t main(save);
    bg_t background(save);
    //time
    //{
    dt_t in_game_time(save);
    dt_t sit_time = {0,0,0,0};
    dt_t end_game_time = {0,0,0,1};
    dt_t easter_egg_time = {0,0,5,0};
    //}
    txSelectFont ("Times New Roman", 60);
    while(true)
    {
        if(GetAsyncKeyState(VK_ESCAPE))
        {

            /*if (action == 1)
                game_save(background, main, in_game_time);
            if (action == 2)
                break;*/
            return settings(background, main, in_game_time);
        }
    }
}
