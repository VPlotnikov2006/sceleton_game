#ifndef __VOVABACKGROUND__
#define __VOVABACKGROUND__
//{=====================================================================================================================
///    \author ��������� ��������
///
///    \file   background.h
///
///    \defgroup    Drawing     ���������
///    \defgroup    File     ������ � �������
///    \defgroup    Movment     ��������
//}=====================================================================================================================

//Global variables
//{=====================================================================================================================
char back_name[22] = {"background_blocks.bmp"};
char back_collision_name[6][26] = {"background1_collision.txt",
                                   "background2_collision.txt",
                                   "background3_collision.txt",
                                   "background4_collision.txt",
                                   "background5_collision.txt",
                                   "background6_collision.txt"};
//}=====================================================================================================================

typedef class Background bg_t;

//Background
//{=====================================================================================================================
///     \name   ��������� ����
class Background
{
private:
    /// <= �������, ���������� �������, ���������������� �������� ������ 24X24
    int ground[30][45];
    /// <= ���������� �������� � �������
    HDC picture;
    /// <= ����� �������� ����� ���� (�� 0 �� nummax)
    int num;
    /// <= ������������ ��������� num
    int nummax;
public:
    Background (const Background &bg);
    Background operator=(Background bg);
    Background(FILE* f);
    ~Background();
    void delete_picture();
    //{=====================================================================================================================
    ///     \name       ������� �������
    ///
    ///     \brief      ������� ��������
    //}=====================================================================================================================

    void change();
    //{=====================================================================================================================
    ///     \name       ����� ����
    ///
    ///     \brief      ������ ���
    //}=====================================================================================================================

    int get_cell(int y, int x);
    //{=====================================================================================================================
    ///     \name       ������
    ///
    ///     \brief      ���������� �������� ������
    ///
    ///     \param  x   ����� ������ �� ��� X (x �� 0 �� 44)
    ///     \param  y   ����� ������ �� ��� Y (y �� 0 �� 29)
    ///
    ///     \return     �������� ������
    //}=====================================================================================================================

    void get_from_file(FILE* f);
    //{=====================================================================================================================
    ///     \name       ����� �� �����
    ///
    ///     \ingroup    File
    ///
    ///     \brief      ����� num �� ����� save.txt
    ///
    ///     \param  f   ��������� �� ���� ���������� � ������� ������
    ///
    ///     \warning    ���� ������ ����� ��� �� - Undefined Behavior
    //}=====================================================================================================================

    void put_to_file(FILE* f);
    //{=====================================================================================================================
    ///     \name       �������� � ����
    ///
    ///     \ingroup    File
    ///
    ///     \brief      ������ num � ����� ����� save.txt
    ///
    ///     \param  f   ��������� �� ���� ���������� � ������� �����������
    ///
    ///     \warning    ���� ������ ����� ��� �� ������� �����
    //}=====================================================================================================================

    bool load_image();
    //{=====================================================================================================================
    ///     \name       ������ ��������
    ///
    ///     \ingroup    File
    ///
    ///     \brief      ������ �������� �� ����� � ������ � ���������� back_name
    ///
    ///     \warning    ���� ������ ����� ��� �� - Undefined Behavior
    ///
    ///     \return     True ���� ������� ��������, False ���� ��� ������ �����
    //}=====================================================================================================================

    bool load_ground();
    //{=====================================================================================================================
    ///     \name       ������� �� �����
    ///
    ///     \ingroup    File
    ///
    ///     \brief      ��������� �������� ������ �� ����� � ������ � ���������� back_collision_name[num]
    ///
    ///     \warning    ���� ������ ����� ��� �� - Undefined Behavior
    ///
    ///     \return     True ���� ������� ��������, False ���� ��� ������ �����
    //}=====================================================================================================================

    void draw_background();
    //{=====================================================================================================================
    ///     \name       ���������� ���
    ///
    ///     \ingroup    Drawing
    ///
    ///     \brief      ������ ���
    //}=====================================================================================================================

};
//}=====================================================================================================================

