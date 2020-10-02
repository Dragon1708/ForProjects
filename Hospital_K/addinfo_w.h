#ifndef ADDINFO_W_H
#define ADDINFO_W_H
#pragma once
#include <QDialog>
#include <qfile.h>
#include <QVector>

namespace Ui {
class AddInfo_W;
}

class AddInfo_W : public QDialog
{
    Q_OBJECT

public:
    explicit AddInfo_W(QWidget *parent = nullptr);
    ~AddInfo_W();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::AddInfo_W *ui;
};

class Pasient{
public:
    QString FIO;
    int NumPalat;
    QString Gender;
    QString Diagnoz;
};
#endif // ADDINFO_W_H
