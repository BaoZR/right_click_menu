#ifndef MYTABLEVIEW_H
#define MYTABLEVIEW_H

#include <QWidget>
#include <QTableView>
#include <QStandardItemModel>
#include <QMenu>
#include <QEvent>
#include <QHeaderView>
#include <QDebug>

class MyTableView : public QTableView
{
    Q_OBJECT
public:
    explicit MyTableView(QWidget *parent = nullptr);
    void add_row(QString& tmpl_name);
    void remove_rows();
    //void setModel();
    //int  get_item_count();
 private:
    //QTableView  view;
    QStandardItemModel model;
    QMenu menu;
    bool eventFilter(QObject* obj, QEvent *evt);//事件过滤器
signals:
    void delete_item_signal(QString name);
public slots:
    void on_delete(void);

};

#endif // MYTABLEVIEW_H
