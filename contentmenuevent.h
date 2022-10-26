#ifndef CONTENTMENUEVENT_H
#define CONTENTMENUEVENT_H

#include <QObject>
#include <QWidget>
#include <QContextMenuEvent>

class ContentMenuEvent : public QWidget
{
    Q_OBJECT
public:
    explicit ContentMenuEvent(QWidget *parent = nullptr);

protected :
    void ContextMenuEvent(QContextMenuEvent *event);

private:
    QList<QAction*>faActon();

    private slots :
        void oshowMenu(const QPoint &pos);
        void onAction();
        void QtjiMu();

};

#endif // CONTENTMENUEVENT_H
