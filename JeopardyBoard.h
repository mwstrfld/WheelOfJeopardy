#pragma once


#include <QDialog>

#include <WheelOfJeopardyTypes.h>


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

public slots:
    void onCategoryChosen( Types::Category );

protected:
    Ui::JeopardyBoard* m_ui;
};
