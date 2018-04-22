#include "screentask2.h"
#include "ui_screentask2.h"
#include "static.h"

ScreenTask2::ScreenTask2(QWidget *parent) : ScreenController(parent), ui(new Ui::ScreenTask2) {
    ui->setupUi(this);
    init();
}

ScreenTask2::~ScreenTask2() {
    delete ui;
}

void ScreenTask2::init() {
    s = rand() % 3 + 4;
    x0 = 1;
    x1 = rand() % 2;
    x2 = rand() % 2;
    x3 = rand() % 2;
    x4 = s == 4 ? 1 : rand() % 2;
    x5 = s == 5 ? 1 : s > 4 ? rand() % 2 : -1;
    x6 = s == 6 ? 1 : s > 5 ? rand() % 2 : -1;
    switch (s) {
    case 4:
        switch (rand() % 2) {
        case 0: a = 1;  polynomC = "0010011"; break;
        case 1: a = 7;  polynomC = "0011001"; break;
        }
        break;
    case 5:
        switch (rand() % 6) {
        case 0: a = 1;  polynomC = "0100101"; break;
        case 1: a = 3;  polynomC = "0111101"; break;
        case 2: a = 5;  polynomC = "0110111"; break;
        case 3: a = 7;  polynomC = "0101111"; break;
        case 4: a = 11; polynomC = "0111011"; break;
        case 5: a = 15; polynomC = "0101001"; break;
        }
        break;
    case 6:
        switch (rand() % 6) {
        case 0: a = 1;  polynomC = "1000011"; break;
        case 1: a = 5;  polynomC = "1100111"; break;
        case 2: a = 11; polynomC = "1101101"; break;
        case 3: a = 13; polynomC = "1011011"; break;
        case 4: a = 23; polynomC = "1110011"; break;
        case 5: a = 31; polynomC = "1100001"; break;
        }
        break;
    }
    relayH1 = true;
    relayH2 = true;
    relayH3 = true;
    relayH4 = true;
    relayH5 = true;

    QString title;
    title.append("Над полем GF(2<sup>").append(QString::number(s)).append("</sup>), pi(x)=");
    title.append(x6 == 1 ? "x<sup>6</sup>+" : "");
    title.append(x5 == 1 ? "x<sup>5</sup>+" : "");
    title.append(x4 == 1 ? "x<sup>4</sup>+" : "");
    title.append(x3 == 1 ? "x<sup>3</sup>+" : "");
    title.append(x2 == 1 ? "x<sup>2</sup>+" : "");
    title.append(x1 == 1 ? "x+" : "");
    title.append("1, a=x");
    QString titleA;
    titleA.append("А) Ввести коэффициенты проверочного полинома h(x), корнем которого является элемент a<sup>").append(QString::number(a)).append("</sup>");
    ui->title->setText(title);
    ui->titleA->setText(titleA);

    switch (s) {
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
    QString polynomCAnswer;
    polynomCAnswer.append(ui->inputX6->text());
    polynomCAnswer.append(ui->inputX5->text());
    polynomCAnswer.append(ui->inputX4->text());
    polynomCAnswer.append(ui->inputX3->text());
    polynomCAnswer.append(ui->inputX2->text());
    polynomCAnswer.append(ui->inputX1->text());
    polynomCAnswer.append(ui->inputX0->text());
    if (polynomC == polynomCAnswer) {
        message->append("А) Ответ верный (+2 балла)");
        core->changeScore(2);
    } else {
        message->append("А) Ответ неверный (-2 балла)");
        core->changeScore(-2);
    }
    message->append("\n");

    QString polynom;
    polynom.append(x6 == -1 ? "" : QString::number(x6));
    polynom.append(x5 == -1 ? "" : QString::number(x5));
    polynom.append(QString::number(x4));
    polynom.append(QString::number(x3));
    polynom.append(QString::number(x2));
    polynom.append(QString::number(x1));
    polynom.append(QString::number(x0));
    QString args;
    for (int i = 0; i < s - 1; i++) {
        args.append("1");
    }
    QString mSeq = Static::getMSequence(polynom, args, 15);
    if (mSeq == ui->inputMseq->text()) {
        message->append("Б) Ответ верный (+2 балла)");
        core->changeScore(2);
    } else {
        message->append("Б) Ответ неверный (-2 балла)");
        core->changeScore(-2);
    }
    message->append("\n");

    QString polynomCRelayAnswer;
    polynomCRelayAnswer.append(s < 6 ? "0" : "1");
    polynomCRelayAnswer.append(s < 5 ? "0" : s == 5 ? "1" : relayH5 ? "1" : "0");
    polynomCRelayAnswer.append(s < 4 ? "0" : s == 4 ? "1" : relayH4 ? "1" : "0");
    polynomCRelayAnswer.append(relayH3 ? "1" : "0");
    polynomCRelayAnswer.append(relayH2 ? "1" : "0");
    polynomCRelayAnswer.append(relayH1 ? "1" : "0");
    polynomCRelayAnswer.append("1");
    if (polynomCAnswer == polynomCRelayAnswer) {
        message->append("С) Ответ верный (+2 балла)");
        core->changeScore(2);
    } else {
        message->append("С) Ответ неверный (-2 балла)");
        core->changeScore(-2);
    }
    return true;
}
