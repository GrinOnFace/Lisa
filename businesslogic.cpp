#include "businesslogic.h"

QString convertNumber(QString &number, QString &inSystem, QString &outSystem) {
    bool conversionSuccess = false;
    long long int decimalNumber = number.toLongLong(&conversionSuccess, inSystem.toInt());

    if (conversionSuccess) {
        return QString::number(decimalNumber, outSystem.toInt());
    } else {
        QMessageBox::critical(nullptr, "Error", "Convert error");
        return QString();
    }
}

QString getAllowedChars(QString base) {
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

int validateNumber(QString &number, QString &base) {
    int flag = OK;
    QString allowedChars = getAllowedChars(base);

    for (int i = 0; i < number.size(); ++i) {
        if (!allowedChars.contains(number.at(i))) {
            flag = ERROR;
        }
    }
    return flag;
}
