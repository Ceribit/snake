#include <QApplication>
#include "gameview.h"



int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    GameView* game;
    game = new GameView();
    game->show();
    return app.exec();
}
