#include "screentask5.h"
#include "ui_screentask5.h"
#include "static.h"

ScreenTask5::ScreenTask5(QWidget *parent) : ScreenController(parent), ui(new Ui::ScreenTask5) {
    ui->setupUi(this);
    init();
}

ScreenTask5::~ScreenTask5() {
    delete ui;
}

void ScreenTask5::init() {
    n = rand() % 2 + 5;
    if (n == 5) {
        switch (rand() % 6) {
        case 0: polynom1 = "101001"; polynom2 = "111011"; break; // 1  5
        case 1: polynom1 = "101111"; polynom2 = "100101"; break; // 3  15
        case 2: polynom1 = "111011"; polynom2 = "111101"; break; // 5  7
        case 3: polynom1 = "111101"; polynom2 = "101001"; break; // 7  1
        case 4: polynom1 = "110111"; polynom2 = "101111"; break; // 11 3
        case 5: polynom1 = "100101"; polynom2 = "110111"; break; // 15 11
        }
    }
    if (n == 6) {
        switch (rand() % 6) {
        case 0: polynom1 = "1100001"; polynom2 = "1110011"; break; // 1  5
        case 1: polynom1 = "1110011"; polynom2 = "1011011"; break; // 5  11
        case 2: polynom1 = "1011011"; polynom2 = "1000011"; break; // 11 31
        case 3: polynom1 = "1101101"; polynom2 = "1100001"; break; // 13 1
        case 4: polynom1 = "1100111"; polynom2 = "1101101"; break; // 23 13
        case 5: polynom1 = "1000011"; polynom2 = "1100111"; break; // 31 23
        }
    }
    QString title;
    title.append("Для полинома степени S=");
    title.append(QString::number(n));
    title.append(" h<sub>1</sub>(x)=");
    title.append(polynom1);
    title.append(" определить полином h<sub>2</sub>(x) и сформировать первые 15 символов М-последовательности, составляющей предпочтительную пару с последовательностью, задаваемой полиномом h<sub>1</sub>(x). Расчет проводить для единичных исходных символов.");
    ui->title->setText(title);
}

bool ScreenTask5::validate(Core* core, QString* message) {
    QString arg;
    for (int i = 0; i < n; i++) {
        arg.append("1");
    }
    QString mSeq = Static::getMSequence(polynom2, arg, 15);
    if (polynom2 == ui->inputHX->text() && mSeq == ui->inputF->text()) {
        message->append("Ответ верный (+2 балла)");
        core->changeScore(2);
    } else {
        message->append("Ответ неверный (-2 балла)");
        core->changeScore(-2);
    }
    return true;
}
