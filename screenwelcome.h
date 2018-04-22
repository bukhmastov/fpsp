#ifndef SCREENWELCOME_H
#define SCREENWELCOME_H

#include <QFrame>
#include "core.h"
#include "screencontroller.h"

namespace Ui {
    class ScreenWelcome;
}

class ScreenWelcome : public ScreenController {
    Q_OBJECT

public:
    explicit ScreenWelcome(QWidget *parent = 0);
    ~ScreenWelcome();
    bool validate(Core*, QString*);

private:
    Ui::ScreenWelcome *ui;
};

#endif // SCREENWELCOME_H
