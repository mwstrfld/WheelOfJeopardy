#include "WheelOfFortuneBoard.h"
#include <QApplication>


int main( int argc, char* argv[] )
{
    QApplication app( argc, argv );

    WheelOfFortuneBoard wofb;
    wofb.show();

    return app.exec();
}
