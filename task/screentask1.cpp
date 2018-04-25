#include "screentask1.h"
#include "ui_screentask1.h"
#include "view/clickableqlabel.h"
#include "static.h"
#include <iostream>

ScreenTask1::ScreenTask1(QWidget *parent) : ScreenController(parent), ui(new Ui::ScreenTask1) {
    ui->setupUi(this);
    init();
}

ScreenTask1::~ScreenTask1() {
    delete ui;
}

void ScreenTask1::init() {
    // generate polynom x3 x2 x1 x0
    x0 = 1;
    x1 = rand() % 2;
    x2 = 1 - x1;
    x3 = 1;
    // generate initial symbols
    c0 = rand() % 2;
    c1 = rand() % 2;
    c2 = rand() % 2;
    // set triggers to off state
    relayH1 = false;
    relayH2 = false;
    // setup view
    QString titleA = "";
    titleA.append("A) Составить уравнение для символов М-последовательности, если h(x)=x<sup>3</sup>");
    titleA.append(x2 == 1 ? "+x<sup>2</sup>" : "");
    titleA.append(x1 == 1 ? "+x" : "");
    titleA.append("+1");
    QString titleB = "";
    titleB.append("Б) Для исходных символов C<sub>0</sub>=");
    titleB.append(QString::number(c0));
    titleB.append(", C<sub>1</sub>=");
    titleB.append(QString::number(c1));
    titleB.append(", C<sub>2</sub>=");
    titleB.append(QString::number(c2));
    titleB.append(" сформировать М-последовательность F");
    ui->titleA->setText(titleA);
    ui->titleB->setText(titleB);
    ui->relayOnH1->setVisible(relayH1);
    ui->relayOffH1->setVisible(!relayH1);
    ui->relayOnH2->setVisible(relayH2);
    ui->relayOffH2->setVisible(!relayH2);
    QObject::connect(ui->relayOnH1, &ClickableQLabel::clicked, this, [this]{ onRelayClicked(1); });
    QObject::connect(ui->relayOffH1, &ClickableQLabel::clicked, this, [this]{ onRelayClicked(1); });
    QObject::connect(ui->relayOnH2, &ClickableQLabel::clicked, this, [this]{ onRelayClicked(2); });
    QObject::connect(ui->relayOffH2, &ClickableQLabel::clicked, this, [this]{ onRelayClicked(2); });
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
    if (x0 == ui->inputA0->text().toInt() &&
        x1 == ui->inputA1->text().toInt() &&
        x2 == ui->inputA2->text().toInt()
    ) {
        message->append("А) Ответ верный (+2 балла)");
        core->changeScore(2);
    } else {
        message->append("А) Ответ неверный (-2 балла)");
        core->changeScore(-2);
    }
    message->append("\n");
    QString mSeg = Static::getMSequence(QString::number(x3) + QString::number(x2) + QString::number(x1) + QString::number(x0), QString::number(c0) + QString::number(c1) + QString::number(c2), 7);
    if (mSeg == ui->inputB->text()) {
        message->append("Б) Ответ верный (+2 балла)");
        core->changeScore(2);
    } else {
        message->append("Б) Ответ неверный (-2 балла)");
        core->changeScore(-2);
    }
    message->append("\n");
    if (c0 == ui->inputC0->text().toInt() &&
        c1 == ui->inputC1->text().toInt() &&
        c2 == ui->inputC2->text().toInt() &&
        ((x1 == 1 && relayH1) || (x1 == 0 && !relayH1)) &&
        ((x2 == 1 && relayH2) || (x2 == 0 && !relayH2))
    ) {
        message->append("С) Ответ верный (+2 балла)");
        core->changeScore(2);
    } else {
        message->append("С) Ответ неверный (-2 балла)");
        core->changeScore(-2);
    }
    return true;
}
