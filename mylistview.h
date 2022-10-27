#ifndef MYLISTVIEW_H
#define MYLISTVIEW_H

#include <QWidget>
#include <QStringListModel>
#include <QListView>
#include <QHBoxLayout>
#include <QPushButton>
#include <QInputDialog>
#include <QMessageBox>

class MyListView : public QWidget
{
    Q_OBJECT
public:
    explicit MyListView(QWidget *parent = nullptr);

private:
    QStringListModel* model;
    QListView* listView;

signals:
public slots:
    void insertData();
    void deleteData();
    void showData();
};

#endif // MYLISTVIEW_H
