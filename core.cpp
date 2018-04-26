#include "static.h"
#include "core.h"
#include "windowcontroller.h"
#include "task.h"
#include "screenwelcome.h"
#include "screenabout.h"
#include "screendescription.h"
#include "screenquestion.h"
#include "screensummary.h"
#include "task/screentask1.h"
#include "task/screentask2.h"
#include "task/screentask3.h"
#include "task/screentask4.h"
#include "task/screentask5.h"
#include "task/screentask6.h"
#include "task/screentask7.h"
#include "task/screentask8.h"
#include "task/screentask9.h"
#include "task/screentask10.h"
#include <iostream>
#include <time.h>
#include <algorithm>

Core::Core() {}

void Core::init(WindowController *window) {
    this->window = window;
}

void Core::generate() {
    generate(time(NULL));
}

void Core::generate(unsigned int seed) {
    // clear questions
    for (Question* question : questions) {
        delete question;
    }
    questions.clear();
    // clear tasks
    for (Task* task : tasks) {
        delete task;
    }
    tasks.clear();
    // reset progress
    questionsOrder.clear();
    currentTask = 0;
    score = Static::scoreInitial;
    // set seed for random
    srand(seed);
    // ------------------------------
    // HERE GOES DEFINITIONS OF QUESTIONS
    // EVERY QUESTION SHOULD BE ADDED TO QUESTIONS VECTOR BELOW
    // SHOULD BE MINIMUM 10 QUESTIONS
    // ------------------------------
    questions.push_back(new Question("База непрерывного сигнала - это", std::vector<QString>{"Число составляющих при разложении x(t) в обобщенный ряд Фурье с заданной точностью", "Число составляющих при разложении сигнала x(t) в ряд Котельникова", "Число составляющих при аналого-цифровом преобразовании x(t) с заданной точностью", "Число составляющих при разложении сигнала x(t) в обобщенный ряд Фурье", "Число независимых отсчетов при аналого-цифровом преобразовании сигнала x(t)"}));
    questions.push_back(new Question("Для формирования M-последовательности периода N=p^(S) - 1 полином h(x) степени S должен быть:", std::vector<QString>{"примитивным", "неприводимым", "минимальным", "сопряженным", "нормированным"}));
    questions.push_back(new Question("Какой вид ненормированной корреляционной функции последовательностей Баркера имеет боковые выбросы {0, +1, -1} ?", std::vector<QString>{"апериодическая автокорреляционная функция", "периодическая взаимокорреляционная функция", "апериодическая взаимокорреляционная функция", "периодическая автокорреляционная функция", "периодическая корреляционная функция"}));
    questions.push_back(new Question("Какой максимальный период имеют известные последовательности Баркера?", std::vector<QString>{"13", "11", "15", "14", "18"}));
    questions.push_back(new Question("Период последовательностей Уолша N определяется выражением (k - натуральное число):", std::vector<QString>{"2^k", "2^k - 1", "2^(k-1) - 1", "2^k + 1", "2^(k+1) - 1"}));
    questions.push_back(new Question("Число V различных последовательностей Уолша периода N равно:", std::vector<QString>{"2^k", "2^k - 1", "2^(k-1) - 1", "2^k + 1", "2^(k+1) - 1"}));
    questions.push_back(new Question("Корни примитивных полиномов h1(x), h2(x), образующих предпочтительную пару М-последовательностей, связаны соотношением:", std::vector<QString>{"S(k) = 2^int[(k+2)/2] + 1", "S(k) = 2^int[k/2] + 1", "S(k) = 2^int[(k-2)/2] - 1 ", "S(k) = 2^int[(k-2)/2] + 1", "S(k) = 2^int[k/2] - 1"}));
    questions.push_back(new Question("Определить степень проверочного полинома для последовательностей Голда периода N = 511", std::vector<QString>{"deg h(x) = 18", "deg h(x) = 27", "deg h(x) = 12", "deg h(x) = 9", "deg h(x) = 16"}));
    questions.push_back(new Question("Определить степень проверочного полинома для последовательностей малого множества Касами периода N = 255", std::vector<QString>{"12", "8", "20", "24", "16"}));
    questions.push_back(new Question("Определить степень проверочного полинома для последовательностей большого множества Касами периода N = 1023", std::vector<QString>{"25", "15", "20", "30", "10"}));
    // ------------------------------
    unsigned int size = questions.size() < 10 ? questions.size() : 10;
    while (true) {
        int current = rand() % questions.size();
        if (!(std::find(questionsOrder.begin(), questionsOrder.end(), current) != questionsOrder.end())) {
            questionsOrder.push_back(current);
        }
        if (questionsOrder.size() >= size) {
            break;
        }
    }
    // ------------------------------
    // HERE GOES DEFINITIONS OF TASKS
    // EVERY TASK SHOULD BE ADDED TO TASKS VECTOR BELOW
    // TASK'S VIEWS DEFINES AT Core::getView(int id)
    // ------------------------------
    // intro part
    tasks.push_back(new Task(0,  0,  "Лабораторная работа"));
    tasks.push_back(new Task(1,  0,  "Лабораторная работа"));
    tasks.push_back(new Task(2,  0,  "Лабораторная работа"));
    // questions part
    tasks.push_back(new Task(3,  1,  "Входной контрольный опрос: вопрос 1",  false));
    tasks.push_back(new Task(4,  1,  "Входной контрольный опрос: вопрос 2",  false));
    tasks.push_back(new Task(5,  1,  "Входной контрольный опрос: вопрос 3",  false));
    tasks.push_back(new Task(6,  1,  "Входной контрольный опрос: вопрос 4",  false));
    tasks.push_back(new Task(7,  1,  "Входной контрольный опрос: вопрос 5",  false));
    tasks.push_back(new Task(8,  1,  "Входной контрольный опрос: вопрос 6",  false));
    tasks.push_back(new Task(9,  1,  "Входной контрольный опрос: вопрос 7",  false));
    tasks.push_back(new Task(10, 1,  "Входной контрольный опрос: вопрос 8",  false));
    tasks.push_back(new Task(11, 1,  "Входной контрольный опрос: вопрос 9",  false));
    tasks.push_back(new Task(12, 1,  "Входной контрольный опрос: вопрос 10", false));
    // tasks part
    tasks.push_back(new Task(13, 2,  "Формирование М-последовательности периода N = 7"));
    tasks.push_back(new Task(14, 3,  "Формирование М-последовательности периода N = 2^s - 1"));
    tasks.push_back(new Task(15, 4,  "Формирование последовательностей Баркера"));
    tasks.push_back(new Task(16, 5,  "Формирование последовательностей Уолша"));
    tasks.push_back(new Task(17, 6,  "Формирование предпочтительных пар М-последовательностей"));
    tasks.push_back(new Task(18, 7,  "Формирование последовательностей Голда"));
    tasks.push_back(new Task(19, 8,  "Формирование последовательностей малого множества Касами"));
    tasks.push_back(new Task(20, 9,  "Формирование последовательностей большого множества Касами"));
    tasks.push_back(new Task(21, 10, "Формирование редецимированных последовательностей"));
    tasks.push_back(new Task(22, 11, "Формирование троичных последовательностей"));
    // summary part
    tasks.push_back(new Task(99, 0, "Результат", false));
    // ------------------------------
    window->setMaxProgress(tasks.size());
    window->setNextEnabled(true);
    window->setResetEnabled(true);
}

