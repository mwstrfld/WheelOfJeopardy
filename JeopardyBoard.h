#pragma once


#include <QDialog>


// Forward declarations
namespace Ui
{
    class JeopardyBoard;
}


class JeopardyBoard : public QDialog
{
    Q_OBJECT

public:
    JeopardyBoard( QWidget* parent = 0 );
    ~JeopardyBoard();

protected:
    Ui::JeopardyBoard* m_ui;
};
