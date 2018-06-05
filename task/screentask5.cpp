#include "screentask5.h"
#include "ui_screentask5.h"

ScreenTask5::ScreenTask5(QWidget *parent) : ScreenController(parent), ui(new Ui::ScreenTask5) {
    ui->setupUi(this);
}

ScreenTask5::~ScreenTask5() {
    delete ui;
}

void ScreenTask5::init() {
    n = rnd() % 2 + 5;
    if (n == 5) {
        v = "33";
        switch (rnd() % 6) {
        default:
        case 0: h1 = "100101"; h2 = "110111"; break; // 1  5
        case 1: h1 = "111101"; h2 = "101001"; break; // 3  15
        case 2: h1 = "110111"; h2 = "101111"; break; // 5  7
        case 3: h1 = "101111"; h2 = "100101"; break; // 7  1
        case 4: h1 = "111011"; h2 = "111101"; break; // 11 3
        case 5: h1 = "101001"; h2 = "111011"; break; // 15 11
        }
    }
    if (n == 6) {
        v = "65";
        switch (rnd() % 6) {
        default:
        case 0: h1 = "1000011"; h2 = "1100111"; break; // 1  5
        case 1: h1 = "1100111"; h2 = "1101101"; break; // 5  11
        case 2: h1 = "1101101"; h2 = "1100001"; break; // 11 31
        case 3: h1 = "1011011"; h2 = "1000011"; break; // 13 1
        case 4: h1 = "1110011"; h2 = "1011011"; break; // 23 13
        case 5: h1 = "1100001"; h2 = "1110011"; break; // 31 23
        }
    }
    mSeq = Static::getMSequence(h2, 15);
    // setup view
    QString title = ui->title->text();
    title = title.replace("%s%", QString::number(n));
    title = title.replace("%h%", Static::getReadablePolynom(h1));
    ui->title->setText(title);
    if (readOnly) {
        ui->inputHX->setReadOnly(true);
        ui->inputHX->setText(h2);
        ui->inputF->setReadOnly(true);
        ui->inputF->setText(mSeq);
    } else {
        ScreenController::store["task5_v"] = v;
        ScreenController::store["task5_h1"] = h1;
        ScreenController::store["task5_h2"] = h2;
    }
}

bool ScreenTask5::validate(Core* core, QString* message) {
    if (readOnly) {
        return true;
    }
    if (h2 == ui->inputHX->text() && mSeq == ui->inputF->text()) {
        message->append(Static::messageAnswerRight);
        core->changeScore(2);
    } else {
        message->append(Static::messageAnswerWrong);
        core->changeScore(-2);
    }
    return true;
}
