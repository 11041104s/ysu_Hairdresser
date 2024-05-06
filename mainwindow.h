#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <qtmaterialtoggle.h>
#include <qtmaterialflatbutton.h>
#include <qtmaterialflatbutton_internal.h>
#include <qtmaterialdrawer.h>
#include <QtMaterialAppBar.h>
#include <QTableWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Mainwindow : public QWidget
{
    Q_OBJECT

public:
    Mainwindow(QWidget *parent = nullptr);
    ~Mainwindow();

public slots:
    void openDrawer_od();

private:
    QTableWidget *table;
    QtMaterialDrawer *drawer;
    QtMaterialAppBar *bar;
    QtMaterialFlatButton *bar_btn;

    QtMaterialFlatButton *customerInfobtn;
    QtMaterialFlatButton *employeeInfobtn;
    QtMaterialFlatButton *historyInfobtn;
    QtMaterialFlatButton *globalInfobtn;
    QtMaterialFlatButton *addBtn;
    QtMaterialFlatButton *deleteBtn;
    QtMaterialFlatButton *editBtn;
    QtMaterialFlatButton *exitBtn;

    bool drawerOpen; // 添加 drawer 的状态变量
    Ui::Widget *ui;
};

#endif // MAINWINDOW_H
