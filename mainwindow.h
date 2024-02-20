#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

enum ValidationFlag {
    ERROR = 0,
    OK
};

#define LENGTH 10

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
    void on_convertButton_clicked();
    void on_textEdit_textChanged();

private:
    Ui::MainWindow *ui;

    QString getComboBoxIn();
    QString getComboBoxOut();
    QString getTextEdit();
    void setText(QString &result);

    QString getAllowedChars(QString base);

    void handleZeroInput(QString &text);
    void handleLengthError(QString &text);
    void updateUIBasedOnInput(QString &text);

    int validateNumber(QString &number, QString &base);
    QString convertNumber(QString &number, QString &inSystem, QString &outSystem);

};
#endif // MAINWINDOW_H
