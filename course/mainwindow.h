/*!
\file   mainwindow.h
\brief  Заголовочный файл функционала главноего меню (интерфейс главного меню)
\author Иванов Никита
\date   15.05.2023
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/*!
\brief  Класс интерфейсного окна главного меню
\details Открывается форма интерфейсного окна главного меню
*/

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    /*!
        \brief Конструктор класса MainWindow
        */

    MainWindow(QWidget *parent = nullptr);

    /*!
        \brief Деструктор класса MainWindow
        */

    ~MainWindow();

private slots:

    /*!
        \brief Выход
        \details При нажатии на кнопку, пользователь выдет из приложения
        */

    void on_pushButton_exit_clicked();

    /*!
        \brief Рекорды
        \details При нажатии на кнопку, пользователь посмотрит на свои рекорды в лёгкой, средней и тяжёлой сложности
        */

    void on_pushButton_records_clicked();

    /*!
        \brief Играть
        \details При нажатии на кнопку, пользователь перейдёт к выбору сложности игры
        */

    void on_pushButton_playgame_clicked();

    /*!
        \brief Помощь
        \details При нажатии на кнопку, пользователь получит краткую инструкцию по использованию приложения
        */

    void on_pushButton_help_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
