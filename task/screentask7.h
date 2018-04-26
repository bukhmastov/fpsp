#ifndef SCREENTASK7_H
#define SCREENTASK7_H

#include <QFrame>
#include "core.h"
#include "screencontroller.h"

namespace Ui {
    class ScreenTask7;
}

class ScreenTask7 : public ScreenController {
    Q_OBJECT

public:
    explicit ScreenTask7(QWidget *parent = 0);
    ~ScreenTask7();
    bool validate(Core*, QString*);

private:
    void init();
    Ui::ScreenTask7 *ui;
    QString h1;
    QString h2;
    QString h3;
    QString h13;
    QString h123;
};

#endif // SCREENTASK7_H