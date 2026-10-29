#include "mainwindow.h"
#include "Game.h"
#include <QApplication>
#include <fstream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();

}
