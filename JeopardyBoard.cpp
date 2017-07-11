#include "JeopardyBoard.h"
#include "ui_JeopardyBoard.h"


JeopardyBoard::JeopardyBoard( QWidget* parent )
    : QDialog( parent ),
      m_ui( new Ui::JeopardyBoard )
{
    // Parent the actual UI
    m_ui->setupUi( this );
}


JeopardyBoard::~JeopardyBoard()
{
    delete m_ui;
}
