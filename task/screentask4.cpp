#include "screentask4.h"
#include "ui_screentask4.h"

ScreenTask4::ScreenTask4(QWidget *parent) : ScreenController(parent), ui(new Ui::ScreenTask4) {
    ui->setupUi(this);
    init();
}

ScreenTask4::~ScreenTask4() {
    delete ui;
}

void ScreenTask4::init() {
    int n;
    switch (rand() % 2) {
    default:
    case 0: n = 8;  h5 = "+1+1+1+1-1-1-1-1"; h8 = "+1-1-1+1-1+1+1-1"; break;
    case 1: n = 16; h5 = "+1+1+1+1-1-1-1-1+1+1+1+1-1-1-1-1"; h8 = "+1+1-1+1-1-1+1-1+1+1-1+1-1-1+1-1"; break;
    }
    ui->titleB->setText("Б) Сформируйте последовательности Уолша h5 и h8, соответствующие 5 и 8 строкам матрицы Адамара с периодом N = " + QString::number(n));
}

bool ScreenTask4::validate(Core* core, QString* message) {
    if (ui->inputH11->text() == "1"  && ui->inputH12->text() == "1"  && ui->inputH13->text() == "1"  && ui->inputH14->text() == "1"  &&
        ui->inputH21->text() == "1"  && ui->inputH22->text() == "-1" && ui->inputH23->text() == "1"  && ui->inputH24->text() == "-1" &&
        ui->inputH31->text() == "1"  && ui->inputH32->text() == "1"  && ui->inputH33->text() == "-1" && ui->inputH34->text() == "-1" &&
        ui->inputH41->text() == "1"  && ui->inputH42->text() == "-1" && ui->inputH43->text() == "-1" && ui->inputH44->text() == "1"
    ) {
        message->append("А) Ответ верный (+2 балла)");
        core->changeScore(2);
    } else {
        message->append("А) Ответ неверный (-2 балла)");
        core->changeScore(-2);
    }
    message->append("\n");
    if (h5 == ui->inputH5->text() && h8 == ui->inputH8->text()) {
        message->append("Б) Ответ верный (+2 балла)");
        core->changeScore(2);
    } else {
        message->append("Б) Ответ неверный (-2 балла)");
        core->changeScore(-2);
    }
    return true;
}
