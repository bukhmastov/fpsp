#ifndef WINDOWCONTROLLER_H
#define WINDOWCONTROLLER_H

#include <QString>
#include <QWidget>

class WindowController {
public:
    virtual void setWidget(QWidget*) = 0;
    virtual void setStep(int, QString) = 0;
    virtual void setMaxProgress(int) = 0;
    virtual void setProgress(int) = 0;
    virtual void setNextEnabled(bool) = 0;
    virtual void setResetEnabled(bool) = 0;
    virtual void setScore(int) = 0;
};

#endif // WINDOWCONTROLLER_H
