#ifndef SCORE_H
#define SCORE_H
#include <QGraphicsTextItem>
#include <QObject>

class Score : public QGraphicsTextItem

{
    Q_OBJECT
    int score;
public:
    Score();
public slots:
    void increaseScore(int points);
};

#endif // SCORE_H
