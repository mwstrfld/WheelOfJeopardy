#include <QApplication>
#include <QDateTime>

#include <WheelOfFortuneBoard.h>


int main( int argc, char* argv[] )
{
    // Create the application
    QApplication app( argc, argv );

    // Seed the random number generator for wheel spinning
    qsrand( (uint)QDateTime::currentSecsSinceEpoch() );

    // Instantiate main GUI and show
    WheelOfFortuneBoard wofb;
    wofb.show();

    // Execute the app
    return app.exec();
}
