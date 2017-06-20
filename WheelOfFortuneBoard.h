#pragma once


#include <QMainWindow>


// Forward declarations
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

protected slots:
    // Spin button handler
    void onSpinButtonPressed();

protected:
    // Spin counter
    unsigned short m_spinCount;

    // Actual UI
    Ui::WheelOfFortuneBoard *m_ui;

    // Helper for rotating wheel
    void rotateWheel();
};
