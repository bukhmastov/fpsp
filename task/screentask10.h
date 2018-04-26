#ifndef SCREENTASK10_H
#define SCREENTASK10_H

#include <QFrame>
#include "core.h"
#include "screencontroller.h"

namespace Ui {
    class ScreenTask10;
}

class ScreenTask10 : public ScreenController {
    Q_OBJECT

public:
    explicit ScreenTask10(QWidget *parent = 0);
    ~ScreenTask10();
    bool validate(Core*, QString*);

private:
    void init();
    Ui::ScreenTask10 *ui;
    QString h;
    int c0;
    int c1;
    QString f;
    int a0;
    int a1;
    int cA0;
    int cA1;
};

#endif // SCREENTASK10_H
