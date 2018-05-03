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
    x0 = 1;
    x1 = rnd() % 2;
    x2 = rnd() % 2;
    x3 = rnd() % 2;
    x4 = s == 4 ? 1 : rnd() % 2;
    x5 = s == 5 ? 1 : s > 4 ? rnd() % 2 : -1;
    x6 = s == 6 ? 1 : s > 5 ? rnd() % 2 : -1;
    switch (s) {
    default:
    case 4:
        switch (rnd() % 2) {
        default:
        case 0: a = 1;  polynomC = "1100100"; break;
        case 1: a = 7;  polynomC = "1001100"; break;
        }
        break;
    case 5:
        switch (rnd() % 6) {
        default:
        case 0: a = 1;  polynomC = "1010010"; break;
        case 1: a = 3;  polynomC = "1011110"; break;
        case 2: a = 5;  polynomC = "1110110"; break;
        case 3: a = 7;  polynomC = "1111010"; break;
        case 4: a = 11; polynomC = "1101110"; break;
        case 5: a = 15; polynomC = "1001010"; break;
        }
        break;
    case 6:
        switch (rnd() % 6) {
        default:
        case 0: a = 1;  polynomC = "1100001"; break;
        case 1: a = 5;  polynomC = "1110011"; break;
        case 2: a = 11; polynomC = "1011011"; break;
        case 3: a = 13; polynomC = "1101101"; break;
        case 4: a = 23; polynomC = "1100111"; break;
        case 5: a = 31; polynomC = "1000011"; break;
        }
        break;
    }
    relayH1 = true;
    relayH2 = true;
    relayH3 = true;
    relayH4 = true;
    relayH5 = true;
    mSeq = Static::getMSequence(polynomC, 15);
    // setup view
    QString title = ui->title->text();
    QString titleA = ui->titleA->text();
    QString pi = "";
    pi.append(x6 == 1 ? "x<sup>6</sup>+" : "");
    pi.append(x5 == 1 ? "x<sup>5</sup>+" : "");
    pi.append(x4 == 1 ? "x<sup>4</sup>+" : "");
    pi.append(x3 == 1 ? "x<sup>3</sup>+" : "");
    pi.append(x2 == 1 ? "x<sup>2</sup>+" : "");
    pi.append(x1 == 1 ? "x+" : "");
    pi.append("1");
    title = title.replace("%gf%", QString::number(s));
    title = title.replace("%pi%", pi);
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
        ui->inputX6->setReadOnly(true);
        ui->inputX6->setValue(polynomC.at(0).digitValue());
        ui->inputX5->setReadOnly(true);
        ui->inputX5->setValue(polynomC.at(1).digitValue());
        ui->inputX4->setReadOnly(true);
        ui->inputX4->setValue(polynomC.at(2).digitValue());
        ui->inputX3->setReadOnly(true);
        ui->inputX3->setValue(polynomC.at(3).digitValue());
        ui->inputX2->setReadOnly(true);
        ui->inputX2->setValue(polynomC.at(4).digitValue());
        ui->inputX1->setReadOnly(true);
        ui->inputX1->setValue(polynomC.at(5).digitValue());
        ui->inputX0->setReadOnly(true);
        ui->inputX0->setValue(polynomC.at(6).digitValue());
        ui->inputMseq->setReadOnly(true);
        ui->inputMseq->setText(mSeq);
        relayH1 = polynomC.at(5).digitValue() == 0;
        relayH2 = polynomC.at(4).digitValue() == 0;
        relayH3 = polynomC.at(3).digitValue() == 0;
        relayH4 = polynomC.at(2).digitValue() == 0;
        relayH5 = polynomC.at(1).digitValue() == 0;
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
    polynomCAnswer.append(ui->inputX6->text());
    polynomCAnswer.append(ui->inputX5->text());
    polynomCAnswer.append(ui->inputX4->text());
    polynomCAnswer.append(ui->inputX3->text());
    polynomCAnswer.append(ui->inputX2->text());
    polynomCAnswer.append(ui->inputX1->text());
    polynomCAnswer.append(ui->inputX0->text());
    if (polynomC == polynomCAnswer) {
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
    polynomCRelayAnswer.append(s < 6 ? "0" : "1");
    polynomCRelayAnswer.append(s < 5 ? "0" : s == 5 ? "1" : relayH5 ? "1" : "0");
    polynomCRelayAnswer.append(s < 4 ? "0" : s == 4 ? "1" : relayH4 ? "1" : "0");
    polynomCRelayAnswer.append(relayH3 ? "1" : "0");
    polynomCRelayAnswer.append(relayH2 ? "1" : "0");
    polynomCRelayAnswer.append(relayH1 ? "1" : "0");
    polynomCRelayAnswer.append("1");
    if (polynomCAnswer == polynomCRelayAnswer) {
        message->append("С) " + Static::messageAnswerRight);
        core->changeScore(2);
    } else {
        message->append("С) " + Static::messageAnswerWrong);
        core->changeScore(-2);
    }
    return true;
}
