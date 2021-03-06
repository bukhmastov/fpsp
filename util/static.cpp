#include "static.h"
#include <QString>
#include <QChar>

QString Static::worktype = "Лабораторная работа"; // "Лабораторная работа" "Практическое занятие"
QString Static::worktypeShort = "ЛР"; // "ЛР" "ПЗ"

int Static::scoreInitial = 50;
int Static::score4quetion = 2;
int Static::score4task = 1;
QString Static::messageAnswerRight = "Ответ верный (+2 балла)";
QString Static::messageAnswerWrong = "Ответ неверный (-2 балла)";

QString Static::getMSequence(/* polynom x^3+x+1 = 1011 */QString poly, int n) {
    QString args;
    for (int i = 0; i < poly.size() - 1; i++) {
        args.append("1");
    }
    return getMSequence(poly, args, n);
}

QString Static::getMSequence(/* polynom 1+x+x^3 = 1101 */QString poly, QString args, int n) {
    QString mSeg;
    mSeg.reserve(n);
    mSeg.append(args);
    poly.chop(1);
    for (int i = args.size(); i < n; i++) {
        int sum = 0;
        for (int j = 0; j < args.size(); j++) {
            if ((poly.at(args.size() - j - 1) == QChar('1')) && (mSeg.at(i - j - 1) == QChar('1'))) {
                sum++;
            }
        }
        mSeg.append(QString::number(sum % 2));
    }
    mSeg.squeeze();
    return mSeg;
}

QString Static::getXOR(QString p1, QString p2) {
    QString p12;
    for (int i = 0; i < p1.size(); i++) {
        p12.append(p1.at(i) == p2.at(i) ? "0" : "1");
    }
    return p12;
}

QString Static::getReadablePolynom(QString poly) {
    QString readable = "";
    int size = poly.size();
    for (int i = 0; i < size; i++) {
        if (poly.at(i) == QChar('1')) {
            if (!readable.isEmpty()) {
                readable += "+";
            }
            if (i == 0) {
                readable += "1";
            }
            if (i == 1) {
                readable += "x";
            }
            if (i > 1) {
                readable += "x<sup>" + QString::number(i) + "</sup>";
            }
        }
    }
    return readable;
}

QString Static::multiplyPolynoms(QString p1, QString p2, int n) {
    QString p12;
    std::vector<int> p12v;
    for (int i = 0; i < p1.size() + p2.size() - 1; i++) {
        p12v.push_back(0);
    }
    for (int i = 0; i < p1.size(); i++) {
        for (int j = 0; j < p2.size(); j++) {
            p12v.at(i + j) += QString(p1.at(i)).toInt() * QString(p2.at(j)).toInt();
        }
    }
    for (unsigned int i = 0; i < p12v.size(); i++) {
        p12.append(QString::number(p12v.at(i) % n));
    }
    return p12;
}
