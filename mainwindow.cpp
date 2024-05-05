#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qtmaterialtoggle.h>
#include <qtmaterialflatbutton.h>
#include <qtmaterialflatbutton_internal.h>
#include <qtmaterialdrawer.h>
#include <QtMaterialAppBar.h>
#include <QString>
#include <QTableWidget>

Mainwindow::Mainwindow(QWidget *parent)
    : QWidget(parent)
    , drawerOpen(false)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    drawer = new QtMaterialDrawer(this);
    drawer->setDrawerWidth(150);
    drawer->setClickOutsideToClose(0);
    drawer->setAutoRaise(0);

    bar = new QtMaterialAppBar(this);
    bar->setGeometry(0, 0, 1024, 35);
    bar->setBackgroundColor(QColor(255, 255, 255));
    bar->setWindowFlag(Qt::WindowStaysOnTopHint, true);
    bar->raise(); // 将 bar 放置在顶层

    bar_btn = new QtMaterialFlatButton(bar);
    bar_btn->setForegroundColor(QColor(100, 100, 100));
    bar_btn->setGeometry(10, 0, 35, 35);
    bar_btn->setText("");
    bar_btn->applyPreset(Material::FlatPreset);
    connect(bar_btn, SIGNAL(clicked()), this, SLOT(openDrawer_od()));

    QIcon listIcon;
    listIcon.addFile(tr(":/image/list.png"));
    bar_btn->setIcon(listIcon);
    bar_btn->setIconSize(QSize(35, 35));
    bar_btn->setFlat(1);

    bar_btn->raise(); // 将 bar_btn 放置在顶层


    table = ui->tableWidget;
    // 设置表格控件的大小策略为 Expanding
    table->setGeometry(170,55,1004,565);
    //table->resize(QSize(1004,565));
}

void Mainwindow::openDrawer_od()
{
    if (!drawerOpen) { // 如果 drawer 是关闭的，则打开它
        drawer->openDrawer();
        // 将 bar 放置在 drawer 的下层
        drawer->stackUnder(bar);
        drawerOpen = true; // 更新 drawer 的状态为打开
        table->setGeometry(170,55,1004,565);

    } else { // 如果 drawer 是打开的，则关闭它
        drawer->closeDrawer();
        // 将 bar 放置在顶层
        bar->raise();
        drawerOpen = false; // 更新 drawer 的状态为关闭
        table->setGeometry(170,55,834,565);
    }
}

Mainwindow::~Mainwindow()
{
    delete ui;
}
