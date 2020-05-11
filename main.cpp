#include "mainwindow.h"
#include <QApplication>
#include "gameview.h"
bool laserOnScreen;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GameView *gv = new GameView();
    gv->show();
    return a.exec();
}
