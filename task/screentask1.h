#ifndef SCREENTASK1A_H
#define SCREENTASK1A_H

#include <QFrame>
#include "core.h"
#include "screencontroller.h"

namespace Ui {
    class ScreenTask1;
}

class ScreenTask1 : public ScreenController {
    Q_OBJECT

public:
    explicit ScreenTask1(QWidget *parent = 0);
    ~ScreenTask1();
    bool validate(Core*, QString*);

private slots:
    void onRelayClicked(int);

private:
    void init();
    Ui::ScreenTask1 *ui;
    int x1;
    int x2;
    int x3;
    int x0;
    int c2;
    int c1;
    int c0;
    bool relayH1 = false;
    bool relayH2 = false;
};

#endif // SCREENTASK1A_H
