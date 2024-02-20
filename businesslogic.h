#ifndef BUSINESSLOGIC_H
#define BUSINESSLOGIC_H

#include <QString>
#include "QMessageBox"

enum ValidationFlag {
    ERROR = 0,
    OK
};

QString getAllowedChars(QString base);
int validateNumber(QString &number, QString &base);
QString convertNumber(QString &number, QString &inSystem, QString &outSystem);

#endif // BUSINESSLOGIC_H
