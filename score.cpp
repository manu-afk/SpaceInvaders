#include "score.h"
#include <QFont>

Score::Score()
{
    score = 0;
    setPlainText(QString("Score : ") + QString::number(score));
    setDefaultTextColor(Qt::white);
    setFont(QFont("arial",20));
}

void Score::increaseScore(int points){
    this->score += points;
    setPlainText(QString("Score : ") + QString::number(score));

}
