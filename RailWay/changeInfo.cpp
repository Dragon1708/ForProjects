#include "changeInfo.h"
#include "ui_changeInfo.h"
#include <QDebug>

ChangePasient::ChangePasient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangePasient)
{
    ui->setupUi(this);
    ui->TimeExit->setDisplayFormat("hh:mm");
    ui->dateExit->setDisplayFormat("dd.MM.yyyy");
}

ChangePasient::~ChangePasient()
{
    delete ui;
}

RailData *ChangedItem;
void ChangePasient::AddInfoToPanels(RailData *Pas){
    ChangedItem=Pas;

    ui->FinalDest_T->insertPlainText(Pas->final_Dest);
    ui->NumRace_T->insertPlainText(QString::number(Pas->NumTrain));
    ui->dateExit->setDate(Pas->DATE_Exit);
    ui->TimeExit->setTime(Pas->Depart_Time);
    ui->NumPlaz_T->insertPlainText(QString::number(Pas->NumPlazk));
    ui->NumCompey_T->insertPlainText(QString::number(Pas->NumCompey));
}

void ChangePasient::on_buttonBox_accepted()
{
ChangedItem->NumTrain=ui->NumRace_T->toPlainText().toInt();
ChangedItem->final_Dest=ui->FinalDest_T->toPlainText();
ChangedItem->DATE_Exit=ui->dateExit->date();
ChangedItem->Depart_Time=ui->TimeExit->time();
ChangedItem->NumPlazk=ui->NumPlaz_T->toPlainText().toInt();
ChangedItem->NumCompey=ui->NumCompey_T->toPlainText().toInt();
}

