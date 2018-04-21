#ifndef SCREENWELCOME_H
#define SCREENWELCOME_H

#include <QFrame>

namespace Ui {
class ScreenWelcome;
}

class ScreenWelcome : public QFrame {
    Q_OBJECT

public:
    explicit ScreenWelcome(QWidget *parent = 0);
    ~ScreenWelcome();

private:
    Ui::ScreenWelcome *ui;
};

#endif // SCREENWELCOME_H
