#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include "addinfo_w.h"
#include "changepasient.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
void AddItem( QListWidget* lstWgt,Pasient NewPasient);
private slots:

    void on_AddPasient_clicked();
    void on_DelPasient_clicked();
    void SelectItemEvent(QListWidgetItem* item);
    void update();
    void on_SortPalat_clicked();
    void onChangeBClicked();
    void on_SearchButton_clicked();
    void ChangeElement(int Index);
    void AddAll_Items();

private:
    Ui::MainWindow *ui;
    AddInfo_W *window;
    ChangePasient *Change_W;
};


#endif // MAINWINDOW_H
