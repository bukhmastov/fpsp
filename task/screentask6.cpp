#include "screentask6.h"
#include "ui_screentask6.h"
#include "static.h"

ScreenTask6::ScreenTask6(QWidget *parent) : ScreenController(parent), ui(new Ui::ScreenTask6) {
    ui->setupUi(this);
    init();
}

ScreenTask6::~ScreenTask6() {
    delete ui;
}

void ScreenTask6::init() {
    switch (rand() % 5) {
    case 0:
        n = 6;
        h1 = "1100001";
        h2 = "1101101";
        h12 = "1011010001101";
        v = "65";
        break;
    case 1:
        n = 6;
        h1 = "1110011";
        h2 = "1011011";
        h12 = "1100011111101";
        v = "65";
        break;
    case 2:
        n = 6;
        h1 = "1100111";
        h2 = "1101101";
        h12 = "1011111100011";
        v = "65";
        break;
    case 3:
        n = 5;
        h1 = "100101";
        h2 = "110111";
        h12 = "11000001011";
        v = "33";
        break;
    case 4:
        n = 5;
        h1 = "101111";
        h2 = "100101";
        h12 = "10101110011";
        v = "33";
        break;
    }
    ui->inputV->addItem("31");
    ui->inputV->addItem("32");
    ui->inputV->addItem("33");
    ui->inputV->addItem("63");
    ui->inputV->addItem("64");
    ui->inputV->addItem("65");
    ui->titleH1->setText("h1(x) = " + h1);
    ui->titleH2->setText("h2(x) = " + h2);
}

bool ScreenTask6::validate(Core* core, QString* message) {
    QString arg;
    for (int i = 0; i < n; i++) {
        arg.append("1");
    }
    QString mSeq1 = Static::getMSequence(h1, arg, 15);
    QString mSeq2 = Static::getMSequence(h2, arg, 15);
    if (ui->inputHX->text() == h12 &&
        ui->inputF->text() == Static::getXOR(mSeq1, mSeq2) &&
        ui->inputV->currentText() == v) {
        message->append("Ответ верный (+2 балла)");
        core->changeScore(2);
    } else {
        message->append("Ответ неверный (-2 балла)");
        core->changeScore(-2);
    }
    return true;
}
