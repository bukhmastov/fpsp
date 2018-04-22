#include "static.h"
#include <QString>
#include <QChar>

int Static::scoreInitial = 50;
int Static::score4quetion = 2;
int Static::score4task = 1;

QString Static::getMSequence(/* polynom 1+x^3 = 1001 */QString poly, QString args, int n) {
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
