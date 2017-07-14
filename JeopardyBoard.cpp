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


void JeopardyBoard::onCategoryChosen( Types::Category )
{
    // TODO: Make sure Qt signal/slot connection hits here,
    //       use QAF to get next question and answer.
}
