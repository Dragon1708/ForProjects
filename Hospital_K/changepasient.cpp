#include "changepasient.h"
#include "ui_changepasient.h"
#include <QDebug>

ChangePasient::ChangePasient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangePasient)
{
    ui->setupUi(this);
}

ChangePasient::~ChangePasient()
{
    delete ui;
}

Pasient *ChangedItem;
void ChangePasient::AddInfoToPanels(Pasient *Pas){
    ChangedItem=Pas;
    ui->FIO_Text->insertPlainText(Pas->FIO);
    ui->Ward_T->insertPlainText(QString::number(Pas->NumPalat));
   ui->Gender_T->insertPlainText(Pas->Gender);
    ui->Diag_T->insertPlainText(Pas->Diagnoz);


}

void ChangePasient::on_buttonBox_accepted()
{
ChangedItem->FIO=ui->FIO_Text->toPlainText();
ChangedItem->NumPalat=ui->Ward_T->toPlainText().toInt();
ChangedItem->Gender=ui->Gender_T->toPlainText();
ChangedItem->Diagnoz=ui->Diag_T->toPlainText();
}

