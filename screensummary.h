#ifndef SCREENSUMMARY_H
#define SCREENSUMMARY_H

#include <QFrame>
#include "core.h"
#include "screencontroller.h"

namespace Ui {
    class ScreenSummary;
}

class ScreenSummary : public ScreenController {
    Q_OBJECT

public:
    explicit ScreenSummary(QWidget *parent = 0);
    ~ScreenSummary();
    static ScreenSummary* get(Core*);
    bool validate(Core*, QString*);

private:
    Ui::ScreenSummary *ui;
};

#endif // SCREENSUMMARY_H
