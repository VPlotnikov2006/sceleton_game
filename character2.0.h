#include "TXLib.h"

using namespace std;

//{=====================================================================================================================
///    \author Плотников Владимир
///
///    \file   character.h
///
///    \defgroup    Drawing     Рисование
///    \defgroup    File     Работа с файлами
///    \defgroup    Movment     Движение
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

//types
//{=====================================================================================================================
typedef struct Background bg_t;
typedef struct Character ch_t;
typedef struct Dtime dt_t;
//}=====================================================================================================================

//functions
//{=====================================================================================================================
void end_game(bg_t background, ch_t main);
//{=====================================================================================================================
///     \name   Финал
///
///     \brief  Финал игры
///
///     \param  background  Структура фона
///     \param  main        Структура главного героя
//}=====================================================================================================================

bool time_comp(dt_t t1, dt_t t2);
//{=====================================================================================================================
///     \name   Сравнение времен
///
///     \brief  Сравнивает два времени
///
///     \param  t1  Первое время
///     \param  t2  Второе время
///
///     \return True если первое>=второе, иначе False
//}=====================================================================================================================

void fclear(char* s);
//{=====================================================================================================================
///     \name   Очистка
///
///     \ingroup    File
///
///     \brief  Очищает файл
///
///     \param s    Имя файла
///
///     \warning    Если такого файла нет, то создаст
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

void easter_egg(ch_t main);
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

//structures
//{=====================================================================================================================
//Time
//{=====================================================================================================================
///     \name   Структура десятичного времени
struct Dtime
{
    /// <= миллисекунды
    int milliseconds;
    /// <= секунды
    int seconds;
    /// <= минуты
    int minutes;
    /// <= часы
    int hours;

    void get_from_file(FILE* f);
    //{=====================================================================================================================
    ///     \name       Взять из файла
    ///
    ///     \ingroup    File
    ///
    ///     \brief      Берет зашифрованую информацию из файла save.txt
    ///
    ///     \param  f   Указатель на файл сохранения в формате чтения
    ///
    ///     \warning    Если такого файла нет то - Undefined Behavior
    //}=====================================================================================================================

    void put_to_file(FILE* f);
    //{=====================================================================================================================
    ///     \name       Положить в файл
    ///
    ///     \ingroup    File
    ///
    ///     \brief      Кладет и шифрует информацию в конец файла save.txt
    ///
    ///     \param  f   Указатель на файл сохранения в формате дописывания
    ///
    ///     \warning    Если такого файла нет то создаст новый
    //}=====================================================================================================================

    void update_time(int t);
    //{=====================================================================================================================
    ///     \name       Обновление
    ///
    ///     \brief      Обновляет время
    ///
    ///     \param  t   Время в миллисекундах, прошедшее с последнего обновления
    //}=====================================================================================================================
};
//}=====================================================================================================================

//Character
//{=====================================================================================================================
///     \name   Структура персонажа
struct Character
{
    /// <= Координата по оси X середины картинки персоонажа на холсте
    double xpos;
    /// <= Координата по оси Y середины картинки персоонажа на холсте
    double ypos;
    /// <= Размер одного кадра по оси X
    double xsize;
    /// <= Размер одного кадра по оси Y
    double ysize;
    /// <= Дискриптор холста картинки
    HDC picture;
    /// <= Направление движения персонажа
    int direction;
    /// <= Номер кадра анимации персонажа
    int frame;
    /// <= Размер
    double scale;
    /// <= Сидит ли персонаж
    int sit;
    /// <= Длина одного шага
    int step;
    /// <= Кол-во кадров в анимации движения
    int framesn;
    /// <= расстояние от центра кадра до нижней границы персонажа
    int dlenght;
    /// <= расстояние от центра кадра до верхней границы персонажа
    int ulenght;
    /// <= расстояние от центра кадра до левой границы персонажа
    int rlenght;
    /// <= расстояние от центра кадра до правой границы персонажа
    int llenght;
    /// <= имя картинки в котором лежит персонаж (sceleton) с типом
    char* name;

    bool load_image();
    //{=====================================================================================================================
    ///     \name       Грузит картинку
    ///
    ///     \ingroup    File
    ///
    ///     \brief      Грузит картинку из файла name + ".bmp"
    ///
    ///     \warning    Если такого файла нет то - Undefined Behavior
    ///
    ///     \return     True если удачная загрузка, False если нет такого файла
    //}=====================================================================================================================

