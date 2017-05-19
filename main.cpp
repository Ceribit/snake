#include <QApplication>
#include "gameview.h"

GameView* game;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    game = new GameView();
    game->show();
    return app.exec();
}
