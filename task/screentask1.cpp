#include "screentask1.h"
#include "ui_screentask1.h"
#include "view/clickableqlabel.h"

ScreenTask1::ScreenTask1(QWidget *parent) : ScreenController(parent), ui(new Ui::ScreenTask1) {
    ui->setupUi(this);
}

ScreenTask1::~ScreenTask1() {
    delete ui;
}

void ScreenTask1::init() {
    // generate polynom x3 x2 x1 x0
    x0 = 1;
    x1 = rnd() % 2;
    x2 = 1 - x1;
    x3 = 1;
    // generate initial symbols
    c0 = rnd() % 2;
    c1 = rnd() % 2;
    c2 = c0 == 0 && c1 == 0 ? 1 : rnd() % 2;
    // set triggers to off state
    relayH1 = false;
    relayH2 = false;
    // get m sequence
    mSeg = Static::getMSequence(QString::number(x0) + QString::number(x1) + QString::number(x2) + QString::number(x3), QString::number(c0) + QString::number(c1) + QString::number(c2), 7);
    // setup view
    QString titleA = ui->titleA->text();
    QString titleB = ui->titleB->text();
    QString titleAH = "x<sup>3</sup>";
    titleAH.append(x2 == 1 ? "+x<sup>2</sup>" : "");
    titleAH.append(x1 == 1 ? "+x" : "");
    titleAH.append("+1");
    titleA = titleA.replace("%h%", titleAH);
    titleB = titleB.replace("%c0%", QString::number(c0));
    titleB = titleB.replace("%c1%", QString::number(c1));
    titleB = titleB.replace("%c2%", QString::number(c2));
    ui->titleA->setText(titleA);
    ui->titleB->setText(titleB);
    if (readOnly) {
        relayH1 = x1 == 1;
        relayH2 = x2 == 1;
        ui->inputA0->setReadOnly(true);
        ui->inputA0->setValue(x0);
        ui->inputA1->setReadOnly(true);
        ui->inputA1->setValue(x1);
        ui->inputA2->setReadOnly(true);
        ui->inputA2->setValue(x2);
        ui->inputB->setReadOnly(true);
        ui->inputB->setText(mSeg);
        ui->inputC0->setReadOnly(true);
        ui->inputC0->setValue(c0);
        ui->inputC1->setReadOnly(true);
        ui->inputC1->setValue(c1);
        ui->inputC2->setReadOnly(true);
        ui->inputC2->setValue(c2);
    } else {
        QObject::connect(ui->relayOnH1, &ClickableQLabel::clicked, this, [this]{ onRelayClicked(1); });
        QObject::connect(ui->relayOffH1, &ClickableQLabel::clicked, this, [this]{ onRelayClicked(1); });
        QObject::connect(ui->relayOnH2, &ClickableQLabel::clicked, this, [this]{ onRelayClicked(2); });
        QObject::connect(ui->relayOffH2, &ClickableQLabel::clicked, this, [this]{ onRelayClicked(2); });
    }
    ui->relayOnH1->setVisible(relayH1);
    ui->relayOffH1->setVisible(!relayH1);
    ui->relayOnH2->setVisible(relayH2);
    ui->relayOffH2->setVisible(!relayH2);
}

void ScreenTask1::onRelayClicked(int h) {
    switch (h) {
    case 1:
        relayH1 = !relayH1;
        ui->relayOnH1->setVisible(relayH1);
        ui->relayOffH1->setVisible(!relayH1);
        break;
    case 2:
        relayH2 = !relayH2;
        ui->relayOnH2->setVisible(relayH2);
        ui->relayOffH2->setVisible(!relayH2);
        break;
    }
}

bool ScreenTask1::validate(Core* core, QString* message) {
    if (readOnly) {
        return true;
    }
    if (x0 == ui->inputA0->value() &&
        x1 == ui->inputA1->value() &&
        x2 == ui->inputA2->value()
    ) {
        message->append("А) " + Static::messageAnswerRight);
        core->changeScore(2);
    } else {
        message->append("А) " + Static::messageAnswerWrong);
        core->changeScore(-2);
    }
    message->append("\n");
    if (mSeg == ui->inputB->text()) {
        message->append("Б) " + Static::messageAnswerRight);
        core->changeScore(2);
    } else {
        message->append("Б) " + Static::messageAnswerWrong);
        core->changeScore(-2);
    }
    message->append("\n");
    if (c0 == ui->inputC0->value() &&
        c1 == ui->inputC1->value() &&
        c2 == ui->inputC2->value() &&
        ((x1 == 1 && relayH1) || (x1 == 0 && !relayH1)) &&
        ((x2 == 1 && relayH2) || (x2 == 0 && !relayH2))
    ) {
        message->append("С) " + Static::messageAnswerRight);
        core->changeScore(2);
    } else {
        message->append("С) " + Static::messageAnswerWrong);
        core->changeScore(-2);
    }
    return true;
}
