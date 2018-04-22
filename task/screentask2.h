#ifndef SCREENTASK2_H
#define SCREENTASK2_H

#include <QFrame>
#include "core.h"
#include "screencontroller.h"

namespace Ui {
    class ScreenTask2;
}

class ScreenTask2 : public ScreenController {
    Q_OBJECT

public:
    explicit ScreenTask2(QWidget *parent = 0);
    ~ScreenTask2();
    bool validate(Core*, QString*);

private:
    void init();
    void onRelayClicked(int h);
    Ui::ScreenTask2 *ui;
    int s;
    int x0;
    int x1;
    int x2;
    int x3;
    int x4;
    int x5;
    int x6;
    int a;
    QString polynomC;
    bool relayH1 = false;
    bool relayH2 = false;
    bool relayH3 = false;
    bool relayH4 = false;
    bool relayH5 = false;
};

#endif // SCREENTASK2_H
