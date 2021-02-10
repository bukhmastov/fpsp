#include "screentask2.h"
#include "ui_screentask2.h"

ScreenTask2::ScreenTask2(QWidget *parent) : ScreenController(parent), ui(new Ui::ScreenTask2) {
    ui->setupUi(this);
}

ScreenTask2::~ScreenTask2() {
    delete ui;
}

void ScreenTask2::init() {
    s = rnd() % 3 + 4;
    switch (s) {
    default:
    case 4:
        switch (rnd() % 2) {
        default:
        case 0: a = 1; pi = "11001"; hx = "11001"; break;
        case 1: a = 7; pi = "11001"; hx = "10011"; break;
        }
        break;
    case 5:
        switch (rnd() % 6) {
        default:
        case 0: a = 1;  pi = "101001"; hx = "101001"; break; // 1  5
        case 1: a = 3;  pi = "101001"; hx = "101111"; break; // 3  15
        case 2: a = 5;  pi = "101001"; hx = "111011"; break; // 5  7
        case 3: a = 7;  pi = "101001"; hx = "111101"; break; // 7  1
        case 4: a = 11; pi = "101001"; hx = "110111"; break; // 11 3
        case 5: a = 15; pi = "101001"; hx = "100101"; break; // 15 11
        }
        break;
    case 6:
        switch (rnd() % 6) {
        default:
        case 0: a = 1;  pi = "1100001"; hx = "1100001"; break; // 1  5
        case 1: a = 5;  pi = "1100001"; hx = "1110011"; break; // 5  11
        case 2: a = 11; pi = "1100001"; hx = "1011011"; break; // 11 31
        case 3: a = 13; pi = "1100001"; hx = "1101101"; break; // 13 1
        case 4: a = 23; pi = "1100001"; hx = "1100111"; break; // 23 13
        case 5: a = 31; pi = "1100001"; hx = "1000011"; break; // 31 23
        }
        break;
    }
    relayH1 = true;
    relayH2 = true;
    relayH3 = true;
    relayH4 = true;
    relayH5 = true;
    mSeq = Static::getMSequence(hx, 15);
    // setup view
    QString title = ui->title->text();
    QString titleA = ui->titleA->text();
    title = title.replace("%gf%", QString::number(s));
    title = title.replace("%pi%", Static::getReadablePolynom(pi));
    titleA = titleA.replace("%a%", QString::number(a));
    ui->title->setText(title);
    ui->titleA->setText(titleA);
    switch (s) {
    default:
    case 4:
        ui->set4->setVisible(true);
        ui->set5->setVisible(false);
        ui->set6->setVisible(false);
        break;
    case 5:
        ui->set4->setVisible(false);
        ui->set5->setVisible(true);
        ui->set6->setVisible(false);
        break;
    case 6:
        ui->set4->setVisible(false);
        ui->set5->setVisible(false);
        ui->set6->setVisible(true);
        break;
    }
    if (readOnly) {
        ui->inputX0->setReadOnly(true);
        ui->inputX0->setValue(hx.at(0).digitValue());
        ui->inputX1->setReadOnly(true);
        ui->inputX1->setValue(hx.at(1).digitValue());
        ui->inputX2->setReadOnly(true);
        ui->inputX2->setValue(hx.at(2).digitValue());
        ui->inputX3->setReadOnly(true);
        ui->inputX3->setValue(hx.at(3).digitValue());
        ui->inputX4->setReadOnly(true);
        ui->inputX4->setValue(hx.at(4).digitValue());
        if (s > 4) {
            ui->inputX5->setReadOnly(true);
            ui->inputX5->setValue(hx.at(5).digitValue());
        }
        if (s > 5) {
            ui->inputX6->setReadOnly(true);
            ui->inputX6->setValue(QString(hx.at(6)).toInt());
        }
        ui->inputMseq->setReadOnly(true);
        ui->inputMseq->setText(mSeq);
        relayH1 = hx.at(1).digitValue() == 0;
        relayH2 = hx.at(2).digitValue() == 0;
        relayH3 = hx.at(3).digitValue() == 0;
        relayH4 = hx.at(4).digitValue() == 0;
        relayH5 = s > 4 && hx.at(5).digitValue() == 0;
    } else {
        QObject::connect(ui->relayOn4H1, &ClickableQLabel::clicked, this, [this]{ onRelayClicked(1); });
        QObject::connect(ui->relayOff4H1, &ClickableQLabel::clicked, this, [this]{ onRelayClicked(1); });
        QObject::connect(ui->relayOn5H1, &ClickableQLabel::clicked, this, [this]{ onRelayClicked(1); });
        QObject::connect(ui->relayOff5H1, &ClickableQLabel::clicked, this, [this]{ onRelayClicked(1); });
        QObject::connect(ui->relayOn6H1, &ClickableQLabel::clicked, this, [this]{ onRelayClicked(1); });
        QObject::connect(ui->relayOff6H1, &ClickableQLabel::clicked, this, [this]{ onRelayClicked(1); });
        QObject::connect(ui->relayOn4H2, &ClickableQLabel::clicked, this, [this]{ onRelayClicked(2); });
        QObject::connect(ui->relayOff4H2, &ClickableQLabel::clicked, this, [this]{ onRelayClicked(2); });
        QObject::connect(ui->relayOn5H2, &ClickableQLabel::clicked, this, [this]{ onRelayClicked(2); });
        QObject::connect(ui->relayOff5H2, &ClickableQLabel::clicked, this, [this]{ onRelayClicked(2); });
        QObject::connect(ui->relayOn6H2, &ClickableQLabel::clicked, this, [this]{ onRelayClicked(2); });
        QObject::connect(ui->relayOff6H2, &ClickableQLabel::clicked, this, [this]{ onRelayClicked(2); });
        QObject::connect(ui->relayOn4H3, &ClickableQLabel::clicked, this, [this]{ onRelayClicked(3); });
        QObject::connect(ui->relayOff4H3, &ClickableQLabel::clicked, this, [this]{ onRelayClicked(3); });
        QObject::connect(ui->relayOn5H3, &ClickableQLabel::clicked, this, [this]{ onRelayClicked(3); });
        QObject::connect(ui->relayOff5H3, &ClickableQLabel::clicked, this, [this]{ onRelayClicked(3); });
        QObject::connect(ui->relayOn6H3, &ClickableQLabel::clicked, this, [this]{ onRelayClicked(3); });
        QObject::connect(ui->relayOff6H3, &ClickableQLabel::clicked, this, [this]{ onRelayClicked(3); });
        QObject::connect(ui->relayOn5H4, &ClickableQLabel::clicked, this, [this]{ onRelayClicked(4); });
        QObject::connect(ui->relayOff5H4, &ClickableQLabel::clicked, this, [this]{ onRelayClicked(4); });
        QObject::connect(ui->relayOn6H4, &ClickableQLabel::clicked, this, [this]{ onRelayClicked(4); });
        QObject::connect(ui->relayOff6H4, &ClickableQLabel::clicked, this, [this]{ onRelayClicked(4); });
        QObject::connect(ui->relayOn6H5, &ClickableQLabel::clicked, this, [this]{ onRelayClicked(5); });
        QObject::connect(ui->relayOff6H5, &ClickableQLabel::clicked, this, [this]{ onRelayClicked(5); });
    }
    onRelayClicked(1);
    onRelayClicked(2);
    onRelayClicked(3);
    onRelayClicked(4);
    onRelayClicked(5);
}

