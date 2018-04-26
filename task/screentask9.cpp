#include "screentask9.h"
#include "ui_screentask9.h"
#include <map>

ScreenTask9::ScreenTask9(QWidget *parent) : ScreenController(parent), ui(new Ui::ScreenTask9) {
    ui->setupUi(this);
    init();
}

ScreenTask9::~ScreenTask9() {
    delete ui;
}

void ScreenTask9::init() {
    QString ip;
    switch (rand() % 5) {
    case 0: ip = "0121-"; break;
    case 1: ip = "1202-"; break;
    case 2: ip = "2010-"; break;
    case 3: ip = "1210-"; break;
    case 4: ip = "2021-"; break;
    }
    std::map<int, int> ir;
    std::map<std::pair<int, int>, int> sd;
    sd[std::make_pair(0, 0)] = 0;
    sd[std::make_pair(0, 1)] = 1;
    sd[std::make_pair(0, 2)] = 1;
    sd[std::make_pair(1, 0)] = 1;
    sd[std::make_pair(1, 1)] = 0;
    sd[std::make_pair(1, 2)] = 1;
    sd[std::make_pair(2, 0)] = 1;
    sd[std::make_pair(2, 1)] = 1;
    sd[std::make_pair(2, 2)] = 0;
    sd[std::make_pair(3, 0)] = 0;
    sd[std::make_pair(3, 1)] = 0;
    sd[std::make_pair(3, 2)] = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            int t = ip.mid(j, 1).toInt();
            ir[i * 5 + j] = sd[std::make_pair(t, i)];
        }
        ir[i * 5 + 4] = 0;
    }
    for (unsigned int i = 0; i < ir.size(); i++) {
        sequence.append(QString::number(ir.at(i)));
    }
    ui->titleIp->setText(ui->titleIp->text().replace("%ip%", ip));
}

bool ScreenTask9::validate(Core* core, QString* message) {
    if (ui->inputFRP->text() == sequence) {
        message->append("Ответ верный (+2 балла)");
        core->changeScore(2);
    } else {
        message->append("Ответ неверный (-2 балла)");
        core->changeScore(-2);
    }
    return true;
}
