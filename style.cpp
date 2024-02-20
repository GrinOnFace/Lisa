#include "style.h"

void setBntEnabled(int status, QPushButton *btn) {
    btn->setEnabled(status);
    if (status) {
        btn->setStyleSheet("QPushButton{color:black; border:1px solid black; border-radius:10px;}");
    } else {
        btn->setStyleSheet("QPushButton{color:red; border:1px solid black; border-radius:10px;}");
    }
}

