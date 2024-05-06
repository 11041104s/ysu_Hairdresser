#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qtmaterialtoggle.h>
#include <qtmaterialflatbutton.h>
#include <qtmaterialflatbutton_internal.h>
#include <qtmaterialdrawer.h>
#include <QtMaterialAppBar.h>
#include <QString>
#include <QButtonGroup>
#include <QTableWidget>
#include <QIcon>
#include <QLabel>
#include <QHBoxLayout>

Mainwindow::Mainwindow(QWidget *parent)
    : QWidget(parent)
    , drawerOpen(false)
    , ui(new Ui::Widget)
    , table(new QTableWidget(this))
    , drawer(new QtMaterialDrawer(this))
    , bar(new QtMaterialAppBar(this))
    , bar_btn(new QtMaterialFlatButton(bar))
    , customerInfobtn(new QtMaterialFlatButton("顾客信息", drawer))
    , employeeInfobtn(new QtMaterialFlatButton("员工信息", drawer))
    , historyInfobtn(new QtMaterialFlatButton("历史", drawer))
    , globalInfobtn(new QtMaterialFlatButton("统计", drawer))

    , addBtn(new QtMaterialFlatButton("添加", drawer))
    , deleteBtn(new QtMaterialFlatButton("删除", drawer))
    , editBtn(new QtMaterialFlatButton("编辑", drawer))
    , exitBtn(new QtMaterialFlatButton("退出", drawer))
{
    ui->setupUi(this);
    this->setStyleSheet("background-color:#D2D2D2;");

    QIcon listIcon;
    listIcon.addFile(tr(":/image/list.png"));
    QIcon chartIcon(":/image/chart.png");
    QIcon dataIcon(":/image/data.png");
    QIcon deleteIcon(":/image/delete.png");
    QIcon infoIcon(":/image/info.png");
    QIcon newIcon(":/image/new.png");
    QIcon editIcon(":/image/edit.png");
    QIcon searchIcon(":/image/search.png");
    QIcon exitIcon(":/image/close.png");
    QColor black_def(0,0,0);

    QFont btn_font;
    btn_font.setFamily("微软雅黑");
    btn_font.setPixelSize(20);

    table->setGeometry(20, 55, 984, 565);
    table->setStyleSheet("background-color:#ffffff;");
    table->stackUnder(drawer);

    drawer->setDrawerWidth(150);
    drawer->setClickOutsideToClose(0);
    drawer->setAutoRaise(0);
    drawer->setStyleSheet("background-color:#f4f4f4;");

    customerInfobtn->applyPreset(Material::FlatPreset);
    employeeInfobtn->applyPreset(Material::FlatPreset);
    historyInfobtn->applyPreset(Material::FlatPreset);
    globalInfobtn->applyPreset(Material::FlatPreset);

    addBtn->applyPreset(Material::FlatPreset);
    deleteBtn->applyPreset(Material::FlatPreset);
    editBtn->applyPreset(Material::FlatPreset);
    exitBtn->applyPreset(Material::FlatPreset);
    //font
    customerInfobtn->setFont(btn_font);
    employeeInfobtn->setFont(btn_font);
    historyInfobtn->setFont(btn_font);
    globalInfobtn->setFont(btn_font);

    addBtn->setFont(btn_font);
    deleteBtn->setFont(btn_font);
    editBtn->setFont(btn_font);
    exitBtn->setFont(btn_font);
    //icon
    customerInfobtn->setIconPlacement(Material::LeftIcon);
    customerInfobtn->setIcon(dataIcon);
    customerInfobtn->setIconSize(QSize(30,30));

    employeeInfobtn->setIconPlacement(Material::LeftIcon);
    employeeInfobtn->setIcon(dataIcon);
    employeeInfobtn->setIconSize(QSize(30,30));

    historyInfobtn->setIconPlacement(Material::LeftIcon);
    historyInfobtn->setIcon(dataIcon);
    historyInfobtn->setIconSize(QSize(30,30));

    globalInfobtn->setIconPlacement(Material::LeftIcon);
    globalInfobtn->setIcon(chartIcon);
    globalInfobtn->setIconSize(QSize(30,30));
    //part2 icon
    addBtn->setIconPlacement(Material::LeftIcon);
    addBtn->setIcon(newIcon);
    addBtn->setIconSize(QSize(30,30));

    deleteBtn->setIconPlacement(Material::LeftIcon);
    deleteBtn->setIcon(deleteIcon);
    deleteBtn->setIconSize(QSize(30,30));

    editBtn->setIconPlacement(Material::LeftIcon);
    editBtn->setIcon(editIcon);
    editBtn->setIconSize(QSize(30,30));

    exitBtn->setIconPlacement(Material::LeftIcon);
    exitBtn->setIcon(exitIcon);
    exitBtn->setIconSize(QSize(30,30));
    //btn location
    //part1 btn
    customerInfobtn->setGeometry(10, 90, 130, 35);
    employeeInfobtn->setGeometry(10, 90 + customerInfobtn->height() + 10, 130, 35);
    historyInfobtn->setGeometry(10, 90 + customerInfobtn->height() + employeeInfobtn->height() + 20, 130, 35);
    globalInfobtn->setGeometry(10, 90 + customerInfobtn->height() + employeeInfobtn->height() +historyInfobtn->height()+ 30, 130, 35);

    exitBtn->setGeometry(10, 590, 130, 35);
    editBtn->setGeometry(10, 590-addBtn->height()-10, 130, 35);
    deleteBtn->setGeometry(10, 590-(addBtn->height())*2-20, 130, 35);
    addBtn->setGeometry(10, 590-(addBtn->height())*3-30, 130, 35);
    //设置按钮互斥
    // 连接按钮的点击信号到槽函数
    connect(customerInfobtn, &QtMaterialFlatButton::clicked, [=]() {
        // 设置按钮状态
        customerInfobtn->setForegroundColor(QColor(0,198,231));

        employeeInfobtn->setForegroundColor(black_def);
        historyInfobtn->setForegroundColor(black_def);
        globalInfobtn->setForegroundColor(black_def);

        employeeInfobtn->setChecked(false);
        historyInfobtn->setChecked(false);
        globalInfobtn->setChecked(false);
        // 在这里执行其他逻辑
    });
    connect(employeeInfobtn, &QtMaterialFlatButton::clicked, [=]() {
        // 设置按钮状态
        employeeInfobtn->setForegroundColor(QColor(0,198,231));

        customerInfobtn->setForegroundColor(black_def);
        historyInfobtn->setForegroundColor(black_def);
        globalInfobtn->setForegroundColor(black_def);

        customerInfobtn->setChecked(false);
        historyInfobtn->setChecked(false);
        globalInfobtn->setChecked(false);
        // 在这里执行其他逻辑
    });
    connect(historyInfobtn, &QtMaterialFlatButton::clicked, [=]() {
        // 设置按钮状态
        historyInfobtn->setForegroundColor(QColor(0,198,231));

        employeeInfobtn->setForegroundColor(black_def);
        customerInfobtn->setForegroundColor(black_def);
        globalInfobtn->setForegroundColor(black_def);

        employeeInfobtn->setChecked(false);
        customerInfobtn->setChecked(false);
        globalInfobtn->setChecked(false);
        // 在这里执行其他逻辑
    });
    connect(globalInfobtn, &QtMaterialFlatButton::clicked, [=]() {
        // 设置按钮状态
        globalInfobtn->setForegroundColor(QColor(0,198,231));

        employeeInfobtn->setForegroundColor(black_def);
        historyInfobtn->setForegroundColor(black_def);
        customerInfobtn->setForegroundColor(black_def);

        employeeInfobtn->setChecked(false);
        historyInfobtn->setChecked(false);
        customerInfobtn->setChecked(false);
        // 在这里执行其他逻辑
    });



    // 设置 AppBar
    bar->setGeometry(0, 0, 1024, 35);
    bar->setBackgroundColor(QColor(255, 255, 255));
    bar->setWindowFlag(Qt::WindowStaysOnTopHint, true);
    bar->raise();

    // 设置 AppBar 按钮
    bar_btn->setForegroundColor(QColor(100, 100, 100));
    bar_btn->setGeometry(10, 0, 35, 35);
    bar_btn->setText("");
    bar_btn->applyPreset(Material::FlatPreset);
    bar_btn->setIcon(listIcon);
    bar_btn->setIconSize(QSize(35, 35));
    bar_btn->setFlat(1);
    bar_btn->raise();
    connect(bar_btn, SIGNAL(clicked()), this, SLOT(openDrawer_od()));

    // 在构造函数中先隐藏按钮
    customerInfobtn->hide();
    employeeInfobtn->hide();
    historyInfobtn->hide();
    globalInfobtn->hide();

    addBtn->hide();
    deleteBtn->hide();
    editBtn->hide();
    exitBtn->hide();
}

void Mainwindow::openDrawer_od()
{
    if (!drawerOpen) { // 如果 drawer 是关闭的，则打开它
        drawer->openDrawer();
        // 将 bar 放置在 drawer 的下层
        drawer->stackUnder(bar);
        drawerOpen = true; // 更新 drawer 的状态为打开
        customerInfobtn->show();
        employeeInfobtn->show();
        historyInfobtn->show();
        globalInfobtn->show();

        addBtn->show();
        deleteBtn->show();
        editBtn->show();
        exitBtn->show();
        // 调整表格的位置和大小
        table->setGeometry(170, 55, 834, 565);
    } else { // 如果 drawer 是打开的，则关闭它
        drawer->closeDrawer();
        // 将 bar 放置在顶层
        bar->raise();
        drawerOpen = false; // 更新 drawer 的状态为关闭
        customerInfobtn->hide();
        employeeInfobtn->hide();
        historyInfobtn->hide();
        globalInfobtn->hide();

        addBtn->hide();
        deleteBtn->hide();
        editBtn->hide();
        exitBtn->hide();
        // 恢复表格的原始位置和大小
        table->setGeometry(20, 55, 984, 565);
    }
}

Mainwindow::~Mainwindow()
{
    delete ui;
}
