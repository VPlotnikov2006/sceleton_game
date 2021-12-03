#ifndef __VOVATIME__
#define __VOVATIME__
//{=====================================================================================================================
///    \author Плотников Владимир
///
///    \file   time.h
///
///    \defgroup    Drawing     Рисование
///    \defgroup    File     Работа с файлами
///    \defgroup    Movment     Движение
//}=====================================================================================================================

typedef class Dtime dt_t;

//Time
//{=====================================================================================================================
///     \name   Структура десятичного времени
class Dtime
{
private:
    /// <= миллисекунды
    int milliseconds;
    /// <= секунды
    int seconds;
    /// <= минуты
    int minutes;
    /// <= часы
    int hours;
public:
    Dtime(int ms, int s, int m, int h)://{
                                         milliseconds(ms),
                                         seconds(s),
                                         minutes(m),
                                         hours(h) //}
    {}
    Dtime()://{
            milliseconds(0),
            seconds(0),
            minutes(0),
            hours(0) //}
    {}
    Dtime(const Dtime &t)://{
                        milliseconds(t.milliseconds),
                        seconds(t.seconds),
                        minutes(t.minutes),
                        hours(t.hours) //}
    {}
    Dtime& operator=(Dtime t)
    {
        milliseconds = t.milliseconds;
        seconds = t.seconds;
        minutes = t.minutes;
        hours = t.hours;
        return *this;
    }
    friend bool operator== (const Dtime &t1, const Dtime &t2)
    {
        return (t1.milliseconds == t2.milliseconds) && (t1.seconds == t2.seconds) &&
               (t1.minutes == t2.minutes) && (t1.hours == t2.hours);
    }
    friend bool operator!= (const Dtime &t1, const Dtime &t2)
    {
        return !(t1 == t2);
    }
    friend bool operator< (const Dtime &t1, const Dtime &t2)
    {
        if(t1.hours < t2.hours)
            return 1;
        if(t1.hours > t2.hours)
            return 0;

        if(t1.minutes < t2.minutes)
            return 1;
        if(t1.minutes > t2.minutes)
            return 0;

        if(t1.seconds < t2.seconds)
            return 1;
        if(t1.seconds > t2.seconds)
            return 0;

        if(t1.milliseconds < t2.milliseconds)
            return 1;
        return 0;
    }
    friend bool operator> (const Dtime &t1, const Dtime &t2)
    {
        return !(t1 < t2 || t1 == t2);
    }
    friend bool operator>= (const Dtime &t1, const Dtime &t2)
    {
        return (t1 > t2 || t1 == t2);
    }
    friend bool operator<= (const Dtime &t1, const Dtime &t2)
    {
        return (t1 < t2 || t1 == t2);
    }
    void print_time()
    {
        printf("%d:%d:%d:%d\n", hours, minutes, seconds, milliseconds );
    }
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

//Initialization
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
#endif
