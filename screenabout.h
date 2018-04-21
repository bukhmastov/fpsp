#ifndef SCREENABOUT_H
#define SCREENABOUT_H

#include <QFrame>

namespace Ui {
    class ScreenAbout;
}

class ScreenAbout : public QFrame {
    Q_OBJECT

public:
    explicit ScreenAbout(QWidget *parent = 0);
    ~ScreenAbout();

private:
    Ui::ScreenAbout *ui;
};

#endif // SCREENABOUT_H
