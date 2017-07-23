#include <JeopardyBoard.h>
#include <QuestionDialog.h>
#include <PointManager.h>

#include <ui_JeopardyBoard.h>


JeopardyBoard::JeopardyBoard( QWidget* parent )
    : QDialog( parent ),
      m_ui( new Ui::JeopardyBoard ),
      m_qaf(),
      m_currentAnswer( "" )
{
    // Parent the actual UI
    m_ui->setupUi( this );
}


JeopardyBoard::~JeopardyBoard()
{
    delete m_ui;
}


void JeopardyBoard::onCategoryChosen( Types::Player player, Types::Category category )
{
    // Get next question and answer
    QPair< QString, QString > questionAndAnswerPair = m_qaf.getNextQuestionAndAnswer( category );

    // Store current answer
    m_currentAnswer = questionAndAnswerPair.second;

    // Store current player
    m_currentPlayer = player;

    // If valid question, display and update Board
    if ( questionAndAnswerPair.first != "" )
    {
        // Update board
        updateBoard( category );

        // Create new question dialog to show
        QuestionDialog* questionDialog = new QuestionDialog( this,
                                                             questionAndAnswerPair.first );

        // Connect answer submission signal and slot
        connect( questionDialog, SIGNAL( answerSubmitted( const QString& ) ), this, SLOT( onAnswerSubmitted( const QString& ) ) );

        // Display QuestionDialog to user
        questionDialog->show();
    }
    else
    {
        // Just give control back for now?
        emit passBackControl();
    }
}


void JeopardyBoard::updateBoard( Types::Category category )
{
    // Iterate over rows within column (category), starting at 1
    // to skip the "header" row where the categories are displayed
    for( quint8 i = 1; i < m_ui->jeopardyBoardTableWidget->rowCount(); ++i )
    {
        // Get the table widget item
        auto item = m_ui->jeopardyBoardTableWidget->item( i, (int)category );

        // See if it has text
        if( item && (item->text() != "") )
        {
            // Set the text to blank to show question used
            item->setText( "" );

            // Get the point value accounting for "header" row again
            m_currentFirstRoundPointValue = (Types::FirstRoundPointValue)(i - 1);

            break;
        }
    }
}


void JeopardyBoard::onAnswerSubmitted( QString answer )
{
    // Figure out if correct
    bool correct = !(bool)m_currentAnswer.compare( answer, Qt::CaseInsensitive );

    // Get the Point Manager
    PointManager* pm = PointManager::instance();

    // Add or subtract points accordingly
    if( correct )
        pm->addPoints( m_currentPlayer, m_currentFirstRoundPointValue );
    else
        pm->subtractPoints( m_currentPlayer, m_currentFirstRoundPointValue );

    // Pass back control
    emit passBackControl();
}
