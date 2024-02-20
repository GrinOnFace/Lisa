#ifndef STYLE_H
#define STYLE_H
#include <QPushButton>

enum EnabledFlag {
    FALSE = 0,
    TRUE
};

void setBtnEnabled(int status, QPushButton *btn);

#endif // STYLE_H
