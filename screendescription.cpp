#include "screendescription.h"
#include "ui_screendescription.h"

ScreenDescription::ScreenDescription(QWidget *parent) : ScreenController(parent), ui(new Ui::ScreenDescription) {
    ui->setupUi(this);
}

ScreenDescription::~ScreenDescription() {
    delete ui;
}

bool ScreenDescription::validate(Core*, QString*) {
    return true;
}
