#ifndef SCREENTASK8_H
#define SCREENTASK8_H

#include <QFrame>
#include "util/core.h"
#include "util/screencontroller.h"

namespace Ui {
    class ScreenTask8;
}

class ScreenTask8 : public ScreenController {
    Q_OBJECT

public:
    explicit ScreenTask8(QWidget *parent = 0);
    ~ScreenTask8();
    ScreenController* init(int, bool);
    bool validate(Core*, QString*);

protected:
    void init();

private:
    Ui::ScreenTask8 *ui;
    QString h1;
    QString h2;
    QString h3;
    QString h123;
    QString mSeqXOR;
};

#endif // SCREENTASK8_H
