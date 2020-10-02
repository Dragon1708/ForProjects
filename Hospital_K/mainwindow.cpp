#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include <QTimer>

#include <qfile.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

       QLayout* l = new QVBoxLayout;
       l->addWidget( ui->listWidget );
       setLayout( l );
}

QFile fileDATA("DATAtemp.bin");
QVector <Pasient> HospitalDATA;
QVector<int> IDsearch;
 QTimer *SearchTimer = new QTimer();
 bool Cantimer=true;
 bool isSearch=false;

 void PrintDATA(){
     for(int i=0;i<HospitalDATA.length();i++){
          qDebug()<< "=====ASA";
        qDebug()<< HospitalDATA[i].FIO;
        qDebug()<< HospitalDATA[i].NumPalat;
     }
 }
 void MainWindow::AddAll_Items(){
     ui->listWidget->clear();
  for (int i=0;i<HospitalDATA.length();i++) {
     AddItem( ui->listWidget, HospitalDATA[i]);
  }
 }

void RemoveElement(int Index){
if(isSearch){
 HospitalDATA.remove(IDsearch[Index]);
}
else {

    HospitalDATA.remove(Index);
}
}

void MainWindow::ChangeElement(int Index){
    if(isSearch){
        ChangePasient Change_W;
        Change_W.AddInfoToPanels(&HospitalDATA[IDsearch[Index]]);
       Change_W.setModal(true);
                Change_W.exec();
          SearchTimer->stop();
          AddAll_Items();
           isSearch=false;
        Cantimer=true;
    }
    else {
        ChangePasient Change_W;
        Change_W.AddInfoToPanels(&HospitalDATA[Index]);
       Change_W.setModal(true);
                Change_W.exec();
               AddAll_Items();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::AddItem( QListWidget* lstWgt,Pasient NewPasient) {
    QWidget* wgt = new QWidget;
    QLayout* l = new QHBoxLayout;
  QLabel*Num_palata=new QLabel();
   QLabel*Name=new QLabel(NewPasient.FIO);
   QLabel*Gen=new QLabel(NewPasient.Gender);
   Num_palata->setText(QString::number(NewPasient.NumPalat));
    l->addWidget(Name);
    l->addWidget(Num_palata);
    l->addWidget(Gen);
     QPushButton* DelB = new QPushButton( "Delete" );
     QPushButton* ChangeB = new QPushButton( "Change" );
    connect(ui->listWidget, SIGNAL(itemClicked(QListWidgetItem*)),
               this, SLOT(SelectItemEvent(QListWidgetItem*)));
    connect( DelB, SIGNAL( clicked() ), SLOT( on_DelPasient_clicked() ) );
     connect( ChangeB, SIGNAL( clicked() ), SLOT( onChangeBClicked() ) );
    l->addWidget(ChangeB);
    l->addWidget(DelB);
    wgt->setLayout( l );

    QListWidgetItem* item = new QListWidgetItem( lstWgt );
    item->setSizeHint( wgt->sizeHint() );
    lstWgt->setItemWidget( item, wgt );

}

void MainWindow::on_AddPasient_clicked()
{
    AddInfo_W window;
    window.setModal(true);
            window.exec();
//QString str="";
 AddItem( ui->listWidget, HospitalDATA.back());
 /* if ((fileDATA.exists())&&(fileDATA.open(QIODevice::ReadOnly)))
{
 Pasient Temp;
   while(!fileDATA.atEnd())
   {
       str=fileDATA.readLine();

       bool Check=false;
       if(str=="@@@__\n"){
        Check=true;
       }
       if(Check){
           Temp.FIO=fileDATA.readLine();
           Temp.NumPalat=fileDATA.readLine().toInt();
           Temp.Gender=fileDATA.readLine();
           Temp.Diagnoz=fileDATA.readLine();
           HospitalDATA.append(Temp);
          // qDebug()<< "GENDER "<<Temp.FIO;

           file.write('\n'+ui->FIO_Text->toPlainText().toUtf8());
           file.write('\n'+ui->Ward_T->toPlainText().toUtf8());
           file.write('\n'+ui->Gender_T->toPlainText().toUtf8());
           file.write('\n'+ui->Diag_T->toPlainText().toUtf8());

       }
       if(str=="###__@\n"){
        Check=false;
       }

   }
   fileDATA.close();


  AddItem( ui->listWidget, HospitalDATA.back().FIO, HospitalDATA.back().NumPalat, HospitalDATA.back().Gender);

  //ZakachDATA
   for (int i=0;i<HospitalDATA.length();i++) {
       bool tempB=true;
       for (int j=1;j<HospitalDATA.length();j++) {
           if(HospitalDATA[i].FIO==HospitalDATA[j].FIO){
               tempB=false;
           }
       }
if(tempB){
     AddItem( ui->listWidget, HospitalDATA[i].FIO, HospitalDATA[i].NumPalat, HospitalDATA[i].Gender);
}*/
  qDebug()<<"=========ADDED";
  for(int i=0;i<HospitalDATA.length();i++){
     qDebug()<< HospitalDATA[i].FIO;
     // qDebug()<< HospitalDATA.length();

  }
}

void MainWindow::SelectItemEvent(QListWidgetItem* item){

    qDebug()<<"Znachenie "<< ui->listWidget->currentRow();
    qDebug()<<item;
    qDebug()<<"=========";
    for(int i=0;i<HospitalDATA.length();i++){
        qDebug()<< HospitalDATA[i].FIO;
         qDebug()<< HospitalDATA.length();
    }
}

void  MainWindow::on_DelPasient_clicked(){
    if(ui->listWidget->currentRow()!=-1){
        RemoveElement( ui->listWidget->currentRow());
    qDeleteAll(ui->listWidget->selectedItems());
    }
}

void MainWindow::on_SortPalat_clicked()
{
     Pasient tempSearch;
   ui->listWidget->clear();
   for (int i = 0; i < HospitalDATA.length() - 1; i++) {
          for (int j = 0; j < HospitalDATA.length() - i - 1; j++) {
              if (HospitalDATA[j].NumPalat > HospitalDATA[j + 1].NumPalat) {
                  // меняем элементы местами
                  tempSearch= HospitalDATA[j];
                  HospitalDATA[j] = HospitalDATA[j + 1];
                  HospitalDATA[j + 1] =tempSearch;
              }
          }
      }
   AddAll_Items();
}
void MainWindow::on_SearchButton_clicked()
{
     IDsearch.clear();
    QVector<Pasient> temp;
    ui->listWidget->clear();
    for(int i=0;i<HospitalDATA.length();i++){
        if(HospitalDATA[i].FIO.toLower().indexOf(ui->Search_Text->toPlainText().toLower())!=-1){
            temp.append(HospitalDATA[i]);
            IDsearch.append(i);
            isSearch=true;
        }
    }
    for (int i=0;i<temp.length();i++) {
        AddItem( ui->listWidget, temp[i]);
    }
if( Cantimer){
    connect(SearchTimer, SIGNAL(timeout()), this, SLOT(update()));
    SearchTimer->start(1000);
    Cantimer=false;
}
}
void MainWindow::onChangeBClicked(){
    if(ui->listWidget->currentRow()!=-1){
        ChangeElement(ui->listWidget->currentRow());
    }
}

void MainWindow::update(){
    if(ui->Search_Text->toPlainText()==""||ui->Search_Text->toPlainText()==" "){
         qDebug()<< "Nichego";
         SearchTimer->stop();
         Cantimer=true;
         isSearch=false;
          AddAll_Items();
    }
}
