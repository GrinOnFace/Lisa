#ifndef STYLE_H
#define STYLE_H
#include <QPushButton>

enum EnabledFlag {
    FALSE = 0,
    TRUE
};

void setBntEnabled(int status, QPushButton *btn);

#endif // STYLE_H
