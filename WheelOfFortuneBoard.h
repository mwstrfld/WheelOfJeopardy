#pragma once


#include <QMainWindow>

#include <WheelOfJeopardyTypes.h>


// Forward declarations
class JeopardyBoard;
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

signals:
    void categoryChosen( Types::Category category );

protected slots:
    // Spin button handler
    void onSpinButtonPressed();

    // Name change handlers
    void onPlayer1NameChange( const QString& name );
    void onPlayer2NameChange( const QString& name );
    void onPlayer3NameChange( const QString& name );

protected:
    // Spin counter
    unsigned short m_spinCount;

    // Actual UI
    Ui::WheelOfFortuneBoard *m_ui;

    // Helper for rotating wheel
    void rotateWheel();

    // Original image pixmap
    QPixmap m_originalPixmap;

    // Player names
    QString m_player1Name;
    QString m_player2Name;
    QString m_player3Name;

    // Turn state
    Types::Player m_turnState;

    // Current sector
    Types::Sector m_currentSector;

    // Main action function
    void actUponNewSector();

    // Advance the turn to next player
    void advanceTurn();

    JeopardyBoard* m_jeopardyBoard;
};
