#include "contentmenuevent.h"

#include <QAction>
#include <QDebug>
#include <QMenu>
#include <QList>
#include <QLabel>
#include <QFont>
#include <QDesktopServices>

/**************************************************************************
* 三种显示右键菜单的方式
* 1. Qt::DefaultContextMenu 默认的显示右键菜单的方式, QWidget 的子类重写
*    QWidget::contextMenuEvent() 函数来实现菜单的显示
*
* 2. Qt::ActionsContextMenu 右键菜单式QWidget 的所有acitons 作为菜单
*
* 3. Qt::CustomContextMenu 发送  QWidget::customContextMenuRequested() 信号
*		通过重写函数来相应这个信号, 可以显示菜单......
*
***************************************************************************/



//  如果想通过默认的菜单显示方式, 则不需要设置菜单选项
// 如果通过显示action 来显示右键菜单, 设置属性setContextMenuPolicy(Qt::ActionsContextMenu)
    // 同时往QWidget 子类中天就要显示的action

// 通过发送相应信号的方式来显示右键菜单, 设置setContextMenuPolicy(Qt::CustomContextMenu)
    // 设置相应信号的函数, 生成菜单的对象, 往菜单对象中添加 action
    // 显示菜单
ContentMenuEvent::ContentMenuEvent(QWidget *parent)
    : QWidget(parent)
{
    qDebug() << "显示默认的菜单选项  : "<<contextMenuPolicy();

    //通过设置menu策略来显示右键菜单的方式


    //setContextMenuPolicy(Qt::ActionsContextMenu);
    setContextMenuPolicy(Qt::CustomContextMenu);

    //重新设置窗口的大小
    resize(800, 600);
    //actions.append(new QAction(QIcon(), "ok", this));


    addAction(new QAction(QIcon("this"), "点击我是没有任何反应的!", this));
    QFont font("微软雅黑",20,12,true);
    auto label = new QLabel(this);
    qDebug() << " label parent " << label->parent();
    label->setGeometry(0, 0, 800, 600);
    label->setObjectName("label");
    label->setWordWrap(true);   //设置自动换行
    label->setFont(font);		//设置字体
    label->setText(" 通过  setContextMenuPolicy(Qt::ContextMenuPolicy policy) 函数设置右键菜单 试下在窗口点击鼠标右键吧!  ");
    connect(this, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(oshowMenu(const QPoint &)));
}





// 这是通过发送信号的方式来显示右键的菜单
void ContentMenuEvent::oshowMenu(const QPoint &pos)
{
    static QMenu *menu = new (QMenu);
    menu->setTitle("自定义的菜单");
    static QList<QAction *> *list = nullptr ;
    if (list == nullptr) {
        list = new QList<QAction*>;
        list->append(new QAction(QIcon("icon.jpg"), "hello world ", this));

        list->append(new QAction(QIcon(), "hello  ", this));
        menu->setParent(this,Qt::Window);

        auto action = new QAction(this);
        // 设置icon的图标
        action->setIcon(QIcon(":/contentMenuEvent/Resources/icon.jpg"));
        //设置显示图标在icon 上
        action->setIconVisibleInMenu(true);
        action->setText("Qt积木笔记");
        // 同样处理 点击 信号. 跳转到 Qt积木笔记
        connect(action, SIGNAL(triggered(bool)), this, SLOT(QtjiMu()));
        // 将这个action append 到list
        list->append(action);
        menu->addActions(*list);


    }
    menu->move(pos);
    menu->show();

}

// contextMenuEvent 通过重写函数来实现函数来
// 实现右键的菜单
void ContentMenuEvent::ContextMenuEvent(QContextMenuEvent * event)
{
    qDebug() << "contextMenuEvent";
    static QMenu *menu = nullptr;;
    if (menu == nullptr) {
        menu = new QMenu(this);
        menu->setParent(this);
        menu->addActions(faActon());
    }

    // 选择globalX() 和globalY() 的返回值设置菜单的显示位置
    menu->move(event->globalX() ,event->globalY());
    menu->show();
}


//faActon  生产action ....
//
QList<QAction*> ContentMenuEvent::faActon()
{
    QList<QAction*> list;
    for (int i = 0; i < 10; i++) {
        //
        auto action = new QAction(this);
        action->setText("搜索 " + QString::number(i));
        // 链接信号的处理函数
        //处理的信号是 action 被点击的信号
        connect(action, SIGNAL(triggered(bool  )), this, SLOT(onAction()));
        // 将action append到list
        list.append(action);
    }

    //独立生产一个特殊的action
    // 在真是的开发中这个特殊的action 一般要用
    // 一个独立的函数来处理
    //不应该这样直接生成, 这样的代码不好维护
    auto action = new QAction(this);
    // setText 就是我们可以在用肉眼看到的文字
    action->setText("Qt积木笔记");

    action->setIcon(QIcon(":/contentMenuEvent/Resources/icon.jpg"));
    //设置显示图标在icon 上
    action->setIconVisibleInMenu(true);
    action->setText("Qt积木笔记");
    // 同样处理 点击 信号. 跳转到 Qt积木笔记
    connect(action, SIGNAL(triggered(bool)), this, SLOT(QtjiMu()));
    // 将这个action append 到list
    list.append(action);
    //
    return list;
}

// onAction action的响应函数
void ContentMenuEvent::onAction()
{
    auto se = sender();
    //向下转型
    auto action = dynamic_cast<QAction*>(se);
    if (action != nullptr) {
        //分割 ""
        auto li = action->text().split(" ");
        // action 的真正要做的事情, 这里只是做一个演示
        // 如果设置了默认的浏览器, 浏览器会通过搜索引擎搜索相应的数字
        // 分别 是  0 -9
        QDesktopServices::openUrl("http://www.baidu.com/s?wd=" + li[1]);
    }
}

//QtjiMu 指定转移到Qt积木笔记
void ContentMenuEvent::QtjiMu()
{
    auto se = sender();
    //用了一个向下转型
    auto action = dynamic_cast<QAction*>(se);

    if (action != nullptr) {
        // 唤醒浏览器, 跳转到 Qt积木笔记 ?
        QDesktopServices::openUrl(QUrl("https://zhuanlan.zhihu.com/c_140361491"));

    }
}
