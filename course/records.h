/*!
\file   records.h
\brief  Заголовочный файл для меню рекордов
\author Иванов Никита
\date   15.05.2023
*/

#ifndef RECORDS_H
#define RECORDS_H

#include <QMainWindow>

namespace Ui {
class records;
}

/*!
\brief  Класс интерфейсного окна рекордов
\details Открывается форма интерфейсного окна с рекордами. Показывается лучший счёт в каждой сложности.
*/

class records : public QMainWindow
{
    Q_OBJECT

public:

    /*!
        \brief Конструктор класса records
        */

    explicit records(QWidget *parent = nullptr);

    /*!
        \brief Деструктор класса records
        */

    ~records();

private slots:

    /*!
        \brief Выход в главное меню
        \details При нажатии на кнопку, пользователь перейдёт в главное меню
        */

    void on_pushButton_exit_clicked();

private:
    Ui::records *ui;
};

#endif // RECORDS_H
