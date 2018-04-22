#ifndef SCREENTASK3_H
#define SCREENTASK3_H

#include <QFrame>
#include "core.h"
#include "screencontroller.h"

namespace Ui {
    class ScreenTask3;
}

class ScreenTask3 : public ScreenController {
    Q_OBJECT

public:
    explicit ScreenTask3(QWidget *parent = 0);
    ~ScreenTask3();
    bool validate(Core*, QString*);

private:
    void init();
    Ui::ScreenTask3 *ui;
    QString sequence;
};

#endif // SCREENTASK3_H