    void get_from_file(FILE* f);
    //{=====================================================================================================================
    ///     \name       Взять из файла
    ///
    ///     \ingroup    File
    ///
    ///     \brief      Берет информацию из файла save.txt
    ///
    ///     \param  f   Указатель на файл сохранения в формате чения
    ///
    ///     \warning    Если такого файла нет то - Undefined Behavior
    //}=====================================================================================================================

    void put_to_file(FILE* f);
    //{=====================================================================================================================
    ///     \name       Положить в файл
    ///
    ///     \ingroup    File
    ///
    ///     \brief      Кладет информацию в конец файла save.txt
    ///
    ///     \param  f   Указатель на файл сохранения в формате дописывания
    ///
    ///     \warning    Если такого файла нет то создаст новый
    //}=====================================================================================================================

    void turn_up();
    //{=====================================================================================================================
    ///     \name       Поворот вврех
    ///
    ///     \ingroup    Movment
    ///
    ///     \brief      Поворачивает персонажа в направлении вверх
    //}=====================================================================================================================

    void turn_left();
    //{=====================================================================================================================
    ///     \name       Поворот влево
    ///
    ///     \ingroup    Movment
    ///
    ///     \brief      Поворачивает персонажа в направлении влево
    //}=====================================================================================================================

    void turn_down();
    //{=====================================================================================================================
    ///     \name       Поворот вниз
    ///
    ///     \ingroup    Movment
    ///
    ///     \brief      Поворачивает персонажа в направлении вниз
    //}=====================================================================================================================

    void turn_right();
    //{=====================================================================================================================
    ///     \name       Поворот вправо
    ///
    ///     \ingroup    Movment
    ///
    ///     \brief      Поворачивает персонажа в направлении вправо
    //}=====================================================================================================================

    void move_forward();
    //{=====================================================================================================================
    ///     \name       Движение вперед
    ///
    ///     \ingroup    Movment
    ///
    ///     \brief      Двигает персонажа в направлениикуда он смотрит
    //}=====================================================================================================================

    void move_up();
    //{=====================================================================================================================
    ///     \name       Движение вврех
    ///
    ///     \ingroup    Movment
    ///
    ///     \brief      Двигает персонажа в направлении вверх
    //}=====================================================================================================================

    void move_left();
    //{=====================================================================================================================
    ///     \name       Движение влево
    ///
    ///     \ingroup    Movment
    ///
    ///     \brief      Двигает персонажа в направлении влево
    //}=====================================================================================================================

    void move_down();
    //{=====================================================================================================================
    ///     \name       Движение вниз
    ///
    ///     \ingroup    Movment
    ///
    ///     \brief      Двигает персонажа в направлении вниз
    //}=====================================================================================================================

    void move_right();
    //{=====================================================================================================================
    ///     \name       Движение вправо
    ///
    ///     \ingroup    Movment
    ///
    ///     \brief      Двигает персонажа в направлении вправо
    //}=====================================================================================================================

    void do_sit();
    //{=====================================================================================================================
    ///     \name       Посадить
    ///
    ///     \ingroup    Movment
    ///
    ///     \brief      Сажает персонажа
    //}=====================================================================================================================

    void update_character(bg_t background, dt_t* sit_time);
    //{=====================================================================================================================
    ///     \name       Обновление
    ///
    ///     \ingroup    Movment
    ///
    ///     \brief      Обновляет параметры персонажа в зависимости от нажатых кнопок
    ///
    ///     \param  background  Структура фона
    ///     \param  sit_time    Указатель на время, которое сидит персонаж
    //}=====================================================================================================================

    void draw_character();
    //{=====================================================================================================================
    ///     \name       Рисует
    ///
    ///     \ingroup    Drawing
    ///
    ///     \brief      Рисует персонажа
    //}=====================================================================================================================

    bool character_collision(bg_t ground);
    //{=====================================================================================================================
    ///     \name       Проверка коллизии
    ///
    ///     \ingroup    Movment
    ///
    ///     \brief      Проверяет может ли персонаж двигаться в выбранном направлении
    ///
    ///     \return     Возвращает True если можно двигаться и False если нельзя
    ///
    ///     \param  ground  Структура фона
    //}=====================================================================================================================

