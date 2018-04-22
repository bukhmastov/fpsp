#ifndef SCREENABOUT_H
#define SCREENABOUT_H

#include <QFrame>
#include "core.h"
#include "screencontroller.h"

namespace Ui {
    class ScreenAbout;
}

class ScreenAbout : public ScreenController {
    Q_OBJECT

public:
    explicit ScreenAbout(QWidget *parent = 0);
    ~ScreenAbout();
    bool validate(Core*, QString*);

private:
    Ui::ScreenAbout *ui;
};

#endif // SCREENABOUT_H
