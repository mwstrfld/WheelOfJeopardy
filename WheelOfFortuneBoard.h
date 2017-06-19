#pragma once


#include <QMainWindow>


namespace Ui
{
    class WheelOfFortuneBoard;
}


class WheelOfFortuneBoard : public QMainWindow
{
    Q_OBJECT

public:
    WheelOfFortuneBoard( QWidget* parent = 0 );
    ~WheelOfFortuneBoard();

protected:
    Ui::WheelOfFortuneBoard *ui;
};
