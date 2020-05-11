#ifndef TURRET_H
#define TURRET_H
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QMediaPlayer>
#include <QObject>

class Turret : public QObject ,public QGraphicsPixmapItem
{
    Q_OBJECT
    QMediaPlayer *laserSound;
    bool leftPressed;
    bool rightPressed;
private slots:
    void manageMoveKeys();
public:
    Turret(QString sprite);
    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent* event);
};

#endif // TURRET_H
