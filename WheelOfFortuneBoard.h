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
    // To Jeopardy Board
    void categoryChosen( Types::Player, Types::Category );

protected slots:
    // Spin button handler
    void onSpinButtonPressed();

    // Name change handlers
    void onPlayer1NameChange( const QString& name );
    void onPlayer2NameChange( const QString& name );
    void onPlayer3NameChange( const QString& name );

    // From Jeopardy Board
    void receivedControlBack();

protected:
    // Spin counter
    unsigned short m_spinCount;

    // Actual UI
    Ui::WheelOfFortuneBoard *m_ui;

    // Helper for rotating wheel
    void rotateWheel();

    // Original wheel image pixmap
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

    // Helpers for a few sectors
    void loseTurn();
    void freeTurn();
    void bankrupt();

    // Helper for updating status label
    void updateStatusLabel();

    // The Jeopardy Board
    JeopardyBoard* m_jeopardyBoard;
};
