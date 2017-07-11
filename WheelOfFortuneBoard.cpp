#include "WheelOfFortuneBoard.h"
#include "ui_WheelOfFortuneBoard.h"


WheelOfFortuneBoard::WheelOfFortuneBoard( QWidget* parent )
    : QMainWindow( parent ),
      m_spinCount( 50 ),
      m_ui( new Ui::WheelOfFortuneBoard ),
      m_originalPixmap(),
      m_player1Name( "Player 1" ),
      m_player2Name( "Player 2" ),
      m_player3Name( "Player 3" )
{
    // Parent the actual UI
    m_ui->setupUi( this );

    // Setup spin count
    m_ui->spinCountLineEdit->setReadOnly( true );
    m_ui->spinCountLineEdit->setText( QString::number( m_spinCount ) );

    // Signal/slot connections
    connect( m_ui->spinButton, SIGNAL( pressed() ), SLOT( onSpinButtonPressed() ) );
    connect( m_ui->player1NameLineEdit, SIGNAL( textChanged(QString) ), SLOT( onPlayer1NameChange(QString) ) );
    connect( m_ui->player2NameLineEdit, SIGNAL( textChanged(QString) ), SLOT( onPlayer2NameChange(QString) ) );
    connect( m_ui->player3NameLineEdit, SIGNAL( textChanged(QString) ), SLOT( onPlayer3NameChange(QString) ) );

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
        m_ui->scoreboardTableWidget->setItem( i, 1, scoreItem );
    }

    // Setup original pixmap
    m_originalPixmap = *(m_ui->wheelLabel->pixmap());
}


WheelOfFortuneBoard::~WheelOfFortuneBoard()
{
    delete m_ui;
}


void WheelOfFortuneBoard::rotateWheel()
{
    // Initialize transformation matrix and center of image
    QTransform transform;

    // Translate, rotate, and translate back
    transform.translate( m_ui->wheelLabel->width()/2, m_ui->wheelLabel->height()/2 );
    // TODO: Generate a random number between 1 and 12 and multiply
    //       by 30?  There are 12 sectors, so they're 30 degrees apart.
    transform.rotate( 45 );
    transform.translate( -m_ui->wheelLabel->width()/2, -m_ui->wheelLabel->height()/2 );

    // Generate a new pixmap and apply transformation/rotation
    auto pixmap = m_ui->wheelLabel->pixmap();
    auto newPixmap = pixmap->transformed( transform );

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

    // Update the label
    m_ui->spinCountLineEdit->setText( QString::number( --m_spinCount ) );

    // Do the actual rotation
    rotateWheel();
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
