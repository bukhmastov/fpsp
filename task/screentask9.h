#ifndef SCREENTASK9_H
#define SCREENTASK9_H

#include <QFrame>
#include "util/core.h"
#include "util/screencontroller.h"

namespace Ui {
    class ScreenTask9;
}

class ScreenTask9 : public ScreenController {
    Q_OBJECT

public:
    explicit ScreenTask9(QWidget *parent = 0);
    ~ScreenTask9();
    ScreenController* init(int, bool);
    bool validate(Core*, QString*);

protected:
    void init();

private:
    Ui::ScreenTask9 *ui;
    QString sequence;
};

#endif // SCREENTASK9_H