ScreenController* Core::getView(int id) {
    // ------------------------------
    // HERE GOES VIEWS OF TASKS
    // EVERY TASK VIEW SHOULD BE ADDED BELOW
    // ------------------------------
    switch (id) {
        // intro part
        case 0:  return new ScreenWelcome; break;
        case 1:  return new ScreenAbout; break;
        case 2:  return new ScreenDescription; break;
        // questions part
        case 3:  return ScreenQuestion::get(this, questions.at(questionsOrder.at(0))); break;
        case 4:  return ScreenQuestion::get(this, questions.at(questionsOrder.at(1))); break;
        case 5:  return ScreenQuestion::get(this, questions.at(questionsOrder.at(2))); break;
        case 6:  return ScreenQuestion::get(this, questions.at(questionsOrder.at(3))); break;
        case 7:  return ScreenQuestion::get(this, questions.at(questionsOrder.at(4))); break;
        case 8:  return ScreenQuestion::get(this, questions.at(questionsOrder.at(5))); break;
        case 9:  return ScreenQuestion::get(this, questions.at(questionsOrder.at(6))); break;
        case 10: return ScreenQuestion::get(this, questions.at(questionsOrder.at(7))); break;
        case 11: return ScreenQuestion::get(this, questions.at(questionsOrder.at(8))); break;
        case 12: return ScreenQuestion::get(this, questions.at(questionsOrder.at(9))); break;
        // tasks part
        case 13: return new ScreenTask1; break;
        case 14: return new ScreenTask2; break;
        case 15: return new ScreenTask3; break;
        case 16: return new ScreenTask4; break;
        case 17: return new ScreenTask5; break;
        case 18: return new ScreenTask6; break;
        case 19: return new ScreenTask7; break;
        case 20: return new ScreenTask8; break;
        case 21: return new ScreenTask9; break;
        case 22: return new ScreenTask10; break;
        // summary part
        case 99: return ScreenSummary::get(this); break;
        default: return NULL;
    }
    // ------------------------------
}

void Core::next() {
    next(false);
}

void Core::next(bool force) {
    QString message;
    if (currentTask == 0 || window->getWidget() == nullptr || window->getWidget()->validate(this, &message)) {
        if (force || (score >= 0 && currentTask < tasks.size())) {
            currentTask++;
            Task *task = tasks.at(currentTask - 1);
            window->setStep(task->getNumber(), task->getTitle());
            window->setProgress(currentTask);
            window->setScore(score);
            window->setMessage(message);
            window->setWidget(getView(task->getId()));
            window->setNextEnabled(task->getNextButtonActive());
        } else {
            currentTask = tasks.size() - 1;
            next(true);
        }
    }
}

void Core::reset() {
    generate();
    next();
}

void Core::changeScore(int delta) {
    this->score += delta;
}

int Core::getScore() {
    return score;
}
