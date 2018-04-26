#ifndef SCREENTASK10_H
#define SCREENTASK10_H

#include <QFrame>
#include "util/core.h"
#include "util/screencontroller.h"

namespace Ui {
    class ScreenTask10;
}

class ScreenTask10 : public ScreenController {
    Q_OBJECT

public:
    explicit ScreenTask10(QWidget *parent = 0);
    ~ScreenTask10();
    ScreenController* init(int, bool);
    bool validate(Core*, QString*);

protected:
    void init();

private:
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
