#include "static.h"
#include "screenquestion.h"
#include "ui_screenquestion.h"
#include "questionanswerlabel.h"
#include "mainwindow.h"
#include <iostream>

ScreenQuestion::ScreenQuestion(QWidget *parent) : QFrame(parent), ui(new Ui::ScreenQuestion) {
    ui->setupUi(this);
}

ScreenQuestion::~ScreenQuestion() {
    delete ui;
}

ScreenQuestion* ScreenQuestion::get(Core *core, Question* question) {
    ScreenQuestion *screen = new ScreenQuestion;
    screen->core = core;
    screen->ui->questionLabel->setText(question->getQustion());
    unsigned int start = rand() % question->getAnswers().size();
    for (unsigned int i = start; i < question->getAnswers().size() + start; i++) {
        int index = i % question->getAnswers().size();
        QString answer = question->getAnswers().at(index);
        QuestionAnswerLabel *label = new QuestionAnswerLabel;
        label->setText(answer);
        screen->ui->answersLayout->addWidget(label);
        QObject::connect(label, &QuestionAnswerLabel::clicked, screen, index == 0 ? &ScreenQuestion::onRightAnswer : &ScreenQuestion::onWrongAnswer);
    }
    return screen;
}

void ScreenQuestion::onRightAnswer() {
    this->core->changeScore(Static::score4quetion);
    this->core->next();
}

void ScreenQuestion::onWrongAnswer() {
    this->core->changeScore(-Static::score4quetion);
    this->core->next();
}