    bool character_collision_up(bg_t ground);
    //{=====================================================================================================================
    ///     \name       Проверка коллизии
    ///
    ///     \ingroup    Movment
    ///
    ///     \brief      Проверяет может ли персонаж двигаться вверх
    ///
    ///     \return     Возвращает True если можно двигаться и False если нельзя
    ///
    ///     \param  ground  Структура фона
    //}=====================================================================================================================

    bool character_collision_left(bg_t ground);
    //{=====================================================================================================================
    ///     \name       Проверка коллизии
    ///
    ///     \ingroup    Movment
    ///
    ///     \brief      Проверяет может ли персонаж двигаться влево
    ///
    ///     \return     Возвращает True если можно двигаться и False если нельзя
    ///
    ///     \param  ground  Структура фона
    //}=====================================================================================================================

    bool character_collision_down(bg_t ground);
    //{=====================================================================================================================
    ///     \name       Проверка коллизии при
    ///
    ///     \ingroup    Movment
    ///
    ///     \brief      Проверяет может ли персонаж двигаться вниз
    ///
    ///     \return     Возвращает True если можно двигаться и False если нельзя
    ///
    ///     \param  ground  Структура фона
    //}=====================================================================================================================

    bool character_collision_right(bg_t ground);
    //{=====================================================================================================================
    ///     \name       Проверка коллизии при
    ///
    ///     \ingroup    Movment
    ///
    ///     \brief      Проверяет может ли персонаж двигаться вправо
    ///
    ///     \return     Возвращает True если можно двигаться и False если нельзя
    ///
    ///     \param  ground  Структура фона
    //}=====================================================================================================================


};
//}=====================================================================================================================

//Background
//{=====================================================================================================================
///     \name   Структура фона
struct Background
{
    /// <= матрица, заполненая числами, соответствующими коллизии блоков 24X24
    int ground[30][45];
    /// <= дискриптор картинки с блоками
    HDC picture;
    /// <= номер текущего кадра фона
    int num;

    void get_from_file(FILE* f);
    //{=====================================================================================================================
    ///     \name       Взять из файла
    ///
    ///     \ingroup    File
    ///
    ///     \brief      Берет num из файла save.txt
    ///
    ///     \param  f   Указатель на файл сохранения в формате чтения
    ///
    ///     \warning    Если такого файла нет то - Undefined Behavior
    //}=====================================================================================================================

    void put_to_file(FILE* f);
    //{=====================================================================================================================
    ///     \name       Положить в файл
    ///
    ///     \ingroup    File
    ///
    ///     \brief      Кладет num в конец файла save.txt
    ///
    ///     \param  f   Указатель на файл сохранения в формате дописывания
    ///
    ///     \warning    Если такого файла нет то создаст новый
    //}=====================================================================================================================

    bool load_image();
    //{=====================================================================================================================
    ///     \name       Грузит картинку
    ///
    ///     \ingroup    File
    ///
    ///     \brief      Грузит картинку из файла с именем в переменной back_name
    ///
    ///     \warning    Если такого файла нет то - Undefined Behavior
    ///
    ///     \return     True если удачная загрузка, False если нет такого файла
    //}=====================================================================================================================

    bool load_ground();
    //{=====================================================================================================================
    ///     \name       Считать из файла
    ///
    ///     \ingroup    File
    ///
    ///     \brief      Считывает коллизию блоков из файла с именем в переменной back_collision_name[num]
    ///
    ///     \warning    Если такого файла нет то - Undefined Behavior
    ///
    ///     \return     True если удачная загрузка, False если нет такого файла
    //}=====================================================================================================================

    void draw_background();
    //{=====================================================================================================================
    ///     \name       Нарисовать фон
    ///
    ///     \ingroup    Drawing
    ///
    ///     \brief      Рисует фон
    //}=====================================================================================================================

};
//}=====================================================================================================================
//}=====================================================================================================================

//initialization
//{=====================================================================================================================
//Time
//{=====================================================================================================================
void Dtime::put_to_file(FILE* f)
{
    fprintf(f,"%d %d %d %d\n",milliseconds * 8677, seconds * 4079, minutes * 7193, hours * 2503);
}

