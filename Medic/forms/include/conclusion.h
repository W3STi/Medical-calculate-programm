#ifndef CONCLUSION_H
#define CONCLUSION_H

#include <QGraphicsView>
#include <QWidget>

namespace Ui
{
class conclusion;
}

class conclusion : public QWidget
{
    Q_OBJECT

public:
    explicit conclusion(QWidget* parent = nullptr);
    ~conclusion();

private:
    Ui::conclusion* ui;
};

#endif // CONCLUSION_H