void ScreenTask2::onRelayClicked(int h) {
    switch (h) {
    case 1:
        relayH1 = !relayH1;
        ui->relayOn4H1->setVisible(relayH1);
        ui->relayOn5H1->setVisible(relayH1);
        ui->relayOn6H1->setVisible(relayH1);
        ui->relayOff4H1->setVisible(!relayH1);
        ui->relayOff5H1->setVisible(!relayH1);
        ui->relayOff6H1->setVisible(!relayH1);
        break;
    case 2:
        relayH2 = !relayH2;
        ui->relayOn4H2->setVisible(relayH2);
        ui->relayOn5H2->setVisible(relayH2);
        ui->relayOn6H2->setVisible(relayH2);
        ui->relayOff4H2->setVisible(!relayH2);
        ui->relayOff5H2->setVisible(!relayH2);
        ui->relayOff6H2->setVisible(!relayH2);
        break;
    case 3:
        relayH3 = !relayH3;
        ui->relayOn4H3->setVisible(relayH3);
        ui->relayOn5H3->setVisible(relayH3);
        ui->relayOn6H3->setVisible(relayH3);
        ui->relayOff4H3->setVisible(!relayH3);
        ui->relayOff5H3->setVisible(!relayH3);
        ui->relayOff6H3->setVisible(!relayH3);
        break;
    case 4:
        relayH4 = !relayH4;
        ui->relayOn5H4->setVisible(relayH4);
        ui->relayOn6H4->setVisible(relayH4);
        ui->relayOff5H4->setVisible(!relayH4);
        ui->relayOff6H4->setVisible(!relayH4);
        break;
    case 5:
        relayH5 = !relayH5;
        ui->relayOn6H5->setVisible(relayH5);
        ui->relayOff6H5->setVisible(!relayH5);
        break;
    }
}

bool ScreenTask2::validate(Core* core, QString* message) {
    if (readOnly) {
        return true;
    }
    QString polynomCAnswer;
    polynomCAnswer.append(ui->inputX0->text());
    polynomCAnswer.append(ui->inputX1->text());
    polynomCAnswer.append(ui->inputX2->text());
    polynomCAnswer.append(ui->inputX3->text());
    polynomCAnswer.append(ui->inputX4->text());
    if (s > 4) {
        polynomCAnswer.append(ui->inputX5->text());
    }
    if (s > 5) {
        polynomCAnswer.append(ui->inputX6->text());
    }
    if (hx == polynomCAnswer) {
        message->append("А) " + Static::messageAnswerRight);
        core->changeScore(2);
    } else {
        message->append("А) " + Static::messageAnswerWrong);
        core->changeScore(-2);
    }
    message->append("\n");

    if (mSeq == ui->inputMseq->text()) {
        message->append("Б) " + Static::messageAnswerRight);
        core->changeScore(2);
    } else {
        message->append("Б) " + Static::messageAnswerWrong);
        core->changeScore(-2);
    }
    message->append("\n");

    QString polynomCRelayAnswer = "";
    polynomCRelayAnswer.append("1");
    polynomCRelayAnswer.append(relayH1 ? "1" : "0");
    polynomCRelayAnswer.append(relayH2 ? "1" : "0");
    polynomCRelayAnswer.append(relayH3 ? "1" : "0");
    polynomCRelayAnswer.append(s < 4 ? "0" : s == 4 ? "1" : relayH4 ? "1" : "0");
    if (s > 4) {
        polynomCRelayAnswer.append(s < 5 ? "0" : s == 5 ? "1" : relayH5 ? "1" : "0");
    }
    if (s > 5) {
        polynomCRelayAnswer.append("1");
    }
    if (polynomCAnswer == polynomCRelayAnswer) {
        message->append("С) " + Static::messageAnswerRight);
        core->changeScore(2);
    } else {
        message->append("С) " + Static::messageAnswerWrong);
        core->changeScore(-2);
    }
    return true;
}
