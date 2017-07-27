#pragma once


#include <QDialog>

#include <QuestionAndAnswerFacilitator.h>
#include <WheelOfJeopardyTypes.h>


// Forward declarations
namespace Ui
{
    class JeopardyBoard;
}


class JeopardyBoard : public QDialog
{
    Q_OBJECT

public:
    JeopardyBoard( QWidget* parent = 0 );
    ~JeopardyBoard();

signals:
    // To Wheel of Fortune Board
    void passBackControl();

public slots:
    // From Wheel of Fortune Board
    void onRoundSwitch();
    void onCategoryChosen( Types::Player, Types::Category );
    // From Question Dialog
    void onAnswerSubmitted( QString, bool );

protected:
    // Actual UI
    Ui::JeopardyBoard* m_ui;

    // Update category headers
    void updateCategories();

    // Round indicator
    bool m_firstRound;

    // Reset after round switch
    void resetForSecondRound();

    // QAF to aid in question and answer selection
    QuestionAndAnswerFacilitator m_qaf;

    // Helper function to update board display
    void updateBoard( Types::Category category );

    // Current player answering question
    Types::Player m_currentPlayer;

    // Current answer for question
    QString m_currentAnswer;

    // Current point values
    Types::FirstRoundPointValue m_currentFirstRoundPointValue;
    Types::SecondRoundPointValue m_currentSecondRoundPointValue;
};
