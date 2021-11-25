#ifndef __VOVACHARACTER__
#define __VOVACHARACTER__
//{=====================================================================================================================
///    \author Плотников Владимир
///
///    \file   character.h
///
///    \defgroup    Drawing     Рисование
///    \defgroup    File     Работа с файлами
///    \defgroup    Movment     Движение
//}=====================================================================================================================

typedef class Character ch_t;

//Character
//{=====================================================================================================================
///     \name   Класс персонажа
class Character
{
private:
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
public:
    Character (const Character &ch);
    Character operator=(Character ch);
    ~Character();
    Character(FILE* f);
    double get_ypos();
    //{=====================================================================================================================
    ///     \name
    ///
    ///     \brief
    ///
    ///     \return     ypos
    //}=====================================================================================================================

    void set_framesn(int a);
    //{=====================================================================================================================
    ///     \name       Установить framesn
    ///
    ///     \brief      Меняет переменную framesn
    ///
    ///     \param  a   Новое значение переменной
    //}=====================================================================================================================

    void set_frame(int a);
    //{=====================================================================================================================
    ///     \name       Установить frame
    ///
    ///     \brief      Меняет переменную frame
    ///
    ///     \param  a   Новое значение переменной
    //}=====================================================================================================================

    void set_ysize(double a);
    //{=====================================================================================================================
    ///     \name       Установить ysize
    ///
    ///     \brief      Меняет переменную ysize
    ///
    ///     \param  a   Новое значение переменной
    //}=====================================================================================================================

    void set_xsize(double a);
    //{=====================================================================================================================
    ///     \name       Установить xsize
    ///
    ///     \brief      Меняет переменную xsize
    ///
    ///     \param  a   Новое значение переменной
    //}=====================================================================================================================

    void set_scale(double a);
    //{=====================================================================================================================
    ///     \name       Установить scale
    ///
    ///     \brief      Меняет переменную scale
    ///
    ///     \param  a   Новое значение переменной
    //}=====================================================================================================================

    void set_name(char* a);
    //{=====================================================================================================================
    ///     \name       Установить name
    ///
    ///     \brief      Меняет переменную name
    ///
    ///     \param  a   Новое значение переменной
    //}=====================================================================================================================

    void delete_picture();
    //{=====================================================================================================================
    ///     \name       Удалить картнку
    ///
    ///     \brief      Удаляет картинку
    //}=====================================================================================================================
private:
    void check_border_down(bg_t *background);
    //{=====================================================================================================================
    ///     \name               Проверка нижней границы
    ///
    ///     \brief              Проверяет пересечение нижней границы экрана
    ///
    ///     \param  background  Указатель на фон
    //}=====================================================================================================================

    void check_border_left(bg_t *background);
    //{=====================================================================================================================
    ///     \name               Проверка левой границы
    ///
    ///     \brief              Проверяет пересечение левой границы экрана
    ///
    ///     \param  background  Указатель на фон
    //}=====================================================================================================================

    void check_border_up(bg_t *background);
    //{=====================================================================================================================
    ///     \name               Проверка верхней границы
    ///
    ///     \brief              Проверяет пересечение верхней границы экрана
    ///
    ///     \param  background  Указатель на фон
    //}=====================================================================================================================

    void check_border_right(bg_t *background);
    //{=====================================================================================================================
    ///     \name               Проверка правой границы
    ///
    ///     \brief              Проверяет пересечение правой границы экрана
    ///
    ///     \param  background  Указатель на фон
    //}=====================================================================================================================
public:
    void check_border(bg_t *background);
    //{=====================================================================================================================
    ///     \name               Проверка границы
    ///
    ///     \brief              Проверяет пересечение границы экрана
    ///
    ///     \param  background  Указатель на фон
    //}=====================================================================================================================

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
private:
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
public:
    void do_sit();
    //{=====================================================================================================================
    ///     \name       Посадить
    ///
    ///     \ingroup    Movment
    ///
    ///     \brief      Сажает персонажа
    //}=====================================================================================================================

    void update_character(bg_t &background, dt_t *sit_time, char imitate, bool checkcollision );
    //{=====================================================================================================================
    ///     \name       Обновление
    ///
    ///     \ingroup    Movment
    ///
    ///     \brief      Обновляет параметры персонажа в зависимости от нажатых кнопок
    ///
    ///     \param  background      Структура фона
    ///     \param  sit_time        Указатель на время, которое сидит персонаж
    ///     \param  imitate         Кнопка, нажатие которой нужно сымитировать
    ///     \param  checkcollision  Проверять ли коллизию
    //}=====================================================================================================================

    void draw_character();
    //{=====================================================================================================================
    ///     \name       Рисует
    ///
    ///     \ingroup    Drawing
    ///
    ///     \brief      Рисует персонажа
    //}=====================================================================================================================
private:
    bool character_collision(bg_t &ground);
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

    bool character_collision_up(bg_t &ground);
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

    bool character_collision_left(bg_t &ground);
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

    bool character_collision_down(bg_t &ground);
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

