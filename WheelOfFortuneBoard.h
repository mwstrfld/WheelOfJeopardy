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
    void roundSwitch();
    void categoryChosen( Types::Player, Types::Category );

protected slots:
    // Spin button handler
    void onSpinButtonPressed();

    // Name change handlers
    void onPlayer1NameChange( const QString& );
    void onPlayer2NameChange( const QString& );
    void onPlayer3NameChange( const QString& );

    // From Category Selector Dialog
    void onCategorySelected( Types::Category );

    // From Jeopardy Board
    void receivedControlBack( bool );

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
    void selectCategory( bool playerChoice = true );

    // Helper for updating status label
    void updateStatusLabel();

    // Round indicator
    bool m_firstRound;

    // The Jeopardy Board
    JeopardyBoard* m_jeopardyBoard;
};
