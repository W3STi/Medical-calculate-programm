#ifndef MYLINEEDIT_H
#define MYLINEEDIT_H

#include <QLineEdit>

class MyLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit MyLineEdit(QWidget* parent = nullptr);
    explicit MyLineEdit( const QString& str, QWidget* parent = nullptr );

    void focusInEvent( QFocusEvent* ) override;

signals:
    void isSelected();
};

#endif // MYLINEEDIT_H
