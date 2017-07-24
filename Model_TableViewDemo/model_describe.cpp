#include "model_describe.h"
#include<QDebug>
Model_Describe::Model_Describe()
{
    QString  str="A<B<C<D<E";
//    m_headData=str.split('<');
    m_headData<<"A"<<"B"<<"C"<<"D"<<"E";
    }
int Model_Describe::rowCount(const QModelIndex &parent) const
{
    return  vecdata.size();
}
int Model_Describe::columnCount(const QModelIndex &parent) const
{
    return  m_headData.size();
}
QVariant Model_Describe::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
    {
        return QVariant();
    }
    if(role==Qt::TextAlignmentRole)
    {
        //QVariant value= Qt::AlignCenter;
        return QVariant(Qt::AlignRight|Qt::AlignCenter);
        //return   value;
    }
     if(role==Qt::DisplayRole)
    {
        foreach ( QStringList  itemrow,vecdata)
        {
            switch(index.column()){

            case 0: return itemrow.at(0);break;

            case 1: return  itemrow.at(1);break;

            case 2:  return itemrow.at(2);break;

            case 3: return  itemrow.at(3);break;

            case 4: return itemrow.at(4);break;

            default:return QVariant();
            }

        }
        return QVariant();
    }
     return QVariant();
}
QVariant Model_Describe::headerData(int section, Qt::Orientation orientation,int role) const//
{
        if(role==Qt::DisplayRole && orientation==Qt::Horizontal)
                    //qDebug()<<"ID"<<section<<"value"<<m_headData.at(section);
         return  m_headData[section];

           return QAbstractTableModel::headerData(section,orientation,role);
}
void Model_Describe::setModelData(const QVector<QStringList> &strvec_Datas){
    vecdata=strvec_Datas;
    //reset();Qt 5  had delete it
    //the new way:
    //QAbstractItemModel::beginResetModel();

    //QAbstractItemModel::endResetModel();
}
