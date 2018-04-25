#ifndef SCREENTASK6_H
#define SCREENTASK6_H

#include <QFrame>
#include "core.h"
#include "screencontroller.h"

namespace Ui {
    class ScreenTask6;
}

class ScreenTask6 : public ScreenController {
    Q_OBJECT

public:
    explicit ScreenTask6(QWidget *parent = 0);
    ~ScreenTask6();
    bool validate(Core*, QString*);

private:
    void init();
    Ui::ScreenTask6 *ui;
    int n;
    QString h1;
    QString h2;
    QString h12;
    QString v;
};

#endif // SCREENTASK6_H
