#ifndef __VOVAFUNCTIONS__
#define __VOVAFUNCTIONS__
//{=====================================================================================================================
///    \author ��������� ��������
///
///    \file   gamelib3.0.h
///
///    \defgroup    Drawing     ���������
///    \defgroup    File     ������ � �������
///    \defgroup    Movment     ��������
//}=====================================================================================================================

//functions
//{=====================================================================================================================
void fcheck(char* s);
//{=====================================================================================================================
///     \name   �������� �����
///
///     \brief  ��������� ������� ����� � ��� ������������� ����� ����� � ���������� ����������
///
///     \param  s   ��� ����� � �����
//}=====================================================================================================================


void end_game(bg_t &background, ch_t &main);
//{=====================================================================================================================
///     \name   �����
///
///     \brief  ����� ����
///
///     \param  background  ��������� ����
///     \param  main        ��������� �������� �����
//}=====================================================================================================================

void rain();
//{=====================================================================================================================
///     \name   �����
///
///     \ingroup    Drawing
///
///     \brief  ������ �����
///
///     \warning    ��� ��������� ����� �������
//}=====================================================================================================================

void easter_egg(ch_t &main);
//{=====================================================================================================================
///     \name   ��������
///
///     \ingroup    Drawing
///
///     \brief  ��������
///
///     \warning    ��� ��������� ����� �������
///
///     \param  main    ��������� �������� �����
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
    main.turn_down();
    main.set_frame(1);
    txClear();
    background.draw_background();
    main.draw_character();
    main.set_frame(18);
    txSleep(1000);
    txPlaySound("thunder.wav");
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
    main.set_name("ghost.bmp");
    main.delete_picture();
    main.load_image();
    main.set_frame(1);
    main.turn_up();
    main.set_xsize(16);
    main.set_ysize(24);
    main.set_scale(1);
    main.set_framesn(3);
    txClear();
    background.draw_background();
    main.draw_character();
    dt_t time = {0,0,0,0};
    while (main.get_ypos() > -30)
    {
        main.update_character(background, time, 'w', 0);
        txClear();
        background.draw_background();
        main.draw_character();
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
        if (j>240)
            txGetFPS();
        else
            di = 1 / txGetFPS();txSetFillColor(TX_WHITE);
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
