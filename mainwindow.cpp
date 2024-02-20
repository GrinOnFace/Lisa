#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "style.h"
#include "businesslogic.h"

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
        setBtnEnabled(FALSE, ui->convertButton);
        ui->labelRes->clear();
    } else {
        setBtnEnabled(TRUE, ui->convertButton);
    }
}


void MainWindow::on_textEdit_textChanged() {
    QString text = getTextEdit();

    handleZeroInput(text);
    handleLengthError(text);
    updateUIBasedOnInput(text);
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
