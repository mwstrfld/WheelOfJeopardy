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
    transform.rotate( 90 );
    transform.translate( -m_ui->wheelLabel->width()/2, -m_ui->wheelLabel->height()/2 );

    // Generate a new pixmap and apply transformation/rotation
    auto pixmap = m_ui->wheelLabel->pixmap();
    auto newPixmap = pixmap->transformed( transform );

    // Update with the new pixmap.
    m_ui->wheelLabel->setPixmap( newPixmap );
}


void WheelOfFortuneBoard::onSpinButtonPressed()
{
    // Reset once it hits 50
    if( m_spinCount == 50 )
        m_spinCount = -1;

    // Update the label
    m_ui->spinCountLineEdit->setText( QString::number( ++m_spinCount ) );

    // Do the actual rotation
    rotateWheel();
}
