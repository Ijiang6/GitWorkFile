#ifndef MODEL_DESCRIBE_H
#define MODEL_DESCRIBE_H
#include<QAbstractListModel>
#include<QStringList>
#include<QVector>

class Model_Describe : public QAbstractTableModel
{
public:
    Model_Describe();
    void setModelData(const QVector<QStringList> &strvec_Datas);
    int  rowCount(const QModelIndex &parent)const;// the count of Row
    int columnCount(const QModelIndex &parent) const;// the count of Coluwn
    QVariant    data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation,int role) const;//  the order of argument donot change ,if change ,it is  another one
private:
    QStringList  m_data;
    QStringList  m_headData;
    QVector<QStringList> vecdata;
};

///*
// Variant:    adj. 不同的；多样的     n. 变体；转化
// * QVariant类作为一个最为普遍的Qt数据类型的联合*
//    一个QVariant对象在一个时间内只保留一种类型的值。我们可以使用canConvert来查询是否能够转换当前的类型。转换类型一般以toT()命名。
//    QVariant实质就是一个union的用法封装。作为统一参数使用。
//    QVariant可以保存很多Qt的数据类型，包括QBrush、QColor、QCursor、QDateTime、QFont、QKeySequence、QPalette、QPen、QPixmap、QPoint、QRect、QRegion、
//    QSize和QString，并且还有C++基本类型，如int、float等。QVariant还能保存很多集合类型，如QMap<QString, QVariant>, QStringList和QList<QVariant>。
//    item view classes，数据库模块和QSettings都大量使用了QVariant类，，以方便我们读写数据。
//QTableView的使用：

//（1）设置最后一列填满表格剩余空间：

//tableView->horizontalHeader()->setStretchLastSection(true);

//（2）设置默认的表格行高：

//tableView->verticalHeader()->setDefaultSectionSize(20);

//（3）设置按内容调整列宽：

//tableView->horizontalHeader()->setResizeMode(QHeaderView::ResizeToContents);

//（4）设置只可以单行选择：

//tableView->setSelectionBehavior(QAbstractItemView::SelectRows);//按行选择

//tableView->setSelectionMode(QAbstractItemView::SingleSelection);//每次只可选择一行

//（5）设置表格交替填充背景色：

//tableView->setAlternatingRowColors(true);



//QAbstractTableModel的使用：

//（1）垂直表头需要在headerData中对DisplayRole进行设置才会有。

//继承QAbstractTableModel实现CurrencyModel,需要重写的函数有

//introwCount(constQModelIndex&parent)const; //返回表的行数

//intcolumnCount(constQModelIndex&parent)const;//返回表的列数

//QVariantheaderData(intsection,Qt::Orientationorientation,introle)const;//用来显示表头信息

//QVariantdata(constQModelIndex&index,introle)const;//用来显示表中的数据

//Qt::ItemFlagsflags(constQModelIndex&index)const;//设置表项是否可编辑

//boolsetData(constQModelIndex&index,constQVariant&value,introle =Qt::EditRole);//用来设置表的数据（指的是后台数据）
//重写rowCount()和columnCount()这两个函数，用于返回model的行数和列数
//------------------data()--------------------
//data()函数返回单元格的数据。它有两个参数：第一个是QModelIndex，也就是单元格的位置；第二个是role，也就是这个数据的角色。
//这个函数的返回值是QVariant。至此，我们还是第一次见到这个类型。这个类型相当于是Java里面的Object，
//它把绝大多数Qt提供的数据类型都封装起来，起到一个数据类型“擦除”的作用。
//比如我们的table单元格可以是string，也可以是int，也可以是一个颜色值，那么这么多类型怎么返回呢？
//于是，Qt提供了这个QVariant类型，你可以把这很多类型都存放进去，到需要使用的时候使用一系列的to函数取出来即可。
//比如你把int包装成一个QVariant，使用的时候要用QVariant::toInt()重新取出来。
//这里需要注意的是，QVariant类型的放入和取出必须是相对应的，你放入一个int就必须按int取出，
//不能用toString(), Qt不会帮你自动转换
//首先判断传入的index是不是合法，如果不合法直接return一个空白的QVariant。然后如果role是Qt::TextAlignmentRole，
//也就是文本的对象方式，那么就返回int(Qt::AlignRight | Qt::AlignVCenter)；
//否则，role如果是Qt::DisplayRole，就按照我们前面所说的逻辑进行计算，然后按照字符串返回。
//这时候你就会发现，其实我们在if…else…里面返回的不是一种数据类型，if里面是int，而else里面是QString，
//这就是QVariant的作用了，也正是“类型擦除”的意思。

//剩下的三个函数就很简单了：headerData()返回列名或者行名；setCurrencyMap()用于设置底层的数据源；
//currencyAt()返回偏移量为offset的键值。
//model->remove(startrow,endrow);  //delete rows
//* /
#endif // MODEL_DESCRIBE_H
