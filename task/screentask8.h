#ifndef SCREENTASK8_H
#define SCREENTASK8_H

#include <QFrame>
#include "core.h"
#include "screencontroller.h"

namespace Ui {
    class ScreenTask8;
}

class ScreenTask8 : public ScreenController {
    Q_OBJECT

public:
    explicit ScreenTask8(QWidget *parent = 0);
    ~ScreenTask8();
    bool validate(Core*, QString*);

private:
    void init();
    Ui::ScreenTask8 *ui;
    QString h1;
    QString h2;
    QString h3;
    QString h123;
};

#endif // SCREENTASK8_H
