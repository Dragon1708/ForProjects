#include "addinfo_w.h"
#include "ui_addinfo_w.h"
#include "ui_mainwindow.h"
#include<QDebug>

AddInfo_W::AddInfo_W(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddInfo_W)
{
    ui->setupUi(this);

}
QString Defile="@@@__";
QString Endfile="###__@";
AddInfo_W::~AddInfo_W()
{
    delete ui;
}
extern QVector<Pasient> HospitalDATA;
QFile file("DATAtemp.bin");

void AddInfo_W::on_buttonBox_accepted()
{
/*
   if (file.open(QIODevice::Append))
   {
       file.write('\n'+Defile.toUtf8());
      file.write('\n'+ui->FIO_Text->toPlainText().toUtf8());
      file.write('\n'+ui->Ward_T->toPlainText().toUtf8());
      file.write('\n'+ui->Gender_T->toPlainText().toUtf8());
      file.write('\n'+ui->Diag_T->toPlainText().toUtf8());
       file.write('\n'+Endfile.toUtf8());
       file.close();
*/
    Pasient tempDATA;
        tempDATA.FIO=ui->FIO_Text->toPlainText();
         tempDATA.Gender=ui->Gender_T->toPlainText();
         tempDATA.NumPalat=ui->Ward_T->toPlainText().toInt();
        tempDATA.Diagnoz=ui->Diag_T->toPlainText();
    HospitalDATA.append(tempDATA);
    qDebug()<< "ZApisalo";

 }

