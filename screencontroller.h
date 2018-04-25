#ifndef SCREENCONTROLLER_H
#define SCREENCONTROLLER_H

#include <QFrame>
#include <QString>
#include <map>

class Core;
class ScreenController : public QFrame {
public:
    explicit ScreenController(QWidget* parent = Q_NULLPTR) : QFrame(parent) {}
    virtual bool validate(Core*, QString*) = 0;

protected:
    static std::map<QString, QString> store;
};

#endif // SCREENCONTROLLER_H