    bool character_collision_right(bg_t &ground);
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

//Initialization
//Character
//{=====================================================================================================================
Character::Character (const Character &ch) : //{
                                            xpos(ch.xpos),
                                            ypos(ch.ypos),
                                            xsize(ch.xsize),
                                            ysize(ch.ysize),
                                            picture(nullptr),
                                            direction(ch.direction),
                                            frame(ch.frame),
                                            scale(ch.scale),
                                            sit(ch.sit),
                                            step(ch.step),
                                            framesn(ch.framesn),
                                            dlenght(ch.dlenght),
                                            ulenght(ch.ulenght),
                                            rlenght(ch.rlenght),
                                            llenght(ch.llenght),
                                            name(ch.name)
                                            //}
{
    load_image();
}

Character Character::operator=(Character ch)
{
    xpos = ch.xpos;
    ypos = ch.ypos;
    xsize = ch.xsize;
    ysize = ch.ysize;
    picture = nullptr;
    direction = ch.direction;
    frame = ch.frame;
    scale = ch.scale;
    sit = ch.sit;
    step = ch.step;
    framesn = ch.framesn;
    dlenght = ch.dlenght;
    ulenght = ch.ulenght;
    rlenght = ch.rlenght;
    llenght = ch.rlenght;
    name = ch.name;
    load_image();
    return *this;
}

Character::~Character()
{
    delete_picture();
}

Character::Character(FILE* f) : //{
                               xpos(0),
                               ypos(0),
                               xsize(64),
                               ysize(64),
                               picture(nullptr),
                               direction(0),
                               frame(0),
                               scale(0),
                               sit(0),
                               step(5),
                               framesn(7),
                               dlenght(25),
                               ulenght(21),
                               rlenght(9),
                               llenght(12),
                               name("sceleton.bmp")
                               //}
{
    load_image();
    get_from_file(f);
}

double Character::get_ypos()
{
    return ypos;
}

void Character::set_frame(int a)
{
    frame = a;
}

void Character::set_framesn(int a)
{
    framesn = a;
}

void Character::set_ysize(double a)
{
    ysize = a;
}

void Character::set_xsize(double a)
{
    xsize = a;
}

void Character::set_scale(double a)
{
    scale = a;
}

void Character::set_name(char* a)
{
    name = a;
}

void Character::delete_picture()
{
    txDeleteDC(picture);
}

void Character::check_border_right(bg_t *background)
{
    if(xpos - llenght * scale >= 1080)
    {
        xpos = -1 * rlenght * scale + step * scale;
        background->change();
    }
}

void Character::check_border_left(bg_t *background)
{
    if(xpos + rlenght * scale <= 0)
    {
        xpos = 1080 + llenght * scale - step * scale;
        background->change();
    }
}

void Character::check_border_down(bg_t *background)
{
    if(ypos - ulenght * scale >= 720)
    {
        ypos = -1 * dlenght * scale + step * scale;
        background->change();
    }
}

void Character::check_border_up(bg_t *background)
{
    if(ypos + dlenght * scale <= 0)
    {
        ypos = 720 + ulenght * scale - step * scale;
        background->change();
    }
}

void Character::check_border(bg_t *background)
{
    check_border_up(background);
    check_border_down(background);
    check_border_right(background);
    check_border_left(background);
}

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

bool Character::character_collision(bg_t &background)
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
bool Character::character_collision_up(bg_t &background)
{
    double yf = ypos + dlenght * scale - step * scale;
    if (yf <= 0 || yf >= 720)
        return 1;
    if (background.get_cell(int(yf/24),int((xpos - llenght * scale)/24)) ||
        background.get_cell(int(yf/24),int((xpos + rlenght * scale)/24)))
        return 0;
    return 1;
}
bool Character::character_collision_left(bg_t &background)
{
    double xf = xpos - llenght * scale  - step * scale;
    if (xf <= 0 || xf >= 1080)
        return 1;
    if (background.get_cell(int((ypos + dlenght * scale)/24),int(xf/24)))
        return 0;
    return 1;
}
bool Character::character_collision_down(bg_t &background)
{
    double yf = ypos + dlenght * scale + step * scale;
    if (yf >= 720 || yf <= 0)
        return 1;
    if (background.get_cell(int(yf/24),int((xpos - llenght * scale)/24)) ||
        background.get_cell(int(yf/24),int((xpos + rlenght * scale)/24)))
        return 0;
    return 1;
}
bool Character::character_collision_right(bg_t &background)
{
    double xf = xpos + rlenght * scale  + step * scale;
    if (xf >= 1080 || xf <= 0)
        return 1;
    if (background.get_cell(int((ypos + dlenght * scale)/24),int(xf/24)))
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

void Character::update_character(bg_t &background, dt_t *sit_time, char imitate = '\0', bool checkcollision = 1)
{
    bool m = 1;
    if(GetAsyncKeyState('W') || imitate == 'w')//w
    {
        turn_up();
        frame = frame%framesn + 1;
        if (character_collision(background) || !checkcollision)
            move_forward();
        m = 0;
    }
    if(GetAsyncKeyState('A') || imitate == 'a')//a
    {
        turn_left();
        frame = frame%framesn + 1;
        if (character_collision(background) || !checkcollision)
            move_forward();
        m = 0;
    }
    if(GetAsyncKeyState('S') || imitate == 's')//s
    {
        turn_down();
        frame = frame%framesn + 1;
        if (character_collision(background) || !checkcollision)
            move_forward();
        m = 0;
    }
    if(GetAsyncKeyState('D') || imitate == 'd')//d
    {
        turn_right();
        frame = frame%framesn + 1;
        if (character_collision(background) || !checkcollision)
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
                          TX_WHITE);
}

//}=====================================================================================================================
#endif
