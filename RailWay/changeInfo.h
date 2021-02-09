#ifndef CHANGEPASIENT_H
#define CHANGEPASIENT_H

#include <QDialog>

#include "addinfo_w.h"

namespace Ui {
class ChangePasient;
}

class ChangePasient : public QDialog
{
    Q_OBJECT

public:
    explicit ChangePasient(QWidget *parent = nullptr);
    ~ChangePasient();
    QString FIO;
void AddInfoToPanels(RailData *Pas);
private slots:
    void on_buttonBox_accepted();

private:
    Ui::ChangePasient *ui;

};

#endif // CHANGEPASIENT_H
