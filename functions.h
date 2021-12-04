#ifndef __VOVAFUNCTIONS__
#define __VOVAFUNCTIONS__
//{=====================================================================================================================
///    \author Плотников Владимир
///
///    \file   gamelib3.0.h
///
///    \defgroup    Drawing     Рисование
///    \defgroup    File     Работа с файлами
///    \defgroup    Movment     Движение
//}=====================================================================================================================

//functions
//{=====================================================================================================================
void fcheck(char* s);
//{=====================================================================================================================
///     \name   Проверка файла
///
///     \brief  Проверяет наличие файла и при необходимости пишет новый с деволтными значениями
///
///     \param  s   Имя файла с типом
//}=====================================================================================================================


void end_game(bg_t &background, ch_t &main);
//{=====================================================================================================================
///     \name   Финал
///
///     \brief  Финал игры
///
///     \param  background  Структура фона
///     \param  main        Структура главного героя
//}=====================================================================================================================

void rain();
//{=====================================================================================================================
///     \name   Дождь
///
///     \ingroup    Drawing
///
///     \brief  Рисует дождь
///
///     \warning    Ваш компьютер может сгореть
//}=====================================================================================================================

void easter_egg(ch_t &main);
//{=====================================================================================================================
///     \name   Пасхалка
///
///     \ingroup    Drawing
///
///     \brief  Пасхалка
///
///     \warning    Ваш компьютер может сгореть
///
///     \param  main    Структура главного героя
//}=====================================================================================================================
//}=====================================================================================================================

//initialization
//functions
//{=====================================================================================================================
void fcheck(char* s)
{
    FILE* f = fopen(s, "r");
    if (!f)
    {
        f = fopen(s,"w");
        fprintf(f,"85 100 1 17 0.75\n1\n0 0 0 0");
    }
    fclose(f);
}

void end_game(bg_t &background, ch_t &main)
{
    bot_t bot(main.get_xpos(), main.get_ypos(), 1);
    main.turn_down();
    main.set_frame(1);
    txClear();
    background.draw_background();
    main.draw_character();
    main.set_frame(18);
    txPlaySound("thunder.wav");
    txSleep(1000);

    for (int i = 0; i < 5; i++)
    {
        txSleep(50);
        txClear();
        txSetFillColor(TX_WHITE);
        txSetColor(TX_WHITE);
        txRectangle(0,0,1080,720);
        txSleep(50);
        txClear();
        background.draw_background();
        main.draw_character();
    }
    txClear();
    background.draw_background();
    bot.draw();
    dt_t time = {0,0,0,0};
    while (bot.move_forward())
    {

        txClear();
        background.draw_background();
        bot.draw();
        txSleep(40);
    }
}

void rain()
{
    int x,y;
    txSetColor(RGB(50,50,50),1);
    for (int i = 0; i< 800;i++)
    {
        x = rand()%1100;
        y = rand()%800;
        txLine(x,y,x-10,y-25);
    }
}

void easter_egg(ch_t &main)
{
    main.do_sit();
    double i = 0;
    double di = 0.010;
    txPlaySound("Hello_darknes_my_old_friend.wav");
    for (double j = 250; j >= 100 && i < 33.5 && !GetAsyncKeyState(VK_ESCAPE); j -= 0.5, i += di )
    {
        di = 1 / (txGetFPS(1) + 5);
        txSetFillColor(TX_WHITE);
        txClear();
        txSetColor(RGB(j,j,j));
        txSetFillColor(RGB(j,j,j));
        txRectangle(0,0,1080,720);
        main.draw_character();
        rain();
        txSleep(10);
    }
    for(;i<33.5 && !GetAsyncKeyState(VK_ESCAPE); i += di)
    {
        di = 1 / txGetFPS();
        txSetFillColor(TX_WHITE);
        txClear();
        txSetColor(RGB(100,100,100));
        txSetFillColor(RGB(100,100,100));
        txRectangle(0,0,1080,720);
        main.draw_character();
        rain();
        txSleep(10);
    }
}
//}=====================================================================================================================
#endif
