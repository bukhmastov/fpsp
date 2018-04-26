#include "screentask7.h"
#include "ui_screentask7.h"

ScreenTask7::ScreenTask7(QWidget *parent) : ScreenController(parent), ui(new Ui::ScreenTask7) {
    ui->setupUi(this);
}

ScreenTask7::~ScreenTask7() {
    delete ui;
}

void ScreenTask7::init() {
    switch (rnd() % 3) {
    default:
    case 0:
        h1 = "1110011";
        h2 = "1011011";
        h3 = "1101";
        h13 = "1000100111";
        h123 = "1011110011100001";
        break;
    case 1:
        h1 = "1011011";
        h2 = "1000011";
        h3 = "1101";
        h13 = "1111101111";
        h123 = "1111111111110001";
        break;
    case 2:
        h1 = "1000011";
        h2 = "1101101";
        h3 = "1101";
        h13 = "1101010111";
        h123 = "1010101110010011";
        break;
    }
    mSeqXOR = Static::getXOR(Static::getMSequence(h1, 10), Static::getMSequence(h3, 10));
    // setup view
    ui->inputV->addItem("31");
    ui->inputV->addItem("33");
    ui->inputV->addItem("63");
    ui->inputV->addItem("64");
    ui->inputV->addItem("65");
    ui->inputV->addItem("66");
    ui->title->setText(ui->title->text().replace("%h1%", h1));
    if (readOnly) {
        ui->inputH3->setReadOnly(true);
        ui->inputH3->setText(h3);
        ui->inputHKM->setReadOnly(true);
        ui->inputHKM->setText(h13);
        ui->inputFKM->setReadOnly(true);
        ui->inputFKM->setText(mSeqXOR);
        ui->inputV->setEnabled(false);
        ui->inputV->setCurrentText("65");
    } else {
        ScreenController::store["task7_h1"] = h1;
        ScreenController::store["task7_h2"] = h2;
        ScreenController::store["task7_h3"] = h3;
        ScreenController::store["task7_h123"] = h123;
    }
}

bool ScreenTask7::validate(Core* core, QString* message) {
    if (readOnly) {
        return true;
    }
    if (ui->inputH3->text() == h3 &&
        ui->inputHKM->text() == h13 &&
        ui->inputFKM->text() == mSeqXOR &&
        ui->inputV->currentText() == "65"
    ) {
        message->append(Static::messageAnswerRight);
        core->changeScore(2);
    } else {
        message->append(Static::messageAnswerWrong);
        core->changeScore(-2);
    }
    return true;
}
