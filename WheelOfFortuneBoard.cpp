#include <QDebug>

#include <JeopardyBoard.h>
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
      m_jeopardyBoard( 0 )
{
    // Parent the actual UI
    m_ui->setupUi( this );

    // Setup spin count
    m_ui->spinCountLineEdit->setReadOnly( true );
    m_ui->spinCountLineEdit->setText( QString::number( m_spinCount ) );

    // Show Jeopardy Board
    m_jeopardyBoard = new JeopardyBoard( this );
    m_jeopardyBoard->show();

    // Signal/slot connections
    connect( m_ui->spinButton, SIGNAL( pressed() ), SLOT( onSpinButtonPressed() ) );
    connect( m_ui->player1NameLineEdit, SIGNAL( textChanged(QString) ), SLOT( onPlayer1NameChange(QString) ) );
    connect( m_ui->player2NameLineEdit, SIGNAL( textChanged(QString) ), SLOT( onPlayer2NameChange(QString) ) );
    connect( m_ui->player3NameLineEdit, SIGNAL( textChanged(QString) ), SLOT( onPlayer3NameChange(QString) ) );
    connect( this, SIGNAL( categoryChosen(Types::Category) ), m_jeopardyBoard, SLOT( onCategoryChosen(Types::Category) ) );

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
    // TODO: Apply end of game criteria when it hits zero and switch
    //       to Double Jeopardy at 25?  For now, reset once it hits 0.
    if( m_spinCount == 0 )
        m_spinCount = 50;

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
}


void WheelOfFortuneBoard::onPlayer2NameChange( const QString& name )
{
    // Store Player 2's name
    m_player2Name = name;

    // Update the Scoreboard
    auto item = m_ui->scoreboardTableWidget->item( 1, 0 );
    item->setText( name );
}


void WheelOfFortuneBoard::onPlayer3NameChange( const QString& name )
{
    // Store Player 3's name
    m_player3Name = name;

    // Update the Scoreboard
    auto item = m_ui->scoreboardTableWidget->item( 2, 0 );
    item->setText( name );
}


void WheelOfFortuneBoard::actUponNewSector()
{
    // TODO: Implement flow chart from SRS document
    switch( m_currentSector )
    {
    case Types::SectorCategory1:
        emit categoryChosen( Types::Category::Category1 );
        break;
    case Types::LoseTurn:
        break;
    case Types::SectorCategory2:
        emit categoryChosen( Types::Category::Category2 );
        break;
    case Types::FreeTurn:
        break;
    case Types::SectorCategory3:
        emit categoryChosen( Types::Category::Category3 );
        break;
    case Types::Bankrupt:
        break;
    case Types::SectorCategory4:
        emit categoryChosen( Types::Category::Category4 );
        break;
    case Types::PlayerChoice:
        break;
    case Types::SectorCategory5:
        emit categoryChosen( Types::Category::Category5 );
        break;
    case Types::OpponentChoice:
        break;
    case Types::SectorCategory6:
        emit categoryChosen( Types::Category::Category6 );
        break;
    case Types::SpinAgain:
        break;
    default:
        break;
    }
}


void WheelOfFortuneBoard::advanceTurn()
{
    QString str = "";

    // Set to next player
    switch( m_turnState )
    {
    case Types::Player1:
        m_turnState = Types::Player2;
        str=  m_player2Name;
        break;
    case Types::Player2:
        m_turnState = Types::Player3;
        str = m_player3Name;
        break;
    case Types::Player3:
        m_turnState = Types::Player1;
        str = m_player1Name;
        break;
    default:
        break;
    }

    // Update status label
    str.append( "'s Turn" );
    m_ui->statusLabel->setText( str );
}
