#include "screentask7.h"
#include "ui_screentask7.h"

ScreenTask7::ScreenTask7(QWidget *parent) : ScreenController(parent), ui(new Ui::ScreenTask7) {
    ui->setupUi(this);
}

ScreenTask7::~ScreenTask7() {
    delete ui;
}

void ScreenTask7::init() {
    switch (rnd() % 6) {
    default:
    case 0: h1 = "1000011"; h2 = "1100111"; h3 = "1101"; break; // 1  5  9
    case 1: h1 = "1100111"; h2 = "1101101"; h3 = "1011"; break; // 5  11 27
    case 2: h1 = "1101101"; h2 = "1100001"; h3 = "1101"; break; // 11 31 36
    case 3: h1 = "1011011"; h2 = "1000011"; h3 = "1011"; break; // 13 1  54
    case 4: h1 = "1110011"; h2 = "1011011"; h3 = "1101"; break; // 23 13 18
    case 5: h1 = "1100001"; h2 = "1110011"; h3 = "1011"; break; // 31 23 27
    }
    h13 = Static::multiplyPolynoms(h1, h3, 2);
    mSeqXOR = Static::getXOR(Static::getMSequence(h1, 10), Static::getMSequence(h3, 10));
    // setup view
    ui->inputV->addItem("4");
    ui->inputV->addItem("8");
    ui->inputV->addItem("11");
    ui->inputV->addItem("16");
    ui->inputV->addItem("31");
    ui->inputV->addItem("33");
    ui->inputV->addItem("63");
    ui->inputV->addItem("64");
    ui->inputV->addItem("65");
    ui->inputV->addItem("66");
    ui->title->setText(ui->title->text().replace("%h1%", Static::getReadablePolynom(h1)));
    if (readOnly) {
        ui->inputH3->setReadOnly(true);
        ui->inputH3->setText(h3);
        ui->inputHKM->setReadOnly(true);
        ui->inputHKM->setText(h13);
        ui->inputFKM->setReadOnly(true);
        ui->inputFKM->setText(mSeqXOR);
        ui->inputV->setEnabled(false);
        ui->inputV->setCurrentText("8");
    } else {
        ScreenController::store["task7_h1"] = h1;
        ScreenController::store["task7_h2"] = h2;
        ScreenController::store["task7_h3"] = h3;
    }
}

bool ScreenTask7::validate(Core* core, QString* message) {
    if (readOnly) {
        return true;
    }
    if (ui->inputH3->text() == h3 &&
        ui->inputHKM->text() == h13 &&
        ui->inputFKM->text() == mSeqXOR &&
        ui->inputV->currentText() == "8"
    ) {
        message->append(Static::messageAnswerRight);
        core->changeScore(2);
    } else {
        message->append(Static::messageAnswerWrong);
        core->changeScore(-2);
    }
    return true;
}
