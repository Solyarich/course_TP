/*!
\file   game.cpp
\brief  Исходный файл функционала меню игры
\author Иванов Никита
\date   15.05.2023
*/

#include "game.h"
#include "ui_game.h"
#include <random>
#include "QDateTime"
#include "QtMath"
#include <QMessageBox>
#include "mainwindow.h"
#include <QFile>

game::game(int diff, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::game)
{
    game::dif_ = diff;

    // выбор множителя очков
    if (diff == 10)
        game::mult = 1;
    else if (diff == 25)
        game::mult = 5;
    else
        game::mult = 10;

    ui->setupUi(this);
    // генератор рандомных чисел

    unsigned int ms = static_cast<unsigned>(QDateTime::currentMSecsSinceEpoch());
    std::mt19937 gen(ms);
    std::uniform_int_distribution<> uid(-game::dif_, game::dif_);
    std::uniform_int_distribution<> uid_2(1, 4);
    std::uniform_int_distribution<> uid_3(1, game::dif_);
    int number_1 = uid(gen);
    int number_2 = uid(gen);
    int oper = uid_2(gen);
    QString quest = "";

    // обработка и вывод примера на экран
    if (oper == 4 && number_2 == 0)
        number_2 = uid_3(gen);
    quest += QString::number(number_1) + " ";
    if (oper == 1 && number_2 < 0)
        quest += "- " + QString::number(qFabs(number_2)) + " =";
    if (oper == 1 && number_2 >= 0)
        quest += "+ " + QString::number(number_2) + " =";
    if (oper == 2 && number_2 < 0)
        quest += "+ " + QString::number(qFabs(number_2)) + " =";
    if (oper == 2 && number_2 >= 0)
        quest += "- " + QString::number(number_2) + " =";
    if (oper == 3 && number_2 < 0)
        quest += "* (" + QString::number(number_2) + ") =";
    if (oper == 3 && number_2 >= 0)
        quest += "* " + QString::number(number_2) + " =";
    if (oper == 4 && number_2 < 0)
        quest += "/ (" + QString::number(number_2) + ") =";
    if (oper == 4 && number_2 > 0)
        quest += "/ " + QString::number(number_2) + " =";
    ui->label_quest->setText(quest);

    // вычисление ответа
    if (oper == 1)
        game::check = QString::number(number_1 + number_2);
    if (oper == 2)
        game::check = QString::number(number_1 - number_2);
    if (oper == 3)
        game::check = QString::number(number_1 * number_2);
    if (oper == 4)
    {
        double boo = double(number_1) / double(number_2);
        int numb = boo * 1000;
        if (numb % 10 > 4)
        {
            numb += 10;
        }
        if (numb % 10 < -4)
        {
            numb -= 10;
        }
        int fr =numb / 1000;
        int sc = numb % 1000;
        bool isminus = false;
        QString number = "";
        if (sc < 0 || fr < 0)
            isminus = true;
        if (isminus == true)
        {
            number = "-" + QString::number(qFabs(fr)) + "." + QString::number(qFabs(sc));
        }
        else
        {
            number = QString::number(fr) + "." + QString::number(sc);
        }
        double numb_2 = number.toDouble();
        numb_2 = std::trunc(numb_2 * 100) / 100;
        game::check = QString::number(numb_2);
    }
}

game::~game()
{
    delete ui;
}

// ввод ответа пользователем
void game::on_lineEdit_answer_textEdited(const QString &arg1)
{
    game::answer = arg1;
}

