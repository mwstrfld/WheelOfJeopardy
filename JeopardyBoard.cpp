#include <JeopardyBoard.h>
#include <QuestionDialog.h>
#include <PointManager.h>

#include <ui_JeopardyBoard.h>


JeopardyBoard::JeopardyBoard( QWidget* parent )
    : QDialog( parent ),
      m_ui( new Ui::JeopardyBoard ),
      m_firstRound( true ),
      m_qaf(),
      m_currentAnswer( "" ),
      m_currentFirstRoundPointValue( Types::TwoHundred1 ),
      m_currentSecondRoundPointValue( Types::FourHundred2 )
{
    // Parent the actual UI
    m_ui->setupUi( this );

    // Update the category headers
    updateCategories();
}


JeopardyBoard::~JeopardyBoard()
{
    delete m_ui;
}


void JeopardyBoard::onRoundSwitch()
{
    // Set to second round
    m_firstRound = false;

    // Reset the board
    resetForSecondRound();

    // Reset questions and answers
    m_qaf.resetForSecondRound();

    // Reset categories
    updateCategories();
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
        connect( questionDialog, SIGNAL( answerSubmitted(QString) ), this, SLOT( onAnswerSubmitted(QString) ) );

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
            if( m_firstRound )
                m_currentFirstRoundPointValue = (Types::FirstRoundPointValue)(i - 1);
            else
                m_currentSecondRoundPointValue = (Types::SecondRoundPointValue)(i - 1);

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
    if( m_firstRound )
    {
        if( correct )
            pm->addPoints( m_currentPlayer, m_currentFirstRoundPointValue );
        else
            pm->subtractPoints( m_currentPlayer, m_currentFirstRoundPointValue );
    }
    else
    {
        if( correct )
            pm->addPoints( m_currentPlayer, m_currentSecondRoundPointValue );
        else
            pm->subtractPoints( m_currentPlayer, m_currentSecondRoundPointValue );
    }

    // Pass back control
    emit passBackControl();
}


void JeopardyBoard::updateCategories()
{
    // Initialize string for categories
    QString catStr = "";

    for( int j = 0; j < m_ui->jeopardyBoardTableWidget->columnCount(); ++j )
    {
        catStr = "Category " + QString::number( j+1 ) + ":\n";
        catStr += m_qaf.getCategories().at( j );
        auto item = m_ui->jeopardyBoardTableWidget->item( 0, j );
        item->setText( catStr );
    }
}


void JeopardyBoard::resetForSecondRound()
{
    // Initialize second round multiplier
    quint32 mult = 400;

    // Reset to second round scoring
    for( int j = 0; j < m_ui->jeopardyBoardTableWidget->columnCount(); ++j )
    {
        // Skip "header" rows
        for( int i = 1; i < m_ui->jeopardyBoardTableWidget->rowCount(); ++i )
        {
            auto item = m_ui->jeopardyBoardTableWidget->item( i, j );
            if( item )
            {
                item->setText( QString::number( mult * i ) );
            }
        }
    }
}
