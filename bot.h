#ifndef __VBOT__
#define __VBOT__

//{=====================================================================================================================
///    \author ��������� ��������
///
///    \file   character.h
///
///    \defgroup    Drawing     ���������
///    \defgroup    File     ������ � �������
///    \defgroup    Movment     ��������
//}=====================================================================================================================

typedef class Bot bot_t;

//Bot
//{=====================================================================================================================
///     \name   ����� ����
class Bot
{
private:
    /// <= ���������� �� ��� X �������� �������� ���������� �� ������
    double xpos;
    /// <= ���������� �� ��� Y �������� �������� ���������� �� ������
    double ypos;
    /// <= ������ ������ ����� �� ��� X
    double xsize;
    /// <= ������ ������ ����� �� ��� Y
    double ysize;
    /// <= ���������� ������ ��������
    HDC picture;
    /// <= ����������� �������� ���������
    int direction;
    /// <= ����� ����� �������� ���������
    int frame;
    /// <= ������
    double scale;
    /// <= ����� ������ ����
    int step;
    /// <= ���-�� ������ � �������� ��������
    int framesn;
    /// <= ��� �������� � ������� ����� �������� (sceleton) � �����
    char* name;

    void move_up();
    //{=====================================================================================================================
    ///     \name       �������� �����
    ///
    ///     \ingroup    Movment
    ///
    ///     \brief      ������� ��������� � ����������� �����
    //}=====================================================================================================================

    void move_left();
    //{=====================================================================================================================
    ///     \name       �������� �����
    ///
    ///     \ingroup    Movment
    ///
    ///     \brief      ������� ��������� � ����������� �����
    //}=====================================================================================================================

    void move_down();
    //{=====================================================================================================================
    ///     \name       �������� ����
    ///
    ///     \ingroup    Movment
    ///
    ///     \brief      ������� ��������� � ����������� ����
    //}=====================================================================================================================

    void move_right();
    //{=====================================================================================================================
    ///     \name       �������� ������
    ///
    ///     \ingroup    Movment
    ///
    ///     \brief      ������� ��������� � ����������� ������
    //}=====================================================================================================================

    bool load_image();
    //{=====================================================================================================================
    ///     \name       ������ ��������
    ///
    ///     \ingroup    File
    ///
    ///     \brief      ������ �������� �� ����� name + ".bmp"
    ///
    ///     \warning    ���� ������ ����� ��� �� - Undefined Behavior
    ///
    ///     \return     True ���� ������� ��������, False ���� ��� ������ �����
    //}=====================================================================================================================


public:
     Bot(int x, int y, int d)://{
          xpos(x),
          ypos(y),
          xsize(48),
          ysize(48),
          picture(nullptr),
          direction(d),
          frame(1),
          scale(1),
          step(5),
          framesn(1),
          name("ghost.bmp")//}
    {
        load_image();
    }

    Bot()://{
          xpos(0),
          ypos(0),
          xsize(48),
          ysize(48),
          picture(nullptr),
          direction(1),
          frame(1),
          scale(1),
          step(5),
          framesn(1),
          name("ghost.bmp")//}
    {
        load_image();
    }
    ~Bot()
    {
        txDeleteDC(picture);
    }
    Bot(const Bot &b)://{
                    xpos(b.xpos),
                    ypos(b.ypos),
                    xsize(b.xsize),
                    ysize(b.ysize),
                    picture(nullptr),
                    direction(b.direction),
                    frame(b.frame),
                    scale(b.scale),
                    step(b.step),
                    framesn(b.framesn),
                    name(b.name)//}
    {
        load_image();
    }
    Bot& operator=(Bot b)
    {
        xpos = b.xpos;
        ypos = b.ypos;
        xsize = b.xsize;
        ysize = b.ysize;
        picture = nullptr;
        direction = b.direction;
        frame = b.frame;
        scale = b.scale;
        step = b.step;
        framesn = b.framesn;
        name = b.name;
        load_image();
        return *this;
    }
    void delete_image()
    {
        txDeleteDC(picture);
    }
    void setx(int x)
    {
        xpos = x;
    }
    void sety(int y)
    {
        ypos = y;
    }
    void setd(int d)
    {
        direction = d;
    }
    bool move_forward();
    //{=====================================================================================================================
    ///     \name       �������� ������
    ///
    ///     \ingroup    Movment
    ///
    ///     \brief      ������� ��������� � ��������������� �� �������
    ///
    ///     \return     True ���� �������� �� ������, ����� False
    //}=====================================================================================================================

    void swich_direction();
    //{=====================================================================================================================
    ///     \name       ����� �����������
    ///
    ///     \ingroup    Movment
    ///
    ///     \brief      � ������������ 0.25 ������ ����������� ���������
    //}=====================================================================================================================

    void draw();
    //{=====================================================================================================================
    ///     \name       ������
    ///
    ///     \ingroup    Drawing
    ///
    ///     \brief      ������ ����
    //}=====================================================================================================================

};
//}=====================================================================================================================

//Initialization
//Bot
//{=====================================================================================================================
bool Bot::move_forward()
{
    frame = frame%framesn + 1;
    if (direction == 1)
        move_up();
    if (direction == 2)
        move_left();
    if (direction == 3)
        move_down();
    if (direction == 4)
        move_right();
    if (ypos - ysize > 720 || ypos + ysize < 0 || xpos - xsize > 1080 || xpos + xsize < 0)
        return 0;
    return 1;
}
void Bot::move_up()
{
    ypos -= step * scale;
}
void Bot::move_left()
{
    xpos -= step * scale;
}
void Bot::move_down()
{
    ypos += step * scale;
}
void Bot::move_right()
{
    xpos += step * scale;
}

void Bot::swich_direction()
{
    int b = rand() % 12;
    if (1 <= b && b <= 4)
        direction = b;
}

void Bot::draw()
{
    Win32::TransparentBlt(txDC(),
                          int(xpos - scale * xsize / 2),
                          int(ypos - scale * ysize / 2),
                          int(xsize * scale),
                          int(ysize * scale),
                          picture,
                          int((frame - 1) * xsize),
                          int((direction - 1) * ysize),
                          int(xsize),
                          int(ysize),
                          RGB(254,254,255));
}

bool Bot::load_image()
{
    picture = txLoadImage(name);
    if (!picture)
    {
        txMessageBox("������","�� ������ ���� � ����������");
        return 0;
    }
    return 1;
}
//}=====================================================================================================================
#endif
