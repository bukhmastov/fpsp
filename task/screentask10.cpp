#include "screentask10.h"
#include "ui_screentask10.h"

ScreenTask10::ScreenTask10(QWidget *parent) : ScreenController(parent), ui(new Ui::ScreenTask10) {
    ui->setupUi(this);
    init();
}

ScreenTask10::~ScreenTask10() {
    delete ui;
}

void ScreenTask10::init() {
    switch (rand() % 2) {
    case 0:
        h = "x<sup>2</sup>+x+2";
        c0 = 1;
        c1 = 0;
        f = "10122021";
        a0 = 1;
        a1 = 2;
        cA0 = 1;
        cA1 = 2;
        break;
    case 2:
        h = "x<sup>2</sup>+2x+2";
        c0 = 0;
        c1 = 2;
        f = "02210112";
        a0 = 0;
        a1 = 1;
        cA0 = 1;
        cA1 = 1;
        break;
    }
    QString titleA = ui->titleA->text().replace("%h%", h);
    QString titleB = ui->titleB->text();
    titleB.replace("%c0%", QString::number(c0));
    titleB.replace("%c1%", QString::number(c1));
    ui->titleA->setText(titleA);
    ui->titleB->setText(titleB);
}

bool ScreenTask10::validate(Core* core, QString* message) {
    if (ui->inputC0->text() == QString::number(cA0) &&
        ui->inputC1->text() == QString::number(cA1) &&
        ui->inputF->text() == f &&
        ui->inputA0->text() == QString::number(a0) &&
        ui->inputA1->text() == QString::number(a1)
    ) {
        message->append("Ответ верный (+2 балла)");
        core->changeScore(2);
    } else {
        message->append("Ответ неверный (-2 балла)");
        core->changeScore(-2);
    }
    return true;
}
