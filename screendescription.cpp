#include "screendescription.h"
#include "ui_screendescription.h"

ScreenDescription::ScreenDescription(QWidget *parent) : QFrame(parent), ui(new Ui::ScreenDescription) {
    ui->setupUi(this);
}

ScreenDescription::~ScreenDescription() {
    delete ui;
}
