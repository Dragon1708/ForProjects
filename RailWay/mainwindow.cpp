#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include <QTimer>
#include <QHBoxLayout>

#include <qfile.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
  Load();
}

QFile fileDATA("MainDATA.ral");
QString Defile="@@@__";
QString Endfile="###__@";
QList <RailData> RailwayDATA;
QVector<int> IDsearch;
 bool isSearch=false;

 void PrintDATA(){
     for(int i=0;i<RailwayDATA.length();i++){
          qDebug()<< "=====ASA";
        //qDebug()<< RailwayDATA[i].FIO;
     //   qDebug()<< RailwayDATA[i].NumPalat;
     }
 }
void MainWindow::AddInfoToPanel(){
   //ui->NameText->setText(RailwayDATA[ui->listWidget->currentRow()].FIO);
    qDebug()<<"SOOO";
   ui->RouteTrain_T->setText(RailwayDATA[ui->listWidget->currentRow()].final_Dest);
   ui->NumTrain_T->setText(QString::number(RailwayDATA[ui->listWidget->currentRow()].NumTrain));
   ui->Date_T->setText(RailwayDATA[ui->listWidget->currentRow()].DATE_Exit.toString());
   ui->Time_T->setText(RailwayDATA[ui->listWidget->currentRow()].Depart_Time.toString("hh:mm"));
   ui->Plaz_T->setText(QString::number(RailwayDATA[ui->listWidget->currentRow()].NumPlazk));
   ui->Kupe_T->setText(QString::number(RailwayDATA[ui->listWidget->currentRow()].NumCompey));
}
 void MainWindow::AddAll_Items(){
     ui->listWidget->clear();
  for (int i=0;i<RailwayDATA.length();i++) {
     AddItem( ui->listWidget, RailwayDATA[i]);
  }
 }

void RemoveElement(int Index){
if(isSearch){
// RailwayDATA.remove(IDsearch[Index]);
 RailwayDATA.removeAt(IDsearch[Index]);
}
else {

    RailwayDATA.removeAt(Index);
}
}

