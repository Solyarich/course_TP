/*!
\file   main.cpp
\brief  Основной исходный файл, с которого запускается приложение
\author Иванов Никита
\date   15.05.2023
*/

#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Тренировка счёта");
    w.show();
    return a.exec();
}
