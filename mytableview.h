#ifndef MYTABLEVIEW_H
#define MYTABLEVIEW_H

#include <QWidget>
#include <QTableView>
#include <QStandardItemModel>
#include <QMenu>
#include <QEvent>
#include <QHeaderView>

class MyTableView : public QWidget
{
    Q_OBJECT
public:
    explicit MyTableView(QWidget *parent = nullptr);

 private:
    QTableView  view;
    QStandardItemModel model;
    QMenu menu;
    bool eventFilter(QObject* obj, QEvent *evt);//事件过滤器
signals:

public slots:
    void onDelete(void);

};

#endif // MYTABLEVIEW_H