void Dtime::get_from_file(FILE* f)
{
    int mi,s,m,h;
    bool cheat = 0;
    fscanf(f,"%d%d%d%d",&mi,&s,&m,&h);
    if (mi % 8677 == 0)
        milliseconds = mi / 8677;
    else
        cheat = 1;

    if (s % 4079 == 0)
        seconds = s / 4079;
    else
        cheat = 1;

    if (m % 7193 == 0)
        minutes = m / 7193;
    else
        cheat = 1;

    if (h % 2503 == 0)
        hours = h / 2503;
    else
        cheat = 1;
    if (milliseconds >= 1000 || seconds >=100 || minutes >= 100)
        cheat = 1;
    if (cheat)
    {
        milliseconds = 0;
        seconds = 0;
        minutes = 0;
        hours = 0;
        txMessageBox("Не жульничать, штраф - обнунление времени игры", "Обнаружен чит");
    }
}

void Dtime::update_time(int t)
{
    milliseconds += t;
    seconds += milliseconds / 1000;
    minutes += seconds / 100;
    hours += minutes / 100;
    milliseconds %= 1000;
    seconds %= 100;
    minutes %= 100;
}
//}=====================================================================================================================

//Character
//{=====================================================================================================================
bool Character::load_image()
{
    picture = txLoadImage(name);
    if (!picture)
    {
        txMessageBox("Ошибка","Не найден файл с персонажем");
        return 0;
    }
    return 1;
}

bool Character::character_collision(bg_t background)
{
    if (direction == 1)
        return character_collision_up(background);
    if (direction == 2)
        return character_collision_left(background);
    if (direction == 3)
        return character_collision_down(background);
    if (direction == 4)
        return character_collision_right(background);
}
bool Character::character_collision_up(bg_t background)
{
    double yf = ypos + dlenght * scale - step * scale;
    if (yf <= 0)
        return 1;
    if (background.ground[int(yf/24)][int((xpos - llenght * scale)/24)] || background.ground[int(yf/24)][int((xpos + rlenght * scale)/24)])
        return 0;
    return 1;
}
bool Character::character_collision_left(bg_t background)
{
    double xf = xpos - llenght * scale  - step * scale;
    if (xf <= 0)
        return 1;
    if (background.ground[int((ypos + dlenght * scale)/24)][int(xf/24)])
        return 0;
    return 1;
}
bool Character::character_collision_down(bg_t background)
{
    double yf = ypos + dlenght * scale + step * scale;
    if (yf >= 720)
        return 1;
    if (background.ground[int(yf/24)][int((xpos - llenght * scale)/24)] || background.ground[int(yf/24)][int((xpos + rlenght * scale)/24)])
        return 0;
    return 1;
}
bool Character::character_collision_right(bg_t background)
{
    double xf = xpos + rlenght * scale  + step * scale;
    if (xf >= 1080)
        return 1;
    if (background.ground[int((ypos + dlenght * scale)/24)][int(xf/24)])
        return 0;
    return 1;
}

void Character::get_from_file(FILE* f)
{
    fscanf(f, "%lf %lf %d %d %lf", &xpos, &ypos, &direction, &frame, &scale);
}
void Character::put_to_file(FILE* f)
{
    fprintf(f, "%.3lf %.3lf %d %d %.3lf\n", xpos, ypos, direction, frame, scale);
}

void Character::turn_up()
{
    direction = 1;
    sit = 0;
}
void Character::turn_left()
{
    direction = 2;
    sit = 0;
}
void Character::turn_down()
{
    direction = 3;
    sit = 0;
}
void Character::turn_right()
{
    direction = 4;
    sit = 0;
}

void Character::move_forward()
{
    if (direction == 1)
        move_up();
    if (direction == 2)
        move_left();
    if (direction == 3)
        move_down();
    if (direction == 4)
        move_right();
}
void Character::move_up()
{
    ypos -= step * scale;
}
void Character::move_left()
{
    xpos -= step * scale;
}
void Character::move_down()
{
    ypos += step * scale;
}
void Character::move_right()
{
    xpos += step * scale;
}

void Character::do_sit()
{
    sit = 1;

    frame = 17;
}

