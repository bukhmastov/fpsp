#ifndef CORE_H
#define CORE_H

#include "windowcontroller.h"
#include "screencontroller.h"
#include "question.h"
#include "task.h"

class Core {
public:
    Core();
    void init(WindowController*);
    void generate();
    void generate(unsigned int);
    void next();
    void next(bool);
    void reset();
    void changeScore(int);
    int getScore();

private:
    ScreenController* getView(int);

    WindowController *window;

    std::vector<Question*> questions;
    std::vector<Task*> tasks;

    std::vector<int> questionsOrder;
    unsigned int currentTask = 0;
    int score = 50;
};

#endif // CORE_H
