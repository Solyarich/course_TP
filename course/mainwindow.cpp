/*!
\file   mainwindow.cpp
\brief  Исходный файл функционала главного меню (интерфейс главного меню)
\author Иванов Никита
\date   15.05.2023
*/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "choose_difficulty.h"
#include "records.h"
#include <QFile>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // создание файлов
    QFile fail_easy("../../Data/easy.txt");
    fail_easy.open(QIODevice::ReadWrite);
    QFile fail_medium("../../Data/medium.txt");
    fail_medium.open(QIODevice::ReadWrite);
    QFile fail_hard("../../Data/hard.txt");
    fail_hard.open(QIODevice::ReadWrite);

    fail_easy.close();
    fail_medium.close();
    fail_hard.close();
}

MainWindow::~MainWindow()
{
    delete ui;
}

// кнопка выхода
void MainWindow::on_pushButton_exit_clicked()
{
    QWidget::close();
}

// кнопка рекордов
void MainWindow::on_pushButton_records_clicked()
{
    records *rec = new records;
    rec->setWindowTitle("Рекорды");
    rec -> show();
    hide();
}

// кнопка играть
void MainWindow::on_pushButton_playgame_clicked()
{
    choose_difficulty *choose_dif = new choose_difficulty;
    choose_dif->setWindowTitle("Сложность");
    choose_dif -> show();
    hide();
}

// кнопка помощь
void MainWindow::on_pushButton_help_clicked()
{
    QMessageBox::information(this, "Помощь", "Добро пожаловать! \n"
"В главном меню Вы можете выбрать играть или посмотреть рекорды. Чтобы начать игру необходимо нажать на соответсвующую кнопку и выбрать уровень сложности. На лёгком уровне вам даётся по 1 очку за правильный ответ, на среднем - 5, на тяжёлом - 10. Чтобы ответить необходимо ввести ответ в поле и нажать ответить. Для выхода из игры можно нажать ответить ничего не вводя в поле ответа.");
}

