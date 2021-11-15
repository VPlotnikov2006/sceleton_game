//Плотников
#include "character.h"

int main()
{
    FILE* f = fopen("save.txt", "r");
    if (!f)
    {
        f = fopen("save.txt","w");
        fprintf(f,"85 100 1 17 0.75\n1\n0 0 0 0");
    }
    fclose(f);

    txCreateWindow(1080, 720);
    FILE* save = fopen("save.txt","r");

    bool back_change = 0;
    bool gsave;
    //sceleton
    //{
    ch_t main;
    main.name = "sceleton.bmp";
    if(!main.load_image())
        return 1;
    main.xsize = 64;
    main.ysize = 64;
    main.step = 5;
    main.framesn = 7;
    main.ulenght = 21;
    main.llenght = 12;
    main.dlenght = 25;
    main.rlenght = 9;
    main.get_from_file(save);
    //}
    //background
    //{
    bg_t background;
    background.xsize = 1080;
    background.ysize = 720;
    background.get_from_file(save);
    if(!background.load_image())
        return 2;
    if(!background.load_collision())
        return 3;
    //}
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

        main.update_character(background, &sit_time);
        in_game_time.update_time(200);
        sit_time.update_time(200);

        if(time_comp(sit_time, easter_egg_time))
        {
            easter_egg(main);
            sit_time = {0,0,0,0};
        }
        if(time_comp(in_game_time, end_game_time))
        {
            end_game(background,&main);
            in_game_time = {0,0,0,0};
            gsave = 0;
            remove("save.txt");
            break;
        }

        if(main.xpos - main.llenght * main.scale >= 1080)
        {
            main.xpos = -1 * main.rlenght * main.scale + main.step * main.scale;
            back_change = 1;
        }
        if(main.xpos + main.rlenght * main.scale <= 0)
        {
            main.xpos = 1080 + main.llenght * main.scale - main.step * main.scale;
        }
        if(main.ypos - main.ulenght * main.scale >= 720)
        {
            main.ypos = -1 * main.dlenght * main.scale + main.step * main.scale;
            back_change = 1;
        }
        if(main.ypos + main.dlenght * main.scale <= 0)
        {
            main.ypos = 720 + main.ulenght * main.scale - main.step * main.scale;
            back_change = 1;
        }

        if (back_change)
        {
            background.num = rand() % 3;
            txDeleteDC(background.picture);
            background.load_image();
            background.load_collision();
            back_change = 0;
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
        fclear("save.txt");
        save = fopen("save.txt", "a");
        main.put_to_file(save);
        background.put_to_file(save);
        in_game_time.put_to_file(save);
    }
    txDeleteDC(main.picture);
    txDeleteDC(background.picture);
    return 0;
}
