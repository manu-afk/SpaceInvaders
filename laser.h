#ifndef LASER_H
#define LASER_H
#include <QGraphicsRectItem>
#include <QObject>

class Laser : public QObject, public QGraphicsRectItem

{
    Q_OBJECT
    int width;
    int height;
public:
    Laser(int, int);
private slots:
    void move();

};



#endif // LASER_H
