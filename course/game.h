/*!
\file   game.h
\brief  Заголовочный файл для меню игры
\author Иванов Никита
\date   15.05.2023
*/

#ifndef GAME_H
#define GAME_H

#include <QMainWindow>


namespace Ui {
class game;
}

/*!
\brief  Класс интерфейсного окна игры
\details Открывается форма интерфейсного окна с игрой. В поле необходимо написать ответ на пример, расположенный выше и нажать на кнопку ответить.
*/

class game : public QMainWindow
{
    Q_OBJECT

public:
    /*!
        \brief Конструктор класса game
        \param[in] diff Сложность игры
        */
    explicit game(int diff = 0, QWidget *parent = nullptr);
    /*!
        \brief Деструктор класса game
        */
    ~game();

private slots:

    /*!
    \brief  Чтение введённого пользователем текста
    \details При вводе текста он записывается в переменную класса.
    */

    void on_lineEdit_answer_textEdited(const QString &arg1);

    /*!
    \brief  Ответ на пример
    \details При нажатии на кнопку ответ на пример сравнивается с введённым пользователем ответом.
    */

    void on_pushButton_answer_clicked();

private:

    Ui::game *ui;
    int dif_ = 0;
    QString dif = ""; //для хранения сложности игры
    QString answer = ""; //для хранения ответа пользователя
    QString check = ""; //для хранения готового ответа
    int score = 0; //для хранения набранных очков
    int mult = 0; //для хранения множителя
};

#endif // GAME_H
