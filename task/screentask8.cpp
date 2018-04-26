#include "screentask8.h"
#include "ui_screentask8.h"
#include "static.h"

ScreenTask8::ScreenTask8(QWidget *parent) : ScreenController(parent), ui(new Ui::ScreenTask8) {
    ui->setupUi(this);
    init();
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
        switch (rand() % 3) {
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
    ui->inputV->addItem("63");
    ui->inputV->addItem("64");
    ui->inputV->addItem("65");
    ui->inputV->addItem("512");
    ui->inputV->addItem("520");
    ui->inputV->addItem("513");
    ui->inputV->addItem("521");
    ui->title->setText(ui->title->text().replace("%h1%", h1));
}

bool ScreenTask8::validate(Core* core, QString* message) {
    QString mSeq1 = Static::getMSequence(h1, "111111", 10);
    QString mSeq2 = Static::getMSequence(h2, "111111", 10);
    QString mSeq3 = Static::getMSequence(h3, "111", 10);
    if (ui->inputH2->text() == h2 &&
        ui->inputHKB->text() == h123 &&
        ui->inputFKB->text() == Static::getXOR(Static::getXOR(mSeq1, mSeq2), mSeq3) &&
        ui->inputV->currentText() == "520"
    ) {
        message->append("Ответ верный (+2 балла)");
        core->changeScore(2);
    } else {
        message->append("Ответ неверный (-2 балла)");
        core->changeScore(-2);
    }
    return true;
}
