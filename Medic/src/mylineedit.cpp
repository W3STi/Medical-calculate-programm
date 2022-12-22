#include "mylineedit.h"
#include <QFocusEvent>

MyLineEdit:: MyLineEdit( QWidget* parent )
    : QLineEdit( parent )
{

}

MyLineEdit::MyLineEdit( const QString& str, QWidget* parent )
    : QLineEdit( str, parent )
{

}

void MyLineEdit::focusInEvent( QFocusEvent* )
{
    emit isSelected();
}




