#include "screentask10.h"
#include "ui_screentask10.h"

ScreenTask10::ScreenTask10(QWidget *parent) : ScreenController(parent), ui(new Ui::ScreenTask10) {
    ui->setupUi(this);
}

ScreenTask10::~ScreenTask10() {
    delete ui;
}

void ScreenTask10::init() {
    switch (rnd() % 2) {
    default:
    case 0:
        h = "2+x+x<sup>2</sup>";
        c0 = 1;
        c1 = 0;
        f = "10122021";
        a0 = 1;
        a1 = 2;
        cA0 = 1;
        cA1 = 2;
        break;
    case 1:
        h = "2+2x+x<sup>2</sup>";
        c0 = 0;
        c1 = 2;
        f = "02210112";
        a0 = 1;
        a1 = 1;
        cA0 = 1;
        cA1 = 1;
        break;
    }
    // setup view
    QString titleA = ui->titleA->text().replace("%h%", h);
    QString titleB = ui->titleB->text();
    titleB.replace("%c0%", QString::number(c0));
    titleB.replace("%c1%", QString::number(c1));
    ui->titleA->setText(titleA);
    ui->titleB->setText(titleB);
    if (readOnly) {
        ui->inputC0->setReadOnly(true);
        ui->inputC0->setValue(cA0);
        ui->inputC1->setReadOnly(true);
        ui->inputC1->setValue(cA1);
        ui->inputF->setReadOnly(true);
        ui->inputF->setText(f);
        ui->inputA0->setReadOnly(true);
        ui->inputA0->setValue(a0);
        ui->inputA1->setReadOnly(true);
        ui->inputA1->setValue(a1);
    }
}

bool ScreenTask10::validate(Core* core, QString* message) {
    if (readOnly) {
        return true;
    }
    if (ui->inputC0->value() == cA0 &&
        ui->inputC1->value() == cA1 &&
        ui->inputF->text() == f &&
        ui->inputA0->value() == a0 &&
        ui->inputA1->value() == a1
    ) {
        message->append(Static::messageAnswerRight);
        core->changeScore(2);
    } else {
        message->append(Static::messageAnswerWrong);
        core->changeScore(-2);
    }
    return true;
}
