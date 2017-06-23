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
    
    auto pixmap = m_ui->wheelLabel->pixmap();
    Q_ASSERT(pixmap);
    m_masterOrigImage = *pixmap;
}


WheelOfFortuneBoard::~WheelOfFortuneBoard()
{
    delete m_ui;
}

inline int normalizedOrientation(int orientation)
{
    int normal = orientation % 360;
    if (normal < 0)
        normal += 360;
    return normal;
}

void WheelOfFortuneBoard::rotateWheel()
{
    // Initialize transformation matrix and center of image
    QTransform transform;

    // Translate, rotate, and translate back
    transform.translate( m_ui->wheelLabel->width()/2, m_ui->wheelLabel->height()/2 );
    transform.rotate( normalizedOrientation(45 * m_spinCount) );
    transform.translate( -m_ui->wheelLabel->width()/2, -m_ui->wheelLabel->height()/2 );

    // Generate a new pixmap and apply transformation/rotation
    // when we translate the pixmap, we change the size of the image
    // rotating the original image 45 degrees causes the width of the new
    // image to be the diagonal of the old, which is larger.  Then to fit the
    // fixed label size, it scales down.  So we're cropping the image and fixing that.
    // Keeping the orignal image each time so that after scaling and cropping 
    // a bunch, It doesn't get fuzzy.
    auto rotatedPixmap = m_masterOrigImage.transformed( transform );
    int widthDifference = (rotatedPixmap.width() - m_masterOrigImage.width()) / 2;
    int heightDifference = (rotatedPixmap.height() - m_masterOrigImage.height()) / 2;
    rotatedPixmap = rotatedPixmap.copy(widthDifference, heightDifference, m_masterOrigImage.width(), m_masterOrigImage.height());

    // Update with the new pixmap.
    m_ui->wheelLabel->setPixmap(rotatedPixmap);
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
