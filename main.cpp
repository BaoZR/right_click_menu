#include "mainwindow.h"
#include "contentmenuevent.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ContentMenuEvent   w;
    //MainWindow w;
    w.show();
    return a.exec();
}
