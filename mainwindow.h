#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#define OK 1
#define ERROR 0

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_textEdit_textChanged();

private:
    Ui::MainWindow *ui;

    QString get_comboBox_In();
    QString get_comboBox_Out();
    QString get_textEdit();
    void set_text(QString &result);

    int validateNumber(QString &number, QString &base);
    QString convertNumber(QString &number, QString &inSystem, QString &outSystem);

};
#endif // MAINWINDOW_H
