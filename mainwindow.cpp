#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "customer.h"
#include "consume.h"
#include "employee.h"
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
#include <QFile>				// 用于打开文件
#include <QJsonParseError>		// 返回错误信息
#include <QJsonArray>			// Json数据对象
#include <QJsonDocument>		// Json文档对象
#include <QJsonObject>			// 普通Json对象

Mainwindow::Mainwindow(QWidget *parent)
    : QWidget(parent)
    , drawerOpen(false)
    , ui(new Ui::Widget)
    , table(new QTableWidget(this))
    , drawer(new QtMaterialDrawer(this))
    , bar(new QtMaterialAppBar(this))
    , bar_btn(new QtMaterialFlatButton(bar))
    , bar_btn2(new QtMaterialFlatButton(bar))
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
    QIcon historyIcon(":/image/history.png");
    QIcon aboutIcon(":/image/about.png");
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
    historyInfobtn->setIcon(historyIcon);
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
    //part2
    exitBtn->setGeometry(10, 590, 130, 35);
    editBtn->setGeometry(10, 590-addBtn->height()-10, 130, 35);
    deleteBtn->setGeometry(10, 590-(addBtn->height())*2-20, 130, 35);
    addBtn->setGeometry(10, 590-(addBtn->height())*3-30, 130, 35);

    //part2 btn default unaccessable
    editBtn->setCheckable(0);
    editBtn->setForegroundColor(QColor(211,211,211));
    deleteBtn->setCheckable(0);
    deleteBtn->setForegroundColor(QColor(211,211,211));
    addBtn->setCheckable(0);
    addBtn->setForegroundColor(QColor(211,211,211));
    exitBtn->setCheckable(0);
    exitBtn->setForegroundColor(QColor(211,211,211));

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

        editBtn->setChecked(false);
        deleteBtn->setChecked(false);
        addBtn->setChecked(false);
        exitBtn->setChecked(false);

        editBtn->setCheckable(1);
        editBtn->setForegroundColor(black_def);
        deleteBtn->setCheckable(1);
        deleteBtn->setForegroundColor(black_def);
        addBtn->setCheckable(1);
        addBtn->setForegroundColor(black_def);
        exitBtn->setCheckable(1);
        exitBtn->setForegroundColor(black_def);
        //load_customer_info(table,load_json(":/Data/customer.json"));
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

        editBtn->setChecked(false);
        deleteBtn->setChecked(false);
        addBtn->setChecked(false);
        exitBtn->setChecked(false);

        editBtn->setCheckable(1);
        editBtn->setForegroundColor(black_def);
        deleteBtn->setCheckable(1);
        deleteBtn->setForegroundColor(black_def);
        addBtn->setCheckable(1);
        addBtn->setForegroundColor(black_def);
        exitBtn->setCheckable(1);
        exitBtn->setForegroundColor(black_def);
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

        editBtn->setChecked(false);
        deleteBtn->setChecked(false);
        addBtn->setChecked(false);
        exitBtn->setChecked(false);

        editBtn->setCheckable(1);
        editBtn->setForegroundColor(black_def);
        deleteBtn->setCheckable(1);
        deleteBtn->setForegroundColor(black_def);
        addBtn->setCheckable(1);
        addBtn->setForegroundColor(black_def);
        exitBtn->setCheckable(1);
        exitBtn->setForegroundColor(black_def);
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

        editBtn->setChecked(false);
        deleteBtn->setChecked(false);
        addBtn->setChecked(false);
        exitBtn->setChecked(false);

        editBtn->setCheckable(0);
        editBtn->setForegroundColor(QColor(211,211,211));
        deleteBtn->setCheckable(0);
        deleteBtn->setForegroundColor(QColor(211,211,211));
        addBtn->setCheckable(0);
        addBtn->setForegroundColor(QColor(211,211,211));
        exitBtn->setCheckable(0);
        exitBtn->setForegroundColor(QColor(211,211,211));
        // 在这里执行其他逻辑
    });

    connect(editBtn, &QtMaterialFlatButton::clicked, [=]() {
        // 取消其他按钮的选中状态
        deleteBtn->setChecked(false);
        addBtn->setChecked(false);
        exitBtn->setChecked(false);
    });

    connect(deleteBtn, &QtMaterialFlatButton::clicked, [=]() {
        // 取消其他按钮的选中状态
        editBtn->setChecked(false);
        addBtn->setChecked(false);
        exitBtn->setChecked(false);
    });

    connect(addBtn, &QtMaterialFlatButton::clicked, [=]() {
        // 取消其他按钮的选中状态
        editBtn->setChecked(false);
        deleteBtn->setChecked(false);
        exitBtn->setChecked(false);
    });

    connect(exitBtn, &QtMaterialFlatButton::clicked, [=]() {
        // 取消其他按钮的选中状态
        editBtn->setChecked(false);
        deleteBtn->setChecked(false);
        addBtn->setChecked(false);
    });


    // 设置 AppBar
    bar->setGeometry(0, 0, 1024, 35);
    bar->setBackgroundColor(QColor(255, 255, 255));
    bar->setWindowFlag(Qt::WindowStaysOnTopHint, true);
    bar->raise();

    // 设置 AppBar 按钮
    bar_btn->setForegroundColor(QColor(100, 100, 100));
    bar_btn->setGeometry(10, 0,90, 35);
    bar_btn->setText("菜单");
    bar_btn->setIconPlacement(Material::LeftIcon);
    bar_btn->applyPreset(Material::FlatPreset);
    bar_btn->setIcon(listIcon);
    bar_btn->setIconSize(QSize(35, 35));
    bar_btn->setFont(btn_font);
    bar_btn->setFlat(1);
    bar_btn->raise();

    bar_btn2->setForegroundColor(QColor(100, 100, 100));
    bar_btn2->setGeometry(110, 0,90, 35);
    bar_btn2->setText("关于");
    bar_btn2->setIconPlacement(Material::LeftIcon);
    bar_btn2->applyPreset(Material::FlatPreset);
    bar_btn2->setIcon(aboutIcon);
    bar_btn2->setIconSize(QSize(35, 35));
    bar_btn2->setFont(btn_font);
    bar_btn2->setFlat(1);
    bar_btn2->raise();
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



