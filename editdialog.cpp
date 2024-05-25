#include "editdialog.h"
#include "ui_editdialog.h"

EditDialog::EditDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EditDialog)
{
    ui->setupUi(this);
}

EditDialog::~EditDialog()
{
    delete ui;
}

void EditDialog::on_buttonBox_clicked(QAbstractButton *button)
{

}


void EditDialog::on_pushButton_clicked()
{
    Mainwindow * p = static_cast<Mainwindow*>(parentWidget());

    // 获取输入框内容
    QString card_num = ui->card->text();
    QString name = ui->name->text();
    bool genderMale = ui->radioButton->isChecked();  // Assuming radioButtonMale for male gender
    bool genderFemale = ui->radioButton_2->isChecked();  // Assuming radioButtonFemale for female gender
    QString phone_num = ui->phonenum->text();

    // 检查输入框是否为空
    if (card_num.isEmpty() || name.isEmpty() || phone_num.isEmpty()) {
        QMessageBox::warning(this, "输入错误", "所有文本框必须填写！");
        return;
    }

    // 确保选择一个性别
    if (!genderMale && !genderFemale) {
        QMessageBox::warning(this, "选择错误", "必须选择一个性别！");
        return;
    }

    bool gender = genderMale;
    Customer customer_temp(card_num, name, !gender, phone_num);
    int selected_index = p->AllTables->getSelected_customer();

    if (selected_index != -1) {
        p->AllTables->customer_info.removeAt(selected_index);
        p->AllTables->customer_info.insert(selected_index, customer_temp.toJson());
        p->AllTables->saveJsonArrayToFile(p->AllTables->customer_info, "F:/QtProject/YSU_Hairdresser/Data/customer.json");
        p->AllTables->customerShow(p->AllTables->customer_info);

        this->close();
    } else {
        QMessageBox::warning(this, "错误", "未选中客户！");
        this->close();
    }
}


void EditDialog::on_pushButton_2_clicked()
{
    this->close();
}

