#include "mainwindow.h"
#include "contentmenuevent.h"
#include "mylistview.h"
#include "mytableview.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyListView   w;
    //MyTableView w;
    //MainWindow w;
    w.show();
    return a.exec();
}
