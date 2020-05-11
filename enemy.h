#ifndef ENEMY_H
#define ENEMY_H
#include <QGraphicsPixmapItem>
#include <QObject>


class Enemy : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
    int directionMove;
    int frameNumber;
public:
    Enemy(QString sprite);
    ~Enemy();

private slots:
    void move();
    void displayNextFrame();

signals:
    void killed(int);
    void touchTurret();
};


#endif // ENEMY_H