//Initialization
//Background
//{======================================================================================================================
Background::Background (const Background &bg) : //{
                                               picture(nullptr),
                                               num(bg.num),
                                               nummax(bg.nummax)
                                               //}
{
    load_image();
    load_ground();
}

Background Background::operator=(Background bg)
{
    picture = nullptr;
    num = bg.num;
    nummax = bg.nummax;
    load_image();
    load_ground();
    return *this;
}

Background::~Background()
{
    delete_picture();
}

Background::Background(FILE* f) : //{
                                 picture(nullptr),
                                 num(3),
                                 nummax(3)
                                 //}
{
    get_from_file(f);
    load_image();
    load_ground();
}

void Background::delete_picture()
{
    txDeleteDC(picture);
}

void Background::change()
{
    num = rand() % (nummax + 1);
    load_ground();
}

void Background::get_from_file(FILE* f)
{
    fscanf(f, "%d", &num);

}
void Background::put_to_file(FILE* f)
{
    fprintf(f, "%d\n", num);
}

bool Background::load_image()
{
    picture = txLoadImage(back_name);
    if (!picture)
    {
        txMessageBox("������","�� ������ ���� � ����������");
        return 0;
    }
    return 1;
}
bool Background::load_ground()
{
    FILE* f = fopen(back_collision_name[num], "r");
    if (!f)
    {
        txMessageBox("������","�� ������ ���� � ����������");
        return 0;
    }
    for (int i = 0; i < 30; i++)
    {
        for(int j = 0; j < 45; j++)
        {
            fscanf(f, "%d", &ground[i][j]);
        }
    }

    fclose(f);
    return 1;
}

int Background::get_cell(int y, int x)
{
    return ground[y][x];
}

