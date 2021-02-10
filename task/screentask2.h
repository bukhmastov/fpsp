#ifndef SCREENTASK2_H
#define SCREENTASK2_H

#include <QFrame>
#include "util/core.h"
#include "util/screencontroller.h"

namespace Ui {
    class ScreenTask2;
}

class ScreenTask2 : public ScreenController {
    Q_OBJECT

public:
    explicit ScreenTask2(QWidget *parent = 0);
    ~ScreenTask2();
    ScreenController* init(int, bool);
    bool validate(Core*, QString*);

protected:
    void init();

private:
    void onRelayClicked(int h);
    Ui::ScreenTask2 *ui;
    int s;
    /*int x0;
    int x1;
    int x2;
    int x3;
    int x4;
    int x5;
    int x6;*/
    QString pi;
    QString hx;
    int a;
    //QString polynomC;
    bool relayH1 = false;
    bool relayH2 = false;
    bool relayH3 = false;
    bool relayH4 = false;
    bool relayH5 = false;
    QString mSeq;
};

#endif // SCREENTASK2_H
