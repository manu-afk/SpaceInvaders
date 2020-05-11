#ifndef UFO_H
#define UFO_H
#include <QGraphicsPixmapItem>
#include <QObject>


class Ufo : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    bool isFirstSpawn;
public:
    Ufo();
    ~Ufo();

signals:
    void killed(int);
private slots:
    void move();
    void show();

};

#endif // UFO_H