void Character::update_character(bg_t background, dt_t* sit_time)
{
    bool m = 1;
    if(GetAsyncKeyState('W'))//w
    {
        turn_up();
        frame = frame%framesn + 1;
        if (character_collision(background))
            move_forward();
        m = 0;
    }
    if(GetAsyncKeyState('A'))//a
    {
        turn_left();
        frame = frame%framesn + 1;
        if (character_collision(background))
            move_forward();
        m = 0;
    }
    if(GetAsyncKeyState('S'))//s
    {
        turn_down();
        frame = frame%framesn + 1;
        if (character_collision(background))
            move_forward();
        m = 0;
    }
    if(GetAsyncKeyState('D'))//d
    {
        turn_right();
        frame = frame%framesn + 1;
        if (character_collision(background))
            move_forward();
        m = 0;
    }
    if(m)//shift
    {
        do_sit();
    }
    else
    {
        sit_time->milliseconds = 0;
        sit_time->seconds = 0;
        sit_time->minutes = 0;
        sit_time->hours = 0;
    }
}
void Character::draw_character()
{
    if(sit)
        do_sit();
    Win32::TransparentBlt(txDC(), xpos - scale * xsize / 2, ypos - scale * ysize / 2, xsize * scale, ysize * scale, picture,
                          (frame - 1) * xsize, (direction - 1) * ysize, xsize, ysize,  TX_WHITE);
}

//}=====================================================================================================================

