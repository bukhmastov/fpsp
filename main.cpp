#include "mainwindow.h"
#include <QApplication>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow window;
    try {
        if (argc > 1) {
            int seed = atoi(argv[1]);
            if (seed > 0) {
                window.setSeed(seed);
            }
        }
    } catch (...) {}
    window.setWindowTitle("Исследование методов формирования псевдослучайных последовательностей");
    window.setWindowIcon(QIcon(":icons/icon.png"));
    window.show();
    return app.exec();
}
