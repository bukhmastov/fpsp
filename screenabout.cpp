#include "screenabout.h"
#include "ui_screenabout.h"

ScreenAbout::ScreenAbout(QWidget *parent) : QFrame(parent), ui(new Ui::ScreenAbout) {
    ui->setupUi(this);
}

ScreenAbout::~ScreenAbout() {
    delete ui;
}
