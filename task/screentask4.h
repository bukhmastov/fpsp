#ifndef SCREENTASK4_H
#define SCREENTASK4_H

#include <QFrame>
#include "core.h"
#include "screencontroller.h"

namespace Ui {
    class ScreenTask4;
}

class ScreenTask4 : public ScreenController {
    Q_OBJECT

public:
    explicit ScreenTask4(QWidget *parent = 0);
    ~ScreenTask4();
    bool validate(Core*, QString*);

private:
    void init();
    Ui::ScreenTask4 *ui;
    QString h5;
    QString h8;
};

#endif // SCREENTASK4_H
