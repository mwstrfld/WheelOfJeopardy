#include "WheelOfFortuneBoard.h"
#include "ui_WheelOfFortuneBoard.h"


WheelOfFortuneBoard::WheelOfFortuneBoard( QWidget* parent )
    : QMainWindow( parent ),
      ui( new Ui::WheelOfFortuneBoard )
{
    ui->setupUi( this );
}


WheelOfFortuneBoard::~WheelOfFortuneBoard()
{
    delete ui;
}
