/*!
\file   choose_difficulty.cpp
\brief  Исходный файл функционала меню выбора сложности
\author Иванов Никита
\date   15.05.2023
*/

#include "choose_difficulty.h"
#include "ui_choose_difficulty.h"
#include "game.h"

choose_difficulty::choose_difficulty(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::choose_difficulty)
{
    ui->setupUi(this);
}

choose_difficulty::~choose_difficulty()
{
    delete ui;
}

// кнопка лёгкой сложности
void choose_difficulty::on_pushButton_easy_clicked()
{
    game *gam = new game(10);
    gam->setWindowTitle("Игра");
    gam -> show();
    hide();
}

// кнопка средней сложности
void choose_difficulty::on_pushButton_medium_clicked()
{
    game *gam = new game(25);
    gam->setWindowTitle("Игра");
    gam -> show();
    hide();
}

// кнопка тяжёлой сложности
void choose_difficulty::on_pushButton_hard_clicked()
{
    game *gam = new game(50);
    gam->setWindowTitle("Игра");
    gam -> show();
    hide();
}

