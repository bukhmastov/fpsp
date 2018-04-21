#ifndef SCREENQUESTION_H
#define SCREENQUESTION_H

#include <QFrame>
#include "core.h"
#include "question.h"

namespace Ui {
    class ScreenQuestion;
}

class ScreenQuestion : public QFrame {
    Q_OBJECT

public:
    explicit ScreenQuestion(QWidget *parent = 0);
    ~ScreenQuestion();
    static ScreenQuestion* get(Core*, Question*);

private slots:
    void onRightAnswer();
    void onWrongAnswer();

private:
    Ui::ScreenQuestion *ui;
    Core *core;
};

#endif // SCREENQUESTION_H
