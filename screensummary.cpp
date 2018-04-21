#include "screensummary.h"
#include "ui_screensummary.h"
#include <ctime>

ScreenSummary::ScreenSummary(QWidget *parent) : QFrame(parent), ui(new Ui::ScreenSummary) {
    ui->setupUi(this);
}

ScreenSummary* ScreenSummary::get(Core *core) {
    ScreenSummary *screen = new ScreenSummary;
    QString mark = "";
    if (core->getScore() >= 85) {
        mark = "Отлично";
    } else if (core->getScore() >= 68) {
        mark = "Хорошо";
    } else if (core->getScore() >= 50) {
        mark = "Удовлетворительно";
    } else {
        mark = "Неудовлетворительно";
    }
    time_t now = time(0);
    tm *ltm = localtime(&now);
    QString date = QString::number(ltm->tm_mday) + "." + QString::number(1 + ltm->tm_mon) + "." + QString::number(1900 + ltm->tm_year) + " " + QString::number(ltm->tm_hour) + ":" + QString::number(ltm->tm_min);
    //delete ltm;
    screen->ui->score->setText(QString::number(core->getScore()));
    screen->ui->mark->setText(mark);
    screen->ui->date->setText(date);
    return screen;
}

ScreenSummary::~ScreenSummary() {
    delete ui;
}
