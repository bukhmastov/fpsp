#include "screenwelcome.h"
#include "ui_screenwelcome.h"

ScreenWelcome::ScreenWelcome(QWidget *parent) : QFrame(parent), ui(new Ui::ScreenWelcome) {
    ui->setupUi(this);
}

ScreenWelcome::~ScreenWelcome() {
    delete ui;
}
