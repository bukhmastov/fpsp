#ifndef SCREENTASK5_H
#define SCREENTASK5_H

#include <QFrame>
#include "core.h"
#include "screencontroller.h"

namespace Ui {
    class ScreenTask5;
}

class ScreenTask5 : public ScreenController {
    Q_OBJECT

public:
    explicit ScreenTask5(QWidget *parent = 0);
    ~ScreenTask5();
    bool validate(Core*, QString*);

private:
    void init();
    Ui::ScreenTask5 *ui;
    int n;
    QString polynom1;
    QString polynom2;
};

#endif // SCREENTASK5_H
