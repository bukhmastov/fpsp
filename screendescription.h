#ifndef SCREENDESCRIPTION_H
#define SCREENDESCRIPTION_H

#include <QFrame>
#include "core.h"
#include "screencontroller.h"

namespace Ui {
    class ScreenDescription;
}

class ScreenDescription : public ScreenController {
    Q_OBJECT

public:
    explicit ScreenDescription(QWidget *parent = 0);
    ~ScreenDescription();
    bool validate(Core*, QString*);

private:
    Ui::ScreenDescription *ui;
};

#endif // SCREENDESCRIPTION_H
