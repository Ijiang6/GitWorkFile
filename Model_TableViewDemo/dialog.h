#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include"model_describe.h"
#include<QVector>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
void   setInit();
private:
    Ui::Dialog *ui;
    Model_Describe * user_model;
    QStringList    datalist;
    QString     str;
    QVector<QStringList> vec_idata;

};

#endif // DIALOG_H
