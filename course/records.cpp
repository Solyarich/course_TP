/*!
\file   records.cpp
\brief  Исходный файл функционала меню рекордов
\author Иванов Никита
\date   15.05.2023
*/

#include "records.h"
#include "ui_records.h"
#include "mainwindow.h"
#include <QFile>

records::records(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::records)
{
    ui->setupUi(this);
    // чтение файлов
    QFile fail_easy("../../Data/easy.txt");
    fail_easy.open(QIODevice::ReadWrite);
    QFile fail_medium("../../Data/medium.txt");
    fail_medium.open(QIODevice::ReadWrite);
    QFile fail_hard("../../Data/hard.txt");
    fail_hard.open(QIODevice::ReadWrite);

    // вывод на экран данных
    QString var = QByteArray(fail_easy.readAll());
    if (var == "")
        ui->label_easy->setText("0");
    else
        ui->label_easy->setText(var);

    var = QByteArray(fail_medium.readAll());
    if (var == "")
        ui->label_medium->setText("0");
    else
        ui->label_medium->setText(var);

    var = QByteArray(fail_hard.readAll());
    if (var == "")
        ui->label_hard->setText("0");
    else
        ui->label_hard->setText(var);

    fail_easy.close();
    fail_medium.close();
    fail_hard.close();
}

records::~records()
{
    delete ui;
}

// кновка выхода
void records::on_pushButton_exit_clicked()
{
    MainWindow *main_win = new MainWindow;
    main_win->setWindowTitle("Тренировка счёта");
    main_win -> show();
    hide();
}