// проверка ответа
void game::on_pushButton_answer_clicked()
{
    // неверный ответ
    if (game::answer != game::check)
    {
        QMessageBox::information(this, "Ошибка", "Вы ответили неверно!");
        MainWindow *mainwind = new MainWindow();
        if (game::mult == 1)
        {
            QFile file_easy("../../Data/easy.txt");
            file_easy.open(QIODevice::ReadWrite);
            QString var = QByteArray(file_easy.readAll());
            QByteArray new1 = "";
            if (var == "")
            {
                new1 = "";
                new1.setNum(game::score);
                file_easy.write(new1);
            }
            else
            {
                int score = var.toInt();
                if (game::score > score)
                {
                    new1.setNum(game::score);
                    QFile::remove("../../Data/easy.txt");
                    QFile file_easy("../../Data/easy.txt");
                    file_easy.open(QIODevice::WriteOnly);
                    file_easy.write(new1);
                }
            }
            file_easy.close();
        }
        else if (game::mult == 5)
        {
            QFile file_medium("../../Data/medium.txt");
            file_medium.open(QIODevice::ReadWrite);
            QString var = QByteArray(file_medium.readAll());
            QByteArray new1 = "";
            if (var == "")
            {
                new1 = "";
                new1.setNum(game::score);
                file_medium.write(new1);
            }
            else
            {
                int score = var.toInt();
                if (game::score > score)
                {
                    new1.setNum(game::score);
                    QFile::remove("../../Data/medium.txt");
                    QFile file_medium("../../Data/medium.txt");
                    file_medium.open(QIODevice::WriteOnly);
                    file_medium.write(new1);
                }
            }
            file_medium.close();
        }
        else
        {
            QFile file_hard("../../Data/hard.txt");
            file_hard.open(QIODevice::ReadWrite);
            QString var = QByteArray(file_hard.readAll());
            QByteArray new1 = "";
            if (var == "")
            {
                new1 = "";
                new1.setNum(game::score);
                file_hard.write(new1);
            }
            else
            {
                int score = var.toInt();
                if (game::score > score)
                {
                    new1.setNum(game::score);
                    QFile::remove("../../Data/hard.txt");
                    QFile file_hard("../../Data/hard.txt");
                    file_hard.open(QIODevice::WriteOnly);
                    file_hard.write(new1);
                }
            }
            file_hard.close();
        }
        mainwind->setWindowTitle("Тренировка счёта");
        mainwind -> show();
        hide();
    }
    // верный ответ
    game::score += game::mult;
    ui->label_score_2->setText(QString::number(game::score));
    unsigned int ms = static_cast<unsigned>(QDateTime::currentMSecsSinceEpoch());
    std::mt19937 gen(ms);
    std::uniform_int_distribution<> uid(-game::dif_, game::dif_);
    std::uniform_int_distribution<> uid_2(1, 4);
    std::uniform_int_distribution<> uid_3(1, game::dif_);
    int number_1 = uid(gen);
    int number_2 = uid(gen);
    int oper = uid_2(gen);
    QString quest = "";
    if (oper == 4 && number_2 == 0)
        number_2 = uid_3(gen);
    quest += QString::number(number_1) + " ";
    if (oper == 1 && number_2 < 0)
        quest += "- " + QString::number(qFabs(number_2)) + " =";
    if (oper == 1 && number_2 >= 0)
        quest += "+ " + QString::number(number_2) + " =";
    if (oper == 2 && number_2 < 0)
        quest += "+ " + QString::number(qFabs(number_2)) + " =";
    if (oper == 2 && number_2 >= 0)
        quest += "- " + QString::number(number_2) + " =";
    if (oper == 3 && number_2 < 0)
        quest += "* (" + QString::number(number_2) + ") =";
    if (oper == 3 && number_2 >= 0)
        quest += "* " + QString::number(number_2) + " =";
    if (oper == 4 && number_2 < 0)
        quest += "/ (" + QString::number(number_2) + ") =";
    if (oper == 4 && number_2 > 0)
        quest += "/ " + QString::number(number_2) + " =";
    ui->label_quest->setText(quest);
    if (oper == 1)
        game::check = QString::number(number_1 + number_2);
    if (oper == 2)
        game::check = QString::number(number_1 - number_2);
    if (oper == 3)
        game::check = QString::number(number_1 * number_2);
    if (oper == 4)
    {
        double boo = double(number_1) / double(number_2);
        int numb = boo * 1000;
        if (numb % 10 > 4)
        {
            numb += 10;
        }
        if (numb % 10 < -4)
        {
            numb -= 10;
        }
        int fr =numb / 1000;
        int sc = numb % 1000;
        bool isminus = false;
        QString number = "";
        if (sc < 0 || fr < 0)
            isminus = true;
        if (isminus == true)
        {
            number = "-" + QString::number(qFabs(fr)) + "." + QString::number(qFabs(sc));
        }
        else
        {
            number = QString::number(fr) + "." + QString::number(sc);
        }
        double numb_2 = number.toDouble();
        numb_2 = std::trunc(numb_2 * 100) / 100;
        game::check = QString::number(numb_2);
    }
    ui->lineEdit_answer->setText("");
}