void MainWindow::ChangeElement(int Index){
    if(isSearch){
        ChangePasient Change_W;
        Change_W.AddInfoToPanels(&RailwayDATA[IDsearch[Index]]);
       Change_W.setModal(true);
                Change_W.exec();

          AddAll_Items();
           isSearch=false;

    }
    else {
        ChangePasient Change_W;
        Change_W.AddInfoToPanels(&RailwayDATA[Index]);
       Change_W.setModal(true);
                Change_W.exec();
               AddAll_Items();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::AddItem( QListWidget* lstWgt,RailData NewTrain) {
    QWidget* wgt = new QWidget;
    QGridLayout* l = new QGridLayout;
  QLabel*Num_Train=new QLabel(QString::number(NewTrain.NumTrain));
  //Num_palata->setText(QString::number(NewTrain.NumTrain));
   QLabel*final_Dest=new QLabel(NewTrain.final_Dest);
   QLabel*ExitDATE=new QLabel(NewTrain.DATE_Exit.toString());
    QLabel*Depart_Time=new QLabel(NewTrain.Depart_Time.toString("hh:mm"));
    QLabel*NumPlaz=new QLabel(QString::number(NewTrain.NumPlazk));
    QLabel*NumCompey=new QLabel(QString::number(NewTrain.NumCompey));
    l->addWidget(Num_Train, 0,0,Qt::AlignCenter);
    l->addWidget(final_Dest, 0,1,Qt::AlignCenter);
    l->addWidget(ExitDATE, 0,2,Qt::AlignCenter);
    l->addWidget(Depart_Time, 0,3, Qt::AlignCenter);
    l->addWidget(NumPlaz, 0,4,Qt::AlignCenter);
    l->addWidget(NumCompey, 0,5,Qt::AlignCenter);
    wgt->setLayout( l );
    QListWidgetItem* item = new QListWidgetItem( lstWgt );
/*   QPixmap bkgnd(":/PicResource/Group 1.png");
   bkgnd.scaled(11, 21, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    item->setBackground(bkgnd); */

    item->setSizeHint( wgt->sizeHint() );
    lstWgt->setItemWidget( item, wgt );
}

void MainWindow::on_AddPasient_clicked()
{
    AddInfo_W window;
    window.setModal(true);
            window.exec();
  if(!RailwayDATA.empty()){
      AddItem( ui->listWidget, RailwayDATA.back());
      qDebug()<<"=========ADDED";
      for(int i=0;i<RailwayDATA.length();i++){
         qDebug()<< RailwayDATA[i].final_Dest;
         // qDebug()<< HospitalDATA.length();
      }
 }

}

void MainWindow::update(){
    if(ui->Search_Text->toPlainText()==""||ui->Search_Text->toPlainText()==" "){
         isSearch=false;
          AddAll_Items();
    }
}

void MainWindow::on_Search_Text_textChanged()
{
    IDsearch.clear();
   QVector<RailData> temp;
   ui->listWidget->clear();
   for(int i=0;i<RailwayDATA.length();i++){
       if(RailwayDATA[i].final_Dest.toLower().indexOf(ui->Search_Text->toPlainText().toLower())!=-1){
           temp.append(RailwayDATA[i]);
           IDsearch.append(i);
           isSearch=true;
       }
   }
   for (int i=0;i<temp.length();i++) {
       AddItem( ui->listWidget, temp[i]);
   }
   // Cantimer=false;
}
bool MinMaxP=true;
void MainWindow::on_SortPlaz_clicked()
{
    if(MinMaxP){
        RailData tempSearch;
      ui->listWidget->clear();
      for (int i = 0; i < RailwayDATA.length() - 1; i++) {
             for (int j = 0; j < RailwayDATA.length() - i - 1; j++) {
                 if (RailwayDATA[j].NumPlazk < RailwayDATA[j + 1].NumPlazk) {
                     // меняем элементы местами
                     tempSearch= RailwayDATA[j];
                     RailwayDATA[j] = RailwayDATA[j + 1];
                     RailwayDATA[j + 1] =tempSearch;
                 }
             }
         }
      AddAll_Items();
  MinMaxP=false;
    }
    else {
        RailData tempSearch;
      ui->listWidget->clear();
      for (int i = 0; i < RailwayDATA.length() - 1; i++) {
             for (int j = 0; j < RailwayDATA.length() - i - 1; j++) {
                 if (RailwayDATA[j].NumPlazk > RailwayDATA[j + 1].NumPlazk) {
                     // меняем элементы местами
                     tempSearch= RailwayDATA[j];
                     RailwayDATA[j] = RailwayDATA[j + 1];
                     RailwayDATA[j + 1] =tempSearch;
                 }
             }
         }
      AddAll_Items();
        MinMaxP=true;
    }
}


void MainWindow::on_SortNumTrain_clicked()
{
    if(MinMaxP){
        RailData tempSearch;
      ui->listWidget->clear();
      for (int i = 0; i < RailwayDATA.length() - 1; i++) {
             for (int j = 0; j < RailwayDATA.length() - i - 1; j++) {
                 if (RailwayDATA[j].NumTrain < RailwayDATA[j + 1].NumTrain) {
                     // меняем элементы местами
                     tempSearch= RailwayDATA[j];
                     RailwayDATA[j] = RailwayDATA[j + 1];
                     RailwayDATA[j + 1] =tempSearch;
                 }
             }
         }
      AddAll_Items();
  MinMaxP=false;
    }
    else {
        RailData tempSearch;
      ui->listWidget->clear();
      for (int i = 0; i < RailwayDATA.length() - 1; i++) {
             for (int j = 0; j < RailwayDATA.length() - i - 1; j++) {
                 if (RailwayDATA[j].NumTrain > RailwayDATA[j + 1].NumTrain) {
                     // меняем элементы местами
                     tempSearch= RailwayDATA[j];
                     RailwayDATA[j] = RailwayDATA[j + 1];
                     RailwayDATA[j + 1] =tempSearch;
                 }
             }
         }
      AddAll_Items();
        MinMaxP=true;
    }
}

void MainWindow::on_SortKupe_clicked()
{
    if(MinMaxP){
        RailData tempSearch;
      ui->listWidget->clear();
      for (int i = 0; i < RailwayDATA.length() - 1; i++) {
             for (int j = 0; j < RailwayDATA.length() - i - 1; j++) {
                 if (RailwayDATA[j].NumCompey < RailwayDATA[j + 1].NumCompey) {
                     // меняем элементы местами
                     tempSearch= RailwayDATA[j];
                     RailwayDATA[j] = RailwayDATA[j + 1];
                     RailwayDATA[j + 1] =tempSearch;
                 }
             }
         }
      AddAll_Items();
  MinMaxP=false;
    }
    else {
        RailData tempSearch;
      ui->listWidget->clear();
      for (int i = 0; i < RailwayDATA.length() - 1; i++) {
             for (int j = 0; j < RailwayDATA.length() - i - 1; j++) {
                 if (RailwayDATA[j].NumCompey > RailwayDATA[j + 1].NumCompey) {
                     // меняем элементы местами
                     tempSearch= RailwayDATA[j];
                     RailwayDATA[j] = RailwayDATA[j + 1];
                     RailwayDATA[j + 1] =tempSearch;
                 }
             }
         }
      AddAll_Items();
       MinMaxP=true;
    }
}

void MainWindow::on_ChangeInfo_clicked()
{
    if(ui->listWidget->currentRow()!=-1){
        ChangeElement(ui->listWidget->currentRow());
    }
}

void MainWindow::on_Delete_Item_clicked()
{
    if(ui->listWidget->currentRow()!=-1){
        RemoveElement( ui->listWidget->currentRow());
    qDeleteAll(ui->listWidget->selectedItems());
    }
}

void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
  AddInfoToPanel();
}

//SaveButton
void MainWindow::Save(){
    fileDATA.remove();
    if (fileDATA.open(QIODevice::ReadWrite))
    {
        for (int i=0;i<RailwayDATA.length();i++) {
            fileDATA.write('\n'+Defile.toUtf8());
        fileDATA.write('\n'+QString::number(RailwayDATA[i].NumTrain).toUtf8());
        fileDATA.write('\n'+RailwayDATA[i].final_Dest.toUtf8());
        fileDATA.write('\n'+RailwayDATA[i].DATE_Exit.toString().toUtf8());
       fileDATA.write('\n'+RailwayDATA[i].Depart_Time.toString().toUtf8());
        fileDATA.write('\n'+QString::number(RailwayDATA[i].NumPlazk).toUtf8());
        fileDATA.write('\n'+QString::number(RailwayDATA[i].NumCompey).toUtf8());
            fileDATA.write('\n'+Endfile.toUtf8());
        }

        fileDATA.close();
}
}
//LoadButton
void MainWindow::Load(){
    QString str;
    RailData Temp;
    if ((fileDATA.exists())&&(fileDATA.open(QIODevice::ReadOnly)))
    {  while(!fileDATA.atEnd())
        {
            str=fileDATA.readLine();
            bool Check=false;
            if(str=="@@@__\n"){
             Check=true;
            }
            if(Check){
                Temp.NumTrain=fileDATA.readLine().toInt();
                Temp.final_Dest=fileDATA.readLine();
                Temp.DATE_Exit= QDate::fromString(fileDATA.readLine());
                Temp.Depart_Time= QTime::fromString(fileDATA.readLine());
                Temp.NumPlazk=fileDATA.readLine().toInt();
                Temp.NumCompey=fileDATA.readLine().toInt();
             RailwayDATA.append(Temp);
            }
            if(str=="###__@\n"){
             Check=false;
            }
        }
        fileDATA.close();
    }
    AddAll_Items();
}


void MainWindow::on_pushButton_clicked()
{
    Save();
}
