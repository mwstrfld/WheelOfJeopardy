#include <CategorySelectorDialog.h>
#include <ui_CategorySelectorDialog.h>


CategorySelectorDialog::CategorySelectorDialog( QWidget* parent,
                                                const QString& text )
    : QDialog( parent ),
      m_ui( new Ui::CategorySelectorDialog )
{
    // Parent the actual UI
    m_ui->setupUi( this );

    // Set modal, can't click anything else
    setModal( true );
    
    // Set the text
    m_ui->textLabel->setText( text );

    // Connect submit button signal/slot
    connect( m_ui->okButton, SIGNAL( pressed() ), SLOT( onOkButtonPressed() ) );
}


CategorySelectorDialog::~CategorySelectorDialog()
{
    delete m_ui;
}


void CategorySelectorDialog::onOkButtonPressed()
{
    // Close this dialog
    close();
}


void CategorySelectorDialog::done( int r )
{
    // Let Jeopardy Board know the submitted answer
    emit categorySelected( (Types::Category)m_ui->categoryComboBox->currentIndex() );

    // Call base class
    QDialog::done( r );
}
