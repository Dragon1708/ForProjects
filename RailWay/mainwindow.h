#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include "addinfo_w.h"
#include "changeInfo.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
void AddItem( QListWidget* lstWgt,RailData NewPasient);
void AddInfoToPanel();
void SortFunk(QList <RailData> RailwayDA);
void Save();
void Load();

private slots:

    void on_AddPasient_clicked();
    void update();

    void ChangeElement(int Index);
    void AddAll_Items();

    void on_Search_Text_textChanged();

    void on_SortPlaz_clicked();

    void on_SortNumTrain_clicked();

    void on_SortKupe_clicked();

    void on_ChangeInfo_clicked();

    void on_Delete_Item_clicked();

    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    AddInfo_W *window;
    ChangePasient *Change_W;
};


#endif // MAINWINDOW_H
