#include "screentask7.h"
#include "ui_screentask7.h"
#include "static.h"

ScreenTask7::ScreenTask7(QWidget *parent) : ScreenController(parent), ui(new Ui::ScreenTask7) {
    ui->setupUi(this);
    init();
}

ScreenTask7::~ScreenTask7() {
    delete ui;
}

void ScreenTask7::init() {
    switch (rand() % 3) {
    case 0:
        h1 = "1110011";
        h2 = "1011011";
        h3 = "1101";
        h13 = "1000100111";
        break;
    case 1:
        h1 = "1011011";
        h2 = "1000011";
        h3 = "1101";
        h13 = "1111101111";
        break;
    case 2:
        h1 = "1000011";
        h2 = "1101101";
        h3 = "1101";
        h13 = "1101010111";
        break;
    }
    ui->inputV->addItem("31");
    ui->inputV->addItem("33");
    ui->inputV->addItem("63");
    ui->inputV->addItem("64");
    ui->inputV->addItem("65");
    ui->inputV->addItem("66");
    ui->title->setText(ui->title->text().replace("%h1%", h1));
}

bool ScreenTask7::validate(Core* core, QString* message) {
    QString mSeq1 = Static::getMSequence(h1, "111111", 10);
    QString mSeq3 = Static::getMSequence(h3, "111", 10);
    if (ui->inputH3->text() == h3 &&
        ui->inputHKM->text() == h13 &&
        ui->inputFKM->text() == Static::getXOR(mSeq1, mSeq3) &&
        ui->inputV->currentText() == "65"
    ) {
        message->append("Ответ верный (+2 балла)");
        core->changeScore(2);
    } else {
        message->append("Ответ неверный (-2 балла)");
        core->changeScore(-2);
    }
    return true;
}
