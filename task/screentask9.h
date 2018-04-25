#ifndef SCREENTASK9_H
#define SCREENTASK9_H

#include <QFrame>
#include "core.h"
#include "screencontroller.h"

namespace Ui {
    class ScreenTask9;
}

class ScreenTask9 : public ScreenController {
    Q_OBJECT

public:
    explicit ScreenTask9(QWidget *parent = 0);
    ~ScreenTask9();
    bool validate(Core*, QString*);

private:
    void init();
    Ui::ScreenTask9 *ui;
    QString sequence;
};

#endif // SCREENTASK9_H
