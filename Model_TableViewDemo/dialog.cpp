#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    str="a,b,c,d,e";
    user_model=new Model_Describe;
    setInit();
}
void Dialog::setInit(){
    datalist=str.split(',');
    vec_idata.append(datalist);
    vec_idata.append(datalist);
    vec_idata.append(datalist);
    user_model->setModelData(vec_idata);
    ui->tableView->setModel( user_model);
}

Dialog::~Dialog()
{
    delete ui;
}
