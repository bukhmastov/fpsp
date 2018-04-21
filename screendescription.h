#ifndef SCREENDESCRIPTION_H
#define SCREENDESCRIPTION_H

#include <QFrame>

namespace Ui {
    class ScreenDescription;
}

class ScreenDescription : public QFrame {
    Q_OBJECT

public:
    explicit ScreenDescription(QWidget *parent = 0);
    ~ScreenDescription();

private:
    Ui::ScreenDescription *ui;
};

#endif // SCREENDESCRIPTION_H
