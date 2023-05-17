/*!
\file   choose_difficulty.h
\brief  Заголовочный файл для меню выбора сложности
\author Иванов Никита
\date   15.05.2023
*/

#ifndef CHOOSE_DIFFICULTY_H
#define CHOOSE_DIFFICULTY_H

#include <QMainWindow>

namespace Ui {
class choose_difficulty;
}

/*!
\brief  Класс интерфейсного окна выбора сложности игры
\details Открывается форма интерфейсного окна с выбором сложности: лёгкая, средняя, тяжёлая.
*/

class choose_difficulty : public QMainWindow
{
    Q_OBJECT

public:
    /*!
        \brief Конструктор класса choose_difficulty
        */
    explicit choose_difficulty(QWidget *parent = nullptr);
    /*!
        \brief Деструктор класса choose_difficulty
        */
    ~choose_difficulty();

private slots:

    /*!
        \brief Выбор лёгкой сложности
        \details При нажатии на кнопку, пользователь выбирает лёгкую сложность игры
        */
    void on_pushButton_easy_clicked();

    /*!
        \brief Выбор средней сложности
        \details При нажатии на кнопку, пользователь выбирает среднюю сложность игры
        */

    void on_pushButton_medium_clicked();

    /*!
        \brief Выбор тяжёлой сложности
        \details При нажатии на кнопку, пользователь выбирает тяжёлую сложность игры
        */

    void on_pushButton_hard_clicked();

private:
    Ui::choose_difficulty *ui;
};

#endif // CHOOSE_DIFFICULTY_H
