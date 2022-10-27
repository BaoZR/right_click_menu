#include "mytableview.h"

MyTableView::MyTableView(QWidget *parent)
    : QWidget{parent},
      view(this),
      model(this),
      menu(this)
{
    //model.setItem(0,0, new QStandardItem("A"));
    //model.setItem(0,1, new QStandardItem("B"));
    //model.setItem(1,0, new QStandardItem("C"));
    //model.setItem(1,1, new QStandardItem("D"));
    //model.setItem(2,0, new QStandardItem("E"));
    //model.setItem(2,1, new QStandardItem("F"));
    //model.setItem(3,0, new QStandardItem("G"));
    //model.setItem(3,1, new QStandardItem("H"));
    model.setItem(0,new QStandardItem("A"));
    model.appendRow(new QStandardItem("A"));
    model.appendRow(new QStandardItem("A"));
    model.appendRow(new QStandardItem("A"));





    (view.horizontalHeader())->setVisible(false);
    view.setFocusPolicy(Qt::NoFocus);//取消焦点
    view.setEditTriggers(QAbstractItemView::NoEditTriggers);//设置无法编辑
    view.setSelectionMode(QAbstractItemView::SingleSelection);//设置视图只能选择一个项目
    view.setSelectionBehavior(QAbstractItemView::SelectRows);//设置视图只能选择行
    view.setModel(&model);//设置显示模型
    view.installEventFilter(this);//设置事件过滤器
    menu.addAction("删除",this,SLOT(onDelete()));     //设置菜单项,并连接槽函数


}
void MyTableView::onDelete(void)
{
    model.removeRow(view.currentIndex().row());   //根据当前鼠标所在的索引的行位置,删除一行
    view.clearSelection();
}

bool MyTableView::eventFilter(QObject* obj, QEvent *evt)
{
    if(obj == &view  &&  evt->type() == QEvent::ContextMenu) //被监视的组件为view,要转发的事件是上下文弹出菜单
    {
        if(view.currentIndex().isValid()==true)  //索引有效
        {
              menu.exec(cursor().pos());      //将菜单menu定位到当前鼠标位置
        }
    }
    return QWidget::eventFilter(obj,evt);//返回事件过滤器
}



