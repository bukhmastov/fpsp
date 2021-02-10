#include "screentask3.h"
#include "ui_screentask3.h"

ScreenTask3::ScreenTask3(QWidget *parent) : ScreenController(parent), ui(new Ui::ScreenTask3) {
    ui->setupUi(this);
}

ScreenTask3::~ScreenTask3() {
    delete ui;
}

void ScreenTask3::init() {
    sequence.clear();
    int n;
    switch (rnd() % 6) {
    default:
    case 0: n = 3;  sequence.push_back("+1+1-1"); sequence.push_back("+1-1+1"); break;
    case 1: n = 4;  sequence.push_back("+1+1-1+1"); sequence.push_back("+1+1+1-1"); break;
    case 2: n = 5;  sequence.push_back("+1+1+1-1+1"); break;
    case 3: n = 7;  sequence.push_back("+1+1+1-1-1+1-1"); break;
    case 4: n = 11; sequence.push_back("+1+1+1-1-1-1+1-1-1+1-1"); break;
    case 5: n = 13; sequence.push_back("+1+1+1+1+1-1-1+1+1-1+1-1+1"); break;
    }
    ui->title->setText(ui->title->text().replace("%n%", QString::number(n)));
    if (readOnly) {
        ui->input->setReadOnly(true);
        ui->input->setText(sequence.at(0));
    }
}

bool ScreenTask3::validate(Core* core, QString* message) {
    if (readOnly) {
        return true;
    }
    if (std::find(sequence.begin(), sequence.end(), ui->input->text()) != sequence.end()) {
        message->append(Static::messageAnswerRight);
        core->changeScore(2);
    } else {
        message->append(Static::messageAnswerWrong);
        core->changeScore(-2);
    }
    return true;
}
