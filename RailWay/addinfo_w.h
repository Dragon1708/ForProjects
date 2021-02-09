#ifndef ADDINFO_W_H
#define ADDINFO_W_H
#pragma once
#include <QDialog>
#include <qfile.h>
#include <QDate>
#include <QTime>
#include <QVector>
#include <QList>

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

    void on_buttonBox_rejected();

private:
    Ui::AddInfo_W *ui;
};

class RailData{
public:
    int NumTrain;
    QString final_Dest;
     QDate DATE_Exit;
    QTime Depart_Time;
    int NumCompey;
    int NumPlazk;
};
#endif // ADDINFO_W_H
