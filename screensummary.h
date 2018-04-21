#ifndef SCREENSUMMARY_H
#define SCREENSUMMARY_H

#include <QFrame>
#include "core.h"

namespace Ui {
    class ScreenSummary;
}

class ScreenSummary : public QFrame {
    Q_OBJECT

public:
    explicit ScreenSummary(QWidget *parent = 0);
    ~ScreenSummary();
    static ScreenSummary* get(Core*);

private:
    Ui::ScreenSummary *ui;
};

#endif // SCREENSUMMARY_H
