#ifndef SCREENQUESTION_H
#define SCREENQUESTION_H

#include <QFrame>
#include "core.h"
#include "question.h"
#include "screencontroller.h"

namespace Ui {
    class ScreenQuestion;
}

class ScreenQuestion : public ScreenController {
    Q_OBJECT

public:
    explicit ScreenQuestion(QWidget *parent = 0);
    ~ScreenQuestion();
    static ScreenQuestion* get(Core*, Question*);
    bool validate(Core*, QString*);

private slots:
    void onRightAnswer();
    void onWrongAnswer();

private:
    Ui::ScreenQuestion *ui;
    Core *core;
    bool status = false;
};

#endif // SCREENQUESTION_H
