#include "addinfo_w.h"
#include "ui_addinfo_w.h"
#include "ui_mainwindow.h"
#include<QDebug>

AddInfo_W::AddInfo_W(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddInfo_W)
{
    ui->setupUi(this);
    ui->TimeExit->setDisplayFormat("hh:mm");
    ui->dateExit->setDisplayFormat("dd.MM.yyyy");
}
//QString Defile="@@@__";
//QString Endfile="###__@";
AddInfo_W::~AddInfo_W()
{
    delete ui;
}
extern QList<RailData> RailwayDATA;
 RailData tempDATA;
//QFile file("DATAtemp.bin");

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
 RailData tempDATA;
        tempDATA.final_Dest=ui->FinalDest_T->toPlainText();
         tempDATA.NumTrain=ui->NumRace_T->toPlainText().toInt();
         tempDATA.DATE_Exit=ui->dateExit->date();
        tempDATA.Depart_Time=ui->TimeExit->time();
        tempDATA.NumPlazk=ui->NumPlaz_T->toPlainText().toInt();
       tempDATA.NumCompey=ui->NumCompey_T->toPlainText().toInt();
    RailwayDATA.append(tempDATA);
    qDebug()<< "ZApisalo";

 }


void AddInfo_W::on_buttonBox_rejected()
{


}
