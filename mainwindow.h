#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include "core.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow, public WindowController {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void init(Core);
    void setSeed(unsigned int);
    void setWidget(QWidget*);
    void setStep(int, QString);
    void setMaxProgress(int);
    void setProgress(int);
    void setNextEnabled(bool);
    void setResetEnabled(bool);
    void setScore(int);

private slots:
    void on_nextButton_clicked(); // next question/step
    void on_resetButton_clicked(); // reset progress, start from the beginning (eg step -> 0)

private:
    Ui::MainWindow *ui;
    Core *core;
    void clearWidgets(QLayout*);
};

#endif // MAINWINDOW_H
