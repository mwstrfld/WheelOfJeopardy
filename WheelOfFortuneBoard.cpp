#include "WheelOfFortuneBoard.h"
#include "ui_WheelOfFortuneBoard.h"


WheelOfFortuneBoard::WheelOfFortuneBoard( QWidget* parent )
    : QMainWindow( parent ),
      m_spinCount( 0 ),
      m_ui( new Ui::WheelOfFortuneBoard )
{
    // Parent the actual UI
    m_ui->setupUi( this );

    // Setup spin count
    m_ui->spinCountLineEdit->setReadOnly( true );
    m_ui->spinCountLineEdit->setText( QString::number( m_spinCount ) );

    // Signal/slot connections
    connect( m_ui->spinButton, SIGNAL( pressed() ), SLOT( onSpinButtonPressed() ) );

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
    // TODO: Apply end of game criteria when it hits fifty and switch
    //       to Double Jeopardy at 25?  For now, reset once it hits 50.
    if( m_spinCount == 50 )
        m_spinCount = -1;

    // Update the label
    m_ui->spinCountLineEdit->setText( QString::number( ++m_spinCount ) );

    // Do the actual rotation
    rotateWheel();
}
