#include "screentask4.h"
#include "ui_screentask4.h"

ScreenTask4::ScreenTask4(QWidget *parent) : ScreenController(parent), ui(new Ui::ScreenTask4) {
    ui->setupUi(this);
}

ScreenTask4::~ScreenTask4() {
    delete ui;
}

void ScreenTask4::init() {
    int n;
    switch (rnd() % 2) {
    default:
    case 0:
        n = 8;
        h5 = "+1+1+1+1-1-1-1-1";
        h8 = "+1-1-1+1-1+1+1-1";
        break;
    case 1:
        n = 16;
        h5 = "+1+1+1+1-1-1-1-1+1+1+1+1-1-1-1-1";
        h8 = "+1+1-1+1-1-1+1-1+1+1-1+1-1-1+1-1";
        break;
    }
    ui->titleB->setText(ui->titleB->text().replace("%n%", QString::number(n)));
    if (readOnly) {
        ui->inputH5->setReadOnly(true);
        ui->inputH5->setText(h5);
        ui->inputH8->setReadOnly(true);
        ui->inputH8->setText(h8);
        ui->inputH11->setReadOnly(true);
        ui->inputH11->setValue(1);
        ui->inputH12->setReadOnly(true);
        ui->inputH12->setValue(1);
        ui->inputH13->setReadOnly(true);
        ui->inputH13->setValue(1);
        ui->inputH14->setReadOnly(true);
        ui->inputH14->setValue(1);
        ui->inputH21->setReadOnly(true);
        ui->inputH21->setValue(1);
        ui->inputH22->setReadOnly(true);
        ui->inputH22->setValue(-1);
        ui->inputH23->setReadOnly(true);
        ui->inputH23->setValue(1);
        ui->inputH24->setReadOnly(true);
        ui->inputH24->setValue(-1);
        ui->inputH31->setReadOnly(true);
        ui->inputH31->setValue(1);
        ui->inputH32->setReadOnly(true);
        ui->inputH32->setValue(1);
        ui->inputH33->setReadOnly(true);
        ui->inputH33->setValue(-1);
        ui->inputH34->setReadOnly(true);
        ui->inputH34->setValue(-1);
        ui->inputH41->setReadOnly(true);
        ui->inputH41->setValue(1);
        ui->inputH42->setReadOnly(true);
        ui->inputH42->setValue(-1);
        ui->inputH43->setReadOnly(true);
        ui->inputH43->setValue(-1);
        ui->inputH44->setReadOnly(true);
        ui->inputH44->setValue(1);
    }
}

bool ScreenTask4::validate(Core* core, QString* message) {
    if (readOnly) {
        return true;
    }
    if (ui->inputH11->value() == 1  && ui->inputH12->value() == 1  && ui->inputH13->value() == 1  && ui->inputH14->value() == 1  &&
        ui->inputH21->value() == 1  && ui->inputH22->value() == -1 && ui->inputH23->value() == 1  && ui->inputH24->value() == -1 &&
        ui->inputH31->value() == 1  && ui->inputH32->value() == 1  && ui->inputH33->value() == -1 && ui->inputH34->value() == -1 &&
        ui->inputH41->value() == 1  && ui->inputH42->value() == -1 && ui->inputH43->value() == -1 && ui->inputH44->value() == 1
    ) {
        message->append("А) " + Static::messageAnswerRight);
        core->changeScore(2);
    } else {
        message->append("А) " + Static::messageAnswerWrong);
        core->changeScore(-2);
    }
    message->append("\n");
    if (h5 == ui->inputH5->text() && h8 == ui->inputH8->text()) {
        message->append("Б) " + Static::messageAnswerRight);
        core->changeScore(2);
    } else {
        message->append("Б) " + Static::messageAnswerWrong);
        core->changeScore(-2);
    }
    return true;
}
