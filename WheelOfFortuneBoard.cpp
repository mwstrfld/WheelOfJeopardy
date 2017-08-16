#include <QDebug>
#include <QMessageBox>

#include <CategorySelectorDialog.h>
#include <JeopardyBoard.h>
#include <PointManager.h>
#include <WheelOfFortuneBoard.h>
#include <ui_WheelOfFortuneBoard.h>


WheelOfFortuneBoard::WheelOfFortuneBoard( QWidget* parent )
    : QMainWindow( parent ),
      m_spinCount( 50 ),
      m_ui( new Ui::WheelOfFortuneBoard ),
      m_originalPixmap(),
      m_player1Name( "Player 1" ),
      m_player2Name( "Player 2" ),
      m_player3Name( "Player 3" ),
      m_turnState( Types::Player1 ),
      m_currentSector( Types::SectorCategory1 ),
      m_firstRound( true ),
      m_jeopardyBoard( 0 )
{
    // Parent the actual UI
    m_ui->setupUi( this );

    // Setup spin count
    m_ui->spinCountLineEdit->setReadOnly( true );
    m_ui->spinCountLineEdit->setText( QString::number( m_spinCount ) );

    // Hide the tokens
    m_ui->player1TokenLabel->setEnabled( false );
    m_ui->player2TokenLabel->setEnabled( false );
    m_ui->player3TokenLabel->setEnabled( false );

    // Show Jeopardy Board
    m_jeopardyBoard = new JeopardyBoard( this );
    m_jeopardyBoard->show();

    // Signal/slot connections
    connect( m_ui->spinButton, SIGNAL( pressed() ), SLOT( onSpinButtonPressed() ) );
    connect( m_ui->player1NameLineEdit, SIGNAL( textChanged(QString) ), SLOT( onPlayer1NameChange(QString) ) );
    connect( m_ui->player2NameLineEdit, SIGNAL( textChanged(QString) ), SLOT( onPlayer2NameChange(QString) ) );
    connect( m_ui->player3NameLineEdit, SIGNAL( textChanged(QString) ), SLOT( onPlayer3NameChange(QString) ) );
    connect( this, SIGNAL( roundSwitch() ), m_jeopardyBoard, SLOT( onRoundSwitch() ) );
    connect( this, SIGNAL( categoryChosen(Types::Player, Types::Category) ), m_jeopardyBoard, SLOT( onCategoryChosen(Types::Player, Types::Category) ) );
    connect( m_jeopardyBoard, SIGNAL( passBackControl() ), this, SLOT( receivedControlBack() ) );

    // Initialize the Scoreboard Player names
    auto player1Item = new QTableWidgetItem( m_player1Name );
    m_ui->scoreboardTableWidget->setItem( 0, 0, player1Item );

    auto player2Item = new QTableWidgetItem( m_player2Name );
    m_ui->scoreboardTableWidget->setItem( 1, 0, player2Item );

    auto player3Item = new QTableWidgetItem( m_player3Name );
    m_ui->scoreboardTableWidget->setItem( 2, 0, player3Item );

    // Initialize the Scoreboard scores
    for( int i = 0; i < m_ui->scoreboardTableWidget->rowCount(); ++i )
    {
        auto scoreItem = new QTableWidgetItem( "0" );
        scoreItem->setTextAlignment( Qt::AlignCenter );
        m_ui->scoreboardTableWidget->setItem( i, 1, scoreItem );
    }

    // Update the status
    updateStatusLabel();

    // Setup original pixmap
    m_originalPixmap = *(m_ui->wheelLabel->pixmap());
}


WheelOfFortuneBoard::~WheelOfFortuneBoard()
{
    delete m_ui;
    delete m_jeopardyBoard;
}


void WheelOfFortuneBoard::rotateWheel()
{
    // Initialize transformation matrix and center of image
    QTransform transform;

    // Translate, rotate, and translate back
    transform.translate( m_ui->wheelLabel->width()/2, m_ui->wheelLabel->height()/2 );
    // Multiple random sector number by -30 degrees (12
    // sectors: 360 / 12 = 30) and we want to rotate clockwise
    transform.rotate( m_currentSector * -30 );
    transform.translate( -m_ui->wheelLabel->width()/2, -m_ui->wheelLabel->height()/2 );

    // Generate a new pixmap after applying transformation/rotation
    auto newPixmap = m_originalPixmap.transformed( transform );

    // Use the original pixmap to get scaling and cropping values
    int widthDiff = (newPixmap.width() - m_originalPixmap.width()) / 2;
    int heightDiff = (newPixmap.height() - m_originalPixmap.height()) / 2;

    // Update with the new pixmap copy
    m_ui->wheelLabel->setPixmap( newPixmap.copy( widthDiff,
                                                 heightDiff,
                                                 m_originalPixmap.width(),
                                                 m_originalPixmap.height() ) );
}