void Mainwindow::load_customer_info(QTableWidget *tablewidget,QJsonDocument root_doc){
    QJsonArray jsonArray = root_doc.array();

}




QJsonArray addinto_json(QJsonArray jsonarray, const Customer& customer) {
    jsonarray.append(customer.toJson());
    return jsonarray;
}
QJsonArray addinto_json(QJsonArray jsonarray,const Consume& consume){
    jsonarray.append(consume.toJson());
    return jsonarray;
}
QJsonArray addinto_json(QJsonArray jsonarray,const Employee& employee){
    jsonarray.append(employee.toJson());
    return jsonarray;
}
QJsonDocument readJsonFile(const QString& filePath) {
    QFile file(filePath);
    if(file.exists()) {
        if (!file.open(QIODevice::ReadOnly)) {
            // 文件打开失败，返回空的 QJsonDocument 对象
            return QJsonDocument();
        }

        QJsonParseError parseError;
        QJsonDocument jsonDoc = QJsonDocument::fromJson(file.readAll(), &parseError); // 解析 JSON 数据
        if (parseError.error != QJsonParseError::NoError) {
            // JSON 解析错误，返回空的 QJsonDocument 对象
            return QJsonDocument();
        }

        // 成功读取并解析 JSON 文件，返回 QJsonDocument 对象
        return jsonDoc;
    }
    else {
        // 文件不存在，创建一个空的文件
        if (!file.open(QIODevice::WriteOnly)) {
            // 创建文件失败，返回空的 QJsonDocument 对象
            return QJsonDocument();
        }

        // 写入空的 JSON 格式数据
        file.write("{}");
        file.close();

        // 返回一个空的 QJsonDocument 对象
        return QJsonDocument();
    }
}

Mainwindow::~Mainwindow()
{
    delete ui;
}
