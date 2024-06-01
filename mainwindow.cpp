#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "customer.h"
#include "consume.h"
#include "employee.h"
#include "hairdressing.h"
#include "editdialog.h"
#include "editdialog_consume.h"
#include "editdialog_employee.h"
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
#include <qtmaterialdialog.h>
#include <qtmaterialtextfield.h>
#include <QDialog>
#include <QCheckBox>
#include <QMessageBox>
#include <QRadioButton>

Mainwindow::Mainwindow(QWidget *parent)
    : QWidget(parent)
    , drawerOpen(false)
    , ui(new Ui::Widget)
    , AllTables (new tableList(this,true))
    , drawer(new QtMaterialDrawer(this))
    , bar(new QtMaterialAppBar(this))
    , bar_btn(new QtMaterialFlatButton(bar))
    , bar_btn2(new QtMaterialFlatButton(bar))
    , customerInfobtn(new QtMaterialFlatButton("顾客信息", drawer))
    , employeeInfobtn(new QtMaterialFlatButton("员工信息", drawer))
    , historyInfobtn(new QtMaterialFlatButton("消费历史", drawer))
    , globalInfobtn(new QtMaterialFlatButton("统计", drawer))
    , addBtn(new QtMaterialFlatButton("添加", drawer))
    , deleteBtn(new QtMaterialFlatButton("删除", drawer))
    , editBtn(new QtMaterialFlatButton("编辑", drawer))
    , exitBtn(new QtMaterialFlatButton("退出", drawer))
{
    ui->setupUi(this);
    this->setStyleSheet("background-color:#D2D2D2;");
    QString customer_path = "F:/QtProject/YSU_Hairdresser/Data/customer.json";
    QString consume_path = "F:/QtProject/YSU_Hairdresser/Data/consume.json";
    QString employee_path = "F:/QtProject/YSU_Hairdresser/Data/employee.json";

    AllTables->customer_info = (AllTables->tran_doc_array(AllTables->readJsonFile(customer_path)));
    QJsonDocument doc(AllTables->customer_info);
    QString jsonString = doc.toJson(QJsonDocument::Compact);
    QMessageBox::warning(this, "选择错误", QString("Customer Info: %1").arg(jsonString));

    AllTables->consume_info = (AllTables->tran_doc_array(AllTables->readJsonFile(consume_path)));
    AllTables->employee_info = (AllTables->tran_doc_array(AllTables->readJsonFile(employee_path)));
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
    btn_font.setFamily("汉仪文黑-85W");
    btn_font.setPixelSize(20);

    // table->setGeometry(20, 55, 984, 565);
    // table->setStyleSheet("background-color:#ffffff;");
    // table->stackUnder(drawer);

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
        //按钮的ui改变↑
        //load_customer_info(table,load_json(":/Data/customer.json"));
        // 其他逻辑
        AllTables->customerShow(AllTables->customer_info);
        tabletype = CustomerTable;
        AllTables->employeeHide();
        AllTables->consumeHide();

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
        tabletype = EmployeeTable;

        AllTables->employeeShow(AllTables->employee_info);
        AllTables->customerHide();
        AllTables->consumeHide();
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

        AllTables->consumeShow(AllTables->consume_info);
        tabletype = ConsumeTable;
        AllTables->employeeHide();
        AllTables->customerHide();
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

        EditDialog *customer_edit = nullptr;
        editdialog_consume *consume_edit = nullptr;
        editdialog_employee *employee_edit = nullptr;
        int selected = -1;
        switch (tabletype) {
        case CustomerTable:
            selected = AllTables->getSelected_customer();
            if (selected != -1) {
                customer_edit = new EditDialog(this);
                customer_edit->show();
            }
            break;
        case ConsumeTable:
            selected = AllTables->getSelected_consume();
            if (selected != -1) {
                consume_edit = new editdialog_consume(this);
                consume_edit->show();
            }
            break;
        case EmployeeTable:
            selected = AllTables->getSelected_employee();
            if (selected != -1) {
                employee_edit = new editdialog_employee(this);
                employee_edit->show();
            }
            break;
        default:
            break;
        }
    });

    connect(deleteBtn, &QtMaterialFlatButton::clicked, [=]() {
        // 取消其他按钮的选中状态
        editBtn->setChecked(false);
        addBtn->setChecked(false);
        exitBtn->setChecked(false);

        int selected_index = -1;
        switch (tabletype) {
        case CustomerTable:
            selected_index = AllTables->getSelected_customer();

            if (selected_index != -1) {
                AllTables->customer_info.removeAt(selected_index);
                AllTables->saveJsonArrayToFile(AllTables->customer_info, customer_path);
                AllTables->customerShow(AllTables->customer_info);


            } else {
                QMessageBox::warning(this, "错误", "未选中客户！");
            }
            break;
        case ConsumeTable:
            selected_index = AllTables->getSelected_consume();

            if (selected_index != -1) {
                AllTables->consume_info.removeAt(selected_index);
                AllTables->saveJsonArrayToFile(AllTables->consume_info, consume_path);
                AllTables->consumeShow(AllTables->consume_info);
            } else {
                QMessageBox::warning(this, "错误", "未选中客户！");
            }
            break;
        case EmployeeTable:
            selected_index = AllTables->getSelected_employee();

            if (selected_index != -1) {
                AllTables->employee_info.removeAt(selected_index);
                AllTables->saveJsonArrayToFile(AllTables->employee_info, employee_path);
                AllTables->employeeShow(AllTables->employee_info);
            } else {
                QMessageBox::warning(this, "错误", "未选中客户！");

            }
            break;
        default:
            break;
        }

    });
    connect(exitBtn, &QtMaterialFlatButton::clicked, [=]() {
        // 取消其他按钮的选中状态
        editBtn->setChecked(false);
        addBtn->setChecked(false);
        deleteBtn->setChecked(false);
        this->close();
    });

    connect(addBtn, &QtMaterialFlatButton::clicked, [=]() {
        // 取消其他按钮的选中状态
        editBtn->setChecked(false);
        deleteBtn->setChecked(false);
        exitBtn->setChecked(false);

        if(tabletype==CustomerTable){

        }
        QtMaterialDialog *addDialog = new QtMaterialDialog(this); // 将主窗口设置为对话框的父窗口
        addDialog->resize(QSize(1024,640));


        QVBoxLayout *layout = new QVBoxLayout(addDialog);
        layout->setAlignment(Qt::AlignCenter);

        // 创建并添加第一个输入框及其标签
        QWidget *widget1 = new QWidget(addDialog);
        QHBoxLayout *inputLayout1 = new QHBoxLayout(widget1);
        inputLayout1->setAlignment(Qt::AlignCenter);
        QLabel *label1 = new QLabel("卡号:", widget1);
        inputLayout1->addWidget(label1);
        QtMaterialTextField *textField1 = new QtMaterialTextField(widget1);
        textField1->setLabelColor(Qt::white);
        textField1->setPlaceholderText("请输入卡号");
        inputLayout1->addWidget(textField1);
        layout->addWidget(widget1);

        QWidget *widget2 = new QWidget(addDialog);
        QHBoxLayout *inputLayout2 = new QHBoxLayout(widget2);
        inputLayout2->setAlignment(Qt::AlignCenter);
        QLabel *label2 = new QLabel("姓名:", widget2);
        inputLayout2->addWidget(label2);
        QtMaterialTextField *textField2 = new QtMaterialTextField(widget2);
        textField2->setPlaceholderText("请输入姓名");
        inputLayout2->addWidget(textField2);
        layout->addWidget(widget2);

        QWidget *radioWidget = new QWidget(addDialog);
        QHBoxLayout *radioLayout = new QHBoxLayout(radioWidget);
        radioLayout->setAlignment(Qt::AlignCenter);

        QRadioButton *maleRadio = new QRadioButton("男", radioWidget);
        QRadioButton *femaleRadio = new QRadioButton("女", radioWidget);

        QButtonGroup *genderGroup = new QButtonGroup(radioWidget);
        genderGroup->addButton(maleRadio);
        genderGroup->addButton(femaleRadio);

        radioLayout->addWidget(maleRadio);
        radioLayout->addWidget(femaleRadio);
        layout->addWidget(radioWidget);

        QWidget *widget4 = new QWidget(addDialog);
        QHBoxLayout *inputLayout4 = new QHBoxLayout(widget4);
        inputLayout4->setAlignment(Qt::AlignCenter);
        QLabel *label4 = new QLabel("手机号:", widget4);
        inputLayout4->addWidget(label4);
        QtMaterialTextField *textField4 = new QtMaterialTextField(widget4);
        textField4->setPlaceholderText("请输入手机号");
        inputLayout4->addWidget(textField4);
        layout->addWidget(widget4);

        QWidget *checkboxWidget = nullptr;
        QHBoxLayout *checkboxLayout = nullptr;
        QCheckBox *checkbox1 = nullptr, *checkbox2 = nullptr, *checkbox3 = nullptr, *checkbox4 = nullptr, *checkbox5 = nullptr;


        //复选框

        // 创建水平布局用于包含按钮
        QHBoxLayout *buttonLayout = new QHBoxLayout();
        layout->addLayout(buttonLayout);

        QPushButton *submitButton = new QPushButton("确认", addDialog);
        buttonLayout->addWidget(submitButton);
        connect(submitButton, &QPushButton::clicked, [=]() {
            QString text1 = textField1->text();
            QString text2 = textField2->text();
            QString text4 = textField4->text();
            bool gender = maleRadio->isChecked(); // true for male, false for female
            switch (tabletype) {
            case CustomerTable: {

                break;
            }
            case ConsumeTable: {
                bool option1 = checkbox1->isChecked();
                bool option2 = checkbox2->isChecked();
                bool option3 = checkbox3->isChecked();
                bool option4 = checkbox4->isChecked();
                bool option5 = checkbox5->isChecked();
                if (!option1 && !option2 && !option3 && !option4 && !option5) {
                    QMessageBox::warning(addDialog, "选择错误", "必须至少选择一个选项！");
                    return;
                }
                qDebug() << "选项1:" << option1;
                qDebug() << "选项2:" << option2;
                qDebug() << "选项3:" << option3;
                qDebug() << "选项4:" << option4;
                qDebug() << "选项5:" << option5;
                break;
            }
            case EmployeeTable: {
                bool option1 = checkbox1->isChecked();
                bool option2 = checkbox2->isChecked();
                bool option3 = checkbox3->isChecked();
                bool option4 = checkbox4->isChecked();
                bool option5 = checkbox5->isChecked();
                if (!option1 && !option2 && !option3 && !option4 && !option5) {
                    QMessageBox::warning(addDialog, "选择错误", "必须至少选择一个选项！");
                    return;
                }
                qDebug() << "选项1:" << option1;
                qDebug() << "选项2:" << option2;
                qDebug() << "选项3:" << option3;
                qDebug() << "选项4:" << option4;
                qDebug() << "选项5:" << option5;
                break;
            }
            default:
                break;
            }


            if (!maleRadio->isChecked() && !femaleRadio->isChecked()) {
                QMessageBox::warning(addDialog, "输入错误", "必须选择性别");
                return;
            }

            if (text1.isEmpty() || text2.isEmpty() || text4.isEmpty()) {
                QMessageBox::warning(addDialog, "输入错误", "所有文本框必须填写！");
                return;
            }



            // 输出调试信息
            qDebug() << "文本框1内容:" << text1;
            qDebug() << "文本框2内容:" << text2;
            qDebug() << "文本框4内容:" << text4;
            qDebug() << "性别:" << (gender ? "男" : "女");


            switch (tabletype) {
            case CustomerTable: {
                Customer customer_temp(text1, text2, gender, text4);
                QJsonObject custome_json = customer_temp.toJson();
                AllTables->customer_info.append(custome_json);
                QJsonDocument doc(AllTables->customer_info);
                QString jsonString = doc.toJson(QJsonDocument::Compact);
                QMessageBox::warning(this, "选择错误", QString("Customer Info: %1").arg(jsonString));
                AllTables->saveJsonArrayToFile(AllTables->customer_info, customer_path);
                AllTables->customerShow(AllTables->customer_info);

                break;
            }
            case ConsumeTable: {
                QMap<QString, double> Consume_Proj;
                if (checkbox1->isChecked()) {
                    Consume_Proj.insert("洗剪吹", 50.0);
                }
                if (checkbox2->isChecked()) {
                    Consume_Proj.insert("染发", 80.0);
                }
                if (checkbox3->isChecked()) {
                    Consume_Proj.insert("剪发", 30.0);
                }
                if (checkbox4->isChecked()) {
                    Consume_Proj.insert("烫发", 100.0);
                }
                if (checkbox5->isChecked()) {
                    Consume_Proj.insert("护发", 60.0);
                }
                Consume consume_temp(text1, text2, gender, text4, Consume_Proj);
                QJsonObject  consume_json =consume_temp.toJson();
                AllTables->consume_info.append(consume_json);
                QJsonDocument doc(AllTables->consume_info);
                QString jsonString = doc.toJson(QJsonDocument::Compact);
                QMessageBox::warning(this, "选择错误", QString("Consume Info: %1").arg(jsonString));
                AllTables->saveJsonArrayToFile(AllTables->consume_info, consume_path);
                AllTables->consumeShow(AllTables->consume_info);
                // 处理 ConsumeTable 情况
                break;
            }
            case EmployeeTable: {
                QMap<QString, double> Employee_Proj;
                if (checkbox1->isChecked()) {
                    Employee_Proj.insert("洗剪吹", 50.0);
                }
                if (checkbox2->isChecked()) {
                    Employee_Proj.insert("染发", 80.0);
                }
                if (checkbox3->isChecked()) {
                    Employee_Proj.insert("剪发", 30.0);
                }
                if (checkbox4->isChecked()) {
                    Employee_Proj.insert("烫发", 100.0);
                }
                if (checkbox5->isChecked()) {
                    Employee_Proj.insert("护发", 60.0);
                }
                Employee employee_temp(text1, text2, gender, text4, Employee_Proj);
                QJsonObject  employee_json =employee_temp.toJson();
                AllTables->employee_info.append(employee_json);
                QJsonDocument doc(AllTables->employee_info);
                QString jsonString = doc.toJson(QJsonDocument::Compact);
                QMessageBox::warning(this, "选择错误", QString("employee Info: %1").arg(jsonString));
                AllTables->saveJsonArrayToFile(AllTables->employee_info, employee_path);
                AllTables->employeeShow(AllTables->employee_info);
                // 处理 EmployeeTable 情况
                break;
            }
            default:
                break;
            }

            addDialog->deleteLater();
        });


        QPushButton *cancelButton = new QPushButton("取消", addDialog);
        buttonLayout->addWidget(cancelButton);


        addDialog->setWindowLayout(layout);
        addDialog->show();
        addDialog->showDialog();
        connect(cancelButton, &QPushButton::clicked, [=]() {
            qDebug() << "用户取消了输入";
            addDialog->deleteLater();
        });
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
        switch (tabletype) {
        case CustomerTable:
            // 处理顾客表
            AllTables->customerShow(AllTables->customer_info); // 先显示表格
            AllTables->customerChange_open(); // 更改表格大小
            break;
        case ConsumeTable:
            // 处理消费表
            AllTables->consumeShow(AllTables->consume_info); // 先显示表格
            AllTables->consumeChange_open(); // 更改表格大小
            break;
        case EmployeeTable:
            // 处理雇员表
            AllTables->employeeShow(AllTables->employee_info); // 先显示表格
            AllTables->employeeChange_open(); // 更改表格大小
            break;
        }
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
        switch (tabletype) {
        case CustomerTable:
            // 处理顾客表
            AllTables->customerChange_close(); // 更改表格大小

            break;
        case ConsumeTable:
            // 处理消费表
            AllTables->consumeChange_close(); // 更改表格大小

            break;
        case EmployeeTable:
            // 处理雇员表
            AllTables->employeeChange_close(); // 更改表格大小

            break;
        }
        // 恢复表格的原始位置和大小
        //
        //table->setGeometry(20, 55, 984, 565);
    }
}



Mainwindow::~Mainwindow()
{
    delete ui;
}