//Background
//{=====================================================================================================================
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
        txMessageBox("Ошибка","Не найден файл с персонажем");
        return 0;
    }
    return 1;
}
bool Background::load_ground()
{
    FILE* f = fopen(back_collision_name[num], "r");
    if (!f)
    {
        txMessageBox("Ошибка","Не найден файл с персонажем");
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

//функция на 81 if/else
void Background::draw_background()
{
    int a;
    for (int i = 0; i < 30; i++)
    {
        for (int j = 0; j < 45; j++)
        {
            a = ground[i][j];
            if (a == 0)
                txTransparentBlt(txDC(),j * 24, i * 24, 24, 24, picture, 0, 0, TX_WHITE);
            else if (a == 2)
            {
                int b = rand()%8;
                if(b < 5)
                    txTransparentBlt(txDC(),j * 24, i * 24, 24, 24, picture, 13 * 24, 0, TX_WHITE);
                else
                    txTransparentBlt(txDC(),j * 24, i * 24, 24, 24, picture, (13  + b - 4)* 24, 0, TX_WHITE);
            }
            else if (a == 1)
            {
                if(i == 0)
                {
                    if(j == 0)
                    {
                        if(ground[1][0] == 1 && ground[0][1] == 1)
                            txTransparentBlt(txDC(),j * 24, i * 24, 24, 24, picture, 7 * 24, 0, TX_WHITE);
                        else if(ground[1][0] == 1)
                            txTransparentBlt(txDC(),j * 24, i * 24, 24, 24, picture, 4 * 24, 0, TX_WHITE);
                        else if(ground[0][1] == 1)
                            txTransparentBlt(txDC(),j * 24, i * 24, 24, 24, picture, 5 * 24, 0, TX_WHITE);
                        else
                            txTransparentBlt(txDC(),j * 24, i * 24, 24, 24, picture, 26 * 24, 0, TX_WHITE);
                    }
                    else if(j == 44)
                    {
                        if(ground[1][44] == 1 && ground[0][43] == 1)
                            txTransparentBlt(txDC(),j * 24, i * 24, 24, 24, picture, 8 * 24, 0, TX_WHITE);
                        else if(ground[1][44] == 1)
                            txTransparentBlt(txDC(),j * 24, i * 24, 24, 24, picture, 4 * 24, 0, TX_WHITE);
                        else if(ground[0][43] == 1)
                            txTransparentBlt(txDC(),j * 24, i * 24, 24, 24, picture, 6 * 24, 0, TX_WHITE);
                        else
                            txTransparentBlt(txDC(),j * 24, i * 24, 24, 24, picture, 26 * 24, 0, TX_WHITE);
                    }
                    else
                    {
                        if(ground[1][j] == 1 && ground[0][j - 1] == 1 && ground[0][j + 1])
                            txTransparentBlt(txDC(),j * 24, i * 24, 24, 24, picture, 11 * 24, 0, TX_WHITE);
                        else if(ground[1][j] == 1 && ground[0][j - 1])
                            txTransparentBlt(txDC(),j * 24, i * 24, 24, 24, picture, 8 * 24, 0, TX_WHITE);
                        else if(ground[1][j] == 1 && ground[0][j + 1])
                            txTransparentBlt(txDC(),j * 24, i * 24, 24, 24, picture, 7 * 24, 0, TX_WHITE);
                        else if(ground[0][j - 1] == 1 && ground[0][j + 1] == 1)
                            txTransparentBlt(txDC(),j * 24, i * 24, 24, 24, picture, 2 * 24, 0, TX_WHITE);
                        else if(ground[0][j + 1] == 1)
                            txTransparentBlt(txDC(),j * 24, i * 24, 24, 24, picture, 5 * 24, 0, TX_WHITE);
                        else if(ground[0][j - 1] == 1)
                            txTransparentBlt(txDC(),j * 24, i * 24, 24, 24, picture, 6 * 24, 0, TX_WHITE);
                        else if(ground[1][j] == 1)
                            txTransparentBlt(txDC(),j * 24, i * 24, 24, 24, picture, 4 * 24, 0, TX_WHITE);
                        else
                            txTransparentBlt(txDC(),j * 24, i * 24, 24, 24, picture, 26 * 24, 0, TX_WHITE);
                    }
                }
                else if(i == 29)
                {
                    if(j == 0)
                    {
                        if(ground[28][0] == 1 && ground[29][1] == 1)
                            txTransparentBlt(txDC(),j * 24, i * 24, 24, 24, picture, 9 * 24, 0, TX_WHITE);
                        else if(ground[28][0] == 1)
                            txTransparentBlt(txDC(),j * 24, i * 24, 24, 24, picture, 3 * 24, 0, TX_WHITE);
                        else if(ground[29][1] == 1)
                            txTransparentBlt(txDC(),j * 24, i * 24, 24, 24, picture, 5 * 24, 0, TX_WHITE);
                        else
                            txTransparentBlt(txDC(),j * 24, i * 24, 24, 24, picture, 26 * 24, 0, TX_WHITE);
                    }
                    else if(j == 44)
                    {
                        if(ground[28][44] == 1 && ground[29][43] == 1)
                            txTransparentBlt(txDC(),j * 24, i * 24, 24, 24, picture, 10 * 24, 0, TX_WHITE);
                        else if(ground[28][44] == 1)
                            txTransparentBlt(txDC(),j * 24, i * 24, 24, 24, picture, 3 * 24, 0, TX_WHITE);
                        else if(ground[29][43] == 1)
                            txTransparentBlt(txDC(),j * 24, i * 24, 24, 24, picture, 6 * 24, 0, TX_WHITE);
                        else
                            txTransparentBlt(txDC(),j * 24, i * 24, 24, 24, picture, 26 * 24, 0, TX_WHITE);
                    }
                    else
                    {
                        if(ground[28][j] == 1 && ground[29][j - 1] == 1 && ground[29][j + 1])
                            txTransparentBlt(txDC(),j * 24, i * 24, 24, 24, picture, 12 * 24, 0, TX_WHITE);
                        else if(ground[28][j] == 1 && ground[29][j - 1])
                            txTransparentBlt(txDC(),j * 24, i * 24, 24, 24, picture, 10 * 24, 0, TX_WHITE);
                        else if(ground[28][j] == 1 && ground[29][j + 1])
                            txTransparentBlt(txDC(),j * 24, i * 24, 24, 24, picture, 9 * 24, 0, TX_WHITE);
                        else if(ground[29][j - 1] == 1 && ground[29][j + 1] == 1)
                            txTransparentBlt(txDC(),j * 24, i * 24, 24, 24, picture, 2 * 24, 0, TX_WHITE);
                        else if(ground[29][j + 1] == 1)
                            txTransparentBlt(txDC(),j * 24, i * 24, 24, 24, picture, 5 * 24, 0, TX_WHITE);
                        else if(ground[29][j - 1] == 1)
                            txTransparentBlt(txDC(),j * 24, i * 24, 24, 24, picture, 6 * 24, 0, TX_WHITE);
                        else if(ground[28][j] == 1)
                            txTransparentBlt(txDC(),j * 24, i * 24, 24, 24, picture, 3 * 24, 0, TX_WHITE);
                        else
                            txTransparentBlt(txDC(),j * 24, i * 24, 24, 24, picture, 26 * 24, 0, TX_WHITE);
                    }
                }
                else
                {
                    if(j == 0)
                    {
                        if(ground[i + 1][j] == 1 && ground[i][j+1] == 1 && ground[i-1][j])
                            txTransparentBlt(txDC(),j * 24, i * 24, 24, 24, picture, 25 * 24, 0, TX_WHITE);
                        else if(ground[i + 1][0] == 1 && ground[i][1] == 1)
                            txTransparentBlt(txDC(),j * 24, i * 24, 24, 24, picture, 7 * 24, 0, TX_WHITE);
                        else if(ground[i - 1][0] == 1 && ground[i][1] == 1)
                            txTransparentBlt(txDC(),j * 24, i * 24, 24, 24, picture, 9 * 24, 0, TX_WHITE);
                        else if(ground[i-1][0] == 1 && ground[i+1][0] == 1)
                            txTransparentBlt(txDC(),j * 24, i * 24, 24, 24, picture, 1 * 24, 0, TX_WHITE);
                        else if(ground[i][1] == 1)
                            txTransparentBlt(txDC(),j * 24, i * 24, 24, 24, picture, 5 * 24, 0, TX_WHITE);
                        else if(ground[i+1][0] == 1)
                            txTransparentBlt(txDC(),j * 24, i * 24, 24, 24, picture, 4 * 24, 0, TX_WHITE);
                        else if(ground[i-1][0] == 1)
                            txTransparentBlt(txDC(),j * 24, i * 24, 24, 24, picture, 3 * 24, 0, TX_WHITE);
                        else
                            txTransparentBlt(txDC(),j * 24, i * 24, 24, 24, picture, 26 * 24, 0, TX_WHITE);
                    }
                    else if(j == 44)
                    {
                        if(ground[i + 1][j] == 1 && ground[i][j-1] == 1 && ground[i-1][j])
                            txTransparentBlt(txDC(),j * 24, i * 24, 24, 24, picture, 24 * 24, 0, TX_WHITE);
                        else if(ground[i + 1][44] == 1 && ground[i][43] == 1)
                            txTransparentBlt(txDC(),j * 24, i * 24, 24, 24, picture, 8 * 24, 0, TX_WHITE);
                        else if(ground[i - 1][44] == 1 && ground[i][43] == 1)
                            txTransparentBlt(txDC(),j * 24, i * 24, 24, 24, picture, 10 * 24, 0, TX_WHITE);
                        else if(ground[i-1][44] == 1 && ground[i+1][44] == 1)
                            txTransparentBlt(txDC(),j * 24, i * 24, 24, 24, picture, 1 * 24, 0, TX_WHITE);
                        else if(ground[i][43] == 1)
                            txTransparentBlt(txDC(),j * 24, i * 24, 24, 24, picture, 6 * 24, 0, TX_WHITE);
                        else if(ground[i+1][44] == 1)
                            txTransparentBlt(txDC(),j * 24, i * 24, 24, 24, picture, 4 * 24, 0, TX_WHITE);
                        else if(ground[i-1][44] == 1)
                            txTransparentBlt(txDC(),j * 24, i * 24, 24, 24, picture, 3 * 24, 0, TX_WHITE);
                        else
                            txTransparentBlt(txDC(),j * 24, i * 24, 24, 24, picture, 26 * 24, 0, TX_WHITE);
                    }
                    else
                    {
                        if(ground[i + 1][j] == 1 && ground[i][j+1] == 1 && ground[i-1][j])
                            txTransparentBlt(txDC(),j * 24, i * 24, 24, 24, picture, 25 * 24, 0, TX_WHITE);
                        else if(ground[i + 1][j] == 1 && ground[i][j-1] == 1 && ground[i-1][j])
                            txTransparentBlt(txDC(),j * 24, i * 24, 24, 24, picture, 24 * 24, 0, TX_WHITE);
                        else if(ground[i + 1][j] == 1 && ground[i][j+1] == 1 && ground[i][j-1])
                            txTransparentBlt(txDC(),j * 24, i * 24, 24, 24, picture, 11 * 24, 0, TX_WHITE);
                        else if(ground[i - 1][j] == 1 && ground[i][j+1] == 1 && ground[i][j-1])
                            txTransparentBlt(txDC(),j * 24, i * 24, 24, 24, picture, 12 * 24, 0, TX_WHITE);
                        else if(ground[i-1][j] == 1 && ground[i+1][j] == 1)
                            txTransparentBlt(txDC(),j * 24, i * 24, 24, 24, picture, 1 * 24, 0, TX_WHITE);
                        else if(ground[i][j+1] == 1 && ground[i][j-1] == 1)
                            txTransparentBlt(txDC(),j * 24, i * 24, 24, 24, picture, 2 * 24, 0, TX_WHITE);
                        else if(ground[i-1][j] == 1 && ground[i][j-1] == 1)
                            txTransparentBlt(txDC(),j * 24, i * 24, 24, 24, picture, 10 * 24, 0, TX_WHITE);
                        else if(ground[i-1][j] == 1 && ground[i][j+1] == 1)
                            txTransparentBlt(txDC(),j * 24, i * 24, 24, 24, picture, 9 * 24, 0, TX_WHITE);
                        else if(ground[i+1][j] == 1 && ground[i][j-1] == 1)
                            txTransparentBlt(txDC(),j * 24, i * 24, 24, 24, picture, 8 * 24, 0, TX_WHITE);
                        else if(ground[i+1][j] == 1 && ground[i][j+1] == 1)
                            txTransparentBlt(txDC(),j * 24, i * 24, 24, 24, picture, 7 * 24, 0, TX_WHITE);
                        else if(ground[i][j+1] == 1)
                            txTransparentBlt(txDC(),j * 24, i * 24, 24, 24, picture, 5 * 24, 0, TX_WHITE);
                        else if(ground[i][j-1] == 1)
                            txTransparentBlt(txDC(),j * 24, i * 24, 24, 24, picture, 6 * 24, 0, TX_WHITE);
                        else if(ground[i+1][j] == 1)
                            txTransparentBlt(txDC(),j * 24, i * 24, 24, 24, picture, 4 * 24, 0, TX_WHITE);
                        else if(ground[i-1][j] == 1)
                            txTransparentBlt(txDC(),j * 24, i * 24, 24, 24, picture, 3 * 24, 0, TX_WHITE);
                        else
                            txTransparentBlt(txDC(),j * 24, i * 24, 24, 24, picture, 26 * 24, 0, TX_WHITE);
                    }
                }
            }
            else
                txTransparentBlt(txDC(),j * 24, i * 24, 24, 24, picture, (17 + a - 3) * 24, 0, TX_WHITE);

        }
    }
}
//}=====================================================================================================================

//Others
//{=====================================================================================================================
void end_game(bg_t background, ch_t *main)
{
    main->turn_down();
    main->frame = 1;
    txClear();
    background.draw_background();
    main->draw_character();
    main->frame = 18;
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
        main->draw_character();
    }
    main->name = "ghost.bmp";
    txDeleteDC(main->picture);
    main->load_image();
    main->frame = 1;
    main->direction = 1;
    main->xsize = 16;
    main->ysize = 24;
    main->scale = 1;
    main->step = 5;
    main->framesn = 3;
    txClear();
    background.draw_background();
    main->draw_character();
    while (main->ypos > -30)
    {
        main->move_up();
        main->frame = main->frame % main->framesn + 1;
        txClear();
        background.draw_background();
        main->draw_character();
        txSleep(40);
    }
}

bool time_comp(dt_t t1, dt_t t2)
{
    if(t1.hours > t2.hours)
        return 1;
    if (t1.hours < t2.hours)
        return 0;

    if(t1.minutes > t2.minutes)
        return 1;
    if (t1.minutes < t2.minutes)
        return 0;

    if(t1.seconds > t2.seconds)
        return 1;
    if (t1.seconds < t2.seconds)
        return 0;

    if(t1.milliseconds >= t2.milliseconds)
        return 1;
    if (t1.milliseconds < t2.milliseconds)
        return 0;
}

void fclear(char* s)
{
    FILE* f = fopen(s,"w");
    fprintf(f,"");
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

void easter_egg(ch_t main)
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
//}=====================================================================================================================
