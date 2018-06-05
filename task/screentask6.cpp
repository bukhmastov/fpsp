#include "screentask6.h"
#include "ui_screentask6.h"

ScreenTask6::ScreenTask6(QWidget *parent) : ScreenController(parent), ui(new Ui::ScreenTask6) {
    ui->setupUi(this);
}

ScreenTask6::~ScreenTask6() {
    delete ui;
}

void ScreenTask6::init() {
    if (ScreenController::store.count("task5_v") &&
        ScreenController::store.count("task5_h1") &&
        ScreenController::store.count("task5_h2")
    ) {
        v = ScreenController::store.at("task5_v");
        h1 = ScreenController::store.at("task5_h1");
        h2 = ScreenController::store.at("task5_h2");
    } else {
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
    }
    h12 = Static::multiplyPolynoms(h1, h2, 2);
    mSeqXOR = Static::getXOR(Static::getMSequence(h1, 15), Static::getMSequence(h2, 15));
    // setup view
    ui->inputV->addItem("31");
    ui->inputV->addItem("32");
    ui->inputV->addItem("33");
    ui->inputV->addItem("63");
    ui->inputV->addItem("64");
    ui->inputV->addItem("65");
    ui->titleH1->setText("h1(x) = " + Static::getReadablePolynom(h1));
    ui->titleH2->setText("h2(x) = " + Static::getReadablePolynom(h2));
    if (readOnly) {
        ui->inputHX->setReadOnly(true);
        ui->inputHX->setText(h12);
        ui->inputF->setReadOnly(true);
        ui->inputF->setText(mSeqXOR);
        ui->inputV->setEnabled(false);
        ui->inputV->setCurrentText(v);
    }
}

bool ScreenTask6::validate(Core* core, QString* message) {
    if (readOnly) {
        return true;
    }
    if (ui->inputHX->text() == h12 &&
        ui->inputF->text() == mSeqXOR &&
        ui->inputV->currentText() == v) {
        message->append(Static::messageAnswerRight);
        core->changeScore(2);
    } else {
        message->append(Static::messageAnswerWrong);
        core->changeScore(-2);
    }
    return true;
}
