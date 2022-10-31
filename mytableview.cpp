#include "mytableview.h"

MyTableView::MyTableView(QWidget *parent)
    : QTableView{parent},

      model(this),
      menu(this)
{
    (this->horizontalHeader())->setVisible(false);
    (this->verticalHeader())->setVisible(false);//去掉自动序号列
    this->setFocusPolicy(Qt::NoFocus);//取消焦点
    this->setEditTriggers(QAbstractItemView::NoEditTriggers);//设置无法编辑
   this->setSelectionMode(QAbstractItemView::SingleSelection);//设置视图只能选择一个项目
   this->setSelectionBehavior(QAbstractItemView::SelectRows);//设置视图只能选择行
    this->setModel(&model);//设置显示模型
    this->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//自适应所有列，让它布满空间
  //  view.verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);


    this->installEventFilter(this);//设置事件过滤器
    menu.addAction("删除",this,SLOT(on_delete()));     //设置菜单项,并连接槽函数


}
void MyTableView::on_delete(void)
{
    this->setEnabled(false);
    delete_item_signal(this->currentIndex().data().toString());
    model.removeRow(this->currentIndex().row());   //根据当前鼠标所在的索引的行位置,删除一行
    this->clearSelection();
}

bool MyTableView::eventFilter(QObject* obj, QEvent *evt)
{
    if(obj == this  &&  evt->type() == QEvent::ContextMenu) //被监视的组件为view,要转发的事件是上下文弹出菜单
    {
        if(this->currentIndex().isValid()==true)  //索引有效
        {
              menu.exec(cursor().pos());      //将菜单menu定位到当前鼠标位置
        }
    }
    return QWidget::eventFilter(obj,evt);//返回事件过滤器
}

void MyTableView::add_row(QString& tmpl_name)
{
    QStandardItem* item = new QStandardItem;
    item->setData(tmpl_name, Qt::DisplayRole);
    model.appendRow(item);

    int t = model.rowCount();
    qDebug()<< QString(t);
}

void MyTableView::remove_rows()
{
    this->model.clear();
}

//void MyTableView::setModel()
//{
//    qDebug() << model.rowCount();
//    view.setModel(&model);
//}

//int MyTableView::get_item_count()
//{
//    return  this->model.rowCount();
//}

