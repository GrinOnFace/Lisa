#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::get_textEdit () {
    return ui->textEdit->toPlainText();
}

QString MainWindow::get_comboBox_In () {
    return ui->comboBox_In->currentText();
}

QString MainWindow::get_comboBox_Out () {
    return ui->comboBox_Out->currentText();
}

void MainWindow::set_text(QString &result) {
    ui->label_Res->setText(result);
}

int MainWindow::validateNumber(QString &number, QString &base){
    int flag = OK;
    QString allowedChars;
    if (base == "2") {
        allowedChars = "01";
    } else if (base == "8") {
        allowedChars = "01234567";
    } else if (base == "10") {
        allowedChars = "0123456789";
    } else {
        allowedChars = "0123456789ABCDEFabcdef";
    }

    for (int i = 0; i < number.size(); ++i) {
        if (!allowedChars.contains(number.at(i))) {
            flag = ERROR;
        }
    }
    return flag;
}

void MainWindow::on_textEdit_textChanged()
{
    QString text = get_textEdit();
    if (text.length() == 1 && text == "0") {
        ui->textEdit->clear();
    }
}

QString MainWindow::convertNumber(QString &number, QString &inSystem, QString &outSystem) {
    try {
        long long int decimalNumber = number.toLongLong(nullptr, inSystem.toInt());
        return QString::number(decimalNumber, outSystem.toInt());
    } catch (std::exception& e) {
        qDebug() << "Ошибка при преобразовании числа в 10 СС: " << e.what();
        return QString();
    }
}

void MainWindow::on_pushButton_clicked()
{
    QString number = get_textEdit();
    QString comboBoxOne = get_comboBox_In();
    QString comboBoxTwo = get_comboBox_Out();
    int validate = validateNumber(number, comboBoxOne);
    if (validate == ERROR){
        QMessageBox::critical(this, "Error", "Validation error");
    }
    else{
        QString result = convertNumber(number, comboBoxOne, comboBoxTwo);
        set_text(result);
    }
}




