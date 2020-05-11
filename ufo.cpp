#include "ufo.h"
#include <QTimer>

#include <iostream>
using namespace std;

Ufo::Ufo()
{
    setPixmap(QPixmap(":/vaisseau.png"));
    setPos(-50, -50);
    QTimer *timer = new QTimer();
    srand(time(NULL));
    int myrand = rand()%15000 + 5000;
    connect(timer, SIGNAL(timeout()), this, SLOT(show()));
    timer->start(myrand);
    isFirstSpawn = true;

}

Ufo::~Ufo(){
    emit killed(100);
}

void Ufo::show(){
    setPos(0, 200);
    if(isFirstSpawn){
        QTimer *timer = new QTimer();
        connect(timer, SIGNAL(timeout()), this, SLOT(move()));
        timer->start(50);
    }
    isFirstSpawn = false;
}

void Ufo::move(){
    setPos(x()+10, y());
}
