#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "style.h"

#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

QString MainWindow::getTextEdit () {
    return ui->textEdit->toPlainText();
}

QString MainWindow::getComboBoxIn () {
    return ui->comboBoxIn->currentText();
}

QString MainWindow::getComboBoxOut () {
    return ui->comboBoxOut->currentText();
}

void MainWindow::setText(QString &result) {
    ui->labelRes->setText(result);
}

QString MainWindow::getAllowedChars(QString base) {
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

    return allowedChars;
}

int MainWindow::validateNumber(QString &number, QString &base) {
    int flag = OK;
    QString allowedChars = getAllowedChars(base);

    for (int i = 0; i < number.size(); ++i) {
        if (!allowedChars.contains(number.at(i))) {
            flag = ERROR;
        }
    }
    return flag;
}

void MainWindow::handleZeroInput(QString &text) {
    if (text.length() == 1 && text == "0") {
        ui->textEdit->clear();
    }
}

void MainWindow::handleLengthError(QString &text) {
    if (text.length() == LENGTH) {
        QMessageBox::critical(this, "Error", "Length error");
        ui->textEdit->clear();
    }
}

void MainWindow::updateUIBasedOnInput(QString &text) {
    if (text.isEmpty()) {
        setBntEnabled(FALSE, ui->convertButton);
        ui->labelRes->clear();
    } else {
        setBntEnabled(TRUE, ui->convertButton);
    }
}


void MainWindow::on_textEdit_textChanged() {
    QString text = getTextEdit();

    handleZeroInput(text);
    handleLengthError(text);
    updateUIBasedOnInput(text);
}

QString MainWindow::convertNumber(QString &number, QString &inSystem, QString &outSystem) {
    bool conversionSuccess = false;
    long long int decimalNumber = number.toLongLong(&conversionSuccess, inSystem.toInt());

    if (conversionSuccess) {
        return QString::number(decimalNumber, outSystem.toInt());
    } else {
        QMessageBox::critical(this, "Error", "Convert error");
        return QString();
    }
}

void MainWindow::on_convertButton_clicked() {
    QString number = getTextEdit();
    QString comboBoxOne = getComboBoxIn();
    QString comboBoxTwo = getComboBoxOut();

    int validate = validateNumber(number, comboBoxOne);
    if (validate == ERROR) {
        QMessageBox::critical(this, "Error", "Validation error");
    }
    else {
        QString result = convertNumber(number, comboBoxOne, comboBoxTwo);
        setText(result);
    }
}