void WheelOfFortuneBoard::onSpinButtonPressed()
{
    if( m_spinCount == 1 )
    {
        if( m_firstRound )
        {
            // Reset spin count
            m_spinCount = 51;
            m_firstRound = false;

            // Let Jeopardy Board know round changed
            emit roundSwitch();
        }
        else
        {
            // End of game
            QString str = "Congratulations! ";

            // Find out winner
            Types::Player winner = PointManager::instance()->getCurrentWinner();

            // Add their name
            switch( winner )
            {
            case Types::Player1:
                str += m_player1Name;
                break;
            case Types::Player2:
                str += m_player2Name;
                break;
            case Types::Player3:
                str += m_player3Name;
                break;
            default:
                break;
            }

            // Finish string
            str += " is the winner!";

            // Display to players
            QMessageBox::question( this,
                                   tr( "The winner is..." ),
                                   str,
                                   QMessageBox::Ok );

            // Close game
            m_jeopardyBoard->close();
            close();
        }
    }

    // Get a random sector number between 0 and 11
    m_currentSector = (Types::Sector)(qrand() % 11);

    // Update the label
    m_ui->spinCountLineEdit->setText( QString::number( --m_spinCount ) );

    // Do the actual rotation
    rotateWheel();

    // Do what sector says
    actUponNewSector();
}


void WheelOfFortuneBoard::onPlayer1NameChange( const QString& name )
{
    // Store Player 1's name
    m_player1Name = name;

    // Update the Scoreboard
    auto item = m_ui->scoreboardTableWidget->item( 0, 0 );
    item->setText( name );

    // Update the status
    updateStatusLabel();
}


void WheelOfFortuneBoard::onPlayer2NameChange( const QString& name )
{
    // Store Player 2's name
    m_player2Name = name;

    // Update the Scoreboard
    auto item = m_ui->scoreboardTableWidget->item( 1, 0 );
    item->setText( name );

    // Update the status
    updateStatusLabel();
}


void WheelOfFortuneBoard::onPlayer3NameChange( const QString& name )
{
    // Store Player 3's name
    m_player3Name = name;

    // Update the Scoreboard
    auto item = m_ui->scoreboardTableWidget->item( 2, 0 );
    item->setText( name );

    // Update the status
    updateStatusLabel();
}


void WheelOfFortuneBoard::actUponNewSector()
{
    // TODO: Implement flow chart from SRS document
    switch( m_currentSector )
    {
    case Types::SectorCategory1:
        emit categoryChosen( m_turnState, Types::Category::Category1 );
        break;
    case Types::LoseTurn:
        loseTurn();
        break;
    case Types::SectorCategory2:
        emit categoryChosen( m_turnState, Types::Category::Category2 );
        break;
    case Types::FreeTurn:
        freeTurn();
        break;
    case Types::SectorCategory3:
        emit categoryChosen( m_turnState, Types::Category::Category3 );
        break;
    case Types::Bankrupt:
        bankrupt();
        break;
    case Types::SectorCategory4:
        emit categoryChosen( m_turnState, Types::Category::Category4 );
        break;
    case Types::PlayerChoice:
        selectCategory( true );
        break;
    case Types::SectorCategory5:
        emit categoryChosen( m_turnState, Types::Category::Category5 );
        break;
    case Types::OpponentChoice:
        selectCategory( false );
        break;
    case Types::SectorCategory6:
        emit categoryChosen( m_turnState, Types::Category::Category6 );
        break;
    case Types::SpinAgain:
    default:
        break;
    }
}


void WheelOfFortuneBoard::loseTurn()
{
    // Which player's token label and count?
    QLabel* tokenLabel = 0;
    QLineEdit* tokenCountLineEdit = 0;
    QString outputStr = "";

    switch( m_turnState )
    {
    case Types::Player1:
        outputStr = m_player1Name;
        tokenLabel = m_ui->player1TokenLabel;
        tokenCountLineEdit = m_ui->player1TokenCountLineEdit;
        break;
    case Types::Player2:
        outputStr = m_player2Name;
        tokenLabel = m_ui->player2TokenLabel;
        tokenCountLineEdit = m_ui->player2TokenCountLineEdit;
        break;
    case Types::Player3:
        outputStr = m_player3Name;
        tokenLabel = m_ui->player3TokenLabel;
        tokenCountLineEdit = m_ui->player3TokenCountLineEdit;
        break;
    default:
        break;
    }

    // If they have a token, do they want to use it?
    if( tokenLabel && tokenLabel->isEnabled() )
    {
        outputStr += ", would you like to use a free turn?";
        int ret = QMessageBox::question( this,
                                         tr( "Use Free Turn?" ),
                                         outputStr,
                                         QMessageBox::Yes | QMessageBox::No );
        if( ret == QMessageBox::Yes )
        {
            if( tokenCountLineEdit )
            {
                // Get the current count
                qint8 tokenCount = tokenCountLineEdit->text().toInt();
                if( tokenCount > 0 )
                {
                    // Subtract a token count and disable if all out
                    if( tokenCount == (qint8)1 )
                        tokenLabel->setEnabled( false );

                    tokenCountLineEdit->setText( QString::number( --tokenCount ) );
                }
            }
        }
        else
            advanceTurn();
    }
    else
        advanceTurn();
}


