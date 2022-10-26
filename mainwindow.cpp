#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "contentmenuevent.h"
#include "QDebug"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ContentMenuEvent e;
   // e.show();
     this->ui->pushButton->setContextMenuPolicy(Qt::CustomContextMenu);
    ;
    resize(800, 600);
    //this->setGeometry(0, 0, 800, 600);
    //setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this->ui->pushButton, &QPushButton::customContextMenuRequested,
            this, &MainWindow::showMenu);
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showMenu(const QPoint &pos)
{
    qDebug() <<"123";
    QMenu *menu = new QMenu(this);
    QAction *act = new QAction("helloworld");
    act->setStatusTip(tr("Open an existing file"));
    menu->setParent(this);
    menu->addAction(act);
//    menu->move(pos.x()+this->ui->pushButton->x()+this->geometry().x()
//               ,pos.y()+this->ui->pushButton->y()+this->geometry().y());
    menu->exec(QCursor::pos());
    //menu->show();
}

