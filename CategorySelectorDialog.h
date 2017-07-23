#pragma once


#include <WheelOfJeopardyTypes.h>

#include <QDialog>


// Forward declarations
namespace Ui
{
    class CategorySelectorDialog;
}


class CategorySelectorDialog : public QDialog
{
    Q_OBJECT

public:
    CategorySelectorDialog( QWidget* parent = 0,
                            const QString& text = "" );
    ~CategorySelectorDialog();

signals:
    void categorySelected( Types::Category );

protected slots:
    void onOkButtonPressed();
    void done( int );

protected:
    // Actual UI
    Ui::CategorySelectorDialog* m_ui;
};