void WheelOfFortuneBoard::freeTurn()
{
    int count = 0;

    switch( m_turnState )
    {
    case Types::Player1:
        count = m_ui->player1TokenCountLineEdit->text().toInt();
        m_ui->player1TokenCountLineEdit->setText( QString::number( ++count ) );
        m_ui->player1TokenLabel->setEnabled( true );
        break;
    case Types::Player2:
        count = m_ui->player2TokenCountLineEdit->text().toInt();
        m_ui->player2TokenCountLineEdit->setText( QString::number( ++count ) );
        m_ui->player2TokenLabel->setEnabled( true );
        break;
    case Types::Player3:
        count = m_ui->player3TokenCountLineEdit->text().toInt();
        m_ui->player3TokenCountLineEdit->setText( QString::number( ++count ) );
        m_ui->player3TokenLabel->setEnabled( true );
        break;
    default:
        break;
    }

    advanceTurn();
}


void WheelOfFortuneBoard::bankrupt()
{
    // Get the point manager
    auto pm = PointManager::instance();

    // Call bankrupt
    pm->bankrupt( m_turnState );

    // Update score
    auto scoreItem = m_ui->scoreboardTableWidget->item( (int)m_turnState, 1 );
    scoreItem->setText( QString::number( pm->getPlayerPoints( m_turnState ) ) );

    // Advance
    advanceTurn();
}


void WheelOfFortuneBoard::selectCategory( bool playerChoice )
{
    // Create the text to display
    QString str = "";

    // Change based on player or opponent choice
    if( playerChoice )
    {
        switch( m_turnState )
        {
        case Types::Player1:
            str += m_player1Name;
            break;
        case Types::Player2:
            str += m_player2Name;
            break;
        case Types::Player3:
            str += m_player3Name;
            break;
        default:
            break;
        }

        str += ", please choose a category for yourself.";
    }
    else
    {
        // Opponents' choice
        QString playerStr = "";

        switch( m_turnState )
        {
        case Types::Player1:
            str += m_player2Name + " and " + m_player3Name;
            playerStr = m_player1Name;
            break;
        case Types::Player2:
            str += m_player1Name + " and " + m_player3Name;
            playerStr = m_player2Name;
            break;
        case Types::Player3:
            str += m_player1Name + " and " + m_player2Name;
            playerStr = m_player3Name;
            break;
        default:
            break;
        }

        str += ", please choose a category for " + playerStr + ".";
    }

    // Create new Category Selector Dialog
    auto csd = new CategorySelectorDialog( this, str );

    // Connect the selection signal/slot
    connect( csd, SIGNAL( categorySelected(Types::Category) ), this, SLOT( onCategorySelected(Types::Category) ) );

    // Show to user
    csd->show();
}


void WheelOfFortuneBoard::onCategorySelected( Types::Category category )
{
    emit categoryChosen( m_turnState, category );
}


void WheelOfFortuneBoard::advanceTurn()
{
    // Set to next player
    switch( m_turnState )
    {
    case Types::Player1:
        m_turnState = Types::Player2;
        break;
    case Types::Player2:
        m_turnState = Types::Player3;
        break;
    case Types::Player3:
        m_turnState = Types::Player1;
        break;
    default:
        break;
    }

    // Update the label
    updateStatusLabel();
}


void WheelOfFortuneBoard::updateStatusLabel()
{
    QString str = "";

    // Get player's name
    switch( m_turnState )
    {
    case Types::Player1:
        str=  m_player1Name;
        break;
    case Types::Player2:
        str = m_player2Name;
        break;
    case Types::Player3:
        str = m_player3Name;
        break;
    default:
        break;
    }

    // Actually update status label
    str.append( "'s Turn" );
    m_ui->statusLabel->setText( str );
}


void WheelOfFortuneBoard::receivedControlBack()
{
    // Get the Point Manager
    PointManager* pm = PointManager::instance();

    // Reset the Scoreboard scores
    // Player 1
    auto scoreItem = m_ui->scoreboardTableWidget->item( 0, 1 );
    scoreItem->setText( QString::number( pm->getPlayer1Points() ) );
    // Player 2
    scoreItem = m_ui->scoreboardTableWidget->item( 1, 1 );
    scoreItem->setText( QString::number( pm->getPlayer2Points() ) );
    // Player 3
    scoreItem = m_ui->scoreboardTableWidget->item( 2, 1 );
    scoreItem->setText( QString::number( pm->getPlayer3Points() ) );

    // Advance the turn
    advanceTurn();
}