//������� �� 81 if/else
void Background::draw_background()
{
    int a;
    for (int i = 0; i < 30; i++)
    {
        for (int j = 0; j < 45; j++)
        {
            a = get_cell(i,j);
            if (a == 1)
            {
                int b;
                if(i == 0)
                {
                    if(j == 0)
                    {
                        if(get_cell(1,0) == 1 && get_cell(0,1) == 1)
                            b = 7;
                        else if(get_cell(1,0) == 1)
                            b = 4;
                        else if(get_cell(0,1) == 1)
                            b = 5;
                        else
                            b = 26;
                    }
                    else if(j == 44)
                    {
                        if(get_cell(1,44) == 1 && get_cell(0,43) == 1)
                            b = 8;
                        else if(get_cell(1,44) == 1)
                            b = 4;
                        else if(get_cell(0,43) == 1)
                            b = 6;
                        else
                            b = 26;
                    }
                    else
                    {
                        if(get_cell(1,j) == 1 && get_cell(0,j - 1) == 1 && get_cell(0,j + 1))
                            b = 11;
                        else if(get_cell(1,j) == 1 && get_cell(0,j - 1))
                            b = 8;
                        else if(get_cell(1,j) == 1 && get_cell(0,j + 1))
                            b = 7;
                        else if(get_cell(0,j - 1) == 1 && get_cell(0,j + 1) == 1)
                            b = 2;
                        else if(get_cell(0,j + 1) == 1)
                            b = 5;
                        else if(get_cell(0,j - 1) == 1)
                            b = 6;
                        else if(get_cell(1,j) == 1)
                            b = 4;
                        else
                            b = 26;
                    }
                }
                else if(i == 29)
                {
                    if(j == 0)
                    {
                        if(get_cell(28,0) == 1 && get_cell(29,1) == 1)
                            b = 9;
                        else if(get_cell(28,0) == 1)
                            b = 3;
                        else if(get_cell(29,1) == 1)
                            b = 5;
                        else
                            b = 26;
                    }
                    else if(j == 44)
                    {
                        if(get_cell(28,44) == 1 && get_cell(29,43) == 1)
                            b = 10;
                        else if(get_cell(28,44) == 1)
                            b = 3;
                        else if(get_cell(29,43) == 1)
                            b = 6;
                        else
                            b = 26;
                    }
                    else
                    {
                        if(get_cell(28,j) == 1 && get_cell(29,j - 1) == 1 && get_cell(29,j + 1))
                            b = 12;
                        else if(get_cell(28,j) == 1 && get_cell(29,j - 1))
                            b = 10;
                        else if(get_cell(28,j) == 1 && get_cell(29,j + 1))
                            b = 9;
                        else if(get_cell(29,j - 1) == 1 && get_cell(29,j + 1) == 1)
                            b = 2;
                        else if(get_cell(29,j + 1) == 1)
                            b = 5;
                        else if(get_cell(29,j - 1) == 1)
                            b = 6;
                        else if(get_cell(28,j) == 1)
                            b = 3;
                        else
                            b = 26;
                    }
                }
                else
                {
                    if(j == 0)
                    {
                        if(get_cell(i + 1,j) == 1 && get_cell(i,j+1) == 1 && get_cell(i-1,j))
                            b = 25;
                        else if(get_cell(i + 1,0) == 1 && get_cell(i,1) == 1)
                            b = 7;
                        else if(get_cell(i - 1,0) == 1 && get_cell(i,1) == 1)
                            b = 9;
                        else if(get_cell(i-1,0) == 1 && get_cell(i+1,0) == 1)
                            b = 1;
                        else if(get_cell(i,1) == 1)
                            b = 5;
                        else if(get_cell(i+1,0) == 1)
                            b = 4;
                        else if(get_cell(i-1,0) == 1)
                            b = 3;
                        else
                            b = 26;
                    }
                    else if(j == 44)
                    {
                        if(get_cell(i + 1,j) == 1 && get_cell(i,j-1) == 1 && get_cell(i-1,j))
                            b = 24;
                        else if(get_cell(i + 1,44) == 1 && get_cell(i,43) == 1)
                            b = 8;
                        else if(get_cell(i - 1,44) == 1 && get_cell(i,43) == 1)
                            b = 10;
                        else if(get_cell(i-1,44) == 1 && get_cell(i+1,44) == 1)
                            b = 1;
                        else if(get_cell(i,43) == 1)
                            b = 6;
                        else if(get_cell(i+1,44) == 1)
                            b = 4;
                        else if(get_cell(i-1,44) == 1)
                            b = 3;
                        else
                            b = 26;
                    }
                    else
                    {
                        if(get_cell(i + 1,j) == 1 && get_cell(i,j+1) == 1 && get_cell(i-1,j))
                            b = 25;
                        else if(get_cell(i + 1,j) == 1 && get_cell(i,j-1) == 1 && get_cell(i-1,j))
                            b = 24;
                        else if(get_cell(i + 1,j) == 1 && get_cell(i,j+1) == 1 && get_cell(i,j-1))
                            b = 11;
                        else if(get_cell(i - 1,j) == 1 && get_cell(i,j+1) == 1 && get_cell(i,j-1))
                            b = 12;
                        else if(get_cell(i-1,j) == 1 && get_cell(i+1,j) == 1)
                            b = 1;
                        else if(get_cell(i,j+1) == 1 && get_cell(i,j-1) == 1)
                            b = 2;
                        else if(get_cell(i-1,j) == 1 && get_cell(i,j-1) == 1)
                            b = 10;
                        else if(get_cell(i-1,j) == 1 && get_cell(i,j+1) == 1)
                            b = 9;
                        else if(get_cell(i+1,j) == 1 && get_cell(i,j-1) == 1)
                            b = 8;
                        else if(get_cell(i+1,j) == 1 && get_cell(i,j+1) == 1)
                            b = 7;
                        else if(get_cell(i,j+1) == 1)
                            b = 5;
                        else if(get_cell(i,j-1) == 1)
                            b = 6;
                        else if(get_cell(i+1,j) == 1)
                            b = 4;
                        else if(get_cell(i-1,j) == 1)
                            b = 3;
                        else
                            b = 26;
                    }
                }
                txTransparentBlt(txDC(),j * 24, i * 24, 24, 24, picture, b * 24, 0, TX_WHITE);
            }
            else
                txTransparentBlt(txDC(),j * 24, i * 24, 24, 24, picture, a * 24, 0, TX_WHITE);

        }
    }
}
//}=====================================================================================================================
#endif
