#include "screentask8.h"
#include "ui_screentask8.h"

ScreenTask8::ScreenTask8(QWidget *parent) : ScreenController(parent), ui(new Ui::ScreenTask8) {
    ui->setupUi(this);
}

ScreenTask8::~ScreenTask8() {
    delete ui;
}

void ScreenTask8::init() {
    if (ScreenController::store.count("task7_h1") &&
        ScreenController::store.count("task7_h2") &&
        ScreenController::store.count("task7_h3") &&
        ScreenController::store.count("task7_h123")
    ) {
        h1 = ScreenController::store.at("task7_h1");
        h2 = ScreenController::store.at("task7_h2");
        h3 = ScreenController::store.at("task7_h3");
        h123 = ScreenController::store.at("task7_h123");
    } else {
        switch (rnd() % 3) {
        default:
        case 0:
            h1 = "1110011";
            h2 = "1011011";
            h3 = "1101";
            h123 = "1011110011100001";
            break;
        case 1:
            h1 = "1011011";
            h2 = "1000011";
            h3 = "1101";
            h123 = "1111111111110001";
            break;
        case 2:
            h1 = "1000011";
            h2 = "1101101";
            h3 = "1101";
            h123 = "1010101110010011";
            break;
        }
    }
    mSeqXOR = Static::getXOR(Static::getXOR(Static::getMSequence(h1, 10), Static::getMSequence(h2, 10)), Static::getMSequence(h3, 10));
    // setup view
    ui->inputV->addItem("63");
    ui->inputV->addItem("64");
    ui->inputV->addItem("65");
    ui->inputV->addItem("512");
    ui->inputV->addItem("520");
    ui->inputV->addItem("513");
    ui->inputV->addItem("521");
    ui->title->setText(ui->title->text().replace("%h1%", h1));
    if (readOnly) {
        ui->inputH2->setReadOnly(true);
        ui->inputH2->setText(h2);
        ui->inputHKB->setReadOnly(true);
        ui->inputHKB->setText(h123);
        ui->inputFKB->setReadOnly(true);
        ui->inputFKB->setText(mSeqXOR);
        ui->inputV->setEnabled(false);
        ui->inputV->setCurrentText("520");
    }
}

bool ScreenTask8::validate(Core* core, QString* message) {
    if (readOnly) {
        return true;
    }
    if (ui->inputH2->text() == h2 &&
        ui->inputHKB->text() == h123 &&
        ui->inputFKB->text() == mSeqXOR &&
        ui->inputV->currentText() == "520"
    ) {
        message->append(Static::messageAnswerRight);
        core->changeScore(2);
    } else {
        message->append(Static::messageAnswerWrong);
        core->changeScore(-2);
    }
    return true;
}
